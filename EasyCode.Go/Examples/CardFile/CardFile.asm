;EasyCodeName=CardFile,1
;
;	GeneSys Opcode CardFile, 1.0.0
; ___________________________________________________
;|                                                   |
;| GeneSys Opcode CardFile, 1.0.0      Paul Brennick |
;| pebrennick@verizon.net   http://www.pbrennick.com |
;|___________________________________________________|
;|                                                   |
;| Version key:  GeneSys Opcode CardFile a.b.c       |
;|           a:  a major change to the GUI           |
;|           b:  functions added and/or changed      |
;|           c:  bug fixes                           |
;|                                                   |
;| Version History:                                  |
;| October 27, 2006   Major rewrite and first        |
;|                    release of the software        |
;|                    Version tracking starts        |
;|                    from this point, on.           |
;|                                                   |
;| Written by: Paul Brennick                         |
;| Email     : pebrennick@verizon.net                |
;| Page      : http://www.pbrennick.com/             |
;| Compiler  : Microsoft Macro Assembler v6.14.8444  |
;| Date      : 27-Oct-2006                           |
;| Purpose   : This Opcode CardFile Manager can be   |
;|           : used to examine various MASM Opcodes  |
;|           : and Mnemonics.                        |
;|                                     Editor's Note |
;|___________________________________________________|
;|                                                   |
;
.Data
;---------------------------------------
ClassName       DB  "DLGCLASS"
				DB	0
MenuName        DB  "MyMenu"
				DB	0
DlgName         DB  "MainDialog"
				DB	0
AbtName         DB  "AboutDialog"
				DB	0
num2            DB  "%lu"
				DB	0
hInstance       DD	?
buff            DB  256 Dup ?
menuhand        DD	?
ASCIIname       DB  "OpCodeDatabase.asc"
				DB	0
ASCIIdata       DB  "fld1"
                DB  "fld2"
                DB  "fld3"
                DB  "fld4"
                DB  "fld5"
szOpen          DB  "open"
				DB	0
szAppName       DB  "CardFile"
				DB	0
szNotFound      DB  ": File not found"
				DB	0

;
;---------------------------------------
hover           DD	    ?
hFinger         DD      ?
orgStatic       DD      ?
hwndDlg         DD      ?
filehand1       DD	    ?
memhand         DD	    ?
filesize        DD	    ?
mem             DD	    ?
sizeread        DD	    ?
temp            DD	    ?
memdata         DD	    ?
parts           DD	    ?
memmax          DD	    ?
index           DD	    ?
;
.Const
;---------------------------------------
IDC_NEXT        Equ     3000
IDC_PREV        Equ     3001
IDC_EXIT        Equ     3002
IDM_UPDATE      Equ     32000
IDM_EXIT        Equ     32003
IDM_ABOUT       Equ     32002
IDI_ICON1       Equ     5
IDC_URL         Equ     9
;
;
.Code
;---------------------------------------
start:  Invoke  GetModuleHandle, NULL
        Mov [hInstance], Eax
        Invoke  WinMain, [hInstance], NULL, NULL, SW_SHOWDEFAULT
        Invoke ExitProcess, Eax
;
;
WinMain Frame hInst, hPrevInst, CmdLine, CmdShow
;---------------------------------------
        Local wc:WNDCLASSEX
        Local msg:MSG
        Local hDlg:D
;
        Mov D[wc.cbSize], SizeOf WNDCLASSEX
        Mov D[wc.style], CS_HREDRAW Or CS_VREDRAW
        Mov D[wc.lpfnWndProc], Offset WndProc
        Mov D[wc.cbClsExtra], NULL
        Mov D[wc.cbWndExtra], DLGWINDOWEXTRA
        Push [hInst]
        Pop [wc.hInstance]
        Mov D[wc.hbrBackground], COLOR_BTNFACE + 1
        Mov [wc.lpszMenuName], Offset MenuName
        Mov [wc.lpszClassName], Offset ClassName
        Invoke  LoadIcon, [hInstance], IDI_ICON1
        Mov [wc.hIcon], Eax
        Mov [wc.hIconSm], Eax
        Invoke  LoadCursor, NULL, IDC_ARROW
        Mov [wc.hCursor], Eax
        Invoke RegisterClassEx, Addr wc
        Invoke CreateDialogParam, [hInstance], Addr DlgName, NULL, NULL, NULL
        Mov [hDlg], Eax
        Invoke  ShowWindow, [hDlg], SW_SHOWNORMAL
        Invoke  UpdateWindow, [hDlg]
