.code

lszCaseW FRAME pString,fCase
	uses ebx,esi,edi

	mov ebx,offset lcase
	cmp D[fCase],1
	jne >
	mov ebx,offset ucase
	:

	mov edi,[pString]
	mov esi,[pString]
	xor ecx,ecx

	mov ax,[edi]
	cmp ax,0FFFEh
	jne >
	add ecx,2
	:
	mov al,[esi+ecx]
	xlatb
	mov [edi+ecx],al
	inc ecx
	inc ecx
	or al,al
	jnz <
	:

	mov eax,edi
	RET
ENDF