;coded in BiH, 387

;this application is written for my dad :)
;actual, i started to use it a lot lately :D
;as you may see, it is coded in assembly, and it will not work (al least properly) on os less than windows 2000 (so msdn says) because of SetLayeredWindowAttributes(x,x,x,x)
;since it is coded in EasyCode and i am very gratefull to Ramon Sala for this application, i decided to publish its ecSrcCode.
;i used ExitWindowsEx part of code from Reboot application example added in EasyCode.
;with this little code, app is very fancy :D hehehehe
;application is written and tested on Windows Vista sp1, not sure it may not work on any other platiforms.
;my aproach to coding is bit different than Ramon's, i like to have everything in variables and like to type less, so, lots of variables are very short and similar.
;allso, i used my way to hide window from taskbar, i hope you will not mind.
;this source is free and you may modify it under any conditions.
;you are using application and source at own risk. (it works fine with me) :D

;for any comment feel free to contact me:
;wook@symbian-freak.com
;yours
;wook

.Const
WM_TRAY Equ WM_USER + 2048 ;stolen from Memory app
inv Equ Invoke ;because i am lazy to type, and i dont like that api popups that much, i use inv for functions i know verry well, and for functions i dont, there is invoke ;)


.Data

W_MESSAGES	DD WM_CREATE, OnmnCreate
			DD WM_COMMAND, OnmnCommand
			DD WM_LBUTTONDOWN, OnmnLButtonDown
			DD WM_TIMER, OnmnTimer
			DD WM_TRAY, OnmnTray
			DD WM_CLOSE, OnmnClose

dwnb		DD ? ;shutdown button handler
rbtb		DD ? ;reboot button handler
run			DD ? ;run button handler
smpl		DD ? ;sample text ("type here...")
runb		DD ? ;run box
buff		DB 256 Dup ? ;buffer
mv			DD ? ;move handler
sb			DD ? ;switch to background handler
xb			DD ? ;close handler
iconh		DD ? ;icon handler
mnu			DD ? ;menu handler
thgh		DD ? ;taskbar height
hb			DD ?
ib			DD ?

nID			NOTIFYICONDATA <0> ;another handler
errmsg		DB 'invalid application/command!', 0 ;text for messagebox when user misstype app/command name
cpyr		DB 'copyright 2010, stwoowerks, wook', 13, 10, 'wook'
hdn2		DD 1 ;are "buttons" hidden or shown


.Code

mnProcedure Frame hWnd, uMsg, wParam, lParam
	Local handle:D
	Local tp:TOKEN_PRIVILEGES
	Local rct:RECT
	Local pt:POINT

	Mov Eax, [uMsg]
	Mov Ecx, SizeOf W_MESSAGES / 8
	Mov Edx, Addr W_MESSAGES
:	Dec Ecx
	Js > L2
	Cmp [Edx + Ecx * 8], Eax
	Jne <
	Call [Edx + Ecx * 8 + 4]
	Ret
L2:	Xor Eax, Eax	;Return (FALSE)
	Ret
EndF

