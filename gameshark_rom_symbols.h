/*
 * GameShark v1.99 ROM Symbol Definitions
 * Auto-generated from ROM binary analysis
 * 
 * This file provides proper names for Ghidra auto-generated symbols
 * (DAT_*, PTR_DAT_*, PTR_FUN_*) based on ROM data analysis.
 */

#ifndef GAMESHARK_ROM_SYMBOLS_H
#define GAMESHARK_ROM_SYMBOLS_H

#include <stdint.h>

/* ========================================================================
 * STRING CONSTANTS
 * ======================================================================== */

/* Main Menu Strings (ROM 0x13590-0x13750) */
extern const char s_GameShark_PLAYSTATION_Version_1_99_1f013590[];  /* "GameShark PLAYSTATION Version 1.99" */
extern const char s_MAIN_MENU_1f0135b4[];                           /* "MAIN  MENU" */
extern const char s_NO_GAME_SELECTED_1f0135c0[];                    /* "NO GAME SELECTED" */
extern const char s_NO_ENHANCEMENT_CODES_ARE_ON_1f0135d4[];         /* "NO ENHANCEMENT CODES ARE ON" */
extern const char s_ENHANCEMENTS_ARE_ON_1f0135f0[];                 /* "ENHANCEMENTS ARE ON" */
extern const char s_NO_CODES_ARE_ON_1f013604[];                     /* "NO CODES ARE ON" */
extern const char s_GAMES_SUPPORTED_1f013614[];                     /* "GAMES SUPPORTED" */
extern const char s_CODES_IN_TOTAL_1f013624[];                      /* "CODES IN TOTAL" */
extern const char s_UP_DOWN_HIGHLIGHT_1f013634[];                   /* "UP/DOWN:HIGHLIGHT   »:SELECT" */
extern const char s_RIGHT_TRIGGER_1_PLUS_SELECT_SWAP_1f013650[];    /* "RIGHT TRIGGER 1+SELECT:SWAP »/¹" */
extern const char s_START_GAME_1f013674[];                          /* "START GAME" */
extern const char s_SELECT_ENHANCEMENTS_1f013680[];                 /* "SELECT  ENHANCEMENTS" */
extern const char s_MEMORY_CARD_MANAGER_1f013698[];                 /* "MEMORY CARD MANAGER" */
extern const char s_CREDITS_1f0136ac[];                             /* "CREDITS" */
extern const char s_SWAPPING_THE_BUTTONS_1f0136b4[];                /* "SWAPPING THE » and ¹ BUTTONS" */
extern const char s_Note_Any_mention_of_these_1f0136d4[];           /* "Note: Any mention of these" */
extern const char s_buttons_in_the_manual_may_1f0136f0[];           /* "buttons in the manual may" */
extern const char s_be_incorrect_1f01370c[];                        /* "be incorrect" */
extern const char s_The_buttons_will_now_be_set_1f01371c[];         /* "The buttons will now be set" */
extern const char s_as_in_the_manual_1f013738[];                    /* "as in the manual" */

/* Credits Strings (ROM 0x13750-0x13930) */
extern const char s_GameShark_is_based_on_1f013750[];               /* "GameShark is based on" */
extern const char s_ACTION_REPLAY_technology_1f013768[];            /* "ACTION REPLAY technology" */
extern const char s_copyright_Datel_Design_1f013784[];              /* "copyright Datel Design &" */
extern const char s_Development_1995_1996_1f0137a0[];               /* "Development 1995/1996." */
extern const char s_GameShark_is_neither_1f0137c0[];                /* "GameShark is neither" */
extern const char s_licensed_nor_endorsed_1f0137d0[];               /* "licensed nor endorsed" */
extern const char s_by_Sony_Computer_1f0137e8[];                    /* "by Sony Computer" */
extern const char s_Entertainment_Inc_1f0137fc[];                   /* "Entertainment Inc." */
extern const char s_Distributed_by_Interact_1f013810[];             /* "Distributed by Interact" */
extern const char s_Multimedia_Products_1f013824[];                 /* "Multimedia Products" */
extern const char s_1995_1996_1f013838[];                           /* "1995/1996" */
extern const char s_PlayStation_Version_1_99_1f013844[];            /* "PlayStation Version 1.99" */
extern const char s_RETURN_TO_MAIN_MENU_1f013864[];                 /* "¹:RETURN TO MAIN MENU" */
extern const char s_PROGRAMMING_1f013880[];                         /* "PROGRAMMING       " */
extern const char s_Gavin_Thornton_1f013890[];                      /* "   Gavin Thornton " */
extern const char s_Wayne_Beckett_1f0138a4[];                       /* "   Wayne Beckett  " */
extern const char s_Colin_Whitehouse_1f0138b8[];                    /* "   Colin Whitehouse" */
extern const char s_HARDWARE_1f0138cc[];                            /* "HARDWARE          " */
extern const char s_Roy_Harding_1f0138e4[];                         /* "   Roy Harding    " */
extern const char s_GRAPHICS_1f0138f8[];                            /* "GRAPHICS          " */
extern const char s_SUPPORT_1f013908[];                             /* "SUPPORT           " */
extern const char s_Mark_Wallace_1f013920[];                        /* "   Mark Wallace   " */
extern const char s_Press_to_finish_1f013930[];                     /* "Press » to finish" */

