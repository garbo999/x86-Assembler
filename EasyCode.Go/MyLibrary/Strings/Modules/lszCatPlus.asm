.code

lszCatPlus FRAME
	LOCAL buffer[1024]	:B

	; This function is a C calling convention function (caller balances stack)
	; All paramters are explicitly calculated, the following
	; equates automate the process
	; The following are required parameters :
	pOutString	= ebp+8
	pFmtString	= ebp+12
	pOptional	= ebp+16

	; Preserve the Windows registers
	; Preserve ECX as well so the function can easily be used
	; in counted loops
	push esi, edi, ebx, ecx

	; truncate the string
	mov eax, [pOutString]
	mov B[eax], 0

	; Set up the scasb parameters
	invoke lszLen, [pFmtString]
	mov ecx, eax
	mov edi, [pFmtString]
	mov esi, edi
	mov eax, 025h ;"%"

	L1:
	REPNE scasb
	or ecx, ecx
	jz >>L2
		push eax, ecx

		; We have found a %
		mov edx, edi
		sub edx, esi
		dec edx

		lea eax, [buffer+edx]
		mov B[eax], 0

		; Set EAX to the end of the output string
		invoke lszCopyn, offset buffer, esi, edx
		invoke lszLen,[pOutString]
		add eax, [pOutString]

		; Append the text
		invoke lszCopy, eax, offset buffer

		xor edx, edx
		mov dl, [edi]
		cmp dl, 025h ;"%"
		jne >>
			; %% so just append a %
			; Set EAX to the end of the output string
			invoke lszLen, [pOutString]
			add eax, [pOutString]
			mov B[eax], 025h ;"%"
			mov B[eax+1], 0
			pop ecx, eax
			inc edi
			mov esi, edi
			jmp <<L1
		:

		cmp dl,"s"
		jne >>N1
		mov dl, [edi+1]
		cmp dl, 030h ;"0"
		jl >>N1
		cmp dl, 039h ;"9"
		jg >>N1
			sub dl, 030h ;"0"
			; Calculate offset of next parameter
			movzx ebx, dl
			shl ebx,2

			; Set EAX to the end of the output string
			invoke lszLen, [pOutString]
			add eax, [pOutString]
			invoke lszCopy, eax, [pOptional+ebx] ; Next parameter

			pop ecx, eax
			inc edi
			inc edi
			mov esi, edi
			jmp <<L1
		N1:
		
		cmp dl,"i"
		jne >>N2
		mov dl, [edi+1]
		cmp dl, 030h ;"0"
		jl >>N2
		cmp dl, 039h ;"9"
		jg >>N2
			sub dl, 030h ;"0"
			; Calculate offset of next parameter
			movzx ebx, dl
			shl ebx,2

			; Convert the parameter to decimal
			mov eax,[pOptional+ebx]
			invoke dw2ac,eax,offset buffer

			; Set EAX to the end of the output string
			invoke lszLen, [pOutString]
			add eax, [pOutString]
			invoke lszCopy, eax, offset buffer ; Next parameter

			pop ecx, eax
			inc edi
			inc edi
			mov esi, edi
			jmp <<L1
		N2:

		cmp dl,"x"
		jne >>N3
		mov dl, [edi+1]
		cmp dl, 030h ;"0"
		jl >>N3
		cmp dl, 039h ;"9"
		jg >>N3
			sub dl, 030h ;"0"
			; Calculate offset of next parameter
			movzx ebx, dl
			shl ebx,2

			; Convert the parameter to hex
			mov eax,[pOptional+ebx]
			invoke dw2hx,eax,offset buffer

			; Set EAX to the end of the output string
			invoke lszLen, [pOutString]
			add eax, [pOutString]
			invoke lszCopy, eax, offset buffer ; Next parameter

			pop ecx, eax
			inc edi
			inc edi
			mov esi, edi
			jmp <<L1
		N3:

		cmp dl,"u"
		jne >>N4
		mov dl, [edi+1]
		cmp dl, 030h ;"0"
		jl >>N4
		cmp dl, 039h ;"9"
		jg >>N4
			sub dl, 030h ;"0"
			; Calculate offset of next parameter
			movzx ebx, dl
			shl ebx,2

			; Convert the parameter to hex
			mov eax,[pOptional+ebx]
			invoke udw2ac,eax,offset buffer

			; Set EAX to the end of the output string
			invoke lszLen, [pOutString]
			add eax, [pOutString]
			invoke lszCopy, eax, offset buffer ; Next parameter

			pop ecx, eax
			inc edi
			inc edi
			mov esi, edi
			jmp <<L1
		N4:

		pop ecx, eax
		mov esi, edi
	jmp <<L1
	L2:

	; Copy the end of the string if any
	; Set EAX to the end of the output string
	invoke lszLen, [pOutString]
	add eax, [pOutString]
	invoke lszCopy, eax, esi

	mov eax,[pOutString]
	; Restore the Windows registers + ECX
	pop ecx, ebx, edi, esi
	RET
