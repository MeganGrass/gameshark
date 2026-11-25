# GameShark [v1.99] for Sony PlayStation (1994)

## Pointer Tables

### ROM Function Pointers

**Primary Function Pointer Table** (ROM 0x1CD0-0x1CD4):

| Symbol | ROM Offset | Target Address | Type |
|--------|------------|----------------|------|
| PTR_FUN_1f001cd0 | 0x1CD0 | 0x1F0014A8 | ROM Function (Entry Point) |
| PTR_FUN_1f001cd4 | 0x1CD4 | 0x1F001704 | ROM Function (Secondary) |

**Secondary Function Pointer Table** (ROM 0x4B34-0x4B38):

| Symbol | ROM Offset | Target Address | Type |
|--------|------------|----------------|------|
| PTR_FUN_1f004b34 | 0x4B34 | 0x1F000DFC | ROM Function |
| PTR_FUN_1f004b38 | 0x4B38 | 0x1F000F7C | ROM Function |

---

## Function Map

**Memory Region**: EXP1 ROM text section (0x1F000110 - 0x1F0134B4)

| Address | Function | Category | Purpose |
|---------|----------|----------|---------|
| 0x1F000110 | Data Read/Verify/Load | Flash I/O | Core data transfer with mode selection |
| 0x1F0003B8 | Flash Check and Load | Flash I/O | Check flash signature and trigger load |
| 0x1F0003F0 | Flash Check Extended | Flash I/O | Extended flash check with additional processing |
| 0x1F00044C | Flash Hook 1 | Flash I/O | Flash subsystem hook (calls 0x80150008) |
| 0x1F00047C | Flash Hook 2 | Flash I/O | Flash subsystem hook (calls 0x80150010) |
| 0x1F0004AC | Flash Hook 3 | Flash I/O | Flash subsystem hook (calls 0x80150018) |
| 0x1F0004DC | Flash Programming Wrapper | Flash I/O | High-level flash write with status messages |
| 0x1F00053C | Memory Compare | Utility | Optimized memory comparison |
| 0x1F000634 | Flash Write Byte | Flash I/O | Low-level byte write with polling |
| 0x1F00067C | Flash Read Byte | Flash I/O | Low-level byte read with polling |
| 0x1F0006CC | Flash Wait Ready | Flash I/O | Wait for flash operation completion |
| 0x1F0006F4 | Character Output | Debug/Serial | Output single character |
| 0x1F000714 | Character Input | Debug/Serial | Read single character |
| 0x1F000734 | Output Hex Nibble | Debug/Serial | Output single hex digit (0-F) |
| 0x1F000770 | Output Hex Byte | Debug/Serial | Output byte as two hex digits |
| 0x1F0007A4 | Output Hex Word | Debug/Serial | Output 16-bit word as hex |
| 0x1F0007D4 | Output Hex DWord | Debug/Serial | Output 32-bit dword as hex |
| 0x1F000804 | Hex Dump | Debug/Serial | Format and output memory dump |
| 0x1F000A1C | String Output | Debug/Serial | Output null-terminated string |
| 0x1F000A64 | Debug Output Buffer | Debug/Serial | Output buffer with address and hex dump |
| 0x1F000AE8 | Debug Dump Stack | Debug/Serial | Dump stack contents for debugging |
| 0x1F000B40 | System Init 1 | Initialization | Initialize system state (variant 1) |
| 0x1F000B4C | System Init 2 | Initialization | Initialize system state (variant 2) |
| 0x1F000D08 | System Halt Loop | System Control | Infinite loop for system halt |
| 0x1F000DA0 | GPU Reset | Graphics | Reset GPU with mode selection |
| 0x1F000DFC | Entry Point 1 | Initialization | ROM entry point variant 1 |
| 0x1F000F7C | Entry Point 2 | Initialization | ROM entry point variant 2 |
| 0x1F0010E8 | Memory Init | Initialization | Initialize memory regions and buffers |
| 0x1F001210 | Controller Read | Input | Read controller state |
| 0x1F0013A0 | GPU Command | Graphics | Send GPU command |
| 0x1F001408 | GPU Command Pair | Graphics | Send paired GPU commands |
| 0x1F001464 | GPU Setup | Graphics | Configure GPU parameters |
| 0x1F0014A8 | Load Frame Buffer | Graphics | Transfer frame buffer to GPU |
| 0x1F001704 | Read Frame Buffer | Graphics | Read frame buffer from GPU |
| 0x1F0019A0 | Display Control | Graphics | Set display control parameters |
| 0x1F0019D8 | Display Mode | Graphics | Set display mode |
| 0x1F001A24 | Calculate Offset | Graphics | Calculate display offset |
| 0x1F001A54 | Graphics Helper | Graphics | Graphics calculation helper |
| 0x1F001CD8 | Parse Input | Input | Parse controller input data |
| 0x1F001E2C | Graphics Op 1 | Graphics | Graphics operation |
| 0x1F001EBC | Graphics Op 2 | Graphics | Graphics operation |
| 0x1F001EF0 | Graphics Op 3 | Graphics | Graphics operation |
| 0x1F002074 | Sync Operation | Graphics | Graphics synchronization |
| 0x1F0020A4 | Wait VBlank | Graphics | Wait for vertical blank |
| 0x1F0021F0 | DMA Operation | DMA | DMA transfer operation |
| 0x1F00227C | DMA Control | DMA | DMA control function |
| 0x1F0023BC | System Setup | Initialization | System setup routine |
| 0x1F0023DC | Cache Control | System Control | CPU cache control |
| 0x1F00249C | Enter Critical Section | Interrupt/Control | Disable interrupts (syscall 0) |
| 0x1F0024BC | Exit Critical Section | Interrupt/Control | Enable interrupts (syscall 0) |
| 0x1F0024CC | Memory Zero Fill | Utility | Zero-fill memory buffer |
| 0x1F0024F8 | IRQ Dispatcher | Interrupt/Control | Main interrupt handler and callback dispatcher |
| 0x1F0026FC | Change Clear RCnt | Interrupt/Control | Modify timer clear behavior |
| 0x1F00271C | Return From Exception | Interrupt/Control | Exception return handler |
| 0x1F002760 | DMA Init | Interrupt/Control | Initialize DMA interrupt handlers |
| 0x1F0027C4 | Timer Init | Interrupt/Control | Initialize Timer 0 interrupt handlers |
| 0x1F002838 | Zero Memory Region | Utility | memset(ptr, 0, count*4): zero count dwords starting at param_1, decrement loop |
| 0x1F002864 | IRQ Enable Wrapper | Interrupt/Control | Wrapper: call FUN_1f0028bc() to enable/disable IRQ source |
| 0x1F002894 | BIOS ReturnFromException | Interrupt/Control | Wrapper: call BIOS vector 0x000000B0 (ReturnFromException) |
| 0x1F0028BC | IRQ Source Enable/Disable | Interrupt/Control | Hook/unhook IRQ handler (0-10): update DAT_8002d2c4 table, modify I_MASK and DAT_8002d2f0 mask, call ChangeClearRCnt for TMR IRQs (4,5,6) |
| 0x1F0029E4 | BIOS Vector A0h Call | Interrupt/Control | Wrapper: call BIOS A-table entry (vector 0x000000A0) |
| 0x1F0029F4 | Printf Wrapper | Debug/Serial | Empty wrapper (may have been used for debug logging in earlier builds) |
| 0x1F002A0C | ROM Pointer Init | Initialization | Copy ROM pointer table to RAM |
| 0x1F002AEC | Serial Init | Debug/Serial | Initialize serial communication |
| 0x1F002AFC | Serial Handshake | Debug/Serial | Wait for "din" handshake sequence |
| 0x1F002B6C | Write 32-bit Value | Debug/Serial | Write 32-bit value bytewise |
| 0x1F002BDC | Write 16-bit Value | Debug/Serial | Write 16-bit value bytewise |
| 0x1F002C24 | Serial Command | Debug/Serial | Process serial command |
| 0x1F002CF0 | Read 16-bit Value | Debug/Serial | Read two bytes via FUN_1f000634(1) and (2), return big-endian uint16 |
| 0x1F002D50 | Poll-and-Echo Byte | Debug/Serial | Block until DAT_1f020010 & 1, copy DAT_1f060000 → DAT_1f060008, return byte |
| 0x1F002DCC | Command Response Loop | Debug/Serial | Send 0x12345678, repeatedly read (ptr,len) via FUN_1f002c24, echo bytes, send checksum, end with "OK" |
| 0x1F002EB0 | Sparse Table Setter | Utility | Write param_3 into param_1[index] using binary-search mapping of param_2 (0-0x1D, 0xFFFFFFFF) |
| 0x1F003370 | Structure Serializer | Debug/Serial | Emit structure fields (+0x04 through +0x78) as 32-bit values via FUN_1f002b6c() |
| 0x1F003668 | COP0 Register Init | System Control | Initialize CP0 HWREna/EntryLo1/PageMask/Wired/Count/Compare, copy ROM data → 0x80000040-0x8000004C |
| 0x1F003700 | System Function 4 | System Control | System control function |
| 0x1F003BEC | Low Level Op 1 | System Control | Low-level system operation |
| 0x1F003CC4 | Low Level Op 2 | System Control | Low-level system operation |
| 0x1F003D6C | Low Level Op 3 | System Control | Low-level system operation |
| 0x1F003D88 | Low Level Op 4 | System Control | Low-level system operation |
| 0x1F003EDC | Low Level Op 5 | System Control | Low-level system operation |
| 0x1F004050 | Hardware Op 1 | Hardware | Hardware operation |
| 0x1F00406C | Hardware Op 2 | Hardware | Hardware operation |
| 0x1F004704 | Hardware Op 3 | Hardware | Hardware operation |
| 0x1F004720 | Hardware Op 4 | Hardware | Hardware operation |
| 0x1F004738 | Hardware Op 5 | Hardware | Hardware operation |
| 0x1F0047CC | Hardware Op 6 | Hardware | Hardware operation |
| 0x1F0047E8 | Hardware Op 7 | Hardware | Hardware operation |
| 0x1F004840 | Hardware Op 8 | Hardware | Hardware operation |
| 0x1F004930 | Hardware Op 9 | Hardware | Hardware operation |
| 0x1F004958 | Hardware Op 10 | Hardware | Hardware operation |
| 0x1F004B44 | BIOS Function 1 | BIOS/System | BIOS-level function |
| 0x1F004C54 | BIOS Function 2 | BIOS/System | BIOS-level function |
| 0x1F004F8C | BIOS Function 3 | BIOS/System | BIOS-level function |
| 0x1F0051F0 | BIOS Function 4 | BIOS/System | BIOS-level function |
| 0x1F005354 | BIOS Function 5 | BIOS/System | BIOS-level function |
| 0x1F00541C | BIOS Function 6 | BIOS/System | BIOS-level function |
| 0x1F0056E0 | BIOS Function 7 | BIOS/System | BIOS-level function |
| 0x1F0058A4 | BIOS Thunk | BIOS/System | BIOS external thunk |
| 0x1F0060D8 | Font/Char Op 1 | Graphics/Font | Font/character operation |
| 0x1F0060E0 | Font/Char Op 2 | Graphics/Font | Font/character operation |
| 0x1F006138 | Font/Char Op 3 | Graphics/Font | Font/character operation |
| 0x1F006370 | Draw Character | Graphics/Font | Render 8×8 font glyph: loop 8 scan-lines, call FUN_1f006138 to blit glyph row from PTR_DAT_1f0065a8 font table (char - 0x20) to VRAM at 0x8003A910 + (y*0x500) |
| 0x1F00648C | Font Data Swap | Graphics/Font | Swap two 8-dword font data blocks: PTR_DAT_1f0065a8[0x1320..0x133F] ↔ [0x1360..0x137F] |
| 0x1F006EE4 | Math Op 1 | Math/Utility | Mathematical operation |
| 0x1F006EF0 | Math Op 2 | Math/Utility | Mathematical operation |
| 0x1F006F0C | Math Op 3 | Math/Utility | Mathematical operation |
| 0x1F006F40 | Math Op 4 | Math/Utility | Mathematical operation |
| 0x1F006F4C | Math Op 5 | Math/Utility | Mathematical operation |
| 0x1F006FB4 | Math Op 6 | Math/Utility | Mathematical operation |
| 0x1F006FC0 | Math Op 7 | Math/Utility | Mathematical operation |
| 0x1F006FCC | Math Op 8 | Math/Utility | Mathematical operation |
| 0x1F006FD8 | Math Op 9 | Math/Utility | Mathematical operation |
| 0x1F006FE4 | Math Op 10 | Math/Utility | Mathematical operation |
| 0x1F006FF0 | Math Op 11 | Math/Utility | Mathematical operation |
| 0x1F006FFC | Math Op 12 | Math/Utility | Mathematical operation |
| 0x1F007008 | Math Op 13 | Math/Utility | Mathematical operation |
| 0x1F007014 | Math Op 14 | Math/Utility | Mathematical operation |
| 0x1F007020 | Find RLE Escape Char | Compression | Build 256-entry histogram, return least-frequent byte (0x00-0xFF) for use as RLE marker |
| 0x1F007110 | DEF0 Decompress | Compression | Decompress DEF0 format (LZ77 variant) |
| 0x1F00722C | DEF0 Compress | Compression | Compress to DEF0 format (LZ77 variant) |
| 0x1F0073EC | RLE Compress | Compression | RLE encoder: copy 5-byte header from 0x1F013998, find escape byte, encode runs ≥4 as [ESC,count,byte], literal bytes (or ESC,0 for ESC itself), store compressed size at offset +6 (32-bit BE) |
| 0x1F007548 | RLE Decompress | Compression | Run-length encoding decompression |
| 0x1F007640 | Compression Helper 1 | Compression | Compression helper function |
| 0x1F007748 | Compression Helper 2 | Compression | Compression helper function |
| 0x1F007894 | Compression Helper 3 | Compression | Compression helper function |
| 0x1F0079CC | Compression Helper 4 | Compression | Compression helper function |
| 0x1F007A80 | Data Processing 1 | Data/Transfer | Data processing function |
| 0x1F007A88 | Data Processing 2 | Data/Transfer | Data processing function |
| 0x1F007B20 | Data Processing 3 | Data/Transfer | Data processing function |
| 0x1F007BF4 | Dialog Display | UI/Display | Display dialog box |
| 0x1F007C90 | Dialog Helper 1 | UI/Display | Dialog helper function |
| 0x1F007CC8 | Dialog Helper 2 | UI/Display | Dialog helper function |
| 0x1F008040 | Menu Handler 1 | UI/Menu | Menu event handler |
| 0x1F008178 | Menu Handler 2 | UI/Menu | Menu event handler |
| 0x1F00868C | Menu State 1 | UI/Menu | Menu state machine |
| 0x1F008A28 | Menu State 2 | UI/Menu | Menu state machine |
| 0x1F008D84 | Menu State 3 | UI/Menu | Menu state machine |
| 0x1F008DAC | Menu State 4 | UI/Menu | Menu state machine |
| 0x1F008DF8 | Menu State 5 | UI/Menu | Menu state machine |
| 0x1F008EB8 | Count Enabled Codes | Game Management | Iterate Global.codeCount (+0x50) entries in PTR_DAT_1f013534, count non-zero (enabled) flags, store result → Global.enabledCodeCount (+0x1C) |
| 0x1F008F18 | String Compare | String/Utility | strcmp(): byte-by-byte compare until null; return -1 if str1<str2, 0 if equal, 1 if str1>str2 |
| 0x1F008F74 | Align to 4 Bytes | Utility | Round up to next 4-byte boundary: if (addr & 3) return (addr & ~3) + 4; else return addr |
| 0x1F008F94 | Insert Sorted Game | Game Management | Insert game into sorted list |
| 0x1F0090E8 | Init New Game | Game Management | Copy 0x4000-byte "New Game" template from 0x1F01C000 → PTR_DAT_1f013de8, conditionally append 0x1C000 bytes from 0x1F040000 if flash present, duplicate → PTR_DAT_1f013dfc, terminate with 0xFFFFFFFF |
| 0x1F0091E8 | Load Game List | Game Management | Load and process game database |
| 0x1F009340 | Code Helper 1 | Code Management | Code manipulation helper |
| 0x1F0093EC | Code Helper 2 | Code Management | Code manipulation helper |
| 0x1F009450 | Code Helper 3 | Code Management | Code manipulation helper |
| 0x1F009480 | Code Offset Calc | Code Management | Calculate code offset |
| 0x1F0094B8 | Parse Game Entry | Game Management | Parse game entry and set global state |
| 0x1F009620 | Get Game By Index | Game Management | Retrieve game entry by index |
| 0x1F009784 | Navigate Code List | Code Management | Navigate to specific code in list |
| 0x1F0098BC | Display Code List | UI/Display | Render scrollable code list |
| 0x1F009A64 | Code Name Parser | Code Management | Parse code name string |
| 0x1F009D7C | Code Display Helper | UI/Display | Code display helper |
| 0x1F009F98 | Delete Code | Code Management | Delete code from game |
| 0x1F00A024 | Add Code | Code Management | Add new code to game |
| 0x1F00A208 | Code Edit 1 | Code Management | Code editing function |
| 0x1F00A344 | Code Edit 2 | Code Management | Code editing function |
| 0x1F00A530 | Code Edit 3 | Code Management | Code editing function |
| 0x1F00A5FC | Code Edit 4 | Code Management | Code editing function |
| 0x1F00A674 | Code Edit 5 | Code Management | Code editing function |
| 0x1F00A730 | Code Edit 6 | Code Management | Code editing function |
| 0x1F00A828 | Code Save | Code Management | Save code changes |
| 0x1F00ACE4 | Get Icon Data | Graphics | Extract memory card icon data |
| 0x1F00ADAC | Memory Card Op 1 | Memory Card | Memory card operation |
| 0x1F00ADF8 | Copy String Limited | String/Utility | Copy string with length limit |
| 0x1F00AE28 | Memory Card Op 2 | Memory Card | Memory card operation |
| 0x1F00AE48 | Memory Card Op 3 | Memory Card | Memory card operation |
| 0x1F00AF58 | Memory Card Op 4 | Memory Card | Memory card operation |
| 0x1F00B038 | Memory Card Op 5 | Memory Card | Memory card operation |
| 0x1F00B084 | Memory Card Op 6 | Memory Card | Memory card operation |
| 0x1F00B560 | Memory Card Op 7 | Memory Card | Memory card operation |
| 0x1F00B734 | Memory Card Op 8 | Memory Card | Memory card operation |
| 0x1F00B9B8 | Memory Card Op 9 | Memory Card | Memory card operation |
| 0x1F00BC80 | Memory Card Op 10 | Memory Card | Memory card operation |
| 0x1F00BD50 | Memory Card Op 11 | Memory Card | Memory card operation |
| 0x1F00BED8 | Memory Card Op 12 | Memory Card | Memory card operation |
| 0x1F00C4FC | Hex Editor 1 | Code Editor | Hex editor function |
| 0x1F00C5DC | Hex Editor 2 | Code Editor | Hex editor function |
| 0x1F00CB50 | Hex Editor 3 | Code Editor | Hex editor function |
| 0x1F00D0DC | Input Handler 1 | Input | Input event handler |
| 0x1F00D170 | Input Handler 2 | Input | Input event handler |
| 0x1F00D1B8 | Input Handler 3 | Input | Input event handler |
| 0x1F00D214 | Input Handler 4 | Input | Input event handler |
| 0x1F00D2C4 | Input Handler 5 | Input | Input event handler |
| 0x1F00D2E4 | Input Helper | Input | Input helper function |
| 0x1F00D660 | String Length | String/Utility | Calculate string length |
| 0x1F00D6D4 | Memory Card Read | Memory Card | Read data from memory card |
| 0x1F00D780 | String Copy | String/Utility | Copy string |
| 0x1F00D800 | Memory Card Init | Memory Card | Initialize memory card subsystem |
| 0x1F00D8C8 | Memory Card Status | Memory Card | Get memory card status |
| 0x1F00DA34 | Memory Card Format | Memory Card | Format memory card |
| 0x1F00DB28 | Memory Card Verify | Memory Card | Verify memory card data |
| 0x1F00DBC8 | Memory Card Erase | Memory Card | Erase memory card block |
| 0x1F00DCE0 | String Length (dup) | String/Utility | Calculate string length (duplicate) |
| 0x1F00DD44 | Text Processing | String/Utility | Text processing function |
| 0x1F00DE00 | GPU Init | Graphics | Initialize GPU subsystem |
| 0x1F00DE30 | Read Controller | Input | Read controller button state |
| 0x1F00DEB4 | Display Text at Pos | UI/Display | Render text at screen position |
| 0x1F00DF44 | Display Centered Text | UI/Display | Render centered text |
| 0x1F00DFA0 | Display Padded Text | UI/Display | Render text with padding/centering |
| 0x1F00E110 | Display Selected Text | UI/Display | Render text with selection markers |
| 0x1F00E2D0 | Display Character Glyph | UI/Display | Render single character from font |
| 0x1F00E404 | Display Hex Digit | UI/Display | Render single hex digit (0-F) |
| 0x1F00E450 | Display Hex Digit (cond) | UI/Display | Conditionally render hex digit |
| 0x1F00E4B4 | Display Byte as Hex | UI/Display | Render byte as two hex digits |
| 0x1F00E518 | Display Word as Hex | UI/Display | Render word as four hex digits |
| 0x1F00E588 | Display Number 1 | UI/Display | Display number function |
| 0x1F00E5EC | Display Number 2 | UI/Display | Display number function |
| 0x1F00E658 | Display Number 3 | UI/Display | Display number function |
| 0x1F00E6BC | Display Number 4 | UI/Display | Display number function |
| 0x1F00E720 | Display Number 5 | UI/Display | Display number function |
| 0x1F00E780 | Display Number 6 | UI/Display | Display number function |
| 0x1F00E7F4 | Format Number | UI/Display | Number formatting function |
| 0x1F00E948 | Display Helper 1 | UI/Display | Display helper function |
| 0x1F00EA9C | Display Title Bar | UI/Display | Render menu title bar |
| 0x1F00EB74 | Display Footer | UI/Display | Render menu footer |
| 0x1F00EC74 | Display Border Box | UI/Display | Render rectangular border |
| 0x1F00EDF4 | Menu Frame 1 | UI/Menu | Menu frame rendering |
| 0x1F00EE24 | Menu Frame 2 | UI/Menu | Menu frame rendering |
| 0x1F00EEBC | Menu Frame 3 | UI/Menu | Menu frame rendering |
| 0x1F00EF3C | Menu Frame 4 | UI/Menu | Menu frame rendering |
| 0x1F00EFFC | Menu Render 1 | UI/Menu | Menu rendering function |
| 0x1F00F594 | Menu Render 2 | UI/Menu | Menu rendering function |
| 0x1F00F680 | Menu Render 3 | UI/Menu | Menu rendering function |
| 0x1F00F754 | Menu Render 4 | UI/Menu | Menu rendering function |
| 0x1F00F780 | Menu Render 5 | UI/Menu | Menu rendering function |
| 0x1F00FF38 | Credits Screen 1 | UI/Credits | Credits screen function |
| 0x1F00FF88 | Credits Screen 2 | UI/Credits | Credits screen function |
| 0x1F01005C | Credits Screen 3 | UI/Credits | Credits screen function |
| 0x1F0100FC | Credits Screen 4 | UI/Credits | Credits screen function |
| 0x1F01020C | Main Menu 1 | UI/Menu | Main menu function |
| 0x1F010364 | Main Menu 2 | UI/Menu | Main menu function |
| 0x1F0103A0 | Main Menu 3 | UI/Menu | Main menu function |
| 0x1F0103D4 | Main Menu 4 | UI/Menu | Main menu function |
| 0x1F01043C | Game Select 1 | UI/Menu | Game selection function |
| 0x1F010598 | Game Select 2 | UI/Menu | Game selection function |
| 0x1F010618 | Game Select 3 | UI/Menu | Game selection function |
| 0x1F010680 | Game Select 4 | UI/Menu | Game selection function |
| 0x1F0106CC | Code Select 1 | UI/Menu | Code selection function |
| 0x1F01095C | Code Select 2 | UI/Menu | Code selection function |
| 0x1F010AD4 | Code Select 3 | UI/Menu | Code selection function |
| 0x1F010BB4 | Code Select 4 | UI/Menu | Code selection function |
| 0x1F010D10 | Code Select 5 | UI/Menu | Code selection function |
| 0x1F010E44 | Code Select 6 | UI/Menu | Code selection function |
| 0x1F010EF8 | Code Edit Screen 1 | UI/Editor | Code editing screen |
| 0x1F010FD4 | Code Edit Screen 2 | UI/Editor | Code editing screen |
| 0x1F011034 | Code Edit Screen 3 | UI/Editor | Code editing screen |
| 0x1F011158 | Code Edit Screen 4 | UI/Editor | Code editing screen |
| 0x1F011394 | Input Screen 1 | UI/Input | Character input screen |
| 0x1F0113FC | Input Screen 2 | UI/Input | Character input screen |
| 0x1F0115B8 | Input Screen 3 | UI/Input | Character input screen |
| 0x1F01160C | Input Screen 4 | UI/Input | Character input screen |
| 0x1F01165C | Input Screen 5 | UI/Input | Character input screen |
| 0x1F011920 | Hex Input 1 | UI/Input | Hex value input |
| 0x1F011974 | Hex Input 2 | UI/Input | Hex value input |
| 0x1F011A00 | Hex Input 3 | UI/Input | Hex value input |
| 0x1F011D1C | Memory Card Manager 1 | UI/MemCard | Memory card manager screen |
| 0x1F011D7C | Memory Card Manager 2 | UI/MemCard | Memory card manager screen |
| 0x1F011DD4 | Memory Card Manager 3 | UI/MemCard | Memory card manager screen |
| 0x1F011E10 | Memory Card Manager 4 | UI/MemCard | Memory card manager screen |
| 0x1F011E40 | Memory Card Manager 5 | UI/MemCard | Memory card manager screen |
| 0x1F011ECC | Memory Card List 1 | UI/MemCard | Memory card file list |
| 0x1F011F74 | Memory Card List 2 | UI/MemCard | Memory card file list |
| 0x1F011FDC | Memory Card List 3 | UI/MemCard | Memory card file list |
| 0x1F012050 | Memory Card Op Screen 1 | UI/MemCard | Memory card operation screen |
| 0x1F01219C | Memory Card Op Screen 2 | UI/MemCard | Memory card operation screen |
| 0x1F0121E4 | Memory Card Op Screen 3 | UI/MemCard | Memory card operation screen |
| 0x1F012274 | Memory Card Op Screen 4 | UI/MemCard | Memory card operation screen |
| 0x1F0122EC | Memory Card Op Screen 5 | UI/MemCard | Memory card operation screen |
| 0x1F0123F0 | Memory Card Op Screen 6 | UI/MemCard | Memory card operation screen |
| 0x1F0124EC | Memory Card Op Screen 7 | UI/MemCard | Memory card operation screen |
| 0x1F013470 | Main Loop | System Control | Main program loop |

