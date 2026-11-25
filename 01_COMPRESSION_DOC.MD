# GameShark [v1.99] for Sony PlayStation (1994)

## Compression Overview

The GameShark v1.99 ROM uses two custom compression formats to reduce data size:
- **RLE01**: Run-Length Encoding for highly repetitive data
- **DEF01**: LZ77-variant dictionary compression for structured data

Both formats share a common 10-byte header structure and use dynamically-selected escape characters.

---

## Header Format

**Critical Discovery**: RLE01 and DEF01 do **not** share the same header semantics at offset +6.

### RLE01 Header

```
Offset | Size | Description
-------|------|-------------
0x00   | 5    | Format signature ("RLE01" ASCII)
0x05   | 1    | Escape character (dynamically selected)
0x06   | 4    | Compressed size (big-endian 32-bit) - total size including header
0x0A   | N    | Compressed data stream
```

### DEF01 Header

```
Offset | Size | Description
-------|------|-------------
0x00   | 5    | Format signature ("DEF01" ASCII)
0x05   | 1    | Escape character (dynamically selected)
0x06   | 4    | Decompressed size (big-endian 32-bit) - output data size
0x0A   | N    | Compressed data stream
```

**Why the difference?**
- **RLE01** stores compressed size because decompressed size is variable and depends on run-length expansion
- **DEF01** stores decompressed size to preallocate output buffer and enforce exact output length; compressed size can be inferred from 0xFF padding or block boundaries

### Escape Character Selection

Both compression algorithms automatically select the least-used byte value in the input data as the escape character. This minimizes overhead from escaping literal bytes.

**Algorithm** (FUN_1f007020 at 0x1F007020):
1. Count frequency of each byte value (0-255) in input
2. Select byte with lowest frequency
3. Use this byte as the escape marker

---

## RLE01 Format (Run-Length Encoding)

### Decompression (FUN_1f007548 at 0x1F007548)

RLE01 uses simple run-length encoding for sequences of repeated bytes.

**Data Stream Format**:
- **Literal byte**: Any byte != escape character → copy to output
- **Escape sequence**:
  - `[escape][0x00]` → Output literal escape character
  - `[escape][count][byte]` → Output `byte` repeated `count` times (1-255)

**Example**:
```
Input:  41 41 41 41 42 43 43 43 43 43 43
Escape: FF

Compressed: [FF][04][41][42][FF][06][43]
			└─┬─┘ │  └┬┘ │  └─┬─┘ │  └┬┘
			  │   │   │  │    │   │   └── 'C' repeated
			  │   │   │  │    │   └────── 6 times
			  │   │   │  │    └────────── escape marker
			  │   │   │  └─────────────── literal 'B'
			  │   │   └────────────────── 'A' repeated
			  │   └────────────────────── 4 times
			  └────────────────────────── escape marker

Decompressed: 41 41 41 41 42 43 43 43 43 43 43
			  A  A  A  A  B  C  C  C  C  C  C
```

**Compression Threshold**: Runs of 4+ identical bytes are encoded; shorter runs output literal bytes.

### Compression (FUN_1f0073ec at 0x1F0073EC)

1. Select escape character (least-used byte)
2. Write header (signature + escape + size placeholder)
3. Process input sequentially:
   - Count consecutive identical bytes (max 255)
   - If run >= 4: encode as `[escape][count][byte]`
   - If run < 4: output literal byte(s), escape if needed
4. Update header with final compressed size

---

## DEF01 Format (LZ77-Variant Dictionary Compression)

### Critical Implementation Detail: Absolute RAM Pointers

**DEF01 backreferences are ABSOLUTE RAM POINTERS, not relative offsets within the compressed stream.**

When the GameShark firmware decompresses DEF01 blocks to PlayStation RAM, backreferences can point to:
1. Previously decompressed bytes within the same block (intra-block)
2. Data from other blocks decompressed earlier in the initialization sequence (cross-block)
3. Any pre-initialized data in the PlayStation's 2MB RAM space

This means **standalone decompression of individual DEF01 blocks may fail** if they contain cross-buffer references. Full decompression requires simulating the complete PlayStation RAM state (2MB at 0x80000000-0x801FFFFF) with all previously-loaded blocks.

### Decompression (FUN_1f007110 at 0x1F007110)

DEF01 uses absolute RAM addressing for backreferences.

**Data Stream Format**:
- **Literal byte**: Any byte != escape character → copy to output
- **Escape sequence**:
  - `[escape][0x00]` → Output literal escape character
  - `[escape][count][offset_hi][offset_lo]` → Copy `count` bytes from RAM address `(current_RAM_address - offset)`

