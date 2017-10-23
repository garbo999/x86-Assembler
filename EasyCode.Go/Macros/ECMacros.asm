Return(%1) MACRO
	Mov Eax, %1
	Ret
ENDM

HiByte(%1) MACRO
	Mov Ax, %1
	Shr Ax, 8
ENDM

LoByte(%1) MACRO
	Mov Ax, %1
	Snd Ax, 00FFh
ENDM

HiWord(%1) MACRO
	Mov Eax, %1
	Shr Eax, 16
ENDM

LoWord(%1) MACRO
	Mov Eax, %1
	And Eax, 0000FFFFH
ENDM

MakeWord(%1,%2) MACRO
	Pushw Cx
	Mov Cl, %1
	Mov Ah, %2
	Mov Al, Cl
	Popw Cx
ENDM

MakeLong(%1,%2) MACRO
	Pushw %2
	Pushw %1
	Pop Eax
ENDM

Color(%1,%2,%3) MACRO
	Xor Eax, Eax
	Mov Ah, %3
	Mov Al, %2
	Shl Eax, 8
	Mov Al, %1
ENDM

Move(%1,%2) MACRO
	Push %2
	Pop %1
ENDM

Date(%1) MACRO
	Push Esi
	Push Edi
	Invoke GlobalAlloc, GPTR, MAX_PATH
	Mov Esi, Eax
	Invoke GetSystemTime, Esi
	Mov Edi, Esi
	Add Edi, 64
	Invoke GetDateFormat, LOCALE_USER_DEFAULT, LOCALE_NOUSEROVERRIDE, Esi, NULL, Edi, MAX_PATH - 65
	Invoke lstrcpy, %1, Edi
	Invoke GlobalFree, Esi
	Pop Edi
	Pop Esi
ENDM

Now(%1) MACRO
	Push Esi
	Push Edi
	Invoke GlobalAlloc, GPTR, MAX_PATH
	Mov Esi, Eax
	Invoke GetSystemTime, Esi
	Mov Edi, Esi
	Add Edi, 64
	Invoke GetDateFormat, LOCALE_USER_DEFAULT, LOCALE_NOUSEROVERRIDE, Esi, NULL, Edi, MAX_PATH - 65
	Invoke lstrcpy, %1, Edi
	Invoke lstrcat, %1, " - "
	Invoke GetTimeFormat, LOCALE_USER_DEFAULT, LOCALE_NOUSEROVERRIDE, Esi, NULL, Edi, MAX_PATH - 65
	Invoke lstrcat, %1, Edi
	Invoke GlobalFree, Esi
	Pop Edi
	Pop Esi
ENDM

Time(%1) MACRO
	Push Esi
	Push Edi
	Invoke GlobalAlloc, GPTR, MAX_PATH
	Mov Esi, Eax
	Invoke GetSystemTime, Esi
	Mov Edi, Esi
	Add Edi, 64
	Invoke GetTimeFormat, LOCALE_USER_DEFAULT, LOCALE_NOUSEROVERRIDE, Esi, NULL, Edi, MAX_PATH - 65
	Invoke lstrcpy, %1, Edi
	Invoke GlobalFree, Esi
	Pop Edi
	Pop Esi
ENDM

Swap(%1,%2) MACRO
	Push %1
	Push %2
	Pop %1
	Pop %2
ENDM
