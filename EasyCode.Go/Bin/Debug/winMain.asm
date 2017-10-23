.Const

.Data

WINMAIN_MESSAGES	DD WM_CREATE, OnwinMainCreate
					DD WM_CLOSE, OnwinMainClose
					DD WM_COMMAND, OnwinMainClickBtn

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
OnwinMainClickBtn: UseData winMainProcedure

	Mov Eax, [wParam]
	Cmp Ax, IDC_WINMAIN_BTN1		; Is this button 1?
		Jnz >.notButton1

	; This IS button 1 so check for left click
	Shr Eax, 16
	Cmp Ax, BN_CLICKED
		Jnz >.exitProcedure

	; Button 1 AND left click so process
	Invoke SetText, [hWnd], "You clicked button 1!!!"
	Return (TRUE)

	.notButton1						; This is not button 1

	Cmp Ax, IDC_WINMAIN_BTN2		; Is this button 2?
		Jnz >.exitProcedure

	; This IS button 2 so check for left click
	Shr Eax, 16
	Cmp Ax, BN_CLICKED
		Jnz >.exitProcedure

	; Button 2 AND left click so process
	Invoke SetText, [hWnd], "You clicked button 2!!!"
	Return (TRUE)

	.exitProcedure					; Neither button 1 nor button 2

	Return (FALSE)

; End OnwinMainClickBtn
EndU
winMainbtn1 Frame hWnd, uMsg, wParam, lParam
	Xor Eax, Eax	;Return (FALSE)
	Ret
EndF

winMainbtn2 Frame hWnd, uMsg, wParam, lParam
	Xor Eax, Eax	;Return (FALSE)
	Ret
EndF
