.code
lszCopyn FRAME lpDest,lpSource,nBytes
	uses edi,esi,ecx
	cld
	mov edi,[lpDest]
	mov esi,[lpSource]
	invoke lszLen,[lpSource]
	mov ecx,[nBytes]

	cmp ecx,eax
	jle >
		inc eax
		mov ecx,eax
	:

	; do the evenly divisible ones
	shr ecx,2
	rep movsd

	; do the remainder
	mov ecx,[nBytes]
	and ecx,3
	rep movsb

	mov B[edi],0

	mov eax,[lpDest]
   RET
ENDF