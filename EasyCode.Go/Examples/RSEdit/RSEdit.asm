;EasyCodeName=RSEdit,1
/*==================================================================;
;  This is a complete dll text editor, with full source code, that  ;
;  can be modified and improved for anyone who uses it. If you mo-  ;
;  dify it, please send me the new code. Thank you.                 ;
;                                                                   ;
;        For any doubt, e-mail me at the following addresses:       ;
;                                                                   ;
;        asm@easycode.cat                 rsala@easycode.cat        ;
;                                                                   ;
;                     http://www.easycode.cat                       ;
;                                                                   ;
;                Copyright © 2003-2011 Ramon Sala                   ;
;===================================================================*/

.Data

MESSAGES		DD WM_NCCREATE, OnNcCreate
				DD WM_CREATE, OnCreate
				DD WM_ERASEBKGND, OnEraseBkgnd
				DD WM_PAINT, OnPaint
				DD WM_SETCURSOR, OnSetCursor
				DD WM_KILLFOCUS, OnKillFocus
				DD WM_SETFOCUS, OnSetFocus
				DD WM_KEYDOWN, OnKeyDown
				DD WM_CHAR, OnChar
				DD WM_LBUTTONDOWN, OnLButtonDown
				DD WM_LBUTTONDBLCLK, OnLButtonDblClk
				DD WM_MOUSEMOVE, OnMouseMove
				DD WM_RBUTTONDOWN, OnRButtonDown
				DD WM_RBUTTONDBLCLK, OnRButtonDblClk
				DD WM_LBUTTONUP, OnLButtonUp
				DD WM_RBUTTONUP, OnRButtonUp
				DD WM_MOUSEWHEEL, OnMouseWheel
				DD WM_HSCROLL, OnHScroll
				DD WM_VSCROLL, OnVScroll
				DD WM_GETFONT, OnGetFont
				DD WM_GETTEXT, OnGetText
				DD WM_GETTEXTLENGTH, OnGetTextLength
				DD WM_SETFONT, OnSetFont
				DD WM_SETTEXT, OnSetText
				DD WM_CUT, OnCutCopy
				DD WM_COPY, OnCutCopy
				DD WM_PASTE, OnPaste
				DD WM_UNDO, OnUndo
				DD RSM_CANPASTE, OnCanPaste
				DD RSM_CANREDO, OnCanRedo
				DD RSM_CANUNDO, OnCanUndo
				DD RSM_CLEARUNDOBUFFER, OnClearUndoBuffer
				DD RSM_FINDWORD, OnFindWord
				DD RSM_FINDTEXT, OnFindText
				DD RSM_GETBACKCOLOR, OnGetBackColor
				DD RSM_GETEVENTMASK, OnGetEventMask
				DD RSM_GETFIRSTVISIBLELINE, OnGetFirstVisibleLine
				DD RSM_GETHANDLE, OnGetHandle
				DD RSM_GETHIDESELECTION, OnGetHideSelection
				DD RSM_GETLINE, OnGetLine
				DD RSM_GETLINECOUNT, OnGetLineCount
				DD RSM_GETLINEFROMCHAR, OnGetLineFromChar
				DD RSM_GETLINEINDEX, OnGetLineIndex
				DD RSM_GETLINELENGTH, OnGetLineLength
				DD RSM_GETMODIFY, OnGetModify
				DD RSM_GETPOSITION, OnGetPosition
				DD RSM_GETSELBACKCOLOR, OnGetSelBackColor
				DD RSM_GETMARGINCOLOR, OnGetMarginColor
				DD RSM_GETMARGINWIDTH, OnGetMarginWidth
				DD RSM_GETSELECTION, OnGetSelection
				DD RSM_GETSELTEXT, OnGetSelText
				DD RSM_GETSELTEXTCOLOR, OnGetSelTextColor
				DD RSM_GETTEXTCOLOR, OnGetTextColor
				DD RSM_EDITORSCROLL, OnEditorScroll
				DD RSM_REPLACESEL, OnReplaceSel
				DD RSM_REDO, OnRedo
				DD RSM_SETAUTOINDENT, OnSetAutoIndent
				DD RSM_SETBACKCOLOR, OnSetBackColor
				DD RSM_SETCARETWIDTH, OnSetCaretWidth
				DD RSM_SETEVENTMASK, OnSetEventMask
				DD RSM_SETFINDPROC, OnSetFindProc
				DD RSM_SETHIDESELECTION, OnSetHideSelection
				DD RSM_SETHSCROLLBAR, OnSetHScrollBar
				DD RSM_SETMODIFY, OnSetModify
				DD RSM_SETPAINTPROC, OnSetPaintProc
				DD RSM_SETREADONLY, OnSetReadOnly
				DD RSM_SETSELBACKCOLOR, OnSetSelBackColor
				DD RSM_SETMARGINCOLOR, OnSetMarginColor
				DD RSM_SETMARGINWIDTH, OnSetMarginWidth
				DD RSM_SETSELECTION, OnSetSelection
				DD RSM_SETSELTEXTCOLOR, OnSetSelTextColor
				DD RSM_SETTABSTOPS, OnSetTabStops
				DD RSM_SETTEXTCOLOR, OnSetTextColor
				DD RSM_SETUNDOLIMIT, OnSetUndoLimit
				DD RSM_SETVSCROLLBAR, OnSetVScrollBar
				DD WM_SYSCOLORCHANGE, OnSysColorChange
				DD WM_TIMER, OnTimer
				DD WM_SIZE, OnSize
				DD WM_NCDESTROY, OnNcDestroy

RSszEditClass	DB	 		'RSEditClass', 0
RSszChar		DB			0, 0, 0
RSszLineFeed	DB			13, 10, 0
RSbMargin		DD			FALSE
RSdwPageSize	DD			4096
RShIBeam		DD			NULL
RShRArrow		DD			NULL
RShInst			DD			NULL
RSsci			SCROLLINFO


.Code

;===========================================================================
; Dll Entry Point
;===========================================================================

start:

DllEntryPoint Frame hInstance, dwReason, lpvReserved
	Cmp D[dwReason], DLL_PROCESS_ATTACH
	Jne >
	Call OnProcessAttach
	Ret

:	Cmp D[dwReason], DLL_PROCESS_DETACH
	Jne >
	Call OnProcessDetach
	Ret

:	Mov Eax, TRUE
	Ret
EndF

OnProcessAttach: UseData DllEntryPoint
	Local wc:WNDCLASSEX, sysinfo:SYSTEM_INFO

	Mov Eax, [hInstance]
	Mov [RShInst], Eax

	Mov [wc.hInstance], Eax
	Mov D[wc.cbSize], SizeOf WNDCLASSEX
	Mov D[wc.style], CS_DBLCLKS
	Mov [wc.lpfnWndProc], Offset RSEditProcedure
	Mov D[wc.cbClsExtra], 0
	Mov D[wc.cbWndExtra], 4
	Mov D[wc.hIcon], NULL
	Mov D[wc.hCursor], NULL
	Mov D[wc.hbrBackground], NULL
	Mov D[wc.lpszMenuName], NULL
	Mov [wc.lpszClassName], Offset RSszEditClass
	Mov D[wc.hIconSm], NULL
	Invoke RegisterClassEx, Addr wc

	Invoke GetSystemInfo, Addr sysinfo
	Mov Eax, [sysinfo.dwPageSize]
	Mov [RSdwPageSize], Eax

	Invoke LoadImage, 0, OCR_IBEAM, IMAGE_CURSOR, 0, 0, (LR_DEFAULTSIZE Or LR_LOADMAP3DCOLORS Or LR_SHARED)
	Mov [RShIBeam], Eax
	Invoke LoadImage, [RShInst], IDC_RARROW, IMAGE_CURSOR, 0, 0, LR_DEFAULTSIZE Or LR_LOADMAP3DCOLORS Or LR_SHARED
	Mov [RShRArrow], Eax
	Return (TRUE)
EndU

OnProcessDetach: UseData DllEntryPoint
	Invoke UnregisterClass, Offset RSszEditClass, [RShInst]
	Invoke DestroyCursor, [RShIBeam]
	Invoke DestroyCursor, [RShRArrow]
	Return (TRUE)
EndU

RSEditProcedure Frame hWnd, uMsg, wParam, lParam Uses Ebx
	Local lTemp:D, hdc:D, rc:RECT
	Local chr:RSSCHARSEL

	Invoke GetWindowLong, [hWnd], GWL_EDITORDATA
	Mov Ebx, Eax
	Mov Eax, [uMsg]
	Mov Ecx, SizeOf MESSAGES / 8
	Mov Edx, Addr MESSAGES
:	Dec Ecx
	Js >
	Cmp [Edx + Ecx * 8], Eax
	Jne <
	Call [Edx + Ecx * 8 + 4]
	Ret
:	Invoke DefWindowProc, [hWnd], [uMsg], [wParam], [lParam]
	Ret
EndF

OnNcCreate: UseData RSEditProcedure
	Invoke GlobalAlloc, GPTR, SizeOf EDITORDATA
	Mov Ebx, Eax
	Invoke SetWindowLong, [hWnd], GWL_EDITORDATA, Eax
	Mov Eax, [hWnd]
	Mov [Ebx + EDITORDATA.hWnd], Eax
	Invoke GetParent, [hWnd]
	Mov [Ebx + EDITORDATA.hWndOwner], Eax
	Invoke GetWindowLong, [hWnd], GWL_STYLE
	Mov Ecx, Eax
	And Eax, WS_HSCROLL
	Jz >
	Mov D[Ebx + EDITORDATA.bHScrollBar], TRUE
:	And Ecx, WS_VSCROLL
	Jz >
	Mov D[Ebx + EDITORDATA.bVScrollBar], TRUE
:	Mov D[Ebx + EDITORDATA.lCaretWidth], 1
	Mov D[Ebx + EDITORDATA.lMarginWidth], (-1)
	Lea Eax, rsFindHook
	Mov [Ebx + EDITORDATA.prFindProc], Eax
	Mov Eax, TRUE
	Ret
EndU

OnCreate: UseData RSEditProcedure
	Invoke GetClientRect, [hWnd], Addr rc
	Invoke GetDC, [hWnd]
	Mov [hdc], Eax
	Push Edx
	Mov D[lTemp], 10
	Invoke GetDeviceCaps, [hdc], LOGPIXELSY
	Mul D[lTemp]
	Mov D[lTemp], 72
	Xor Edx, Edx
	Div D[lTemp]
	Mov [lTemp], Eax
	Neg D[lTemp]
	Pop Edx
	Invoke CreateFont, [lTemp], 0, 0, 0, 400, FALSE, FALSE, FALSE, ANSI_CHARSET, 0, 0, 0, 0, TEXT("MS Sans Serif")
	Mov [Ebx + EDITORDATA.hFont], Eax
	Invoke SelectObject, [hdc], Eax
	Cmp Eax, [Ebx + EDITORDATA.hFont]
	Je >
	Invoke DeleteObject, Eax
:	Invoke ReleaseDC, [hWnd], [hdc]
	Mov D[Ebx + EDITORDATA.lTabStops], 4
	Mov D[Ebx + EDITORDATA.bInsert], TRUE
	Mov D[Ebx + EDITORDATA.crRealBackColor], (80000000H Or COLOR_WINDOW)
	Mov D[Ebx + EDITORDATA.crRealTextColor], (80000000H Or COLOR_WINDOWTEXT)
	Mov D[Ebx + EDITORDATA.crRealMarginColor], 00E0E0E0H
	Mov D[Ebx + EDITORDATA.crRealBackSelect], (80000000H Or COLOR_HIGHLIGHT)
	Mov D[Ebx + EDITORDATA.crRealTextSelect], (80000000H Or COLOR_HIGHLIGHTTEXT)
	Invoke GlobalAlloc, GPTR, 1028
	Mov [Ebx + EDITORDATA.lpszLine], Eax
	Mov D[Ebx + EDITORDATA.dwEventMask], (EV_CHANGE Or EV_SELCHANGE Or EV_HSCROLL Or EV_VSCROLL Or EV_UPDATE)
	Mov D[Ebx + EDITORDATA.lStartModified], 0
	Mov D[Ebx + EDITORDATA.lUndoCount], 0
	Mov D[Ebx + EDITORDATA.lUndoLimit], 200
	Mov D[Ebx + EDITORDATA.lUndoStart], (-1)
	Invoke GlobalAlloc, GPTR, (804 + 256)
	Mov [Ebx + EDITORDATA.lpUndoBuffer], Eax
	Add Eax, 804 ;200 * 4 + 4
	Mov [Ebx + EDITORDATA.lpszUndoText], Eax
	Invoke rsChangeControlColors, 31
	Mov D[RSsci.cbSize], SizeOf SCROLLINFO
	Mov D[RSsci.fMask], (SIF_PAGE Or SIF_POS Or SIF_RANGE Or SIF_DISABLENOSCROLL)
	Invoke SendMessage, [hWnd], WM_SETFONT, [Ebx + EDITORDATA.hFont], TRUE
	Invoke SendMessage, [hWnd], WM_SETTEXT, 0, NULL
	Xor Eax, Eax
	Ret
EndU

OnEraseBkgnd: UseData RSEditProcedure
	Mov Eax, TRUE
	Ret
EndU

OnPaint: UseData RSEditProcedure
	Call rsPaintEditor
	Xor Eax, Eax
	Ret
EndU

OnSetCursor: UseData RSEditProcedure
	Local pt:POINTL

	Invoke GetCursorPos, Addr pt
	Invoke ScreenToClient, [hWnd], Addr pt
	Mov Eax, [Ebx + EDITORDATA.lMarginWidth]
	Mov Edx, [RShIBeam]
	Cmp [pt.x], Eax
	Jg >
	Mov Edx, [RShRArrow]
:	Invoke SetClassLong, [hWnd], GCL_HCURSOR, Edx
	Push Eax
	Invoke DefWindowProc, [hWnd], [uMsg], [wParam], [lParam]
	Pop Eax
	Invoke SetClassLong, [hWnd], GCL_HCURSOR, Eax
	Mov Eax, TRUE
	Ret
EndU

OnKillFocus: UseData RSEditProcedure
	Invoke DefWindowProc, [hWnd], [uMsg], [wParam], [lParam]
	Call rsKillScrollTimer
	Invoke DestroyCaret
	Mov D[Ebx + EDITORDATA.bCaret], FALSE
	Mov Eax, EN_KILLFOCUS
	Shl Eax, 16
	Invoke SendMessage, [Ebx + EDITORDATA.hWndOwner], WM_COMMAND, Eax, [hWnd]
	Xor Eax, Eax
	Ret
EndU

OnSetFocus: UseData RSEditProcedure
	Invoke DefWindowProc, [hWnd], [uMsg], [wParam], [lParam]
	Invoke rsDisplayCursor
	Mov Eax, EN_SETFOCUS
	Shl Eax, 16
	Invoke SendMessage, [Ebx + EDITORDATA.hWndOwner], WM_COMMAND, Eax, [hWnd]
	Xor Eax, Eax
	Ret
EndU

OnKeyDown: UseData RSEditProcedure
	Local bCtrl:D, bShift:D, bAlt:D

	Invoke GetKeyState, VK_CONTROL
	And Eax, 00008000H
	Mov [bCtrl], Eax
	Invoke GetKeyState, VK_SHIFT
	And Eax, 00008000H
	Mov [bShift], Eax
	Invoke GetKeyState, VK_MENU
	And Eax, 00008000H
	Mov [bAlt], Eax
	Mov Eax, [Ebx + EDITORDATA.chrPos.lMin]
	Mov [chr.lMin], Eax
	Mov Eax, [Ebx + EDITORDATA.chrPos.lMax]
	Mov [chr.lMax], Eax
	Cmp D[wParam], 65 ;Ctrl+A
	Jne >
	Cmp D[bCtrl], 0
	Je >> L82
	Cmp D[bShift], 0
	Jne >> L82
	Cmp D[bAlt], 0
	Jne >> L82
	Invoke rsSetSelection, 0, [Ebx + EDITORDATA.lTextLength]
	Xor Eax, Eax
	Ret
:	Cmp D[wParam], 67 ;Ctrl+C
	Jne > L2
	Cmp D[bCtrl], 0
	Je >> L82
	Invoke SendMessage, [hWnd], WM_COPY, 0, 0
	Xor Eax, Eax
	Ret
L2:	Cmp D[wParam], 86 ;Ctrl+V
	Jne > L4
	Cmp D[bCtrl], 0
	Je >> L82
	Invoke SendMessage, [hWnd], WM_PASTE, 0, 0
	Xor Eax, Eax
	Ret
L4:	Cmp D[wParam], 88 ;Ctrl+X
	Jne > L6
	Cmp D[bCtrl], 0
	Je >> L82
	Invoke SendMessage, [hWnd], WM_CUT, 0, 0
	Xor Eax, Eax
	Ret
L6:	Cmp D[wParam], 89 ;Ctrl+Y
	Jne > L8
	Cmp D[bCtrl], 0
	Je >> L82
	Invoke SendMessage, [hWnd], RSM_REDO, 0, 0
	Xor Eax, Eax
	Ret
L8:	Cmp D[wParam], 90 ;Ctrl+Z
	Jne > L10
	Cmp D[bCtrl], 0
	Je >> L82
	Invoke SendMessage, [hWnd], WM_UNDO, 0, 0
	Xor Eax, Eax
	Ret
L10:
	Cmp D[wParam], VK_ESCAPE
	Jne > L12
	Mov Eax, [Ebx + EDITORDATA.chrPos.lMax]
	Cmp Eax, [Ebx + EDITORDATA.chrPos.lMin]
	Jle >
	Mov Eax, [Ebx + EDITORDATA.chrSel.lMax]
	Mov [Ebx + EDITORDATA.chrPos.lMin], Eax
	Mov [Ebx + EDITORDATA.chrPos.lMax], Eax
	Invoke rsUpdateEditor, FALSE
	Invoke rsSetCaret
:	Xor Eax, Eax
	Ret
L12:
	Cmp D[wParam], VK_INSERT
	Jne >> L14
	Cmp D[bCtrl], 0
	Jne >
	Cmp D[bShift], 0
	Jne >
	Cmp D[bAlt], 0
	Jne >
	Mov Eax, [Ebx + EDITORDATA.bInsert]
	Neg Eax
	Inc Eax
	Mov [Ebx + EDITORDATA.bInsert], Eax
	Xor Eax, Eax
	Ret
:	Cmp D[bCtrl], 0
	Je >
	Cmp D[bShift], 0
	Jne >
	Cmp D[bAlt], 0
	Jne >
	Invoke SendMessage, [hWnd], WM_COPY, 0, 0
	Xor Eax, Eax
	Ret
:	Cmp D[bShift], 0
	Je >> L82
	Cmp D[bCtrl], 0
	Jne >> L82
	Cmp D[bAlt], 0
	Jne >> L82
	Invoke SendMessage, [hWnd], WM_PASTE, 0, 0
	Xor Eax, Eax
	Ret
L14:
	Cmp D[bCtrl], 0
	Jne > L16
	Cmp D[wParam], VK_SHIFT
	Je >
	Cmp D[wParam], VK_CONTROL
	Je >
	Cmp D[wParam], VK_MENU
	Jne > L16
:	Xor Eax, Eax
	Ret
L16:
	Cmp D[wParam], VK_DELETE
	Jne >> L22
	Cmp D[bCtrl], 0
	Jne >> L20
	Cmp D[bAlt], 0
	Jne >> L20
	Mov Eax, [Ebx + EDITORDATA.lTextLength]
	Cmp [Ebx + EDITORDATA.chrPos.lMin], Eax
	Jge >
	Lea Eax, [RSszChar]
	Mov W[Eax], 0
	Mov Eax, [Ebx + EDITORDATA.chrPos.lMax]
	Sub Eax, [Ebx + EDITORDATA.chrPos.lMin]
	Mov [lTemp], Eax
	Or Eax, Eax
	Jnz > L18
	Inc D[Ebx + EDITORDATA.chrPos.lMax]
	Mov Eax, [Ebx + EDITORDATA.lpszText]
	Add Eax, [Ebx + EDITORDATA.chrPos.lMin]
	Cmp B[Eax], 13
	Jne > L18
	Inc D[Ebx + EDITORDATA.chrPos.lMax]
L18:
	Invoke rsReplaceSelection, Addr RSszChar, [wParam]
	Cmp D[lTemp], 0
	Jle > L20
	Invoke rsSetFirstLineIndex
:	Invoke rsSetSelection, [Ebx + EDITORDATA.chrSel.lMin], [Ebx + EDITORDATA.chrSel.lMax]
L20:
	Xor Eax, Eax
	Ret
L22:
	Cmp D[bAlt], 0
	Jne < L20
	Cmp D[wParam], VK_HOME
	Jne >> L30
	Cmp D[bCtrl], 0
	Je > L24
	Cmp D[bShift], 0
	Je >
	Cmp D[Ebx + EDITORDATA.chrPos.lMin], 0
	Jle >> L28
	Mov D[Ebx + EDITORDATA.chrPos.lMax], 0
	Mov Eax, [Ebx + EDITORDATA.chrSel.lMin]
	Mov [Ebx + EDITORDATA.chrPos.lMin], Eax
	Jmp > L28
:	Mov D[Ebx + EDITORDATA.chrPos.lMin], 0
	Mov D[Ebx + EDITORDATA.chrPos.lMax], 0
	Jmp > L28
L24:
	Cmp D[bShift], 0
	Je > L26
	Invoke rsFindFirstChar
	Add Eax, [Ebx + EDITORDATA.lLineIndex]
	Mov [lTemp], Eax
	Mov Eax, [Ebx + EDITORDATA.chrSel.lMax]
	Cmp [Ebx + EDITORDATA.chrSel.lMin], Eax
	Jne >
	Mov Eax, [lTemp]
	Mov [Ebx + EDITORDATA.chrPos.lMax], Eax
	Jmp > L28
:	Mov Eax, [Ebx + EDITORDATA.chrSel.lMin]
	Mov [Ebx + EDITORDATA.chrPos.lMin], Eax
	Mov Eax, [lTemp]
	Mov [Ebx + EDITORDATA.chrPos.lMax], Eax
	Jmp > L28
L26:
	Invoke rsFindFirstChar
	Add Eax, [Ebx + EDITORDATA.lLineIndex]
	Mov [Ebx + EDITORDATA.chrPos.lMin], Eax
	Mov [Ebx + EDITORDATA.chrPos.lMax], Eax
L28:
	Mov D[Ebx + EDITORDATA.bSelCol], TRUE
	Jmp >> L82
L30:
	Cmp D[wParam], VK_END
	Jne >> L38
	Mov Eax, [Ebx + EDITORDATA.lTextLength]
	Mov [lTemp], Eax
	Cmp D[bCtrl], 0
	Je > L34
	Cmp D[bShift], 0
	Je > L32
	Mov Eax, [Ebx + EDITORDATA.chrSel.lMax]
	Cmp Eax, [Ebx + EDITORDATA.chrSel.lMin]
	Jl >
	Mov Eax, [lTemp]
	Mov [Ebx + EDITORDATA.chrPos.lMax], Eax
	Jmp < L28
:	Mov Eax, [Ebx + EDITORDATA.chrPos.lMax]
	Mov [Ebx + EDITORDATA.chrPos.lMin], Eax
	Mov Eax, [lTemp]
	Mov [Ebx + EDITORDATA.chrPos.lMax], Eax
	Jmp < L28
L32:
	Mov Eax, [lTemp]
	Mov [Ebx + EDITORDATA.chrPos.lMax], Eax
	Mov [Ebx + EDITORDATA.chrPos.lMin], Eax
	Jmp < L28
L34:
	Cmp D[bShift], 0
	Je > L36
	Mov Eax, [Ebx + EDITORDATA.chrSel.lMax]
	Cmp Eax, [Ebx + EDITORDATA.chrSel.lMin]
	Jl >
	Mov Eax, [Ebx + EDITORDATA.lLineIndex]
	Add Eax, [Ebx + EDITORDATA.lCols]
	Mov [Ebx + EDITORDATA.chrPos.lMax], Eax
	Jmp << L28
:	Mov Eax, [Ebx + EDITORDATA.chrPos.lMax]
	Mov [Ebx + EDITORDATA.chrPos.lMin], Eax
	Mov Eax, [Ebx + EDITORDATA.lLineIndex]
	Add Eax, [Ebx + EDITORDATA.lCols]
	Mov [Ebx + EDITORDATA.chrPos.lMax], Eax
	Jmp << L28
L36:
	Mov Eax, [Ebx + EDITORDATA.lLineIndex]
	Add Eax, [Ebx + EDITORDATA.lCols]
	Mov [Ebx + EDITORDATA.chrPos.lMin], Eax
	Mov [Ebx + EDITORDATA.chrPos.lMax], Eax
	Jmp << L28
