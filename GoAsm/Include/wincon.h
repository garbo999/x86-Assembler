#ifndef WINCON_H
#define WINCON_H

#define WINCON_H_REQVER 100

/*
Switches used
UNICODE
*/

#IFDEF LINKFILES
	#dynamiclinkfile Kernel32.dll
#ENDIF

/* Windows Console subsystem definitions */


#define RIGHT_ALT_PRESSED  0x0001
#define LEFT_ALT_PRESSED  0x0002
#define RIGHT_CTRL_PRESSED  0x0004
#define LEFT_CTRL_PRESSED  0x0008
#define SHIFT_PRESSED  0x0010
#define NUMLOCK_ON  0x0020
#define SCROLLLOCK_ON  0x0040
#define CAPSLOCK_ON  0x0080
#define ENHANCED_KEY  0x0100
#define NLS_DBCSCHAR  0x00010000
#define NLS_ALPHANUMERIC  0x00000000
#define NLS_KATAKANA  0x00020000
#define NLS_HIRAGANA  0x00040000
#define NLS_ROMAN  0x00400000
#define NLS_IME_CONVERSION  0x00800000
#define NLS_IME_DISABLE  0x20000000

#define FROM_LEFT_1ST_BUTTON_PRESSED  0x0001
#define FROM_LEFT_2ND_BUTTON_PRESSED  0x0004
#define FROM_LEFT_3RD_BUTTON_PRESSED  0x0008
#define FROM_LEFT_4TH_BUTTON_PRESSED  0x0010
#define RIGHTMOST_BUTTON_PRESSED  0x0002

#define MOUSE_MOVED  0x0001
#define DOUBLE_CLICK  0x0002
#define MOUSE_WHEELED  0x0004

#define KEY_EVENT  0x0001
#define MOUSE_EVENT  0x0002
#define WINDOW_BUFFER_SIZE_EVENT  0x0004
#define MENU_EVENT  0x0008
#define FOCUS_EVENT  0x0010

#define FOREGROUND_BLUE  0x0001
#define FOREGROUND_GREEN  0x0002
#define FOREGROUND_RED  0x0004
#define FOREGROUND_INTENSITY  0x0008
#define BACKGROUND_BLUE  0x0010
#define BACKGROUND_GREEN  0x0020
#define BACKGROUND_RED  0x0040
#define BACKGROUND_INTENSITY  0x0080

#define COMMON_LVB_LEADING_BYTE  0x0100
#define COMMON_LVB_TRAILING_BYTE  0x0200
#define COMMON_LVB_GRID_HORIZONTAL  0x0400
#define COMMON_LVB_GRID_LVERTICAL  0x0800
#define COMMON_LVB_GRID_RVERTICAL  0x1000
#define COMMON_LVB_REVERSE_VIDEO  0x4000
#define COMMON_LVB_UNDERSCORE  0x8000
#define COMMON_LVB_SBCSDBCS  0x0300

#define CTRL_C_EVENT  0
#define CTRL_BREAK_EVENT  1
#define CTRL_CLOSE_EVENT  2
#define CTRL_LOGOFF_EVENT  5
#define CTRL_SHUTDOWN_EVENT  6

#define ENABLE_PROCESSED_INPUT  0x0001
#define ENABLE_LINE_INPUT  0x0002
#define ENABLE_ECHO_INPUT  0x0004
#define ENABLE_WINDOW_INPUT  0x0008
#define ENABLE_MOUSE_INPUT  0x0010

#define ENABLE_PROCESSED_OUTPUT  0x0001
#define ENABLE_WRAP_AT_EOL_OUTPUT  0x0002

#define CONSOLE_TEXTMODE_BUFFER  1

#define CONSOLE_FULLSCREEN  1
#define CONSOLE_FULLSCREEN_HARDWARE  2

#define CONSOLE_NO_SELECTION  0x0000
#define CONSOLE_SELECTION_IN_PROGRESS  0x0001
#define CONSOLE_SELECTION_NOT_EMPTY  0x0002
#define CONSOLE_MOUSE_SELECTION  0x0004
#define CONSOLE_MOUSE_DOWN  0x0008

