.data
hProcessHeap	DD	?

.code

CreateArray FRAME MaxIndex
	uses ebx

	invoke GetProcessHeap
	mov ebx,eax
	mov [hProcessHeap],eax

	mov eax,[MaxIndex]
	shl eax,2
	add eax,4
	invoke HeapAlloc, ebx, 08h, eax
	mov D[eax],1
	ret
ENDF

AddString FRAME pArray,pString
	uses ebx,edi

	mov ebx, [hProcessHeap]

	invoke HeapSize, ebx, 0, [pArray]
	shr eax, 2

	mov ecx,[pArray]
	mov ecx,[ecx]
	cmp eax,ecx
	jg >
		mov eax,-1
		ret
	:

	invoke lszLen, [pString]
	push eax
	inc eax ; Null terminator
	invoke HeapAlloc, ebx, 08h, eax

	pop ecx
	invoke lszCopyn, eax, [pString], ecx

	mov edi, [pArray]
	mov ecx,[pArray]
	mov ecx,[ecx]
	push ecx

	mov [edi+ecx*4], eax

	mov eax,[pArray]
	inc D[eax]

	pop eax
	ret
ENDF

GetString FRAME pArray,iString
	uses edi,ebx

	mov ebx, [hProcessHeap]

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
	ret
ENDF

DestroyArray FRAME pArray
	uses ebx,edi,esi

	invoke HeapSize, [hProcessHeap], 0, [pArray]
	shr eax, 2

	mov ebx, eax
	mov edi, [pArray]
	xor esi, esi
	inc esi
	jmp >L2
	L1:
		mov eax, [edi+esi*4]
		or eax, eax
		jz >
			invoke HeapFree, [hProcessHeap], 0, eax
		:
		inc esi
	L2:
	cmp esi,ebx
	jb <L1

	invoke HeapFree, [hProcessHeap], 0, [pArray]

	RET
ENDF
