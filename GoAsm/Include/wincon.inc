;=============================================================;
;          wincon.inc file for Easy Code visual IDE           ;
;            (made for the GoAsm compiler version)            ;
;                                                             ;
;         Version 1.0.00 (created on February, 2007)          ;
;                                                             ;
;      Please report any bug you find (asm@easycode.cat)      ;
;                                                             ;
;                Do not modify this file!!                    ;
;=============================================================;

#IFNDEF WINCON_INC
#Define WINCON_INC

#Define RIGHT_ALT_PRESSED     			00001H
#Define LEFT_ALT_PRESSED      			00002H
#Define RIGHT_CTRL_PRESSED    			00004H
#Define LEFT_CTRL_PRESSED     			00008H
#Define SHIFT_PRESSED         			00010H
#Define NUMLOCK_ON            			00020H
#Define SCROLLLOCK_ON         			00040H
#Define CAPSLOCK_ON           			00080H
#Define ENHANCED_KEY          			00100H
#Define NLS_DBCSCHAR          			000010000H
#Define NLS_ALPHANUMERIC      			000000000H
#Define NLS_KATAKANA          			000020000H
#Define NLS_HIRAGANA          			000040000H
#Define NLS_ROMAN             			000400000H
#Define NLS_IME_CONVERSION    			000800000H
#Define NLS_IME_DISABLE       			020000000H


#Define FROM_LEFT_1ST_BUTTON_PRESSED    00001H
#Define RIGHTMOST_BUTTON_PRESSED        00002H
#Define FROM_LEFT_2ND_BUTTON_PRESSED    00004H
#Define FROM_LEFT_3RD_BUTTON_PRESSED    00008H
#Define FROM_LEFT_4TH_BUTTON_PRESSED    00010H

#Define MOUSE_MOVED   					00001H
#Define DOUBLE_CLICK  					00002H
#Define MOUSE_WHEELED 					00004H


#Define KEY_EVENT         				00001H
#Define MOUSE_EVENT       				00002H
#Define WINDOW_BUFFER_SIZE_EVENT		00004H
#Define MENU_EVENT 						00008H
#Define FOCUS_EVENT						00010H

#Define FOREGROUND_BLUE      			00001H
#Define FOREGROUND_GREEN     			00002H
#Define FOREGROUND_RED       			00004H
#Define FOREGROUND_INTENSITY 			00008H
#Define BACKGROUND_BLUE      			00010H
#Define BACKGROUND_GREEN     			00020H
#Define BACKGROUND_RED       			00040H
#Define BACKGROUND_INTENSITY 			00080H
#Define COMMON_LVB_LEADING_BYTE    		00100H
#Define COMMON_LVB_TRAILING_BYTE   		00200H
#Define COMMON_LVB_GRID_HORIZONTAL 		00400H
#Define COMMON_LVB_GRID_LVERTICAL  		00800H
#Define COMMON_LVB_GRID_RVERTICAL  		01000H
#Define COMMON_LVB_REVERSE_VIDEO   		04000H
#Define COMMON_LVB_UNDERSCORE      		08000H

#Define COMMON_LVB_SBCSDBCS        		00300H

#Define CTRL_C_EVENT        			0
#Define CTRL_BREAK_EVENT    			1
#Define CTRL_CLOSE_EVENT    			2
#Define CTRL_LOGOFF_EVENT   			5
#Define CTRL_SHUTDOWN_EVENT 			6

#Define ENABLE_PROCESSED_INPUT 			00001H
#Define ENABLE_LINE_INPUT      			00002H
#Define ENABLE_ECHO_INPUT      			00004H
#Define ENABLE_WINDOW_INPUT    			00008H
#Define ENABLE_MOUSE_INPUT     			00010H

#Define ENABLE_PROCESSED_OUTPUT    		00001H
#Define ENABLE_WRAP_AT_EOL_OUTPUT  		00002H

#Define CONSOLE_TEXTMODE_BUFFER  		1


COORD Struct
	X DW
	Y DW
EndS

SMALL_RECT Struct
	Left DW
	Top DW
	Right DW
	Bottom DW
EndS

KEY_EVENT_RECORD Struct
	bKeyDown DD
	wRepeatCount DW
	wVirtualKeyCode DW
	wVirtualScanCode DW
	Union ;uChar
		UnicodeChar DW
		AsciiChar DB
	EndUnion
	dwControlKeyState DD
EndS

MOUSE_EVENT_RECORD Struct
	dwMousePosition COORD <>
	dwButtonState DD
	dwControlKeyState DD
	dwEventFlags DD
EndS

WINDOW_BUFFER_SIZE_RECORD Struct
	dwSize COORD <>
EndS

MENU_EVENT_RECORD Struct
	dwCommandId DD
EndS

FOCUS_EVENT_RECORD Struct
	bSetFocus DD
EndS

INPUT_RECORD Struct
	EventType DW
	Union ;Event
		KeyEvent KEY_EVENT_RECORD <>
		MouseEvent MOUSE_EVENT_RECORD <>
		WindowBufferSizeEvent WINDOW_BUFFER_SIZE_RECORD<>
		MenuEvent MENU_EVENT_RECORD <>
		FocusEvent FOCUS_EVENT_RECORD <>
	EndUnion
EndS

CHAR_INFO Struct
	Union ;Char
		UnicodeChar DW
		AsciiChar DB
	EndUnion
	Attributes DW
EndS

CONSOLE_SCREEN_BUFFER_INFO Struct
	dwSize COORD <>
	dwCursorPosition COORD <>
	wAttributes DW
	srWindow SMALL_RECT <>
	dwMaximumWindowSize COORD <>
EndS

CONSOLE_CURSOR_INFO Struct
	dwSize DD
	bVisible DD
EndS

#IF STRINGS UNICODE
	#Define PeekConsoleInput PeekConsoleInputW
	#Define ReadConsoleInput ReadConsoleInputW
	#Define WriteConsoleInput WriteConsoleInputW
	#Define ReadConsoleOutput ReadConsoleOutputW
	#Define WriteConsoleOutput WriteConsoleOutputW
	#Define ReadConsoleOutputCharacter ReadConsoleOutputCharacterW
	#Define WriteConsoleOutputCharacter WriteConsoleOutputCharacterW
	#Define FillConsoleOutputCharacter FillConsoleOutputCharacterW
	#Define ScrollConsoleScreenBuffer ScrollConsoleScreenBufferW
	#Define GetConsoleTitle GetConsoleTitleW
	#Define SetConsoleTitle SetConsoleTitleW
	#Define ReadConsole ReadConsoleW
	#Define WriteConsole WriteConsoleW
#ELSE
	#Define PeekConsoleInput PeekConsoleInputA
	#Define ReadConsoleInput ReadConsoleInputA
	#Define WriteConsoleInput WriteConsoleInputA
	#Define ReadConsoleOutput ReadConsoleOutputA
	#Define WriteConsoleOutput WriteConsoleOutputA
	#Define ReadConsoleOutputCharacter ReadConsoleOutputCharacterA
	#Define WriteConsoleOutputCharacter WriteConsoleOutputCharacterA
	#Define FillConsoleOutputCharacter FillConsoleOutputCharacterA
	#Define ScrollConsoleScreenBuffer ScrollConsoleScreenBufferA
	#Define GetConsoleTitle GetConsoleTitleA
	#Define SetConsoleTitle SetConsoleTitleA
	#Define ReadConsole ReadConsoleA
	#Define WriteConsole WriteConsoleA
#ENDIF

#ENDIF ;WINCON_INC