---

## Startup/Initialization

The main initialization routine (FUN_1f004b44 at 0x1F004B44) is called from the post-boot entry point (FUN_1f0003f0 at 0x1F0003F0) after parallel I/O hardware detection.

**Pre-Boot Entry (FUN_1f0003b8 at 0x1F0003B8)**:
- Checks parallel I/O at 0x1F060000 for 'W' signature
- If signature present, calls flash updater (FUN_1f000110)

**Post-Boot Entry (FUN_1f0003f0 at 0x1F0003F0)**:
- Checks parallel I/O at 0x1F060000 for 'W' signature
- If signature present, calls flash updater (FUN_1f000110)
- Checks register 0x1F020018 bit 0
- If set, calls main initialization (FUN_1f004958 then FUN_1f004b44)

**Main Initialization Sequence (FUN_1f004b44)**:

1. **Clear Display Flags**
   - Zero 0x8014FFFA (2 bytes)

2. **Zero Low RAM** (0x80000000-0x80038000)
   - Clear 0xE000 dwords (57,344 bytes / 56 KB)
   - Loop writes 4-byte aligned zeros

3. **Decompress RLE01 Graphics** (FUN_1f007548)
   - Source: 0x1F017A60
   - Destination: 0x80018000
   - Decompresses first RLE01 compressed block