L38:
	Cmp D[wParam], VK_LEFT
	Jne >> L48
	Cmp D[bCtrl], 0
	Je >> L42
	Invoke rsFindPrevWord, [Ebx + EDITORDATA.chrPos.lMin]
	Mov [lTemp], Eax
	Cmp D[bShift], 0
	Je > L40
	Mov Eax, [Ebx + EDITORDATA.chrSel.lMin]
	Cmp Eax, [Ebx + EDITORDATA.chrSel.lMax]
	Jne >
	Cmp D[Ebx + EDITORDATA.chrPos.lMin], 0
	Jle >> L46 ;L42
	Mov Eax, [lTemp]
	Mov [Ebx + EDITORDATA.chrPos.lMax], Eax
	Jmp >> L46 ;L42
:	Cmp [Ebx + EDITORDATA.chrSel.lMax], Eax
	Jle >
	Invoke rsFindPrevWord, [Ebx + EDITORDATA.chrPos.lMax]
	Mov [Ebx + EDITORDATA.chrPos.lMax], Eax
	Jmp >> L46 ;L42
:	Mov Eax, [Ebx + EDITORDATA.chrPos.lMax]
	Mov [Ebx + EDITORDATA.chrPos.lMin], Eax
	Mov Eax, [lTemp]
	Mov [Ebx + EDITORDATA.chrPos.lMax], Eax
	Jmp >> L46 ;L42
L40:
	Mov Eax, [Ebx + EDITORDATA.chrSel.lMax]
	Cmp Eax, [Ebx + EDITORDATA.chrSel.lMin]
	Jne >
	Mov Eax, [lTemp]
	Mov [Ebx + EDITORDATA.chrPos.lMin], Eax
	Mov [Ebx + EDITORDATA.chrPos.lMax], Eax
	Jmp >> L46 ;L42
:	Mov Eax, [Ebx + EDITORDATA.chrPos.lMin]
	Mov [Ebx + EDITORDATA.chrPos.lMax], Eax
	Jmp >> L46
L42:
	Cmp D[bShift], 0
	Je > L44
	Mov Eax, [Ebx + EDITORDATA.chrSel.lMin]
	Cmp Eax, [Ebx + EDITORDATA.chrSel.lMax]
	Jne >
	Cmp D[Ebx + EDITORDATA.chrPos.lMin], 0
	Jle >> L46
	Mov Eax, [Ebx + EDITORDATA.chrPos.lMin]
	Dec Eax
	Mov [Ebx + EDITORDATA.chrPos.lMax], Eax
	Jmp > L46
:	Cmp [Ebx + EDITORDATA.chrSel.lMax], Eax
	Jg >
	Cmp D[Ebx + EDITORDATA.chrPos.lMin], 0
	Jle > L46
	Mov Eax, [Ebx + EDITORDATA.chrPos.lMax]
	Mov [Ebx + EDITORDATA.chrPos.lMin], Eax
	Mov Eax, [Ebx + EDITORDATA.chrSel.lMax]
	Mov [Ebx + EDITORDATA.chrPos.lMax], Eax
	Cmp D[Ebx + EDITORDATA.chrPos.lMax], 0
	Jle > L46
	Dec D[Ebx + EDITORDATA.chrPos.lMax]
	Jmp > L46
:	Cmp D[Ebx + EDITORDATA.chrPos.lMax], 0
	Jle > L46
	Dec D[Ebx + EDITORDATA.chrPos.lMax]
	Jmp > L46
L44:
	Mov Eax, [Ebx + EDITORDATA.chrSel.lMax]
	Cmp [Ebx + EDITORDATA.chrSel.lMin], Eax
	Jne >
	Cmp D[Ebx + EDITORDATA.chrPos.lMin], 0
	Jle >
	Dec D[Ebx + EDITORDATA.chrPos.lMin]
:	Mov Eax, [Ebx + EDITORDATA.chrPos.lMin]
	Mov [Ebx + EDITORDATA.chrPos.lMax], Eax
L46:
	Mov Eax, [Ebx + EDITORDATA.lpszText]
	Add Eax, [Ebx + EDITORDATA.chrPos.lMax]
	Cmp B[Eax], 10
	Jne << L28
	Mov Eax, [Ebx + EDITORDATA.chrPos.lMin]
	Cmp Eax, [Ebx + EDITORDATA.chrPos.lMax]
	Jne >
	Dec D[Ebx + EDITORDATA.chrPos.lMin]
:	Dec D[Ebx + EDITORDATA.chrPos.lMax]
	Jmp << L28
L48:
	Cmp D[wParam], VK_RIGHT
	Jne >> L58
	Mov Eax, [Ebx + EDITORDATA.lTextLength]
	Mov [lTemp], Eax
	Cmp D[bCtrl], 0
	Je >> L52
	Cmp D[bShift], 0
	Je > L50
	Mov Eax, [Ebx + EDITORDATA.chrSel.lMax]
	Cmp [Ebx + EDITORDATA.chrSel.lMin], Eax
	Jne >
	Mov Eax, [Ebx + EDITORDATA.chrPos.lMax]
	Cmp Eax, [lTemp]
	Jge >> L56
	Invoke rsFindNextWord, [Ebx + EDITORDATA.chrPos.lMin]
	Mov [Ebx + EDITORDATA.chrPos.lMax], Eax
	Jmp >> L56
:	Cmp Eax, [Ebx + EDITORDATA.chrSel.lMin]
	Jle >
	Invoke rsFindNextWord, [Ebx + EDITORDATA.chrPos.lMax]
	Mov [Ebx + EDITORDATA.chrPos.lMax], Eax
	Jmp >> L56
:	Mov Eax, [Ebx + EDITORDATA.chrPos.lMin]
	Mov [lTemp], Eax
	Mov Eax, [Ebx + EDITORDATA.chrPos.lMax]
	Mov [Ebx + EDITORDATA.chrPos.lMin], Eax
	Invoke rsFindNextWord, [lTemp]
	Mov [Ebx + EDITORDATA.chrPos.lMax], Eax
	Jmp >> L56
L50:
	Mov Eax, [Ebx + EDITORDATA.chrSel.lMin]
	Cmp [Ebx + EDITORDATA.chrSel.lMax], Eax
	Jne >
	Mov Eax, [Ebx + EDITORDATA.chrPos.lMax]
	Cmp Eax, [lTemp]
	Jge >> L56
	Invoke rsFindNextWord, [Ebx + EDITORDATA.chrPos.lMax]
	Mov [Ebx + EDITORDATA.chrPos.lMax], Eax
	Mov [Ebx + EDITORDATA.chrPos.lMin], Eax
	Jmp >> L56
:	Mov Eax, [Ebx + EDITORDATA.chrPos.lMax]
	Mov [Ebx + EDITORDATA.chrPos.lMin], Eax
	Jmp >> L56
L52:
	Cmp D[bShift], 0
	Je > L54
	Mov Eax, [Ebx + EDITORDATA.chrSel.lMax]
	Cmp Eax, [Ebx + EDITORDATA.chrSel.lMin]
	Jl >
	Mov Eax, [Ebx + EDITORDATA.chrPos.lMax]
	Cmp Eax, [lTemp]
	Jge > L56
	Inc D[Ebx + EDITORDATA.chrPos.lMax]
	Jmp > L56
:	Mov Eax, [Ebx + EDITORDATA.chrPos.lMax]
	Mov [Ebx + EDITORDATA.chrPos.lMin], Eax
	Mov Eax, [Ebx + EDITORDATA.chrSel.lMax]
	Mov [Ebx + EDITORDATA.chrPos.lMax], Eax
	Cmp Eax, [Ebx + EDITORDATA.lTextLength]
	Jge > L56
	Inc D[Ebx + EDITORDATA.chrPos.lMax]
	Jmp > L56
L54:
	Mov Eax, [Ebx + EDITORDATA.chrSel.lMin]
	Cmp Eax, [Ebx + EDITORDATA.chrSel.lMax]
	Jne >
	Mov Eax, [Ebx + EDITORDATA.chrPos.lMax]
	Cmp Eax, [lTemp]
	Jge > L56
	Inc Eax
	Mov [Ebx + EDITORDATA.chrPos.lMax], Eax
	Mov [Ebx + EDITORDATA.chrPos.lMin], Eax
	Jmp > L56
:	Mov Eax, [Ebx + EDITORDATA.chrPos.lMax]
	Mov [Ebx + EDITORDATA.chrPos.lMin], Eax
L56:
	Mov Eax, [Ebx + EDITORDATA.lpszText]
	Add Eax, [Ebx + EDITORDATA.chrPos.lMax]
	Cmp B[Eax], 10
	Jne << L28
	Mov Eax, [Ebx + EDITORDATA.chrPos.lMin]
	Cmp Eax, [Ebx + EDITORDATA.chrPos.lMax]
	Jne >
	Inc D[Ebx + EDITORDATA.chrPos.lMin]
:	Inc D[Ebx + EDITORDATA.chrPos.lMax]
	Jmp << L28
L58:
	Cmp D[wParam], VK_UP
	Jne >> L66
	Cmp D[bCtrl], 0
	Je >
	Cmp D[bShift], 0
	Je >
	Xor Eax, Eax
	Ret
:	Cmp D[bCtrl], 0
	Je > L60
	Cmp D[bShift], 0
	Jne > L60
	Cmp D[Ebx + EDITORDATA.lVScrollPos], 0
	Jle >> L82
	Invoke rsScroll, (-1), 0
	Invoke rsUpdateEditor, FALSE
L60:
	Invoke rsGetPrevLineIndex, [Ebx + EDITORDATA.lLineIndex]
	Mov [Ebx + EDITORDATA.lLineIndex], Eax
	Mov [lTemp], Eax
	Mov Eax, [Ebx + EDITORDATA.lSelCol]
	Mov [Ebx + EDITORDATA.ptPos.x], Eax
	Invoke rsGetMemoryPosition
	Add [lTemp], Eax
	Mov Eax, [Ebx + EDITORDATA.chrSel.lMax]
	Cmp Eax, [Ebx + EDITORDATA.chrSel.lMin]
	Jge >
	Mov Eax, [Ebx + EDITORDATA.chrPos.lMax]
	Mov [Ebx + EDITORDATA.chrPos.lMin], Eax
:	Mov Eax, [lTemp]
	Mov [Ebx + EDITORDATA.chrPos.lMax], Eax
	Invoke rsGetLineLength, [Ebx + EDITORDATA.lLineIndex]
	Mov [lTemp], Eax
	Mov Eax, [Ebx + EDITORDATA.chrPos.lMax]
	Sub Eax, [Ebx + EDITORDATA.lLineIndex]
	Cmp Eax, [lTemp]
	Jl > L62
	Cmp D[bShift], 0
	Je >
	Mov Eax, [Ebx + EDITORDATA.lLineIndex]
	Add Eax, [lTemp]
	Inc Eax
	Mov [Ebx + EDITORDATA.chrPos.lMax], Eax
	Jmp > L62
:	Mov Eax, [Ebx + EDITORDATA.lLineIndex]
	Add Eax, [lTemp]
	Dec Eax
	Mov [Ebx + EDITORDATA.chrPos.lMax], Eax
L62:
	Cmp D[bShift], 0
	Jne > L64
	Mov Eax, [Ebx + EDITORDATA.chrSel.lMin]
	Cmp Eax, [Ebx + EDITORDATA.chrSel.lMax]
	Jge >
	Invoke rsGetPrevLineIndex, [Ebx + EDITORDATA.chrPos.lMin]
	Mov [Ebx + EDITORDATA.chrPos.lMax], Eax
	Mov Eax, [Ebx + EDITORDATA.lSelCol]
	Mov [Ebx + EDITORDATA.ptPos.x], Eax
	Invoke rsGetMemoryPosition
	Add [Ebx + EDITORDATA.chrPos.lMax], Eax
:	Mov Eax, [Ebx + EDITORDATA.chrPos.lMax]
	Mov [Ebx + EDITORDATA.chrPos.lMin], Eax
L64:
	Mov D[Ebx + EDITORDATA.bSelCol], FALSE
	Jmp >> L82
L66:
	Cmp D[wParam], VK_DOWN
	Jne >> L72
	Mov Eax, [Ebx + EDITORDATA.lTextLength]
	Mov [lTemp], Eax
	Cmp [Ebx + EDITORDATA.chrPos.lMax], Eax
	Jl >
	Cmp Eax, [Ebx + EDITORDATA.chrPos.lMin]
	Je >> L82
:	Cmp D[bCtrl], 0
	Je >
	Cmp D[bShift], 0
	Je >
	Xor Eax, Eax
	Ret
:	Cmp D[bCtrl], 0
	Je > L68
	Cmp D[bShift], 0
	Jne > L68
	Mov Eax, [Ebx + EDITORDATA.lLines]
	Sub Eax, [Ebx + EDITORDATA.lVScrollPage]
	Invoke rsScroll, 1, 0
	Invoke rsUpdateEditor, FALSE
L68:
	Invoke rsGetNextLineIndex, [Ebx + EDITORDATA.lLineIndex]
	Mov [Ebx + EDITORDATA.lLineIndex], Eax
	Cmp Eax, [lTemp]
	Jge >
	Mov Eax, [Ebx + EDITORDATA.lSelCol]
	Mov [Ebx + EDITORDATA.ptPos.x], Eax
	Invoke rsGetMemoryPosition
	Add Eax, [Ebx + EDITORDATA.lLineIndex]
	Mov [lTemp], Eax
:	Mov Eax, [Ebx + EDITORDATA.chrSel.lMax]
	Cmp Eax, [Ebx + EDITORDATA.chrSel.lMin]
	Jge >
	Mov Eax, [Ebx + EDITORDATA.chrPos.lMax]
	Mov [Ebx + EDITORDATA.chrPos.lMin], Eax
:	Mov Eax, [lTemp]
	Mov [Ebx + EDITORDATA.chrPos.lMax], Eax
	Invoke rsGetLineLength, [Ebx + EDITORDATA.lLineIndex]
	Mov [lTemp], Eax
	Mov Eax, [Ebx + EDITORDATA.chrPos.lMax]
	Sub Eax, [Ebx + EDITORDATA.lLineIndex]
	Cmp D[lTemp], 0
	Jle > L70
	Cmp Eax, [lTemp]
	Jl > L70
	Cmp D[bShift], 0
	Je >
	Mov Eax, [Ebx + EDITORDATA.lLineIndex]
	Add Eax, [lTemp]
	Inc Eax
	Mov [Ebx + EDITORDATA.chrPos.lMax], Eax
	Jmp > L70
:	Mov Eax, [Ebx + EDITORDATA.lLineIndex]
	Add Eax, [lTemp]
	Dec Eax
	Mov [Ebx + EDITORDATA.chrPos.lMax], Eax
L70:
	Cmp D[bShift], 0
	Jne << L64
	Mov Eax, [Ebx + EDITORDATA.chrSel.lMax]
	Cmp [Ebx + EDITORDATA.chrSel.lMin], Eax
	Jle >
	Invoke rsGetNextLineIndex, [Ebx + EDITORDATA.chrPos.lMin]
	Mov [Ebx + EDITORDATA.chrPos.lMax], Eax
	Mov Eax, [Ebx + EDITORDATA.lSelCol]
	Mov [Ebx + EDITORDATA.ptPos.x], Eax
	Invoke rsGetMemoryPosition
	Add [Ebx + EDITORDATA.chrPos.lMax], Eax
:	Mov Eax, [Ebx + EDITORDATA.chrPos.lMax]
	Mov [Ebx + EDITORDATA.chrPos.lMin], Eax
	Jmp << L64
L72:
	Cmp D[wParam], VK_PRIOR
	Jne >> L76
	Cmp D[bCtrl], 0
	Jne << L64
	Cmp D[Ebx + EDITORDATA.lLineIndex], 0
	Jne >
	Mov Eax, [Ebx + EDITORDATA.chrPos.lMax]
	Cmp Eax, [Ebx + EDITORDATA.chrPos.lMin]
	Je << L64
:	Push Edx
	Mov Edx, [Ebx + EDITORDATA.lVScrollPos]
	Sub Edx, [Ebx + EDITORDATA.lVScrollPage]
	Jge >
	Xor Edx, Edx
:	Mov Eax, [Ebx + EDITORDATA.ptPos.y]
	Sub Eax, [Ebx + EDITORDATA.lVScrollPos]
	Mov [lTemp], Eax
	Mov Eax, [Ebx + EDITORDATA.lVScrollPos]
	Sub Eax, [lTemp]
	Jge >
	Mov [lTemp], Edx
:	Invoke rsGetLineIndex, Edx
	Mov [Ebx + EDITORDATA.lLineIndex], Eax
	Mov [Ebx + EDITORDATA.lVScrollPos], Edx
	Mov Eax, [Ebx + EDITORDATA.lLineIndex]
	Mov [Ebx + EDITORDATA.lFirstLineIndex], Eax
	Add Edx, [lTemp]
	Invoke rsGetLineIndex, Edx
	Mov [Ebx + EDITORDATA.lLineIndex], Eax
	Cmp Eax, [Ebx + EDITORDATA.lTextLength]
	Jge >
	Mov Eax, [Ebx + EDITORDATA.lSelCol]
	Mov [Ebx + EDITORDATA.ptPos.x], Eax
	Mov Edx, [Ebx + EDITORDATA.lLineIndex]
	Invoke rsGetMemoryPosition
	Add Edx, Eax
	Mov [Ebx + EDITORDATA.lLineIndex], Edx
	Mov Eax, Edx
:	Pop Edx
	Mov [Ebx + EDITORDATA.chrPos.lMax], Eax
	Cmp D[bShift], 0
	Je >
	Mov Eax, [Ebx + EDITORDATA.chrSel.lMin]
	Mov [Ebx + EDITORDATA.chrPos.lMin], Eax
	Jmp > L74
:	Mov Eax, [Ebx + EDITORDATA.chrPos.lMax]
	Mov [Ebx + EDITORDATA.chrPos.lMin], Eax
L74:
	Invoke rsUpdateEditor, FALSE
	Jmp << L64
L76:
	Cmp D[wParam], VK_NEXT
	Jne >> L82
	Cmp D[bCtrl], 0
	Jne << L64
	Mov Eax, [Ebx + EDITORDATA.lLineIndex]
	Cmp Eax, [Ebx + EDITORDATA.lTextLength]
	Jl >
	Mov Eax, [Ebx + EDITORDATA.chrPos.lMax]
	Cmp Eax, [Ebx + EDITORDATA.chrPos.lMin]
	Je << L64
:	Push Edx
	Mov Eax, [Ebx + EDITORDATA.lVScrollPos]
	Mov Edx, Eax
	Add Eax, [Ebx + EDITORDATA.lVScrollPage]
	Cmp Edx, Eax
	Jge >
	Add Edx, [Ebx + EDITORDATA.lVScrollPage]
:	Mov Eax, Edx
	Add Eax, [Ebx + EDITORDATA.lVScrollPage]
	Cmp Eax, [Ebx + EDITORDATA.lLines]
	Jl >
	Mov Edx, [Ebx + EDITORDATA.lLines]
	Dec Edx
	Sub Edx, [Ebx + EDITORDATA.lVScrollPage]
:	Cmp Edx, 0
	Jge >
	Mov Eax, [Ebx + EDITORDATA.lTextLength]
	Mov [Ebx + EDITORDATA.chrPos.lMax], Eax
	Jmp > L78
:	Mov Eax, [Ebx + EDITORDATA.ptPos.y]
	Sub Eax, [Ebx + EDITORDATA.lVScrollPos]
	Mov [lTemp], Eax
	Add Eax, [Ebx + EDITORDATA.lVScrollPos]
	Add Eax, [Ebx + EDITORDATA.lVScrollPage]
	Inc Eax
	Push Ecx
	Mov Ecx, [Ebx + EDITORDATA.lLines]
	Dec Ecx
	Cmp Eax, Ecx
	Jl >
	Sub Ecx, Edx
	Mov [lTemp], Ecx
:	Pop Ecx
	Invoke rsGetLineIndex, Edx
	Mov [Ebx + EDITORDATA.lLineIndex], Eax
	Mov [Ebx + EDITORDATA.lVScrollPos], Edx
	Mov [Ebx + EDITORDATA.lFirstLineIndex], Eax
	Add Edx, [lTemp]
	Invoke rsGetLineIndex, Edx
	Mov [Ebx + EDITORDATA.lLineIndex], Eax
	Cmp Eax, [Ebx + EDITORDATA.lTextLength]
	Jge >
	Mov Eax, [Ebx + EDITORDATA.lSelCol]
	Mov [Ebx + EDITORDATA.ptPos.x], Eax
	Invoke rsGetMemoryPosition
	Add Eax, [Ebx + EDITORDATA.lLineIndex]
	Mov [Ebx + EDITORDATA.lLineIndex], Eax
:	Mov [Ebx + EDITORDATA.chrPos.lMax], Eax
L78:
	Pop Edx
	Cmp D[bShift], 0
	Je >
	Mov Eax, [Ebx + EDITORDATA.chrSel.lMin]
	Mov [Ebx + EDITORDATA.chrPos.lMin], Eax
	Jmp > L80
:	Mov Eax, [Ebx + EDITORDATA.chrPos.lMax]
	Mov [Ebx + EDITORDATA.chrPos.lMin], Eax
L80:
	Invoke rsUpdateEditor, FALSE
	Jmp << L64
L82:
	Cmp D[wParam], 31
	Ja >
	Xor Eax, Eax
	Ret
:	Push Ecx
	Mov Eax, [chr.lMin]
	Mov Ecx, [chr.lMax]
	Cmp [Ebx + EDITORDATA.chrPos.lMin], Eax
	Jne >
	Cmp [Ebx + EDITORDATA.chrPos.lMax], Ecx
	Je > L84
:	Invoke rsSetSelection, [Ebx + EDITORDATA.chrPos.lMin], [Ebx + EDITORDATA.chrPos.lMax]
	Jmp > L86
L84:
	Mov Eax, [Ebx + EDITORDATA.lVScrollPos]
	Add Eax, [Ebx + EDITORDATA.ptPos.y]
	Cmp Eax, [Ebx + EDITORDATA.lVScrollPos]
	Jl > L86
	Cmp D[Ebx + EDITORDATA.bSelCol], FALSE
	Je > L86
	Mov D[Ebx + EDITORDATA.bSelCol], FALSE
	Mov Eax, [Ebx + EDITORDATA.lRealCol]
	Mov [Ebx + EDITORDATA.lSelCol], Eax
L86:
	Invoke rsSetSelection, [Ebx + EDITORDATA.chrSel.lMin], [Ebx + EDITORDATA.chrSel.lMax]
	Pop Ecx
	Xor Eax, Eax
	Ret
EndU

OnChar: UseData RSEditProcedure
	Cmp D[wParam], VK_ESCAPE
	Jne >
L2:	Xor Eax, Eax
	Ret
:	Cmp D[wParam], 1 ; Ctrl+A
	Je < L2
	Cmp D[wParam], 3 ; Ctrl+C
	Je < L2
	Cmp D[wParam], 22 ; Ctrl+V
	Je < L2
	Cmp D[wParam], 24 ; Ctrl+X
	Je < L2
	Cmp D[wParam], 25 ; Ctrl+Y
	Je < L2
	Cmp D[wParam], 26 ; Ctrl+Z
	Je < L2
	Cmp D[wParam], VK_RETURN
	Jne > L8
	Invoke rsSendNotifyMessage, NM_RETURN
	Cmp D[Ebx + EDITORDATA.bAutoIndent], 0
	Jne >
	Invoke rsReplaceSelection, Addr RSszLineFeed, [wParam]
	Jmp < L2
:	Push Esi
	Push Edi
	Mov Edi, [Ebx + EDITORDATA.lpszLine]
	Mov Ax, 0A0DH
	Stosw
	Mov Esi, [Ebx + EDITORDATA.lLineIndex]
	Add Esi, [Ebx + EDITORDATA.lpszText]
L4:	Cmp B[Esi], 0
	Je > L6
	Lodsb
	Cmp Al, ' '
	Je >
	Cmp Al, 9
	Jne > L6
:	Stosb
	Jmp < L4
L6:	Invoke rsReplaceSelection, [Ebx + EDITORDATA.lpszLine], [wParam]
	Pop Edi
	Pop Esi
	Xor Eax, Eax
	Ret
L8:	Cmp D[wParam], VK_BACK
	Jne > L12
	Lea Eax, [RSszChar]
	Mov B[Eax], 0
	Mov B[Eax + 1], 0
	Mov Eax, [Ebx + EDITORDATA.chrPos.lMin]
	Cmp Eax, [Ebx + EDITORDATA.chrPos.lMax]
	Jne > L10
	Cmp Eax, 0
	Jg >
	Xor Eax, Eax
	Ret