:		Invoke GetMessage, Addr msg, NULL, 0, 0
		Or Eax, Eax
		Jz >
		Invoke IsDialogMessage, [hDlg], Addr msg
		Or Eax, Eax
		Jnz <
		Invoke  TranslateMessage, Addr msg
		Invoke  DispatchMessage, Addr msg
        Jmp <
:       Mov Eax, [msg.wParam]
        Ret
;---------------------------------------
EndF
;
;
WndProc Frame hWnd, uMsg, wParam, lParam Uses Ebx, Esi
;---------------------------------------
        Mov Eax, [uMsg]
        Cmp Eax, WM_GETMINMAXINFO        ; 24
        Jne > L2
;;       cmp     first, FALSE
;;       jne     nob1
        Invoke  GetMenu, [hWnd]
        Mov [menuhand], Eax
        Invoke  DefWindowProc, [hWnd], [uMsg], [wParam], [lParam]
        Invoke  OpenASCII, [hWnd]
        Mov Eax, [mem]
        Mov [memdata], Eax
        Mov D[index], 1
        Ret
L2:	    Cmp Eax, WM_ACTIVATE
		Jne > L4
        Cmp D[mem], 0
        Jne >okok2
        Mov Eax, [mem]
        Mov [memdata], Eax
        Invoke  OpenASCII, [hWnd]
okok2:  Invoke  ASCIIscan, [hWnd]
        Mov Eax, [parts]
        Push Eax
        Push Offset num2
        Push Offset buff
        Call wsprintf
        Add Esp, 12
        Invoke SendDlgItemMessage, [hWnd], 506, WM_SETTEXT, 0, Addr buff
        Ret
L4:		Cmp Eax, WM_DESTROY
		Jne > L6
		Cmp D[memhand], NULL
		Je >
		Invoke GlobalFree, [memhand]
:		Invoke  PostQuitMessage, 0
		Ret
L6:		Cmp Eax, WM_COMMAND
		Jne >>L9
        Mov Eax, [wParam]
        Cmp D[lParam], 0
        Jne > L8
        Cmp Ax, IDM_EXIT
        Jne >
        Invoke  DestroyWindow, [hWnd]
        Ret
:       Cmp Ax, IDC_NEXT
		Je >gonext
        Cmp Ax, IDC_PREV
        Je >goprev
        Cmp Ax, IDM_ABOUT
        Jne >>L10
        Invoke DialogBoxParam, [hInstance], Addr AbtName, [hWnd], Offset AboutDlgProc, NULL
        Mov [hwndDlg], Eax
		Jmp >>L10
L8:     Cmp Ax, IDC_EXIT
        Jne >
        Invoke  SendMessage, [hWnd], WM_COMMAND, IDM_EXIT, 0
        Ret
:		Cmp Ax, IDC_NEXT
		Jne >toobig
gonext: Mov Ebx, [index]
        Cmp Ebx, [parts]
        Jae >toobig
        Mov Esi, [memdata]
        Add Esi, 4
        Cmp Esi, [memmax]
        Jae >toobig
gosi:   Inc Esi
        Cmp Esi, [memmax]
        Je >toobig
        Cmp W[Esi], 0D0AH     ; CRLF?
        Jne <gosi
        Add Esi, 3
        Mov [memdata], Esi
        Inc D[index]
        Invoke  ASCIIscan, [hWnd]
        Jmp >L10
toobig: Cmp Ax, IDC_PREV
	    Jne >L10
goprev: Mov Ebx, [index]
        Or Ebx, Ebx
        Jz >L10
        Mov Esi, [memdata]
        Cmp Esi, [mem]
        Je >L10
        Sub Esi, 4
gosi2:  Dec Esi
        Cmp Esi, [mem]
        Je >foundtop
        Cmp W[Esi], 0D0AH     ; CRLF?
        Jne <gosi2
        Add Esi, 3
foundtop:
		Mov [memdata], Esi
        Dec D[index]
        Invoke  ASCIIscan, [hWnd]
		Jmp >L10
L9:
        Invoke  DefWindowProc, [hWnd], [uMsg], [wParam], [lParam]
        Ret
L10:
	  	Xor Eax, Eax
        Ret
