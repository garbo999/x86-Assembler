.code
lszCopyMMX FRAME lpDest,lpSource
	uses esi,edi

	mov esi,[lpSource]
	mov edi,[lpDest]

	mov ecx,esi
	and ecx,15
	rep movsb

	nop
	pxor mm0,mm0
	nop
	pxor mm1,mm1
	nop

	:
		movq mm0,[esi]
		movq mm2,[esi]
		pcmpeqb mm2,mm1
		pmovmskb ecx,mm2
		or ecx,ecx
		jnz >
		movq [edi],mm0
		add edi, 8
		add esi, 8
	jmp <
	:

	emms
	; Do the remainder
	bsf ecx,ecx
	rep movsb
	mov [edi],cl
	
	mov eax,edi
	sub eax,[lpDest]
   ret
ENDF
