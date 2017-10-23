.code

lszCopyW FRAME pDest,pSource
	uses esi,edi,ecx
	invoke lszLenW,[pSource]
	push eax		;save String length
	shr  eax,1		;eax = eax / 2
	inc eax
	mov ecx,eax
	mov esi,[pSource]
	mov edi,[pDest]
	
	:
		mov eax, [esi]
		add esi, 4
		mov [edi], eax
		add edi, 4
		dec ecx
	jnz <

	pop eax			;load String length
	shl eax,1		;multiply by 2
	add eax,[pDest]
	ret
ENDF