;---------------------------------------
EndF
;
;
HyperLinkWndProc Frame hWnd, uMsg, wParam, lParam Uses Ebx
;---------------------------------------
        Local tmpFont:LOGFONT
        Local rect:RECT
        Local pt:POINTL
;
        Mov Eax, [uMsg]
        Cmp Eax, WM_NCHITTEST
        Jne >
        Mov Eax, 1                ; We want to handle the non client hit test so we return true or 1
        Ret
:       Cmp Eax, WM_CTLCOLORSTATIC
		Jne >> L2
        Push Ebx
        Push Edx
        Invoke  SendMessage, [hWnd], WM_GETFONT, 0, 0
        Mov Edx, Eax
        Invoke  GetObject, Edx, SizeOf LOGFONT, Addr tmpFont
        Mov D[tmpFont.lfUnderline], TRUE
        Invoke  CreateFontIndirect, Addr tmpFont
        Mov Ebx, Eax
        Invoke  SelectObject, [wParam], Ebx
        Invoke  SetTextColor, [wParam], 0FF0000H
        Cmp D[hover], FALSE
        Je >
        Invoke  SetTextColor, [wParam], 0000FFH
:       Invoke  GetSysColor, COLOR_MENU
        Invoke  SetBkColor, [wParam], Eax
        Invoke  DeleteObject, Ebx
        Invoke  GetStockObject, HOLLOW_BRUSH
        Pop Edx
        Pop Ebx
        Ret
L2:		Cmp Eax, WM_MOUSEMOVE
		Jne >> L6
        Invoke  GetParent, [hWnd]
        Push Ebx
        Mov Ebx, Eax
        Invoke  GetActiveWindow
        Cmp Eax, Ebx
        Jne >> L4
        Invoke GetCursorPos, Addr pt
        Invoke GetWindowRect, [hWnd], Addr rect
        Invoke PtInRect, Addr rect, [pt.x], [pt.y]
        Or Eax, Eax
		Jz >
        Invoke GetCapture
        Or Eax, Eax
        Jnz > L4
        Invoke SetCapture, [hWnd]
        Mov D[hover], TRUE
        Invoke InvalidateRect, [hWnd], FALSE, FALSE
        Invoke SetCursor, [hFinger]
        Jmp > L4
:       Invoke GetCapture
		Or Eax, Eax
		Jz > L4
        Invoke ReleaseCapture
        Mov D[hover], FALSE
        Invoke InvalidateRect, [hWnd], FALSE, FALSE
L4:     Pop Ebx
        Xor Eax, Eax
        Ret
L6:     Cmp Eax, WM_LBUTTONDOWN
	    Jne >>.Default
        Invoke GetWindowText, [hWnd], Offset buff, SizeOf buff ; Change this for using a preset url
        Invoke ShellExecute, NULL, Offset szOpen, Offset buff, NULL, NULL, SW_MAXIMIZE   ; Change this to represent your preset url
        Mov D[hover], FALSE
        Invoke InvalidateRect, [hWnd], FALSE, FALSE
        Invoke SendMessage, [hWnd], WM_GETFONT, 0, 0        ; Get the defualt system font
        Mov Edx, Eax                                        ; Store result
        Invoke GetObject, Edx, SizeOf LOGFONT, Addr tmpFont	; Get our font into a logfont structure
        Mov D[tmpFont.lfUnderline], TRUE                    ; Under line the link
        Invoke CreateFontIndirect, Addr tmpFont             ; Create the new font
        Mov Ebx, Eax                                      	; We need the return to free the memory later
        Invoke SelectObject, [wParam], Ebx                  ; Select our control
        Invoke SetTextColor, [wParam], 0FF0000H             ; Change this to change the color of the link
        Xor Eax, Eax
        Ret
.Default:
        Invoke CallWindowProc, [orgStatic], [hWnd], [uMsg], [wParam], [lParam]
        Ret
;---------------------------------------
EndF
;
;
AboutDlgProc Frame hWnd, uMsg, wParam, lParam
;---------------------------------------
        Mov Eax, [uMsg]
        Cmp Eax, WM_INITDIALOG
        Jne >
        Invoke  GetDlgItem, [hWnd], IDC_URL
        Invoke  SetWindowLong, Eax, GWL_WNDPROC, Addr HyperLinkWndProc
        Mov [orgStatic], Eax
        Mov [hFinger], Eax
        Invoke GetDlgItem, [hWnd], IDC_EXIT
        Invoke SetFocus, Eax
        Mov Eax, TRUE
        Ret