4. **Decompress DEF01 Data** (FUN_1f007110)
   - Source: 0x1F015FF0
   - Destination: 0x80140000
   - Decompresses first DEF01 compressed block

5. **Initialize GPU Subsystem** (FUN_1f00de00)
   - Setup display mode and video output
   - Initialize frame buffers
   - Configure GPU registers

6. **Initialize BIOS Functions** (FUN_1f005354)
   - Setup interrupt handlers
   - Configure system fonts and text rendering
   - Display version string "PlayStation Version 1.99"

7. **Zero Global State** (0x80011000)
   - Clear 0x400 dwords (4,096 bytes / 4 KB)
   - First pass: offset 0x0-0xFFF

8. **Zero Extended Global State**
   - Clear 0x400 dwords (4,096 bytes / 4 KB)
   - Second pass: offset 0x1000-0x1FFF

9. **Initialize System Services** (FUN_1f006ee4)
   - Register handler at 0x20000001
   - Setup interrupt vector 0x30

10. **Decompress DEF01 Resources** (FUN_1f008d84)
    - Source: 0x1F017450
    - Destination: 0x80150000
    - Decompresses second DEF01 compressed block

11. **Decompress RLE01 Menu Resources** (FUN_1f007548)
    - Source: 0x1F015B40
    - Destination: 0x80020000
    - Decompresses second RLE01 compressed block

