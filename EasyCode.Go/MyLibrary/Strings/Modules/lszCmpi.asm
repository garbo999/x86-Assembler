.code
lszCmpi FRAME pString1,pString2
	uses ebx,esi,edi

	lea ebx,lcase
	mov edi, [pString1]
	mov esi, [pString2]
	:
	mov al, [esi]
	xlatb
	mov ah,al
	mov al, [edi]
	xlatb
	add esi,1
	add edi,1
	sub al, ah
	jnz >
	or ah, ah
	jnz <
	:
	movsx eax, al
	ret

ENDF