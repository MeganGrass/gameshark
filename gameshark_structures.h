// GameShark PlayStation Version 1.99 ROM Structures
// Reverse engineered from Ghidra decompilation of v1.99e.rom
// Binary: 131,072 bytes (128KB)
// ROM Base Address: 0x1F000000 (PS1 Expansion Region 1 - EXP1, Parallel I/O)
// Entry Point: 0x1F000108
// Copyright: Datel Design & Development 1995/1996, Interact Multimedia Products

#ifndef GAMESHARK_STRUCTURES_H
#define GAMESHARK_STRUCTURES_H

#include <stdint.h>

typedef unsigned char   byte;
typedef unsigned short  ushort;
typedef unsigned int    uint;
typedef unsigned long   ulong;

// ============================================================================
// ROM Memory Map
// ============================================================================
// 0x1F000000-0x1F01FFFF: GameShark ROM (128KB, Expansion Region 1)
// 0x1F000108: Code entry point (MIPS)
// 0x1F002A7C-0x1F002AD8: Hardware register pointer table
// 0x1F013530-0x1F01357F: RAM buffer pointer table
// 0x1F013590-0x1F01FFFF: String tables and constant data
//
// 0x80000000-0x801FFFFF: PS1 Main RAM (2MB)
// 0x80011000: GameShark Global State Structure (this file)
// 0x80013000-0x800B0000: GameShark work buffers
// ============================================================================

// Global state pointer (PTR_DAT_1f01352c -> 0x80011000)
#define PTR_GLOBAL_STATE      ((void*)0x80011000)

