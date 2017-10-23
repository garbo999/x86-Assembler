.code
FindEmptyIndex FRAME pArray,InitialIndex
	uses ebx,edi,esi

	invoke GetProcessHeap
	invoke HeapSize, eax, 0, [pArray]
	shr eax, 2

	mov ebx, eax
	mov edi, [pArray]
	mov esi, [InitialIndex]
	jmp >L2
	L1:
		mov eax, [edi+esi*4]
		or eax, eax
		jnz >L3
			mov eax, esi
			ret
		L3:
		inc esi
	L2:
	cmp esi, ebx
	jb <L1

	mov eax,-1

	RET
ENDF