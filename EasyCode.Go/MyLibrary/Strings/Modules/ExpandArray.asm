.code
ExpandArray FRAME pArray,MaxIndex
	uses edi,ebx,esi

	invoke GetProcessHeap
	mov ebx,eax
	invoke HeapSize,ebx, 0, [pArray]
	shr eax, 2

	cmp eax,[MaxIndex]
	jl >
		mov eax, [pArray]
		RET
	:

	mov eax, [MaxIndex]
	shl eax,2
	add eax,4
	invoke HeapReAlloc, ebx, 08h, [pArray], eax
	or eax,eax
	jnz >
	mov eax, [pArray]
	:
	RET
ENDF