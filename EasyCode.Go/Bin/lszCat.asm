.code
lszCat FRAME lpDest,lpAdd
	push edi

	invoke lszLen,[lpDest]
	mov edi,[lpDest]
	mov ecx,[lpAdd]
	add edi,eax
	xor edx,edx
	xor eax,eax

	:
		mov al, [ecx+edx]
		mov [edi+edx], al
		add edx, 1
		test al,al
		jne <

	pop edi
	mov eax,[lpDest]

	ret

ENDF
