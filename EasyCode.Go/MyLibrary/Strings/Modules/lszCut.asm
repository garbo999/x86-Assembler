.code
lszCut FRAME pString,iStart,nLen
	
	mov edi,[pString]
	add edi,[iStart]
	mov esi,edi
	add esi,[nLen]

	:
	mov al,[esi]
	mov [edi],al
	inc edi
	inc esi
	or al,al
	jnz <

	mov eax,[pString]
	RET
ENDF