:	Dec Eax
	Mov [Ebx + EDITORDATA.chrPos.lMin], Eax
	Add Eax, [Ebx + EDITORDATA.lpszText]
	Cmp B[Eax], 10
	Jne > L10
	Dec D[Ebx + EDITORDATA.chrPos.lMin]
L10:
	Invoke rsReplaceSelection, Addr RSszChar, [wParam]
	Xor Eax, Eax
	Ret
L12:
	Cmp D[Ebx + EDITORDATA.lRealCols], 1023
	Jle >
	Invoke MessageBeep, 0
	Xor Eax, Eax
	Ret
:	Cmp D[wParam], VK_TAB
	Je >
	Cmp D[wParam], 32
	Jl > L14
:	LoWord ([wParam])
	Lea Edx, [RSszChar]
	Mov B[Edx], Al
	Mov B[Edx + 1], 0
	Mov Eax, [Ebx + EDITORDATA.chrPos.lMax]
	Cmp Eax, [Ebx + EDITORDATA.chrPos.lMin]
	Jne >
	Add Eax, [Ebx + EDITORDATA.lpszText]
	Cmp D[Ebx + EDITORDATA.bInsert], 0
	Jne >
	Cmp B[Eax], 13
	Je >
	Sub Eax, [Ebx + EDITORDATA.lpszText]
	Cmp Eax, [Ebx + EDITORDATA.lTextLength]
	Jg >
	Inc D[Ebx + EDITORDATA.chrPos.lMax]
:	Invoke rsReplaceSelection, Addr RSszChar, [wParam]
L14:
	Xor Eax, Eax
	Ret
EndU

OnLButtonDown: UseData RSEditProcedure
	Invoke SetFocus, [hWnd]
	LoWord ([lParam])
	Cwde
	Cmp Eax, [Ebx + EDITORDATA.lMarginWidth]
	Jge >
	Mov D[RSbMargin], TRUE
	Invoke rsProcessMarginMouseMessages, [uMsg], [wParam], [lParam]
	Xor Eax, Eax
	Ret
:	Invoke rsProcessEditotMouseMessages, [uMsg], [wParam], [lParam]
	Mov Ecx, [wParam]
	And Ecx, MK_SHIFT
	Jnz >
	Mov Ecx, [wParam]
	And Ecx, MK_CONTROL
	Jz > L2
:	Mov Eax, [Ebx + EDITORDATA.chrSel.lMin]
L2:	Mov [Ebx + EDITORDATA.lStart], Eax
	Invoke SetCapture, [hWnd]
	Invoke rsSetSelection, [Ebx + EDITORDATA.chrPos.lMin], [Ebx + EDITORDATA.chrPos.lMax]
	Xor Eax, Eax
	Ret
EndU

OnLButtonDblClk: UseData RSEditProcedure
	Invoke rsSendNotifyMessage, NM_DBLCLK
	LoWord ([lParam])
	Cwde
	Cmp Eax, [Ebx + EDITORDATA.lMarginWidth]
	Jge >
	Invoke SendMessage, [hWnd], WM_LBUTTONDOWN, [wParam], [lParam]
	Xor Eax, Eax
	Ret
:	Invoke rsSelectWord, [Ebx + EDITORDATA.chrPos.lMin], FALSE
	Invoke rsSetSelection, [Ebx + EDITORDATA.chrPos.lMin], [Ebx + EDITORDATA.chrPos.lMax]
	Xor Eax, Eax
	Ret
EndU

OnMouseMove: UseData RSEditProcedure
	Mov Eax, [wParam]
	And Eax, MK_LBUTTON
	Jz >> L6
	Invoke GetCapture
	Cmp Eax, [hWnd]
	Jne >> L6
	Cmp D[RSbMargin], FALSE
	Je >
	Invoke rsProcessMarginMouseMessages, [uMsg], [wParam], [lParam]
	Xor Eax, Eax
	Ret
:	Invoke rsProcessEditotMouseMessages, [uMsg], [wParam], [lParam]
	Mov Eax, [Ebx + EDITORDATA.chrPos.lMax]
	Cmp Eax, [Ebx + EDITORDATA.lStart]
	Jg >
	Mov Eax, [wParam]
	And Eax, (MK_SHIFT Or MK_CONTROL)
	Jz > L2
	Invoke rsSetSelection, [Ebx + EDITORDATA.chrPos.lMin], [Ebx + EDITORDATA.chrPos.lMax]
	Jmp > L6
L2:	Invoke rsSetSelection, [Ebx + EDITORDATA.lStart], [Ebx + EDITORDATA.chrPos.lMin]
	Jmp > L6
:	Mov Eax, [wParam]
	And Eax, (MK_SHIFT Or MK_CONTROL)
	Jz > L4
	Invoke rsSetSelection, [Ebx + EDITORDATA.chrPos.lMin], [Ebx + EDITORDATA.chrPos.lMax]
	Jmp > L6
L4:	Invoke rsSetSelection, [Ebx + EDITORDATA.lStart], [Ebx + EDITORDATA.chrPos.lMax]
L6:	Xor Eax, Eax
	Ret
EndU

OnRButtonDown: UseData RSEditProcedure
	Invoke SetFocus, [hWnd]
	Invoke rsSendNotifyMessage, NM_RCLICK
	Mov Eax, [Ebx + EDITORDATA.chrPos.lMin]
	Mov [chr.lMin], Eax
	Mov Eax, [Ebx + EDITORDATA.chrPos.lMax]
	Mov [chr.lMax], Eax
	Invoke rsProcessEditotMouseMessages, [uMsg], [wParam], [lParam]
	Mov Eax, [Ebx + EDITORDATA.chrPos.lMin]
	Mov Edx, [Ebx + EDITORDATA.chrPos.lMax]
	Cmp Eax, [chr.lMin]
	Jl >
	Cmp Edx, [chr.lMax]
	Jle > L2
:	Invoke rsSetSelection, [Ebx + EDITORDATA.chrPos.lMin], [Ebx + EDITORDATA.chrPos.lMax]
	Jmp > L4
L2:	Mov Eax, [chr.lMin]
	Mov [Ebx + EDITORDATA.chrPos.lMin], Eax
	Mov Eax, [chr.lMax]
	Mov [Ebx + EDITORDATA.chrPos.lMax], Eax
L4:	Xor Eax, Eax
	Ret
EndU

OnRButtonDblClk: UseData RSEditProcedure
	Invoke rsSendNotifyMessage, NM_RDBLCLK
	Xor Eax, Eax
	Ret
EndU

OnLButtonUp: UseData RSEditProcedure
	Invoke GetCapture
	Cmp Eax, [hWnd]
	Jne >
	Invoke rsSendNotifyMessage, NM_CLICK
:	Invoke ReleaseCapture
	Call rsKillScrollTimer
	Mov D[RSbMargin], FALSE
	Xor Eax, Eax
	Ret
EndU

OnRButtonUp: UseData RSEditProcedure
	Invoke rsSendNotifyMessage, NM_RCLICK
	Xor Eax, Eax
	Ret
EndU

OnMouseWheel: UseData RSEditProcedure
	HiWord ([wParam])
	Cmp Ax, 0
	Jge >
	Mov Eax, 3
	Jmp > L2
:	Cmp D[Ebx + EDITORDATA.lVScrollPos], 0
	Jne >
	Ret
:	Cmp D[Ebx + EDITORDATA.lVScrollPos], 3
	Jl >
	Mov Eax, (-3)
	Jmp > L2
:	Mov Eax, [Ebx + EDITORDATA.lVScrollPos]
	Neg Eax
L2:	Invoke rsScroll, Eax, 0
	Invoke rsUpdateScrollBars
	Invoke rsUpdateEditor, FALSE
	Invoke rsSetCaret
	Xor Eax, Eax
	Ret
EndU

OnHScroll: UseData RSEditProcedure
	Push Edi
	Invoke SetFocus, [hWnd]
	Mov Eax, [Ebx + EDITORDATA.lHScrollPos]
	Mov Edi, Eax
	LoWord ([wParam])
	Cmp Ax, SB_LINELEFT
	Jne >
	Mov Eax, [Ebx + EDITORDATA.szFont.cx]
	Not Eax
	Jmp > L2
:	Cmp Ax, SB_LINERIGHT
	Jne >
	Mov Eax, [Ebx + EDITORDATA.szFont.cx]
	Jmp > L2
:	Cmp Ax, SB_PAGELEFT
	Jne >
	Mov Eax, [Ebx + EDITORDATA.lHScrollPage]
	Not Eax
	Jmp > L2
:	Cmp Ax, SB_PAGERIGHT
	Jne >
	Mov Eax, [Ebx + EDITORDATA.lHScrollPage]
	Jmp > L2
:	Cmp Ax, SB_THUMBPOSITION
	Je >
	Cmp Ax, SB_THUMBTRACK
	Jne > L4
:	Invoke rsGetTrackPos, SB_HORZ
	Sub Eax, [Ebx + EDITORDATA.lHScrollPos]
L2:	Invoke rsScroll, 0, Eax
	Cmp Edi, [Ebx + EDITORDATA.lHScrollPos]
	Je > L4
	Invoke rsUpdateEditor, FALSE
	Invoke rsUpdateScrollBars
L4:	Mov Eax, [Ebx + EDITORDATA.dwEventMask]
	And Eax, EV_HSCROLL
	Jz >
	Mov Eax, EN_HSCROLL
	Shl Eax, 16
	Invoke SendMessage, [Ebx + EDITORDATA.hWndOwner], WM_COMMAND, Eax, [Ebx + EDITORDATA.hWnd]
:	Pop Edi
	Xor Eax, Eax
	Ret
EndU

OnVScroll: UseData RSEditProcedure
	Push Edi
	Invoke SetFocus, [hWnd]
	Mov Edi, [Ebx + EDITORDATA.lVScrollPos]
	LoWord ([wParam])
	Cmp Ax, SB_LINEUP
	Jne >
	Mov Eax, (-1)
	Jmp > L2
:	Cmp Ax, SB_LINEDOWN
	Jne >
	Mov Eax, 1
	Jmp > L2
:	Cmp Ax, SB_PAGEUP
	Jne >
	Mov Eax, [Ebx + EDITORDATA.lVScrollPage]
	Neg Eax
	Jmp > L2
:	Cmp Ax, SB_PAGEDOWN
	Jne >
	Mov Eax, [Ebx + EDITORDATA.lVScrollPage]
	Jmp > L2
:	Cmp Ax, SB_THUMBPOSITION
	Je >
	Cmp Ax, SB_THUMBTRACK
	Jne > L4
:	Invoke rsGetTrackPos, SB_VERT
	Sub Eax, [Ebx + EDITORDATA.lVScrollPos]
L2:	Invoke rsScroll, Eax, 0
	Cmp Edi, [Ebx + EDITORDATA.lVScrollPos]
	Je > L4
	Invoke rsUpdateEditor, FALSE
	Invoke rsUpdateScrollBars
L4:	Mov Eax, [Ebx + EDITORDATA.dwEventMask]
	And Eax, EV_VSCROLL
	Jz >
	Mov Eax, EN_VSCROLL
	Shl Eax, 16
	Invoke SendMessage, [Ebx + EDITORDATA.hWndOwner], WM_COMMAND, Eax, [Ebx + EDITORDATA.hWnd]
:	Pop Edi
	Xor Eax, Eax
	Ret
EndU

OnGetFont: UseData RSEditProcedure
	Mov Eax, [Ebx + EDITORDATA.hFont]
	Ret
EndU

OnGetText: UseData RSEditProcedure
	Mov Eax, [Ebx + EDITORDATA.lTextLength]
	Add Eax, 1
	Cmp [wParam], Eax
	Jle >
	Mov [wParam], Eax
:	Invoke lstrcpyn, [lParam], [Ebx + EDITORDATA.lpszText], [wParam]
	Mov Eax, [wParam]
	Ret
EndU

OnGetTextLength: UseData RSEditProcedure
	Mov Eax, [Ebx + EDITORDATA.lTextLength]
	Ret
EndU

OnSetFont: UseData RSEditProcedure
	Mov Eax, [wParam]
	Mov [Ebx + EDITORDATA.hFont], Eax
	Invoke GetDC, [hWnd]
	Mov [hdc], Eax
	Invoke SelectObject, [hdc], [Ebx + EDITORDATA.hFont]
	Cmp Eax, [Ebx + EDITORDATA.hFont]
	Je >
	Invoke DeleteObject, Eax
:	Invoke SetTextColor, [hdc], [Ebx + EDITORDATA.crTextColor]
	Lea Eax, [Ebx + EDITORDATA.szFont]
	Invoke GetTextExtentPoint32, [hdc], "W", 1, Eax
	Invoke ReleaseDC, [hWnd], [hdc]
	Mov Eax, [Ebx + EDITORDATA.szFont.cx]
	Mov Edx, 1024
	Mul Edx
	Mov [Ebx + EDITORDATA.lHScrollMax], Eax
	Cmp D[Ebx + EDITORDATA.lMarginWidth], (-1)
	Jne >
	Mov Eax, [Ebx + EDITORDATA.szFont.cx]
	Mov [Ebx + EDITORDATA.lMarginWidth], Eax
:	Mov Eax, [Ebx + EDITORDATA.lpszLine]
	Mov W[Eax], 0
	Invoke rsUpdateScrollBars
	Cmp D[lParam], 0
	Je >
	Invoke rsUpdateEditor, TRUE
:	Invoke DefWindowProc, [hWnd], [uMsg], [wParam], [lParam]
	Ret
EndU

OnSetText: UseData RSEditProcedure
	Invoke rsInitEditor, [lParam]
	Invoke rsUpdateScrollBars
	Invoke rsUpdateEditor, TRUE
	Invoke rsSetCaret
	Xor Eax, Eax
	Ret
EndU

OnCutCopy: UseData RSEditProcedure
	Local lpch:D

	Mov Eax, [Ebx + EDITORDATA.chrPos.lMax]
	Cmp Eax, [Ebx + EDITORDATA.chrPos.lMin]
	Jle >>
	Invoke OpenClipboard, [hWnd]
	Invoke EmptyClipboard
	Mov Eax, [Ebx + EDITORDATA.chrPos.lMax]
	Sub Eax, [Ebx + EDITORDATA.chrPos.lMin]
	Inc Eax
	Invoke GlobalAlloc, (GMEM_MOVEABLE Or GMEM_DDESHARE Or GMEM_ZEROINIT), Eax
	Mov [lTemp], Eax
	Invoke GlobalLock, [lTemp]
	Mov [lpch], Eax
	Invoke SendMessage, [hWnd], RSM_GETSELTEXT, 0, [lpch]
	Invoke GlobalUnlock, [lTemp]
	Invoke SetClipboardData, CF_TEXT, [lTemp]
	Invoke CloseClipboard
	Cmp D[uMsg], WM_CUT
	Jne >
	Lea Eax, [RSszChar]
	Mov W[Eax], 0
	Invoke rsReplaceSelection, Addr RSszChar, VK_DELETE
	Invoke rsSetFirstLineIndex
:	Xor Eax, Eax
	Ret
EndU

OnPaste: UseData RSEditProcedure
	Local lpch:D

	Invoke OpenClipboard, [hWnd]
	Or Eax, Eax
	Jz > L2
	Invoke GetClipboardData, CF_TEXT
	Mov [lTemp], Eax
	Cmp Eax, NULL
	Je >
	Invoke GlobalLock, [lTemp]
	Mov [lpch], Eax
	Invoke rsReplaceSelection, [lpch], 0
	Invoke rsSetFirstLineIndex
	Invoke GlobalUnlock, [lTemp]
:	Invoke CloseClipboard
L2:	Xor Eax, Eax
	Ret
EndU

OnUndo: UseData RSEditProcedure
	Invoke SendMessage, [hWnd], RSM_CANUNDO, 0, 0
	Or Eax, Eax
	Jz >
	Invoke rsUndoAction
:	Ret
EndU

OnCanPaste: UseData RSEditProcedure
	Invoke IsClipboardFormatAvailable, CF_TEXT
	Ret
EndU

OnCanRedo: UseData RSEditProcedure
	Cmp D[Ebx + EDITORDATA.lpUndoBuffer], NULL
	Jne >
	Xor Eax, Eax
	Ret
:	Push Edx
	Mov Eax, [Ebx + EDITORDATA.lUndoCount]
	Shl Eax, 2
	Add Eax, [Ebx + EDITORDATA.lpUndoBuffer]
	Cmp D[Eax], NULL
	Je >
	Mov Eax, TRUE
	Jmp > L2
:	Xor Eax, Eax
L2:	Pop Edx
	Ret
EndU

OnCanUndo: UseData RSEditProcedure
	Cmp D[Ebx + EDITORDATA.lpUndoBuffer], NULL
	Jne >
	Xor Eax, Eax
	Ret
:	Push Edx
	Mov Eax, [Ebx + EDITORDATA.lUndoCount]
	Or Eax, Eax
	Jnz >
	Mov Eax, [Ebx + EDITORDATA.lUndoLimit]
:	Dec Eax
	Shl Eax, 2
	Add Eax, [Ebx + EDITORDATA.lpUndoBuffer]
	Mov Edx, [Ebx + EDITORDATA.lpszUndoText]
	Cmp D[Eax], NULL
	Jne >
	Cmp B[Edx], 0
	Je > L2
:	Mov Eax, TRUE
	Jmp > L4
L2:	Xor Eax, Eax
L4:	Pop Edx
	Ret
EndU

OnClearUndoBuffer: UseData RSEditProcedure
	Invoke rsClearUndoBuffer
	Xor Eax, Eax
	Ret
EndU

OnFindWord: UseData RSEditProcedure
	Mov Eax, [Ebx + EDITORDATA.lTextLength]
	Cmp D[lParam], 0
	Jl > L2
	Cmp [lParam], Eax
	Jge > L2
	Cmp D[wParam], RSC_PREV
	Jne >
	Invoke rsFindPrevWord, [lParam]
	Ret
:	Cmp D[wParam], RSC_NEXT
	Jne > L2
	Invoke rsFindNextWord, [lParam]
	Ret
L2:	Mov Eax, (-1)
	Ret
EndU

OnFindText: UseData RSEditProcedure
	Invoke rsFindText, [wParam], [lParam]
	Ret
EndU

OnGetBackColor: UseData RSEditProcedure
	Mov Eax, [Ebx + EDITORDATA.crRealBackColor]
	Ret
EndU

OnGetEventMask: UseData RSEditProcedure
	Mov Eax, [Ebx + EDITORDATA.dwEventMask]
	Ret
EndU

OnGetFirstVisibleLine: UseData RSEditProcedure
	Mov Eax, [Ebx + EDITORDATA.lVScrollPos]
	Ret
EndU

OnGetHandle: UseData RSEditProcedure
	Mov Eax, [Ebx + EDITORDATA.lpszText]
	Ret
EndU

OnGetHideSelection: UseData RSEditProcedure
	Mov Eax, [Ebx + EDITORDATA.bHideSelection]
	Ret
EndU

OnGetLine: UseData RSEditProcedure
	Local lpch:D

	Mov Eax, [Ebx + EDITORDATA.lLines]
	Cmp [wParam], Eax
	Jl >
	Mov Eax, [lParam]
	Mov B[Eax], 0
	Mov D[lTemp], 0
	Jmp > L2
:	Invoke rsGetLineIndex, [wParam]
	Mov [lTemp], Eax
	Add Eax, [Ebx + EDITORDATA.lpszText]
	Mov [lpch], Eax
	Invoke rsGetNextLineIndex, [lTemp]
	Dec Eax
	Sub Eax, [lTemp]
	Mov [lTemp], Eax
	Cmp Eax, 0
	Jge >
	Xor Eax, Eax
	Ret
:	Inc D[lTemp]
	Invoke lstrcpyn, [lParam], [lpch], [lTemp]
	Dec D[lTemp]
L2:	Mov Eax, [lTemp]
	Ret
EndU

OnGetLineCount: UseData RSEditProcedure
	Mov Eax, [Ebx + EDITORDATA.lLines]
	Ret
EndU

OnGetLineFromChar: UseData RSEditProcedure
	Mov Eax, [Ebx + EDITORDATA.lTextLength]
	Cmp [lParam], Eax
	Jg > L2
	Cmp D[lParam], 0
	Jge > L4
L2:	Mov Eax, (-1)
	Ret
L4:	Invoke rsGetLineFromChar, [wParam], FALSE
	Ret
EndU

OnGetLineIndex: UseData RSEditProcedure
	Mov Eax, [Ebx + EDITORDATA.lLines]
	Cmp D[wParam], 0
	Jl > L2
	Cmp [wParam], Eax
	Jge > L2
	Invoke rsGetLineIndex, [wParam]
	Ret
L2:	Mov Eax, (-1)
	Ret
EndU

OnGetLineLength: UseData RSEditProcedure
	Cmp D[lParam], (-1)
	Jne >
	Invoke rsGetLineIndex, [wParam]
	Mov [lParam], Eax
:	Invoke rsGetLineLength, [lParam]
	Ret
EndU

OnGetModify: UseData RSEditProcedure
	Mov Eax, [Ebx + EDITORDATA.bModified]
	Ret
EndU

OnGetPosition: UseData RSEditProcedure
	Push Edx
	Cmp D[wParam], NULL
	Je >
	Mov Edx, [wParam]
	Mov Eax, [Ebx + EDITORDATA.lRealCol]
	Mov [Edx], Eax
:	Cmp D[lParam], NULL
	Je >
	Mov Edx, [lParam]
	Mov Eax, [Ebx + EDITORDATA.ptPos.y]
	Mov [Edx], Eax
:	Pop Edx
	Xor Eax, Eax
	Ret
EndU

OnGetSelBackColor: UseData RSEditProcedure
	Mov Eax, [Ebx + EDITORDATA.crRealBackSelect]
	Ret
EndU

OnGetMarginColor: UseData RSEditProcedure
	Mov Eax, [Ebx + EDITORDATA.crRealMarginColor]
	Ret
EndU

OnGetMarginWidth: UseData RSEditProcedure
	Mov Eax, [Ebx + EDITORDATA.lMarginWidth]
	Ret
EndU

OnGetSelection: UseData RSEditProcedure
	Push Edx
	Cmp D[wParam], NULL
	Je >
	Mov Edx, [wParam]
	Mov Eax, [Ebx + EDITORDATA.chrPos.lMin]
	Mov [Edx], Eax
:	Cmp D[lParam], NULL
	Je >
	Mov Edx, [lParam]
	Mov Eax, [Ebx + EDITORDATA.chrPos.lMax]
	Mov [Edx], Eax
:	Pop Edx
	Xor Eax, Eax
	Ret
EndU

OnGetSelText: UseData RSEditProcedure
	Mov Eax, [Ebx + EDITORDATA.chrPos.lMax]
	Sub Eax, [Ebx + EDITORDATA.chrPos.lMin]
	Inc Eax
	Mov [lTemp], Eax
	Mov Eax, [Ebx + EDITORDATA.lpszText]
	Add Eax, [Ebx + EDITORDATA.chrPos.lMin]
	Invoke lstrcpyn, [lParam], Eax, [lTemp]
	Dec D[lTemp]
	Mov Eax, [lTemp]
	Ret
EndU

OnGetSelTextColor: UseData RSEditProcedure
	Mov Eax, [Ebx + EDITORDATA.crRealTextSelect]
	Ret
EndU

OnGetTextColor: UseData RSEditProcedure
	Mov Eax, [Ebx + EDITORDATA.crRealTextColor]
	Ret
EndU

OnEditorScroll: UseData RSEditProcedure
	Invoke rsScroll, [lParam], [wParam]
	Invoke rsSetCaret
	Invoke rsUpdateEditor, FALSE
	Invoke rsUpdateScrollBars
	Xor Eax, Eax
	Ret
EndU

OnReplaceSel: UseData RSEditProcedure
	Invoke rsReplaceSelection, [lParam], 0
	Xor Eax, Eax
	Ret
EndU

OnRedo: UseData RSEditProcedure
	Invoke SendMessage, [hWnd], RSM_CANREDO, 0, 0
	Or Eax, Eax
	Jz >
	Invoke rsRedoAction
:	Ret
EndU

OnSetAutoIndent: UseData RSEditProcedure
	Mov Eax, [wParam]
	Mov [Ebx + EDITORDATA.bAutoIndent], Eax
	Xor Eax, Eax
	Ret
EndU

OnSetBackColor: UseData RSEditProcedure
	Mov Eax, [lParam]
	Mov [Ebx + EDITORDATA.crRealBackColor], Eax
	Invoke rsChangeControlColors, 1
	Xor Eax, Eax
	Ret
EndU

OnSetCaretWidth: UseData RSEditProcedure
	Mov Eax, [lParam]
	Cmp Eax, 0
	Jg >
	Ret
:	Cmp Eax, 6
	Jl >
	Ret
:	Mov [Ebx + EDITORDATA.lCaretWidth], Eax
	Invoke rsDisplayCursor
	Xor Eax, Eax
	Ret
