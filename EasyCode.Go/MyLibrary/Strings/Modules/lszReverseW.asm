.code

lszReverseW FRAME pString
	uses edi,esi

	mov edi,[pString]
	mov esi,[pString]
	xor ecx,ecx
	:
	mov ax,[edi]
	inc edi
	inc ecx
	or ax,ax
	jnz <
	dec ecx
	cmp ecx,1
	jae >.EXIT

	sub edi,2
	xor eax,eax
	:
	mov ax,[edi]
	mov dx,[esi]
	mov [esi],ax
	mov [edi],dx
	sub edi,2
	add esi,2
	cmp edi,esi
	ja <

	.EXIT
	RET
ENDF

/*
lszReverseW FRAME lpString

	invoke lszLenW,[lpString]
	shl eax,1
	invoke ReverseItW,[lpString],eax
	RET
ENDF

ReverseItW FRAME lpString, cbLen
	uses esi,edi

	mov esi, [lpString]
	mov edi, esi
	mov ecx, [cbLen]
	add edi, ecx
	cmp ecx,4
	jle >
		sub edi, 4

		mov eax, [edi]
		mov edx, [esi]

		bswap eax
		bswap edx
		ror eax,8
		ror edx,8

		mov [edi], edx
		mov [esi], eax

		sub ecx, 8
		add esi, 4

		invoke ReverseItW, esi, ecx

	:
	cmp ecx,4
	jne >
		mov eax, [esi]
		bswap eax
		ror eax,8
		mov [esi], eax
	:

   ret
ENDF
*/