12. **Initialize Global State Variables**
    - Set Global+0x38 = 0xFFFFFFFD (gameIndexOrMenu = -3)
    - Set Global+0x14 = 1 (currentSelection = 1)
    - Set Global+0x2C = 1 (counterOrFlag2 = 1)
    - Set Global+0x1B4 = 1 (menuRefreshFlag = 1)

---

### Flash Memory I/O Subsystem

These functions handle all flash ROM operations including read, write, and status polling.

#### 0x1F000110 - Data Read/Verify/Load (Core Transfer)

**Classification**: Primary I/O handler  
**Call Graph**: Called by FUN_1f0003b8, FUN_1f0003f0

**Operation Modes**:
- **'U' (0x55)**: Upload mode - read from flash
- **'X' (0x58)**: Execute mode - write to flash

**Hardware Registers**:
- `0x1F060000` - Flash control/status register
- Uses RAM buffer pointers from table at ROM 0x1F013530

**Return Status Codes**:

| Code | Meaning | Condition |
|------|---------|-----------|
| 0x00 | Success | Operation completed successfully |
| 0x01 | --- | --- |
| 0x02 | Verification failure | Data mismatch after write |
| 0x03 | Write failure | Flash write operation failed |
| 0x05 | Mode error | Invalid mode byte |
| 0x55 | Hardware error | Flash busy or unavailable |

**Usage Pattern**:
```c
// Typical call sequence
if (DAT_1f060000 == 'W') {
    status = FUN_1f000110();  // Perform flash operation
    if (status != 0x00) {
        // Handle error
    }
}
```

#### 0x1F0004DC - Flash Programming Wrapper

**Classification**: High-level wrapper  
**Call Graph**: → FUN_1f000a1c (message output) → FUN_80150020 (flash write)

**Behavior Sequence**:
1. Output "program flash in" message (ROM string at 0x1F0134C0)
2. Call `FUN_80150020()` to perform actual flash programming
3. Output "program flash out" message (ROM string at 0x1F0134D4)

**Purpose**: User-facing flash write operation with progress feedback

#### 0x1F000634 - Flash Write Byte (Low-Level)

**Classification**: Primitive hardware operation  
**Registers Used**:
- `0x1F020010` - Status register (bit 0 = ready flag)
- `0x1F060008` - Flash data register (write)
- `0x1F060000` - Flash status register (return value)

**Algorithm**:
```c
while ((DAT_1f020010 & 0x01) == 0);  // Wait for ready
DAT_1f060008 = byte_value;           // Write byte
return DAT_1f060000;                 // Return status
```

**Timing**: Blocking poll loop - waits indefinitely for hardware ready

#### 0x1F00067C - Flash Read Byte (Low-Level)

**Classification**: Primitive hardware operation  
**Registers Used**:
- `0x1F020010` - Status register (bit 0 = ready flag)
- `0x1F060000` - Flash data register (read)
- `0x1F060008` - Flash echo register

**Algorithm**:
```c
while ((DAT_1f020010 & 0x01) == 0);  // Wait for ready
DAT_1f060008 = DAT_1f060000;         // Echo read value
return DAT_1f060000;                 // Return data
```

**Note**: Echo pattern may be for signal integrity verification

#### 0x1F0006CC - Flash Wait Ready

**Classification**: Synchronization primitive  
**Register**: `0x1F01FFF1` - ROM region status register

**Wait Condition**:
```c
while ((DAT_1f01fff1 & 0xC2) != 0x80);
```

**Status Bits**:
- Bit 7 (0x80): Operation complete flag
- Bits 6,1 (0x42): Error/busy flags (must be clear)

**Usage**: Called before flash operations to ensure hardware is ready

---

### Debug and Serial I/O Subsystem