// Main GameShark Global State Structure (PTR_DAT_1f01352c)
// This structure controls the overall state of the GameShark system
// Location: 0x80011000 (Main RAM)
// Total size: 0x1000 bytes (4096 decimal) - fields up to +0x1B8, remainder is padding
// Layout: 72 uint fields (0x1B8 bytes / 440 decimal) + padding (3656 bytes)
// Note: Code accesses scratch buffers at Global+0x1000 and Global+0x1080 via pointer arithmetic
// Verified to match v1.99e.rom.c Global structure usage patterns
typedef struct GameSharkGlobalState {
	uint unknown_0x00;                // +0x00: Command/status byte (used in FUN_1f002afc)
	uint unknown_0x04;                // +0x04: (No usage found in decompilation)
	uint buttons;                     // +0x08: Controller button state (bitfield: 0x1, 0x4, 0x20, 0x40, 0x80, 0x800, 0x1000, 0x2000, 0x4000, 0x8000)
	uint gameIndexOrMenu;             // +0x0C: Game index or menu parameter (also compared with 0xA8)
	uint currentSelection;            // +0x10: Current menu selection/index (signed, -1 = none)
	uint counterOrFlag2;              // +0x14: Counter or flag (set to 1, used in array operations, cleared to 0)
	uint selectedCardSlot;            // +0x18: Selected memory card slot (0,1,2)
	uint listPosition;                // +0x1C: List scroll position (incremented/decremented by toggle operations)
	uint remainingItems;              // +0x20: Remaining items count (decremented, compared >0)
	uint totalCodesCount;             // +0x24: Total codes count accumulator (+=maxItems per game, displayed on main menu)
	uint menuStateOrTimer;            // +0x28: Menu state or timer (copied from 0x30, cleared to 0, checked for values 1/2)
	uint resetPendingFlag;            // +0x2C: Reset pending flag (0/1, cleared before exit)
	uint delay1;                      // +0x30: Copy to 0x34
	uint delay2;                      // +0x34: Delay value
	uint displayMode;                 // +0x38: Display/menu mode (value 0x8, 0xC, 0xFFFFFFF4 seen, copied from 0x3C)
	uint savedDisplayMode;            // +0x3C: Saved display mode (values 0, 3, 4, 5, 0xC, 0x73)
	uint delayFrames;                 // +0x40: Frame delay counter (value 4 seen)
	uint counterOrDelay;              // +0x44: Counter/delay (init values 3,4,9,10, decremented to 0)
	uint initializeFlag;              // +0x48: Initialization flag (set to 1, cleared to 0)
	uint structOffset;                // +0x4C: Structure offset (used as (iVar1 + 0x4c) in struct traversal, offset 0x44 from base)
	uint maxItems;                    // +0x50: Maximum items/codes (upper limit)
	uint codeParam;                   // +0x54: Code parameter (incremented in conditional paths)
	byte *currentCodeNamePtr;         // +0x58: Pointer to current code name string
	uint enableMasterCode;            // +0x5C: Master code enabled flag (0/1)
	byte *masterCodePtr;              // +0x60: Pointer to master code data
	uint codeCount;                   // +0x64: Number of codes (also at +0x100 decimal)
	byte *codeListPtr;                // +0x68: Pointer to code list
	char *currentCodePtr;             // +0x6C: Pointer to current code data (written with 0x00 or 0x41, compared to strings)
	uint callParam;                   // +0x70: Parameter passed to FUN_1f0093ec calls
	char *tempStringPtr;              // +0x74: Temporary string pointer
	byte *endOfCodesPtr;              // +0x78: Pointer to end of codes
	uint unknown_0x7C;                // +0x7C: (No usage found in decompilation)
	uint scrollOffset;                // +0x80: Scroll/window offset
	uint windowOffset;                // +0x84: Window/centering offset (used in text positioning calculations)
	byte *activeGameName;             // +0x88: Pointer to current game name string
	uint state;                       // +0x8C: State machine value (0-0x16, up to 0x70)
	uint editValue1;                  // +0x90: Edit value 1 (copied from arrays, can be 0x80000000, used in pair with 0x94)
	uint editValue2;                  // +0x94: Edit value 2 (copied from arrays, used in pair with 0x90, passed to FUN_1f00c4fc)
	uint clearableValue;              // +0x98: Clearable value (set to 0)
	uint unknown_0x9C;                // +0x9C: (No usage found in decompilation)
	uint unknown_0xA0;                // +0xA0: (No usage found in decompilation)
	uint digitOrFlag;                 // +0xA4: Digit value or flag (set to 1, stores 0x30 subtraction, copied to 0xEC)
	uint lastGameIndex;               // +0xA8: Last game index or menu parameter (compared with 0x0C)
	uint refreshFlag;                 // +0xAC: Refresh/redraw flag
	uint dialogType;                  // +0xB0: Dialog state (0xB, 0xD, -1 special values)
	uint dialogMode;                  // +0xB4: Dialog mode (0-9, controls behavior)
	uint dialogAction;                // +0xB8: Dialog action (0,1,2,5)
	uint dialogResult;                // +0xBC: Dialog result (0x43='C', 0x59='Y')
	uint savedValue1;                 // +0xC0: Saved value 1 (saved from parsed result, copied to array at dialog confirm)
	uint savedValue2;                 // +0xC4: Saved value 2 (saved from parsed result, copied to array at dialog confirm)
	uint activeGameIndexOld;          // +0xC8: Active game index (old location, see +0x100 also called 200 decimal)
	uint operationMode;               // +0xCC: Operation mode (0,1,2,0xC,0xD,0x3E6)
	uint gameListIndex;               // +0xD0: Game list index (used in menu navigation and array offset calculations)
	uint clearFlag;                   // +0xD4: Clear/reset flag (set to 0 on state reset)
	uint savedGameListIndex;          // +0xD8: Saved game list index
	uint uiUpdateFlag;                // +0xDC: UI update flag
	uint hexEditPosition;             // +0xE0: Hex editor position
	uint stringLength;                // +0xE4: String length counter
	uint hexEditValue;                // +0xE8: Hex editor current value
	uint codeFlags;                   // +0xEC: Code flags (copied from 0xA4)
	uint hexEditCursorPos;            // +0xF0: Hex editor cursor position
	uint inputCounter;                // +0xF4: Input counter
	uint keyInputCounter;             // +0xF8: Key input counter
	uint newGameFlag;                 // +0xFC: New game flag
	uint gameMode;                    // +0x100: Game mode (also called activeGameIndex at offset 256 decimal)
	uint flashStatus;                 // +0x104: Flash operation status (also called enableCodesFlag)
	uint memoryCardOp;                // +0x108: Memory card operation state
	byte *stringBufferPtr;            // +0x10C: String buffer pointer
	uint firstByteValue;              // +0x110: First byte value
	uint unknown_0x114;               // +0x114: (No usage found in decompilation)
	uint savedValue3;                 // +0x118: Saved value 3
	uint flag_0x11C;                  // +0x11C: Flag at offset 0x11C
	uint biosParam1;                  // +0x120: BIOS parameter 1
	uint biosParam3;                  // +0x124: BIOS parameter 3
	uint biosParam2;                  // +0x128: BIOS parameter 2
	uint gameModeOrFlag;              // +0x12C: Game mode or flag
	uint initFlag;                    // +0x130: Initialization flag
	uint unknown_0x134;               // +0x134: (No usage found in decompilation)
	uint savedGameIndex;              // +0x138: Saved game index
	uint unknown_0x13C;               // +0x13C: (No usage found in decompilation)
	uint creditsCursorPos;            // +0x140: Credits screen cursor position
	uint creditsSelection;            // +0x144: Credits screen selection
	uint enableCodesFlag;             // +0x148: Enable codes flag (0/1) - also at offset 328 decimal
	uint totalGames_Slot2Alt;         // +0x14C: Total games slot 2 (alternate)
	uint totalGames_Slot1;            // +0x150: Total games slot 1
	uint totalGames_Slot2;            // +0x154: Total games slot 2
	uint card1Available;              // +0x158: Memory card 1 available flag
	uint card2Available;              // +0x15C: Memory card 2 available flag
	uint card1Formatted;              // +0x160: Memory card 1 formatted flag
	uint memCardStateMachine;         // +0x164: Memory card state machine
	uint memCardParam1;               // +0x168: Memory card parameter 1
	uint memCardParam2;               // +0x16C: Memory card parameter 2
	uint compressionIndex;            // +0x170: Compression index
	uint compressionStatus;           // +0x174: Compression status
	uint unknown_0x178;               // +0x178: (No usage found in decompilation)
	uint memCardStatus;               // +0x17C: Memory card status
	uint baseGameIndex1;              // +0x180: Base game index 1
	uint card1GameIndex;              // +0x184: Card 1 game index
	uint selectedGameSlot1;           // +0x188: Selected game slot 1
	uint selectedGameSlot2;           // +0x18C: Selected game slot 2
	uint unknown_0x190;               // +0x190: (No usage found in decompilation)
	uint frameCounter;                // +0x194: Frame counter
	uint totalCodesInGame;            // +0x198: Total codes in current game
	uint unknown_0x19C;               // +0x19C: (No usage found in decompilation)
	uint specialFlag;                 // +0x1A0: Special flag
	uint memCard1ErrorFlag;           // +0x1A4: Memory card 1 error flag
	uint memCard2ErrorFlag;           // +0x1A8: Memory card 2 error flag
	uint hardwareFlag;                // +0x1AC: Hardware flag
	uint buttonConfigFlag;            // +0x1B0: Button configuration flag
	uint menuRefreshFlag;             // +0x1B4: Menu refresh flag
	byte padding_0x1B8[3656];         // +0x1B8: Padding/reserved space (3656 bytes)
	// Note: Global + 0x1000 and Global + 0x1080 are used as scratch buffers in code,
	// but are NOT formal structure members. Access them via pointer arithmetic:
	// - (Global + 0x1000): 128-byte scratch buffer for text formatting
	// - (Global + 0x1080): Small scratch buffer for hex digit conversion
} GameSharkGlobalState;

