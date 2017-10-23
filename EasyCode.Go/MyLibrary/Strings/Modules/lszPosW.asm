.code
lszPosW FRAME pString,SearchChar,StartChar
	uses edi

	mov edi,[pString]
	invoke lszLenW,[pString]
	mov ecx,eax
	cmp ecx,[StartChar]
	jg >
		mov eax,-1
		ret
	:

	mov eax,[StartChar]
	or eax,eax
	jns >
		mov eax,-1
		ret
	:

	sub ecx,[StartChar]
	inc ecx
	shl ecx,1
	add edi,[StartChar]
	mov ax,[SearchChar]
	repne scasw
	or ecx,ecx
	jnz >
		mov eax,-1
		ret
	:
	mov eax,edi
	sub eax,[pString]
	shr eax,1
	RET
ENDF
