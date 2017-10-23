.code

lszInsert FRAME pOutput,pString,pInsert,nPos
	
	mov esi, [pString]
	mov edi, [pOutput]
	mov edx, [pInsert]
	mov ecx, [nPos]
	
	or ecx,ecx
	jz >Z0

	:
	mov al, [esi]
	or al,al
	jz >.EXIT
	mov [edi],al
	inc esi
	inc edi
	dec ecx
	jnz <

	Z0:

	mov al, [edx]
	or al,al
	jz >
	mov [edi], al
	inc edi
	inc edx
	jmp <Z0

	:

	mov al, [esi]
	or al,al
	jz >
	mov [edi],al
	inc esi
	inc edi
	jmp <
	:
	
	.EXIT
	RET
ENDF