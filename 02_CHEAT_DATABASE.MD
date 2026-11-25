# GameShark [v1.99] for Sony PlayStation (1994)

1. [Database Overview](#cheat-code-database)
    - [Structure](#binary-structure)
    - [Dynamic Strings](#dynamic-strings)
2. [Supported Code Types](#supported-code-types)
3. [Runtime Execution Loop](#runtime-execution-loop)

---

## Cheat Code Database

#### Memory Architecture
- **Region**: 0x1F01C000 - 0x1F01FFFF
- **Size**: 16,384 bytes (0x4000 / 16 KB)
- **Type**: raw binary (0xFF fill/padded flash memory)
- **Architecture**: MIPS R3000A (32-bit little endian)

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

#### Binary Structure
```
struct descriptor
{
    int8_t name[];              /*
                                 *  null-terminated string, dynamic length
                                 *  string is always terminated with a single byte (0x00)
                                 *
                                 *  defines either title of game or name of cheat code
                                 *
                                 *  may contain 8-bit opcodes used for dynamic string generation (see: Dynamic Strings)
                                 */

    int8_t count;               /*
                                 *  XY
                                 *  │└───── total count (0x0 - 0xF) (0 min / 15 max)
                                 *  │       defines either the number of cheat codes for a game (if following a game title) or
                                 *  │       the number of individual entries for a cheat code (if following a cheat code name)
                                 *  │
                                 *  └────── always 0x3
                                 *          count may have originally been intended as an ASCII character, possibly either for
                                 *          UI or debugging reasons, but could've lost purpose as newer cheat codes eventually
                                 *          exceeded nine ('9') entries
                                 */

    int8_t enable;              /*
                                 *  ASCII character (always either 0x30 or 0x31)
                                 *
                                 *  bit 0:
                                 *      0 = disabled (default)
                                 *      1 = enabled
                                 *
                                 *  bits 1-7 are unused
                                 */
};

// offset of `code_entry` structure must always be 32-bit aligned, and its corresponding `descriptor` structure is 0x00 fill-padded if necessary
struct code_entry
{
    uint32_t address;           /*
                                 *  address (little endian)
                                 *
                                 *  XYYYYYYY
                                 *  │└─────┴──────── address (28-bit)
                                 *  └─────────────── operation type (4-bit)
                                 *
                                 *  operation type:
                                 *      3 = 8-bit constant write
                                 *      8 = 16-bit constant write
                                 *      C = 16-bit conditional (not equal compare at 32-bit aligned address)
                                 *      D = 16-bit conditional (not equal compare at unaligned address)
                                 */

    uint32_t value;             /*
                                 *  value to write (little endian)
                                 *
                                 *  8/16-bit values are extracted from low bytes
                                 */
};
```

###### The database immediately begins with a null-terminated string, which serves as a placeholder for adding new game entries:
```
2D 2D 2D 20 4E 65 77 20 47 61 6D 65 20 2D 2D 2D 00 30 30
└────────────── --- New Game --- ─────────────┘  │  │  └─── disabled ("0")
                                                 │  └────── zero (0) cheat codes
                                                 └───────── null-terminator
```

#### Dynamic Strings

##### In effort to conserve ROM space, when parsing string characters for `name`, the software may utilize 8-bit opcodes to auto-generate common words found in cheat code names

##### Individual strings for each corresponding opcode are not stored in the ROM. Instead, functionality located at 0x1F009A64 utilizes the opcode to dynamically generate a string in real-time

##### One (1) single space character (' ') is appended to the end of each string to ensure proper separation between words if multiple opcodes are used

| Opcode | String |
|------------|------------|
| 0xF9 | "MISSILES" |
| 0xFA | "MAXIMUM" |
| 0xFB | "UNLIMITED" |
| 0xFC | "HAVE" |
| 0xFD | "TEAM" |
| 0xFE | "HEALTH" |
| 0xFF | "INFINITE" |

###### **Example**: Resident Evil "Infinite Health" cheat code at 0x1F01E410 (line 1304 of usacode.txt)

```
52 45 53 49 44 45 4E 54 20 45 56 49 4C 00 32 30
└─────────── RESIDENT EVIL ──────────┘  │  │  └───── disabled ("0")
                                        │  └──────── two (2) cheat codes
                                        └─────────── null-terminator

FF FE 00 31 31 00 00 00 AC 51 0C 80 60 00 00 00
 │  │  │  │  │  └──┬──┘ └────┬────┘ └─────────┴───── value (0x00000060)
 │  │  │  │  │     │         └────────────────────── address (0x800C51AC)
 │  │  │  │  │     └──────────────────────────────── 32-bit data alignment padding
 │  │  │  │  └────────────────────────────────────── enabled ("1")
 │  │  │  └───────────────────────────────────────── one (1) code entry
 │  │  └──────────────────────────────────────────── null-terminator
 │  └─────────────────────────────────────────────── "HEALTH"
 └────────────────────────────────────────────────── "INFINITE"
```

---

## Supported Code Types

| Opcode | Description | Note |
|--------|-------------|------|
| 3 | 8-bit constant write | |
| 8 | 16-bit constant write | |
| C | 16-bit conditional | not equal compare at 32-bit aligned address |
| D | 16-bit conditional | not equal compare at un/aligned address |

> C/D types are officially undocumented and later versions of this software interprets these opcodes differently  
> Using cheat codes that are not designed for this software is not recommended and **will** result in unexpected behavior

###### Example: 8-bit constant write
```c
```

---
## Runtime Execution Loop

> **Function**: 0x1F00406C  
> **Note**: r/w operations in KUSEG (0x00000000 - 0x7FFFFFFF)

```c
// global variables

uint16_t ByteMaskLo = 0xFF00;           // 0x1F0046FC
uint16_t ByteMaskHi = 0x00FF;           // 0x1F004700

uint32_t ActiveCodeCount;               // 0x1F018010
uint32_t ActiveCodeList;                // 0x1F018038, pointer to code_entry structure
```  

```c
// code excerpt from around 0x1F004300

uint32_t pCodeEntry = &ActiveCodeList;

for (uint32_t i = ActiveCodeCount; i != 0; i--, pCodeEntry += 2)
{
    uint8_t Op = *pCodeEntry >> 28;

    if (Op == 0x08)             // 16-bit write
    {
        *(uint16_t*)*pCodeEntry = (uint16_t)pCodeEntry[1];
    }

    else if (Op == 0x03)        // 8-bit write
    {
        // 16-bit aligned address
        uint16_t* Addr = (uint16_t*)(*pCodeEntry & 0xFFFFFFFE);
		
        uint8_t Src = (uint8_t)pCodeEntry[1];
        uint16_t Dest = *Addr;
		
        if (*pCodeEntry & 1)
        {
            // odd address: replace hi byte
            *Addr = (Dest & ByteMaskHi) | (Src << 8);
        }
        else
        {
            // even address: replace lo byte
            *Addr = (Dest & ByteMaskLo) | Src;
        }
    }

    else if (Op == 0x0D)        // 16-bit conditional (unaligned)
    {
        // read 16-bit value at 28-bit address, cast to 32-bit for comparison
        uint32_t Value = (uint32_t)*(uint16_t*)(*pCodeEntry & 0x0FFFFFFF);

        if (Value != pCodeEntry[1])
        {
            i--;                // skip next code entry
            pCodeEntry += 2;    // advance pointer to next code entry
            if (i == 0) break;  // stop parsing cheats if complete
        }
    }

    else if (Op == 0x0C)        // 16-bit conditional (aligned)
    {
        // read 32-bit value at 32-bit aligned address
        uint32_t Value = *(uint32_t*)(*pCodeEntry & 0xFFFFFFFC);
		
        // extract high 16-bit, cast to 32-bit for comparison
        uint32_t ValueHi = Value >> 16;

        if (ValueHi != pCodeEntry[1])
        {
            i--;                // skip next code entry
            pCodeEntry += 2;    // advance pointer to next code entry
            if (i == 0) break;  // stop parsing cheats if complete
        }
    }
}
```

**Key Points**:
- Executes once per VSync (approximately 60 times per second for NTSC)
- Processes codes sequentially from active code list
- Only processes enabled codes for the current game
- Conditional operations can skip the next code if comparison fails

---