**Backreference Encoding**:
- **Count**: Number of bytes to copy (1-128)
- **Offset**: 16-bit big-endian distance backwards from current RAM position
  - `offset = (offset_hi << 8) | offset_lo`
  - Source RAM address = `current_RAM_address - offset`
  - **Can reference any address in PS1 RAM** (not limited to current block!)

**Example (Intra-Block)**:
```
Current RAM address: 0x80140064 (100 bytes into block at 0x80140000)
Backreference: [escape][05][00][05]
			   └──┬──┘ │  └───┬───┘
				  │    │      └───── offset = 5
				  │    └────────────count = 5
				  └─────────────────escape marker

Source = 0x80140064 - 5 = 0x8014005F
Copy 5 bytes from RAM 0x8014005F-0x80140063 to 0x80140064-0x80140068
```

**Example (Cross-Block)**:
```
Block 4 decompressed earlier to: 0x80018000-0x80033B3F (113,440 bytes)
Current block 2 RAM address: 0x80141FA6 (8,102 bytes into block at 0x80140000)
Backreference: [escape][03][8E][00]
			   └──┬──┘ │  └───┬───┘
				  │    │      └───── offset = 0x8E00 (36,352 bytes)
				  │    └────────────count = 3
				  └─────────────────escape marker

Source = 0x80141FA6 - 0x8E00 = 0x801391A6
Copy 3 bytes from RAM 0x801391A6 (data from earlier initialization)
```

**Window Size**: Based on decompiler analysis:
- Search window: Up to 500 bytes backwards
- Maximum match length: 128 bytes (0x80)
- Minimum match length: 5 bytes (threshold for encoding)

### Compression (FUN_1f00722c at 0x1F00722C)

1. Select escape character (least-used byte)
2. Write header (signature + escape + size placeholder)
3. For each input position:
   - Search sliding window (500 bytes back) for longest match
   - If match >= 5 bytes: encode as backreference
   - Otherwise: output literal byte, escape if needed
4. Update header with final compressed size

**Search Algorithm**:
- Window start: `max(0, current_position - 500)`
- Window end: `current_position - 1`
- Search for longest matching sequence (up to 128 bytes)
- Only encode if match >= 5 bytes (overhead threshold)

---

## ROM Compressed Blocks

The GameShark v1.99 ROM contains four compressed blocks in the data section:

| Address    | Block Size  | Type  | Compressed Size | Decompressed Size | Destination | Contents |
|------------|-------------|-------|-----------------|-------------------|-------------|----------|
| 0x1F015B40 | 1,200 bytes | RLE01 | 1,197 bytes     | 1,272 bytes       | 0x80020000  | --- |
| 0x1F015FF0 | 5,216 bytes | DEF01 | 4,326 bytes     | 7,084 bytes       | 0x80140000  | graphics data |
| 0x1F017450 | 1,552 bytes | DEF01 | 1,440 bytes     | 1,952 bytes       | 0x80150000  | MIPS R3000A machine code |
| 0x1F017A60 | 1,440 bytes | RLE01 | 1,440 bytes     | 113,440 bytes     | 0x80018000  | 0x00 fill + memory pointers |

**Notes**:
- **Block Size**: total allocation size in ROM (header + compressed data + 0xFF fill to boundary)
- **---**: backreferences are absolute KSEG0 pointers, not relative offsets

**Initialization Sequence**:
1. RLE01 @ 0x1F017A60 (block 4) → 0x80018000 (contains memory pointers for cross-block references)
2. DEF01 @ 0x1F015FF0 (block 2) → 0x80140000 (contains cross-block backreferences to block 4 data)
3. DEF01 @ 0x1F017450 (block 3) → 0x80150000
4. RLE01 @ 0x1F015B40 (block 1) → 0x80020000

###### Decompression must follow this initialization order with Sony PlayStation (1994) RAM context

---

## Implementation Details

### Critical Accuracy Points

1. **Header Semantics**:
   - **RLE01**: Offset +6 stores **compressed size** (total file size including header)
   - **DEF01**: Offset +6 stores **decompressed size** (output buffer size)
   - Decompressor must check output length against header value to prevent overruns

2. **Escape Character**:
   - Must be least-used byte in input
   - Algorithm must match FUN_1f007020 exactly
   - Affects compressed output determinism

3. **Byte Order**:
   - Size fields: big-endian 32-bit
   - DEF01 offset: big-endian 16-bit
   - Critical for cross-platform compatibility

4. **Compression Thresholds**:
   - RLE01: Minimum 4 consecutive bytes for run encoding
   - DEF01: Minimum 5 bytes for backreference encoding
   - Below threshold: output literal bytes