Functions for debugging output, likely to a serial port or development console.

#### 0x1F0006F4 - Character Output (Primitive)

**Classification**: Low-level serial output  
**Parameters**: 
- `param_1: byte` - Character to output

**Implementation**: Calls `FUN_1f000634` (flash write) to output character

**Usage**: Base primitive for all text output functions

#### 0x1F000714 - Character Input (Primitive)

**Classification**: Low-level serial input  
**Returns**: `byte` - Character read

**Implementation**: Calls `FUN_1f00067c` (flash read) to read character

**Usage**: Base primitive for all text input functions

#### 0x1F000A1C - String Output

**Classification**: High-level text output  
**Parameters**:
- `param_1: char*` - Pointer to null-terminated string

**Algorithm**:
```c
while (*string != '\0') {
    FUN_1f0006f4(*string);  // Output each character
    string++;
}
```

**Performance**: Iterative character-by-character output

**Usage Examples**:
- Status messages during flash programming
- Menu text rendering
- Error message display

#### 0x1F000804 - Hex Dump Formatter

**Classification**: Debug utility  
**Parameters**:
- `param_1: byte*` - Data buffer start address
- `param_2: int` - Total bytes to dump
- `param_3: int` - Bytes per line (typical: 0x10)

**Output Format**:
```
<8-digit hex address>  <hex bytes>  <ASCII representation>
XXXXXXXX  XX XX XX XX XX XX XX XX  ................
```

**Character Rendering Rules**:
- Bytes < 0x20 (non-printable) → displayed as '.' (0x2E)
- Bytes >= 0x20 → displayed as ASCII character

**Line Structure**:
- Address output via `FUN_1f0007d4` (32-bit hex formatter)
- 16 bytes output as hex pairs via `FUN_1f000770` (byte hex formatter)
- 16 bytes output as ASCII characters
- Lines separated by CR+LF (0x0D, 0x0A)

**Usage**: Memory inspection, flash verification, debugging

---

### Utility Functions

General-purpose helper functions used across multiple subsystems.

#### 0x1F00053C - Optimized Memory Compare

**Classification**: Performance-critical utility  
**Parameters**:
- `param_1: char*` - Source buffer
- `param_2: uint` - Comparison length (bytes)
- `param_3: char*` - Comparison buffer

**Returns**: 
- `0` - Buffers are identical
- `1` - Buffers differ

**Optimization Strategy**:
1. **Alignment handling**: Process unaligned prefix (up to 3 bytes)
2. **4-byte comparison**: Main loop compares 4 bytes per iteration
3. **Loop unrolling**: Reduces branch overhead

**Performance**:
- Unaligned path: ~1.25 bytes/cycle
- Aligned path: ~4 bytes/cycle (4x faster)

**Algorithm Outline**:
```c
// Handle unaligned prefix (1-3 bytes)
remaining = length & 3;
for (i = 0; i < remaining; i++) {
    if (src[i] != cmp[i]) return 1;
}

// 4-byte aligned comparison
for (i = remaining; i < length; i += 4) {
    if (*(uint32*)(src+i) != *(uint32*)(cmp+i)) return 1;
}
return 0;
```

**Usage Context**:
- Flash verification after write
- Game list comparison
- Cheat code validation

---

### Graphics Subsystem

Functions for GPU frame buffer management and transfer.

#### 0x1F0014A8 - Load Frame Buffer to GPU

**Classification**: High-level graphics primitive  
**Parameters**:
- `param_1: undefined4` - Source RAM buffer address
- `param_2: uint` - Configuration flags and color depth

**Hardware Registers**:
- `GPU_REG1` (0x1F801814) - GPU status/control
- `GPU_REG0` (0x1F801810) - GPU command/data FIFO
- DMA GPU registers (0x1F8010A0-0x1F8010A8)

**Frame Buffer Configuration**:
- **Source coordinates**: Read from `DAT_1f002adc`, `DAT_1f002ae0`
- **Dimensions**: Read from `DAT_1f002ae4`
- **Dimension clamping**:
  - PAL/NTSC mode check via `DAT_8002d268`
  - Max width: 0x3FF (1023 pixels)
  - Max height: 0x1FF (511) for NTSC, 0x3FF (1023) for PAL

**Transfer Modes**:

1. **Fast Path (64-byte aligned)**:
   - Condition: `(source_x & 0x3F) == 0 && (width & 0x3F) == 0`
   - Uses direct GPU commands (0xE6000000, 0x2000000)
   - Minimal overhead

2. **DMA Transfer Path**:
   - Condition: Unaligned or large transfers
   - Uses GPU DMA channel 2
   - Commands: 0xE3000000 (env), 0xE4000000 (clip), 0xE5000000 (offset)
   - Block size calculation via `FUN_1f001a24`

**Call Sequence**:
```c
// Configure GPU for transfer
GPU_REG1 = 0x04000000;  // Reset GPU FIFO
GPU_REG0 = 0x01000000;  // Set transfer mode
GPU_REG0 = 0xA0000000;  // VRAM write command
GPU_REG0 = coords;      // Top-left position
GPU_REG0 = dimensions;  // Width × height

// Transfer via DMA or direct writes
if (aligned_fast_path) {
    // Direct GPU FIFO writes
} else {
    // Configure DMA channel 2
    DMA_GPU_MADR = source_buffer;
    DMA_GPU_BCR = block_size;
    DMA_GPU_CHCR = 0x01000201;  // Start DMA
}
```

**Returns**: `0` (always succeeds)

#### 0x1F001704 - Read Frame Buffer from GPU

**Classification**: High-level graphics primitive  
**Parameters**:
- `param_1: undefined4` - Destination RAM buffer
- `param_2: undefined4*` - Frame parameter structure pointer

**Returns**:
- `0x00000000` - Success
- `0xFFFFFFFF` - Timeout or error

**Hardware Registers**: Same as Load Frame Buffer

**GPU Command Sequence**:
```c
// Wait for GPU ready
while ((GPU_REG1 & 0x04000000) == 0) {
    if (timeout_check()) return 0xFFFFFFFF;
}

GPU_REG1 = 0x04000000;  // Reset FIFO
GPU_REG0 = 0x01000000;  // Set mode
GPU_REG0 = 0xA0000000;  // VRAM read command
GPU_REG0 = coords;      // Source position
GPU_REG0 = dimensions;  // Read size
```

**Transfer Method**:
- Reads pixel data from GPU via DMA channel 2
- Block size: `(width * height + 1) / 2` rounded to 16-word blocks
- Data format: 16-bit pixels (R5G5B5)

**Error Handling**:
- Polls `FUN_1f001ef0()` for timeout conditions
- Returns `0xFFFFFFFF` if GPU becomes unresponsive

**Usage**: Screen capture, icon loading, texture readback

---

### Interrupt and Control Subsystem

These functions handle PS1 interrupt management, critical sections, and initialization.

#### 0x1F00249C - Enter Critical Section

**Classification**: BIOS wrapper  
**Assembly**: `syscall 0` (MIPS instruction)

**Purpose**: Disable interrupts to enter a critical section where atomic operations are required.

**Call Graph**: Called before modifying shared state or hardware registers

**Usage Pattern**:
```c
FUN_1f00249c();  // Disable interrupts
// ... critical section code ...
FUN_1f0024bc();  // Re-enable interrupts
```

#### 0x1F0024BC - Exit Critical Section

**Classification**: BIOS wrapper  
**Assembly**: `syscall 0` (MIPS instruction)

**Purpose**: Re-enable interrupts after critical section completion.

**Note**: The same syscall number is used; context determines behavior via BIOS state.

#### 0x1F0024CC - Memory Zero Fill

**Classification**: Utility function  
**Parameters**:
- `param_1: uint*` - Buffer start address
- `param_2: int` - Number of 32-bit words to clear

**Algorithm**:
```c
void zero_fill(uint* buffer, int count) {
    int remaining = count - 1;
    if (count != 0) {
        do {
            *buffer = 0;
            remaining--;
            buffer++;
        } while (remaining != -1);
    }
}
```

**Performance**: Simple linear loop, no MIPS memset optimization

**Usage**: Clear state structures, initialize buffers

#### 0x1F0024F8 - Main IRQ Dispatcher

**Classification**: Interrupt service routine (ISR)  
**Hardware Access**:
- `PTR_I_STAT` (0x1F801070) - Interrupt status register
- `PTR_I_MASK` (0x1F801074) - Interrupt mask register
- `DAT_8002d2f0` - RAM interrupt enable mask

