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
	Invoke pegObject, [hWnd], IDC_WINMAIN_BTNOK
	Return (TRUE)
; End OnwinMainResize
EndU

pegObject Frame hWnd, idControl

	Local hButton:D, pBox:RECT

	; 1. Get a handle on the button
	Invoke GetWindowItem, [hWnd], [idControl]
	Mov [hButton], Eax

	; 2. Get the new size of the window's client area
	Invoke GetClientRect, [hWnd], Addr pBox

	; 3. Get the width of the button and subtract it from the width
	; 	 of the client area, together with any border
	Invoke GetWidth, [hButton]			; Get buttonð current width
	Add Eax, [pegBorder]							; Border of 4
	Mov Ebx, [pBox.right]				; Retrieve parents width
	Sub Ebx, Eax						; Subtract buttons (plus border) width from it.

	; 4. Set left position of button to above value
	Invoke SetLeft, [hButton], Ebx		; Set buttons left position to new value

	; 5. Get height of button and subtract from height of client area
	; 	 together with any border

	Invoke GetHeight, [hButton]			; Get buttons current height
	Add Eax, [pegBorder]
	Mov Ebx, [pBox.bottom]
	Sub Ebx, Eax

	; 6. Set top position of button to above value
	Invoke SetTop, [hButton], Ebx

	; 7. Return to main event loop
	Return (TRUE)

; End pegObject

EndF


winMainbtnOK Frame hWnd, uMsg, wParam, lParam
	Xor Eax, Eax	;Return (FALSE)
	Ret
EndF
