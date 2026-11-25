# GameShark [v1.99] for Sony PlayStation (1994)

## KSEG0 (Physical RAM)

| Address | Size | Pointer | Content |
|---------|------|---------|---------|
| 0x80000040 | 16 bytes | | BIOS exception vector backup |
| 0x800005F4 | dynamic | 0x1F004B3C | BIOS hook (control block) |
| 0x80000A00 | 320 bytes | 0x1F004B40 | master code buffer (40 entries × 8 bytes) |
| 0x8000F050 | --- | | temporary file I/O buffer |
| 0x80011000 | 4,096 bytes | | global structure |
| 0x80012000 | 128 bytes | | text formatting buffer |
| 0x80012080 | 3,968 bytes | | scratch text buffer |
| 0x80013000 | 20,480 bytes | 0x1F013530 | game list buffer |
| 0x80018000 | 20,480 bytes (*) | | decompressed RLE01 from 0x1F017A60 |
| 0x8001D000 | 768 bytes | 0x1F013534 | code selection/toggle array (enable/disable state) |
| 0x8001D300 | 256 bytes | 0x1F013538 | GPU primitive buffer (ordering table entry) |
| 0x8001D400 | 256 bytes | 0x1F01353C | GPU primitive buffer (polygon data) |
| 0x8001D500 | 80 bytes | 0x1F013540 | code list pointer array (20 entries × 4 bytes) |
| 0x8001D550 | 176 bytes | 0x1F013544 | code data staging buffer |
| 0x8001D600 | 512 bytes | 0x1F013548 / 0x1F01355C | game name edit buffer |
| 0x8001D800 | 512 bytes | 0x1F01354C | string format/display buffer |
| 0x8001DA00 | 512 bytes | 0x1F013550 | text edit/input buffer |
| 0x8001DC00 | 768 bytes | 0x1F013554 | display rendering buffer |
| 0x8001DF00 | 256 bytes | 0x1F013558 | menu state buffer |
| 0x8001E000 | 4,096 bytes | 0x1F013560 | cheat code packet assembly buffer |
| 0x8001F000 | 4,096 bytes | | GPU display configuration |
| 0x80020000 | 4,096 bytes | | decompressed RLE01 from 0x1F015B40 |
| 0x80021000 | 454,656 bytes | 0x1F013564 | staging buffer (flash ROM and memory card op) |
| 0x80090000 | 131,072 bytes | 0x1F013568 | memory card I/O buffer |
| 0x800B0000 | 196,608 bytes | 0x1F01356C | RLE compression source buffer |
| 0x800E0000 | 131,072 bytes | 0x1F013570 | DEF compression destination buffer |
| 0x80100000 | 8,192 bytes | 0x1F013574 | game list structure array (0x21-byte entries) |
| 0x80102000 | 1,024 bytes | 0x1F013578 | code edit buffer |
| 0x80102400 | 7,168 bytes | 0x1F01357C | parameter/value edit buffer |
| 0x80104000 | 8,192 bytes | 0x1F013580 | stack/scratch area |
| 0x80106000 | 1,024 bytes | 0x1F013584 | user input buffer |
| 0x80106400 | 7,168 bytes | 0x1F013588 | memory card file descriptor buffer |
| 0x80108000 | 229,376 bytes | 0x1F01358C | memory card file data buffer |
| 0x80140000 | 65,536 bytes | | decompressed DEF01 from 0x1F015FF0 |
| 0x80150000 | 65,536 bytes | | decompressed DEF01 from 0x1F017450 |
| 0x80160000 | 32,768 bytes | 0x1F014288| icon buffer 1 |
| 0x80168000 | 32,768 bytes | 0x1F01428C | icon buffer 2 |
| 0x80170000 | 65,536 bytes | 0x1F014290| graphics work buffer |
| 0x80180000 | 16,384 bytes | 0x1F013DE8 | cheat database primary buffer |
| 0x80184000 | 114,688 bytes | 0x1F013DEC | extended cheat database (if present) |
| 0x801A0000 | 4,096 bytes | 0x1F013DF0 | (end marker for extended database) |
| 0x801A1000 | 131,072 bytes | 0x1F013DFC | cheat database work buffer (duplicate) |
| 0x801C1000 | 258,048 bytes | | unallocated |

