.code

FindBadDOSChar FRAME pFilename, nFirstChar, fSkipSpace
	uses edi,esi,ebx,ecx

	invoke lstrlenA,[pFilename]
	mov edi,eax
	; Scan each byte to make sure it is all numeric or alpha
	mov ebx,[nFirstChar]
	cmp ebx,eax
	jle >
	xor eax,eax
	dec eax
	ret
	:
	xor edx,edx
	mov esi,[pFilename]
	jmp >S2
	S1:
		mov al,[esi+ebx]
		cmp al,20h
		jg >
			cmp D[fSkipSpace],1
			jne >E1
		:
		cmp al,7fh
		jg >E1
		cmp al,22h
		je >E1
		cmp al,2Ah
		je >E1
		cmp al,2Ch
		je >E1
		cmp al,2Fh
		je >E1
		cmp al,3Ah
		je >E1
		cmp al,3Bh
		je >E1
		cmp al,3Ch
		je >E1
		cmp al,3Dh
		je >E1
		cmp al,3Eh
		je >E1
		cmp al,3Fh
		je >E1
		cmp al,5Bh
		je >E1
		cmp al,5Ch
		je >E1
		cmp al,5Dh
		je >E1
		cmp al,7Ch
		je >E1
		S0:
		inc ebx
	S2:
	cmp ebx,edi
	jl <S1

	xor eax,eax
	dec eax
	ret
	E1:
	mov eax,ebx
	ret
ENDF
