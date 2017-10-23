
CODE SECTION

lszTrimLeft FRAME pString
	uses edi,esi

	mov esi,[pString]
	mov edi,[pString]
	xor eax,eax

	L1:
		mov al,[esi]
		or al,al
		jz >L2
		cmp al,20h
		jne >
			inc esi
			jmp L1
		:
		cmp al,09h
		jne >
			inc esi
			jmp L1
		:
		mov al,[esi]
		or al,al
		jz >L2
		mov [edi],al
		inc edi,esi
		jmp <
	L2:
	mov [edi],al

	RET
ENDF