EndU

OnSetEventMask: UseData RSEditProcedure
	Mov Eax, [lParam]
	Mov [Ebx + EDITORDATA.dwEventMask], Eax
	Invoke rsUpdateEditor, TRUE
	Xor Eax, Eax
	Ret
EndU

OnSetFindProc: UseData RSEditProcedure
	Mov Eax, [lParam]
	Mov [Ebx + EDITORDATA.prFindProc], Eax
	Invoke rsUpdateEditor, TRUE
	Lea Eax, [rsFindHook]
	Ret
EndU

OnSetHideSelection: UseData RSEditProcedure
	Mov Eax, [wParam]
	Mov [Ebx + EDITORDATA.bHideSelection], Eax
	Invoke rsUpdateEditor, TRUE
	Xor Eax, Eax
	Ret
EndU

OnSetHScrollBar: UseData RSEditProcedure
	Invoke GetWindowLong, [hWnd], GWL_STYLE
	Cmp D[wParam], 0
	Je >
	Or Eax, WS_HSCROLL
	Mov D[Ebx + EDITORDATA.bHScrollBar], TRUE
	Jmp > L2
:	Mov Ecx, WS_HSCROLL
	Not Ecx
	And Eax, Ecx
	Mov D[Ebx + EDITORDATA.bHScrollBar], FALSE
L2:	Invoke SetWindowLong, [hWnd], GWL_STYLE, Eax
	Invoke SetWindowPos, [hWnd], 0, 0, 0, 0, 0, (SWP_NOZORDER Or SWP_NOMOVE Or SWP_NOSIZE Or SWP_FRAMECHANGED)
	Invoke rsUpdateScrollBars
	Invoke rsUpdateEditor, FALSE
	Ret
EndU

OnSetModify: UseData RSEditProcedure
	Mov Eax, [wParam]
	Mov [Ebx + EDITORDATA.bModified], Eax
	Mov Eax, [Ebx + EDITORDATA.lUndoCount]
	Mov [Ebx + EDITORDATA.lStartModified], Eax
	Xor Eax, Eax
	Ret
EndU

OnSetPaintProc: UseData RSEditProcedure
	Mov Eax, [lParam]
	Mov [Ebx + EDITORDATA.prPaintProc], Eax
	Lea Eax, [rsPaintEditor]
	Invoke rsUpdateEditor, TRUE
	Ret
EndU

OnSetReadOnly: UseData RSEditProcedure
	Mov Eax, [wParam]
	Mov [Ebx + EDITORDATA.bReadOnly], Eax
	Or Eax, Eax
	Jz >
	Invoke DestroyCaret
	Jmp > L2
:	Invoke rsDisplayCursor
L2:	Invoke rsUpdateEditor, TRUE
	Xor Eax, Eax
	Ret
EndU

OnSetSelBackColor: UseData RSEditProcedure
	Mov Eax, [lParam]
	Mov [Ebx + EDITORDATA.crRealBackSelect], Eax
	Invoke rsChangeControlColors, 8
	Xor Eax, Eax
	Ret
EndU

OnSetMarginColor: UseData RSEditProcedure
	Mov Eax, [lParam]
	Mov [Ebx + EDITORDATA.crRealMarginColor], Eax
	Invoke rsChangeControlColors, 8
	Xor Eax, Eax
	Ret
EndU

OnSetMarginWidth: UseData RSEditProcedure
	Mov Eax, [lParam]
	Cmp Eax, 0
	Jl > L2
	Mov [Ebx + EDITORDATA.lMarginWidth], Eax
	Invoke rsUpdateEditor, TRUE
	Xor Eax, Eax
	Ret
L2:	Mov Eax, (-1)
	Ret
EndU

OnSetSelection: UseData RSEditProcedure
	Push Ecx
	Mov Ecx, [Ebx + EDITORDATA.lTextLength]
	Mov Eax, [wParam]
	Cmp D[lParam], 0
	Jge >
	Mov [lParam], Eax
:	Cmp [lParam], Ecx
	Jle >
	Mov [lParam], Eax
:	Mov Eax, [lParam]
	Cmp D[wParam], 0
	Jge >
	Mov [wParam], Eax
:	Cmp [wParam], Ecx
	Jle >
	Mov [wParam], Eax
:	Pop Ecx
	Mov D[Ebx + EDITORDATA.bSelCol], TRUE
	Mov Eax, [Ebx + EDITORDATA.lpszText]
	Push Eax
	Add Eax, [wParam]
	Cmp B[Eax], 10
	Jne >
	Inc D[wParam]
:	Pop Eax
	Add Eax, [lParam]
	Cmp B[Eax], 10
	Jne >
	Inc D[lParam]
:	Invoke rsSetSelection, [wParam], [lParam]
	Push Ecx
	Mov Eax, [Ebx + EDITORDATA.chrPos.lMax]
	Sub Eax, [Ebx + EDITORDATA.chrPos.lMin]
	Mov Ecx, [Ebx + EDITORDATA.ptPos.x]
	Sub Ecx, Eax
	Pop Ecx
	Xor Eax, Eax
	Ret
EndU

OnSetSelTextColor: UseData RSEditProcedure
	Mov Eax, [lParam]
	Mov [Ebx + EDITORDATA.crRealTextSelect], Eax
	Invoke rsChangeControlColors, 16
	Xor Eax, Eax
	Ret
EndU

OnSetTabStops: UseData RSEditProcedure
	Cmp D[wParam], 0
	Jle >
	Cmp D[wParam], 16
	Jg >
	Mov Eax, [wParam]
	Mov [Ebx + EDITORDATA.lTabStops], Eax
	Invoke rsUpdateEditor, TRUE
:	Xor Eax, Eax
	Ret
EndU

OnSetTextColor: UseData RSEditProcedure
	Mov Eax, [lParam]
	Mov [Ebx + EDITORDATA.crRealTextColor], Eax
	Invoke rsChangeControlColors, 4
	Xor Eax, Eax
	Ret
EndU

OnSetUndoLimit: UseData RSEditProcedure
	Invoke rsClearUndoBuffer
	Cmp D[Ebx + EDITORDATA.lpUndoBuffer], NULL
	Je >
	Invoke GlobalFree, [Ebx + EDITORDATA.lpUndoBuffer]
	Mov D[Ebx + EDITORDATA.lpUndoBuffer], Eax
:	Mov Eax, [wParam]
	And Eax, 0FFFFH
	Mov [Ebx + EDITORDATA.lUndoLimit], Eax
	Or Eax, Eax
	Jz >
	Shl Eax, 2
	Add Eax, 4
	Push Eax
	Add Eax, 256
	Invoke GlobalAlloc, GPTR, Eax
	Mov [Ebx + EDITORDATA.lpUndoBuffer], Eax
	Pop Edx
	Add Eax, Edx
	Mov [Ebx + EDITORDATA.lpszUndoText], Eax
	Mov W[Eax], 0
	Xor Eax, Eax
:	Ret
EndU

OnSetVScrollBar: UseData RSEditProcedure
	Invoke GetWindowLong, [hWnd], GWL_STYLE
	Cmp D[wParam], 0
	Je >
	Or Eax, WS_VSCROLL
	Mov D[Ebx + EDITORDATA.bVScrollBar], TRUE
	Jmp > L2
:	Mov Ecx, WS_VSCROLL
	Not Ecx
	And Eax, Ecx
	Mov D[Ebx + EDITORDATA.bVScrollBar], FALSE
L2:	Invoke SetWindowLong, [hWnd], GWL_STYLE, Eax
	Invoke SetWindowPos, [hWnd], 0, 0, 0, 0, 0, (SWP_NOZORDER Or SWP_NOMOVE Or SWP_NOSIZE Or SWP_FRAMECHANGED)
	Invoke rsUpdateScrollBars
	Invoke rsUpdateEditor, FALSE
	Ret
EndU

OnSysColorChange: UseData RSEditProcedure
	Invoke rsChangeControlColors, 31
	Xor Eax, Eax
	Ret
EndU

OnTimer: UseData RSEditProcedure
	Local pt:POINTL

	Invoke GetCursorPos, Addr pt
	Invoke ScreenToClient, [Ebx + EDITORDATA.hWnd], Addr pt
	Mov Eax, [pt.y]
	Shl Eax, 16
	Test D[pt.y], 80000000H
	Jz >
	Or Eax, 80000000H
:	Mov Edx, [pt.x]
	Test D[pt.x], 80000000H
	Jz >
	Or Dx, 8000H
:	Or Ax, Dx
	Invoke PostMessage, [Ebx + EDITORDATA.hWnd], WM_MOUSEMOVE, MK_LBUTTON, Eax
	Xor Eax, Eax
	Ret
EndU

OnSize: UseData RSEditProcedure
	Invoke DefWindowProc, [hWnd], [uMsg], [wParam], [lParam]
	LoWord ([lParam])
	Mov [Ebx + EDITORDATA.szSize.cx], Eax
	Sub Eax, [Ebx + EDITORDATA.lMarginWidth]
	Mov [Ebx + EDITORDATA.lHScrollPage], Eax
	HiWord ([lParam])
	Mov [Ebx + EDITORDATA.szSize.cy], Eax
	Xor Edx, Edx
	Div D[Ebx + EDITORDATA.szFont.cy]
	Mov [Ebx + EDITORDATA.lVScrollPage], Eax
	Add Eax, [Ebx + EDITORDATA.lVScrollPos]
	Cmp Eax, [Ebx + EDITORDATA.lLines]
	Jle >
	Mov Eax, [Ebx + EDITORDATA.lLines]
	Cmp Eax, 1
	Je >
	Sub Eax, [Ebx + EDITORDATA.lVScrollPage]
	Sub Eax, [Ebx + EDITORDATA.lVScrollPos]
	Invoke rsScroll, Eax, 0
:	Invoke rsUpdateScrollBars
	Invoke rsUpdateEditor, FALSE
	Xor Eax, Eax
	Ret
EndU

OnNcDestroy: UseData RSEditProcedure
	Invoke DeleteObject, [Ebx + EDITORDATA.hFont]
	Invoke rsClearUndoBuffer
	Invoke GlobalFree, [Ebx + EDITORDATA.lpszLine]
	Invoke GlobalFree, [Ebx + EDITORDATA.lpUndoBuffer]
	Invoke VirtualFree, [Ebx + EDITORDATA.lpszMemPtr], 0, MEM_RELEASE
	Invoke GlobalFree, Ebx
	Invoke DefWindowProc, [hWnd], [uMsg], [wParam], [lParam]
	Ret
EndU

;===========================================================================;
; Name:		rsCreateEditor                                                  ;
;                                                                           ;
; Function:	Creates a new instance of the RS Edit control                   ;
;                                                                           ;
; Params:  	hwndParent = Handle of the parent                               ;
;          	dwStyle    = Normal style (WS_CHILD, WS_VISIBLE, etc.)          ;
;          	dwExStyle  = Extended style (WS_EX_CLIENTEDGE, etc.)            ;
;          	lLeft      = X position (in pixels)                             ;
;          	lTop       = Y position (in pixels)                             ;
;          	lWidth     = Width (in pixels)                                  ;
;          	lHeight    = Height (in pixels)                                 ;
;                                                                           ;
; Returns: The handle of the new created control in Eax                     ;
;===========================================================================;
Export rsCreateEditor Frame hwndParent, dwStyle, dwExStyle, lLeft, lTop, lWidth, lHeight Uses Ecx, Edx
	Or D[dwStyle], WS_CHILD
	Invoke CreateWindowEx, [dwExStyle], Offset RSszEditClass, \
		   NULL, [dwStyle], [lLeft], [lTop], [lWidth], [lHeight], \
		   [hwndParent], NULL, [RShInst], NULL
	Ret
EndF

;===========================================================================;
; Name:		rsChangeControlColors                                           ;
;                                                                           ;
; Function:	Changes one or more of the RS Edit control colors               ;
;                                                                           ;
; Params:	lFlags  = Colors that must be changed                           ;
;                                                                           ;
; On enter:  Ebx = Pointer to editor's data structure                       ;
;                                                                           ;
; Bits meaning:		0 = 1 -> Changes the editor background                  ;
;                	1 = 1 -> Changes the selection bar background           ;
;                	2 = 1 -> Changes the editor text color                  ;
;                	3 = 1 -> Changes the editor selection background        ;
;                	4 = 1 -> Changes the editor selection text color        ;
;===========================================================================;
rsChangeControlColors Frame lFlags
	Mov Eax, [lFlags]
	And Eax, 1
	Jz > L2
	Mov Eax, [Ebx + EDITORDATA.crRealBackColor]
	Cmp Eax, 0
	Jge >
	And Eax, 0FFH
	Invoke GetSysColor, Eax
:	Mov [Ebx + EDITORDATA.crBackColor], Eax
L2:	Mov Eax, [lFlags]
	And Eax, 2
	Jz > L4
	Mov Eax, [Ebx + EDITORDATA.crRealMarginColor]
	Cmp Eax, 0
	Jge >
	And Eax, 0FFH
	Invoke GetSysColor, Eax
:	Mov [Ebx + EDITORDATA.crMarginColor], Eax
L4:	Mov Eax, [lFlags]
	And Eax, 4
	Jz > L6
	Mov Eax, [Ebx + EDITORDATA.crRealTextColor]
	Cmp Eax, 0
	Jge >
	And Eax, 0FFH
	Invoke GetSysColor, Eax
:	Mov [Ebx + EDITORDATA.crTextColor], Eax
L6:	Mov Eax, [lFlags]
	And Eax, 8
	Jz > L8
	Mov Eax, [Ebx + EDITORDATA.crRealBackSelect]
	Cmp Eax, 0
	Jge >
	And Eax, 0FFH
	Invoke GetSysColor, Eax
:	Mov [Ebx + EDITORDATA.crBackSelect], Eax
L8:	Mov Eax, [lFlags]
	And Eax, 16
	Jz > L10
	Mov Eax, [Ebx + EDITORDATA.crRealTextSelect]
	Cmp Eax, 0
	Jge >
	And Eax, 0FFH
	Invoke GetSysColor, Eax
:	Mov [Ebx + EDITORDATA.crTextSelect], Eax
L10:
	Invoke rsUpdateEditor, TRUE
	Ret
EndF

;On enter Ebx = Pointer to editor's data structure
rsCheckFirstLine:
	Mov Eax, [Ebx + EDITORDATA.lVScrollPos]
	Or Eax, Eax
	Jz >
	Add Eax, [Ebx + EDITORDATA.lVScrollPage]
	Cmp Eax, [Ebx + EDITORDATA.lLines]
	Jl >
	Mov Eax, [Ebx + EDITORDATA.lLines]
	Sub Eax, [Ebx + EDITORDATA.lVScrollPage]
	Jl >
	Mov [Ebx + EDITORDATA.lVScrollPos], Eax
:	Ret

;===========================================================================;
; Name:		rsCheckModified                                                 ;
;                                                                           ;
; Function:	Checks if text is unmodified due to undo / redo operations      ;
;                                                                           ;
; On enter:  Ebx = Pointer to editor's data structure                       ;
;===========================================================================;
rsCheckModified:
	Mov Eax, [Ebx + EDITORDATA.lUndoCount]
	Cmp Eax, [Ebx + EDITORDATA.lStartModified]
	Jne >
	Mov D[Ebx + EDITORDATA.bModified], FALSE
	Mov D[Ebx + EDITORDATA.bChanged], FALSE
:	Ret

;On enter: Ebx = Pointer to editor's data structure
rsCheckForScrollTimer Frame bHorzChecking
	Local pt:POINTL, rc:RECT

	Invoke GetClientRect, [Ebx + EDITORDATA.hWnd], Addr rc
	Invoke GetCursorPos, Addr pt
	Invoke ScreenToClient, [Ebx + EDITORDATA.hWnd], Addr pt
	Mov Eax, [pt.y]
	Cmp Eax, [rc.bottom]
	Jl > L5
	Sub Eax, [rc.bottom]
L2:	Mov Ecx, 100
	Cmp Eax, [Ebx + EDITORDATA.szFont.cy]
	Jl > L3
	Mov Ecx, 50
L3:	Cmp D[Ebx + EDITORDATA.bTimer], 0
	Je > L4
	Cmp [Ebx + EDITORDATA.bTimer], Ecx
	Jne >
	Ret
:	Push Ecx
	Call rsKillScrollTimer
	Pop Ecx
L4:	Mov [Ebx + EDITORDATA.bTimer], Ecx
	Invoke SetTimer, [Ebx + EDITORDATA.hWnd], 10, Ecx, NULL
	Ret
L5:	Cmp Eax, 0
	Jg >
	Neg Eax
	Jmp < L2
:	Cmp D[bHorzChecking], FALSE
	Je > L10
	Mov Eax, [pt.x]
	Cmp Eax, [rc.right]
	Jl > L8
	Sub Eax, [rc.right]
L6:	Mov Ecx, 100
	Cmp Eax, [Ebx + EDITORDATA.szFont.cx]
	Jl < L3
	Mov Ecx, 50
	Jmp < L3
L8:	Cmp Eax, [Ebx + EDITORDATA.lMarginWidth]
	Jg > L10
	Sub Eax, [Ebx + EDITORDATA.lMarginWidth]
	Neg Eax
	Jmp < L6
L10:
	Call rsKillScrollTimer
	Ret
EndF

;===========================================================================;
; Name:		rsClearNextUndoEntry                                            ;
;                                                                           ;
; Function:	Clears the undo entry specified by the 'lpUndoCount' member of  ;
;           the RS Edit control's data structure                            ;
;                                                                           ;
; On enter:  Ebx = Pointer to editor's data structure                       ;
;===========================================================================;
rsClearNextUndoEntry: Uses Edx, Esi
	Cmp D[Ebx + EDITORDATA.lpUndoBuffer], NULL
	Je >
	Mov Esi, [Ebx + EDITORDATA.lpUndoBuffer]
	Mov Eax, [Ebx + EDITORDATA.lUndoCount]
	Shl Eax, 2
	Add Esi, Eax
	Cmp D[Esi], NULL
	Je >
	Invoke GlobalFree, [Esi]
	Mov D[Esi], NULL
:	Ret
EndU

;===========================================================================;
; Name:		rsClearUndoBuffer                                               ;
;                                                                           ;
; Function:	Clears the undo/redo buffer                                     ;
;                                                                           ;
; On enter:  Ebx = Pointer to editor's data structure                       ;
;===========================================================================;
rsClearUndoBuffer: Uses Esi
	Cmp D[Ebx + EDITORDATA.lpUndoBuffer], NULL
	Je > L4
	Mov Esi, [Ebx + EDITORDATA.lpUndoBuffer]
	Mov Eax, [Ebx + EDITORDATA.lUndoLimit]
	Or Eax, Eax
	Jnz > L2
	Ret
L2:	Push Eax
	Cmp D[Esi], NULL
	Je >
	Invoke GlobalFree, [Esi]
	Mov [Esi], Eax
:	Add Esi, 4
	Pop Eax
	Dec Ax
	Jnz < L2
	Mov D[Ebx + EDITORDATA.lUndoCount], 0
	Mov D[Ebx + EDITORDATA.lUndoStart], (-1)
	Mov Eax, [Ebx + EDITORDATA.lpszUndoText]
	Mov W[Eax], 0
L4:	Ret
EndU

;===========================================================================;
; Name:		rsCopyString                                                    ;
;                                                                           ;
; Function:	Copies an ASCIIZ string into another                            ;
;                                                                           ;
; Params:  lpDest = Destination address of the copy                         ;
;          lpSource = Source address of the copy                            ;
;                                                                           ;
; Returns: The length of the copied string in Eax                           ;
;===========================================================================;
rsCopyString Frame lpDest, lpSource Uses Edi, Esi
	Mov Esi, [lpSource]
	Mov Edi, [lpDest]
	Or Esi, Esi
	Jnz >
	Mov Eax, Esi
	Ret
:	Mov Al, [Esi]
	Inc Esi
	Mov [Edi], Al
	Inc Edi
	Or Al, Al
	Jnz <
	Dec Edi
	Sub Edi, [lpDest]
	Mov Eax, Edi
	Ret
EndF

;===========================================================================;
; Name:		rsDecrementUndoCount                                            ;
;                                                                           ;
; Function:	Decrements the undo / redo operations count                     ;
;                                                                           ;
; On enter:  Ebx = Pointer to editor's data structure                       ;
;===========================================================================;
rsDecrementUndoCount:
	Cmp D[Ebx + EDITORDATA.lUndoCount], 0
	Jle >
	Dec D[Ebx + EDITORDATA.lUndoCount]
	Mov Eax, [Ebx + EDITORDATA.lUndoCount]
	Shl Eax, 2
	Add Eax, [Ebx + EDITORDATA.lpUndoBuffer]
	Cmp D[Eax], NULL
	Jne > L2
	Inc D[Ebx + EDITORDATA.lUndoCount]
	Mov Eax, FALSE
	Jmp > L2
:	Mov Eax, [Ebx + EDITORDATA.lUndoLimit]
	Dec Eax
	Mov [Ebx + EDITORDATA.lUndoCount], Eax
	Shl Eax, 2
	Add Eax, [Ebx + EDITORDATA.lpUndoBuffer]
	Cmp D[Eax], NULL
	Jne > L2
	Mov D[Ebx + EDITORDATA.lUndoCount], 0
	Mov Eax, FALSE
L2:	Ret

;===========================================================================;
; Name:		rsDisplayCursor                                                 ;
;                                                                           ;
; Function:	Creates a caret and displays it on the screen                   ;
;                                                                           ;
; On enter:  Ebx = Pointer to editor's data structure                       ;
;===========================================================================;
rsDisplayCursor:
	Cmp D[Ebx + EDITORDATA.bReadOnly], 0
	Jne >
	Invoke CreateCaret, [Ebx + EDITORDATA.hWnd], NULL, [Ebx + EDITORDATA.lCaretWidth], [Ebx + EDITORDATA.szFont.cy]
	Mov D[Ebx + EDITORDATA.bCaret], FALSE
	Invoke rsSetCaret
:	Ret

;===========================================================================;
; Name:	    rsExpandLineAndGetSelection                                     ;
;                                                                           ;
; Function: Gets the line in the 'lpszLine' member buffer of the RS Edit    ;
;           control data structure, with expanded tabs, ready to be painted ;
;                                                                           ;
; Params:   lIndex = Character index of the line to be retreived            ;
;           lpChr  = Address of a CHARSEL structure                         ;
;                                                                           ;
; On enter: Ebx = Pointer to editor's data structure                        ;
;                                                                           ;
; Returns: The length of the expanded line in Eax                           ;
;===========================================================================;
rsExpandLineAndGetSelection Frame lIndex, lpChr Uses Ecx, Edx, Esi, Edi
	Local l1:D, lLength:D
	Local lMin:D, lMax:D
	Local bMin:D, bMax:D

	Mov D[bMin], FALSE
	Mov D[bMax], FALSE
	Mov Edi, [lpChr]
	Invoke rsGetLineLength, [lIndex]
	Mov [l1], Eax
	Cmp Eax, 1024
	Jle >
	Mov D[l1], 1024
:	Or Edi, Edi
	Jz >> L4
	Mov Eax, [Ebx + EDITORDATA.lRealCol]
	Mov [Edi + RSSCHARSEL.lMin], Eax
	Mov [Edi + RSSCHARSEL.lMax], Eax
	Mov Eax, [Ebx + EDITORDATA.chrPos.lMin]
	Cmp Eax, [Ebx + EDITORDATA.chrPos.lMax]
	Jge >> L4
	Mov Ecx, [lIndex]
	Add Ecx, [l1]
	Cmp Eax, [lIndex]
	Jl > L2
	Cmp Eax, Ecx
	Jge > L2
	Mov D[bMin], TRUE
	Mov D[bMax], TRUE
	Mov D[Edi + RSSCHARSEL.lMin], 0
	Cmp [lIndex], Eax
	Jge >
	Sub Eax, [lIndex]
	Mov [Edi + RSSCHARSEL.lMin], Eax
:	Cmp [Ebx + EDITORDATA.chrPos.lMax], Ecx
	Jl >
	Mov Eax, [l1]
	Mov [Edi + RSSCHARSEL.lMax], Eax
	Jmp > L4
:	Mov Eax, [Ebx + EDITORDATA.chrPos.lMax]
	Sub Eax, [lIndex]
	Mov [Edi + RSSCHARSEL.lMax], Eax
	Jmp > L4
L2:	Mov Eax, [Ebx + EDITORDATA.chrPos.lMax]
	Cmp Eax, [lIndex]
	Jle >
	Cmp Eax, Ecx
	Jg >
	Mov D[bMin], TRUE
	Mov D[bMax], TRUE
	Mov D[Edi + RSSCHARSEL.lMin], 0
	Sub Eax, [lIndex]
	Mov [Edi + RSSCHARSEL.lMax], Eax
	Jmp > L4
