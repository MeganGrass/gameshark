using System;
using System.IO;
using System.Linq;
using System.Text;

namespace GameSharkCompression
{
	/// <summary>
	/// Test and validation utility for GameShark compression algorithms.
	/// Verifies implementation against original GameShark v1.99 ROM data.
	/// </summary>
	class Program
	{
		static void DecompressionMain(string[] args)
		{
			Console.WriteLine("GameShark PlayStation v1.99 Compression Test Utility");
			Console.WriteLine("======================================================\n");

			if (args.Length == 0)
			{
				ShowUsage();
				TestAgainstROM();
				return;
			}

			string command = args[0].ToLowerInvariant();

			try
			{
				switch (command)
				{
					case "test":
						TestAgainstROM();
						break;

					case "decompress":
						if (args.Length < 3)
						{
							Console.WriteLine("Error: decompress requires input and output files");
							ShowUsage();
							return;
						}
						DecompressFile(args[1], args[2]);
						break;

					case "compress":
						if (args.Length < 4)
						{
						Console.WriteLine("Error: compress requires format (def01|rle01), input, and output files");
							ShowUsage();
							return;
						}
						CompressFile(args[1], args[2], args[3]);
						break;

					case "extract":
						if (args.Length < 2)
						{
							Console.WriteLine("Error: extract requires ROM file path");
							ShowUsage();
							return;
						}
						ExtractFromROM(args[1]);
						break;

					default:
						Console.WriteLine($"Error: Unknown command '{command}'");
						ShowUsage();
						break;
				}
			}
			catch (Exception ex)
			{
				Console.WriteLine($"\nError: {ex.Message}");
				if (ex.InnerException != null)
					Console.WriteLine($"  {ex.InnerException.Message}");
			}
		}

		static void ShowUsage()
		{
			Console.WriteLine("Usage:");
			Console.WriteLine("  GameSharkCompression test");
			Console.WriteLine("    - Test decompression against ROM data\n");
			Console.WriteLine("  GameSharkCompression extract <rom_file>");
			Console.WriteLine("    - Extract all compressed blocks from ROM\n");
			Console.WriteLine("  GameSharkCompression decompress <input> <output>");
			Console.WriteLine("    - Decompress DEF01 or RLE01 file\n");
			Console.WriteLine("  GameSharkCompression compress <def01|rle01> <input> <output>");
			Console.WriteLine("    - Compress file using specified format\n");
		}

		static void TestAgainstROM()
		{
			string romPath = "v1.99e.rom";
			if (!File.Exists(romPath))
			{
				Console.WriteLine($"ROM file not found: {romPath}");
				Console.WriteLine("Skipping ROM validation tests.\n");
				return;
			}

			Console.WriteLine("Testing against GameShark v1.99 ROM data...\n");

			// Simulate PS1 RAM (2 MB)
			byte[] ram = new byte[2 * 1024 * 1024];

			// Test data from TECHNICAL_REFERENCE.md
			// Decompression order matches initialization sequence:
			// 1. RLE01 block 4 -> 0x80018000
			// 2. DEF01 block 2 -> 0x80140000 (may reference block 4 data!)
			// 3. DEF01 block 3 -> 0x80150000
			// 4. RLE01 block 1 -> 0x80020000
			var testBlocks = new[]
			{
				new { Offset = 0x17A60, Type = "RLE01", Name = "Block 4", RamAddr = 0x80018000u },
				new { Offset = 0x15FF0, Type = "DEF01", Name = "Block 2", RamAddr = 0x80140000u },
				new { Offset = 0x17450, Type = "DEF01", Name = "Block 3", RamAddr = 0x80150000u },
				new { Offset = 0x15B40, Type = "RLE01", Name = "Block 1", RamAddr = 0x80020000u }
			};

			byte[] romData = File.ReadAllBytes(romPath);
			int passCount = 0;
			int failCount = 0;

			foreach (var block in testBlocks)
			{
				Console.Write($"Testing {block.Type} {block.Name} at 0x{block.Offset:X5} -> RAM 0x{block.RamAddr:X8}... ");

				try
				{
					// Read compressed size from header (bytes 6-9, big-endian)
					int headerSize = ((romData[block.Offset + 6] << 24) |
									  (romData[block.Offset + 7] << 16) |
									  (romData[block.Offset + 8] << 8) |
									   romData[block.Offset + 9]);

					byte[] compressed = new byte[headerSize];
					Array.Copy(romData, block.Offset, compressed, 0, headerSize);

					// Decompress with RAM context
					byte[] decompressed;
					if (block.Type == "RLE01")
					{
						decompressed = Compression.DecompressRLE01(compressed);
					}
					else
					{
						// DEF01 needs RAM context for cross-buffer references
						decompressed = Compression.DecompressDEF01(compressed, ram, block.RamAddr);
					}

					// Write decompressed data to simulated RAM
					uint ramOffset = block.RamAddr - 0x80000000;
					Array.Copy(decompressed, 0, ram, ramOffset, decompressed.Length);

					// Re-compress (compression doesn't need RAM context)
					byte[] recompressed = block.Type == "RLE01"
						? Compression.CompressRLE01(decompressed)
						: Compression.CompressDEF01(decompressed);

					// Re-decompress to verify
					byte[] reverify;
					if (block.Type == "RLE01")
					{
						reverify = Compression.DecompressRLE01(recompressed);
					}
					else
					{
						// Use fresh RAM with same pre-existing data for verification
						byte[] ramCopy = new byte[ram.Length];
						Array.Copy(ram, ramCopy, ram.Length);
						reverify = Compression.DecompressDEF01(recompressed, ramCopy, block.RamAddr);
					}

					// Check round-trip consistency
					if (decompressed.SequenceEqual(reverify))
					{
						Console.ForegroundColor = ConsoleColor.Green;
						Console.WriteLine($"PASS ({decompressed.Length} bytes decompressed)");
						Console.ResetColor();
						passCount++;
					}
					else
					{
						Console.ForegroundColor = ConsoleColor.Red;
						Console.WriteLine($"FAIL (round-trip mismatch)");
						Console.ResetColor();
						failCount++;
					}
				}
				catch (Exception ex)
				{
					Console.ForegroundColor = ConsoleColor.Red;
					Console.WriteLine($"FAIL ({ex.GetType().Name}: {ex.Message})");
					if (ex.StackTrace != null && ex.StackTrace.Contains("GameSharkCompression"))
					{
						var lines = ex.StackTrace.Split('\n');
						foreach (var line in lines)
						{
							if (line.Contains("GameSharkCompression"))
							{
								Console.WriteLine($"  {line.Trim()}");
								break;
							}
						}
					}
					Console.ResetColor();
					failCount++;
				}
			}

			Console.WriteLine($"\nTest Results: {passCount} passed, {failCount} failed\n");
		}

