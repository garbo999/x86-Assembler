.code
DeleteString FRAME pArray,iString
	uses edi,ebx,esi

	invoke GetProcessHeap
	mov ebx,eax

	cmp D[iString], 0
	jg >
		mov eax,-1
		ret
	:

	mov esi, [iString]
	mov edi, [pArray]
	mov eax, [edi+esi*4]

	invoke HeapFree, ebx, 0, eax

	mov D[edi+esi*4],0

	xor eax,eax
	RET
ENDF