OnmnCreate:
	UseData mnProcedure

    Mov D[nID.cbSize], SizeOf nID ;stolen from Memory app; constructing notifyicondata structure
    Mov D[nID.uCallbackMessage], WM_TRAY ;numeric identificator for uMsh we will maybe recive from Tray
    Mov Eax, [hWnd] ;this and below is same as m2m nID.hWnd,hWnd, it copys handler of our window to nID.hwnd
    Mov [nID.hWnd], Eax
    Mov D[nID.uFlags], NIF_ICON | NIF_TIP | NIF_MESSAGE ;flags may be used in Tray
	Mov D[nID.uID], 1 ;identifier of taskbar icon
	inv LoadIcon, [App.Instance], IDI_ICO ;icon to its handler handler
	Mov [iconh], Eax
	Mov [nID.hIcon], Eax ;eax to nID,hIcon
	inv LoadString, [App.Instance], IDT_TTL, Addr nID.szTip, 40 ;this is for tooltips of Tray, it is application title, but it can be anything you want
	inv Shell_NotifyIcon, NIM_ADD, Addr nID ;this function adds icon of our window to shell

	inv LoadMenu, [App.Instance], IDR_MENU ;menu resource loaded
	inv GetSubMenu, Eax, 0 ;got submenu of menu
	Mov [mnu], Eax ;store it to handler
	inv SetCurrentDirectory, TEXT("C:\") ;se current directory to c:\, i like to start with c: so i took it as currentdir
	inv SetParent, [hWnd], 0 ;now i will set parent of this window to none
	inv GetDlgItem, [hWnd], IDC_MN_DWN ;controls to its handlers
	Mov [dwnb], Eax
	inv GetDlgItem, [hWnd], IDC_MN_RBT
	Mov [rbtb], Eax
	inv GetDlgItem, [hWnd], IDC_MN_RUN
	Mov [runb], Eax
	inv GetDlgItem, [hWnd], IDC_MN_RB
	Mov [run], Eax
	inv GetDlgItem, [hWnd], IDC_MN_TXT1
	Mov [smpl], Eax
	inv GetDlgItem, [hWnd], IDC_MN_MV
	Mov [mv], Eax
	inv GetDlgItem, [hWnd], IDC_MN_SB
	Mov [sb], Eax
	inv GetDlgItem, [hWnd], IDC_MN_XB
	Mov [xb], Eax
	inv GetDlgItem, [hWnd], IDC_MN_HLP
	Mov [hb], Eax
	inv GetDlgItem, [hWnd], IDC_MN_NFO
	Mov [ib], Eax
	inv FindWindow, TEXT("Shell_TrayWnd"), 0 ;get taskbar window handle to eax
	Mov Ebx, Eax ;copy eax to ebx to fix compiling error "Register value overwritten by invoke" (i would like to get more info on this issue), it is allways with GetWindowRect function
	inv GetWindowRect, Ebx, Addr rct ;get taskbar window rect
	Mov Eax, [rct.bottom] ;move rect.top to eax
	Sub Eax, [rct.top] ;substract rect.top from rect.bottom
	Mov [thgh], Eax ;save taskbar height to handler
	inv GetSystemMetrics, SM_CXSCREEN ;get screen widith
	Sub Eax, 180 ;substract from screen widith application widith
	Mov Ebx, Eax ;save it to ebx because we will need it later ;)
	inv GetSystemMetrics, SM_CYSCREEN ;do same with height, it will stay in eax because in next line we will call function and add those parameters. when you are using registers, you must be aware, some functions returns value in eax, some use ebx... and some need buffer or structure to return all informations we need
	Sub Eax, 222 ;substracting height of app from screen's height
	Sub Eax, [thgh] ;32 ;substract taskbar height from rest of screens height
	inv MoveWindow, [hWnd], Ebx, Eax, 180, 222, 1 ;set size and position of our window
	inv GetPlatform, NULL ;get os versa, for more help on this function press F1
	Cmp Eax, ecWin2K
	Jl >> L2
	inv LoadImage, [App.Instance], IDI_CLOSE, IMAGE_BITMAP, 0, 0, LR_DEFAULTSIZE ;load image with default size
	inv SetPicture, [xb], Eax ;set picture to "button"
	inv LoadImage, [App.Instance], IDI_SBG, IMAGE_BITMAP, 0, 0, LR_DEFAULTSIZE
	inv SetPicture, [sb], Eax
	inv LoadImage, [App.Instance], IDI_MOVE, IMAGE_BITMAP, 0, 0, LR_DEFAULTSIZE
	inv SetPicture, [mv], Eax
	inv LoadImage, [App.Instance], IDI_HLP, IMAGE_BITMAP, 0, 0, LR_DEFAULTSIZE
	inv SetPicture, [hb], Eax
	inv LoadImage, [App.Instance], IDI_NFO, IMAGE_BITMAP, 0, 0, LR_DEFAULTSIZE
	inv SetPicture, [ib], Eax
	inv GetWindowLong, [hWnd], GWL_EXSTYLE ;get our window exstyle
	Add Eax, WS_EX_LAYERED ;add to it ws_ex_layered
	inv SetWindowLong, [hWnd], GWL_EXSTYLE, Eax ;and set new long to our window
	inv SetLayeredWindowAttributes, [hWnd], 0FF00FFH, 0, 1 ;this function attributes are not in windows.h/.inc so instead of LWA_COLORKEY==1 and LWA_ALPHA==2 or both i used integer, so here i set LWA_COLORKEY as attribute to make FF00FFH color transparent
	Jmp >> L4