/* System Messages (ROM 0x13940-0x13990) */
extern const char s_Loading_1f013940[];                             /* "Loading" (actual ROM offset 0x13944) */
extern const char s_Please_Wait_1f01394c[];                         /* "Please Wait" */
extern const char s_Please_move_the_1f01395c[];                     /* "Please move the" (actual ROM offset 0x13958) */
extern const char s_Switch_to_its_UP_position_1f01396c[];           /* "Switch to it's UP position" (actual ROM offset 0x13968) */
extern const char s_Thankyou_1f013980[];                            /* "Thankyou" (actual ROM offset 0x13984) */
extern const char s_DEF01_1f013990[];                               /* "DEF01" - decompression magic */
extern const char s_RLE01_1f013998[];                               /* "RLE01" - RLE compression magic */

/* Menu/Dialog Control Strings (ROM 0x139a0-0x13a40) */
extern const char s_SELECT_ENHANCEMENTS_1f0139a0[];                 /* "SELECT ENHANCEMENTS" */
extern const char s_SELECT_EXIT_DELETE_1f0139b4[];                  /* "»:SELECT  ¹:EXIT  º:DELETE" */
extern const char s_SELECT_GAME_1f0139d4[];                         /* "SELECT GAME" */
extern const char s_SELECT_ENHANCEMENT_CODES_1f0139e0[];            /* "SELECT ENHANCEMENT CODES" */
extern const char s_ON_OFF_controls_1f0139fc[];                     /* "»:ON/OFF  ¹:EXIT  ¼:EDIT  º:DELETE" */
extern const char s_START_START_GAME_1f013a20[];                    /* "START:START GAME" */
extern const char s_OK_1f013a34[];                                  /* "»:OK" */

/* Dialog Prompts (ROM 0x13a3c-0x13c70) */
extern const char s_DELETE_THE_CODE_ARE_YOU_SURE_1f013a3c[];        /* "DELETE THE CODE! ARE YOU SURE?" */
extern const char s_Deleting_the_code_will_1f013a5c[];              /* "Deleting the code will" */
extern const char s_lose_all_its_information_1f013a74[];            /* "lose all it's information" */
extern const char s_PERMANENTLY_Are_you_sure_1f013a90[];            /* "PERMANENTLY! Are you sure?" */
extern const char s_DELETE_1f013aac[];                              /* "DELETE" */
extern const char s_CANCEL_1f013ab4[];                              /* "CANCEL" */
extern const char s_DELETE_THE_GAME_ARE_YOU_SURE_1f013abc[];        /* "DELETE THE GAME! ARE YOU SURE?" */
extern const char s_Deleting_the_game_will_lose_all_1f013adc[];     /* "Deleting the game will lose all" */
extern const char s_its_information_PERMANENTLY_1f013afc[];         /* "it's information PERMANENTLY." */
extern const char s_All_its_codes_will_be_deleted_1f013b1c[];       /* "All it's codes will be deleted!" */
extern const char s_SAVE_CHANGES_1f013b3c[];                        /* "SAVE CHANGES?" */
extern const char s_Select_SAVE_to_keep_the_1f013b4c[];             /* "Select SAVE to keep the" */
extern const char s_changes_made_1f013b64[];                        /* "changes made." */
extern const char s_SAVE_1f013b74[8];                               /* "SAVE\0\0\0\0" */
extern const char s_DISCARD_1f013b7c[];                             /* "DISCARD" */
extern const char s_SAVE_AND_CREATE_NEW_GAME_1f013b84[];            /* "SAVE AND CREATE NEW GAME?" */
extern const char s_Select_SAVE_to_save_this_edit_1f013ba0[];       /* "Select SAVE to save this edit" */
extern const char s_and_create_a_new_game_set_1f013bc0[];           /* "and create a new game set." */
extern const char s_Select_DISCARD_to_abort_1f013bdc[];             /* "Select DISCARD to abort." */
extern const char s_NO_PARAMETER_SPECIFIED_1f013bf8[];              /* "NO PARAMETER SPECIFIED" */
extern const char s_The_code_will_not_be_1f013c10[];                /* "The code will not be" */
extern const char s_saved_without_a_parameter_1f013c28[];           /* "saved without a parameter." */
extern const char s_Select_EDIT_to_resume_1f013c44[];               /* "Select EDIT to resume." */
extern const char s_EDIT_1f013c5c[8];                               /* "EDIT\0\0\0\0" */
extern const char s_EXIT_1f013c64[8];                               /* "EXIT\0\0\0\0" */