**Interrupt Handler Table**: `DAT_8002d2c4` (11 function pointers, one per IRQ source)

**Dispatch Logic**:
```c
void irq_dispatcher() {
    DAT_8002d2c2 = 1;  // Mark ISR active

    // Get pending IRQs (status & mask & enable)
    uint pending = I_STAT & I_MASK & DAT_8002d2f0;

    while (pending != 0) {
        for (int i = 0; i < 11; i++) {
            if ((pending & 1) && handler_table[i] != NULL) {
                I_STAT = ~(1 << i);  // ACK interrupt
                handler_table[i]();  // Call handler
            }
            pending >>= 1;
        }
        pending = I_STAT & I_MASK & DAT_8002d2f0;
    }

    DAT_8002d2c2 = 0;  // Clear ISR active flag
    ReturnFromException();
}
```

**Watchdog Protection**:
- If IRQ remains asserted for > 0x100 iterations: disable that IRQ source
- Prevents infinite interrupt loops

#### 0x1F002760 - DMA Interrupt Init

**Classification**: Initialization routine  
**Returns**: `undefined*` - Pointer to DMA handler structure (0x8001D340)

**Setup Sequence**:
1. Zero-fill DMA state buffer (9 words at 0x8002D330)
2. Disable DMA interrupts: `DMA_DICR = 0`
3. Register interrupt handler 3 (DMA channel) → `DAT_8001d1dc`
4. Set `DAT_8002d330 = 1` (DMA system active)

**Purpose**: Enable DMA-driven transfers for GPU, CD-ROM, and memory card operations

#### 0x1F0027C4 - Timer 0 Interrupt Init

**Classification**: Initialization routine  
**Returns**: `undefined*` - Pointer to timer handler structure (0x8001D688)

**Setup Sequence**:
1. Configure Timer 0: `TMR_HRETRACE_MODE = 0x107`
   - Bits: Enable, IRQ on target, sysclock/8
2. Call `FUN_1f002894(0)` - BIOS timer setup
3. Register RCNT clear callback for timer 3
4. Register interrupt handler 0 (VBlank) → `DAT_8001d63c`
5. Set `DAT_8002d364 = 1` (Timer system active)

**Purpose**: VBlank timing and frame synchronization

#### 0x1F0028BC - IRQ Source Enable/Disable

**Classification**: Interrupt control primitive  
**Parameters**:
- `param_1: uint` - IRQ source number (0-10)
- `param_2: int` - Handler address (0 = disable, non-zero = enable)

**Returns**: Previous handler address

**Register Modification**:
```c
int old_handler = handler_table[source];

if (param_2 != old_handler && interrupt_system_active) {
    uint old_mask = I_MASK;
    I_MASK = 0;  // Disable all IRQs temporarily

    if (param_2 == 0) {
        // Disable source
        uint clear_bit = ~(1 << source);
        handler_table[source] = 0;
        I_MASK = old_mask & clear_bit;
        DAT_8002d2f0 &= clear_bit;
    } else {
        // Enable source
        uint set_bit = 1 << source;
        handler_table[source] = param_2;
        I_MASK = old_mask | set_bit;
        DAT_8002d2f0 |= set_bit;
    }

    // Special handling for timers (sources 4,5,6)
    if (source == 4) ChangeClearRCnt(0, param_2 == 0);
    if (source == 5) ChangeClearRCnt(1, param_2 == 0);
    if (source == 6) ChangeClearRCnt(2, param_2 == 0);
}

return old_handler;
```

**IRQ Sources**:
- 0: VBlank
- 1: GPU
- 2: CD-ROM
- 3: DMA
- 4: Timer 0 (RCnt 0)
- 5: Timer 1 (RCnt 1)
- 6: Timer 2 (RCnt 2)
- 7: Memory card / controller
- 8: SIO
- 9: SPU
- 10: Lightgun / controller IRQ

#### 0x1F002A0C - ROM Pointer Table Initialization

**Classification**: Startup routine  
**Hardware Access**: Copies ROM data pointers to RAM globals

**Mapping Operations**:
```c
void init_rom_pointers() {
    _DAT_0003396c = DAT_1f002a7c;  // Copy ROM offset 0x2A7C
    _DAT_00033afc = DAT_1f002a80;  // Copy ROM offset 0x2A80
    _DAT_00033b00 = DAT_1f002a84;  // Copy ROM offset 0x2A84
    _DAT_00033b0c = DAT_1f002a88;  // Copy ROM offset 0x2A88
    _DAT_0002d298 = PTR_DMA_DPCR_1f002aac;  // DMA control pointer
}
```

**Purpose**: Initialize RAM working copies of ROM pointer tables for faster access

**Call Timing**: Early in boot sequence, before main loop

#### 0x1F002AFC - Serial Handshake Wait

**Classification**: Debug/communication synchronizer  
**Hardware**: Uses `FUN_1f000634` (flash/serial byte read)

**Handshake Sequence**:
```c
void wait_for_handshake() {
    do {
        do {
            c = FUN_1f000634(100);  // Read byte with timeout
        } while (c != 'd');
        c = FUN_1f000634(0x6f);
    } while (c != 'i');
    // Expects "din" sequence (0x64 0x69 0x6E)
}
```

**Purpose**: Wait for external device (PC tool, debugger) to send "din" before proceeding

**Usage Context**: Development/debug builds, memory card programming tools

#### 0x1F002B6C - Write 32-bit Value (Bytewise)

**Classification**: Serial output helper  
**Parameters**:
- `param_1: uint` - 32-bit value to output

**Byte Order**: Big-endian (most significant byte first)

**Implementation**:
```c
void write_u32(uint value) {
    FUN_1f000634(value >> 24);  // Byte 3 (MSB)
    FUN_1f000634(value >> 16);  // Byte 2
    FUN_1f000634(value >> 8);   // Byte 1
    FUN_1f000634(value);        // Byte 0 (LSB)
}
```

**Usage**: Send 32-bit addresses, checksums, or data values over serial/flash interface

#### 0x1F002BDC - Write 16-bit Value (Bytewise)

**Classification**: Serial output helper  
**Parameters**:
- `param_1: uint` - 16-bit value to output (upper bits ignored)

**Byte Order**: Big-endian

**Implementation**:
```c
void write_u16(uint value) {
    FUN_1f000634(value >> 8);  // High byte
    FUN_1f000634(value);       // Low byte
}
```

**Usage**: Send 16-bit control codes, sizes, or parameters

---

### Compression Subsystem

GameShark implements two compression algorithms for memory card data: DEF0 (LZ77-style) and RLE (run-length encoding).

#### 0x1F007020 - Find Escape Character

**Classification**: Compression helper  
**Parameters**:
- `param_1: byte*` - Data buffer to scan
- `param_2: uint` - Data length
- `param_3: undefined4` - Context parameter
- `param_4: uint` - Search range (typically 0x100)

**Returns**: `byte` - Unused escape character in range 0x00-0xFF

**Purpose**: Select escape byte that minimizes overhead in compressed stream by finding the least-used character.

#### 0x1F007110 - DEF0 Decompression (LZ77 Variant)

**Classification**: Primary decompression routine  
**Parameters**:
- `param_1: int` - Compressed data buffer address
- `param_2: int` - Output buffer address

**Returns**: `undefined4` - 0 on success

**Format**: "DEF0" + escape_byte + data_stream

**Stream Encoding**:
- **Literal byte**: If byte != escape_byte → copy to output
- **Escape sequence**: If byte == escape_byte:
  - Next byte == 0 → output literal escape_byte
  - Next byte != 0 → LZ77 back-reference:
    - Byte 1: Match length (1-255)
    - Byte 2-3: Lookback distance (big-endian uint16)

**Header Structure** (10 bytes):
- Offset 0-4: "DEF0\x01" magic
- Offset 5: Escape character
- Offset 6-9: Compressed size (32-bit big-endian)

#### 0x1F00722C - DEF0 Compression (LZ77 Variant)

**Classification**: Primary compression routine  
**Parameters**:
- `param_1: int` - Input data buffer address
- `param_2: int` - Output buffer address
- `param_3: int` - Input data length

**Returns**: `int` - Compressed size

**Strategy**: Sliding window search with 5-500 byte lookback, up to 128-byte matches

**Compression Ratio**: Typically 40-60% for memory card save data with repetitive patterns

#### 0x1F0073EC - RLE Compression

**Classification**: Run-length encoder  
**Parameters**:
- `param_1: char*` - Input data buffer
- `param_2: undefined1*` - Output buffer
- `param_3: uint` - Input length