// Menu Strings Table (PTR_DAT_1f013530)
// Array of pointers to menu string resources
typedef struct MenuStringTable {
	byte **stringPointers;            // Array of byte pointers to null-terminated strings
} MenuStringTable;

// Dialog Strings Table (PTR_DAT_1f013534)
// Pointers to dialog message strings
typedef byte* DialogStringTable;

// Dialog/Menu Button Options (PTR_DAT_1f013540, PTR_DAT_1f013544, PTR_DAT_1f013548, PTR_DAT_1f01354c)
// Arrays used for menu selection and dialog boxes
typedef uint DialogOptionArray[];

// Graphics/Display Buffers (PTR_DAT_1f013564, PTR_DAT_1f013574, PTR_DAT_1f013578, PTR_DAT_1f01357c)
// Character display and font rendering buffers
typedef struct DisplayBuffers {
	byte *charBuffer1;                // PTR_DAT_1f013564: Character buffer (0x21 bytes)
	byte *charBuffer2;                // PTR_DAT_1f013574: Character line buffer (0x21 * 0x8C entries)
	byte *charBuffer3;                // PTR_DAT_1f013578: Character data buffer (0x21 bytes per line)
	byte *charMatrix;                 // PTR_DAT_1f01357c: Character matrix (0x16 * 0x8C entries)
} DisplayBuffers;