L2:	inv SetBackColor, [hWnd], 080000001H ;set background color to dc in eax
	inv SetBackColor, [dwnb], 080000001H
	inv SetBackColor, [rbtb], 080000001H
	inv SetBackColor, [runb], 080000001H
	inv SetBackColor, [run], 080000001H
	inv SetBackColor, [smpl], 080000001H
	inv SetBackColor, [mv], 080000001H
	inv SetBackColor, [sb], 080000001H
	inv SetBackColor, [xb], 080000001H
	inv SetBackColor, [hb], 080000001H
	inv SetBackColor, [ib], 080000001H
	inv LoadImage, [App.Instance], IDI_CLOSEI, IMAGE_ICON, 24, 24, LR_LOADTRANSPARENT ;load icon with 24x24 size
	inv SetPicture, [xb], Eax ;set icon to "button"
	inv LoadImage, [App.Instance], IDI_SBGI, IMAGE_ICON, 24, 24, LR_LOADTRANSPARENT
	inv SetPicture, [sb], Eax
	inv LoadImage, [App.Instance], IDI_MOVEI, IMAGE_ICON, 24, 24, LR_LOADTRANSPARENT
	inv SetPicture, [mv], Eax
	inv LoadImage, [App.Instance], IDI_HLPI, IMAGE_ICON, 24, 24, LR_LOADTRANSPARENT
	inv SetPicture, [hb], Eax
	inv LoadImage, [App.Instance], IDI_NFOI, IMAGE_ICON, 24, 24, LR_LOADTRANSPARENT
	inv SetPicture, [ib], Eax
L4:	inv GetRegistryValue, ecCurrentUser, TEXT("SOFTWARE\Microsoft\Windows\CurrentVersion\run"), TEXT("powermgr"), Addr buff ;i used this to check is there startup entry of this app
	Mov Ecx, 8 ;check menu item
	Or Eax, Eax
	Jnz >
	Xor Ecx, Ecx ;uncheck menu item
:	inv CheckMenuItem, [mnu], IDM_AS, Ecx
	inv SetTimer, [hWnd], 0, 0, 0 ;create timer for constant execution as i like to call it
	Xor Eax, Eax	;Return (FALSE)
	Ret
EndU

OnmnCommand:
	UseData mnProcedure

	HiWord ([wParam]) ;i store hiword of wparam to bx automaticly on start of wm_command block
	Mov Bx, Ax
	LoWord ([wParam]) ;copy loword of wparam to ax (copy wparam to eax)
	Cmp Ax, IDC_MN_DWN
	Jne > L2
	Or Bx, Bx
	Jnz > L2
	inv GetPlatform, NULL
	Cmp Eax, ecWin95
	Je >
	Cmp Eax, ecWin98
	Je >
	;seems like on win95-98 app need to have privilegs to terminate windows, so that provilegs will be adjusted in code below
	inv GetCurrentProcess ;get current process handle
	Mov Edx, Eax ;store current process handle to edx
	inv OpenProcessToken, Edx, TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, Addr handle ;open process privilegs and store them to handle struct
	inv LookupPrivilegeValue, NULL, TEXT("SeShutdownPrivilege"), Addr tp.Privileges.Luid ; get value of shutdown privilegs and store it to token_privilegs struct; you will find problems here with ec auto correction
	Mov D[tp.PrivilegeCount], 1 ;adjusting t_p
	Mov D[tp.Privileges.Attributes], SE_PRIVILEGE_ENABLED ;set privilegs to enabled
	inv AdjustTokenPrivileges, [handle], FALSE, Addr tp, SizeOf tp, NULL, NULL ;apply t_p and handle struct infos to process privilegs, now we should call "inv clode handle,edx", but after window terminate we dont need to do anything like :D
