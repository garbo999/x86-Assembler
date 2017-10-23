;EasyCodeName=RSMeter,1
.Const

MAX_METERS			Equ			20
MAX_LEDS			Equ			40

METER_DATA Struct
	lIndex			DD			?
	lHeight			DD			?
	lLedsOn			DD			?
	lMaxValue		DD			?
	lMinValue		DD			?
	lShape			DD			?
	lValue			DD			?
	lWidth			DD			?
	bVertical		DD			?
	wndOldProc		DD			?
	hWndMeter		DD	 		?
	hWndOwner		DD	 		?
	hBrush			DD			?
	hLedOnBrush		DD			?
	hLedArray		DD			MAX_LEDS Dup ?
EndS


.Data

lRSMeters			DD			0
lRSMHeight			DD			6
lRSMWidth			DD			10
hRSMLabelArray		DD			20 Dup 0
hLedOffBrush		DD			NULL

rc					RECT		<>


.Code

CreateMeter Frame hWndOwner, x, y, lFlags Uses Ebx, Edi, Esi
	Local dwStyle:D, dwExStyle:D, sz:SIZEL

	Cmp D[hLedOffBrush], NULL
	Jne >
	Invoke GetSysColor, COLOR_BTNFACE
	Sub Eax, 00404040H
	Invoke CreateSolidBrush, Eax
	Mov [hLedOffBrush], Eax
:	Invoke GetFreeIndex
	Cmp Eax, (-1)
	Jne >
L2:	Xor Eax, Eax
	Ret
:	Lea Esi, [hRSMLabelArray]
	Push Eax
	Shl Eax, 2
	Add Esi, Eax
	Invoke GlobalAlloc, GPTR, SizeOf METER_DATA
	Pop Ecx
	Or Eax, Eax
	Jz L2
	Mov [Esi], Eax
	Mov Esi, Eax
	Mov [Esi + METER_DATA.lIndex], Ecx
	Mov Eax, [lRSMHeight]
	Mov [Esi + METER_DATA.lHeight], Eax
	Mov Eax, [lRSMWidth]
	Mov [Esi + METER_DATA.lWidth], Eax
	Mov Eax, [hWndOwner]
	Mov [Esi + METER_DATA.hWndOwner], Eax
	Mov Eax, [lFlags]
	Mov Edx, Eax
	And Edx, 007FH
	Mov [Esi + METER_DATA.lShape], Edx
	And Eax, RSMETER_VERTICAL
	Jz >
	Mov D[Esi + METER_DATA.bVertical], TRUE
	Cmp D[Esi + METER_DATA.lShape], RSMETER_FLAT
	Jne > L4
	Dec D[Esi + METER_DATA.lHeight]
	Jmp > L4
:	Cmp D[Esi + METER_DATA.lShape], RSMETER_FLAT
	Jne > L4
	Dec D[Esi + METER_DATA.lWidth]
L4:	Mov D[dwStyle], (WS_CHILD | WS_VISIBLE)
	Mov D[dwExStyle], 0
	Mov Eax, [lFlags]
	Cmp Eax, RSMETER_INSET
	Jne >
	Or D[dwExStyle], WS_EX_STATICEDGE
	Jmp > L6
:	Cmp Eax, RSMETER_RAISED
	Jne >
	Or D[dwExStyle], WS_EX_DLGMODALFRAME
	Jmp > L6
:	Cmp Eax, RSMETER_BORDER
	Jne > L6
	Or D[dwStyle], WS_BORDER
L6:	Invoke GetParentSize, Addr sz
	Invoke CreateWindowEx, 0, TEXT("STATIC"), NULL, (WS_CHILD | WS_VISIBLE), [x], [y], [sz.cx], [sz.cy], [hWndOwner], 0, [App.Instance], NULL
	Mov [Esi + METER_DATA.hWndMeter], Eax
	Lea Ebx, [Esi + METER_DATA.hLedArray]
	Mov Edi, 1
	Inc D[lRSMeters]
	Invoke CreateSolidBrush, 00FFFF00H
	Mov [Esi + METER_DATA.hLedOnBrush], Eax
	Mov D[x], 0
	Mov D[y], 0
