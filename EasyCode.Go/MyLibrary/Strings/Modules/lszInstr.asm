.code
lszInstr FRAME pString,pFind,StartChar
	uses esi,edi,ebx
	LOCAL len	:D

	invoke lszLen,[pFind]
	push eax
	invoke lszLen,[pString]
	mov ebx,eax
	pop edx
	cmp edx,eax
	jle >
		mov eax,-1
		ret
	:
	
	mov eax,[StartChar]
	or eax,eax
	jns >
		mov eax,-1
		ret
	:

	sub ebx,edx
	inc edx
	mov [len],ebx
	mov ebx,[StartChar]
	:
	mov ecx,edx
	mov eax,[pString]
	lea edi,[eax+ebx]
	mov esi,[pFind]
	repe cmpsb
	or ecx,ecx
	jz >E1
	inc ebx
	cmp ebx,[len]
	jbe <

	xor eax,eax
	dec eax
	ret

	E1:
	mov eax,ebx
	RET
ENDF
