;EasyCodeName=pegObject,1
.Const

.Data

.Code

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