L8:	Invoke CreateWindowEx, [dwExStyle], TEXT("STATIC"), NULL, [dwStyle], [x], [y], [Esi + METER_DATA.lWidth], [Esi + METER_DATA.lHeight], [Esi + METER_DATA.hWndMeter], Edi, [App.Instance], NULL
	Or Eax, Eax
	Jz > L14
	Mov [Ebx], Eax

	Cmp D[Esi + METER_DATA.wndOldProc], NULL
	Jne >
	Invoke GetWindowLong, Eax, GWL_WNDPROC
	Mov [Esi + METER_DATA.wndOldProc], Eax
:	Invoke SetWindowLong, [Ebx], GWL_USERDATA, Esi
	Invoke SetWindowLong, [Ebx], GWL_WNDPROC, Addr wndLedsProc
	Cmp D[Esi + METER_DATA.bVertical], FALSE
	Je > L10
	Mov Eax, [Esi + METER_DATA.lHeight]
	Cmp D[Esi + METER_DATA.lShape], RSMETER_FLAT
	Jne >
	Inc Eax
:	Add [y], Eax
	Jmp > L12
L10:
	Mov Eax, [Esi + METER_DATA.lWidth]
	Cmp D[Esi + METER_DATA.lShape], RSMETER_FLAT
	Jne >
	Inc Eax
:	Add [x], Eax
L12:
	Add Ebx, 4
	Inc Edi
	Cmp Edi, (MAX_LEDS + 1)
	Jl << L8
	Mov Eax, [Esi + METER_DATA.lIndex]
	Ret
L14:
	Invoke DestroyMeter, [Esi + METER_DATA.lIndex]
	Mov Eax, (-1)
	Ret
EndF

DestroyMeter Frame lIndex Uses Edi, Esi
	Cmp D[lIndex], 0
	Jl > L6
	Lea Esi, [hRSMLabelArray]
	Mov Eax, [lIndex]
	Shl Eax, 2
	Add Esi, Eax
	Push Esi
	Mov Esi, [Esi]
	Or Esi, Esi
	Jz > L6
	Lea Esi, [Esi + METER_DATA.hLedArray]
	Mov Edi, MAX_LEDS
L2:	Or Edi, Edi
	Jz > L4
	Cmp D[Esi], 0
	Je >
	Invoke DestroyWindow, [Esi]
	Mov D[Esi], 0
	Add Esi, 4
:	Dec Edi
	Jmp < L2
L4:	Pop Esi
	Invoke GlobalFree, [Esi]
	Mov D[Esi], 0
	Dec D[lRSMeters]
	Jnz >
	Invoke DeleteObject, [hLedOffBrush]
	Mov D[hLedOffBrush], NULL
:	Mov Eax, TRUE
	Ret
L6:	Xor Eax, Eax
	Ret
EndF

GetFreeIndex: Uses Esi
	Lea Esi, hRSMLabelArray
	Xor Ecx, Ecx
L2:	Cmp Ecx, MAX_METERS
	Jge > L4
	Cmp D[Esi], 0
	Jne >
	Mov Eax, Ecx
	Ret
:	Add Esi, 4
	Inc Ecx
	Jmp < L2
L4:	Mov Eax, (-1)
	Ret
EndU

;On enter Esi = Pointer to data
GetParentSize Frame lpszSize Uses Edi
	Mov Edi, [lpszSize]
	Cmp D[Esi + METER_DATA.bVertical], 0
	Je > L2
	Mov Eax, [Esi + METER_DATA.lWidth]
	Mov [Edi + SIZEL.cx], Eax
	Mov Eax, [Esi + METER_DATA.lHeight]
	Cmp D[Esi + METER_DATA.lShape], RSMETER_FLAT
	Jne >
	Inc Eax
:	Mov Ecx, MAX_LEDS
	Mul Ecx
	Mov [Edi + SIZEL.cy], Eax
	Ret
L2:
	Mov Eax, [Esi + METER_DATA.lHeight]
	Mov [Edi + SIZEL.cy], Eax
	Mov Eax, [Esi + METER_DATA.lWidth]
	Cmp D[Esi + METER_DATA.lShape], RSMETER_FLAT
	Jne >
	Inc Eax
