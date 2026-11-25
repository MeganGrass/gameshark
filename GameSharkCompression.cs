using System;
using System.IO;
using System.Text;

namespace GameSharkCompression
{
	/// <summary>
	/// GameShark PlayStation v1.99 compression/decompression utilities.
	/// Implements DEF01 (LZ77-variant with backreference) and RLE01 (Run-Length Encoding).
	/// </summary>
	public static class Compression
	{
		// Header signatures
		private static readonly byte[] DEF01_SIGNATURE = Encoding.ASCII.GetBytes("DEF01");
		private static readonly byte[] RLE01_SIGNATURE = Encoding.ASCII.GetBytes("RLE01");

		#region RLE01 Decompression

		/// <summary>
		/// Decompresses RLE01-compressed data.
		/// Format: [RLE01 signature (5 bytes)][escape byte (1 byte)][compressed size (4 bytes BE)][data]
		/// </summary>
		/// <param name="input">Compressed data buffer starting with RLE01 header</param>
		/// <returns>Decompressed data</returns>
		public static byte[] DecompressRLE01(byte[] input)
		{
			if (input == null || input.Length < 10)
				throw new ArgumentException("Input too small for RLE01 format");

			// Verify signature (bytes 0-4)
			for (int i = 0; i < 5; i++)
			{
				if (input[i] != RLE01_SIGNATURE[i])
					throw new InvalidDataException($"Invalid RLE01 signature at offset {i}");
			}

			// Read escape character (byte 5)
			byte escapeChar = input[5];

			// RLE01: bytes 6-9 = compressed size (big-endian)
			uint compressedSize = (uint)((input[6] << 24) | (input[7] << 16) | (input[8] << 8) | input[9]);

			// Decompress
			using (var output = new MemoryStream())
			{
				uint readPos = 10; // Start after 10-byte header

				while (readPos < compressedSize)
				{
					byte currentByte = input[readPos++];

					if (currentByte == escapeChar)
					{
						// Escape sequence
						if (readPos >= compressedSize)
							throw new InvalidDataException("Unexpected end of data in RLE escape sequence");

						byte count = input[readPos++];

						if (count == 0)
						{
							// Literal escape character
							output.WriteByte(escapeChar);
						}
						else
						{
							// Run of repeated bytes
							if (readPos >= compressedSize)
								throw new InvalidDataException("Unexpected end of data reading RLE repeat byte");

							byte repeatByte = input[readPos++];

							for (int i = 0; i < count; i++)
							{
								output.WriteByte(repeatByte);
							}
						}
					}
					else
					{
						// Literal byte
						output.WriteByte(currentByte);
					}
				}

				return output.ToArray();
			}
		}

		#endregion

		#region RLE01 Compression

		/// <summary>
		/// Compresses data using RLE01 encoding.
		/// Automatically selects the least-used byte as the escape character.
		/// </summary>
		/// <param name="input">Uncompressed data</param>
		/// <returns>RLE01-compressed data with header</returns>
		public static byte[] CompressRLE01(byte[] input)
		{
			if (input == null || input.Length == 0)
				throw new ArgumentException("Input cannot be null or empty");

			// Find least-used byte for escape character
			byte escapeChar = FindLeastUsedByte(input);

			using (var output = new MemoryStream())
			{
				// Write header (signature + escape + placeholder for size)
				output.Write(RLE01_SIGNATURE, 0, 5);
				output.WriteByte(escapeChar);
				output.Write(new byte[4], 0, 4); // Size placeholder

				uint inputPos = 0;

				while (inputPos < input.Length)
				{
					byte currentByte = input[inputPos];
					int runLength = 1;

					// Count consecutive identical bytes (max 255)
					while (runLength < 255 && inputPos + runLength < input.Length && input[inputPos + runLength] == currentByte)
					{
						runLength++;
					}

					if (runLength >= 4)
					{
						// Use RLE encoding for runs >= 4
						output.WriteByte(escapeChar);
						output.WriteByte((byte)runLength);
						output.WriteByte(currentByte);
						inputPos += (uint)runLength;
					}
					else
					{
						// Output literal byte(s)
						output.WriteByte(currentByte);
						if (currentByte == escapeChar)
						{
							// Escape the escape character
							output.WriteByte(0);
						}
						inputPos++;
					}
				}

				// Write compressed size (big-endian)
				byte[] result = output.ToArray();
				uint compressedSize = (uint)result.Length;
				result[6] = (byte)(compressedSize >> 24);
				result[7] = (byte)(compressedSize >> 16);
				result[8] = (byte)(compressedSize >> 8);
				result[9] = (byte)compressedSize;

				return result;
			}
		}