**Returns**: `int` - Compressed size

**Format**: "RLE0\x01" + escape_byte + run-encoded data

**Encoding Rules**:
- **Run < 4 bytes**: Encode as literals
- **Run >= 4 bytes**: Escape + count + character
- **Literal escape**: Escape + 0x00

**Best Use Case**: Highly repetitive data (icon bitmaps, zero-filled regions)

#### 0x1F007548 - RLE Decompression

**Classification**: Run-length decoder  
**Parameters**:
- `param_1: int` - Compressed data buffer address
- `param_2: int` - Output buffer address

**Returns**: `undefined4` - 0 on success

**Performance**: Fast decompression, simple state machine

**Memory Buffers**:
- Input: `PTR_RLE_COMPRESS` (0x800B0000, 192 KB)
- Output: `PTR_DECOMPRESS` (0x800E0000, 128 KB)

---

### Game Management Subsystem

These functions handle game database operations, code list management, and game entry parsing.

#### 0x1F008EB8 - Count Enabled Codes

**Classification**: Code state counter  
**Hardware Access**: Reads from `PTR_DAT_1f013534` (code enable flags buffer)

**Algorithm**:
```c
void count_enabled_codes() {
    Global.remainingItems = 0;  // +0x1C
    for (i = 0; i < Global.maxItems; i++) {  // maxItems at +0x50
        if (code_flags[i] != 0) {
            Global.remainingItems++;
        }
    }
}
```

**Purpose**: Update enabled code counter for display on main menu

**Called By**: Code selection UI after toggling code on/off

#### 0x1F008F94 - Insert Sorted Game

**Classification**: Game list manager  
**Parameters**:
- `param_1: uint` - Maximum games (must be < 9999)
- `param_2: int` - Pointer to game name string

**Global State Modified**: `Global.field_0x118` (insertion index)

**Sorting**: Alphabetical via `FUN_1f008f18` string compare

**Algorithm**:
1. Find insertion point via lexicographic compare
2. Shift existing entries down
3. Insert new game pointer at correct position
4. Update global insertion index

**Purpose**: Maintain sorted game list for fast navigation

**Buffer**: `PTR_DAT_1f013530` (game pointer table)

#### 0x1F0090E8 - Initialize New Game Entry

**Classification**: Template initialization  
**Hardware Access**: Writes to `PTR_DAT_1f013de8` and `PTR_DAT_1f013dfc`

**Operations**:
1. Copy "New Game" template from `s_____New_Game_____1f01c000` (0x4000 bytes)
2. Check flash subsystem availability via `FUN_1f00044c()` and `FUN_1f00047c()`
3. If flash available, copy additional 0x1C000 bytes from `DAT_1f040000`
4. Mirror data to alternate buffer
5. Set end markers (0xFFFFFFFF)

**Purpose**: Create blank game entry for user-defined codes

**Usage Context**: "Add New Game" menu option

#### 0x1F0091E8 - Load Game List

**Classification**: Database loader  
**Global State Access**: `Global.activeGameName` (+0x88), `Global.totalCodesCount` (+0x24)

**Workflow**:
1. Call `FUN_1f009620(0)` to reset game iterator
2. Parse current game name
3. Clear code pointer table at `PTR_DAT_1f013530`
4. Accumulate total codes count across all games
5. Populate game list for menu display

**Purpose**: Initialize game database at boot or after flash update

**Dependencies**: Relies on pre-parsed flash data structure

#### 0x1F0094B8 - Parse Game Entry

**Classification**: Entry parser  
**Parameters**:
- `param_1: int` - Game index (must be < 9999)

**Returns**: `byte*` - Pointer to game name string

**Global State Modified**:
- `Global.activeGameName` (+0x88) - Current game name pointer
- `Global.enableMasterCode` (+0x5C) - Master code flag
- `Global.masterCodePtr` (+0x60) - Master code data
- `Global.maxItems` (+0x50) - Total codes count
- `Global.codeListPtr` (+0x68) - Code list pointer
- `Global.endOfCodesPtr` (+0x78) - End of codes marker

**Entry Format**:
```
Offset 0: 0x00 = has master code, 0xFF = no codes, other = start of name
Offset N: Null terminator
Offset N+1: ASCII digit (code count - '0')
Offset N+2: ASCII digit (code size multiplier - '0')
Offset N+3: Code data array
```

**Purpose**: Extract game metadata and set global pointers for code navigation

**Buffer**: Reads from `PTR_DAT_1f013530 + (index * 4)` pointer table

#### 0x1F009620 - Get Game By Index

**Classification**: Game iterator  
**Parameters**:
- `param_1: int` - Game index (0-based)

**Returns**: `char*` - Pointer to game name, or 0xFF marker if end

**Global State Modified**:
- `Global.activeGameName` (+0x88)
- `Global.enableMasterCode` (+0x5C)
- `Global.masterCodePtr` (+0x60)
- `Global.maxItems` (+0x50)
- `Global.codeListPtr` (+0x68)
- `Global.endOfCodesPtr` (+0x78)

**Data Source**: `PTR_DAT_1f013de8` (game database buffer)

**Purpose**: Navigate game list and populate global state for selected game

**Usage**: Main menu navigation, code selection screen

#### 0x1F009784 - Navigate Code List

**Classification**: Code list navigator  
**Parameters**:
- `param_1: int` - Target code index (0-based)

**Returns**: `undefined4` - 1 if terminator found (0xFE), 0 otherwise

**Global State Modified**:
- `Global.currentCodePtr` (+0x6C) - Current code pointer
- `Global.codeParam` (+0x54) - Code parameter count
- `Global.callParam` (+0x70) - Function call parameter
- `Global.tempStringPtr` (+0x74) - Temporary string pointer
- `Global.digitOrFlag` (+0xA4) - Code digit/flag value

**Algorithm**:
1. Start from `Global.codeListPtr` (+0x68)
2. Skip over `param_1` code entries
3. Parse code name (null-terminated string)
4. Parse code metadata (2 ASCII digits for param counts)
5. Calculate parameter block offset via `FUN_1f008f74()` alignment
6. Set pointers for code display/editing

**Terminator**: 0xFE byte marks end of code list

**Purpose**: Position code list pointer for display/edit operations

**Usage**: Code selection screen navigation (up/down arrows)

---

### UI/Display Subsystem

These functions handle all on-screen text rendering, menus, and visual feedback.

#### 0x1F0098BC - Display Code List

**Classification**: Scrolling list renderer  
**Parameters**:
- `param_1: int` - Selected index
- `param_2: undefined4` - X position
- `param_3: undefined4` - Y position
- `param_4: int` - Context parameter
- `param_5: int` - Total items
- `param_6: uint` - Visible lines
- `param_7: int` - Mode flags

**Global State Modified**:
- `Global.scrollOffset` (+0x80) - Viewport scroll position

**Scrolling Logic**:
1. If selection is below viewport: scroll down
2. If selection is above viewport: scroll up
3. Keep selection centered when possible
4. Clamp scroll to valid range [0, total - visible]

**Rendering**:
- Calls code name pointer retrieval via `PTR_DAT_1f013530 + (index * 4)`
- Highlights selected item via color/marker parameter
- Clips output to visible window

**Purpose**: Display scrollable code/game lists with selection highlight

**Usage**: Main menu, code selection screen, memory card browser

#### 0x1F00DEB4 - Display Text at Position

**Classification**: Base text renderer  
**Parameters**:
- `param_1: int` - X position (character grid)
- `param_2: int` - Y position (character grid)
- `param_3: char*` - Null-terminated string

**Global State**: None modified (leaf function)

**Implementation**: Calls lower-level character rendering for each byte

**Purpose**: Core text output primitive

**Coordinate System**: Character-based grid (40x28 approximate)

**Usage**: Used by all higher-level display functions

#### 0x1F00DF44 - Display Centered Text

**Classification**: Layout helper  
**Parameters**:
- `param_1: undefined4` - Y position
- `param_2: undefined4` - String pointer
- `param_3: undefined4` - Color/attribute

**Algorithm**:
```c
void display_centered(y, str, attr) {
    len = FUN_1f00dce0(str);  // Get string length
    x = 0x14 - (len >> 1);    // Center at X=20
    FUN_1f00deb4(x, y, str, attr);
}
```

**Purpose**: Center text horizontally on screen

**Usage**: Menu titles, dialog messages, credits

#### 0x1F00DFA0 - Display Padded Text

