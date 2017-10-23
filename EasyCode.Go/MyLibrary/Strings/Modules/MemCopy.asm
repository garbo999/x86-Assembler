.code

dwMemCopy FRAME lpDest,lpSource,nBytes
	uses edi,esi,ecx
	cld
	mov edi,[lpDest]
	mov esi,[lpSource]
	mov ecx,[nBytes]

	; do the evenly divisible ones
	shr ecx,2
	rep movsd

	; do the remainder
	mov ecx,[nBytes]
	and ecx,3
	rep movsb

	D1:

	RET
ENDF