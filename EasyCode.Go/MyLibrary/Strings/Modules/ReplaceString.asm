.code
ReplaceString FRAME pArray,iString,pString
	uses ebx,edi

	invoke GetProcessHeap
	mov ebx, eax

	invoke HeapSize, ebx, 0, [pArray]
	shr eax, 2

	cmp eax,[iString]
	jg >
		mov eax,-1
		ret
	:
	
	cmp D[iString],0
	jg >
		mov eax,-1
		ret
	:

	mov ecx, [iString]
	mov edi, [pArray]
	mov eax, [edi+ecx*4]
	or eax, eax
	jz >
		invoke HeapFree, ebx, 0, eax
	:

	invoke lszLen, [pString]
	push eax
	inc eax ; Null terminator
	invoke HeapAlloc, ebx, 08h, eax

	pop ecx
	invoke lszCopyn,eax,[pString],ecx

	mov edi, [pArray]
	mov ecx, [iString]
	mov [edi+ecx*4], eax
	mov eax, [iString]
	ret
ENDF