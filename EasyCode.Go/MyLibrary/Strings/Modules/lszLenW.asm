.code

lszLenW FRAME pszString
	uses edx,ecx
	mov edx,[pszString]
	xor eax,eax
	:
		mov ecx,[edx+eax*2]
		inc eax
		test ecx,0FFFFh
		jz >
		inc eax
		and ecx,0FFFF0000h
		jnz <
	:

	dec eax ; undo the increment of eax
	RET
ENDF