:	Mov Eax, [Ebx + EDITORDATA.chrPos.lMin]
	Cmp Eax, [lIndex]
	Jg > L4
	Cmp [Ebx + EDITORDATA.chrPos.lMax], Ecx
	Jl > L4
	Mov D[bMin], TRUE
	Mov D[bMax], TRUE
	Mov D[Edi + RSSCHARSEL.lMin], 0
	Mov Eax, [l1]
	Mov [Edi + RSSCHARSEL.lMax], Eax
L4:	Mov D[lLength], 0
	Mov Esi, [Ebx + EDITORDATA.lpszText]
	Add Esi, [lIndex]
	Mov Edx, [Ebx + EDITORDATA.lpszLine]
	Cmp D[l1], 0
	Jne >
	Mov D[Ebx + EDITORDATA.lRealCol], 0
	Jmp >> L12
:	Xor Ecx, Ecx
L6:	Cmp Ecx, [l1]
	Jge > L10
	Cmp D[bMin], FALSE
	Je >
	Cmp [Edi + RSSCHARSEL.lMin], Ecx
	Jne >
	Mov D[bMin], FALSE
	Mov Eax, [lLength]
	Mov [Edi + RSSCHARSEL.lMin], Eax
:	Cmp D[bMax], FALSE
	Je >
	Cmp [Edi + RSSCHARSEL.lMax], Ecx
	Jne >
	Mov D[bMax], FALSE
	Mov Eax, [lLength]
	Mov [Edi + RSSCHARSEL.lMax], Eax
:	Mov Eax, [Ebx + EDITORDATA.ptPos.x]
	Cmp Ecx, Eax
	Jne >
	Mov Eax, [lLength]
	Mov [Ebx + EDITORDATA.lRealCol], Eax
:	Mov Al, [Esi + Ecx]
	Cmp Al, 9
	Jne >
	Invoke rsExpandTabStops, Addr lLength
	Jmp > L8
:	Mov [Edx], Al
	Inc Edx
	Inc D[lLength]
L8:	Inc Ecx
	Jmp < L6
L10:
	Cmp B[Edx - 1], 13
	Jne >
	Mov B[Edx - 1], ' '
:	Cmp D[bMax], 0
	Je > L12
	Cmp D[Edi + RSSCHARSEL.lMax], Ecx
	Jne > L12
	Mov Eax, [lLength]
	Mov [Edi + RSSCHARSEL.lMax], Eax
L12:
	Mov B[Edx], 0
	Mov Eax, [lLength]
	Ret
EndF

;===========================================================================;
; Name:		rsExpandTabStops                                                ;
;                                                                           ;
; Function:	Converts tabs to spaces                                         ;
;                                                                           ;
; Params:	lpszLine   = Address ob buffer to store spaces                  ;
;          	lpLength   = Address of the current length of lpszLine          ;
;                                                                           ;
; Remarks:	Ebx must point to the RS Edit control's data structure    		;
;  			Edx must point to expanded tabs buffer (lpszLine+length)  		;
;===========================================================================;
rsExpandTabStops Frame lpLength Uses Ecx, Esi
	Mov Esi, [lpLength]
	Mov Eax, [Esi]
	Mov Ecx, [Ebx + EDITORDATA.lTabStops]
	Dec Ecx
	And Eax, Ecx
	Inc Ecx
	Sub Ecx, Eax
	Add [Esi], Ecx
:	Mov B[Edx], ' '
	Inc Edx
	Dec Ecx
	Jnz <
	Ret
EndF

;===========================================================================;
; Name:		rsFindFirstChar                                                 ;
;                                                                           ;
; Function:	Finds the first character not being a control character         ;
;                                                                           ;
; On enter:  Ebx = Pointer to editor's data structure                       ;
;                                                                           ;
; Returns: The zero based position of the character inside the line in Eax  ;
;===========================================================================;
rsFindFirstChar: Uses Esi
	Mov Esi, [Ebx + EDITORDATA.lpszText]
	Add Esi, [Ebx + EDITORDATA.lLineIndex]
	Push Esi
:	Mov Al, [Esi]
	Or Al, Al
	Jz >
	Cmp Al, 13
	Je >
	Cmp Al, ' '
	Jg >
	Inc Esi
	Jmp <
:	Mov Eax, Esi
	Pop Esi
	Sub Eax, Esi
	Cmp Eax, [Ebx + EDITORDATA.ptPos.x]
	Jne >
	Xor Eax, Eax
:	Ret
EndU

;===========================================================================;
; Name:		rsFindHook                                                      ;
;                                                                           ;
; Function:	Called by 'rsIsAlpha' procedure. It can be subclassed by user   ;
;           to decide which characters are treated like a word break        ;
;                                                                           ;
; Params:	chr = Character to be compared to                               ;
;                                                                           ;
; Returns:  TRUE  = Character is treated like part of word (no word-break)  ;
;           FALSE = Character is interpreted like a word-break              ;
;===========================================================================;
rsFindHook Frame chr
	Xor Eax, Eax
	Ret
EndF

;===========================================================================;
; Name:		rsFindNextWord                                                  ;
;                                                                           ;
; Function:	Finds the next word after the cursor                            ;
;                                                                           ;
; Params:	lIndex = Current character index (where the cursor is)          ;
;                                                                           ;
; On enter:  Ebx = Pointer to editor's data structure                       ;
;                                                                           ;
; Returns: The character index of the next word in Eax                      ;
;===========================================================================;
rsFindNextWord Frame lIndex Uses Ecx, Esi
	Mov Eax, [Ebx + EDITORDATA.lTextLength]
	Cmp [lIndex], Eax
	Jl >
	Ret
:	Xor Ecx, Ecx
	Mov Esi, [Ebx + EDITORDATA.lpszText]
	Add Esi, [lIndex]
	Cmp B[Esi], 13
	Jne >
	Mov Ecx, 2
	Cmp B[Esi + Ecx], 0
	Je > L8
	Cmp B[Esi + Ecx], 9
	Je >
	Cmp B[Esi + Ecx], ' '
	Jne > L8
:	Invoke rsIsAlphaNumeric, [Esi + Ecx]
	Or Eax, Eax
	Jz > L2
:	Inc Ecx
	Invoke rsIsAlphaNumeric, [Esi + Ecx]
	Or Eax, Eax
	Jnz <
	Jmp > L6
L2:	Cmp B[Esi + Ecx], 9
	Je > L6
	Cmp B[Esi + Ecx], ' '
	Je > L6
	Cmp B[Esi + Ecx], 13
	Je > L6
L4:	Or Eax, Eax
	Jnz > L6
	Cmp B[Esi + Ecx], ' '
	Je > L6
	Cmp B[Esi + Ecx], 9
	Je > L6
	Cmp B[Esi + Ecx], 0
	Je > L8
	Cmp B[Esi + Ecx], 10
	Jne >
	Inc Ecx
	Jmp > L8
:	Inc Ecx
	Invoke rsIsAlphaNumeric, [Esi + Ecx]
	Jmp < L4
L6:	Cmp B[Esi + Ecx], 9
	Je >
	Cmp B[Esi + Ecx], ' '
	Jne > L8
:	Inc Ecx
	Jmp < L6
L8:	Mov Eax, Esi
	Add Eax, Ecx
	Sub Eax, [Ebx + EDITORDATA.lpszText]
	Ret
EndF

;===========================================================================;
; Name:		rsFindPrevWord                                                  ;
;                                                                           ;
; Function:	Finds the previous word before the cursor                       ;
;                                                                           ;
; Params:	lIndex = Current character index (where the cursor is)          ;
;                                                                           ;
; On enter:  Ebx = Pointer to editor's data structure                       ;
;                                                                           ;
; Returns: The character index of the previous word in Eax                  ;
;===========================================================================;
rsFindPrevWord Frame lIndex Uses Ecx, Esi
	Cmp D[lIndex], 1
	Jg >
	Xor Eax, Eax
	Ret
:	Mov Esi, [Ebx + EDITORDATA.lpszText]
	Mov Ecx, [lIndex]
	Dec Ecx
	Cmp B[Esi + Ecx], 10
	Jne > L2
	Dec Ecx
	Jnz >
	Mov Eax, Ecx
	Ret
:	Dec Ecx
L2:	Cmp B[Esi + Ecx], 9
	Je <
	Cmp B[Esi + Ecx], ' '
	Je <
	Cmp B[Esi + Ecx], 10
	Je > L6
	Invoke rsIsAlphaNumeric, [Esi + Ecx]
	Or Eax, Eax
	Jnz > L4
:	Dec Ecx
	Invoke rsIsAlphaNumeric, [Esi + Ecx]
	Or Eax, Eax
	Jnz > L6
	Cmp B[Esi + Ecx], 9
	Je > L6
	Cmp B[Esi + Ecx], ' '
	Je > L6
	Cmp B[Esi + Ecx], 10
	Je > L6
	Cmp B[Esi + Ecx], 13
	Jne <
	Inc Ecx
	Jmp > L6
L4:	Dec Ecx
	Invoke rsIsAlphaNumeric, [Esi + Ecx]
	Or Eax, Eax
	Jz > L6
	Cmp B[Esi + Ecx], 10
	Jne < L4
L6:	Mov Eax, Ecx
	Inc Eax
	Ret
EndF

;===========================================================================;
; Name:		rsFindText                                                      ;
;                                                                           ;
; Function:	Finds text according to an RSSFINDTEXT structure 		       	;
;                                                                           ;
; Params:	lFlags  = Flags for searching                                   ;
;           lpRSsFt = Structure specifying what and how to search           ;
;                                                                           ;
; On enter:  Ebx = Pointer to editor's data structure                       ;
;                                                                           ;
; Returns:  The character index of the text or -1 if not found in Eax       ;
;===========================================================================;
rsFindText Frame lFlags, lpRSFt Uses Ecx, Edx, Edi, Esi
	Local lLength:D

	Mov Edi, [lpRSFt]
	Or Edi, Edi
	Jnz >
L2:	Mov Eax, (-1)
	Ret
:	Mov Eax, [Edi + RSSFINDTEXT.lpstr]
	Or Eax, Eax
	Jz < L2
	Cmp B[Eax], 0
	Je < L2
	Invoke rsGetStringLength, [Edi + RSSFINDTEXT.lpstr]
	Mov [lLength], Eax
	Mov Ecx, [Edi + RSSFINDTEXT.chr.lMin]
	Mov Edx, [Edi + RSSFINDTEXT.chr.lMax]
	Mov Eax, [lFlags]
	And Eax, RSC_DOWN
	Jz > L4
	Cmp Ecx, (-1)
	Jne >
	Xor Ecx, Ecx
:	Cmp Edx, (-1)
	Jne >
	Mov Edx, [Ebx + EDITORDATA.lTextLength]
:	Cmp Ecx, Edx
	Jge < L2
	Mov Eax, Ecx
	Add Eax, [lLength]
	Cmp Eax, [Ebx + EDITORDATA.lTextLength]
	Jg < L2
	Jmp > L6
L4:	Cmp Ecx, (-1)
	Jne >
	Mov Ecx, [Ebx + EDITORDATA.lTextLength]
	Sub Ecx, [lLength]
	Jl < L2
	Cmp Edx, (-1)
	Jne >
	Xor Edx, Edx
:	Cmp Edx, Ecx
	Jge < L2
L6:	Mov Esi, [Ebx + EDITORDATA.lpszText]
	Add Ecx, Esi
	Add Edx, Esi
L8:	Invoke rsSearchText, [Edi + RSSFINDTEXT.lpstr], [lFlags], Esi, Ecx, Edx
	Mov Ecx, Eax
	Cmp Eax, (-1)
	Je > L12
	Mov Eax, [lFlags]
	And Eax, RSC_WHOLEWORD
	Jz > L12
	Or Ecx, Ecx
	Jz >
	Invoke rsIsAlphaNumeric, [Esi + Ecx - 1]
	Or Eax, Eax
	Jnz > L10
:	Mov Eax, Ecx
	Add Eax, [lLength]
	Cmp Eax, [Ebx + EDITORDATA.lTextLength]
	Jg > L12
	Invoke rsIsAlphaNumeric, [Esi + Eax]
	Or Eax, Eax
	Jz > L12
L10:
	Mov Eax, [lFlags]
	And Eax, RSC_DOWN
	Jz >
	Add Ecx, [lLength]
	Add Ecx, Esi
	Jmp < L8
:	Dec Ecx
	Add Ecx, Esi
	Jmp < L8
L12:
	Mov Eax, Ecx
	Ret
EndF

;===========================================================================;
; Name:		rsGetLineFromChar                                               ;
;                                                                           ;
; Function:	Gets the zero based line number for the given index             ;
;                                                                           ;
; Params:	lIndex     = Character index whose number is to be retreived    ;
;           bLineIndex = If TRUE, the new line index is stored in the       ;
;                        'lLineIndex' member of the data structure          ;
;                                                                           ;
; On enter: Ebx = Pointer to editor's data structure                        ;
;                                                                           ;
; Returns: The zero based line for the indicated index                      ;
;===========================================================================;
rsGetLineFromChar Frame lIndex, bLineIndex Uses Edi
	Local lpszTemp:D

	Cmp D[lIndex], 0
	Jg > L2
	Xor Eax, Eax
	Cmp D[bLineIndex], 0
	Je >
	Mov [Ebx + EDITORDATA.lLineIndex], Eax
:	Ret
L2:	Mov Eax, [Ebx + EDITORDATA.lTextLength]
	Cmp [lIndex], Eax
	Jl >
	Mov Edi, [Ebx + EDITORDATA.lpszText]
	Add Edi, Eax
	Mov Eax, [Ebx + EDITORDATA.lLines]
	Dec Eax
	Jmp > L14
:	Mov Eax, [Ebx + EDITORDATA.lpszText]
	Mov Edi, Eax
	Add Eax, [lIndex]
	Mov [lpszTemp], Eax
	Mov Eax, [Ebx + EDITORDATA.lFirstLineIndex]
	Add Edi, Eax
	Cmp [lIndex], Eax
	Jge > L8
	Mov Eax, [Ebx + EDITORDATA.lVScrollPos]
	Mov [lIndex], Eax
L4:	Cmp Edi, [lpszTemp]
	Jle > L6
	Cmp B[Edi], 10
	Jne >
	Dec D[lIndex]
:	Dec Edi
	Jmp < L4
L6:	Mov Eax, [lIndex]
	Jmp > L14
L8:	Mov Eax, [Ebx + EDITORDATA.lVScrollPos]
	Mov [lIndex], Eax
L10:
	Cmp Edi, [lpszTemp]
	Jge > L12
	Cmp B[Edi], 10
	Jne >
	Inc D[lIndex]
:	Inc Edi
	Jmp < L10
L12:
	Mov Eax, [lIndex]
L14:
	Cmp D[bLineIndex], 0
	Je > L18
:	Cmp Edi, [Ebx + EDITORDATA.lpszText]
	Jle > L16
	Cmp B[Edi], 10
	Je >
	Dec Edi
	Jmp <
:	Inc Edi
L16:
	Sub Edi, [Ebx + EDITORDATA.lpszText]
	Mov [Ebx + EDITORDATA.lLineIndex], Edi
L18:
	Ret
EndF

;===========================================================================;
; Name:		rsGetLineIndex                                                  ;
;                                                                           ;
; Function:	Gets the line index for the given line                          ;
;                                                                           ;
; Params:	lLine = Line number whose line index is to be retreived         ;
;                                                                           ;
; On enter: Ebx = Pointer to editor's data structure                        ;
;                                                                           ;
; Returns: The line index for the indicated line                            ;
;===========================================================================;
rsGetLineIndex Frame lLine
	Local lIndex:D, lpszTemp:D

	Cmp D[lLine], 0
	Jg >
	Xor Eax, Eax
	Ret
:	Mov Eax, [Ebx + EDITORDATA.lLines]
	Cmp [lLine], Eax
	Jl >
	Mov Eax, [Ebx + EDITORDATA.lTextLength]
	Invoke rsGetPrevLineIndex, Eax
	Ret
:	Mov Eax, [Ebx + EDITORDATA.lpszText]
	Mov [lpszTemp], Eax
	Mov Eax, [Ebx + EDITORDATA.lVScrollPos]
	Cmp [lLine], Eax
	Jge > L2
	Sub Eax, [lLine]
	Mov [lLine], Eax
	Mov Eax, [Ebx + EDITORDATA.lFirstLineIndex]
	Mov [lIndex], Eax
:	Cmp D[lLine], 0
	Je >
	Invoke rsGetPrevLineIndex, [lIndex]
	Mov [lIndex], Eax
	Dec D[lLine]
	Jmp <
:	Ret
L2:	Cmp [lLine], Eax
	Jle > L4
	Sub [lLine], Eax
	Mov Eax, [Ebx + EDITORDATA.lFirstLineIndex]
	Mov [lIndex], Eax
:	Cmp D[lLine], 0
	Je >
	Invoke rsGetNextLineIndex, [lIndex]
	Mov [lIndex], Eax
	Dec D[lLine]
	Jmp <
:	Ret
L4:	Mov Eax, [Ebx + EDITORDATA.lFirstLineIndex]
	Ret
EndF

;===========================================================================;
; Name:		rsGetLineLength                                                 ;
;                                                                           ;
; Function:	Gets the line length for the given index                        ;
;                                                                           ;
; Params:	lIndex = Index of a char belonging to the line whose length     ;
;                    is to be retreived                                     ;
;                                                                           ;
; On enter: Ebx = Pointer to editor's data structure                        ;
;                                                                           ;
; Returns: The length of the line (including the carriage return) in Eax    ;
;===========================================================================;
rsGetLineLength Frame lIndex Uses Ecx
	Cmp D[lIndex], 0
	Jge >
	Xor Eax, Eax
	Ret
:	Mov Eax, [Ebx + EDITORDATA.lTextLength]
	Cmp [lIndex], Eax
	Jl >
	Xor Eax, Eax
	Ret
:	Mov Eax, [Ebx + EDITORDATA.lpszText]
	Add Eax, [lIndex]
	Cmp D[lIndex], 0
	Je > L2
:	Cmp Eax, [Ebx + EDITORDATA.lpszText]
	Je > L2
	Cmp B[Eax], 10
	Je >
	Dec Eax
	Jmp <
:	Inc Eax
L2:	Push Eax
:	Cmp B[Eax], 0
	Je >
	Cmp B[Eax], 10
	Je >
	Inc Eax
	Jmp <
:	Pop Ecx
	Sub Eax, Ecx
	Ret
EndF

;===========================================================================;
; Name:		rsGetMemoryPosition                                             ;
;                                                                           ;
; Function:	Gets the zero based position inside the line of the char stored ;
;           in the 'ptPos.x' member (column) of the data structure          ;
;                                                                           ;
; On enter: Ebx = Pointer to editor's data structure                        ;
;                                                                           ;
; Returns: The zero based position of the char in memory in Eax             ;
;===========================================================================;
rsGetMemoryPosition Frame
	Local l1:D, lTabs:D

	Invoke rsGetLineLength, [Ebx + EDITORDATA.lLineIndex]
	Or Eax, Eax
	Jnz >
	Ret
:	Push Ecx, Edx, Esi
	Mov [l1], Eax
	Mov Eax, [Ebx + EDITORDATA.lTabStops]
	Mov [lTabs], Eax
	Dec D[lTabs]
	Xor Ecx, Ecx
	Xor Edx, Edx
	Mov Esi, [Ebx + EDITORDATA.lpszText]
	Add Esi, [Ebx + EDITORDATA.lLineIndex]
L2:	Cmp Ecx, [l1]
	Jge > L6
	Cmp Edx, [Ebx + EDITORDATA.ptPos.x]
	Jne >
	Mov Eax, Ecx
	Jmp > L6
:	Cmp B[Esi + Ecx], 9
	Je >
	Inc Edx
	Jmp > L4
:	Push Edx
	And Edx, [lTabs]
	Mov Eax, [Ebx + EDITORDATA.lTabStops]
	Sub Eax, Edx
	Pop Edx
:	Cmp Al, 0
	Jle > L4
	Inc Edx
	Cmp Edx, [Ebx + EDITORDATA.ptPos.x]
	Je > L6
	Dec Al
	Jmp <
L4:	Cmp Edx, [Ebx + EDITORDATA.ptPos.x]
	Jne >
	Inc Ecx
	Mov Eax, Ecx
	Jmp > L6
:	Inc Ecx
	Jmp < L2
L6:	Cmp Ecx, [l1]
	Jl >
	Mov Eax, [l1]
	Dec Eax
:	Mov [Ebx + EDITORDATA.ptPos.x], Eax
	Pop Esi, Edx, Ecx
	Ret
EndF

;===========================================================================;
; Name:		rsGetNextLineIndex                                              ;
;                                                                           ;
; Function:	Gets the next line index (beginning of the next line)           ;
;                                                                           ;
; Params:	lCurrentIndex = Current line index (line index of current line) ;
;                                                                           ;
; On enter: Ebx = Pointer to editor's data structure                        ;
;                                                                           ;
; Returns: The next line index in Eax                                       ;
;===========================================================================;
rsGetNextLineIndex Frame lCurrentIndex
	Mov Eax, [Ebx + EDITORDATA.lTextLength]
	Cmp [lCurrentIndex], Eax
	Jl >
	Ret
:	Mov Eax, [Ebx + EDITORDATA.lpszText]
	Add Eax, [lCurrentIndex]
:	Cmp B[Eax], 0
	Je > L2
	Cmp B[Eax], 10
	Je >
	Inc Eax
	Jmp <
:	Inc Eax
L2:	Sub Eax, [Ebx + EDITORDATA.lpszText]
	Ret
EndF

;===========================================================================;
; Name:		rsGetPrevLineIndex                                              ;
;                                                                           ;
; Function:	Gets the previous line index (beginning of the previous line)   ;
;                                                                           ;
; Params:	lCurrentIndex = Current line index (line index of current line) ;
;                                                                           ;
; On enter: Ebx = Pointer to editor's data structure                        ;
;                                                                           ;
; Returns: The previous line index in Eax                                   ;
;===========================================================================;
rsGetPrevLineIndex Frame lCurrentIndex
	Mov Eax, [Ebx + EDITORDATA.lpszText]
	Add Eax, [lCurrentIndex]
	Cmp Eax, [Ebx + EDITORDATA.lpszText]
	Jg >
	Xor Eax, Eax
	Ret
:	Dec Eax
	Cmp Eax, [Ebx + EDITORDATA.lpszText]
	Je >
	Cmp B[Eax], 10
	Jne <
:	Dec Eax
	Cmp Eax, [Ebx + EDITORDATA.lpszText]
	Je >
	Cmp B[Eax], 10
	Jne <
	Inc Eax
:	Sub Eax, [Ebx + EDITORDATA.lpszText]
	Ret
EndF

;===========================================================================;
; Name:		rsGetRealColWidth                                               ;
;                                                                           ;
; Function:	Gets the real column width (with tabs expanded) in pixels       ;
;                                                                           ;
; On enter: Ebx = Pointer to editor's data structure                        ;
;                                                                           ;
; Returns: The length of the entire line in pixels                          ;
;===========================================================================;
rsGetRealColWidth Frame
	Local hdc:D, sz:SIZEL

	Cmp D[Ebx + EDITORDATA.lRealCols], 0
	Jle >
	Push Ecx
	Invoke rsExpandLineAndGetSelection, [Ebx + EDITORDATA.lLineIndex], NULL
	Invoke GetDC, [Ebx + EDITORDATA.hWnd]
	Mov [hdc], Eax
	Invoke SelectObject, [hdc], [Ebx + EDITORDATA.hFont]
	Invoke GetTextExtentPoint32, [hdc], [Ebx + EDITORDATA.lpszLine], [Ebx + EDITORDATA.lRealCol], Addr sz
	Invoke ReleaseDC, [Ebx + EDITORDATA.hWnd], [hdc]
	Pop Ecx
	Return ([sz.cx])
:	Xor Eax, Eax
	Ret
EndF

;===========================================================================;
; Name:		rsGetStringLength                                               ;
;                                                                           ;
; Function:	Gets the length of an ASCIIZ string (saving Ecx and Edx)        ;
;                                                                           ;
; Params:  lpszBuf = Address of the string whose length is to be retreived  ;
;                                                                           ;
; Returns: The length of indicated string in Eax                            ;
;===========================================================================;
rsGetStringLength Frame lpszBuf Uses Ecx, Edx
	Mov Eax, [lpszBuf]
	Or Eax, Eax
	Jz >
	Invoke lstrlen, [lpszBuf]
:	Ret
EndF

