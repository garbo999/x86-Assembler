.code

lszLen FRAME pString
	uses ebx,edx,ecx,esi

		mov	eax,[pString]
		mov esi,eax
		test eax,3
		jz >N1
			add eax,3
			and eax,-4
ALIGN 4
		:
			mov dl,[esi]
			or dl,dl
			jz >E1
			inc esi
			cmp esi,eax
		jl <

		N1:
		lea		edx,[eax+3]

ALIGN 4
	:  
		mov		ebx,[eax]
		add		eax,4
		lea		ecx,[ebx-01010101h]
		not		ebx
		and		ecx,ebx
		and		ecx,80808080h    
		jz		<
		test	ecx,00008080h
		jnz		>
		shr		ecx,16
		add		eax,2
	:
		shl		cl,1
		sbb		eax,edx

	add eax,esi
	sub eax,[pString]
	ret

	E1:
	mov eax,esi
	sub eax,[pString]
	ret
ENDF
/*
lszLen FRAME pString
	uses ebx,edx,ecx

		mov		eax,[pString]
		lea		edx,[eax+3]
	:  
		mov		ebx,[eax]
		add		eax,4
		lea		ecx,[ebx-01010101h]
		not		ebx
		and		ecx,ebx
		and		ecx,80808080h    
		jz		<
		test	ecx,00008080h
		jnz		>
		shr		ecx,16
		add		eax,2
	:
		shl		cl,1
		sbb		eax,edx

    ret
ENDF
*/