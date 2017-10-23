.code
lszCopynW FRAME lpDest,lpSource,nBytes
	uses edi,esi,ecx
	cld
	mov edi,[lpDest]
	mov esi,[lpSource]
	invoke lszLenW,[lpSource]
	mov ecx,[nBytes]

	cmp ecx,eax
	jle >
		inc eax
		mov ecx,eax
	:

	; do the evenly divisible ones
	shr ecx,1
	rep movsd

	; do the remainder
	mov ecx,[nBytes]
	and ecx,3
	shl ecx,1
	rep movsb

	mov B[edi],0
	mov B[edi+1],0

	mov eax,[lpDest]
   RET
ENDF