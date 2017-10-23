.Const

.Data

WINMAIN_MESSAGES	DD WM_CREATE, OnwinMainCreate
					DD WM_CLOSE, OnwinMainClose
					DD WM_SIZE, OnwinMainResize

pegBorder			DD 4

.Code

winMainProcedure Frame hWnd, uMsg, wParam, lParam
	Mov Eax, [uMsg]
	Mov Ecx, SizeOf WINMAIN_MESSAGES / 8
	Mov Edx, Addr WINMAIN_MESSAGES
:	Dec Ecx
	Js > L2
	Cmp [Edx + Ecx * 8], Eax
	Jne <
	Call [Edx + Ecx * 8 + 4]
	Ret
L2:	Xor Eax, Eax	;Return (FALSE)
	Ret
EndF

OnwinMainCreate: UseData winMainProcedure
	;==================================
	;Write the initialization code here
	;==================================
	Xor Eax, Eax	;Return (FALSE)
	Ret
EndU

OnwinMainClose: UseData winMainProcedure
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

winMainbtnExit Frame hWnd, uMsg, wParam, lParam
	Xor Eax, Eax	;Return (FALSE)
	Ret
EndF

OnwinMainResize: UseData winMainProcedure
	Invoke pegObject, [hWnd], IDC_WINMAIN_BTNEXIT
	Return (TRUE)
; End OnwinMainResize
EndU

winMainbtnOK Frame hWnd, uMsg, wParam, lParam
	Xor Eax, Eax	;Return (FALSE)
	Ret
EndF
