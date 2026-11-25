<div align="center">

# GameShark [v1.99] for Sony PlayStation (1994)

</div>

## Contents

1. [Binary Information](#binary-information)  
    - [Development Team](#development-team)
2. [Memory Architecture](#memory-architecture)
3. [Compression](#compression)
4. [Cheat Code Database](#cheat-code-database)
5. [Disclaimer](#disclaimer)

---

## Hardware Overview

| Logo | Part | Architecture | Memory Density | Access Speed | Voltage / Temp | Package |
|---------|------|---------|---------|---------|---------|---------|
| purple | SST29EE010-120-3C-NH | EEPROM | 1 Mbit (128K x 8) | 120 ns | 5.0V ±5% / 0°C - 70°C | 32-pin PLCC |
| blue | SST29EE010-120-4C-NH | EEPROM | 1 Mbit (128K x 8) | 120 ns | 5.0V ±10% / 0°C - 70°C | 32-pin PLCC |
| interact | SST29EE020-150-4C-NH | EEPROM | 2 Mbit (256K x 8) | 150 ns | 5.0V ±10% / 0°C - 70°C | 32-pin PLCC |
| pro | SST28SF040-120-4C-NH | Sector-Erase Flash | 4 Mbit (512K x 8) | 120 ns | 5.0V ±10% / 0°C - 70°C | 32-pin PLCC |

---

## Binary Information

- **File**: GameShark (USA) v1.99e.rom
- **Size**: 131,072 bytes (0x20000 / 128 KB)
- **Date**: 1998-06-29 18:37:28 PM UTC
- **CRC**: 1E28B1F2
- **MD5**: C1BA5878F49E01682390E8A43D6B16E0
- **Type**: Sony PlayStation (1994) EXP1 ROM
- **Architecture**: MIPS R3000A (32-bit little endian)
- **Title**: GameShark PLAYSTATION Version 1.99
- **Version**: PlayStation Version 1.99
- **Copyright**: Datel Design & Development 1995/1996, Distributed by Interact Multimedia Products 1995/1996

#### Development Team

```
 --- Programming ---
   Gavin Thornton
    Wayne Beckett
  Colin Whitehouse

  --- Hardware ---
    Roy Harding

  --- Graphics ---
    Mark Wallace
   Natalie Kelsall
```

---

## Memory Architecture

#### EXP1 (Parallel I/O)

| Section | Address | Size | Content |
|---------|------|---------|---------|
| header | 0x1F000000 | 256 bytes | EXP1 (Parallel I/O) ROM header |
| text | 0x1F000100 | 78,772 bytes | MIPS R3000A machine code |
| rodata | 0x1F0134B4 | 9,868 bytes | hardcoded pointers, strings, etc. |
| rodata | 0x1F015B40 | 9,408 bytes | compressed data |
| data | 0x1F018000 | 16,384 bytes | saved configuration settings |
| data | 0x1F01C000 | 16,384 bytes | cheat code database |

> This software contains support for additional physical flash memory, which would extend the total ROM size from 128 KB to 256 KB  
> 
> The extended flash memory would only contain additional cheat code data and be mapped to the address range of 0x1F040000 - 0x1F05FFFF (128 KB)  
> 
> Only 112 KB of the extended flash memory would actually be used, increasing the total storage capacity for the cheat code database from 16 KB to 128 KB  
> 
> By default, unmodified retail GameShark Version 1.0 - 1.99 hardware for Sony PlayStation does not have extended physical flash memory  

#### ROM Header
| Address    | Size     | Description | Content |
|------------|----------|-------------|---------|
| 0x1F000000 | 4 bytes  | pointer to post-boot entry point | 0x1F000108 |
| 0x1F000004 | 44 bytes | post-boot ID | "Licensed by Sony Computer Entertainment Inc." |
| 0x1F000030 | 80 bytes | post-boot TTY message | "Game Shark is neither licensed nor endorsed by Sony Computer Entertainment Inc." |
| 0x1F000080 | 4 bytes  | pointer to pre-boot entry point | 0x1F000100 |
| 0x1F000084 | 44 bytes | pre-boot ID | "Licensed by Sony Computer Entertainment Inc." |
| 0x1F0000B0 | 80 bytes | unused | "Game Shark is neither licensed nor endorsed by Sony Computer Entertainment Inc." |
| |
| 0x1F000100 | 8 bytes  | pre-boot entry point | MIPS R3000A machine code (jump + nop delay slot) (goto to 0x1F0003B8) |
| 0x1F000108 | 8 bytes  | post-boot entry point | MIPS R3000A machine code (jump + nop delay slot) (goto to 0x1F0003F0) |

###### For detailed memory architecture:
- [variable map](03_VARIABLE_MAP.MD)
- [string map](04_STRING_RESOURCES.MD)
- [function map](05_FUNCTION_MAP.MD)

---

## Compression

#### RLE01 (Run-Length Encoding)

- simple run-length encoding for repetitive data

#### DEF01 (LZ77-Variant)

- aka "Supa Crunch"
- can reference any data in KSEG0 during deflation, including previously-decompressed blocks
    - serves as a copyright protection mechanism during system boot to prevent unauthorized modification of compressed resources

#### GT COMPRESSED (Memory Card Manager)

This software utilizes an adaptive technique to compress memory card data:

1. perform RLE01 compression test
2. perform DEF01 compression test
3. compare uncompressed size to compression results
4. proceed with most efficient compression method, or leave uncompressed if both methods are inefficient

#### Resources

| Address | Block Size | Type | Compressed Size | Decompressed Size | Destination | Contents |
|----------|-------|------|---------|---------|---------|---------|
| 0x1F015B40 | 1,200 bytes | RLE01 | 1,197 bytes | 1,272 bytes | 0x80020000 | --- |
| 0x1F015FF0 | 5,216 bytes | DEF01 | 4,326 bytes | 7,084 bytes | 0x80140000 | graphics data |
| 0x1F017450 | 1,552 bytes | DEF01 | 1,440 bytes | 1,952 bytes | 0x80150000 | MIPS R3000A machine code |
| 0x1F017A60 | 1,440 bytes | RLE01 | 1,440 bytes| 113,440 bytes | 0x80018000 | 0x00 fill + memory pointers |

###### For detailed format specifications, see [compression documentation](01_COMPRESSION_DOC.MD)

---

## Cheat Code Database

#### Memory Architecture
- **Region**: 0x1F01C000 - 0x1F01FFFF
- **Size**: 16,384 bytes (0x4000 / 16 KB)
- **Type**: raw binary (0xFF fill/padded flash memory)

#### Binary Information
- **File**: USACODES.BIN
- **Size**: 13,518 bytes (0x34FE / 13.2 KB)
- **Date**: 1997-07-30 13:32:34 PM UTC
- **CRC**: F4CDD320
- **MD5**: 479B3888CE61E4BA610BE7691048D7C3
- **Type**: raw binary (custom/proprietary)

#### Binary Source
- **File**: usacodes.txt
- **Size**: 31,269 bytes (0x7A9D / 30.5 KB)
- **Date**: 1997-07-30 13:32:12 PM UTC
- **CRC**: E0C0A8EB
- **MD5**: 016298E8ED5F492C159925766C640C7B
- **Type**: plain-text UTF-8 without BOM, CRLF

#### Supported Code Types

| Opcode | Description | Note |
|--------|-------------|------|
| 3 | 8-bit constant write | |
| 8 | 16-bit constant write | |
| C | 16-bit conditional | not equal compare at 32-bit aligned address |
| D | 16-bit conditional | not equal compare at unaligned address |

> C/D types are officially undocumented and later versions of this software interprets these opcodes differently

###### For detailed format specifications, see [cheat code database documentation](02_CHEAT_DATABASE.MD)

---

## Disclaimer

This documentation was developed using clean-room reverse engineering and is intended for educational purposes only