:	inv ExitWindowsEx, EWX_SHUTDOWN, 0 ;send message to system process to terminate it self :D
	inv SendMessage, [hWnd], WM_CLOSE, 0, 0 ;terminate application; in Reboot example those two lines are replaced by each other, it is because in Reboot app, after wm_close app is still running, and here it dont.
	Jmp LEnd
L2:	Cmp Ax, IDC_MN_RBT
	Jne > L4
	Or Bx, Bx
	Jnz > L4
	;here we check if loword of wparam had same id as control idc_mn_rbt and if hiword of wparam is 0 (bn_clicked)
	inv GetPlatform, NULL
	Cmp Eax, ecWin95
	Je >
	Cmp Eax, ecWin98
	Je >
	inv GetCurrentProcess
	Mov Edx, Eax
	inv OpenProcessToken, Edx, TOKEN_ADJUST_PRIVILEGES Or TOKEN_QUERY, Addr handle
	inv LookupPrivilegeValue, NULL, TEXT("SeShutdownPrivilege"), Addr tp.Privileges.Luid
	Mov D[tp.PrivilegeCount], 1
	Mov D[tp.Privileges.Attributes], SE_PRIVILEGE_ENABLED
	inv AdjustTokenPrivileges, [handle], FALSE, Addr tp, SizeOf tp, NULL, NULL
:	inv ExitWindowsEx, EWX_REBOOT, 0 ;reboots system
	inv SendMessage, [hWnd], WM_CLOSE, 0, 0
	Jmp LEnd
L4:	Cmp Ax, IDC_MN_LO
	Jne > L6
	Or Bx, Bx
	Jnz > L6
	;here we check if loword of wparam had same id as control idc_mn_rbt and if hiword of wparam is 0 (bn_clicked)
	inv GetPlatform, NULL
	Cmp Eax, ecWin95
	Je >
	Cmp Eax, ecWin98
	Je >
	inv GetCurrentProcess
	Mov Edx, Eax
	inv OpenProcessToken, Edx, TOKEN_ADJUST_PRIVILEGES Or TOKEN_QUERY, Addr handle
	inv LookupPrivilegeValue, NULL, TEXT("SeShutdownPrivilege"), Addr tp.Privileges.Luid
	Mov D[tp.PrivilegeCount], 1
	Mov D[tp.Privileges.Attributes], SE_PRIVILEGE_ENABLED
	inv AdjustTokenPrivileges, [handle], FALSE, Addr tp, SizeOf tp, NULL, NULL
:	inv ExitWindowsEx, EWX_LOGOFF, 0 ;logs off user
	inv SendMessage, [hWnd], WM_CLOSE, 0, 0
	Jmp LEnd
L6:	Cmp Ax, IDC_MN_RB
	Jne >> L8
	Or Bx, Bx
	Jnz >> L8
	inv RtlZeroMemory, Addr buff, SizeOf buff ;empty buffer
	inv GetText, [runb], Addr buff ;get run box text to buff
	inv lstrcmp, Addr buff, TEXT("exit") ;compare buff with "exit" and if difference is == 0:
	Or Eax, Eax
	Jnz >
	inv SendMessage, [hWnd], WM_CLOSE, 0, 0 ;terminate app
	Return (TRUE) ;return
:	inv lstrcmp, Addr buff, TEXT("help")
	Or Eax, Eax
	Jnz >
	inv SendMessage, [hWnd], WM_COMMAND, IDM_HLP, 0 ;execute sendmessage with proper parameters
	inv SetWindowText, [runb], 0
	Ret
:	inv lstrcmp, Addr buff, TEXT("about")
	Or Eax, Eax
	Jnz >
	inv SendMessage, [hWnd], WM_COMMAND, IDM_ABT, 0
	inv SetWindowText, [runb], 0
	Ret
:	inv lstrcmp, Addr buff, TEXT("info")
	Or Eax, Eax
	Jnz >
	inv SendMessage, [hWnd], WM_COMMAND, IDM_ABT, 0
	inv SetWindowText, [runb], 0
	Ret