/* Error Messages (ROM 0x13ca0-0x13dd0) */
extern const char s_You_cannot_delete_this_1f013ca0[];              /* "You cannot delete this," */
extern const char s_it_is_not_a_code_1f013cb8[];                    /* "it is not a code" */
extern const char s_it_is_not_a_game_1f013ccc[];                    /* "it is not a game" */
extern const char s_Enable_codes_must_be_1f013ce0[];                /* "Enable codes must be" */
extern const char s_on_to_run_the_game_1f013cf8[];                  /* "on to run the game" */
extern const char s_ERROR_ERASING_FLASH_1f013d0c[];                 /* "ERROR ERASING FLASH" */
extern const char s_CANNOT_EDIT_GAMES_1f013d20[];                   /* "CANNOT EDIT GAMES!" */
extern const char s_NOT_ENOUGH_FREE_SPACE_TO_1f013d34[];            /* "NOT ENOUGH FREE SPACE TO" */
extern const char s_SAVE_DELETE_A_GAME_1f013d50[];                  /* "SAVE. DELETE A GAME." */
extern const char s_ENABLE_CODE_1f013dc0[];                         /* "ENABLE CODE" */
extern const char s_ENABLE_CODE_MUST_BE_ON_1f013dcc[];              /* "ENABLE CODE (MUST BE ON)" */

/* Code Editor Strings (ROM 0x13e20-0x13e80) */
extern const char s_no_cheats_defined_1f013e24[];                   /* "no cheats defined!" */
extern const char s_master_code_1f013e38[];                         /* "-- master code --" */
extern const char s_new_code_1f013e4c[];                            /* "--- new  code ---" */
extern const char s_Sorting_Game_List_1f013e60[];                   /* "Sorting Game List" */
extern const char s_New_Game_1f013e74[];                            /* "--- New Game ---" */

/* Flash/Programming Strings (ROM 0x134c0-0x134d8) */
extern const char s_program_flash_in_1f0134c0[];                    /* "program flash in" (used in FUN_1f0004dc) */
extern const char s_program_flash_out_1f0134d4[];                   /* "program flash out" (used in FUN_1f0004dc) */

/* Character Input Tables (ROM 0x13e88-0x13f1c) */
extern const char s_CHAR_ROW_1_1f013e88[];                          /* "A B C D E F G" */
extern const char s_CHAR_ROW_2_1f013e98[];                          /* "H I J K L M N" */
extern const char s_CHAR_ROW_3_1f013ea8[];                          /* "O P Q R S T U" */
extern const char s_CHAR_ROW_4_1f013eb8[];                          /* "V W X Y Z 0 1" */
extern const char s_CHAR_ROW_5_1f013ec8[];                          /* "2 3 4 5 6 7 8" */
extern const char s_CHAR_ROW_6_1f013ed8[];                          /* "9 - ! ' ( )" */
extern const char s_HEX_ROW_1_1f013efc[];                           /* "0 1 2 3" */
extern const char s_HEX_ROW_2_1f013f04[];                           /* "4 5 6 7" */
extern const char s_HEX_ROW_3_1f013f0c[];                           /* "8 9 A B" */
extern const char s_HEX_ROW_4_1f013f14[];                           /* "C D E F" */

/* Input Control Hints (ROM 0x13f20-0x13f60) */
extern const char s_SELECT_EXIT_BACKSPACE_CLEAR_1f013f2c[];         /* "»:SELECT  ¹:EXIT  ¼:BACKSPACE  º:CLEAR" */
extern const char s_underscore_1f013f54[];                          /* "_" */
extern const char s_ellipsis_1f013f68[];                            /* "...." */

/* ========================================================================
 * ROM FUNCTION POINTERS
 * ======================================================================== */

/* Primary Function Pointer Table (ROM 0x1cd0-0x1cd4) */
#define PTR_FUN_1f001cd0      ((void*)0x1F0014A8)  /* ROM function at offset 0x14A8 */
#define PTR_FUN_1f001cd4      ((void*)0x1F001704)  /* ROM function at offset 0x1704 */

/* Secondary Function Pointer Table (ROM 0x4b34-0x4b38) */
#define PTR_FUN_1f004b34      ((void*)0x1F000DFC)  /* ROM function at offset 0xDFC */
#define PTR_FUN_1f004b38      ((void*)0x1F000F7C)  /* ROM function at offset 0xF7C */

/* ========================================================================
 * ROM DATA POINTERS
 * ======================================================================== */

/* Data Pointer Table (ROM 0x4b2c-0x4b3c) */
#define PTR_DAT_1f004b2c      ((void*)0x1F0047F4)  /* ROM data at offset 0x47F4 */
#define PTR_DAT_1f004b30      ((void*)0x1F004808)  /* ROM data at offset 0x4808 */
#define DAT_1f004b3c          ((void*)0x800005F4)  /* RAM address (PS1 Main RAM) */

/* Additional ROM Data Pointer (ROM 0x6a2c) */
#define PTR_DAT_1f006a2c      ((void*)0x1F0065AC)  /* ROM data at offset 0x65AC */

/* ========================================================================
 * RAM BUFFER POINTER TABLE (Primary)
 * ROM 0x1352c-0x13588 defining PS1 RAM allocations
 * ======================================================================== */

/* Global state structure (already defined in gameshark_structures.h) */
#define PTR_GLOBAL_STATE      ((void*)0x80011000)  /* 4226 bytes - GameSharkGlobalState */