;On enter: Ebx = Pointer to editor's data structure
rsGetTrackPos Frame lBar
	Local sci:SCROLLINFO

	Mov D[sci.cbSize], SizeOf SCROLLINFO
	Mov D[sci.fMask], SIF_TRACKPOS
	Invoke GetScrollInfo, [Ebx + EDITORDATA.hWnd], [lBar], Addr sci
	Mov Eax, [sci.nTrackPos]
	Ret
EndF

;===========================================================================;
; Name:		rsInitEditor                                                    ;
;                                                                           ;
; Function:	Initializes the RS Edit's data structure                        ;
;                                                                           ;
; Params:	lpszBuf = Pointer to the text to be set                         ;
;                                                                           ;
; On enter: Ebx = Pointer to editor's data structure                        ;
;===========================================================================;
rsInitEditor Frame lpszBuf
	Cmp D[Ebx + EDITORDATA.lpszMemPtr], NULL
	Je >
	Invoke VirtualFree, [Ebx + EDITORDATA.lpszMemPtr], 0, MEM_RELEASE
:	Invoke rsGetStringLength, [lpszBuf]
	Mov Ecx, [RSdwPageSize]
	Xor Edx, Edx
	Div Ecx
	Add Eax, 1
	Mul Ecx
	Push Eax
	Invoke VirtualAlloc, 0, Eax, MEM_COMMIT, PAGE_READWRITE
	Mov [Ebx + EDITORDATA.lpszMemPtr], Eax
	Mov B[Eax], 13
	Mov B[Eax + 1], 10
	Add Eax, 2
	Mov [Ebx + EDITORDATA.lpszText], Eax
	Pop Eax
	Sub Eax, 8
	Mov [Ebx + EDITORDATA.lBufferLength], Eax
	Invoke rsCopyString, [Ebx + EDITORDATA.lpszText], [lpszBuf]
	Mov [Ebx + EDITORDATA.lTextLength], Eax
	Invoke lstrcat, [Ebx + EDITORDATA.lpszText], Addr RSszLineFeed
	Mov D[Ebx + EDITORDATA.bModified], FALSE
	Invoke rsGetLineLength, 0
	Dec Eax
	Jge >
	Xor Eax, Eax
:	Mov [Ebx + EDITORDATA.lCols], Eax
	Mov D[Ebx + EDITORDATA.lRealCol], 0
	Mov D[Ebx + EDITORDATA.lRealCols], 0
	Mov D[Ebx + EDITORDATA.lHScrollPos], 0
	Mov D[Ebx + EDITORDATA.lVScrollPos], 0
	Mov D[Ebx + EDITORDATA.lFirstLineIndex], 0
	Mov D[Ebx + EDITORDATA.ptPos.x], 0
	Mov D[Ebx + EDITORDATA.ptPos.y], 0
	Mov D[Ebx + EDITORDATA.chrPos.lMin], 0
	Mov D[Ebx + EDITORDATA.chrPos.lMax], 0
	Mov D[Ebx + EDITORDATA.chrSel.lMin], 0
	Mov D[Ebx + EDITORDATA.chrSel.lMax], 0
	Mov D[Ebx + EDITORDATA.lSelCol], 0
	Invoke rsSetLines
	Invoke rsClearUndoBuffer
	Invoke rsSetPosition, 0, 0
	Ret
EndF

;===========================================================================;
; Name:		rsInsertText                                                    ;
;                                                                           ;
; Function:	Inserts text (or removes it) in the RS Edit control's memory    ;
;                                                                           ;
; Params:	lpszChar = Addres of text to be inserted                        ;
;                                                                           ;
; On enter: Ebx = Pointer to editor's data structure                        ;
;                                                                           ;
; Returns:  The length of the inserted text                                 ;
;===========================================================================;
rsInsertText Frame lpszChar Uses Ecx
	Local lLength:D, lTemp:D, lpszTemp:D

	Xor Ecx, Ecx
	Mov [lTemp], Ecx
	Mov Eax, [Ebx + EDITORDATA.chrPos.lMin]
	Cmp Eax, [Ebx + EDITORDATA.chrPos.lMax]
	Je > L6
	Push Esi
	Mov Esi, [Ebx + EDITORDATA.lpszText]
L2:	Cmp Eax, [Ebx + EDITORDATA.chrPos.lMax]
	Jge > L4
	Cmp B[Esi + Eax], 10
	Jne >
	Sub Ecx, 1
:	Add Eax, 1
	Jmp < L2
L4:	Pop Esi
L6:	Mov Eax, [lpszChar]
L8:	Cmp B[Eax], 0
	Je > L10
	Cmp B[Eax], 10
	Jne >
	Add Ecx, 1
:	Add Eax, 1
	Jmp < L8
L10:
	Cmp Ecx, 0
	Je >
	Add [Ebx + EDITORDATA.lLines], Ecx
:	Invoke rsGetStringLength, [lpszChar]
	Mov [lLength], Eax
	Mov Ecx, [Ebx + EDITORDATA.chrPos.lMax]
	Sub Ecx, [Ebx + EDITORDATA.chrPos.lMin]
	Sub Eax, Ecx
	Mov [lTemp], Eax
	Add Eax, [Ebx + EDITORDATA.lTextLength]
	Add Eax, 3
	Cmp Eax, [Ebx + EDITORDATA.lBufferLength]
	Jl >
	Sub Eax, [Ebx + EDITORDATA.lBufferLength]
	Invoke rsResizeTextBuffer, Eax
:	Mov Eax, [Ebx + EDITORDATA.lpszText]
	Add Eax, [Ebx + EDITORDATA.chrPos.lMin]
	Push Eax
	Add Eax, [lLength]
	Mov [lpszTemp], Eax
	Mov Ecx, [Ebx + EDITORDATA.lpszText]
	Add Ecx, [Ebx + EDITORDATA.chrPos.lMax]
	Mov Eax, [Ebx + EDITORDATA.lTextLength]
	Sub Eax, [Ebx + EDITORDATA.chrPos.lMax]
	Add Eax, 3
	Invoke rsMoveMemory, [lpszTemp], Ecx, Eax
	Pop Ecx
	Cmp D[lLength], 0
	Jle >
	Invoke rsMoveMemory, Ecx, [lpszChar], [lLength]
:	Mov Eax, [lTemp]
	Add [Ebx + EDITORDATA.lTextLength], Eax
	Mov Eax, [lLength]
	Ret
EndF

;===========================================================================;
; Name:		rsIsAlpha                                                       ;
;                                                                           ;
; Function:	Specifies whether a character is a letter or not                ;
;                                                                           ;
; Params:	chr        = Character to check                                 ;
;                                                                           ;
; On enter:  Ebx = Pointer to editor's data structure                       ;
;                                                                           ;
; Returns:  TRUE if chr is an alpha character, FALSE if not                 ;
;===========================================================================;
rsIsAlpha Frame chr
	Mov Eax, [chr]
	Cmp Al, 64
	Jg >
	Xor Eax, Eax
	Ret
:	Cmp Al, 91
	Jl >
	Cmp Al, 96
	Jg >
	Xor Eax, Eax
	Ret
:	Cmp Al, 123
	Jl >
	Cmp Al, 191
	Jg >
	Push Eax
	Call [Ebx + EDITORDATA.prFindProc]
	Ret
:	Mov Eax, TRUE
	Ret
EndF

;===========================================================================;
; Name:		rsIsAlphaNumeric                                                ;
;                                                                           ;
; Function:	Specifies whether a character is alphanumeric or not            ;
;                                                                           ;
; Params:	chr        = Character to check                                 ;
;                                                                           ;
; Returns:  TRUE if chr is a letter or o number, FALSE if not               ;
;===========================================================================;
rsIsAlphaNumeric Frame chr
	Invoke rsIsAlpha, [chr]
	Or Eax, Eax
	Jz >
	Ret
:	Mov Eax, [chr]
	Cmp Al, 47
	Jg >
	Xor Eax, Eax
	Ret
:	Cmp Al, 58
	Jl >
	Xor Eax, Eax
	Ret
:	Mov Eax, TRUE
	Ret
EndF

;On exit: Eax = Pointer to the first valid chararacter
rsKillScrollTimer:
	Cmp D[Ebx + EDITORDATA.bTimer], 0
	Je >
	Invoke KillTimer, [Ebx + EDITORDATA.hWnd], 10
	Or Eax, Eax
	Jz >
	Mov D[Ebx + EDITORDATA.bTimer], 0
:	Ret

;===========================================================================;
; Name:		rsMoveMemory                                                    ;
;                                                                           ;
; Function:	Moves 'lCount' bytes from 'lpszSource' to 'lpszDest'            ;
;                                                                           ;
; Params:	lpszSource = Address of the source of data to be moved          ;
;           lpszDest   = Address of the destination where to move to        ;
;           lCount     = Number of bytes to be moved                        ;
;                                                                           ;
; Returns:  Nothing                                                         ;
;===========================================================================;
rsMoveMemory Frame lpszDest, lpszSource, lCount Uses Ecx, Esi, Edi
	Mov Ecx, [lCount]
	Cmp Ecx, 0
	Jg >
	Ret
:	Mov Edi, [lpszDest]
	Mov Esi, [lpszSource]
	Cmp Edi, Esi
	Jle > L2
	Dec Ecx
	Add Esi, Ecx
	Add Edi, Ecx
	Inc Ecx
:  	Mov Al, [Esi]
    Dec Esi
    Mov [Edi], Al
    Dec Edi
    Dec Ecx
	Jnz <
	Ret
L2:	Mov Al, [Esi]
    Inc Esi
    Mov [Edi], Al
    Inc Edi
    Dec Ecx
	Jnz < L2
	Ret
EndF

;===========================================================================;
; Name:		rsPaintEditor                                                   ;
;                                                                           ;
; Function:	Paints the entire RS Edit control (processes WM_PAINT)          ;
;                                                                           ;
; On enter: Ebx = Pointer to editor's data structure                        ;
;                                                                           ;
; Remarks:  If an address for a 'Paint proc' has been set (refer to message ;
;           RSM_SETPAINTPROC) RSEdit gives control to that procedure and    ;
;           does not paint anything.                                        ;
;===========================================================================;
rsPaintEditor Frame
	Local lIndex:D, lLine:D, lBottom:D, lLength:D
	Local chr:RSSCHARSEL, ps:PAINTSTRUCT
	
	Invoke GetUpdateRect, [Ebx + EDITORDATA.hWnd], NULL, FALSE
	Or Eax, Eax
	Jnz >
	Ret
:	Invoke BeginPaint, [Ebx + EDITORDATA.hWnd], Addr ps
	Cmp D[Ebx + EDITORDATA.prPaintProc], NULL
	Je >
	Lea Eax, [ps]
	Push Eax
	Call [Ebx + EDITORDATA.prPaintProc]
	Jmp >> L8
:	Push Edi
	Push Esi
	Mov D[ps.rcPaint.top], 0
	Mov Eax, [Ebx + EDITORDATA.lVScrollPos]
	Mov [lLine], Eax
	Invoke SelectObject, [ps.hdc], [Ebx + EDITORDATA.hFont]
	Mov D[ps.rcPaint.left], 0
	Mov Eax, [Ebx + EDITORDATA.lMarginWidth]
	Mov [ps.rcPaint.right], Eax
	Invoke SetBkColor, [ps.hdc], [Ebx + EDITORDATA.crMarginColor]
	Invoke ExtTextOut, [ps.hdc], 0, [ps.rcPaint.top], ETO_OPAQUE, Addr ps.rcPaint, 0, 0, NULL
	Invoke SetBkColor, [ps.hdc], [Ebx + EDITORDATA.crBackColor]
	Invoke ExcludeClipRect, [ps.hdc], 0, 0, [Ebx + EDITORDATA.lMarginWidth], [ps.rcPaint.bottom]
	Mov Eax, [ps.rcPaint.right]
	Sub Eax, [Ebx + EDITORDATA.lHScrollPos]
	Mov [ps.rcPaint.left], Eax
	Add Eax, [Ebx + EDITORDATA.szSize.cx]
	Add Eax, [Ebx + EDITORDATA.lHScrollPos]
	Mov D[ps.rcPaint.right], Eax
	Mov Eax, [Ebx + EDITORDATA.lFirstLineIndex]
	Mov [lIndex], Eax
	Mov Eax, [ps.rcPaint.bottom]
	Add Eax, [Ebx + EDITORDATA.szFont.cy]
	Mov [lBottom], Eax
	Mov Eax, [ps.rcPaint.top]
L2:	Add Eax, [Ebx + EDITORDATA.szFont.cy]
	Mov [ps.rcPaint.bottom], Eax
	Mov Eax, [lLine]
	Cmp Eax, [Ebx + EDITORDATA.lLines]
	Jle > L4
L3:	Invoke ExtTextOut, [ps.hdc], [ps.rcPaint.left], 0, ETO_OPAQUE, Addr ps.rcPaint, 0, 0, NULL
	Jmp > L6
L4:	Invoke rsExpandLineAndGetSelection, [lIndex], Addr chr
	Or Eax, Eax
	Jz < L3
	Mov [lLength], Eax
	Mov Eax, [chr.lMin]
	Cmp Eax, [chr.lMax]
	Jl >
	Invoke ExtTextOut, [ps.hdc], [ps.rcPaint.left], [ps.rcPaint.top], ETO_OPAQUE, Addr ps.rcPaint, [Ebx + EDITORDATA.lpszLine], [lLength], NULL
	Jmp > L6
:	Invoke rsPaintSelectedText, [ps.hdc], [lLength], Addr ps.rcPaint, Addr chr
L6:	Invoke rsGetNextLineIndex, [lIndex]
	Mov [lIndex], Eax
	Add D[lLine], 1
	Mov Eax, [ps.rcPaint.top]
	Add Eax, [Ebx + EDITORDATA.szFont.cy]
	Mov [ps.rcPaint.top], Eax
	Cmp Eax, [lBottom]
	Jle << L2
	Pop Edi
	Pop Esi
L8:	Invoke EndPaint, [Ebx + EDITORDATA.hWnd], Addr ps
	Ret
EndF

;On enter: Ebx = Pointer to editor's data structure
rsPaintSelectedText Frame hdc, lLength, lpRcPaint, lpChr Uses Edx, Edi, Esi
	Local lBytes:D, sz:SIZEL

	Mov Edi, [lpChr]
	Mov Esi, [lpRcPaint]
	Cmp D[Edi + RSSCHARSEL.lMin], 0
	Jg >
	Mov D[sz.cx], 0
	Jmp > L2
:	Invoke TextOut, [hdc], [Esi + RECT.left], [Esi + RECT.top], [Ebx + EDITORDATA.lpszLine], [Edi + RSSCHARSEL.lMin]
	Invoke GetTextExtentPoint32, [hdc], [Ebx + EDITORDATA.lpszLine], [Edi + RSSCHARSEL.lMin], Addr sz
L2:	Mov Eax, [lLength]
	Cmp [Edi + RSSCHARSEL.lMax], Eax
	Jge >
	Mov Eax, [Edi + RSSCHARSEL.lMax]
:	Mov [lBytes], Eax
	Push [Esi + RECT.left]
	Invoke SetBkColor, [hdc], [Ebx + EDITORDATA.crBackSelect]
	Invoke SetTextColor, [hdc], [Ebx + EDITORDATA.crTextSelect]
	Cmp D[Edi + RSSCHARSEL.lMin], 0
	Jne >
	Invoke TextOut, [hdc], [Esi + RECT.left], [Esi + RECT.top], [Ebx + EDITORDATA.lpszLine], [lBytes]
	Jmp > L4
:	Mov Eax, [Edi + RSSCHARSEL.lMin]
	Sub [lBytes], Eax
	Add Eax, [Ebx + EDITORDATA.lpszLine]
	Mov Ecx, [sz.cx]
	Add [Esi + RECT.left], Ecx
	Invoke TextOut, [hdc], [Esi + RECT.left], [Esi + RECT.top], Eax, [lBytes]
L4:	Invoke SetBkColor, [hdc], [Ebx + EDITORDATA.crBackColor]
	Invoke SetTextColor, [hdc], [Ebx + EDITORDATA.crTextColor]
	Mov Edx, [Edi + RSSCHARSEL.lMin]
	Add Edx, [Ebx + EDITORDATA.lpszLine]
	Invoke GetTextExtentPoint32, [hdc], Edx, [lBytes], Addr sz
	Mov Eax, [sz.cx]
	Add [Esi + RECT.left], Eax
	Mov Eax, [Edi + RSSCHARSEL.lMax]
	Cmp Eax, [lLength]
	Jl >
	Invoke ExtTextOut, [hdc], [Esi + RECT.left], [Esi + RECT.top], ETO_OPAQUE, [lpRcPaint], 0, 0, NULL
	Pop [Esi + RECT.left]
	Ret
:	Mov Eax, [lLength]
	Dec Eax
	Sub Eax, [Edi + RSSCHARSEL.lMax]
	Mov [lBytes], Eax
	Mov Eax, [Edi + RSSCHARSEL.lMax]
	Add Eax, [Ebx + EDITORDATA.lpszLine]
	Invoke ExtTextOut, [hdc], [Esi + RECT.left], [Esi + RECT.top], ETO_OPAQUE, [lpRcPaint], Eax, [lBytes], NULL
	Pop [Esi + RECT.left]
	Ret
EndF

;===========================================================================;
; Name:		rsProcessEditotMouseMessages                                    ;
;                                                                           ;
; Function:	Processes WM_LBUTTONDOWN message                                ;
;                                                                           ;
; Params:	wMsg    = Value of uMsg parameter                               ;
;           wParam  = Value of wParam parameter                             ;
;			lParam  = Value of lParam parameter                             ;
;                                                                           ;
; On enter: Ebx = Pointer to editor's data structure                        ;
;                                                                           ;
; Returns:  The character index where the mouse clicked                     ;
;===========================================================================;
rsProcessEditotMouseMessages Frame uMsg, wParam, lParam Uses Ecx, Edi
	Local l:D, l1:D, lX:D, pt:POINTL
	Local sz:SIZEL

	Mov Eax, [Ebx + EDITORDATA.lTextLength]
	Mov [pt.x], Eax
	LoWord ([lParam])
	Cwde
	Sub Eax, [Ebx + EDITORDATA.lMarginWidth]
	Mov [lX], Eax
	HiWord ([lParam])
	Cwde
	Cdq
	Cmp Edx, 0
	Jge >
	Cmp D[Ebx + EDITORDATA.bTimer], 0
	Je >
	Sub Eax, [Ebx + EDITORDATA.szFont.cy]
:	IDiv D[Ebx + EDITORDATA.szFont.cy]
	Add Eax, [Ebx + EDITORDATA.lVScrollPos]
	Mov [pt.y], Eax
	Cmp Eax, [Ebx + EDITORDATA.lLines]
	Jl >
	Mov Eax, [pt.x]
	Jmp >> L8
:	Invoke rsGetLineIndex, Eax
	Mov [Ebx + EDITORDATA.lLineIndex], Eax
	Mov Ecx, Eax
	Invoke rsExpandLineAndGetSelection, Ecx, NULL
	Dec Eax
	Mov [pt.x], Eax
	Mov [Ebx + EDITORDATA.ptPos.x], Eax
	Cmp Eax, 0
	Jle >> L6
	Mov D[l], 1
	Invoke GetDC, [Ebx + EDITORDATA.hWnd]
	Mov Edi, Eax
	Invoke SelectObject, Edi, [Ebx + EDITORDATA.hFont]
L2:	Mov Ecx, [l]
	Cmp Ecx, [pt.x]
	Jg > L4
	Invoke GetTextExtentPoint32, Edi, [Ebx + EDITORDATA.lpszLine], [l], Addr sz
	Mov Eax, [lX]
	Add Eax, [Ebx + EDITORDATA.lHScrollPos]
	Cmp Eax, [sz.cx]
	Jg >
	Mov [l1], Eax
	Mov Eax, [sz.cx]
	Sub Eax, [l1]
	Mov [l1], Eax
	Dec D[l]
	Mov Ecx, [Ebx + EDITORDATA.lpszLine]
	Add Ecx, [l]
	Invoke GetTextExtentPoint32, Edi, Ecx, 1, Addr sz
	Mov Eax, [sz.cx]
	Shr Eax, 1
	Cmp Eax, [l1]
	Jl > L4
	Inc D[l]
	Jmp > L4
:	Inc D[l]
	Jmp < L2
L4:	Invoke ReleaseDC, [Ebx + EDITORDATA.hWnd], Edi
	Mov Eax, [l]
	Mov [Ebx + EDITORDATA.ptPos.x], Eax
L6:	Invoke rsGetMemoryPosition
	Add Eax, [Ebx + EDITORDATA.lLineIndex]
	Mov [pt.x], Eax
L8:	Mov Ecx, [wParam]
	And Ecx, MK_SHIFT
	Jz >
	Mov Eax, [Ebx + EDITORDATA.chrSel.lMin]
	Mov [Ebx + EDITORDATA.chrPos.lMin], Eax
	Mov Eax, [pt.x]
:	Mov Ecx, [wParam]
	And Ecx, MK_CONTROL
	Jnz >
	Mov Ecx, [wParam]
	And Ecx, MK_SHIFT
	Jnz >> L18
	Mov [Ebx + EDITORDATA.chrPos.lMin], Eax
	Jmp >> L18
:	Cmp D[uMsg], WM_LBUTTONDOWN
	Jne > L10
	Mov Ecx, [wParam]
	And Ecx, MK_SHIFT
	Jnz > L10
	Mov Ecx, [Ebx + EDITORDATA.chrPos.lMin]
	Cmp Ecx, [Ebx + EDITORDATA.chrPos.lMax]
	Je >
	Cmp Eax, Ecx
	Jl >
	Cmp Eax, [Ebx + EDITORDATA.chrPos.lMax]
	Jle > L9
:	Invoke rsSelectWord, Eax, FALSE
	Mov Eax, [Ebx + EDITORDATA.chrPos.lMax]
	Jmp >> L18
L9:	Mov [Ebx + EDITORDATA.chrPos.lMin], Eax
	Jmp >> L18
L10:
	Invoke rsSelectWord, [Ebx + EDITORDATA.chrSel.lMin], TRUE
	Mov Eax, [Ebx + EDITORDATA.chrSel.lMin]
	Cmp Eax, [Ebx + EDITORDATA.chrSel.lMax]
	Jne > L12
	Cmp [pt.x], Eax
	Jg >
	Mov Eax, [Ebx + EDITORDATA.chrPos.lMax]
	Jmp > L14
:	Mov Eax, [Ebx + EDITORDATA.chrPos.lMin]
	Jmp > L14
L12:
	Cmp [pt.x], Eax
	Jle >
	Mov Eax, [Ebx + EDITORDATA.chrPos.lMin]
	Jmp > L14
:	Cmp Eax, [Ebx + EDITORDATA.chrPos.lMax]
	Jg >
	Mov Eax, [Ebx + EDITORDATA.chrPos.lMax]
	Jmp > L14
:	Mov Eax, [Ebx + EDITORDATA.chrSel.lMin]
L14:
	Mov [pt.y], Eax
	Invoke rsSelectWord, [pt.x], TRUE
	Mov Eax, [Ebx + EDITORDATA.chrSel.lMin]
	Cmp [pt.x], Eax
	Jg >
	Mov Eax, [Ebx + EDITORDATA.chrPos.lMin]
	Jmp > L16
:	Mov Eax, [Ebx + EDITORDATA.chrPos.lMax]
L16:
	Push [pt.y]
	Pop [Ebx + EDITORDATA.chrPos.lMin]
L18:
	Mov [Ebx + EDITORDATA.chrPos.lMax], Eax
	Mov D[Ebx + EDITORDATA.bSelCol], TRUE
	Cmp D[uMsg], WM_MOUSEMOVE
	Jne >
	Invoke rsCheckForScrollTimer, TRUE
:	Ret
EndF

;On enter: Ebx = Pointer to editor's data structure
rsProcessMarginMouseMessages Frame uMsg, wParam, lParam
	Local pt:POINTL

	Cmp D[uMsg], WM_LBUTTONDOWN
	Jne >> L10
	Invoke SetCapture, [Ebx + EDITORDATA.hWnd]
	Mov Eax, [wParam]
	And Eax, MK_CONTROL
	Jz > L4
	Mov Eax, [wParam]
	And Eax, MK_SHIFT
	Jz >
	Invoke rsSetSelection, 0, [Ebx + EDITORDATA.lTextLength]
	Jmp > L2
:	Push [Ebx + EDITORDATA.lFirstLineIndex]
	Push [Ebx + EDITORDATA.lVScrollPos]
	Invoke rsSetPosition, 0, [Ebx + EDITORDATA.lTextLength]
	Invoke rsSetCursorCoordinates
	Invoke rsSetCaret
	Pop [Ebx + EDITORDATA.lVScrollPos]
	Pop [Ebx + EDITORDATA.lFirstLineIndex]
	Invoke rsUpdateEditor, FALSE
