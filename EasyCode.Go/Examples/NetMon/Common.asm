;EasyCodeName=Common,1
.Const

RSMETER_100000				Equ				0
RSMETER_500000				Equ				1
RSMETER_1000000				Equ				2
RSMETER_5000000				Equ				3
RSMETER_10000000			Equ				4
RSMETER_20000000			Equ				5
RSMETER_50000000			Equ				6
RSMETER_100000000			Equ				7


.Data

sDecimal					DB				'.', 0
sThousand					DB				',', 0
szBuffer					DB				MAX_PATH * 2 Dup ?


szRegistryKey				DB				'Software\RSC Products\RSNetMon\Settings', 0
szAutoRefreshPorts			DB				'AutoRefreshPorts', 0
szBits						DB				'Bits', 0
szMeterDownColor			DB				'MeterDownColor', 0
szMeterDownMaxValueEnum		DB				'MeterDownMaxValueEnum', 0
szMeterUpColor				DB				'MeterUpColor', 0
szMeterUpMaxValueEnum		DB				'MeterUpMaxValueEnum', 0
szOnTop						DB				'OnTop', 0
szAffinity					DB				'Affinity', 0
szPriority					DB				'Priority', 0
szSmallLeft					DB				'SmallLeft', 0
szSmallSize					DB				'SmallSize', 0
szSmallTop					DB				'SmallTop', 0
szVisible					DB				'Visible', 0
szFormat					DB				'%lu', 0

bBits						DD				FALSE
crMeterDownColor			DD				00FFFF00H
lAutoRefreshPorts			DD				0
lMeterDownIndex				DD				(-1)
lMeterDownMaxValueEnum		DD				2
lMeterDownMaxValue			DD				1000000
crMeterUpColor				DD				0000FFFFH
lMeterUpIndex				DD				(-1)
lMeterUpMaxValueEnum		DD				0
lMeterUpMaxValue			DD				100000
lPlatForm					DD				0
hWndImage					DD				NULL
hWndImgDown					DD				NULL
hWndImgUp					DD				NULL
lpGetExtendedTcpTable		DD				NULL
lpGetExtendedUdpTable		DD				NULL
hIconBoth					DD				NULL
hIconDownOff				DD				NULL
hIconDownOn					DD				NULL
hIconNone					DD				NULL
hIconReceive				DD				NULL
hIconSend					DD				NULL
hIconUpOff					DD				NULL
hIconUpOn					DD				NULL

IconData					NOTIFYICONDATA	<0>


.Code

ChangeIconColor Frame hIcon, dwOldColor, dwNewColor Uses Ebx, Edi, Esi
	Local IInf:ICONINFO, bi:BITMAPINFO

	Invoke GetIconInfo, [hIcon], Addr IInf
	Or Eax, Eax
	Jnz >
	Ret
:	Invoke CreateCompatibleDC, NULL
	Mov Edi, Eax
	Invoke RtlZeroMemory, Addr bi, SizeOf bi
	Mov D[bi.bmiHeader.biSize], SizeOf BITMAPINFOHEADER
	Invoke GetDIBits, Edi, [IInf.hbmColor], 0, 0, NULL, Addr bi, DIB_RGB_COLORS
	Or Eax, Eax
	Jnz >
	Ret
:	Mov Edx, [bi.bmiHeader.biWidth]
	Mov Eax, [bi.bmiHeader.biHeight]
	Mul Edx
	Shl Eax, 3           ;(W * H * 4)x2 bytes
	Mov Esi, Eax
	Invoke GlobalAlloc, GPTR, Esi
	Mov Ebx, Eax
	Mov D[bi.bmiHeader.biBitCount], 24
	Mov D[bi.bmiHeader.biCompression], BI_RGB
	Invoke GetDIBits, Edi, [IInf.hbmColor], 0, [bi.bmiHeader.biHeight], Ebx, Addr bi, DIB_RGB_COLORS
	;-----------CHANGE COLORS-------------------------
	Xor Ecx, Ecx