/* Working buffers */
#define PTR_WORK_BUFFER       ((void*)0x80013000)  /* ~40 KB general purpose */
#define PTR_TEMP_BUFFER       ((void*)0x8001D000)  /* 768 bytes temporary */
#define PTR_SMALL_BUFFER_A    ((void*)0x8001D300)  /* 256 bytes */
#define PTR_SMALL_BUFFER_B    ((void*)0x8001D400)  /* 256 bytes */

/* Code management buffers */
#define PTR_CODE_LIST         ((void*)0x8001D500)  /* 80 bytes - code list pointers */
#define PTR_CODE_DATA         ((void*)0x8001D550)  /* 176 bytes - code data */
#define PTR_GAME_NAME         ((void*)0x8001D600)  /* 512 bytes - game names */
#define PTR_STRING_BUFFER     ((void*)0x8001D800)  /* 512 bytes - strings */
#define PTR_TEXT_BUFFER       ((void*)0x8001DA00)  /* 512 bytes - text */
#define PTR_DISPLAY_BUFFER    ((void*)0x8001DC00)  /* 768 bytes - display */
#define PTR_MENU_BUFFER       ((void*)0x8001DF00)  /* 256 bytes - menu */

/* Large buffers */
#define PTR_LARGE_WORK        ((void*)0x8001E000)  /* 12 KB work buffer */
#define PTR_FLASH_DATA        ((void*)0x80021000)  /* 450 KB flash/memory card */

/* Compression system */
#define PTR_RLE_COMPRESS      ((void*)0x800B0000)  /* 192 KB - RLE compression input ("RLE0") */
#define PTR_DECOMPRESS        ((void*)0x800E0000)  /* 128 KB - decompression output */

/* Decompression targets for ROM compressed blocks */
#define PTR_UI_RESOURCES      ((void*)0x80018000)  /* UI dialogs/menus (decompressed from ROM 0x1F017A60 RLE0) */
#define PTR_CODE_ENGINE       ((void*)0x80020000)  /* Code execution engine (decompressed from ROM 0x1F015B40 RLE0) */
#define PTR_FONT_DATA         ((void*)0x80140000)  /* Font/graphics data (decompressed from ROM 0x1F015FF0 DEF0) */
#define PTR_GAME_DATABASE     ((void*)0x80150000)  /* Game database (decompressed from ROM 0x1F017450 DEF0) */

/* ROM compressed data blocks */
#define ROM_COMPRESSED_RLE0_CODE_ENGINE   ((const void*)0x1F015B40)  /* 1200 bytes - RLE0 code engine */
#define ROM_COMPRESSED_DEF0_FONT_DATA     ((const void*)0x1F015FF0)  /* 5216 bytes - DEF0 font data */
#define ROM_COMPRESSED_DEF0_GAME_DATABASE ((const void*)0x1F017450)  /* 1552 bytes - DEF0 game DB */
#define ROM_COMPRESSED_RLE0_UI_RESOURCES  ((const void*)0x1F017A60)  /* 17824 bytes - RLE0 UI data */

/* ROM game database template */
#define ROM_GAME_TEMPLATE                 ((const void*)0x1F01C000)  /* 16384 bytes - "New Game" template */
#define ROM_GAME_TEMPLATE_SIZE            0x4000                     /* 16 KB */
#define FLASH_GAME_DATABASE               ((const void*)0x1F040000)  /* 114688 bytes - flash extension (if present) */
#define FLASH_GAME_DATABASE_SIZE          0x1C000                    /* 112 KB */
#define MAX_GAME_DATABASE_SIZE            0x20000                    /* 128 KB total (ROM + flash) */

/* Game database */
#define PTR_GAME_LIST         ((void*)0x80100000)  /* 8 KB - game entries (0x21-byte each) */
#define PTR_CODE_EDIT         ((void*)0x80102000)  /* 1 KB - code editor */
#define PTR_PARAM_BUFFER      ((void*)0x80102400)  /* 7 KB - parameters */
#define PTR_STACK_SCRATCH     ((void*)0x80104000)  /* 8 KB - stack/scratch */
#define PTR_INPUT_BUFFER      ((void*)0x80106000)  /* 1 KB - input */
#define PTR_EXTENDED_BUFFER   ((void*)0x80106400)  /* Extended buffer */

/* ========================================================================
 * MEMORY CARD SYSTEM POINTERS
 * ROM 0x13de8-0x13dfc
 * ======================================================================== */

#define PTR_MEMCARD_SLOT1     ((void*)0x80180000)  /* 16 KB - memory card slot 1 */
#define PTR_MEMCARD_WORK      ((void*)0x80184000)  /* 112 KB - work buffer */
#define PTR_MEMCARD_SLOT2     ((void*)0x801A0000)  /* 4 KB - memory card slot 2 */
#define PTR_MEMCARD_EXTENDED  ((void*)0x801A1000)  /* Extended buffer */

/* Memory card buffer sizes */
#define MEMCARD_BUFFER_SIZE   0x00004000           /* 16 KB per slot */
#define MEMCARD_WORK_SIZE     0x00020000           /* 128 KB work area */

/* ========================================================================
 * ICON/GRAPHICS BUFFERS
 * ROM 0x14288-0x14290
 * ======================================================================== */