		static void ExtractFromROM(string romPath)
		{
			if (!File.Exists(romPath))
			{
				Console.WriteLine($"ROM file not found: {romPath}");
				return;
			}

			Console.WriteLine($"Extracting compressed blocks from {romPath}...\n");

			byte[] romData = File.ReadAllBytes(romPath);

			// Simulate PS1 RAM for DEF01 blocks with cross-references
			byte[] ram = new byte[2 * 1024 * 1024];

			var blocks = new[]
			{
				new { Offset = 0x17A60, Size = 1440, Type = "RLE01", Name = "rle01_1F017A60.bin", RamAddr = 0x80018000u },
				new { Offset = 0x15FF0, Size = 5216, Type = "DEF01", Name = "def01_1F015FF0.bin", RamAddr = 0x80140000u },
				new { Offset = 0x17450, Size = 1552, Type = "DEF01", Name = "def01_1F017450.bin", RamAddr = 0x80150000u },
				new { Offset = 0x15B40, Size = 1200, Type = "RLE01", Name = "rle01_1F015B40.bin", RamAddr = 0x80020000u }
			};

			foreach (var block in blocks)
			{
				Console.Write($"Extracting {block.Type} block to {block.Name}... ");

				// Read entire block (includes header + data + padding)
				byte[] compressed = new byte[block.Size];
				Array.Copy(romData, block.Offset, compressed, 0, block.Size);

				// Decompress with RAM context
				byte[] decompressed;
				if (block.Type == "RLE01")
				{
					decompressed = Compression.DecompressRLE01(compressed);
				}
				else
				{
					decompressed = Compression.DecompressDEF01(compressed, ram, block.RamAddr);
				}

				// Write decompressed data to simulated RAM
				uint ramOffset = block.RamAddr - 0x80000000;
				Array.Copy(decompressed, 0, ram, ramOffset, decompressed.Length);

				string compressedFile = block.Name;
				string decompressedFile = block.Name.Replace(".bin", "_dec.bin");

				File.WriteAllBytes(compressedFile, compressed);
				File.WriteAllBytes(decompressedFile, decompressed);

				Console.WriteLine($"{decompressed.Length} bytes");
			}

			Console.WriteLine("\nExtraction complete.\n");
		}

		static void DecompressFile(string inputPath, string outputPath)
		{
			if (!File.Exists(inputPath))
			{
				Console.WriteLine($"Input file not found: {inputPath}");
				return;
			}

			byte[] input = File.ReadAllBytes(inputPath);

			// Auto-detect format by signature
			string format = "UNKNOWN";
			byte[] output;

			if (input.Length >= 5)
			{
				string sig = Encoding.ASCII.GetString(input, 0, 5);
				if (sig == "RLE01")
				{
					format = "RLE01";
					output = Compression.DecompressRLE01(input);
				}
				else if (sig == "DEF01")
				{
					format = "DEF01";
					output = Compression.DecompressDEF01(input);
				}
				else
				{
					Console.WriteLine($"Error: Unknown format (signature: {sig})");
					return;
				}
			}
			else
			{
				Console.WriteLine("Error: File too small to contain valid header");
				return;
			}

			File.WriteAllBytes(outputPath, output);
			Console.WriteLine($"Decompressed {format}: {input.Length} -> {output.Length} bytes");
			Console.WriteLine($"Output written to: {outputPath}");
		}

		static void CompressFile(string format, string inputPath, string outputPath)
		{
			if (!File.Exists(inputPath))
			{
				Console.WriteLine($"Input file not found: {inputPath}");
				return;
			}

			byte[] input = File.ReadAllBytes(inputPath);
			byte[] output;

			switch (format.ToLowerInvariant())
			{
				case "rle01":
					output = Compression.CompressRLE01(input);
					break;

				case "def01":
					output = Compression.CompressDEF01(input);
					break;

				default:
					Console.WriteLine($"Error: Unknown format '{format}' (use def01 or rle01)");
					return;
			}

			File.WriteAllBytes(outputPath, output);
			Console.WriteLine($"Compressed {format.ToUpperInvariant()}: {input.Length} -> {output.Length} bytes");
			Console.WriteLine($"Compression ratio: {(1.0 - (double)output.Length / input.Length) * 100:F1}%");
			Console.WriteLine($"Output written to: {outputPath}");
		}
	}
}