5. **DEF01 Output Length Control**:
   - Decompressor must stop at exact decompressed size from header
   - Backreference copy loops must check output length before each byte write
   - Prevents buffer overruns when final backreference would exceed target size

6. **DEF01 RAM Context**:
   - Backreferences are absolute RAM pointers, not stream-relative offsets
   - Cross-block references require full 2MB PS1 RAM simulation
   - Initialization order determines which blocks can reference which data

### PC Implementation

**C# API** (`GameSharkCompression.cs`):

```csharp
// Decompression
byte[] DecompressRLE01(byte[] input)
byte[] DecompressDEF01(byte[] input, byte[]? ramContext = null, uint ramBaseAddress = 0x80000000)

// Compression
byte[] CompressRLE01(byte[] input)
byte[] CompressDEF01(byte[] input)
```

**Key Implementation Notes**:
- DEF01 decompression requires `ramContext` (2MB buffer) and `ramBaseAddress` for cross-block references
- Compression does not require RAM context (always uses relative window)
- All functions handle header parsing and size validation automatically

**Validation** (`CompressionTest.cs`):
- `test` command: Round-trip compression/decompression validation against ROM blocks
- `extract` command: Extract all four blocks with proper RAM simulation and initialization order
- All four ROM blocks validated: byte-perfect decompression with RAM context

### Known Limitations

1. **Standalone DEF01 Decompression**:
   - Blocks with cross-buffer references cannot be decompressed in isolation
   - Requires full PS1 RAM state with previously-loaded blocks
   - Example: Block 2 references block 4 data at offset 0x8E00 (36,352 bytes back)

2. **Compression Determinism**:
   - Escape character selection is deterministic
   - DEF01 compression window (500 bytes) matches hardware behavior
   - Recompressed output may differ from original ROM due to search order variations

3. **ROM Block Boundaries**:
   - DEF01 compressed size not stored in header
   - Must use block allocation table or scan for 0xFF padding
   - Block sizes: 1200, 5216, 1552, 1440 bytes

---

## Memory Card Compression Usage

GameShark v1.99 uses RLE01 and DEF01 compression when saving data to PlayStation memory cards via the "MEMORY CARD MANAGER" feature.

### Memory Card Save Format

**File Identifier**: `GT_COMPRESS01`

GameShark memory card saves that contain compressed data use the filename `GT_COMPRESS01` (followed by a slot number) to identify compressed save files. This is **not** a separate compression format—it simply marks that the save file contains data compressed with RLE01 or DEF01.

**File Structure**:
```
Offset | Size | Description
-------|------|-------------
0x00   | 2    | "SC" (Sony Computer Entertainment memory card marker)
0x02   | 1    | 0x11 (magic byte)
0x03   | 1    | Card slot parameter
0x04   | 20   | "GT COMPRESSED" (null-padded identifier)
0x18   | N    | Compressed save data (RLE01 or DEF01 format)
```

### Compression Strategy

GameShark uses an adaptive compression strategy to minimize memory card usage:

1. **Try RLE01 first** ("Crunch size" - function at 0x1F0073EC)
   - Fast compression for repetitive data
   - Stores result if smaller than original

2. **Try DEF01 second** ("Supa Crunch" - function at 0x1F00722C)
   - LZ77-variant dictionary compression
   - Stores result if smaller than RLE01 output

3. **Use smallest result**
   - Compares original size vs. RLE01 size vs. DEF01 size
   - Stores the most efficient format
   - Falls back to uncompressed if both methods increase size

**Functions**:
- `FUN_1f00f594` (0x1F00F594): Creates memory card save file header with "SC  GT COMPRESSED" identifier
- `FUN_1f010e44` (0x1F010E44): RLE01 compression attempt
- `FUN_1f010ef8` (0x1F010EF8): DEF01 compression attempt
- `FUN_1f00f780` (0x1F00F780): Reads and decompresses memory card saves

**User Interface**:
- **LEFT TRIGGER 1**: Compress save to same card
- **LEFT TRIGGER 2**: Uncompress save to same card
- **RIGHT TRIGGER 1**: Copy & compress to other card

---

## Usage Examples

### Extract All Blocks from ROM

```bash
GameSharkCompression extract v1.99e.rom
```

Produces:
- `rle01_block1.bin` / `rle01_block1_decompressed.bin` (1,197 / 1,272 bytes)
- `def01_block2.bin` / `def01_block2_decompressed.bin` (5,216 / 7,084 bytes)
- `def01_block3.bin` / `def01_block3_decompressed.bin` (1,552 / 1,952 bytes)
- `rle01_block4.bin` / `rle01_block4_decompressed.bin` (1,440 / 113,440 bytes)

