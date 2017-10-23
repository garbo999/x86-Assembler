.code
EnumArray FRAME pArray,pCallBack
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
			push eax
			push esi
			push [pArray]
			call [pCallBack]
			or eax,eax
			jz >E1
		L3:
		inc esi
	L2:
	cmp esi, ebx
	jb <L1

	E1:
	xor eax,eax
	RET
ENDF