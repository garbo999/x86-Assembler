CODE SECTION

lszInsertW FRAME pOutput,pString,pInsert,nPos

	mov esi, [pString]
	mov edi, [pOutput]
	mov edx, [pInsert]
	mov ecx, [nPos]
	
	or ecx,ecx
	jz >Z0

	:
	mov ax, [esi]
	or ax,ax
	jz >.EXIT
	mov [edi],ax
	add esi,2
	add edi,2
	dec ecx
	jnz <

	Z0:

	mov ax, [edx]
	or ax,ax
	jz >
	mov [edi], ax
	add edi,2
	add edx,2
	jmp <Z0

	:

	mov ax, [esi]
	or ax,ax
	jz >
	mov [edi],ax
	add esi,2
	add edi,2
	jmp <
	:
	
	.EXIT
	RET
ENDF