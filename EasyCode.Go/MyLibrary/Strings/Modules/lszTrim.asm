.code
lszTrim FRAME pString
	uses esi, edi

	; By Ketil Olsen

	mov esi,[pString]
	mov edi,[pString]
	xor edx,edx
	xor eax,eax
	mov ah,0Ah

	L0:
	lodsb
		cmp al,20h
		jne >
			inc edx
			jmp >L1
		:
		cmp al,09h
		jne >
			mov B[edi],20h
			inc edx
			jmp >L1
		:
		or edx,edx
		jz >
		or al,al
		jz >
		cmp al,0Dh
		je >
		cmp ah,0Ah
		je >
			mov B[edi],20h
			inc edi
		:
		stosb
		mov ah,al
		xor edx,edx
	L1:
	or al,al
	jne <L0

	ret
ENDF