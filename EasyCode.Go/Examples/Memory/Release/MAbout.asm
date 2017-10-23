.Const

.Data

ABOUTMESSAGES	DD				WM_CREATE, OnAboutCreate
				DD				WM_COMMAND, OnAboutCommand
				DD				WM_CLOSE, OnAboutClose

.Code

MAboutProcedure Frame hWnd, uMsg, wParam, lParam
	Mov Eax, [uMsg]
	Mov Ecx, SizeOf ABOUTMESSAGES / 8
	Mov Edx, Addr ABOUTMESSAGES
:	Dec Ecx
	Js >.Default
	Cmp [Edx + Ecx * 8], Eax
	Jne <
	Call [Edx + Ecx * 8 + 4]
	Ret

.Default:
	Xor Eax, Eax	;Mov Eax, FALSE
	Ret
EndF

OnAboutCreate:
	UseData MAboutProcedure
	;Sets the MAbout window according to 'lParam'
	Invoke SetWindowPos, [hWnd], [lParam], 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE
	Mov Eax, TRUE
	Ret
EndU

OnAboutCommand:
	UseData MAboutProcedure
	Mov Eax, [wParam]
	;Checks if message is
	;from 'btnClose' object
	Cmp Ax, IDC_MABOUT_BTNCLOSE
	Je >
	Xor Eax, Eax
	Ret
:	Shr Eax, 16
	;Has button been clicked?
	Cmp Ax, BN_CLICKED
	Je >
	Xor Eax, Eax
	Ret
:	;Closes the MAbout window
	Invoke SendMessage, [hWnd], WM_CLOSE, 0, 0
	;Returns TRUE for no further processing
	Mov Eax, TRUE
	Ret
EndU

OnAboutClose:
	UseData MAboutProcedure
	;Check if it is a modal window
	Invoke IsModal, [hWnd]
	Or Eax, Eax
	Jz >
	;If it is, ends the modal mode
	;and closes the MAbout window
	Invoke EndModal, [hWnd], IDCANCEL
	;Returns TRUE for no further processing
	Mov Eax, TRUE
:	Ret
EndU

MAboutstcWeb Frame hWnd, uMsg, wParam, lParam
	Cmp D[uMsg], WM_LBUTTONDOWN
	Jne >.Exit
	Cmp D[wParam], MK_LBUTTON
	Jne >.Exit
	;Gets the parent window
	Invoke GetParent, [hWnd]
	;Runs the default explorer
	;with Easy Code web address
	Invoke ShellExecute, Eax, NULL, "http://www.easycode.cat", NULL, NULL, SW_SHOWNORMAL
	;Returns TRUE for no further processing
	Mov Eax, TRUE
	Ret

.Exit
	Xor Eax, Eax
	Ret
EndF
