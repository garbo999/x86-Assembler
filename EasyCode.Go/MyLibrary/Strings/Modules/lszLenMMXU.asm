.code
lszLenMMXW FRAME pString

	mov eax,[pString]
	nop
	nop ; fill in stack frame+mov to 8 bytes

	pxor mm0,mm0
	nop ; fill pxor to 4 bytes
	pxor mm1,mm1
	nop ; fill pxor to 4 bytes

	: ; this is aligned to 16 bytes
	movq mm0,[eax]
	pcmpeqw mm0,mm1
	add eax,8
	pmovmskb ecx,mm0
	or ecx,ecx
	jz <

	sub eax,[pString]

	bsf ecx,ecx
	sub eax,8
	add eax,ecx
	shr eax,1
	emms

   RET

ENDF
