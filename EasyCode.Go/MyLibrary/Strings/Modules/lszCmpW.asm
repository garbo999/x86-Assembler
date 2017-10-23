.code
lszCmpW FRAME pString1,pString2
	uses esi,edi

	mov edi, [pString1]
	mov esi, [pString2]
	:
	mov cl, [edi]
	mov ch, [esi]
	add edi,2
	add esi,2
	sub cl, ch
	jnz >
	or ch, ch
	jnz <
	:
	movsx eax, cl
	ret

ENDF