L2:	Mov D[Ebx + EDITORDATA.lSelCol], 0
	Xor Eax, Eax
	Ret
L4:	HiWord ([lParam])
	Cwde
	Cdq
	IDiv D[Ebx + EDITORDATA.szFont.cy]
	Add Eax, [Ebx + EDITORDATA.lVScrollPos]
	Cmp Eax, [Ebx + EDITORDATA.lLines]
	Jl >
	Xor Eax, Eax
	Ret
:	Cmp Eax, 0
	Jge >
	Xor Eax, Eax
	Ret
:	Mov [pt.y], Eax
	Invoke rsGetLineIndex, Eax
	Mov [Ebx + EDITORDATA.lStart], Eax
	Invoke rsGetLineLength, Eax
	Cmp Eax, 0
	Jg >
	Xor Eax, Eax
	Ret
:	Inc Eax
	Mov [pt.x], Eax
	Mov Eax, [Ebx + EDITORDATA.lStart]
	Mov [Ebx + EDITORDATA.lStartPos], Eax
	Mov Ecx, [wParam]
	And Ecx, MK_SHIFT
	Jnz >
	Add [pt.x], Eax
	Jmp > L8
:	Mov [pt.x], Eax
	Cmp [Ebx + EDITORDATA.chrSel.lMin], Eax
	Jle >
	Invoke rsGetLineFromChar, [Ebx + EDITORDATA.chrSel.lMin], FALSE
	Invoke rsGetLineIndex, Eax
	Mov [Ebx + EDITORDATA.lStart], Eax
	Invoke rsGetLineLength, [Ebx + EDITORDATA.lStart]
	Inc Eax
	Add Eax, [Ebx + EDITORDATA.lStart]
	Mov [Ebx + EDITORDATA.lStartPos], Eax
	Jmp > L8
:	Mov Eax, [Ebx + EDITORDATA.chrSel.lMin]
	Cmp Eax, [Ebx + EDITORDATA.chrSel.lMax]
	Jg >
	Invoke rsGetLineFromChar, [Ebx + EDITORDATA.chrSel.lMin], FALSE
	Jmp > L6
:	Dec Eax
	Invoke rsGetLineFromChar, Eax, FALSE
L6:	Invoke rsGetLineIndex, Eax
	Mov [Ebx + EDITORDATA.lStart], Eax
	Invoke rsGetLineLength, [pt.x]
	Inc Eax
	Add [pt.x], Eax
	Mov Eax, [Ebx + EDITORDATA.lStart]
	Mov [Ebx + EDITORDATA.lStartPos], Eax
L8:	Mov D[Ebx + EDITORDATA.bSelCol], TRUE
	Invoke rsSetSelection, [Ebx + EDITORDATA.lStartPos], [pt.x]
	Ret
L10:
	Cmp D[uMsg], WM_MOUSEMOVE
	Je >
	Ret
:	Mov Eax, [wParam]
	And Eax, MK_CONTROL
	Jz >
	Xor Eax, Eax
	Ret
:	HiWord ([lParam])
	Cwde
	Cdq
	Cmp Edx, 0
	Jge >
	Cmp D[Ebx + EDITORDATA.bTimer], 0
	Je >
	Sub Eax, [Ebx + EDITORDATA.szFont.cy]
:	IDiv D[Ebx + EDITORDATA.szFont.cy]
	Add Eax, [Ebx + EDITORDATA.lVScrollPos]
	Cmp Eax, 0
	Jge >
	Xor Eax, Eax
:	Cmp Eax, [Ebx + EDITORDATA.lLines]
	Jl >
	Mov Eax, [Ebx + EDITORDATA.lLines]
	Dec Eax
:	Mov [pt.y], Eax
	Invoke rsGetLineIndex, Eax
	Mov [pt.x], Eax
	Cmp Eax, [Ebx + EDITORDATA.lStart]
	Jl > L12
	Mov Eax, [Ebx + EDITORDATA.lStart]
	Mov [Ebx + EDITORDATA.lStartPos], Eax
	Invoke rsGetLineLength, [pt.x]
	Cmp Eax, 0
	Jge >
	Xor Eax, Eax
	Ret
:	Inc Eax
	Add [pt.x], Eax
	Jmp > L14
L12:
	Mov [pt.x], Eax
	Cmp D[Ebx + EDITORDATA.lStart], 0
	Jle > L14
	Mov Eax, [Ebx + EDITORDATA.chrPos.lMax]
	Mov [Ebx + EDITORDATA.lStartPos], Eax
L14:
	Invoke rsSetSelection, [Ebx + EDITORDATA.lStartPos], [pt.x]
	Cmp D[uMsg], WM_MOUSEMOVE
	Jne >
	Invoke rsCheckForScrollTimer, FALSE
:	Ret
EndF

;===========================================================================;
; Name:		rsRedoAction                                                    ;
;                                                                           ;
; Function:	Performs a redo action (if any)                                 ;
;                                                                           ;
; On enter: Ebx = Pointer to editor's data structure                        ;
;                                                                           ;
; Returns:  Nothing                                                         ;
;===========================================================================;
rsRedoAction: Uses Edx, Edi, Esi
	Cmp D[Ebx + EDITORDATA.lpUndoBuffer], NULL
	Jne >
	Xor Eax, Eax
	Ret
:	Mov Esi, [Ebx + EDITORDATA.lpUndoBuffer]
	Mov Eax, [Ebx + EDITORDATA.lUndoCount]
	Shl Eax, 2
	Add Esi, Eax
	Cmp D[Esi], NULL
	Jne >
	Xor Eax, Eax
	Ret
:	Mov D[Ebx + EDITORDATA.bSelCol], TRUE
	Push [Ebx + EDITORDATA.dwEventMask]
	Mov D[Ebx + EDITORDATA.dwEventMask], 0
	Invoke SendMessage, [Ebx + EDITORDATA.hWnd], WM_SETREDRAW, FALSE, 0
	Invoke GlobalLock, [Esi]
	Mov Edi, Eax
	Push Edi
	Mov Eax, [Edi + 4]
	Mov [Ebx + EDITORDATA.lHScrollPos], Eax
	Mov Eax, [Edi + 8]
	Mov [Ebx + EDITORDATA.chrPos.lMin], Eax
	Mov Eax, [Edi + 12]
	Mov [Ebx + EDITORDATA.chrPos.lMax], Eax
	Mov Eax, [Edi]
	Invoke rsSetFirstVisibleLine, Eax
	Add Edi, 16
	Invoke rsGetStringLength, Edi
	Add Edi, Eax
	Inc Edi
	Invoke rsGetStringLength, Edi
	Push Eax
	Invoke rsReplaceSelection, Edi, (-1)
	Pop Edx
	Pop Edi
	Invoke rsCheckFirstLine
	Invoke rsSetFirstLineIndex
	Mov Eax, [Ebx + EDITORDATA.lUndoCount]
	Inc Eax
	Cmp Eax, [Ebx + EDITORDATA.lUndoLimit]
	Jl >
	Mov D[Ebx + EDITORDATA.lUndoCount], 0
	Jmp > L2
:	Mov [Ebx + EDITORDATA.lUndoCount], Eax
L2:	Mov Ecx, [Edi + 8]
	Add Edx, Ecx
	Push Ecx
	Push Edx
	Invoke GlobalUnlock, [Esi]
	Invoke SendMessage, [Ebx + EDITORDATA.hWnd], WM_SETREDRAW, TRUE, 0
	Pop Edx
	Pop Ecx
	Pop [Ebx + EDITORDATA.dwEventMask]
	Inc Ecx
	Cmp Ecx, Edx
	Je >
	Dec Ecx
:	Mov D[Ebx + EDITORDATA.bChanged], TRUE
	Invoke rsSetSelection, Ecx, Edx
	Call rsCheckModified
	Mov Eax, TRUE
	Ret
EndU

;===========================================================================;
; Name:		rsReplaceSelection                                              ;
;                                                                           ;
; Function:	Replaces selected text with text specified by lpszChar          ;
;                                                                           ;
; Params:	lpszChar = Address of new text                                  ;
;           lKey     = Key code for undo action (-1 if no undo)             ;
;                                                                           ;
; On enter: Ebx = Pointer to editor's data structure                        ;
;                                                                           ;
; Remarks:  If there is no text selected, the new text is inserted in the   ;
;           caret's position (the insertion point)                          ;
;===========================================================================;
rsReplaceSelection Frame lpszChar, lKey
	Mov D[Ebx + EDITORDATA.bSelCol], TRUE
	Cmp D[Ebx + EDITORDATA.bReadOnly], 0
	Je >
	Ret
:	Cmp D[lKey], (-1)
	Je >
	Invoke rsStoreUndoText, [lpszChar]
:	Mov Eax, [Ebx + EDITORDATA.dwEventMask]
	And Eax, EV_UPDATE
	Jz >
	Mov Eax, EN_UPDATE
	Shl Eax, 16
	Invoke SendMessage, [Ebx + EDITORDATA.hWndOwner], WM_COMMAND, Eax, [Ebx + EDITORDATA.hWnd]
:	Invoke rsInsertText, [lpszChar]
	Add Eax, [Ebx + EDITORDATA.chrPos.lMin]
	Mov [Ebx + EDITORDATA.chrPos.lMin], Eax
	Mov [Ebx + EDITORDATA.chrPos.lMax], Eax
	Mov D[Ebx + EDITORDATA.bModified], TRUE
	Mov D[Ebx + EDITORDATA.bChanged], TRUE
	Cmp D[lKey], (-1)
	Je >
	Invoke rsSetSelection, [Ebx + EDITORDATA.chrPos.lMin], [Ebx + EDITORDATA.chrPos.lMax]
:	Mov D[Ebx + EDITORDATA.bChanged], FALSE
	Mov Eax, [Ebx + EDITORDATA.dwEventMask]
	And Eax, EV_CHANGE
	Jz >
	Mov Eax, EN_CHANGE
	Shl Eax, 16
	Invoke SendMessage, [Ebx + EDITORDATA.hWndOwner], WM_COMMAND, Eax, [Ebx + EDITORDATA.hWnd]
:	Ret
EndF

;===========================================================================;
; Name:		rsResizeTextBuffer                                              ;
;                                                                           ;
; Function:	Resizes text buffer to fit the new text length                  ;
;                                                                           ;
; Params:	lBytes = Number of bytes to be add                              ;
;                                                                           ;
; On enter: Ebx = Pointer to editor's data structure                        ;
;===========================================================================;
rsResizeTextBuffer Frame lBytes
	Local dwBytes:D, hHandle:D

	Invoke GetTempPath, MAX_PATH, [Ebx + EDITORDATA.lpszLine]
	Mov [dwBytes], Eax
	Dec Eax
	Add Eax, [Ebx + EDITORDATA.lpszLine]
	Cmp B[Eax], '\'
	Je >
	Mov B[Eax], '\'
	Mov B[Eax + 1], 0
:	Invoke lstrcat, [Ebx + EDITORDATA.lpszLine], "RSEDTTXT.TMP"
	Invoke CreateFile, [Ebx + EDITORDATA.lpszLine], GENERIC_READ Or GENERIC_WRITE, FILE_SHARE_WRITE, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL
	Mov [hHandle], Eax
	Invoke WriteFile, [hHandle], [Ebx + EDITORDATA.lpszText], [Ebx + EDITORDATA.lTextLength], Addr dwBytes, NULL
	Invoke CloseHandle, [hHandle]
	Invoke VirtualFree, [Ebx + EDITORDATA.lpszMemPtr], 0, MEM_RELEASE
	Mov Eax, [lBytes]
	Cmp Eax, [RSdwPageSize]
	Jge >
	Mov Eax, [RSdwPageSize]
	Jmp > L2
:	Mov Ecx, [RSdwPageSize]
	Xor Edx, Edx
	Div Ecx
	Add Eax, 1
	Mul Ecx
L2:	Add Eax, [Ebx + EDITORDATA.lBufferLength]
	Mov [Ebx + EDITORDATA.lBufferLength], Eax
	Add Eax, 8
	Invoke VirtualAlloc, 0, Eax, MEM_COMMIT, PAGE_READWRITE
	Mov [Ebx + EDITORDATA.lpszMemPtr], Eax
	Mov B[Eax], 13
	Mov B[Eax + 1], 10
	Add Eax, 2
	Mov [Ebx + EDITORDATA.lpszText], Eax
	Invoke CreateFile, [Ebx + EDITORDATA.lpszLine], GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL
	Mov [hHandle], Eax
	Invoke ReadFile, [hHandle], [Ebx + EDITORDATA.lpszText], [Ebx + EDITORDATA.lTextLength], Addr dwBytes, NULL
	Invoke CloseHandle, [hHandle]
	Mov Eax, [dwBytes]
	Mov [Ebx + EDITORDATA.lTextLength], Eax
	Add Eax, [Ebx + EDITORDATA.lpszText]
	Mov B[Eax], 13
	Mov B[Eax + 1], 10
	Mov B[Eax + 2], 0
	Invoke DeleteFile, [Ebx + EDITORDATA.lpszLine]
	Ret
EndF

;===========================================================================;
; Name:		rsSaveUndoBufer                                                 ;
;                                                                           ;
; Function:	Saves the undo buffer contents (one key strokes)                ;
;                                                                           ;
; On enter: Ebx = Pointer to editor's data structure                        ;
;===========================================================================;
rsSaveUndoBuffer Frame
	Local chr:RSSCHARSEL

	Mov Eax, [Ebx + EDITORDATA.chrPos.lMin]
	Mov [chr.lMin], Eax
	Mov Eax, [Ebx + EDITORDATA.chrPos.lMax]
	Mov [chr.lMax], Eax
	Mov Eax, [Ebx + EDITORDATA.lUndoStart]
	Mov [Ebx + EDITORDATA.chrPos.lMin], Eax
	Mov [Ebx + EDITORDATA.chrPos.lMax], Eax
	Invoke rsSaveUndoRedoText, [Ebx + EDITORDATA.lpszUndoText]
	Mov Eax, [Ebx + EDITORDATA.lpszUndoText]
	Mov B[Eax], 0
	Mov D[Ebx + EDITORDATA.lUndoStart], (-1)
	Mov Eax, [chr.lMin]
	Mov [Ebx + EDITORDATA.chrPos.lMin], Eax
	Mov Eax, [chr.lMax]
	Mov [Ebx + EDITORDATA.chrPos.lMax], Eax
	Ret
EndF

;===========================================================================;
; Name:		rsSaveUndoRedoText                                              ;
;                                                                           ;
; Function:	Saves blocks of text for undo / redo operations                 ;
;                                                                           ;
; Params:	lpszNewText = Address of new text                               ;
;                                                                           ;
; On enter: Ebx = Pointer to editor's data structure                        ;
;===========================================================================;
rsSaveUndoRedoText Frame lpszNewText Uses Edx, Esi
	Local lSize1:D, lSize2:D, lpch:D

	Cmp D[Ebx + EDITORDATA.lpUndoBuffer], NULL
	Jne >
	Ret
:	Mov Esi, [Ebx + EDITORDATA.lpUndoBuffer]
	Mov Eax, [Ebx + EDITORDATA.lUndoCount]
	Shl Eax, 2
	Add Esi, Eax
	Mov Eax, [Ebx + EDITORDATA.chrPos.lMax]
	Sub Eax, [Ebx + EDITORDATA.chrPos.lMin]
	Mov [lSize1], Eax
	Invoke rsGetStringLength, [lpszNewText]
	Mov [lSize2], Eax
	Cmp D[lSize1], 0
	Jg >
	Cmp D[lSize2], 0
	Jg >
	Ret
:	Cmp D[Esi], NULL
	Je >
	Invoke GlobalFree, [Esi]
	Mov D[Esi], NULL
:	Mov Eax, [lSize1]
	Add Eax, [lSize2]
	Add Eax, 18
	Invoke GlobalAlloc, (GMEM_MOVEABLE Or GMEM_DDESHARE Or GMEM_ZEROINIT), Eax
	Mov [Esi], Eax
	Invoke GlobalLock, Eax
	Mov [lpch], Eax
	Add D[lpch], 16
	Mov Edx, [Ebx + EDITORDATA.lVScrollPos]
	Mov [Eax], Edx
	Mov Edx, [Ebx + EDITORDATA.lHScrollPos]
	Mov [Eax + 4], Edx
	Mov Edx, [Ebx + EDITORDATA.chrPos.lMin]
	Mov [Eax + 8], Edx
	Mov Edx, [Ebx + EDITORDATA.chrPos.lMax]
	Mov [Eax + 12], Edx
	Inc D[lSize1]
	Mov Eax, [Ebx + EDITORDATA.lpszText]
	Add Eax, [Ebx + EDITORDATA.chrPos.lMin]
	Invoke lstrcpyn, [lpch], Eax, [lSize1]
	Inc D[lSize2]
	Mov Eax, [lpch]
	Add Eax, [lSize1]
	Invoke lstrcpyn, Eax, [lpszNewText], [lSize2]
	Invoke GlobalUnlock, [Esi]
	Inc D[Ebx + EDITORDATA.lUndoCount]
	Mov Eax, [Ebx + EDITORDATA.lUndoCount]
	Cmp Eax, [Ebx + EDITORDATA.lUndoLimit]
	Jl >
	Mov D[Ebx + EDITORDATA.lUndoCount], 0
:	Invoke rsClearNextUndoEntry
	Ret
EndF

;===========================================================================;
; Name:		rsScroll                                                        ;
;                                                                           ;
; Function:	Scrolls the specified number of lines and/or columns            ;
;                                                                           ;
; Params:   lLines   = Number of lines to be scrolled                       ;
;           lColumns = Number of colums to be scrolled                      ;
;                                                                           ;
; On enter: Ebx = Pointer to editor's data structure                        ;
;                                                                           ;
; Remarks:  To scroll to left/top, specify negative values                  ;
;===========================================================================;
rsScroll Frame lLines, lColumns Uses Edi
	Cmp D[lLines], 0
	Je > L2
	Mov Edi, [lLines]
	Add Edi, [Ebx + EDITORDATA.lVScrollPos]
	Cmp Edi, 0
	Jge >
	Xor Edi, Edi
:	Mov Eax, [Ebx + EDITORDATA.lLines]
	Cmp Eax, [Ebx + EDITORDATA.lVScrollPage]
	Jl >
	Sub Eax, [Ebx + EDITORDATA.lVScrollPage]
:	Cmp Eax, Edi
	Jge >
	Mov Edi, Eax
:	Invoke rsGetLineIndex, Edi
	Mov [Ebx + EDITORDATA.lFirstLineIndex], Eax
	Mov [Ebx + EDITORDATA.lVScrollPos], Edi

L2:	Cmp D[lColumns], 0
	Jne >
	Ret
:	Mov Edi, [lColumns]
	Add Edi, [Ebx + EDITORDATA.lHScrollPos]
	Cmp Edi, 0
	Jge >
	Xor Edi, Edi
:	Mov Eax, [Ebx + EDITORDATA.lHScrollMax]
	Sub Eax, [Ebx + EDITORDATA.lHScrollPage]
	Cmp Eax, Edi
	Jge >
	Mov Edi, Eax
:	Mov [Ebx + EDITORDATA.lHScrollPos], Edi
	Ret
EndF

;===========================================================================;
; Name:		rsSearchCaseDown                                                ;
;                                                                           ;
; Function:	Searches text down (case sensitive) from a specified position   ;
;                                                                           ;
; Params:	lpText   = Buffer containing the text to search for             ;
;           lPointer = Address of the first char in the editor text buffer  ;
;           lpFirst  = First address where to search for                    ;
;           lpLast   = Last address where to search for                     ;
;                                                                           ;
; Returns:  The character index of the text or -1 if not found in Eax       ;
;===========================================================================;
rsSearchCaseDown Frame lpText, lPointer, lpFirst, lpLast Uses Ecx, Edx, Edi, Esi
	Mov Esi, [lpFirst]
	Mov Ecx, [lpText]
L2:	Mov Edi, Ecx
	Mov Edx, Esi
:	Cmp Esi, [lpLast]
	Jg > L6
	Mov Ah, [Edi]
	Or Ah, Ah
	Jz > L4
	Inc Edi
	Mov Al, [Esi]
	Inc Esi
	Cmp Al, Ah
	Je <
	Jmp < L2
L4:	Mov Eax, Edx
	Sub Eax, [lPointer]
	Ret
L6:	Mov Eax, (-1)
	Ret
EndF

;===========================================================================;
; Name:		rsSearchCaseUp                                                  ;
;                                                                           ;
; Function:	Searches text up (case sensitive) from a specified position     ;
;                                                                           ;
; Params:	lpText   = Buffer containing the text to search for             ;
;           lPointer = Address of the first char in the editor text buffer  ;
;           lpFirst  = First address where to search for                    ;
;           lpLast   = Last address where to search for                     ;
;                                                                           ;
; Returns:  The character index of the text or -1 if not found in Eax       ;
;===========================================================================;
rsSearchCaseUp Frame lpText, lPointer, lpFirst, lpLast Uses Ecx, Edx, Edi, Esi
	Mov Esi, [lpFirst]
	Mov Ecx, [lpText]
L2:	Cmp Esi, [lpLast]
	Jl > L6
	Mov Edi, Ecx
	Mov Edx, Esi
:	Mov Ah, [Edi]
	Or Ah, Ah
	Jz > L4
	Inc Edi
	Mov Al, [Esi]
	Inc Esi
	Cmp Al, Ah
	Je <
	Mov Esi, Edx
	Dec Esi
	Jmp < L2
L4:	Mov Eax, Edx
	Sub Eax, [lPointer]
	Ret
L6:	Mov Eax, (-1)
	Ret
EndF

;===========================================================================;
; Name:		rsSearchNoCaseDown                                              ;
;                                                                           ;
; Function:	Searches text down (case insensitive) from a specified position ;
;                                                                           ;
; Params:	lpText   = Buffer containing the text to search for             ;
;           lPointer = Address of the first char in the editor text buffer  ;
;           lpFirst  = First address where to search for                    ;
;           lpLast   = Last address where to search for                     ;
;                                                                           ;
; Returns:  The character index of the text or -1 if not found in Eax       ;
;===========================================================================;
rsSearchNoCaseDown Frame lpText, lPointer, lpFirst, lpLast Uses Ecx, Edx, Edi, Esi
	Mov Esi, [lpFirst]
	Mov Ecx, [lpText]
L2:	Mov Edi, Ecx
	Mov Edx, Esi
:	Cmp Esi, [lpLast]
	Jg > L6
	Mov Ah, [Edi]
	Or Ah, Ah
	Jz > L4
	Inc Edi
	Mov Al, [Esi]
	Inc Esi
	Cmp Al, Ah
	Je <
	Cmp Ah, 65
	Jb < L2
	Or Ah, 32
	Cmp Al, Ah
	Je <
	Jmp < L2
L4:	Mov Eax, Edx
	Sub Eax, [lPointer]
	Ret
L6:	Mov Eax, (-1)
	Ret
EndF

;===========================================================================;
; Name:		rsSearchNoCaseUp                                                ;
;                                                                           ;
; Function:	Searches text up (case insensitive) from a specified position   ;
;                                                                           ;
; Params:	lpText   = Buffer containing the text to search for             ;
;           lPointer = Address of the first char in the editor text buffer  ;
;           lpFirst  = First address where to search for                    ;
;           lpLast   = Last address where to search for                     ;
;                                                                           ;
; Returns:  The character index of the text or -1 if not found in Eax       ;
;===========================================================================;
rsSearchNoCaseUp Frame lpText, lPointer, lpFirst, lpLast Uses Ecx, Edx, Edi, Esi
	Mov Esi, [lpFirst]
	Mov Ecx, [lpText]
L2:	Cmp Esi, [lpLast]
	Jl > L6
	Mov Edi, Ecx
	Mov Edx, Esi
:	Mov Ah, [Edi]
	Or Ah, Ah
	Jz > L4
	Inc Edi
	Mov Al, [Esi]
	Inc Esi
	Cmp Al, Ah
	Je <
	Cmp Ah, 65
	Jb >
	Or Ah, 32
	Cmp Al, Ah
	Je <
:	Mov Esi, Edx
	Dec Esi
	Jmp < L2
L4:	Mov Eax, Edx
	Sub Eax, [lPointer]
	Ret
L6:	Mov Eax, (-1)
	Ret
EndF

;===========================================================================;
; Name:		rsSearchText                                                    ;
;                                                                           ;
; Function:	Searches text according to flags                                ;
;                                                                           ;
; Params:	lpText   = Buffer containing the text to search for             ;
;           lFlags   = Flags specifying how to search                       ;
;           lPointer = Address of the first char in the editor text buffer  ;
;           lpFirst  = First address where to search for                    ;
;           lpLast   = Last address where to search for                     ;
;                                                                           ;
; Returns:  The character index of the text or -1 if not found in Eax       ;
;===========================================================================;
rsSearchText Frame lpText, lFlags, lPointer, lpFirst, lpLast
	Mov Eax, [lFlags]
	And Eax, RSC_MATCHCASE
	Jz > L2
	Mov Eax, [lFlags]
	And Eax, RSC_DOWN
	Jz >
	Invoke rsSearchCaseDown, [lpText], [lPointer], [lpFirst], [lpLast]
	Ret
