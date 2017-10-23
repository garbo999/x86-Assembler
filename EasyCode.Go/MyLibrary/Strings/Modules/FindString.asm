.code
FindString FRAME pArray,pString,fMatchCase
	uses ebx,edi,esi

	invoke GetProcessHeap
	invoke HeapSize, eax, 0, [pArray]
	shr eax, 2

	mov ebx, eax
	mov edi, [pArray]
	xor esi, esi
	inc esi
	jmp >L2
	L1:
		mov eax, [edi+esi*4]
		or eax, eax
		jz >L3
			cmp D[fMatchCase], 0
			je >
			invoke lszCmp, eax, [pString]
			or eax,eax
			jnz >L3
			mov eax,esi
			ret
			:
			invoke lszCmpi, eax, [pString]
			or eax,eax
			jnz >L3
			mov eax,esi
			ret
		L3:
		inc esi
	L2:
	cmp esi, ebx
	jb <L1

	mov eax,-1

	RET
ENDF