.code

FindNameInPath FRAME pszFileName
	uses edi

	mov edi,[pszFileName]
	invoke IsBadReadPtr,edi,1
	or eax,eax
	jnz >.ERROR
	mov ecx,260
	repne scasb
	dec edi
	xor eax,eax
	L1:
		mov al,[edi]
		cmp al,"\"
		je >L2
		cmp al,":"
		je >L2
		dec edi
		cmp edi,[pszFileName]
		jge <L1

	jmp >.ERROR

	L2:
		mov eax,edi
		add eax,1
		ret

	.ERROR
		mov eax,[pszFileName]
		ret
ENDF

