.code

lszCopy FRAME pDest,pSource
	uses edi,esi

	mov edi,[pDest]
	mov esi,[pSource]

	test esi,7
	jz >L1
	:
		mov al,[esi]
		mov [edi],al
		or al,al
		jz >D1
		inc esi
		inc edi
		test esi,7
	jne <

	ALIGN 16
	L1:
		mov eax,[esi]
		; Test for 0 byte
		mov edx,eax
		lea ecx,[edx-01010101h]
		not edx
		and ecx,edx
		and ecx,80808080h
		jnz >
		; No 0 byte so copy the dword
		mov [edi],eax
		add esi,4
		add edi,4
		jmp <L1
	:
	; Remainder
	bsf ecx,ecx
	shr ecx,3
	inc ecx
	rep movsb

	lea eax,[edi-1]
	sub eax,[pDest]
	D1:

	RET
ENDF
