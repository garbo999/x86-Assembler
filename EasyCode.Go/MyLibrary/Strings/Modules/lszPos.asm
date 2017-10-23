.code
lszPos FRAME pString,SearchChar,StartChar
	uses edi

	mov edi,[pString]
	invoke lszLen,[pString]
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
	add edi,[StartChar]
	mov al,[SearchChar]
	repne scasb
	or ecx,ecx
	jnz >
		mov eax,-1
		ret
	:
	mov eax,edi
	sub eax,[pString]
	RET
ENDF