:	Mov Ecx, MAX_LEDS
	Mul Ecx
	Mov [Edi + SIZEL.cx], Eax
	Ret
EndF

;On enter Esi = Pointer to data
ResizeMeter: Uses Ebx, Edi
	Lea Edi, [Esi + METER_DATA.hLedArray]
	Invoke GetWindowRect, [Edi], Addr rc
	Invoke ScreenToClient, [Esi + METER_DATA.hWndMeter], Addr rc
	Mov Ebx, MAX_LEDS
L2:	Or Ebx, Ebx
	Jnz >
	Ret
:	Invoke MoveWindow, [Edi], [rc.left], [rc.top], [Esi + METER_DATA.lWidth], [Esi + METER_DATA.lHeight], TRUE
	Add Edi, 4
	Cmp D[Esi + METER_DATA.bVertical], 0
	Je > L4
	Mov Eax, [Esi + METER_DATA.lHeight]
	Cmp D[Esi + METER_DATA.lShape], RSMETER_FLAT
	Jne >
	Inc Eax
:	Add [rc.top], Eax
	Jmp > L6
L4:
	Mov Eax, [Esi + METER_DATA.lWidth]
	Cmp D[Esi + METER_DATA.lShape], RSMETER_FLAT
	Jne >
	Inc Eax
:	Add [rc.left], Eax
L6:	Dec Ebx
	Jmp < L2
EndU

SetMeterColor Frame lIndex, crColor Uses Esi
	Cmp D[lIndex], 0
	Jl > L4
	Lea Esi, [hRSMLabelArray]
	Mov Eax, [lIndex]
	Shl Eax, 2
	Add Esi, Eax
	Mov Esi, [Esi]
	Or Esi, Esi
	Jz > L2
	Invoke DeleteObject, [Esi + METER_DATA.hLedOnBrush]
	Mov Eax, [crColor]
	Test Eax, 80000000H
	Jz >
	And Eax, 00FFFFFFH
	Invoke GetSysColor, Eax
:	Invoke CreateSolidBrush, Eax
	Mov [Esi + METER_DATA.hLedOnBrush], Eax
L2:	Mov Eax, TRUE
	Ret
L4:	Xor Eax, Eax
	Ret
EndF

SetMeterHeight Frame lIndex, lHeight Uses Ebx, Edi, Esi
	Local sz:SIZEL

	Cmp D[lIndex], 0
	Jl > L2
	Lea Esi, [hRSMLabelArray]
	Mov Eax, [lIndex]
	Shl Eax, 2
	Add Esi, Eax
	Mov Esi, [Esi]
	Mov Eax, [lHeight]
	Cmp D[Esi + METER_DATA.lShape], RSMETER_FLAT
	Jne >
	Dec Eax
:	Cmp Eax, [Esi + METER_DATA.lHeight]
	Je > L2
	Mov [Esi + METER_DATA.lHeight], Eax
	Invoke GetParentSize, Addr sz
	Invoke SetWindowPos, [Esi+METER_DATA.hWndMeter], NULL, 0, 0, [sz.cx], [sz.cy], (SWP_NOZORDER | SWP_NOMOVE | SWP_FRAMECHANGED)
	Invoke ResizeMeter
	Return (TRUE)
L2:	Xor Eax, Eax
	Ret
EndF

SetMeterMaxValue Frame lIndex, lMaxValue Uses Esi
	Cmp D[lIndex], 0
	Jl >
	Lea Esi, [hRSMLabelArray]
	Mov Eax, [lIndex]
	Shl Eax, 2
	Add Esi, Eax
	Mov Esi, [Esi]
	Mov Eax, [lMaxValue]
	Mov [Esi + METER_DATA.lMaxValue], Eax
	Return (TRUE)
:	Xor Eax, Eax
	Ret
EndF

SetMeterValue Frame lIndex, lValue Uses Ebx, Edi, Esi
	Local lLedsOn:D

	Cmp D[lIndex], 0
	Jge >
	Xor Eax, Eax
	Ret