ENDF

dw2ac FRAME dwValue,lpBuffer
	uses ebx,edi

	; MichaelW w/ PDixon

		mov eax,[dwValue]
		mov ecx,2814749768
		mov edi,[lpBuffer]

		or eax,eax
		jns >S1
		neg eax
		mov B[edi],"-"
		inc edi

S1:
	push eax
;	#####fast div by 100000
		mul ecx
		mov ecx,100000
		shr edx,16
		mov eax,edx
		mov ebx,edx
		mul ecx
	sub [esp],eax

		mov eax,ebx
		mov ecx,429497
		mov ebx,10

		or eax,eax
		jz >S5

;	#######part 1
		mul ecx
		jc >D1

		mul ebx
		jc >D2

		mul ebx
		jc >D3

		mul ebx
		jc >D4

		mul ebx
		jc >D5
S5:
	pop eax
		mul ecx
		jc >D6

		mul ebx
		jc >D7

		mul ebx
		jc >D8

		mul ebx
		jc >D9

		mul ebx
		jmp >D0

;	#####end part1

D1:
		add edx,30h
		mov [edi],dl

		mul ebx
		inc edi
D2:
		add edx,30h
		mov [edi],dl

		mul ebx
		inc edi
D3:
		add edx,30h
		mov [edi],dl

		mul ebx
		inc edi
D4:
		add edx,30h
		mov [edi],dl

		mul ebx
		inc edi
D5:
		add edx,30h
		mov [edi],dl

	pop eax

		mul ecx
		inc edi
D6:
		add edx,30h
		mov [edi],dl

		mul ebx
		inc edi
D7:
		add edx,30h
		mov [edi],dl

		mul ebx
		inc edi
D8:
		add edx,30h
		mov [edi],dl

		mul ebx
		inc edi
D9:
		add edx,30h
		mov [edi],dl

		mul ebx
		inc edi
D0:
		add edx,30h
		mov [edi],dx

	mov eax,[dwValue]
	RET
ENDF

dw2hx FRAME dwValue, lpBuffer
	uses edi

	; Biterider

	mov edx, [dwValue]
	mov ecx, edx
	shr edx, 4
	and edx, 0F0F0F0Fh
	and ecx, 0F0F0F0Fh

	mov eax, edx
	mov edi, ecx

	add edx, 80808080h - 0A0A0A0Ah
	add ecx, 80808080h - 0A0A0A0Ah 
	shr edx, 4          
	shr ecx, 4 
	not edx
	not ecx
	and edx, 07070707h
	and ecx, 07070707h
	add edx, eax
	add ecx, edi
	add edx, 30303030h
	add ecx, 30303030h

	mov edi, [lpBuffer]
	mov B[edi + 7], cl
	mov B[edi + 6], dl
	mov B[edi + 5], ch
	mov B[edi + 4], dh
	shr ecx, 16
	shr edx, 16
	mov B[edi + 3], cl
	mov B[edi + 2], dl
	mov B[edi + 1], ch
	mov B[edi + 0], dh
	mov B[edi + 8], 0

  ret
ENDF

udw2ac FRAME dwNumber, pszString

    push ebx
    push esi
    push edi

    mov     eax, [dwNumber]
    mov     esi, [pszString]
    mov     edi, [pszString]
    mov ecx,429496730

  R1:
    mov ebx,eax
    mul ecx
    mov eax,edx
    lea edx,[edx*4+edx]
    add edx,edx
    sub ebx,edx
    add bl,'0'
    mov [esi],bl
    inc esi
    test    eax, eax
    jnz     <R1
    jmp     >C1

  I1: 
    dec     esi
    mov     al, [edi]
    xchg    [esi], al
    mov     [edi], al
    inc     edi
  C1:
    cmp     edi, esi
    jb      <I1

    pop edi
    pop esi
    pop ebx


    ret

ENDF
