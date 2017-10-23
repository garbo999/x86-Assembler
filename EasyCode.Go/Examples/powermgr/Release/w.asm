.Const

.Data

MN_MESSAGES	DD ECM_AFTERCREATE, OnmnAfterCreate
			DD WM_CLOSE, OnmnClose

.Code

wProcedure Frame hWnd, uMsg, wParam, lParam
	Mov Eax, [uMsg]
	Mov Ecx, SizeOf MN_MESSAGES / 8
	Mov Edx, Addr MN_MESSAGES
:	Dec Ecx
	Js > L2
	Cmp [Edx + Ecx * 8], Eax
	Jne <
	Call [Edx + Ecx * 8 + 4]
	Ret
L2:	Xor Eax, Eax	;Return (FALSE)
	Ret
EndF

OnmnAfterCreate:
	UseData wProcedure

	Invoke MoveWindow, [hWnd], 0, 0, 0, 0, 1
	Invoke Create, TEXT("mn"), 0, ecModal, 0
	Mov Eax, (-1)	;Return (-1)
	Ret
EndU

OnwClose:
	UseData wProcedure
	;=========================
	;Write the final code here
	;=========================
	Invoke IsModal, [hWnd]
	Or Eax, Eax		;Cmp Eax, FALSE
	Jz >
	Invoke EndModal, [hWnd], IDCANCEL
	Mov Eax, TRUE	;Return (TRUE)
:	Ret
EndU
