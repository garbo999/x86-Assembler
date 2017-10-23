.code
lszCatW FRAME lpDest,lpAdd
	push edi

	invoke lszLenW,[lpDest]
	shl eax,1
	mov edi,[lpDest]
	mov ecx,[lpAdd]
	add edi,eax
	xor edx,edx
	xor eax,eax

	:
		mov ax, [ecx+edx]
		mov [edi+edx], ax
		add edx, 2
		test ax,ax
		jne <

	pop edi
	mov eax,[lpDest]

	ret

ENDF