L2:	Cmp Ecx, Esi
	Jge > L4
	Xor Edx, Edx
	Mov Dh, [Ebx + Ecx]
	Shl Edx, 8
	Mov Dh, [Ebx + Ecx + 1]
	Mov Dl, [Ebx + Ecx + 2]
	Cmp Edx, [dwOldColor]
	Jne >
	Mov Edx, [dwNewColor]
	Mov [Ebx + Ecx + 1], Dh
	Mov [Ebx + Ecx + 2], Dl
	Shr Edx, 8
	Mov [Ebx + Ecx], Dh
:	Add Ecx, 3
	Jmp < L2
	;--------------------------------------------------
L4:	Invoke SetDIBits, Edi, [IInf.hbmColor], 0, [bi.bmiHeader.biHeight], Ebx, Addr bi, DIB_RGB_COLORS

	Invoke CreateIconIndirect, Addr IInf
	Push Eax
	Invoke GlobalFree, Ebx
	Invoke DeleteDC, Edi
	Invoke DeleteObject, [IInf.hbmMask]
	Invoke DeleteObject, [IInf.hbmColor]
	Pop Eax
	Ret
EndF

CheckMeterMaxValue Frame lValue, lpMaxValue
	Mov Eax, [lpMaxValue]
	Cmp D[lValue], RSMETER_100000
	Jne >
	Mov D[Eax], 100000
	Ret
:	Cmp D[lValue], RSMETER_500000
	Jne >
	Mov D[Eax], 500000
	Ret
:	Cmp D[lValue], RSMETER_5000000
	Jne >
	Mov D[Eax], 5000000
	Ret
:	Cmp D[lValue], RSMETER_10000000
	Jne >
	Mov D[Eax], 10000000
	Ret
:	Cmp D[lValue], RSMETER_20000000
	Jne >
	Mov D[Eax], 20000000
	Ret
:	Cmp D[lValue], RSMETER_50000000
	Jne >
	Mov D[Eax], 50000000
	Ret
:	Cmp D[lValue], RSMETER_100000000
	Jne >
	Mov D[Eax], 100000000
	Ret
:	Mov D[Eax], 1000000
	Ret
EndF

GetNoEllipsisText Frame lpszText Uses Esi
	Mov Esi, [lpszText]
	Invoke lstrlen, Esi
	Add Esi, Eax
	Sub Esi, 3
	Invoke lstrcmp, Esi, TEXT("...")
	Or Eax, Eax
	Jnz >
	Mov W[Esi], 0
:	Ret
EndF

GetProcessInfo Frame hPID, lpszBuffer, lpProcEntry Uses Ebx, Edi, Esi
	Local hKernel:D, lpCreate:D
	Local lpFirst:D, lpNext:D

	Xor Edi, Edi
	Invoke LoadLibrary, TEXT("kernel32.dll")
	Or Eax, Eax
	Jz >> L8
	Mov Esi, [lpProcEntry]
	Mov [hKernel], Eax
	Invoke GetProcAddress, [hKernel], TEXT("CreateToolhelp32Snapshot")
	Or Eax, Eax
	Jz > L6
	Mov [lpCreate], Eax
	Invoke GetProcAddress, [hKernel], TEXT("Process32First")
	Or Eax, Eax
	Jz > L6
	Mov [lpFirst], Eax
	Invoke GetProcAddress, [hKernel], TEXT("Process32Next")
	Or Eax, Eax
	Jz > L6
	Mov [lpNext], Eax
	Push 0
	Push TH32CS_SNAPPROCESS
	Call [lpCreate]
	Or Eax, Eax
	Jz > L6
	Mov Ebx, Eax
	Mov D[Esi + PROCESSENTRY32.dwSize], SizeOf PROCESSENTRY32
	Push Esi
	Push Ebx
	Call [lpFirst]
	Or Eax, Eax
	Jz > L4
	Mov Eax, [hPID]
	Cmp Eax, [Esi + PROCESSENTRY32.th32ProcessID]
	Je > L2
:	Push Esi
	Push Ebx
	Call [lpNext]
	Or Eax, Eax
	Jz > L4
	Mov Eax, [hPID]
	Cmp Eax, [Esi + PROCESSENTRY32.th32ProcessID]
	Jne <
