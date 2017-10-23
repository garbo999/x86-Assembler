.Const

WM_TRAYMESSAGE	Equ				WM_USER + 2048


.Data

szBuffer		DB				50 Dup 0

MESSAGES		DD				WM_CREATE, OnCreate
				DD				WM_COMMAND, OnCommand
				DD				WM_TIMER, OnTimer
				DD				WM_TRAYMESSAGE, OnTrayMessage
				DD				WM_CLOSE, OnClose
				DD				WM_DESTROY, OnDestroy

dwInsertAfter	DD				HWND_TOPMOST
hIcon			DD				NULL
hMenu			DD				NULL
hSubMenu		DD				NULL
MEMSTATUS		MEMORYSTATUS	<>
MEMSTATUSEX		MEMORYSTATUSEX	<>
nID				NOTIFYICONDATA	<?>


.Code

MemoryProcedure Frame hWnd, uMsg, wParam, lParam
	Mov Eax, [uMsg]
	Mov Ecx, SizeOf MESSAGES / 8
	Mov Edx, Addr MESSAGES
:	Dec Ecx
	Js >L2
	Cmp [Edx + Ecx * 8], Eax
	Jne <
	Call [Edx + Ecx * 8 + 4]
	Ret

L2:
	Xor Eax, Eax
	Ret
EndF

OnCreate:
	UseData MemoryProcedure
	;Loads icon for task bar and stores it in 'hIcon' variable
	Invoke LoadIcon, [App.Instance], IDI_MEMORY
	Mov [hIcon], Eax
	;Loads menu for icon in task bar and stores it in 'hMenu' variable
	Invoke LoadMenu, [App.Instance], IDR_MENU
	Mov [hMenu], Eax
	Invoke GetSubMenu, Eax, 0
	Mov [hSubMenu], Eax
	;Fills the members for NOTIFYICONDATA structure to set an icon in task bar
    Mov D[nID.cbSize], SizeOf nID
    Mov D[nID.uCallbackMessage], WM_TRAYMESSAGE
    Mov Eax, [hWnd]
    Mov [nID.hWnd], Eax
    Mov D[nID.uFlags], NIF_ICON | NIF_TIP Or NIF_MESSAGE
	Mov D[nID.uID], 1
	;Loads the string for tool tip text in the 'nID.szTip' member of the structure
	Invoke LoadString, [App.Instance], IDS_TOOLTIP, Addr nID.szTip, 63
	Mov Eax, [hIcon]
	Mov [nID.hIcon], Eax
	Invoke Shell_NotifyIcon, NIM_ADD, Addr nID
	Mov Eax, TRUE
	Ret
EndU

OnCommand:
	UseData MemoryProcedure
	Mov Eax, [wParam]
	Cmp Ax, IDM_MENU_OPEN
	Jne >wmc2
	;Disables the 'Open' menu option
	Invoke EnableMenuItem, [hSubMenu], IDM_MENU_OPEN, MF_BYCOMMAND Or MF_GRAYED
	;Makes the Main window visible
	Invoke SetVisible, [hWnd], TRUE
	;Sets the Main window according to 'dwInsertAfter' flag
	Invoke SetWindowPos, [hWnd], [dwInsertAfter], 0, 0, 0, 0, SWP_NOMOVE Or SWP_NOSIZE
	;Gets the handle for 'btnClose' object
	Invoke GetWindowItem, [hWnd], IDC_MEMORY_BTNCLOSE
	;Sets the focus to 'btnClose' object
	Invoke SetFocus, Eax
	;Returns TRUE for no further processing
	Mov Eax, TRUE
	Ret

wmc2:
	Cmp Ax, IDM_MENU_ABOUT
	Jne >wmc4
	;Hides the Main window
	Invoke SetVisible, [hWnd], FALSE
	;Sets the Main window according to 'dwInsertAfter' flag
	Invoke SetWindowPos, [hWnd], HWND_NOTOPMOST, 0, 0, 0, 0, SWP_NOMOVE Or SWP_NOSIZE Or SWP_HIDEWINDOW
	;Disables the 'Open' and 'About' menu options
	Invoke EnableMenuItem, [hSubMenu], IDM_MENU_OPEN, MF_BYCOMMAND Or MF_GRAYED
	Invoke EnableMenuItem, [hSubMenu], IDM_MENU_ABOUT, MF_BYCOMMAND Or MF_GRAYED
	;Creates and displays the About window
	Invoke Create, "MAbout", [hWnd], ecModal, [dwInsertAfter]
	;Enables the 'Open' and 'About' menu options
	Invoke EnableMenuItem, [hSubMenu], IDM_MENU_OPEN, MF_BYCOMMAND Or MF_ENABLED
	Invoke EnableMenuItem, [hSubMenu], IDM_MENU_ABOUT, MF_BYCOMMAND Or MF_ENABLED
	;Returns TRUE for no further processing
	Mov Eax, TRUE
	Ret

wmc4:
	Cmp Ax, IDM_MENU_EXIT
	Jne >wmc6
	;Closes and destroys the main window
	Invoke SendMessage, [hWnd], WM_CLOSE, 0, 0
	;Returns TRUE for no further processing
	Mov Eax, TRUE
	Ret

wmc6:
	Cmp Ax, IDC_MEMORY_BTNCLOSE
	Jne >wmc8
	Shr Eax, 16
	Cmp Ax, BN_CLICKED
	Jne >>L2
	;Hides the Main window
	Invoke SetVisible, [hWnd], FALSE
	;Sets the Main Window to 'no top most'
	Invoke SetWindowPos, [hWnd], HWND_NOTOPMOST, 0, 0, 0, 0, SWP_NOMOVE Or SWP_NOSIZE Or SWP_HIDEWINDOW
	;Enables the 'Open' menu option
	Invoke EnableMenuItem, [hSubMenu], IDM_MENU_OPEN, MF_BYCOMMAND Or MF_ENABLED
	;Returns TRUE for no further processing
	Mov Eax, TRUE
	Ret

