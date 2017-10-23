.code
lszSubst FRAME pString,pSubst
	uses esi,edi,ebx
	LOCAL pTable[256]	:B
	LOCAL index			:Q
	LOCAL adder			:Q
	LOCAL MMXRegVal		:Q

	lea eax,MMXRegVal
	movq [eax],mm0

	mov D[index+4],07060504h
	mov D[index],03020100h

	mov D[adder+4],08080808h
	mov D[adder],08080808h

	lea eax,index
	movq mm0,[eax]

	lea ecx,adder
	lea eax,pTable
	mov edx,32
	:
	movq [eax],mm0
	paddb mm0,[ecx]
	add eax,8
	dec edx
	jnz <


	lea ebx,pTable

	mov edi,[pSubst]
	:
	mov ax,[edi]
	or ax,ax
	jz >
	add edi,2
	movzx ecx,al
	mov [ebx+ecx],ah
	jmp <
	:

	mov esi,[pString]
	; scan the string til 0 is found
	:
	mov al,[esi]
	or al,al
	jz >
	xlatb
	mov [esi],al
	inc esi
	jmp <
	:

	lea eax,MMXRegVal
	movq mm0,[eax]
	emms

	RET
ENDF