:	inv WinExec, Addr buff, SW_SHOWDEFAULT ;this will execute *.exe file, and will return result in eax, if ok >32
	Mov Ebx, Eax ;i dont know why have i added this :D
	Cmp Ebx, 32
	Jg >
	inv ShellExecute, 0, TEXT("open"), Addr buff, 0, 0, SW_SHOWDEFAULT ;this will open *.* file with its default application
	Cmp Eax, 32
	Jg >
	inv MessageBox, [hWnd], Addr errmsg, 0, 10H ;error message
:	inv SetWindowText, [runb], 0 ;clears txt in edit control
	Jmp LEnd
L8:	Cmp Ax, IDC_MN_SB
	Jne >
	Or Bx, Bx
	Jnz >
	inv SetWindowPos, [hWnd], HWND_BOTTOM, 0, 0, 0, 0, SWP_NOMOVE + SWP_NOSIZE
	Jmp LEnd
:	Cmp Ax, IDC_MN_XB
	Jne >
	Or Bx, Bx
	Jnz >
	inv SendMessage, [hWnd], WM_CLOSE, 0, 0
	Jmp LEnd
:	Cmp Ax, IDM_SHOW ;processing menu commands
	Jne >
	inv SetFocus, [hWnd] ;i dont know why any of those two "bring window to top" functions dont work
;	inv SetWindowPos, [hWnd], HWND_TOP, 0, 0, 0, 0, SWP_NOMOVE + SWP_NOSIZE ;bring window to front???
	Jmp LEnd
:	Cmp Ax, IDM_AS
	Jne >> L10
	inv GetRegistryValue, ecCurrentUser, TEXT("SOFTWARE\Microsoft\Windows\CurrentVersion\run"), TEXT("powermgr"), Addr buff ;get value from registry and save it to buff
	Or Eax, Eax
	Jz >
	inv DeleteRegistryValue, ecCurrentUser, TEXT("SOFTWARE\Microsoft\Windows\CurrentVersion\run"), TEXT("powermgr") ;remove value
	inv CheckMenuItem, [mnu], IDM_AS, 0 ;remove checkmark from menu (MF_BYPOSITION + MF_UNCHECKED)
	Jmp > LEnd
:  	inv GetModuleFileName, 0, Addr buff, SizeOf buff ;get this application filename and save it to buffer
	inv SetRegistryValue, ecCurrentUser, TEXT("SOFTWARE\Microsoft\Windows\CurrentVersion\run"), TEXT("powermgr"), Addr buff ;save filename to startup entry
	inv CheckMenuItem, [mnu], IDM_AS, 8 ;set checkmark to menu item (MF_BYPOSITION + MF_CHECKED)
	Jmp > LEnd
L10:
	Or Bx, Bx
	Jnz > L12
	Cmp Ax, IDM_HLP
	Je >
	Cmp Ax, IDC_MN_HLP
	Jne > L12
	;processing help
:  	inv GetModuleFileName, 0, Addr buff, SizeOf buff ;get this application filename and save it to buffer
   	inv GetPathOnly, Addr buff, Addr buff ;remove filename from application path
   	inv lstrcat, Addr buff, TEXT("help.txt") ;add to path "help.txt
	inv ShellExecute, [hWnd], TEXT("open"), Addr buff, 0, 0, SW_SHOWDEFAULT ;open help.txt in root path of application
;	inv MessageBox, [hWnd], TEXT("help is not implemented yet"), 0, 30H
	Jmp LEnd
L12:
	Or Bx, Bx
	Jnz > L14
	Cmp Ax, IDM_ABT
	Je >
	Cmp Ax, IDC_MN_NFO
	Jne > L14
	;processing about
:	inv ShellAbout, [hWnd], TEXT("power manager"), Addr cpyr, IDI_ICO
;	Ret
	Jmp > LEnd
L14:
	Cmp Ax, IDM_EXIT ;exit command
	Jne > LEnd
	inv SendMessage, [hWnd], WM_CLOSE, 0, 0 ;exit message