:	Lea Esi, [hRSMLabelArray]
	Mov Eax, [lIndex]
	Shl Eax, 2
	Add Esi, Eax
	Mov Esi, [Esi]
	Mov Eax, [lValue]
	Cmp Eax, 0
	Jge >
	Xor Eax, Eax
	Jmp > L2
:	Cmp Eax, [Esi + METER_DATA.lMaxValue]
	Jle > L2
	Mov Eax, [Esi + METER_DATA.lMaxValue]
L2:	Mov [Esi + METER_DATA.lValue], Eax
	Mov Eax, [Esi + METER_DATA.lMaxValue]
	Xor Edx, Edx
	Mov Ecx, MAX_LEDS
	Div Ecx
	Mov Ecx, Eax
	Mov Eax, [Esi + METER_DATA.lValue]
	Xor Edx, Edx
	Or Ecx, Ecx
	Jz >
	Div Ecx
	Shr Ecx, 1
	Mov Ebx, Ecx
	Shr Ecx, 1
	Add Ebx, Ecx
	Cmp Edx, Ebx
	Jl >
	Inc Eax
:	Mov [Esi + METER_DATA.lLedsOn], Eax
	Mov [lLedsOn], Eax
	Lea Ebx, [Esi + METER_DATA.hLedArray]
	Xor Edi, Edi
	Or Eax, Eax
	Jz > L4
:	Cmp Edi, [lLedsOn]
	Jg > L4
	Mov Eax, [Esi + METER_DATA.hLedOnBrush]
	Mov [Esi + METER_DATA.hBrush], Eax
	Invoke InvalidateRect, [Ebx], NULL, FALSE
	Invoke SendMessage, [Ebx], WM_PAINT, 0, 0
	Add Ebx, 4
	Inc Edi
	Jmp <
L4:	Cmp Edi, MAX_LEDS
	Jge >
	Mov Eax, [hLedOffBrush]
	Mov [Esi + METER_DATA.hBrush], Eax
	Invoke InvalidateRect, [Ebx], NULL, FALSE
	Invoke SendMessage, [Ebx], WM_PAINT, 0, 0
	Add Ebx, 4
	Inc Edi
	Jmp < L4
:	Mov Eax, TRUE
	Ret
EndF

SetMeterWidth Frame lIndex, lWidth Uses Ebx, Edi, Esi
	Local sz:SIZEL

	Cmp D[lIndex], 0
	Jl > L2
	Lea Esi, [hRSMLabelArray]
	Mov Eax, [lIndex]
	Shl Eax, 2
	Add Esi, Eax
	Mov Esi, [Esi]
	Mov Eax, [lWidth]
	Cmp D[Esi + METER_DATA.lShape], RSMETER_FLAT
	Jne >
	Dec Eax
:	Cmp Eax, [Esi + METER_DATA.lWidth]
	Je > L2
	Mov [Esi + METER_DATA.lWidth], Eax
	Invoke GetParentSize, Addr sz
	Invoke SetWindowPos, [Esi+METER_DATA.hWndMeter], NULL, 0, 0, [sz.cx], [sz.cy], (SWP_NOZORDER | SWP_NOMOVE | SWP_FRAMECHANGED)
	Invoke ResizeMeter
	Return (TRUE)
L2:	Xor Eax, Eax
	Ret
EndF

wndLedsProc Frame hWnd, uMsg, wParam, lParam Uses Ebx, Edi, Esi
	Local ps:PAINTSTRUCT

	Invoke GetWindowLong, [hWnd], GWL_USERDATA
	Mov Esi, Eax
	Cmp D[uMsg], WM_ERASEBKGND
	Jne >
	Return (TRUE)
:	Cmp D[uMsg], WM_PAINT
	Jne >
	Invoke BeginPaint, [hWnd], Addr ps
	Invoke GetClientRect, [hWnd], Addr ps.rcPaint
	Invoke FillRect, [ps.hdc], Addr ps.rcPaint, [Esi + METER_DATA.hBrush]
	Invoke EndPaint, [hWnd], Addr ps
	Xor Eax, Eax
	Ret
:	Invoke CallWindowProc, [Esi + METER_DATA.wndOldProc], [hWnd], [uMsg], [wParam], [lParam]
	Ret
EndF
