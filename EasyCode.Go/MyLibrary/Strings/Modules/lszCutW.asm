CODE SECTION

lszCutW FRAME pString,iStart,nLen
	
	mov edi,[pString]
	mov eax,[iStart]
	shl eax,1
	add edi,eax
	mov esi,edi
	mov eax,[nLen]
	shl eax,1
	add esi,eax

	:
	mov ax,[esi]
	mov [edi],ax
	inc edi
	inc esi
	or ax,ax
	jnz <

	mov eax,[pString]
	RET
ENDF