COORD STRUCT
	X SHORT
	Y SHORT
ENDS

SMALL_RECT STRUCT
	Left SHORT
	Top SHORT
	Right SHORT
	Bottom SHORT
ENDS

KEY_EVENT_RECORD STRUCT
	bKeyDown DD
	wRepeatCount DW
	wVirtualKeyCode DW
	wVirtualScanCode DW
    UNION
		UnicodeChar DW
		AsciiChar DB
	ENDUNION
	dwControlKeyState DD
ENDS

MOUSE_EVENT_RECORD STRUCT
	dwMousePosition COORD
	dwButtonState DD
	dwControlKeyState DD
	dwEventFlags DD
ENDS

WINDOW_BUFFER_SIZE_RECORD STRUCT
	dwSize COORD
ENDS

MENU_EVENT_RECORD STRUCT
	dwCommandId DD
ENDS

FOCUS_EVENT_RECORD STRUCT
	bSetFocus DD
ENDS

INPUT_RECORD STRUCT
	EventType DW
    UNION
		KeyEvent KEY_EVENT_RECORD
		MouseEvent MOUSE_EVENT_RECORD
		WindowBufferSizeEvent WINDOW_BUFFER_SIZE_RECORD
		MenuEvent MENU_EVENT_RECORD
		FocusEvent FOCUS_EVENT_RECORD
    ENDUNION
ENDS

CHAR_INFO STRUCT
    UNION
		UnicodeChar DW
		AsciiChar DB
    ENDUNION
	Attributes DW
ENDS

CONSOLE_SCREEN_BUFFER_INFO STRUCT
	dwSize COORD
	dwCursorPosition COORD
	wAttributes DW
	srWindow SMALL_RECT
	dwMaximumWindowSize COORD
ENDS

CONSOLE_CURSOR_INFO STRUCT
	dwSize DD
	bVisible DD
ENDS

CONSOLE_FONT_INFO STRUCT
	nFont DD
	dwFontSize COORD
ENDS

CONSOLE_SELECTION_INFO STRUCT
	dwFlags DD
	dwSelectionAnchor COORD
	srSelection SMALL_RECT
ENDS

#IFDEF UNICODE
	#define PeekConsoleInput PeekConsoleInputW
	#define ReadConsoleInput ReadConsoleInputW
	#define WriteConsoleInput WriteConsoleInputW
	#define ReadConsoleOutput ReadConsoleOutputW
	#define WriteConsoleOutput WriteConsoleOutputW
	#define ReadConsoleOutputCharacter ReadConsoleOutputCharacterW
	#define WriteConsoleOutputCharacter WriteConsoleOutputCharacterW
	#define FillConsoleOutputCharacter FillConsoleOutputCharacterW
	#define ScrollConsoleScreenBuffer ScrollConsoleScreenBufferW
	#define GetConsoleTitle GetConsoleTitleW
	#define SetConsoleTitle SetConsoleTitleW
	#define ReadConsole ReadConsoleW
	#define WriteConsole WriteConsoleW
#else
	#define PeekConsoleInput PeekConsoleInputA
	#define ReadConsoleInput ReadConsoleInputA
	#define WriteConsoleInput WriteConsoleInputA
	#define ReadConsoleOutput ReadConsoleOutputA
	#define WriteConsoleOutput WriteConsoleOutputA
	#define ReadConsoleOutputCharacter ReadConsoleOutputCharacterA
	#define WriteConsoleOutputCharacter WriteConsoleOutputCharacterA
	#define FillConsoleOutputCharacter FillConsoleOutputCharacterA
	#define ScrollConsoleScreenBuffer ScrollConsoleScreenBufferA
	#define GetConsoleTitle GetConsoleTitleA
	#define SetConsoleTitle SetConsoleTitleA
	#define ReadConsole ReadConsoleA
	#define WriteConsole WriteConsoleA
#endif /* UNICODE */

#endif /* WINCON_H */