LEnd:
	Return (TRUE)
EndU

OnmnLButtonDown:
	UseData mnProcedure

	inv SendMessage, [hWnd], WM_NCLBUTTONDOWN, HTCAPTION, 0 ;send message to window that left button is on caption bar and is down
	Xor Eax, Eax
	Ret
EndU

OnmnTimer:
	UseData mnProcedure

	inv GetCursorPos, Addr pt ;get cursor position and store its values to structure
	inv GetWindowRect, [hWnd], Addr rct ;get window rect
	inv PtInRect, Addr rct, [pt.x], [pt.y] ;check is cursor in that rect (is cursor over our window)
	Or Eax, Eax
	Jz > L2
	Cmp D[hdn2], 1
	Jne > L2
	Mov D[hdn2], 0 ;to avoid checking is some wnd visible or not i use my way, so i know that buttons will be shown and i will save to "are buttons hidden" 0 (they are visible)
	inv SetVisible, [mv], 1 ;make "buttons" visible
	inv SetVisible, [sb], 1
	inv SetVisible, [xb], 1
	inv SetVisible, [hb], 1
	inv SetVisible, [ib], 1
	Jmp > L4
L2:	Or Eax, Eax
	Jnz > L4
	Cmp D[hdn2], 0
	Jne > L4
	Mov D[hdn2], 1 ;mov 1 to "are buttons hidden"
	inv SetVisible, [mv], 0 ;make "buttons" hidden /it is not buttons, they are static controls with image style
	inv SetVisible, [sb], 0
	inv SetVisible, [xb], 0
	inv SetVisible, [hb], 0
	inv SetVisible, [ib], 0
L4:	inv SendMessage, [runb], WM_GETTEXTLENGTH, 0, 0 ;get length of text in run box
	Or Eax, Eax
	Jnz > L6
	inv HideCaret, [runb] ;hide caret
	inv ShowWindow, [smpl], 1 ;show "type here..."
	Jmp > L8
L6:	inv ShowCaret, [runb] ;show caret
	inv ShowWindow, [smpl], 0 ;hide "type here..."
L8:	Xor Eax, Eax	;Return (FALSE)
	Ret
EndU

OnmnTray:
	UseData mnProcedure

    Cmp D[lParam], WM_RBUTTONUP
    Jne >
	inv GetCursorPos, Addr pt ;get cursor
	inv TrackPopupMenu, [mnu], 0, [pt.x], [pt.y], 0, [hWnd], NULL ;show menu
	Return (TRUE)
:	Cmp D[lParam], WM_LBUTTONDBLCLK ;if we doubleclicked on icon in tray
	Jne >
	inv SetFocus, [hWnd] ;i dont know why any of those two "bring window to top" functions dont work
;	inv SetWindowPos, [hWnd], HWND_TOP, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE ;bring window to front???
;	Return (TRUE)
	Jmp > L2
:	Cmp D[lParam], WM_LBUTTONDOWN
	Je >
	Cmp D[lParam], WM_RBUTTONDOWN
	Jne > L2
:	Invoke SetForegroundWindow, [hWnd]
L2:	Xor Eax, Eax
	Ret
EndU

OnmnClose:
	UseData mnProcedure
	;=========================
	inv Shell_NotifyIcon, NIM_DELETE, Addr nID ;remove notify from tray
	inv DestroyIcon, [iconh] ;remove icon handler from ram
	inv DestroyMenu, [mnu] ;remove menu from ram
	;inv ExitProcess, 1 ;terminate application
	;=========================
	Invoke IsModal, [hWnd]
	Or Eax, Eax		;Cmp Eax, FALSE
	Jz >
	Invoke EndModal, [hWnd], IDCANCEL
	Mov Eax, TRUE	;Return (TRUE)
:	Ret
EndU

GetPathOnly Frame lpszSource, lpszDest
	Invoke FindCharRev, [lpszSource], '\'
	Cmp Eax, (-1)
	Je >
	Add Eax, [lpszSource]
	Mov B[Eax], 0
	Invoke lstrcpy, [lpszDest], [lpszSource]
:	Ret
EndF
