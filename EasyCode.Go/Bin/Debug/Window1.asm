.Const

.Data

WINDOW1_MESSAGES	DD WM_CREATE, OnWindow1Create
					DD WM_CLOSE, OnWindow1Close
					DD WM_COMMAND, OnWindow1ClickBtn

.Code

Window1Procedure Frame hWnd, uMsg, wParam, lParam
	Mov Eax, [uMsg]
	Mov Ecx, SizeOf WINDOW1_MESSAGES / 8
	Mov Edx, Addr WINDOW1_MESSAGES
:	Dec Ecx
	Js > L2
	Cmp [Edx + Ecx * 8], Eax
	Jne <
	Call [Edx + Ecx * 8 + 4]
	Ret
L2:	Xor Eax, Eax	;Return (FALSE)
	Ret
EndF

OnWindow1Create: UseData Window1Procedure
	;==================================
	;Write the initialization code here
	;==================================
	Xor Eax, Eax	;Return (FALSE)
	Ret
EndU

OnWindow1Close: UseData Window1Procedure
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

OnWindow1ClickBtn: UseData Window1Procedure

	Mov Eax, [wParam]
	Cmp Ax, IDC_WINDOW1_BUTTON1		; Is this button 1?
		Jnz >>.exitProcedure

	; This IS button 1 so check for left click
	Shr Eax, 16
	Cmp Ax, BN_CLICKED
		Jnz >>.exitProcedure		; Button 1 but not left click

	; Button 1 AND left click so process
	Invoke MessageBoxA, [hWnd], '...checking CPU temp...', 'CPU temperature', MB_ICONINFORMATION

.exitProcedure

	Return (TRUE)
EndU

Window1Button1 Frame hWnd, uMsg, wParam, lParam
	Xor Eax, Eax	;Return (FALSE)
	Ret
EndF