#define PTR_ICON_BUFFER1      ((void*)0x80160000)  /* Icon buffer 1 */
#define PTR_ICON_BUFFER2      ((void*)0x80168000)  /* Icon buffer 2 */
#define PTR_GFX_WORK          ((void*)0x80170000)  /* Graphics work buffer */

/* ========================================================================
 * HARDWARE I/O REGISTERS (PlayStation 1)
 * ======================================================================== */

/* Flash ROM control registers */
#define REG_FLASH_CONTROL     ((volatile uint8_t*)0x1F060000)
#define REG_FLASH_DATA        ((volatile uint8_t*)0x1F060008)

/* Expansion port 2 (GameShark hardware) */
#define REG_EXP2_DATA         ((volatile uint8_t*)0x1F020010)
#define REG_EXP2_STATUS       ((volatile uint8_t*)0x1F020018)

/* ROM region flag */
#define REG_ROM_REGION        ((volatile uint8_t*)0x1F01FFF1)

/* ROM base address */
#define ROM_BASE_ADDRESS      0x1F000000
#define ROM_SIZE              0x00020000  /* 128 KB */

/* PS1 Main RAM */
#define PS1_RAM_BASE          0x80000000
#define PS1_RAM_SIZE          0x00200000  /* 2 MB */
#define PS1_KERNEL_END        0x80010FFF  /* BIOS/kernel space ends */

/* ========================================================================
 * COMPRESSION SYSTEM CONSTANTS
 * ======================================================================== */

/* RLE compression signature ("RLE0") */
#define RLE_MAGIC_R           'R'
#define RLE_MAGIC_L           'L'
#define RLE_MAGIC_E           'E'
#define RLE_MAGIC_0           '0'

/* DEF compression signature ("DEF0") */
#define DEF_MAGIC_D           'D'
#define DEF_MAGIC_E           'E'
#define DEF_MAGIC_F           'F'
#define DEF_MAGIC_0           '0'

/* Inline validation macros */
#define IS_RLE_COMPRESSED(ptr) \
	((ptr)[0] == RLE_MAGIC_R && \
	 (ptr)[1] == RLE_MAGIC_L && \
	 (ptr)[2] == RLE_MAGIC_E && \
	 (ptr)[3] == RLE_MAGIC_0)

#define IS_DEF_COMPRESSED(ptr) \
	((ptr)[0] == DEF_MAGIC_D && \
	 (ptr)[1] == DEF_MAGIC_E && \
	 (ptr)[2] == DEF_MAGIC_F && \
	 (ptr)[3] == DEF_MAGIC_0)

/* Compression buffer sizes */
#define RLE_COMPRESS_SIZE     0x00030000  /* 192 KB */
#define DECOMPRESS_SIZE       0x00020000  /* 128 KB */

/* ========================================================================
 * GAME LIST CONSTANTS
 * ======================================================================== */

#define GAME_ENTRY_SIZE       0x21    /* 33 bytes per game entry */
#define CODE_ENTRY_SIZE       0x36    /* 54 bytes per code entry (in some paths) */

/* ========================================================================
 * ROM FUNCTION POINTERS
 * ======================================================================== */

/* Flash Memory I/O Functions */
#define FUN_DATA_TRANSFER     ((void*)0x1F000110)  /* Core flash read/write/verify */
#define FUN_FLASH_PROGRAM     ((void*)0x1F0004DC)  /* High-level flash write wrapper */
#define FUN_FLASH_WRITE_BYTE  ((void*)0x1F000634)  /* Low-level flash write byte */
#define FUN_FLASH_READ_BYTE   ((void*)0x1F00067C)  /* Low-level flash read byte */
#define FUN_FLASH_WAIT_READY  ((void*)0x1F0006CC)  /* Wait for flash ready */

/* Debug and Serial I/O Functions */
#define FUN_CHAR_OUTPUT       ((void*)0x1F0006F4)  /* Output single character */
#define FUN_CHAR_INPUT        ((void*)0x1F000714)  /* Input single character */
#define FUN_STRING_OUTPUT     ((void*)0x1F000A1C)  /* Output null-terminated string */
#define FUN_HEX_DUMP          ((void*)0x1F000804)  /* Format and output hex dump */

/* Graphics Functions */
#define FUN_LOAD_FRAMEBUFFER  ((void*)0x1F0014A8)  /* Load frame buffer to GPU */
#define FUN_READ_FRAMEBUFFER  ((void*)0x1F001704)  /* Read frame buffer from GPU */

/* Interrupt and Control Functions */
#define FUN_ENTER_CRITICAL    ((void*)0x1F00249C)  /* Enter critical section (syscall 0) */
#define FUN_EXIT_CRITICAL     ((void*)0x1F0024BC)  /* Exit critical section (syscall 0) */
#define FUN_MEMORY_ZERO       ((void*)0x1F0024CC)  /* Zero-fill memory buffer */
#define FUN_IRQ_DISPATCHER    ((void*)0x1F0024F8)  /* Main interrupt dispatcher */
#define FUN_DMA_INIT          ((void*)0x1F002760)  /* Initialize DMA interrupts */
#define FUN_TIMER_INIT        ((void*)0x1F0027C4)  /* Initialize Timer 0 interrupts */
#define FUN_IRQ_ENABLE        ((void*)0x1F0028BC)  /* Enable/disable IRQ source */
#define FUN_ROM_PTR_INIT      ((void*)0x1F002A0C)  /* Initialize ROM pointer table */
#define FUN_SERIAL_HANDSHAKE  ((void*)0x1F002AFC)  /* Wait for "din" handshake */
#define FUN_WRITE_U32         ((void*)0x1F002B6C)  /* Write 32-bit value bytewise */
#define FUN_WRITE_U16         ((void*)0x1F002BDC)  /* Write 16-bit value bytewise */

