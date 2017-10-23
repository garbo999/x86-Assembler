.code

lszReverse FRAME pString
	uses edi,esi

	mov edi,[pString]
	mov esi,[pString]
	xor ecx,ecx
	:
	mov al,[edi]
	inc edi
	inc ecx
	or al,al
	jnz <
	dec ecx
	cmp ecx,1
	jae >.EXIT

	sub edi,2
	xor eax,eax
	:
	mov al,[edi]
	mov dl,[esi]
	mov [esi],al
	mov [edi],dl
	dec edi
	inc esi
	cmp edi,esi
	ja <

	.EXIT
	RET
ENDF

/*
lszReverse FRAME lpString
	invoke lszLen,[lpString]
	invoke ReverseIt,[lpString],eax
	RET
ENDF

ReverseIt FRAME lpString, cbLen
	uses esi,edi

	mov esi, [lpString]
	mov edi, esi
	mov ecx, [cbLen]
	add edi, ecx
	cmp ecx,3
	jle >
		sub edi, 4

		mov eax, [edi]
		mov edx, [esi]

		xchg ah, al
		xchg dh, dl

		rol eax, 16
		rol edx, 16

		xchg ah, al
		xchg dh, dl

		mov [edi], edx
		mov [esi], eax

		sub ecx, 8
		add esi, 4

		invoke ReverseIt, esi, ecx

	:
	cmp ecx,3
	jne >

		mov eax, [esi]
		xchg ah, al
		rol  eax, 16
		xchg ah, al
		ror  eax, 8
		mov [esi], eax

	:
	cmp ecx,2
	jne >
		mov eax, [esi]
		xchg ah, al
		mov [esi], eax
	:

   ret
ENDF
*/