L2:	Lea Eax, [Esi + PROCESSENTRY32.szExeFile]
	Invoke lstrcpy, [lpszBuffer], Eax
	Mov Edi, TRUE
L4:	Invoke CloseHandle, Ebx

L6:	Invoke FreeLibrary, [hKernel]

L8:	Or Edi, Edi
	Jnz >
	Invoke LoadString, [App.Instance], IDS_NOT_AVAILABLE, [lpszBuffer], MAX_PATH
:	Mov Eax, Edi
	Ret
EndF

GetStateString Frame dwState, lpszBuffer
	Cmp D[dwState], MIB_TCP_STATE_LISTEN
	Jne >
	Invoke lstrcpy, [lpszBuffer], TEXT("LISTEN")
	Jmp >> L2
:	Cmp D[dwState], MIB_TCP_STATE_SYN_SENT
	Jne >
	Invoke lstrcpy, [lpszBuffer], TEXT("SYN_SENT")
	Jmp >> L2
:	Cmp D[dwState], MIB_TCP_STATE_SYN_RCVD
	Jne >
	Invoke lstrcpy, [lpszBuffer], TEXT("SYN_RCVD")
	Jmp >> L2
:	Cmp D[dwState], MIB_TCP_STATE_ESTAB
	Jne >
	Invoke lstrcpy, [lpszBuffer], TEXT("ESTABLISHED")
	Jmp >> L2
:	Cmp D[dwState], MIB_TCP_STATE_FIN_WAIT1
	Jne >
	Invoke lstrcpy, [lpszBuffer], TEXT("FIN_WAIT1")
	Jmp >> L2
:	Cmp D[dwState], MIB_TCP_STATE_FIN_WAIT2
	Jne >
	Invoke lstrcpy, [lpszBuffer], TEXT("FIN_WAIT2")
	Jmp >> L2
:	Cmp D[dwState], MIB_TCP_STATE_CLOSE_WAIT
	Jne >
	Invoke lstrcpy, [lpszBuffer], TEXT("CLOSE_WAIT")
	Jmp >> L2
:	Cmp D[dwState], MIB_TCP_STATE_CLOSING
	Jne >
	Invoke lstrcpy, [lpszBuffer], TEXT("CLOSING")
	Jmp > L2
:	Cmp D[dwState], MIB_TCP_STATE_LAST_ACK
	Jne >
	Invoke lstrcpy, [lpszBuffer], TEXT("LAST_ACK")
	Jmp > L2
:	Cmp D[dwState], MIB_TCP_STATE_TIME_WAIT
	Jne >
	Invoke lstrcpy, [lpszBuffer], TEXT("TIME_WAIT")
:	Cmp D[dwState], MIB_TCP_STATE_DELETE_TCB
	Jne >
	Invoke lstrcpy, [lpszBuffer], TEXT("DELETE_TCB")
	Jmp > L2
:	Cmp D[dwState], MIB_TCP_STATE_CLOSED
	Jne >
	Invoke lstrcpy, [lpszBuffer], TEXT("CLOSED")
	Jmp > L2
:	Invoke lstrcpy, [lpszBuffer], TEXT("UNKNOWN")

L2:	Invoke lstrlen, [lpszBuffer]
	Ret
EndF

IPToStr Frame dwValue, lpszBuffer Uses Edi, Esi
	Mov Esi, [lpszBuffer]
	Mov Eax, [dwValue]
	Mov Edi, Eax
	And Eax, 0000000FFH
	Invoke wsprintf, Esi, Addr szFormat, Eax
	Add Esp, 12
	Add Esi, Eax
	Mov B[Esi], '.'
	Inc Esi
	Mov Eax, Edi
	Shr Eax, 8
	And Eax, 0000000FFH
	Invoke wsprintf, Esi, Addr szFormat, Eax
	Add Esp, 12
	Add Esi, Eax
	Mov B[Esi], '.'
	Inc Esi
	Mov Eax, Edi
	Shr Eax, 16
	And Eax, 0000000FFH
	Invoke wsprintf, Esi, Addr szFormat, Eax
	Add Esp, 12
	Add Esi, Eax
	Mov B[Esi], '.'
	Inc Esi
	Mov Eax, Edi
	Shr Eax, 24
	Invoke wsprintf, Esi, Addr szFormat, Eax
	Add Esp, 12
	Add Eax, Esi
	Sub Eax, [lpszBuffer]
	Ret
