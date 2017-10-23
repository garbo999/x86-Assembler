.code
lszCmp FRAME pString1,pString2
	uses esi,edi

	mov edi, [pString1]
	mov esi, [pString2]
	:
	mov cl, [edi]
	mov ch, [esi]
	add edi,1
	add esi,1
	sub cl, ch
	jnz >
	or ch, ch
	jnz <
	:
	movsx eax, cl
	ret

ENDF