// Code Data Structure (embedded in game data)
// Individual cheat code entry in GameShark format (8 bytes per code)
typedef struct CheatCode {
	byte type;                        // Code type (0x00=header, 0xFF=end marker, other=code)
	byte nameLength;                  // Length of code name string
	byte paramCount;                  // Number of parameters
	char name[];                      // Null-terminated code name
	// Followed by parameter data
} CheatCode;

// ============================================================================
// GameShark Cheat Code Format (8 bytes per code)
// ============================================================================
// Format: [AABBCCCC] [DDDDDDDD]
//   AA = Command type (8-bit)
//   BB = Address upper byte / sub-command
//   CCCC = Address lower 16 bits
//   DDDDDDDD = Data value (32-bit)
//
// Supported Commands (v1.99):
//   30 = 8-bit Write:  30BBAAAA 000000YY  (Write byte YY to 0x00BBAAAA)
//   80 = 16-bit Write: 80BBAAAA 0000YYYY  (Write word YYYY to 0x00BBAAAA)
// ============================================================================

// Game Entry Structure (in flash memory)
// Format of game data in flash storage
typedef struct GameEntry {
	byte headerType;                  // 0x00 for master code header, 0xFF for end
	byte nameLength;                  // Length of game name
	byte codeCount;                   // Number of codes in this game
	char gameName[];                  // Null-terminated game name
	// Followed by code data array
} GameEntry;

// Function Pointer Tables
typedef void (*FunctionPtr)(void);

typedef struct FunctionPointerTable {
	FunctionPtr *functions;
} FunctionPointerTable;

// ============================================================================
// External declarations for global pointers
// RAM Buffer Pointer Table (ROM 0x1F01352C - 0x1F01358F)
// Total: 25 pointers defining GameShark RAM allocation
// ============================================================================

// Main Global State Structure
extern GameSharkGlobalState *PTR_DAT_1f01352c;   // 0x80011000: Global State (8 KB)