/* Utility Functions */
#define FUN_MEMORY_COMPARE    ((void*)0x1F00053C)  /* Optimized memory comparison */

/* Compression Functions */
#define FUN_FIND_ESCAPE_CHAR  ((void*)0x1F007020)  /* Find unused escape character */
#define FUN_DEF0_DECOMPRESS   ((void*)0x1F007110)  /* DEF0 format decompression (LZ77 variant) */
#define FUN_DEF0_COMPRESS     ((void*)0x1F00722C)  /* DEF0 format compression (LZ77 variant) */
#define FUN_RLE_COMPRESS      ((void*)0x1F0073EC)  /* Run-length encoding compression */
#define FUN_RLE_DECOMPRESS    ((void*)0x1F007548)  /* Run-length encoding decompression */

/* Game Management Functions */
#define FUN_COUNT_ENABLED_CODES ((void*)0x1F008EB8)  /* Count active codes in current game */
#define FUN_STRING_COMPARE      ((void*)0x1F008F18)  /* Compare two null-terminated strings */
#define FUN_ALIGN_TO_4          ((void*)0x1F008F74)  /* Round up to 4-byte boundary */
#define FUN_INSERT_SORTED_GAME  ((void*)0x1F008F94)  /* Insert game into sorted list */
#define FUN_INIT_NEW_GAME       ((void*)0x1F0090E8)  /* Initialize new game entry */
#define FUN_LOAD_GAME_LIST      ((void*)0x1F0091E8)  /* Load game database */
#define FUN_PARSE_GAME_ENTRY    ((void*)0x1F0094B8)  /* Parse game entry and set globals */
#define FUN_GET_GAME_BY_INDEX   ((void*)0x1F009620)  /* Retrieve game by index */
#define FUN_NAVIGATE_CODE_LIST  ((void*)0x1F009784)  /* Navigate to code in list */

/* UI/Display Functions */
#define FUN_DISPLAY_CODE_LIST   ((void*)0x1F0098BC)  /* Render scrollable code list */
#define FUN_DISPLAY_TEXT_AT_POS ((void*)0x1F00DEB4)  /* Render text at position */
#define FUN_DISPLAY_CENTERED    ((void*)0x1F00DF44)  /* Render centered text */
#define FUN_DISPLAY_PADDED      ((void*)0x1F00DFA0)  /* Render padded/centered text */
#define FUN_DISPLAY_SELECTED    ((void*)0x1F00E110)  /* Render text with selection markers */
#define FUN_DISPLAY_CHAR_GLYPH  ((void*)0x1F00E2D0)  /* Render character from font */
#define FUN_DISPLAY_HEX_DIGIT   ((void*)0x1F00E404)  /* Render hex digit (0-F) */
#define FUN_DISPLAY_HEX_BYTE    ((void*)0x1F00E4B4)  /* Render byte as hex (00-FF) */

/* String/Utility Functions */
#define FUN_STRING_LENGTH       ((void*)0x1F00D660)  /* Calculate string length */
#define FUN_STRING_LENGTH_DUP   ((void*)0x1F00DCE0)  /* Calculate string length (dup) */
#define FUN_COPY_STRING_LIMITED ((void*)0x1F00ADF8)  /* Copy string with limit */

/* Memory Card Functions */
#define FUN_GET_ICON_DATA       ((void*)0x1F00ACE4)  /* Extract memory card icon */
#define FUN_MEMCARD_READ        ((void*)0x1F00D6D4)  /* Read from memory card */
#define FUN_MEMCARD_INIT        ((void*)0x1F00D800)  /* Initialize memory card subsystem */

/* Input Functions */
#define FUN_READ_CONTROLLER     ((void*)0x1F00DE30)  /* Read controller button state */

/* Graphics Functions (additional) */
#define FUN_GPU_INIT            ((void*)0x1F00DE00)  /* Initialize GPU subsystem */

/* ========================================================================
 * ROM DATA POINTERS
 * ======================================================================== */

/* State machine control */
#define PTR_STATE_MACHINE     ((uint*)0x800005F4)  /* PTR_DAT_1f004b3c - State control variable */
#define PTR_STATE_BUFFER      ((void*)0x1F004B40)  /* PTR_DAT_1f004b40 - State buffer (8-byte entries) */

/* ========================================================================
 * INTERRUPT SYSTEM CONSTANTS
 * ======================================================================== */

