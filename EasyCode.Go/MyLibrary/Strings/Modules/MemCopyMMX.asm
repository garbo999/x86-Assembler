.code
MemCopyMMX FRAME pDest,pSource,cbLen
	uses edi,esi

	mov esi, [pSource]
	mov edi, [pDest]
	mov ecx, [cbLen]
	shr ecx, 6 // 64 bytes per iteration

L1:
	movq mm1, [ESI]
	movq mm2, [ESI+8]
	movq mm3, [ESI+16]
	movq mm4, [ESI+24]
	movq mm5, [ESI+32]
	movq mm6, [ESI+40]
	movq mm7, [ESI+48]
	movq mm0, [ESI+56]

	movntq [EDI],    mm1
	movntq [EDI+8],  mm2
	movntq [EDI+16], mm3
	movntq [EDI+24], mm4
	movntq [EDI+32], mm5
	movntq [EDI+40], mm6
	movntq [EDI+48], mm7
	movntq [EDI+56], mm0

	add esi, 64
	add edi, 64
	dec ecx
	jnz L1

	emms

	RET
ENDF