// RAM Work Buffers (allocated at runtime)
extern byte *PTR_DAT_1f013530;                   // 0x80013000: Game list buffer (40 KB)
extern byte *PTR_DAT_1f013534;                   // 0x8001D000: Dialog/temp buffer (768 bytes)
extern byte *PTR_DAT_1f013538;                   // 0x8001D300: Small buffer A (256 bytes)
extern byte *PTR_DAT_1f01353c;                   // 0x8001D400: Small buffer B (256 bytes)
extern byte *PTR_DAT_1f013540;                   // 0x8001D500: Code list pointers (80 bytes)
extern byte *PTR_DAT_1f013544;                   // 0x8001D550: Code data buffer (176 bytes)
extern byte *PTR_DAT_1f013548;                   // 0x8001D600: Game name buffer (512 bytes)
extern byte *PTR_DAT_1f01354c;                   // 0x8001D800: String buffer (512 bytes)
extern byte *PTR_DAT_1f013550;                   // 0x8001DA00: Text buffer (512 bytes)
extern byte *PTR_DAT_1f013554;                   // 0x8001DC00: Display buffer (768 bytes)
extern byte *PTR_DAT_1f013558;                   // 0x8001DF00: Menu buffer (256 bytes)
extern byte *PTR_DAT_1f01355c;                   // 0x8001D600: Alias to PTR_DAT_1f013548 (duplicate)
extern byte *PTR_DAT_1f013560;                   // 0x8001E000: Large work buffer (12 KB)
extern byte *PTR_DAT_1f013564;                   // 0x80021000: Flash/Memory card data (444 KB)
extern byte *PTR_DAT_1f013568;                   // 0x80090000: Reserved region (128 KB)
extern byte *PTR_DAT_1f01356c;                   // 0x800B0000: RLE compression input (192 KB)
extern byte *PTR_DAT_1f013570;                   // 0x800E0000: Decompression output (128 KB)
extern byte *PTR_DAT_1f013574;                   // 0x80100000: Game list 0x21-byte entries (8 KB)
extern byte *PTR_DAT_1f013578;                   // 0x80102000: Code edit buffer (1 KB)
extern byte *PTR_DAT_1f01357c;                   // 0x80102400: Parameter buffer (7 KB)
extern byte *PTR_DAT_1f013580;                   // 0x80104000: Stack/scratch area (8 KB)
extern byte *PTR_DAT_1f013584;                   // 0x80106000: Input buffer (1 KB)
extern byte *PTR_DAT_1f013588;                   // 0x80106400: Extended buffer (7 KB)
extern byte *PTR_DAT_1f01358c;                   // 0x80108000: Large allocation (992 KB)

// Function pointers (from other ROM locations)
extern FunctionPtr PTR_FUN_1f001cd0;             // Function pointer 1
extern FunctionPtr PTR_FUN_1f001cd4;             // Function pointer 2
extern FunctionPtr PTR_FUN_1f004b34;             // Function pointer 3
extern FunctionPtr PTR_FUN_1f004b38;             // Function pointer 4

// ============================================================================
// String Constants (Dialog Buttons)
// Defined in ROM at 0x13b74-0x13c70
// ============================================================================

extern const char s_SAVE_1f013b74[8];           // "SAVE\0\0\0\0" - Dialog save button
extern const char s_EDIT_1f013c5c[8];           // "EDIT\0\0\0\0" - Dialog edit button
extern const char s_EXIT_1f013c64[8];           // "EXIT\0\0\0\0" - Dialog exit button

// ============================================================================
// RAM Buffer Pointers
// See gameshark_rom_symbols.h for complete mappings and memory layout
// ============================================================================

// Compression system constants
#define RLE_MAGIC_R           'R'
#define RLE_MAGIC_L           'L'
#define RLE_MAGIC_E           'E'
#define RLE_MAGIC_0           '0'

#define IS_RLE_COMPRESSED(ptr) \
    ((ptr)[0] == RLE_MAGIC_R && \
     (ptr)[1] == RLE_MAGIC_L && \
     (ptr)[2] == RLE_MAGIC_E && \
     (ptr)[3] == RLE_MAGIC_0)

// Game list constants
#define GAME_ENTRY_SIZE       0x21    // 33 bytes per game entry
#define CODE_ENTRY_SIZE       0x36    // 54 bytes per code entry

// Memory card buffer sizes
#define MEMCARD_BUFFER_SIZE   0x00004000  // 16 KB per slot
#define MEMCARD_WORK_SIZE     0x00020000  // 128 KB work area

#endif // GAMESHARK_STRUCTURES_H
