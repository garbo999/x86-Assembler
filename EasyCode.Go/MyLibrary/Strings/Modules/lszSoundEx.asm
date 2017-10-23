DATA SECTION
SoundExTable:
	db 64 DUP (0) ; 00 - 3F
	db 0,"0","1","2","3","0","1","2","0","0","2","2","4","5","5","0" ; 40 - 4F
	db "1","2","6","2","3","0","1","0","2","0","2",0,0,0,0,0 ; 50 - 5F
	db 0,"0","1","2","3","0","1","2","0","0","2","2","4","5","5","0" ; 60 - 6F
	db "1","2","6","2","3","0","1","0","2","0","2",0,0,0,0,0 ; 70 - 7F
	db 128 DUP (0) ; 80 - FF

	sndxucase	db	256 DUP (?)
	sndxtemp	db	1024 DUP (?)

CODE SECTION

lszSoundEx FRAME pOrgString
	uses edi,ebx,esi
	LOCAL pString		:D

	mov edi,offset sndxtemp
	mov [pString],edi

	mov esi,[pOrgString]
	xor ecx,ecx
	.copy
	mov al,[esi+ecx]
	mov [edi+ecx],al
	inc ecx
	or al,al
	jnz <.copy

	invoke PreParse,edi
	mov ebx,offset SoundExTable

	inc edi
	mov esi,edi
	:
	mov al,[edi]
	or al,al
	jz >
	xlatb
	inc edi
	or al,al
	jz <
	mov [esi],al
	inc esi
	jmp <
	:
	mov B[esi],0

	; remove duplicates
	mov edi,[pString]
	mov esi,edi
	L1:
	mov al,[edi]
	or al,al
	jz >.EXIT
	mov cl,[edi+1]
	cmp al,cl
	jne >
		inc edi
		jmp <L1
	:
	mov [esi],al
	inc edi,esi
	jmp <L1
	.EXIT
	mov B[esi],0

	; Remove 0's
	mov edi,[pString]
	mov esi,edi
	:
	mov al,[edi]
	inc edi
	cmp al,"0"
	je <
	or al,al
	jz >
	mov [esi],al
	inc esi
	jmp <
	:
	mov D[esi],"0000"
	mov B[esi+4],0
	mov esi,[pString]
	mov B[esi+4],0

	mov eax,[pString]
	mov eax,[eax]

	RET
ENDF

PreParse FRAME pString
	uses edi,ebx,esi

	; This preparses the string by substituting some
	; letter combinations that have the same sounds
	; as well as converts the case
	mov ebx,offset sndxucase
	mov al,[ebx+10h]
	cmp al,10h
	je >.CASEMAPDONE
		; Build the case conversion table if necessary
		mov edi,offset sndxucase
		xor eax,eax
		:
			mov B[edi+eax],al
			inc eax
			cmp eax,0FFh
			jbe <
		add edi,32
		mov eax,65
		:
			mov B[edi+eax],al
			inc eax
			cmp eax,90
			jbe <
	.CASEMAPDONE
	; convert case
	mov edi,[pString]
	mov esi,[pString]
	xor ecx,ecx
	:
	mov al,[esi+ecx]
	xlatb
	mov [edi+ecx],al
	inc ecx
	or al,al
	jnz <

	; Special cases for P
	mov edi,[pString]
	mov esi,offset sndxtemp
	mov ax,[edi]
	cmp ax,"PS"
	jne >
		mov B[esi],"S"
		inc esi
		add edi,2
	:
	cmp ax,"PF"
	jne >
		mov B[esi],"F"
		inc esi
		add edi,2
	:
	cmp ax,"EL"
	jne >
		mov B[esi],"L"
		inc esi
		add edi,2
	:

	L1:
	mov ax,[edi]
	cmp al,0
	jne >
		mov B[esi],0
		mov esi,offset sndxtemp
		mov edi,[pString]
		xor ecx,ecx
		.copy
		mov al,[esi+ecx]
		mov [edi+ecx],al
		inc ecx
		or al,al
		jnz <.copy
		ret

	:
	cmp ax,"DG"
	jne >
		mov B[esi],"G"
		inc esi
		add edi,2
		jmp L1
	:
	cmp ax,"GH"
	jne >
		mov B[esi],"H"
		inc esi
		add edi,2
		jmp L1
	:
	cmp ax,"GN"
	jne >
		mov B[esi],"N"
		inc esi
		add edi,2
		jmp L1
	:
	cmp ax,"KN"
	jne >
		mov B[esi],"N"
		inc esi
		add edi,2
		jmp L1
	:
	cmp ax,"PH"
	jne >
		mov B[esi],"F"
		inc esi
		add edi,2
		jmp L1
	:
	cmp ax,"MB"
	jne >
		
		mov B[esi],"M"
		inc esi
		add edi,2
		jmp L1
	:
	cmp ax,"MP"
	jne >C1
		mov cl,[edi+2]
		cmp cl,"S"
		je >
		cmp cl,"Z"
		je >
		cmp cl,"T"
		je >
		jmp >C1
		:
		mov B[esi],"M"
		inc esi
		add edi,2
		jmp <<L1
	C1:
	cmp ax,"TC"
	jne >
		mov cl,[edi+2]
		cmp cl,"H"
		jne >
		mov W[esi],"CH"
		add esi,2
		add edi,3
		jmp <<L1
	:
	mov [esi],al
	inc esi
	inc edi
	jmp <<L1

	RET
ENDF