:	Invoke rsSearchCaseUp, [lpText], [lPointer], [lpFirst], [lpLast]
	Ret
L2:	Mov Eax, [lFlags]
	And Eax, RSC_DOWN
	Jz >
	Invoke rsSearchNoCaseDown, [lpText], [lPointer], [lpFirst], [lpLast]
	Ret
:	Invoke rsSearchNoCaseUp, [lpText], [lPointer], [lpFirst], [lpLast]
	Ret
EndF

;============================================================================;
; Name:		rsSelectWord                                                     ;
;                                                                            ;
; Function:	Fills the 'chrPos' member of the edit data structure with the    ;
;           character indexes of the word which is in the position specified ;
;           by 'lPos' parameter. If there is no word, it fills the 'chrPos'  ;
;           member with the value specified by 'lPos' parameter.             ;
;                                                                            ;
; Params:	lPos    = Character index of any part of the text                ;
;			bSpaces = Specifies whether spaces and tabs (blanks) will be     ;
;                   = taken into account (TRUE = Yes).                       ;
;                                                                            ;
; On enter: Ebx = Pointer to editor's data structure                         ;
;============================================================================;
rsSelectWord Frame lPos, bSpaces Uses Ecx, Esi
	Local ch1:B, ch2:B

	Mov Esi, [Ebx + EDITORDATA.lpszText]
	Mov Ecx, [lPos]
	Mov Al, [Esi + Ecx]
	Mov [ch1], Al
	Mov Al, [Esi + Ecx - 1]
	Mov [ch2], Al
	Cmp D[bSpaces], 0
	Jne > L4
	Cmp B[ch1], ' '
	Je >
	Cmp B[ch1], 9
	Jne > L4
:	Cmp B[ch2], ' '
	Je > L2
	Cmp B[ch2], 9
	Jne > L4
L2:	Mov [Ebx + EDITORDATA.chrPos.lMin], Ecx
	Mov [Ebx + EDITORDATA.chrPos.lMax], Ecx
	Ret
L4:	Cmp B[ch2], 10
	Jne > L6
	Mov [Ebx + EDITORDATA.chrPos.lMin], Ecx
:	Invoke rsIsAlphaNumeric, [Esi + Ecx]
	Or Eax, Eax
	Jz >
	Inc Ecx
	Jmp <
:	Mov [Ebx + EDITORDATA.chrPos.lMax], Ecx
	Ret
L6:	Cmp B[ch1], 13
	Jne >
	Mov [Ebx + EDITORDATA.chrPos.lMax], Ecx
	Invoke rsFindPrevWord, Ecx
	Mov [Ebx + EDITORDATA.chrPos.lMin], Eax
	Ret
:	Cmp B[ch1], ' '
	Je >> L12
	Cmp B[ch1], 9
	Je >> L12
	Mov Al, [ch1]
	Invoke rsIsAlphaNumeric, Eax
	Or Eax, Eax
	Jz > L8
	Mov Al, [ch2]
	Invoke rsIsAlphaNumeric, Eax
	Or Eax, Eax
	Jz >
	Invoke rsFindPrevWord, Ecx
	Mov Ecx, Eax
:	Mov [Ebx + EDITORDATA.chrPos.lMin], Ecx
:	Inc Ecx
	Invoke rsIsAlphaNumeric, [Esi + Ecx]
	Or Eax, Eax
	Jnz <
	Mov [Ebx + EDITORDATA.chrPos.lMax], Ecx
	Ret
L8:	Cmp D[bSpaces], 0
	Je > L10
	Mov Al, [ch2]
	Invoke rsIsAlphaNumeric, Eax
	Or Eax, Eax
	Jz > L10
	Invoke rsFindPrevWord, Ecx
	Mov [Ebx + EDITORDATA.chrPos.lMin], Eax
	Mov Ecx, Eax
:	Inc Ecx
	Invoke rsIsAlphaNumeric, [Esi + Ecx]
	Or Eax, Eax
	Jnz <
	Mov [Ebx + EDITORDATA.chrPos.lMax], Ecx
	Ret
L10:
	Mov Eax, [lPos]
	Mov [Ebx + EDITORDATA.chrPos.lMin], Eax
	Mov Ecx, [Ebx + EDITORDATA.chrSel.lMin]
	Cmp Ecx, [Ebx + EDITORDATA.chrSel.lMax]
	Jne >
	Inc Eax
:	Mov [Ebx + EDITORDATA.chrPos.lMax], Eax
	Ret
L12:
	Mov Al, [ch2]
	Invoke rsIsAlphaNumeric, Eax
	Or Eax, Eax
	Jz >
	Mov [Ebx + EDITORDATA.chrPos.lMax], Ecx
	Invoke rsFindPrevWord, Ecx
	Mov [Ebx + EDITORDATA.chrPos.lMin], Eax
	Ret
:	Mov Eax, [lPos]
	Mov [Ebx + EDITORDATA.chrPos.lMin], Eax
	Mov Ecx, [Ebx + EDITORDATA.chrSel.lMin]
	Cmp Ecx, [Ebx + EDITORDATA.chrSel.lMax]
	Jne >
	Dec Eax
:	Mov [Ebx + EDITORDATA.chrPos.lMax], Eax
	Ret
EndF

;===========================================================================;
; Name:		rsSendNotifyMessage                                             ;
;                                                                           ;
; Function:	Sends a WM_NOTIFY message to the parent window                  ;
;                                                                           ;
; Params:	uCode = The code of the message (NM_CLICK, NM_DBLCLK, etc.)     ;
;                                                                           ;
; On enter: Ebx = Pointer to editor's data structure                        ;
;===========================================================================;
rsSendNotifyMessage Frame uCode Uses Ecx
	Local sch:SELCHANGE

	Mov Eax, [Ebx + EDITORDATA.hWnd]
	Mov [sch.nmhdr.hwndFrom], Eax
	Mov D[sch.nmhdr.idFrom], 0
	Mov Eax, [uCode]
	Mov [sch.nmhdr.code], Eax
	Cmp D[uCode], EN_SELCHANGE
	Jne > L2
	Mov Eax, [Ebx + EDITORDATA.chrPos.lMax]
	Mov [sch.chrg.cpMax], Eax
	Mov Ecx, SEL_EMPTY
	Sub Eax, [Ebx + EDITORDATA.chrPos.lMin]
	Jz >
	Mov Ecx, SEL_TEXT
	Cmp Eax, 1
	Je >
	Or Ecx, SEL_MULTICHAR
:	Mov [sch.seltyp], Cx
	Mov Eax, [Ebx + EDITORDATA.chrPos.lMin]
	Mov [sch.chrg.cpMin], Eax
L2:	Invoke SendMessage, [Ebx + EDITORDATA.hWndOwner], WM_NOTIFY, 0, Addr sch
	Ret
EndF

;===========================================================================;
; Name:		rsSetCaret                                                      ;
;                                                                           ;
; Function:	Positions the caret in the x, y coordinates (specified by the   ;
;           members 'ptPos.x' and 'ptPos.y' of the data structure)          ;
;                                                                           ;
; On enter: Ebx = Pointer to editor's data structure                        ;
;===========================================================================;
rsSetCaret Frame
	Local pt:POINTL

	Cmp D[Ebx + EDITORDATA.bReadOnly], 0
	Je >
	Ret
:	Push Ecx
	Push Edx
	Invoke rsGetRealColWidth
	Cmp Eax, 0
	Jl >
	Sub Eax, [Ebx + EDITORDATA.lHScrollPos]
:	Add Eax, [Ebx + EDITORDATA.lMarginWidth]

	Cmp Eax, [Ebx + EDITORDATA.lMarginWidth]
	Jge >
	Sub Eax, [Ebx + EDITORDATA.lMarginWidth]

:	Mov [pt.x], Eax
	Mov Ecx, [Ebx + EDITORDATA.szFont.cy]
	Mov Eax, [Ebx + EDITORDATA.ptPos.y]
	Sub Eax, [Ebx + EDITORDATA.lVScrollPos] ;lFirstLine]
	Mul Ecx
	Mov [pt.y], Eax
	Invoke SetCaretPos, [pt.x], [pt.y]
	Mov Eax, [Ebx + EDITORDATA.chrPos.lMin]
	Cmp Eax, [Ebx + EDITORDATA.chrPos.lMax]
	Jne > L2
	Cmp D[Ebx + EDITORDATA.bCaret], 0
	Jne > L4
	Mov D[Ebx + EDITORDATA.bCaret], TRUE
	Invoke ShowCaret, [Ebx + EDITORDATA.hWnd]
	Jmp > L4
L2:	Cmp D[Ebx + EDITORDATA.bCaret], 0
	Je > L4
	Mov D[Ebx + EDITORDATA.bCaret], FALSE
	Invoke HideCaret, [Ebx + EDITORDATA.hWnd]
L4:	Pop Edx
	Pop Ecx
	Ret
EndF

;On enter: Ebx = Pointer to editor's data structure
rsSetCursorCoordinates:
	Invoke rsGetLineFromChar, [Ebx + EDITORDATA.chrSel.lMax], TRUE
	Mov [Ebx + EDITORDATA.ptPos.y], Eax
	Invoke rsGetLineLength, [Ebx + EDITORDATA.lLineIndex]
	Cmp Eax, 0
	Jle >
	Dec Eax
:	Mov [Ebx + EDITORDATA.lCols], Eax
	Mov Eax, [Ebx + EDITORDATA.chrSel.lMax]
	Sub Eax, [Ebx + EDITORDATA.lLineIndex]
	Cmp Eax, 0
	Jge >
	Xor Eax, Eax
:	Mov [Ebx + EDITORDATA.ptPos.x], Eax
	Invoke rsExpandLineAndGetSelection, [Ebx + EDITORDATA.lLineIndex], NULL
	Mov [Ebx + EDITORDATA.lRealCols], Eax
	Ret

;===========================================================================;
; Name:		rsSetFirstLineIndex                                             ;
;                                                                           ;
; Function:	Sets the line index for the first visible line                  ;
;                                                                           ;
; On enter: Ebx = Pointer to editor's data structure                        ;
;===========================================================================;
rsSetFirstLineIndex:
	Mov Eax, [Ebx + EDITORDATA.lVScrollPos]
	Push Eax
	Mov D[Ebx + EDITORDATA.lVScrollPos], 0
	Mov D[Ebx + EDITORDATA.lFirstLineIndex], 0
	Invoke rsGetLineIndex, Eax
	Mov [Ebx + EDITORDATA.lFirstLineIndex], Eax
	Pop Eax
	Mov [Ebx + EDITORDATA.lVScrollPos], Eax
	Invoke rsSetCursorCoordinates
	Ret

;On enter: Ebx = Pointer to editor's data structure
rsSetFirstVisibleLine Frame lNewVScrollPos Uses Edi
	Invoke rsGetLineFromChar, [Ebx + EDITORDATA.chrPos.lMin], FALSE
	Mov Edi, Eax
	Cmp Eax, [Ebx + EDITORDATA.lVScrollPos]
	Jge >
L2:	Mov Eax, [lNewVScrollPos]
	Mov [Ebx + EDITORDATA.lVScrollPos], Eax
	Invoke rsSetFirstLineIndex
	Ret
:	Mov Eax, [Ebx + EDITORDATA.lVScrollPos]
	Add Eax, [Ebx + EDITORDATA.lVScrollPage]
	Cmp Edi, Eax
	Jge < L2
	Ret
EndF

;On enter: Ebx = Pointer to editor's data structure
rsSetLines: Uses Esi
	Mov Esi, [Ebx + EDITORDATA.lpszText]
	Xor Eax, Eax
	Mov [Ebx + EDITORDATA.lLines], Eax
	Mov Ah, 10
L2:	Cmp [Esi], Al
	Je > L4
	Cmp [Esi], Ah
	Jne >
	Inc D[Ebx + EDITORDATA.lLines]
:	Inc Esi
	Jmp < L2
L4:	Ret
EndU

;On enter: Ebx = Pointer to editor's data structure
rsSetPosition Frame lMin, lMax Uses Ecx, Edx, Edi, Esi
	Xor Edx, Edx
	Xor Edi, Edi
	Mov Eax, [Ebx + EDITORDATA.chrSel.lMin]
	Cmp Eax, [Ebx + EDITORDATA.chrSel.lMax]
	Je >
	Inc Edi
:	Cmp Eax, [lMin]
	Je >
	Inc Edx
	Jmp > L2
:	Mov Eax, [lMax]
	Cmp Eax, [Ebx + EDITORDATA.chrSel.lMax]
	Je > L2
	Inc Edx
L2:	Mov Esi, [Ebx + EDITORDATA.lpszText]
	Mov Eax, [lMin]
	Cmp B[Esi + Eax], 10
	Jne >
	Dec Eax
:	Cmp Eax, [Ebx + EDITORDATA.lTextLength]
	Jle >
	Mov Eax, [Ebx + EDITORDATA.lTextLength]
:	Mov [Ebx + EDITORDATA.chrSel.lMin], Eax
	Mov Ecx, [lMax]
	Cmp B[Esi + Ecx], 10
	Jne >
	Dec Ecx
:	Cmp Ecx, [Ebx + EDITORDATA.lTextLength]
	Jle >
	Mov Ecx, [Ebx + EDITORDATA.lTextLength]
:	Mov [Ebx + EDITORDATA.chrSel.lMax], Ecx
	Cmp Ecx, Eax
	Je >
	Mov D[Ebx + EDITORDATA.bChanged], TRUE
:	Jge >
	Mov [Ebx + EDITORDATA.chrPos.lMax], Eax
	Mov [Ebx + EDITORDATA.chrPos.lMin], Ecx
	Ret
:	Jg >
	Or Edi, Edi
	Jz >
	Mov D[Ebx + EDITORDATA.bChanged], TRUE
:	Mov [Ebx + EDITORDATA.chrPos.lMin], Eax
	Mov [Ebx + EDITORDATA.chrPos.lMax], Ecx
	Mov Eax, Edx
	Ret
EndF

;On enter: Ebx = Pointer to editor's data structure
rsSetSelection Frame lMin, lMax Uses Ecx, Edx, Edi
	Invoke rsSetPosition, [lMin], [lMax]
	Push Eax
	Invoke rsSetCursorCoordinates
	Mov Eax, [Ebx + EDITORDATA.lVScrollPos]
	Add Eax, [Ebx + EDITORDATA.lVScrollPage]
	Cmp [Ebx + EDITORDATA.ptPos.y], Eax
	Jl >
	Mov Ecx, [Ebx + EDITORDATA.ptPos.y]
	Sub Ecx, Eax
	Add Ecx, 1
	Invoke rsScroll, Ecx, 0
	Mov D[Ebx + EDITORDATA.bChanged], TRUE
	Jmp > L2
:	Mov Ecx, [Ebx + EDITORDATA.ptPos.y]
	Cmp Ecx, [Ebx + EDITORDATA.lVScrollPos]
	Jge > L2
	Sub Ecx, [Ebx + EDITORDATA.lVScrollPos]
	Jz > L2
	Invoke rsScroll, Ecx, 0
	Mov D[Ebx + EDITORDATA.bChanged], TRUE
L2:	Invoke rsGetRealColWidth
	Mov Edi, Eax
	Add Eax, [Ebx + EDITORDATA.lMarginWidth]
	Add Eax, [Ebx + EDITORDATA.lCaretWidth]
	Mov Edx, [Ebx + EDITORDATA.szSize.cx]
	Add Edx, [Ebx + EDITORDATA.lHScrollPos]
	Cmp Eax, Edx
	Jg > L4
	Mov Eax, Edi
	Cmp Eax, [Ebx + EDITORDATA.lHScrollPos]
	Jg > L6
	Sub Eax, [Ebx + EDITORDATA.lHScrollPos]
	Jz > L6
	Sub Eax, [Ebx + EDITORDATA.szFont.cx]
	Invoke rsScroll, 0, Eax
	Mov D[Ebx + EDITORDATA.bChanged], TRUE
	Jmp > L6
L4:	Mov Edi, Eax
	Sub Eax, Edx
	Add Eax, [Ebx + EDITORDATA.szFont.cx]
	Invoke rsScroll, 0, Eax
	Mov D[Ebx + EDITORDATA.bChanged], TRUE
L6:	Invoke rsUpdateScrollBars
	Cmp D[Ebx + EDITORDATA.bSelCol], 0
	Je >
	Mov D[Ebx + EDITORDATA.bSelCol], FALSE
	Mov Eax, [Ebx + EDITORDATA.lRealCol]
	Mov [Ebx + EDITORDATA.lSelCol], Eax
:	Cmp D[Ebx + EDITORDATA.bChanged], FALSE
	Je > L8
	Invoke rsUpdateEditor, FALSE
	Mov D[Ebx + EDITORDATA.bChanged], FALSE
L8:	Pop Eax
    Or Eax, Eax
    Je >
	Mov Eax, [Ebx + EDITORDATA.dwEventMask]
	And Eax, EV_SELCHANGE
	Jz >
	Invoke rsSendNotifyMessage, EN_SELCHANGE
:	Invoke rsSetCaret
	Ret
EndF

;===========================================================================;
; Name:		rsStoreUndoText                                                 ;
;                                                                           ;
; Function:	Stores modified text for undo operations                        ;
;                                                                           ;
; On enter: Ebx = Pointer to editor's data structure                        ;
;===========================================================================;
rsStoreUndoText Frame lpszNewText Uses Edi
	Cmp D[Ebx + EDITORDATA.lpUndoBuffer], NULL
	Jne >
	Ret
:	Mov Edi, [Ebx + EDITORDATA.lpszUndoText]
	Mov Eax, [Ebx + EDITORDATA.chrPos.lMin]
	Cmp Eax, [Ebx + EDITORDATA.chrPos.lMax]
	Jne >> L2
	Invoke rsGetStringLength, [lpszNewText]
	Cmp Eax, 1
	Jne > L2
	Mov Eax, [lpszNewText]
	Invoke rsIsAlphaNumeric, [Eax]
	Or Eax, Eax
	Jz > L2
	Cmp B[Edi], 0
	Jne >
	Mov Eax, [Ebx + EDITORDATA.chrPos.lMin]
	Mov [Ebx + EDITORDATA.lUndoStart], Eax
:	Invoke rsGetStringLength, Edi
	Add Eax, [Ebx + EDITORDATA.lUndoStart]
	Cmp Eax, [Ebx + EDITORDATA.chrPos.lMin]
	Je >
	Invoke rsSaveUndoBuffer
	Mov Eax, [Ebx + EDITORDATA.chrPos.lMin]
	Mov [Ebx + EDITORDATA.lUndoStart], Eax
:	Invoke lstrcat, Edi, [lpszNewText]
	Invoke lstrlen, Edi
	Cmp Eax, 254
	Jl >
	Invoke rsSaveUndoBuffer
	Ret
:	Invoke rsClearNextUndoEntry
	Ret
L2:	Cmp B[Edi], 0
	Je >
	Invoke rsSaveUndoBuffer
:	Invoke rsSaveUndoRedoText, [lpszNewText]
	Ret
EndF

;===========================================================================;
; Name:		rsUndoAction                                                    ;
;                                                                           ;
; Function:	Performs an undo action (if any)                                ;
;                                                                           ;
; On enter:  Ebx = Pointer to editor's data structure                       ;
;===========================================================================;
rsUndoAction Frame
	Local lpch:D

	Cmp D[Ebx + EDITORDATA.lpUndoBuffer], NULL
	Jne >
	Xor Eax, Eax
	Ret
:	Push Ecx, Edx, Esi
	Mov D[Ebx + EDITORDATA.bSelCol], TRUE
	Mov Esi, [Ebx + EDITORDATA.lpszUndoText]
	Cmp B[Esi], 0
	Je >
	Mov Eax, [Ebx + EDITORDATA.lUndoStart]
	Mov [Ebx + EDITORDATA.chrPos.lMin], Eax
	Mov [Ebx + EDITORDATA.chrPos.lMax], Eax
	Invoke rsSaveUndoRedoText, Esi
	Invoke rsGetStringLength, Esi
	Add Eax, [Ebx + EDITORDATA.chrPos.lMax]
	Mov [Ebx + EDITORDATA.chrPos.lMax], Eax
	Mov B[Esi], 0
	Mov D[Ebx + EDITORDATA.lUndoStart], (-1)
	Invoke rsDecrementUndoCount
	Invoke rsReplaceSelection, Esi, (-1)
	Invoke rsSetFirstLineIndex
	Mov D[Ebx + EDITORDATA.bChanged], TRUE
	Invoke rsSetSelection, [Ebx + EDITORDATA.chrPos.lMin], [Ebx + EDITORDATA.chrPos.lMax]
	Call rsCheckModified
	Mov Eax, TRUE
	Jmp >> L2
:	Invoke rsDecrementUndoCount
	Or Eax, Eax
	Jz >> L2
	Mov Esi, [Ebx + EDITORDATA.lpUndoBuffer]
	Mov Eax, [Ebx + EDITORDATA.lUndoCount]
	Shl Eax, 2
	Add Esi, Eax
	Cmp D[Esi], NULL
	Jne >
	Xor Eax, Eax
	Jmp >> L2
:	Push [Ebx + EDITORDATA.dwEventMask]
	Mov D[Ebx + EDITORDATA.dwEventMask], 0
	Invoke GlobalLock, [Esi]
	Mov [lpch], Eax
	Mov Edx, Eax
	Push Edx
	Add D[lpch], 16
	Mov Eax, [Edx + 4]
	Mov [Ebx + EDITORDATA.lHScrollPos], Eax
	Mov Eax, [Edx + 8]
	Mov [Ebx + EDITORDATA.chrPos.lMin], Eax
	Invoke rsGetStringLength, [lpch]
	Inc Eax
	Add Eax, [lpch]
	Invoke rsGetStringLength, Eax
	Add Eax, [Edx + 8]
	Mov [Ebx + EDITORDATA.chrPos.lMax], Eax
	Mov Eax, [Edx]
	Invoke rsSetFirstVisibleLine, Eax
	Invoke rsReplaceSelection, [lpch], (-1)
	Pop Edx
	Invoke rsCheckFirstLine
	Invoke rsSetFirstLineIndex
	Mov Ecx, [Edx + 8]
	Inc Ecx
	Cmp Ecx, [Edx + 12]
	Je >
	Dec Ecx
:	Pop [Ebx + EDITORDATA.dwEventMask]
	Mov D[Ebx + EDITORDATA.bChanged], TRUE
	Invoke rsSetSelection, Ecx, [Edx + 12]
	Invoke GlobalUnlock, [Esi]
	Call rsCheckModified
	Mov Eax, TRUE
L2:	Pop Esi, Edx, Ecx
	Ret
EndF

;On enter: Ebx = Pointer to editor's data structure
rsUpdateEditor Frame bNow
	Invoke InvalidateRect, [Ebx + EDITORDATA.hWnd], NULL, FALSE
	Cmp D[bNow], 0
	Je >
	Invoke SendMessage, [Ebx + EDITORDATA.hWnd], WM_PAINT, 0, 0
:	Ret
EndF

;On enter: Ebx = Pointer to editor's data structure
rsUpdateScrollBars: Uses Ecx
	Cmp D[Ebx + EDITORDATA.bVScrollBar], 0
	Je >
	Mov Eax, [Ebx + EDITORDATA.lVScrollPos]
	Mov [RSsci.nPos], Eax
	Mov Eax, [Ebx + EDITORDATA.lVScrollPage]
	Mov [RSsci.nPage], Eax
	Mov D[RSsci.nMin], 0
	Mov Eax, [Ebx + EDITORDATA.lLines]
	Sub Eax, 1
	Mov [RSsci.nMax], Eax
	Invoke SetScrollInfo, [Ebx + EDITORDATA.hWnd], SB_VERT, Addr RSsci, TRUE
:	Cmp D[Ebx + EDITORDATA.bHScrollBar], 0
	Je >
	Mov Eax, [Ebx + EDITORDATA.lHScrollPos]
	Mov D[RSsci.nPos], Eax
	Mov Eax, [Ebx + EDITORDATA.lHScrollPage]
	Mov [RSsci.nPage], Eax
	Mov D[RSsci.nMin], 0
	Mov Eax, [Ebx + EDITORDATA.lHScrollMax]
	Sub Eax, 1
	Mov [RSsci.nMax], Eax
	Invoke SetScrollInfo, [Ebx + EDITORDATA.hWnd], SB_HORZ, Addr RSsci, TRUE
:	Invoke rsSetCaret
	Ret
EndU