/* IRQ source numbers (0-10) */
#define IRQ_VBLANK            0    /* VBlank interrupt */
#define IRQ_GPU               1    /* GPU interrupt */
#define IRQ_CDROM             2    /* CD-ROM interrupt */
#define IRQ_DMA               3    /* DMA interrupt */
#define IRQ_TIMER0            4    /* Timer 0 (RCnt 0) */
#define IRQ_TIMER1            5    /* Timer 1 (RCnt 1) */
#define IRQ_TIMER2            6    /* Timer 2 (RCnt 2) */
#define IRQ_MEMCARD           7    /* Memory card / controller */
#define IRQ_SIO               8    /* Serial I/O */
#define IRQ_SPU               9    /* Sound Processing Unit */
#define IRQ_LIGHTGUN          10   /* Lightgun / controller IRQ */

/* Interrupt handler table (RAM) */
#define IRQ_HANDLER_TABLE     ((void**)0x8002D2C4)  /* 11 function pointers */
#define IRQ_ENABLE_MASK       ((uint*)0x8002D2F0)   /* RAM interrupt enable mask */
#define IRQ_ACTIVE_FLAG       ((uint*)0x8002D2C2)   /* ISR active flag */

/* ========================================================================
 * BUFFER SIZE CONSTANTS
 * ======================================================================== */

#define GLOBAL_STATE_SIZE     0x1082  /* 4226 bytes - GameSharkGlobalState */
#define WORK_BUFFER_SIZE      0xA000  /* 40 KB - general work buffer */
#define TEMP_BUFFER_SIZE      0x0300  /* 768 bytes - temporary buffer */
#define SMALL_BUFFER_SIZE     0x0100  /* 256 bytes - small buffers A/B */
#define CODE_LIST_SIZE        0x0050  /* 80 bytes - code list pointers */
#define CODE_DATA_SIZE        0x00B0  /* 176 bytes - code data */
#define GAME_NAME_SIZE        0x0200  /* 512 bytes - game names */
#define STRING_BUFFER_SIZE    0x0200  /* 512 bytes - string buffer */
#define TEXT_BUFFER_SIZE      0x0200  /* 512 bytes - text buffer */
#define DISPLAY_BUFFER_SIZE   0x0300  /* 768 bytes - display buffer */
#define MENU_BUFFER_SIZE      0x0100  /* 256 bytes - menu buffer */
#define LARGE_WORK_SIZE       0x3000  /* 12 KB - large work buffer */
#define FLASH_DATA_SIZE       0x6F000 /* 450 KB - flash/memory card data */
#define GAME_LIST_SIZE        0x2000  /* 8 KB - game list buffer */
#define CODE_EDIT_SIZE        0x0400  /* 1 KB - code editor buffer */
#define PARAM_BUFFER_SIZE     0x1C00  /* 7 KB - parameter buffer */
#define STACK_SCRATCH_SIZE    0x2000  /* 8 KB - stack/scratch */
#define INPUT_BUFFER_SIZE     0x0400  /* 1 KB - input buffer */
#define ICON_BUFFER_SIZE      0x8000  /* 32 KB - icon buffer (each) */
#define GFX_WORK_SIZE         0x8000  /* 32 KB - graphics work */

/* ========================================================================
 * LEGACY SYMBOL MAPPING (for reference)
 * ======================================================================== */

