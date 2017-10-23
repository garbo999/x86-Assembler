;EasyCodeName=SortArray,1
.code

Compare FRAME item1,item2,ascending,case
	uses ecx,esi,eax
	mov ecx,[item1]
	mov esi,[item2]
	
	mov edx,[ebx + ecx*4]
	or edx,edx
	jz >E1
	mov eax,[ebx + esi*4]
	or eax,eax
	jz >E1
	
	cmp D[ascending],0
	je >S1
		cmp D[case],0
		je >
		invoke lszCmp,eax,edx
		jmp >E0
		:
		invoke lszCmpi,eax,edx
		jmp >E0
	S1:
		cmp D[case],0
		je >
		invoke lszCmp,edx,eax
		jmp >E0
		:
		invoke lszCmpi,edx,eax
	E0:

	mov edx,eax
	RET
	E1:
	mov edx,0
	RET
ENDF

Exchange FRAME item1,item2
	uses ecx,esi
	mov ecx,[item1]
	mov esi,[item2]
	mov edx,[ebx + ecx*4]
	push [ebx + esi*4]
	mov [ebx + esi*4],edx
	pop [ebx + ecx*4]
   ret
ENDF

SortArray FRAME pArray,fAscend,fCase
	uses esi, edi, ebx

	mov ebx, [pArray]
	mov esi, 1
	mov edi,[pArray]
	mov edi, [edi]
	; Call Split
	Call SortArray.Split	;****also change here
	Ret

; Split:
.Split 						;****also change here
	mov eax,edi
	push esi
	push edi
	sub eax,esi
	jle >E1

	mov ecx,esi
	inc edi

	L1:
		inc esi
		dec eax
		js >D1
		invoke Compare,ecx,esi,[fAscend],[fCase]
		or edx,edx
		js L1

	H1:
		dec edi
		dec eax
		js >D1
		invoke Compare,ecx,edi,[fAscend],[fCase]
		or edx,edx
		jns H1
		invoke Exchange,esi,edi
		jmp L1

	D1:
		dec esi
		invoke Exchange,ecx,esi
		cmp edi,[esp]
		jge >12
		dec esi ; pivot is sorted
		mov eax,[esp]
		mov [esp],esi
		xchg edi,eax
		xchg esi,eax
		;call Split
		Call SortArray.Split	;****also change here
		pop edi
		pop esi
		;Jmp Split
		jmp <.Split				;****also change here x2

	12:
		pop edi
		pop esi
		dec edi
		;jmp Split
		Jmp <.Split				;****also change here x2 (this change was MINE)

	E1:
		add esp,8
		retn
ENDF