### Compress/Decompress Individual Files

```bash
# Compress
GameSharkCompression compress rle01 input.bin output.rle01
GameSharkCompression compress def01 input.bin output.def01

# Decompress
GameSharkCompression decompress compressed.rle01 output.bin
GameSharkCompression decompress compressed.def01 output.bin
```

**Warning**: Decompressing DEF01 files extracted from ROM may fail if they contain cross-block references. Use the `extract` command which provides proper RAM context.

### Validation Testing

```bash
GameSharkCompression test
```

Validates all four ROM blocks with:
1. Decompression with proper RAM simulation
2. Recompression
3. Round-trip verification

---

## Technical References

- **ROM Analysis**: `v1.99e.rom.c` (Ghidra decompilation)
- **Key Functions**:
  - `FUN_1f007020`: Escape character selection
  - `FUN_1f007110`: DEF01 decompression
  - `FUN_1f00722c`: DEF01 compression  
  - `FUN_1f007548`: RLE01 decompression
  - `FUN_1f0073ec`: RLE01 compression
  - `FUN_1f004b44`: Initialization sequence
- **Documentation**: `TECHNICAL_REFERENCE.md` (Memory architecture, compression table)
   - DEF01: Encode matches >= 5 bytes
   - Below threshold: output literal bytes

4. **Window Limits**:
   - DEF01 search: 500 bytes backwards (or from start if less)
   - DEF01 match: maximum 128 bytes (0x80)
   - Based on decompiler analysis of FUN_1f00722c

5. **Round-Trip Verification**:
   - Compress → Decompress must produce identical output
   - Validates both compression and decompression accuracy
   - Essential for ROM modification workflows

### Error Handling

Both decompressors validate:
- Header signature (5 bytes)
- Compressed size bounds
- Backreference offsets (DEF01)
- Stream termination

Invalid data throws `InvalidDataException` with specific error context.

---

## Usage Examples

### Command-Line Tool

```bash
# Test against ROM data
GameSharkCompression test

# Extract all compressed blocks from ROM
GameSharkCompression extract v1.99e.rom

# Decompress a file (auto-detects format)
GameSharkCompression decompress input.bin output.bin

# Compress a file
GameSharkCompression compress rle01 input.bin output.rle
GameSharkCompression compress def01 input.bin output.def
```

### C# API

```csharp
using GameSharkCompression;

// RLE01: Simple decompression
byte[] compressed = File.ReadAllBytes("data.rle");
byte[] decompressed = Compression.DecompressRLE01(compressed);

// DEF01: Standalone decompression (intra-block references only)
byte[] def01Data = File.ReadAllBytes("data.def");
byte[] result = Compression.DecompressDEF01(def01Data);

// DEF01: Full decompression with RAM context (supports cross-block references)
byte[] ps1Ram = new byte[2 * 1024 * 1024]; // 2MB PlayStation RAM
// ... load previous blocks into ps1Ram at their correct addresses ...
byte[] block2 = File.ReadAllBytes("block2.def");
byte[] decompressed2 = Compression.DecompressDEF01(block2, ps1Ram, 0x80140000);

// Compression (same for both formats, no RAM context needed)
byte[] input = File.ReadAllBytes("input.bin");
byte[] compressedRLE = Compression.CompressRLE01(input);
byte[] compressedDEF = Compression.CompressDEF01(input);
```

---

## Validation

The implementation has been validated against the original GameShark v1.99 ROM:
- All four compressed blocks successfully decompress
- Round-trip compression produces byte-identical decompressed output
- Escape character selection matches ROM behavior
- Header format matches decompiled code structure

**Test Results**: All ROM blocks pass round-trip verification.

---

## References

**GameShark v1.99 ROM Functions**:
- `FUN_1f007020` (0x1F007020): Find least-used byte
- `FUN_1f007110` (0x1F007110): DEF01 decompression
- `FUN_1f00722c` (0x1F00722C): DEF01 compression
- `FUN_1f007548` (0x1F007548): RLE01 decompression
- `FUN_1f0073ec` (0x1F0073EC): RLE01 compression

**Initialization**:
- `FUN_1f004b44` (0x1F004B44): Main initialization (decompresses all blocks)
- `FUN_1f008d84` (0x1F008D84): Decompress DEF01 block 3

**Documentation**:
- See `TECHNICAL_REFERENCE.md` section "Compression" for ROM layout details
- See `v1.99e.rom.c` for complete decompiled source code