wmc8:
	Cmp Ax, IDC_MEMORY_CHKONTOP
	Jne >L2
	Shr Eax, 16
	Cmp Ax, BN_CLICKED
	Jne >L2
	;Gets the handle for 'chkOnTop' object
	Invoke GetWindowItem, [hWnd], IDC_MEMORY_CHKONTOP
	;Gets the value for 'chkOnTop' object (checked/unchecked)
	Invoke GetValue, Eax
	Or Eax, Eax
	Jz >wmc10
	;Check box is checked
	Mov D[dwInsertAfter], HWND_TOPMOST
	Jmp >wmc12
wmc10:
	;Check box is unchecked
	Mov D[dwInsertAfter], HWND_NOTOPMOST
wmc12:
	;Sets the Main window to the new state
	Invoke SetWindowPos, [hWnd], [dwInsertAfter], 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE
	;Returns TRUE for no further processing
	Mov Eax, TRUE
	Ret

L2:
	Xor Eax, Eax
	Ret
EndU

OnTimer:
	UseData MemoryProcedure

	Mov D[MEMSTATUS.dwLength], SizeOf MEMORYSTATUS
	;Gets memory status in MEMORYSTATUS structure
	Invoke GlobalMemoryStatus, Addr MEMSTATUS
	Cmp D[MEMSTATUS.dwTotalPageFile], (-1)
	Je >
	;Converts MEMSTATUS.dwTotalPhys to string
	Invoke String, [MEMSTATUS.dwTotalPhys], Addr szBuffer, ecDecimal
	;Gets the handle for 'stcTotal' object
	Invoke GetWindowItem, [hWnd], IDC_MEMORY_STCTOTAL
	;Sets the text in 'stcTotal' object
	Invoke SetText, Eax, Addr szBuffer
	;Converts MEMSTATUS.dwTotalPhys to string
	Invoke String, [MEMSTATUS.dwAvailPhys], Addr szBuffer, ecDecimal
	;Gets the handle for 'stcAvailable' object
	Invoke GetWindowItem, [hWnd], IDC_MEMORY_STCAVAILABLE
	;Sets the text in 'stcAvailable' object
	Invoke SetText, Eax, Addr szBuffer
	;Returns TRUE for no further processing
L2:	Mov Eax, TRUE
	Ret
:	Mov D[MEMSTATUSEX.dwLength], SizeOf MEMORYSTATUSEX
	Invoke GlobalMemoryStatusEx, Addr MEMSTATUSEX
	;Converts MEMSTATUSEX.ullTotalPhys to string
	Invoke wsprintf, Addr szBuffer, TEXT("%lu"), [MEMSTATUSEX.ullTotalPhys]
	Add Esp, 12
	;Gets the handle for 'stcTotal' object
	Invoke GetWindowItem, [hWnd], IDC_MEMORY_STCTOTAL
	;Sets the text in 'stcTotal' object
	Invoke SetText, Eax, Addr szBuffer
	;Converts MEMSTATUSEX.dwAvailPhys to string
	Invoke wsprintf, Addr szBuffer, TEXT("%lu"), [MEMSTATUSEX.ullAvailPhys]
	Add Esp, 12
	;Gets the handle for 'stcAvailable' object
	Invoke GetWindowItem, [hWnd], IDC_MEMORY_STCAVAILABLE
	;Sets the text in 'stcAvailable' object
	Invoke SetText, Eax, Addr szBuffer
	;Returns TRUE for no further processing
	Jmp L2
EndU

OnTrayMessage:
	UseData MemoryProcedure
	Local pt:POINTL

	;Processes messages related to icon in the task bar
    Cmp D[lParam], WM_RBUTTONUP
    Jne >
	;Gets cursor coordinates
	Invoke GetCursorPos, Addr pt
	;Displays the menu in the right position
	Invoke TrackPopupMenu, [hSubMenu], 0, [pt.x], [pt.y], 0, [hWnd], NULL
	;Returns TRUE for no further processing
	Mov Eax, TRUE
	Ret
:	Cmp D[lParam], WM_LBUTTONDOWN
	Je >
	Cmp D[lParam], WM_RBUTTONDOWN
	Jne > L2
:	Invoke SetForegroundWindow, [hWnd]

L2:	Xor Eax, Eax
    Ret
EndU

OnClose:
	UseData MemoryProcedure
	;=====================================================;
	; It's not a Modal window, so we can remove this code ;
	;=====================================================;
;	Invoke IsModal, [hWnd]
;	Or Eax, Eax
;	Jz >
;	Invoke EndModal, [hWnd], IDCANCEL
;	Mov Eax, TRUE
;	Ret
;:	;Hides the Main window and sets it in a 'No top most'state
	Invoke SetWindowPos, [hWnd], HWND_NOTOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_HIDEWINDOW
	Xor Eax, Eax
	Ret
EndU

OnDestroy:
	UseData MemoryProcedure
	;Removes the icon from task bar
	Invoke Shell_NotifyIcon, NIM_DELETE, Addr nID
	;Destroys the icon
	Invoke DestroyIcon, [hIcon]
	;Destroys the menu
	Invoke DestroyMenu, [hMenu]
	Xor Eax, Eax
	Ret
EndU