**Classification**: Layout helper with padding  
**Parameters**:
- `param_1: undefined4` - X position
- `param_2: int` - String pointer
- `param_3: undefined4` - Y position
- `param_4: int` - Total width (characters)

**Global State Access**: Uses `Global + 0x1000` as scratch buffer

**Algorithm**:
1. Calculate string length via `FUN_1f00dce0()`
2. If string is empty: fill with spaces
3. Otherwise: center string within width
4. Pad left and right with spaces (0x20)
5. Null-terminate padded buffer
6. Render via `FUN_1f00df44()`

**Purpose**: Display text in fixed-width field with centering and padding

**Usage**: Menu items, button labels, status displays

#### 0x1F00E110 - Display Selected Text

**Classification**: Selection indicator renderer  
**Parameters**:
- `param_1: undefined4` - X position
- `param_2: int` - String pointer
- `param_3: undefined4` - Y position
- `param_4: int` - Total width
- `param_5: int` - Selection mode (0=none, 1=arrows, 2=?, 3=arrows+markers)

**Selection Markers**:
- Mode 1 or 3: Add `>` (0x3E) at start, `<` (0x3C) at end
- Mode 1 or 3: Add double-arrow markers (0xA4 0xA5) near start/end

**Algorithm**: Similar to `FUN_1f00dfa0()` but inserts selection markers

**Global State Access**: Uses `Global + 0x1000` scratch buffer, `Global[0x1001]` for markers

**Purpose**: Highlight selected menu item with visual indicators

**Usage**: Code selection, menu navigation, dialog choices

#### 0x1F00E2D0 - Display Character Glyph

**Classification**: Low-level font renderer  
**Parameters**:
- `param_1: int` - X position (pixel coordinate / 8)
- `param_2: int` - Y position (pixel coordinate / 8)
- `param_3: byte*` - Text buffer
- `param_4: undefined4` - Color/palette
- `param_5: int` - Max characters to render

**Character Mapping**:
- ASCII 0x20-0x7A: Direct mapping to font table
- >= 0x80: Japanese character set (Shift-JIS multi-byte)
- Out of range: Display '?' (0x3F)

**Rendering**: Calls `FUN_1f006370(x << 3, y << 3, glyph_index, color)`

**Purpose**: Render individual character glyphs from font data

**Usage**: Called by text display functions for actual GPU operations

#### 0x1F00E404 - Display Hex Digit

**Classification**: Hex formatter  
**Parameters**:
- `param_1: undefined4` - X position
- `param_2: undefined4` - Y position
- `param_3: uint` - Digit value (0-15)

**Global State Access**: Uses `Global + 0x1080` as scratch buffer

**Encoding**:
- 0-9: ASCII '0'-'9' (0x30-0x39)
- 10-15: ASCII 'A'-'F' (0x41-0x46) via `digit + '7'`

**Purpose**: Render single hexadecimal digit

**Usage**: Code value display, address display, debug output

#### 0x1F00E4B4 - Display Byte as Hex

**Classification**: Hex byte formatter  
**Parameters**:
- `param_1: int` - X position
- `param_2: undefined4` - Y position
- `param_3: uint` - Byte value (0-255)
- `param_4: undefined4` - Color/attribute

**Implementation**:
```c
void display_byte_hex(x, y, byte, attr) {
    FUN_1f00e404(x, y, (byte >> 4) & 0xF);      // High nibble
    FUN_1f00e404(x + 1, y, byte & 0xF, attr);   // Low nibble
}
```

**Purpose**: Display byte as two-digit hexadecimal (00-FF)

**Usage**: Code editing, memory dump display, status values

---

### String and Utility Functions

Helper functions for string manipulation, alignment, and comparison.

#### 0x1F008F18 - String Compare

**Classification**: Standard string comparison  
**Parameters**:
- `param_1: int` - First string pointer
- `param_2: int` - Second string pointer

**Returns**:
- `0xFFFFFFFF` (-1): string1 < string2
- `0`: strings equal
- `1`: string1 > string2

**Algorithm**: Lexicographic byte-by-byte comparison until null terminator

**Purpose**: Alphabetical sorting for game list

**Usage**: Called by `FUN_1f008f94()` insertion sort

#### 0x1F008F74 - Align to 4-Byte Boundary

**Classification**: Alignment utility  
**Parameters**:
- `param_1: uint` - Address or size value

**Returns**: `uint` - Value rounded up to next 4-byte boundary

**Implementation**:
```c
uint align_4(uint val) {
    if (val & 3) {
        val = (val & 0xFFFFFFFC) + 4;
    }
    return val;
}
```

**Purpose**: MIPS requires 32-bit aligned access for word operations

**Usage**: Code parameter block alignment, buffer allocation

#### 0x1F00ADF8 - Copy String with Limit

**Classification**: Bounded string copy  
**Parameters**:
- `param_1: int` - Destination buffer
- `param_2: int` - Source string
- (implicit): Maximum length (not visible in current excerpt)

**Purpose**: Safe string copy with buffer overflow protection

**Usage**: Memory card filename handling, user input

#### 0x1F00D660 - String Length

**Classification**: Standard strlen  
**Parameters**:
- `param_1: char*` - Null-terminated string

**Returns**: `int` - String length (excluding null terminator)

**Implementation**: Byte-by-byte scan until 0x00

**Purpose**: Calculate string length for centering, padding, allocation

**Usage**: Display formatting, buffer size calculation

#### 0x1F00DCE0 - String Length (duplicate)

**Classification**: Duplicate strlen implementation  
**Parameters**: Same as `FUN_1f00d660`

**Note**: Likely inlined in multiple compilation units or different optimization variant

**Purpose**: Same as `FUN_1f00d660`

---

### Memory Card Subsystem

Functions for reading/writing PlayStation memory card data.

#### 0x1F00D6D4 - Memory Card Read

**Classification**: Memory card I/O  
**Parameters**: (to be determined from full decompilation)

**Returns**: Status code or data pointer

**Global Buffers**:
- `PTR_MEMCARD_SLOT1` (0x80180000, 16 KB)
- `PTR_MEMCARD_SLOT2` (0x801A0000, 4 KB)
- `PTR_MEMCARD_WORK` (0x80184000, 112 KB)

**Purpose**: Read memory card blocks (typically 8KB save files)

**Usage**: Load saved code sets, load icon data

#### 0x1F00D800 - Memory Card Initialize

**Classification**: Subsystem initialization  
**Parameters**: (to be determined)

**Operations**:
1. Detect inserted cards in slot 1 and slot 2
2. Set `Global.card1Available` / `Global.card2Available` flags
3. Allocate working buffers
4. Initialize file table cache

**Purpose**: Prepare memory card subsystem for read/write operations

**Call Timing**: Early boot, before main menu

#### 0x1F00ACE4 - Get Icon Data

**Classification**: Icon extractor  
**Parameters**:
- `param_1: byte*` - Memory card block data

**Returns**: `int` - Pointer to icon bitmap (16x16 pixels, 16-color)

**Global Buffers**:
- `PTR_ICON_BUFFER1` (0x80160000, 32 KB)
- `PTR_ICON_BUFFER2` (0x80168000, 32 KB)

**Icon Format**: PlayStation memory card icon format (3 frames, 128 bytes each)

**Purpose**: Extract icon for display in memory card manager

**Usage**: Memory card browser, save file selection

---

### Input Subsystem

Controller reading and button state management.

#### 0x1F00DE30 - Read Controller

**Classification**: Input handler  
**Parameters**: None (uses hardware registers)

**Global State Modified**: `Global.buttons` (+0x08)

**Button Bitfield**:
- 0x0001: ?
- 0x0004: ?
- 0x0020: ?
- 0x0040: ?
- 0x0080: ?
- 0x0800: Start
- 0x1000: Up
- 0x2000: Right
- 0x4000: Down
- 0x8000: Left

**Purpose**: Read digital controller state and update global button state

**Call Frequency**: Every VBlank (60Hz)

**Usage**: Menu navigation, code selection, input handling

---

### Graphics Subsystem (Additional Functions)

#### 0x1F00DE00 - GPU Initialize

**Classification**: Graphics subsystem startup  
**Parameters**: None (uses hardware register pointers)

**Operations**:
1. Reset GPU via GP1 commands
2. Configure display mode (320x240 or 640x480)
3. Set drawing area
4. Initialize frame buffer pointers
5. Load font bitmap to VRAM

**Purpose**: Initialize PlayStation GPU for GameShark UI rendering

**Call Timing**: Early boot, before main menu display

---