:       Cmp Eax, WM_CTLCOLORSTATIC
		Jne >
        Invoke SendMessage, [lParam], [uMsg], [wParam], [lParam]
        Ret
:       Cmp Eax, WM_CLOSE
		Jne >
        Invoke  EndDialog, [hWnd], NULL
        Mov D[hwndDlg], 0
        Jmp >L2
:       Cmp Eax, WM_COMMAND
		Jne >L1
        Mov Eax, [wParam]
        Push Eax
        Shr Eax, 16
        Cmp Ax, BN_CLICKED
        Pop Eax
        Jne >L1
        Cmp Ax, IDC_EXIT
        Jne >L1
        Invoke  EndDialog, [hWnd], NULL
        Mov D[hwndDlg], 0
		Jmp >L2
L1:
        Mov Eax, FALSE
        Ret
L2:
        Mov Eax, TRUE
        Ret
;---------------------------------------
EndF
;
;
OpenASCII Frame hWnd Uses Ebx, Esi
;---------------------------------------

Invoke  CreateFile, Addr ASCIIname, GENERIC_READ, 0, \
                NULL, OPEN_EXISTING, FILE_ATTRIBUTE_ARCHIVE, NULL
        Cmp Eax, INVALID_HANDLE_VALUE
        Jne >
       	Invoke lstrcpy, Addr buff, Addr ASCIIname
		Invoke lstrcat, Addr buff, Addr szNotFound
       	Invoke MessageBox, [hWnd], Addr buff, Addr szAppName, MB_OK
       	Mov D[memhand], NULL
       	Invoke SendMessage, [hWnd], WM_DESTROY, 0, 0
       	Invoke  ExitProcess, Eax
       	Ret
:	    Mov [filehand1], Eax
        Invoke  GetFileSize, [filehand1], Addr temp
        Mov [filesize], Eax
        Invoke  GlobalAlloc, GMEM_MOVEABLE + GMEM_ZEROINIT, [filesize]
        Mov [memhand], Eax
        Invoke  GlobalLock, Eax
        Mov [mem], Eax
        Mov Esi, Eax
        Mov D[Esi], 1
        Invoke  ReadFile, [filehand1], [mem], [filesize], Addr sizeread, NULL
        Mov Esi, [mem]
        Mov Ecx, [filesize]
        Mov Ebx, Ecx
        Add Ebx, Esi
        Mov [memmax], Ebx
        Xor Eax, Eax
notset: Inc Esi
        Cmp D[Esi], 031646C66H
        Jne >notset2
        Inc Eax
notset2:
        Loop notset
        Inc Eax
        Mov [parts], Eax
		Ret
;---------------------------------------
EndF
;
;

ASCIIscan Frame hWnd Uses Esi, Edi
;---------------------------------------
        Mov Esi, [memdata]
bigtry: Lea Edi, ASCIIdata
        Xor Ecx, Ecx
retry:  Mov Al, [Esi]
        Cmp Al, [Edi]
        Jne >notit
        Xor Ch, Ch
        Push Esi
        Push Edi
retry1: Inc Esi
        Inc Edi
        Mov Al, [Esi]
        Cmp Al, [Edi]
        Jne >notit2
        Inc Ch
        Cmp Ch, 3
        Jb <retry1
        Xor Eax, Eax
        Mov Al, Cl
        Add Eax, 501
        Inc Esi
        Inc Esi
        Invoke  SendDlgItemMessage, [hWnd], Eax, WM_SETTEXT, 0, Esi
notit2: Pop Edi
        Pop Esi
notit:  Add Edi, 4
        Inc Cl
        Cmp Cl, 6
        Jb <retry
foundone:
        Cmp Esi, [memmax]
        Jae >overit
        Inc Esi
        Cmp B[Esi], 0AH
        Jne <foundone
        Cmp Esi, [memmax]
        Jae >overit
        Inc Esi
        Cmp B[Esi], 0DH
        Jne <bigtry
overit: Mov Eax, [index]
        Push Eax
        Push Addr num2
        Push Addr buff
        Call wsprintf
		Add Esp, 12
        Invoke SendDlgItemMessage, [hWnd], 507, WM_SETTEXT, 0, Addr buff
        Ret
;---------------------------------------
EndF
;
