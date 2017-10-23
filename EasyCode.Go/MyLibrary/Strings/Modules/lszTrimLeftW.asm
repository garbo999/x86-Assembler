CODE SECTION

lszTrimLeftW FRAME pString
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
			inc esi
			jmp L1
		:
		cmp al,09h
		jne >
			inc esi
			inc esi
			jmp L1
		:
		mov ax,[esi]
		or ax,ax
		jz >L2
		mov [edi],ax
		inc edi,edi
		inc esi,esi
		jmp <
	L2:
	mov [edi],ax

	RET
ENDF