EndF

PortToStr Frame dwPort, lpszBuffer Uses Esi
	Mov Esi, [lpszBuffer]
	Xor Eax, Eax
	Mov Ax, W[dwPort]
	Xchg Al, Ah
	Invoke wsprintf, Esi, Addr szFormat, Eax
	Add Esp, 12
	Ret
EndF

SetAffinityMask Frame hProcess, dwAffinityMask Uses Edi
	Invoke LoadLibrary, TEXT("Kernel32.dll")
	Or Eax, Eax
	Jz >
	Mov Edi, Eax
	Invoke GetProcAddress, Edi, TEXT("SetProcessAffinityMask")
	Or Eax, Eax
	Jz >
	Push [dwAffinityMask]
	Push [hProcess]
	Call Eax
	Invoke FreeLibrary, Edi
:	Ret
EndF

SetMeterDownNewColor Frame crOldColor
	Invoke ChangeIconColor, [hIconDownOn], [crOldColor], [crMeterDownColor]
	Or Eax, Eax
	Jz >
	Xchg [hIconDownOn], Eax
	Or Eax, Eax
	Jz >
	Invoke DestroyIcon, Eax
:	Cmp D[lMeterDownIndex], (-1)
	Je >
	Invoke SetMeterColor, [lMeterDownIndex], [crMeterDownColor]
:	Ret
EndF

SetMeterUpNewColor Frame crOldColor
	Invoke ChangeIconColor, [hIconUpOn], [crOldColor], [crMeterUpColor]
	Or Eax, Eax
	Jz >
	Xchg [hIconUpOn], Eax
	Or Eax, Eax
	Jz >
	Invoke DestroyIcon, Eax
:	Cmp D[lMeterUpIndex], (-1)
	Je >
	Invoke SetMeterColor, [lMeterUpIndex], [crMeterUpColor]
:	Ret
EndF

SetIcons Frame hIcon Uses Edi, Esi
	Mov Eax, [hIcon]
	Mov [IconData.hIcon], Eax
	Cmp Eax, [hIconBoth]
	Jne >
	Mov Edi, [hIconDownOn]
	Mov Esi, [hIconUpOn]
	Jmp > L2
:	Cmp Eax, [hIconReceive]
	Jne >
	Mov Edi, [hIconDownOn]
	Mov Esi, [hIconUpOff]
	Jmp > L2
:	Cmp Eax, [hIconSend]
	Jne >
	Mov Edi, [hIconDownOff]
	Mov Esi, [hIconUpOn]
	Jmp > L2
:	Mov Edi, [hIconDownOff]
	Mov Esi, [hIconUpOff]
L2:	Invoke Shell_NotifyIcon, NIM_MODIFY, Addr IconData
	Invoke SendMessage, [hWndImage], STM_SETICON, [IconData.hIcon], 0
	Invoke SendMessage, [hWndImgDown], STM_SETICON, Edi, 0
	Invoke SendMessage, [hWndImgUp], STM_SETICON, Esi, 0
	Ret
EndF

StrToIP Frame lpszString Uses Edi, Esi
	Mov Esi, [lpszString]
	Invoke Value, Esi
	Mov Edi, Eax
	Invoke FindChar, Esi, '.'
	Add Esi, Eax
	Inc Esi
	Invoke Value, Esi
	Shl Eax, 8
	Or Edi, Eax
	Invoke FindChar, Esi, '.'
	Add Esi, Eax
	Inc Esi
	Invoke Value, Esi
	Shl Eax, 16
	Or Edi, Eax
	Invoke FindChar, Esi, '.'
	Add Esi, Eax
	Inc Esi
	Invoke Value, Esi
	Shl Eax, 24
	Or Edi, Eax
	Mov Eax, Edi
	Ret
EndF