		#endregion

		#region DEF01 Decompression

		/// <summary>
		/// Decompresses DEF01-compressed data with optional RAM context.
		/// DEF01 backreferences are ABSOLUTE RAM POINTERS that can reference any previously-loaded data.
		/// Format: [DEF01 signature (5 bytes)][escape byte (1 byte)][decompressed size (4 bytes BE)][data]
		/// </summary>
		/// <param name="input">Compressed data buffer starting with DEF01 header</param>
		/// <param name="ramContext">Optional: Full PS1 RAM state for resolving absolute backreferences. If null, only intra-block references are supported.</param>
		/// <param name="ramBaseAddress">Base RAM address where this block will be decompressed (e.g., 0x80140000)</param>
		/// <returns>Decompressed data</returns>
		public static byte[] DecompressDEF01(byte[] input, byte[]? ramContext = null, uint ramBaseAddress = 0x80000000)
		{
			if (input == null || input.Length < 10)
				throw new ArgumentException("Input too small for DEF01 format");

			// Verify signature (bytes 0-4)
			for (int i = 0; i < 5; i++)
			{
				if (input[i] != DEF01_SIGNATURE[i])
					throw new InvalidDataException($"Invalid DEF01 signature at offset {i}");
			}

			// Read escape character (byte 5)
			byte escapeChar = input[5];

			// DEF01: bytes 6-9 = decompressed size (big-endian)
			uint decompressedSize = (uint)((input[6] << 24) | (input[7] << 16) | (input[8] << 8) | input[9]);

			// Decompress
			using (var output = new MemoryStream())
			{
				uint readPos = 10; // Start after 10-byte header

				while (readPos < input.Length && output.Length < decompressedSize)
				{
					byte currentByte = input[readPos++];

					if (currentByte == escapeChar)
					{
						// Escape sequence
						if (readPos >= input.Length)
							throw new InvalidDataException("Unexpected end of data in DEF escape sequence");

						byte count = input[readPos++];

						if (count == 0)
						{
							// Literal escape character
							output.WriteByte(escapeChar);
						}
						else
						{
							// Backreference: ABSOLUTE RAM POINTER
							if (readPos + 1 >= input.Length)
								throw new InvalidDataException("Unexpected end of data reading DEF backreference");

							byte offsetHi = input[readPos++];
							byte offsetLo = input[readPos++];
							int offset = (offsetHi << 8) | offsetLo;

							long currentPos = output.Position;
							uint currentRamAddr = ramBaseAddress + (uint)currentPos;
							uint sourceRamAddr = currentRamAddr - (uint)offset;

							// Try to resolve backreference
							byte[] sourceData;
							long sourceOffset;
							bool isIntraBlock;

							if (sourceRamAddr >= ramBaseAddress && sourceRamAddr < ramBaseAddress + currentPos)
							{
								// Intra-block reference (within current decompression output)
								sourceData = output.ToArray();
								sourceOffset = (long)(sourceRamAddr - ramBaseAddress);
								isIntraBlock = true;
							}
							else if (ramContext != null && sourceRamAddr >= 0x80000000 && sourceRamAddr < 0x80000000 + ramContext.Length)
							{
								// Cross-block reference (requires full RAM context)
								sourceData = ramContext;
								sourceOffset = (long)(sourceRamAddr - 0x80000000);
								isIntraBlock = false;
							}
							else
							{
								throw new InvalidDataException(
									$"Cannot resolve backreference: offset={offset} (0x{offset:X4}), " +
									$"source RAM=0x{sourceRamAddr:X8}, current RAM=0x{currentRamAddr:X8}, readPos={readPos-4}. " +
									$"This block requires full PS1 RAM context (2MB buffer starting at 0x80000000). " +
									$"Standalone decompression is not supported for blocks with cross-buffer references.");
							}

							// Copy bytes one at a time (allows overlapping RLE via backreference)
							// This matches the MIPS decompiler behavior at 0x1F007110
							for (int i = 0; i < count; i++)
							{
								// Stop if we've reached the target decompressed size
								if (output.Length >= decompressedSize)
									break;

								if (sourceOffset + i >= sourceData.Length)
									throw new InvalidDataException($"Backreference reads beyond buffer: sourceOffset={sourceOffset + i}, bufferSize={sourceData.Length}");

								output.WriteByte(sourceData[sourceOffset + i]);

								// For intra-block references, refresh the buffer to see newly-written bytes
								if (isIntraBlock && i < count - 1)
									sourceData = output.ToArray();
							}
						}
					}
					else
					{
						// Literal byte
						output.WriteByte(currentByte);
					}
				}

				return output.ToArray();
			}
		}