###### (*) when deflated, RLE01 from 0x1F017A60 clears RAM (0x00 fill from 0x80018000 - 0x80033B20) and stores pointers (at 0x8002D230 - 0x8002D2A0) required for further decompression of additional resources

---


## Map

| Memory Region | R/W Size | Symbol | Value/Init | Access | Purpose |
|---------------|----------|--------|------------|--------|---------|
| **EXP1 (Parallel I/O)** |
| 0x1F002A7C | 4 bytes | DisplayWidth | 0x00000280 | R | Display width in pixels (640) |
| 0x1F002A80 | 4 bytes | DisplayHeight_Units | 0x00000010 | R | Display height unit value (16) |
| 0x1F002A84 | 4 bytes | DisplayHeight_Mult | 0x00000002 | R | Display height multiplier (2) |
| 0x1F002A88 | 4 bytes | DisplayConfig | 0x01000280 | R | Combined display configuration value |
| 0x1F002A8C | 4 bytes | PTR_GPU_REG0 | 0x1F801810 | R | Pointer to GPU data register (GPUREAD/GPUWRITE) |
| 0x1F002A90 | 4 bytes | PTR_GPU_REG1 | 0x1F801814 | R | Pointer to GPU status register (GPUSTAT) |
| 0x1F002A94 | 4 bytes | PTR_DMA_GPU_MADR | 0x1F8010A0 | R | Pointer to DMA channel 2 (GPU) memory address register |
| 0x1F002A98 | 4 bytes | PTR_DMA_GPU_BCR | 0x1F8010A4 | R | Pointer to DMA channel 2 (GPU) block control register |
| 0x1F002A9C | 4 bytes | PTR_DMA_GPU_CHCR | 0x1F8010A8 | R | Pointer to DMA channel 2 (GPU) channel control register |
| 0x1F002AA0 | 4 bytes | PTR_DMA_MDEC_MADR | 0x1F8010E0 | R | Pointer to DMA channel 0 (MDECin) memory address register |
| 0x1F002AA4 | 4 bytes | PTR_DMA_MDEC_BCR | 0x1F8010E4 | R | Pointer to DMA channel 0 (MDECin) block control register |
| 0x1F002AA8 | 4 bytes | PTR_DMA_MDEC_CHCR | 0x1F8010E8 | R | Pointer to DMA channel 0 (MDECin) channel control register |
| 0x1F002AAC | 4 bytes | PTR_DMA_DPCR | 0x1F8010F0 | R | Pointer to DMA priority control register |
| 0x1F002AB0 | 4 bytes | PTR_I_STAT | 0x1F801070 | R | Pointer to interrupt status register |
| 0x1F002AB4 | 4 bytes | PTR_I_MASK | 0x1F801074 | R | Pointer to interrupt mask register |
| 0x1F002AB8 | 4 bytes | PTR_DMA_DICR | 0x1F8010F4 | R | Pointer to DMA interrupt control register |
| 0x1F002AC0 | 4 bytes | PTR_TMR_HRETRACE_MODE | 0x1F801114 | R | Pointer to Timer 1 (horizontal retrace) mode register |
| 0x1F002AC8 | 4 bytes | PTR_TMR_HRETRACE_VAL | 0x1F001110 | R | Pointer to Timer 1 (horizontal retrace) counter value |
| 0x1F002AD4 | 4 bytes | GraphicsParam_Width | 0x00000010 | R | Graphics parameter: width divisor or block size |
| 0x1F002AD8 | 4 bytes | GraphicsParam_Height | 0x00000002 | R | Graphics parameter: height divisor or block count |
| 0x1F002AE0 | 4 bytes | ScreenWidth | 0x00000280 | R | Screen width value (640 pixels) |
| 0x1F002AE4 | 4 bytes | ScreenHeight | 0x00000100 | R | Screen height value (256 pixels) |
| 0x1F0046FC | 4 bytes | ByteMaskLo | 0xFFFFFF00 | R | Byte mask for 8-bit writes at even addresses (keep bits [31:8]) |
| 0x1F004700 | 4 bytes | ByteMaskHi | 0xFFFF00FF | R | Byte mask for 8-bit writes at odd addresses (keep bits [31:16] and [7:0]) |
| 0x1F004B20 | 4 bytes | PTR_LAB_CheatLoopEntry | 0x1F004084 | R | Pointer to cheat loop entry point label |
| 0x1F004B2C | 4 bytes | PTR_Function_4B20 | 0x1F0047F4 | R | Pointer wrapper function (loads 0x1F004B20) |
| 0x1F004B30 | 4 bytes | PTR_Function_4B24 | 0x1F004808 | R | Pointer wrapper function (loads 0x1F004B24 -> 0x1F003EDC) |
| 0x1F004B34 | 4 bytes | PTR_CheatEngineHandler | 0x1F000DFC | R | Pointer to cheat execution handler function |
| 0x1F004B38 | 4 bytes | PTR_CheatEngineInit | 0x1F000F7C | R | Pointer to cheat engine initialization routine |
| 0x1F004B3C | 4 bytes | PTR_GameSharkControlBlock | 0x800005F4 | R | Pointer to GameShark state machine control structure in RAM |
| 0x1F004B40 | 4 bytes | PTR_MasterCodeBuffer | 0x80000A00 | R | Pointer to master code list buffer (40 entries × 8 bytes) |
| 0x1F013DF4 | 4 bytes | IconDataConstant1 |  | R | Icon/memory card data constant (used in card operations) |
| 0x1F013DF8 | 4 bytes | IconDataConstant2 |  | R | Icon/memory card data constant (used in card operations) |
| 0x1F014C94 | 4 bytes | DataTable1 |  | R | Data table entry 1 (menu/UI configuration) |
| 0x1F014C98 | 4 bytes | DataTable2 |  | R | Data table entry 2 (menu/UI configuration) |
| 0x1F014C9C | 4 bytes | DataTable3 |  | R | Data table entry 3 (menu/UI configuration) |
| 0x1F014CA0 | 4 bytes | DataTable4 |  | R | Data table entry 4 (menu/UI configuration) |
| 0x1F014CA4 | 4 bytes | DataTable5 |  | R | Data table entry 5 (menu/UI configuration) |
| 0x1F014CA8 | 4 bytes | DataTable6 |  | R | Data table entry 6 (menu/UI configuration) |
| 0x1F014D00 | 2 bytes | IconColorData |  | R | Memory card icon color/palette data |
| 0x1F014D20 | 1 byte | IconParam1 |  | R | Memory card icon parameter 1 |
| 0x1F014D21 | 1 byte | IconParam2 |  | R | Memory card icon parameter 2 (offset calculation base) |
| 0x1F015B40 | varies | CompressedBlock_RLE01_1 | RLE01 | R | Compressed RLE01 block (decompresses to 0x80020000, 4KB) |
| 0x1F015FF0 | varies | CompressedBlock_DEF01_1 | DEF01 | R | Compressed DEF01 block (decompresses to 0x80140000, 64KB) |
| 0x1F017450 | varies | CompressedBlock_DEF01_2 | DEF01 | R | Compressed DEF01 block (decompresses to 0x80150000, 64KB) |
| 0x1F017A60 | varies | CompressedBlock_RLE01_2 | RLE01 | R | Compressed RLE01 block (clears 0x80018000-0x80033B20, stores pointers at 0x8002D230) |
| 0x1F018000 | 4 bytes | ConfigBlockBase | 0xFFFFFFFF | R/W | Runtime configuration block base address (referenced by flash I/O routines) |
| 0x1F018010 | 4 bytes | ActiveCodeCount | 0xFFFFFFFF | R/W | Number of active cheat codes to execute per VSync interrupt (cheat loop counter) |
| 0x1F018014 | 4 bytes | pTimingCheck | 0xFFFFFFFF | R/W | Pointer to RAM address for frame counter comparison (null disables timing checks) |
| 0x1F018018 | 4 bytes | TimingCheck | 0xFFFFFFFF | R/W | Target value for frame counter comparison (timing-based cheat activation) |
| 0x1F018020 | 4 bytes | ExtendedFlashFlag | 0xFFFFFFFF | R/W | Extended flash memory availability flag (-1 = uninitialized, 0 = disabled, 1 = enabled) |
| 0x1F018024 | 4 bytes | BiosHookAddress | 0xFFFFFFFF | R/W | BIOS exception handler hook address override (0 = use default LAB_000000b0 scan) |
| 0x1F01802C | 4 bytes | ExtendedFlashSize | 0xFFFFFFFF | R/W | Extended flash size indicator (0 = none, 1 = extra 128 KB region present) |
| 0x1F018038 | varies | ActiveCodeList | 0xFFFFFFFF | R/W | Active cheat code list buffer (8-byte entries: address+value pairs, processed by cheat engine) |
| 0x1F01C000 | 16,384 bytes | CheatDatabaseStorage | USACODES.BIN | R/W | Cheat code database (13,518 bytes used, remainder 0xFF filled; see [cheat code database](CHEAT_DATABASE.MD) |
| 0x1F01FFF1 | 1 byte | FlashStatusFlag | 0xFF | R/W | Flash ROM operation status flag (bit 7 = ready when (val & 0xC2) == 0x80) |
| **---** |
| 0x1F020010 | 1 byte | ParallelPortControl |  | R/W | Parallel port control register (bit 0 = ready/busy flag, polled before I/O) |
| 0x1F020018 | 1 byte | ParallelPortStatus |  | R | Parallel port hardware status (bit 0 = disc inserted flag, checked at boot) |
| **---** |
| 0x1F040000 | 114,688 bytes | CheatDatabaseExStorage |  | R/W | Extended cheat code database region (0x7000 dwords / 112 KB additional game/code entries) |
| **---** |
| 0x1F060000 | 1 byte | DiscStatusRegister |  | R | CD-ROM/input disc status register ('i' = inserted, 'W' = warning/no disc state) |
| 0x1F060008 | 1 byte | DiscCommandRegister |  | W | CD-ROM/input command/data register (byte write triggers hardware action) |
| **KSEG0** |
| 0x80000040 | 16 bytes | BiosExceptionVectorBackup |  | R/W | BIOS exception vector backup (IRQ handler preservation) |
| 0x800005F4 | varies | GameSharkControlBlock |  | R/W | GameShark state machine control structure (BIOS hook control block) |
| 0x80000A00 | 320 bytes | MasterCodeBuffer |  | R/W | Master code list buffer (40 entries × 8 bytes: addr+value pairs) |
| 0x80011000 | 4,096 bytes | Global |  | R/W | Global state structure (440 bytes used + scratch buffers) |
| 0x80012000 | 128 bytes | TextFormattingBuffer |  | R/W | Text formatting buffer (Global+0x1000 offset) |
| 0x80012080 | 3,968 bytes | ScratchTextBuffer |  | R/W | Scratch text buffer (Global+0x1080 offset) |
| 0x80013000 | 20,480 bytes | GameListBuffer |  | R/W | Game list buffer for menu display |
| 0x80018000 | 20,480 bytes | DecompressedRLE01_Primary |  | R/W | Decompressed RLE01 from 0x1F017A60 (clears 0x80018000-0x80033B20 on init) |
| 0x8001D000 | 768 bytes | CodeSelectionToggleArray |  | R/W | Code selection/toggle array (enable/disable state for cheat codes) |
| 0x8001D300 | 256 bytes | GPUPrimitiveBuffer_OT |  | R/W | GPU primitive buffer (ordering table entry) |
| 0x8001D400 | 256 bytes | GPUPrimitiveBuffer_Poly |  | R/W | GPU primitive buffer (polygon data) |
| 0x8001D500 | 80 bytes | CodeListPointerArray |  | R/W | Code list pointer array (20 entries × 4 bytes) |
| 0x8001D550 | 176 bytes | CodeDataStagingBuffer |  | R/W | Code data staging buffer |
| 0x8001D600 | 512 bytes | GameNameEditBuffer |  | R/W | Game name edit buffer |
| 0x8001D800 | 512 bytes | StringFormatDisplayBuffer |  | R/W | String format/display buffer |
| 0x8001DA00 | 512 bytes | TextEditInputBuffer |  | R/W | Text edit/input buffer |
| 0x8001DC00 | 768 bytes | DisplayBuffer |  | R/W | Display rendering buffer |
| 0x8001DF00 | 256 bytes | MenuBuffer |  | R/W | Menu state buffer |
| 0x8001E000 | 4,096 bytes | CheatCodePacketAssemblyBuffer |  | R/W | Cheat code packet assembly buffer |
| 0x8001F000 | 4,096 bytes | GPUDisplayConfiguration |  | R/W | GPU display configuration (frame buffer control) |
| 0x80020000 | 4,096 bytes | DecompressedRLE01_Secondary |  | R/W | Decompressed RLE01 from 0x1F015B40 |
| 0x80021000 | 454,656 bytes | FlashMemCardStagingBuffer |  | R/W | Staging buffer (flash ROM and memory card operations) |
| 0x80090000 | 131,072 bytes | MemoryCardIOBuffer |  | R/W | Memory card I/O buffer |
| 0x800B0000 | 196,608 bytes | RLECompressionSourceBuffer |  | R/W | RLE compression source buffer |
| 0x800E0000 | 131,072 bytes | DEFCompressionDestBuffer |  | R/W | DEF compression destination buffer |
| 0x80100000 | 8,192 bytes | GameListStructureArray |  | R/W | Game list structure array (0x21-byte entries) |
| 0x80102000 | 1,024 bytes | CodeEditBuffer |  | R/W | Code edit buffer |
| 0x80102400 | 7,168 bytes | ParameterValueEditBuffer |  | R/W | Parameter/value edit buffer |
| 0x80104000 | 8,192 bytes | StackScratchArea |  | R/W | Stack/scratch area |
| 0x80106000 | 1,024 bytes | UserInputBuffer |  | R/W | User input buffer |
| 0x80106400 | 7,168 bytes | MemoryCardFileDescriptorBuffer |  | R/W | Memory card file descriptor buffer |
| 0x80108000 | 229,376 bytes | MemoryCardFileDataBuffer |  | R/W | Memory card file data buffer |
| 0x80140000 | 65,536 bytes | DecompressedDEF01_Primary |  | R/W | Decompressed DEF01 from 0x1F015FF0 |
| 0x80150000 | 65,536 bytes | DecompressedDEF01_Secondary |  | R/W | Decompressed DEF01 from 0x1F017450 |
| 0x80160000 | 32,768 bytes | IconBuffer1 |  | R/W | Icon buffer 1 (memory card icon data) |
| 0x80168000 | 32,768 bytes | IconBuffer2 |  | R/W | Icon buffer 2 (memory card icon data) |
| 0x80170000 | 65,536 bytes | GraphicsWorkBuffer |  | R/W | Graphics work buffer |
| 0x80180000 | 16,384 bytes | CheatDatabase |  | R/W | Cheat database primary buffer (base database from 0x1F01C000) |
| 0x80184000 | 114,688 bytes | CheatDatabaseEx |  | R/W | Extended cheat database (from 0x1F040000 if hardware present) |
| 0x801A0000 | 4,096 bytes | CheatDatabaseExEndMarker |  | R/W | End boundary marker for extended database region |
| 0x801A1000 | 131,072 bytes | CheatDatabaseWorkBuffer |  | R/W | Cheat database work buffer (duplicate of 0x80180000+extended for runtime processing) |

**Notes**:
- ROM constants are embedded in the binary at compile time and located in EXT1 parallel I/O space
- Runtime variables in ROM region (0x1F018000+) are initialized during boot and modified during execution
- Hardware I/O registers are PlayStation memory-mapped peripherals accessed via pointer table in ROM
- RAM buffers are allocated in PlayStation main memory KSEG0 region during initialization
- Pointer table at 0x1F004B20-0x1F004B40 provides indirection for key runtime functions and structures
- All multi-byte values are stored in little-endian format (LSB first)

---

## Extended Flash Memory (0x1F040000)

#### Hardware Architecture
- **Address Range**: 0x1F040000 - 0x1F05FFFF (theoretical maximum)
- **Utilized Range**: 0x1F040000 - 0x1F05BFFF (114,688 bytes / 112 KB)
- **Physical Location**: Extended parallel I/O flash ROM (hardware-mapped, not present in ROM dump)
- **Default Hardware**: Retail GameShark v1.0-v1.99 units **do not** include extended flash memory
- **Purpose**: Additional cheat code database storage beyond the base 16 KB database at 0x1F01C000

#### Detection and Initialization
The firmware detects extended flash presence via two runtime functions:
- **FUN_80150008** (via FUN_1f00044c): Primary extended flash detection
- **FUN_80150010** (via FUN_1f00047c): Secondary extended flash detection

#### Memory Copy Flow (FUN_1f0090e8)
When extended flash is detected, the firmware performs a multi-stage database initialization:

1. **Base Database Copy** (always performed):
   - Source: 0x1F01C000 (ROM cheat database)
   - Destination: 0x80180000 (RAM primary buffer)
   - Size: 0x4000 bytes (16,384 bytes / 16 KB)
   - Count: 0x1000 dwords

2. **Extended Database Copy** (conditional, only if extended flash detected):
   - Source: 0x1F040000 (extended flash cheat database)
   - Destination: 0x80184000 (RAM, immediately after base database)
   - Size: 0x1C000 bytes (114,688 bytes / 112 KB)
   - Count: 0x7000 dwords

3. **Duplicate to Work Buffer** (always performed):
   - Source: 0x80180000 (RAM primary buffer with base + extended)
   - Destination: 0x801A1000 (RAM work buffer)
   - Size: 0x4000 bytes base + 0x1C000 bytes extended (if present)
   - Count: 0x1000 dwords base + 0x7000 dwords extended (if present)

#### RAM Buffer Boundaries
- function at 0x1F009264 fills unused space with 0xFF:
```c
if ((iVar4 == 0) && (iVar4 = FUN_1f00044c(), pcVar6 = PTR_DAT_1f013df0, iVar4 == 0))
{
    pcVar6 = PTR_DAT_1f013dec;  // Use smaller boundary if no extended flash
}

for (; pcVar8 < pcVar6; pcVar8 = pcVar8 + 1)
{
    *pcVar8 = -1;  // Fill remaining space with 0xFF
}
```

#### Database Format
The extended flash database follows the same structure as the base database documented in [CHEAT_DATABASE.MD](CHEAT_DATABASE.MD):
- Variable-length null-terminated strings (game titles and cheat code names)
- Metadata bytes following each string (count byte + subcount byte)
- 8-byte cheat code entries (address + value pairs)
- Dynamic string opcodes for parameterized text generation
- Database parsing via FUN_1f009620 (game entry iterator)

#### Usage in Cheat Engine
The unified database (base + extended) is accessed through:
- **Game selection**: FUN_1f009620 iterates through all game entries regardless of source
- **Code loading**: FUN_1f008f94 loads cheat codes from the merged buffer
- **Menu display**: Game and code counts reflect the combined database size

#### Hardware Requirements
Extended flash support requires:
- Physical flash ROM chip at parallel I/O address 0x1F040000
- Hardware detection logic returning non-zero from FUN_80150008 or FUN_80150010
- Sufficient RAM allocation at 0x80184000-0x801A0000 (114,688 bytes)

---

## Global State Structure

- 440 / 4,096 bytes used (3,656 bytes free)
- Scratch buffers accessed via pointer arithmetic:
  - `Global + 0x1000`: 128-byte text formatting buffer
  - `Global + 0x1080`: Small scratch buffer for hex conversion

| Address | Type | Name | Description |
|-------------|------|------|-------------|
| 0x80011000 | uint | unknown_0x00 | Command/status byte |
| 0x80011004 | uint | unknown_0x04 | (No usage found) |
| 0x80011008 | uint | buttons | Controller button state bitfield |
| 0x8001100C | uint | gameIndexOrMenu | Game index or menu parameter |
| 0x80011010 | uint | currentSelection | Current menu selection (-1 = none) |
| 0x80011014 | uint | counterOrFlag2 | Counter or flag |
| 0x80011018 | uint | selectedCardSlot | Selected memory card slot (0,1,2) |
| 0x8001101C | uint | listPosition | List scroll position |
| 0x80011020 | uint | remainingItems | Remaining items count |
| 0x80011024 | uint | totalCodesCount | Total codes count (main menu display) |
| 0x80011028 | uint | menuStateOrTimer | Menu state or timer |
| 0x8001102C | uint | resetPendingFlag | Reset pending flag (0/1) |
| 0x80011030 | uint | delay1 | Delay value 1 |
| 0x80011034 | uint | delay2 | Delay value 2 |
| 0x80011038 | uint | displayMode | Display/menu mode (0x8, 0xC, etc.) |
| 0x8001103C | uint | savedDisplayMode | Saved display mode |
| 0x80011040 | uint | delayFrames | Frame delay counter |
| 0x80011044 | uint | counterOrDelay | Counter/delay value |
| 0x80011048 | uint | initializeFlag | Initialization flag (0/1) |
| 0x8001104C | uint | structOffset | Structure offset for traversal |
| 0x80011050 | uint | maxItems | Maximum items/codes (upper limit) |
| 0x80011054 | uint | codeParam | Code parameter |
| 0x80011058 | byte* | currentCodeNamePtr | Pointer to current code name |
| 0x8001105C | uint | enableMasterCode | Master code enabled flag (0/1) |
| 0x80011060 | byte* | masterCodePtr | Pointer to master code data |
| 0x80011064 | uint | codeCount | Number of codes |
| 0x80011068 | byte* | codeListPtr | Pointer to code list |
| 0x8001106C | char* | currentCodePtr | Pointer to current code data |
| 0x80011070 | uint | callParam | Parameter for function calls |
| 0x80011074 | char* | tempStringPtr | Temporary string pointer |
| 0x80011078 | byte* | endOfCodesPtr | Pointer to end of codes |
| 0x8001107C | uint | unknown_0x7C | (No usage found) |
| 0x80011080 | uint | scrollOffset | Scroll/window offset |
| 0x80011084 | uint | windowOffset | Window/centering offset |
| 0x80011088 | byte* | activeGameName | Pointer to current game name |
| 0x8001108C | uint | state | State machine value (0-0x70) |
| 0x80011090 | uint | editValue1 | Edit value 1 (cheat address+command) |
| 0x80011094 | uint | editValue2 | Edit value 2 (cheat data value) |
| 0x80011098 | uint | clearableValue | Clearable value (set to 0) |
| 0x8001109C | uint | unknown_0x9C | (No usage found) |
| 0x800110A0 | uint | unknown_0xA0 | (No usage found) |
| 0x800110A4 | uint | digitOrFlag | Digit value or flag |
| 0x800110A8 | uint | lastGameIndex | Last game index |
| 0x800110AC | uint | refreshFlag | Refresh/redraw flag |
| 0x800110B0 | uint | dialogType | Dialog state (0xB, 0xD, -1) |
| 0x800110B4 | uint | dialogMode | Dialog mode (0-9) |
| 0x800110B8 | uint | dialogAction | Dialog action (0,1,2,5) |
| 0x800110BC | uint | dialogResult | Dialog result (0x43='C', 0x59='Y') |
| 0x800110C0 | uint | savedValue1 | Saved value 1 |
| 0x800110C4 | uint | savedValue2 | Saved value 2 |
| 0x800110C8 | uint | activeGameIndexOld | Active game index (old location) |
| 0x800110CC | uint | operationMode | Operation mode (0,1,2,0xC,0xD,0x3E6) |
| 0x800110D0 | uint | gameListIndex | Game list index (navigation) |
| 0x800110D4 | uint | clearFlag | Clear/reset flag |
| 0x800110D8 | uint | savedGameListIndex | Saved game list index |
| 0x800110DC | uint | uiUpdateFlag | UI update flag |
| 0x800110E0 | uint | hexEditPosition | Hex editor position |
| 0x800110E4 | uint | stringLength | String length counter |
| 0x800110E8 | uint | hexEditValue | Hex editor current value |
| 0x800110EC | uint | codeFlags | Code flags (copied from 0xA4) |
| 0x800110F0 | uint | hexEditCursorPos | Hex editor cursor position |
| 0x800110F4 | uint | inputCounter | Input counter |
| 0x800110F8 | uint | keyInputCounter | Key input counter |
| 0x800110FC | uint | newGameFlag | New game flag |
| 0x80011100 | uint | gameMode | Game mode / active game index |
| 0x80011104 | uint | flashStatus | Flash operation status / enable codes flag |
| 0x80011108 | uint | memoryCardOp | Memory card operation state |
| 0x8001110C | byte* | stringBufferPtr | String buffer pointer |
| 0x80011110 | uint | firstByteValue | First byte value |
| 0x80011114 | uint | unknown_0x114 | (No usage found) |
| 0x80011118 | uint | savedValue3 | Saved value 3 |
| 0x8001111C | uint | flag_0x11C | Flag at offset 0x11C |
| 0x80011120 | uint | biosParam1 | BIOS parameter 1 |
| 0x80011124 | uint | biosParam3 | BIOS parameter 3 |
| 0x80011128 | uint | biosParam2 | BIOS parameter 2 |
| 0x8001112C | uint | gameModeOrFlag | Game mode or flag |
| 0x80011130 | uint | initFlag | Initialization flag |
| 0x80011134 | uint | unknown_0x134 | (No usage found) |
| 0x80011138 | uint | savedGameIndex | Saved game index |
| 0x8001113C | uint | unknown_0x13C | (No usage found) |
| 0x80011140 | uint | creditsCursorPos | Credits screen cursor position |
| 0x80011144 | uint | creditsSelection | Credits screen selection |
| 0x80011148 | uint | enableCodesFlag | Enable codes flag (0/1) |
| 0x8001114C | uint | totalGames_Slot2Alt | Total games slot 2 (alternate) |
| 0x80011150 | uint | totalGames_Slot1 | Total games slot 1 |
| 0x80011154 | uint | totalGames_Slot2 | Total games slot 2 |
| 0x80011158 | uint | card1Available | Memory card 1 available flag |
| 0x8001115C | uint | card2Available | Memory card 2 available flag |
| 0x80011160 | uint | card1Formatted | Memory card 1 formatted flag |
| 0x80011164 | uint | memCardStateMachine | Memory card state machine |
| 0x80011168 | uint | memCardParam1 | Memory card parameter 1 |
| 0x8001116C | uint | memCardParam2 | Memory card parameter 2 |
| 0x80011170 | uint | compressionIndex | Compression index |
| 0x80011174 | uint | compressionStatus | Compression status |
| 0x80011178 | uint | unknown_0x178 | (No usage found) |
| 0x8001117C | uint | memCardStatus | Memory card status |
| 0x80011180 | uint | baseGameIndex1 | Base game index 1 |
| 0x80011184 | uint | card1GameIndex | Card 1 game index |
| 0x80011188 | uint | selectedGameSlot1 | Selected game slot 1 |
| 0x8001118C | uint | selectedGameSlot2 | Selected game slot 2 |
| 0x80011190 | uint | unknown_0x190 | (No usage found) |
| 0x80011194 | uint | frameCounter | Frame counter |
| 0x80011198 | uint | totalCodesInGame | Total codes in current game |
| 0x8001119C | uint | unknown_0x19C | (No usage found) |
| 0x800111A0 | uint | specialFlag | Special flag |
| 0x800111A4 | uint | memCard1ErrorFlag | Memory card 1 error flag |
| 0x800111A8 | uint | memCard2ErrorFlag | Memory card 2 error flag |
| 0x800111AC | uint | hardwareFlag | Hardware flag |
| 0x800111B0 | uint | buttonConfigFlag | Button configuration flag |
| 0x800111B4 | uint | menuRefreshFlag | Menu refresh flag |

---