/*
 * Ghidra Symbol -> Proper Name Mapping:
 * 
 * RAM POINTERS:
 * PTR_DAT_1f01352c -> PTR_GLOBAL_STATE (0x80011000)
 * PTR_DAT_1f013530 -> PTR_WORK_BUFFER (0x80013000)
 * PTR_DAT_1f013540 -> PTR_CODE_LIST (0x8001D500)
 * PTR_DAT_1f013544 -> PTR_CODE_DATA (0x8001D550)
 * PTR_DAT_1f013548 -> PTR_GAME_NAME (0x8001D600)
 * PTR_DAT_1f01354c -> PTR_STRING_BUFFER (0x8001D800)
 * PTR_DAT_1f013564 -> PTR_FLASH_DATA (0x80021000)
 * PTR_DAT_1f01356c -> PTR_RLE_COMPRESS (0x800B0000)
 * PTR_DAT_1f013570 -> PTR_DECOMPRESS (0x800E0000)
 * PTR_DAT_1f013574 -> PTR_GAME_LIST (0x80100000)
 * DAT_1f013de8 -> PTR_MEMCARD_SLOT1 (0x80180000)
 * DAT_1f013dec -> PTR_MEMCARD_WORK (0x80184000)
 * DAT_1f013df0 -> PTR_MEMCARD_SLOT2 (0x801A0000)
 * DAT_1f013dfc -> PTR_MEMCARD_EXTENDED (0x801A1000)
 * DAT_1f014288 -> PTR_ICON_BUFFER1 (0x80160000)
 * DAT_1f01428c -> PTR_ICON_BUFFER2 (0x80168000)
 * DAT_1f014290 -> PTR_GFX_WORK (0x80170000)
 * 
 * ROM FUNCTION POINTERS:
 * PTR_FUN_1f001cd0 -> 0x1F0014A8 (ROM function offset 0x14A8)
 * PTR_FUN_1f001cd4 -> 0x1F001704 (ROM function offset 0x1704)
 * PTR_FUN_1f004b34 -> 0x1F000DFC (ROM function offset 0xDFC)
 * PTR_FUN_1f004b38 -> 0x1F000F7C (ROM function offset 0xF7C)
 * 
 * ROM DATA POINTERS:
 * PTR_DAT_1f004b2c -> 0x1F0047F4 (ROM data offset 0x47F4)
 * PTR_DAT_1f004b30 -> 0x1F004808 (ROM data offset 0x4808)
 * DAT_1f004b3c -> 0x800005F4 (RAM address)
 * PTR_DAT_1f006a2c -> 0x1F0065AC (ROM data offset 0x65AC)
 * 
 * STRING CONSTANTS (ROM 0x13590-0x13f60):
 * DAT_1f013590 -> s_GameShark_PLAYSTATION_Version_1_99_1f013590
 * DAT_1f0135b4 -> s_MAIN_MENU_1f0135b4
 * DAT_1f0135c0 -> s_NO_GAME_SELECTED_1f0135c0
 * DAT_1f0135d4 -> s_NO_ENHANCEMENT_CODES_ARE_ON_1f0135d4
 * DAT_1f0135f0 -> s_ENHANCEMENTS_ARE_ON_1f0135f0
 * DAT_1f013604 -> s_NO_CODES_ARE_ON_1f013604
 * DAT_1f013614 -> s_GAMES_SUPPORTED_1f013614
 * DAT_1f013624 -> s_CODES_IN_TOTAL_1f013624
 * DAT_1f013674 -> s_START_GAME_1f013674
 * DAT_1f013680 -> s_SELECT_ENHANCEMENTS_1f013680
 * DAT_1f013698 -> s_MEMORY_CARD_MANAGER_1f013698
 * DAT_1f0136ac -> s_CREDITS_1f0136ac
 * DAT_1f013750 -> s_GameShark_is_based_on_1f013750
 * DAT_1f013768 -> s_ACTION_REPLAY_technology_1f013768
 * DAT_1f013a3c -> s_DELETE_THE_CODE_ARE_YOU_SURE_1f013a3c
 * DAT_1f013b3c -> s_SAVE_CHANGES_1f013b3c
 * DAT_1f013b74 -> s_SAVE_1f013b74
 * DAT_1f013b7c -> s_DISCARD_1f013b7c
 * DAT_1f013bf8 -> s_NO_PARAMETER_SPECIFIED_1f013bf8
 * DAT_1f013c5c -> s_EDIT_1f013c5c
 * DAT_1f013c64 -> s_EXIT_1f013c64
 * DAT_1f013e24 -> s_no_cheats_defined_1f013e24
 * DAT_1f013e38 -> s_master_code_1f013e38
 * DAT_1f013e4c -> s_new_code_1f013e4c
 * DAT_1f013e88 -> s_CHAR_ROW_1_1f013e88 (character input table)
 * DAT_1f013efc -> s_HEX_ROW_1_1f013efc (hex input table)
 */

/* ========================================================================
 * MEMORY MAP SUMMARY
 * ======================================================================== */

/*
 * PlayStation 1 RAM Usage (2 MB total):
 * 
 * 0x80011000-0x80012082: Global State (4.2 KB)
 * 0x80013000-0x8001FFFF: Work Buffers (52 KB)
 * 0x80021000-0x8008FFFF: Flash Data (444 KB)
 * 0x800B0000-0x800DFFFF: Compression (192 KB)
 * 0x800E0000-0x800FFFFF: Decompress (128 KB)
 * 0x80100000-0x80106FFF: Game Lists (28 KB)
 * 0x80160000-0x80177FFF: Icons/GFX (96 KB)
 * 0x80180000-0x801A1FFF: Memory Cards (136 KB)
 * 
 * Total Usage: ~1080 KB (1.05 MB) out of 2 MB
 */

/* ========================================================================
 * FUNCTION COUNT SUMMARY
 * ======================================================================== */

/*
 * Function Categories (54 documented functions):
 * 
 * Flash I/O:           5 functions (0x1F000110 - 0x1F0006CC)
 * Debug/Serial:        4 functions (0x1F0006F4 - 0x1F002BDC)
 * Graphics:            4 functions (0x1F0014A8 - 0x1F00DE00)
 * Interrupt/Control:   9 functions (0x1F00249C - 0x1F002BDC)
 * Compression:         5 functions (0x1F007020 - 0x1F007548)
 * Game Management:     9 functions (0x1F008EB8 - 0x1F009784)
 * UI/Display:          8 functions (0x1F0098BC - 0x1F00E4B4)
 * String/Utility:      4 functions (0x1F008F18 - 0x1F00DCE0)
 * Memory Card:         3 functions (0x1F00ACE4 - 0x1F00D800)
 * Input:               1 function  (0x1F00DE30)
 * Utility (misc):      2 functions (0x1F00053C - 0x1F0024CC)
 * 
 * Total: 54 fully documented functions
 * Pending: ~196 functions identified but not yet fully analyzed
 * ROM address range: 0x1F000000 - 0x1F01FFFF (128KB)
 */

#endif /* GAMESHARK_ROM_SYMBOLS_H */