		#endregion

		#region DEF01 Compression

		/// <summary>
		/// Compresses data using DEF01 encoding (LZ77-variant).
		/// Automatically selects the least-used byte as the escape character.
		/// </summary>
		/// <param name="input">Uncompressed data</param>
		/// <returns>DEF01-compressed data with header</returns>
		public static byte[] CompressDEF01(byte[] input)
		{
			if (input == null || input.Length == 0)
				throw new ArgumentException("Input cannot be null or empty");

			// Find least-used byte for escape character
			byte escapeChar = FindLeastUsedByte(input);

			using (var output = new MemoryStream())
			{
				// Write header (signature + escape + placeholder for size)
				output.Write(DEF01_SIGNATURE, 0, 5);
				output.WriteByte(escapeChar);
				output.Write(new byte[4], 0, 4); // Size placeholder

				uint inputPos = 0;

				while (inputPos < input.Length)
				{
					// Search for best match in sliding window
					int bestMatchLength = 0;
					int bestMatchOffset = 0;

					// Window limits based on GameShark implementation
					uint windowStart = inputPos < 501 ? 0 : inputPos - 500;
					uint windowEnd = inputPos;

					// Search window for matches (minimum 5 bytes to be worth encoding)
					for (uint searchPos = windowStart; searchPos < windowEnd; searchPos++)
					{
						int matchLength = 0;
						int maxMatchLength = Math.Min(0x80, (int)(input.Length - inputPos)); // Max 128 bytes

						while (matchLength < maxMatchLength && input[searchPos + matchLength] == input[inputPos + matchLength])
						{
							matchLength++;
						}

						if (matchLength > bestMatchLength)
						{
							bestMatchLength = matchLength;
							bestMatchOffset = (int)(inputPos - searchPos);
						}
					}

					// Only encode if match is 5+ bytes (based on decompiler analysis)
					if (bestMatchLength >= 5)
					{
						output.WriteByte(escapeChar);
						output.WriteByte((byte)bestMatchLength);
						output.WriteByte((byte)(bestMatchOffset >> 8));
						output.WriteByte((byte)bestMatchOffset);
						inputPos += (uint)bestMatchLength;
					}
					else
					{
						// Output literal byte
						byte currentByte = input[inputPos++];
						output.WriteByte(currentByte);
						if (currentByte == escapeChar)
						{
							// Escape the escape character
							output.WriteByte(0);
						}
					}
				}

				// DEF01: Write decompressed size (big-endian)
				byte[] result = output.ToArray();
				uint decompressedSize = (uint)input.Length;
				result[6] = (byte)(decompressedSize >> 24);
				result[7] = (byte)(decompressedSize >> 16);
				result[8] = (byte)(decompressedSize >> 8);
				result[9] = (byte)decompressedSize;

				return result;
			}
		}

		#endregion

		#region Helper Methods

		/// <summary>
		/// Finds the least-used byte value in the input data to use as escape character.
		/// Implementation matches FUN_1f007020 at 0x1F007020 in GameShark ROM.
		/// </summary>
		/// <param name="input">Input data to analyze</param>
		/// <returns>Byte value with lowest frequency</returns>
		private static byte FindLeastUsedByte(byte[] input)
		{
			// Count frequency of each byte value (0-255)
			uint[] frequency = new uint[256];

			foreach (byte b in input)
			{
				frequency[b]++;
			}

			// Find byte with minimum frequency
			uint minFreq = 0x7FFF;
			byte leastUsed = 0;

			for (int i = 0; i < 256; i++)
			{
				if (frequency[i] < minFreq)
				{
					minFreq = frequency[i];
					leastUsed = (byte)i;
				}
			}

			return leastUsed;
		}

		#endregion
	}
}
