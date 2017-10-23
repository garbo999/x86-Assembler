.code

/*********************************************************
The characters that are valid for an 8.3-compliant file or 
folder name include any combination of letters (A-Z) and/or 
numbers (0-9), plus the following special characters: 
      $   Dollar sign
      %   Percent sign
      '   Apostrophe
      `   Opening single quotation mark
      -   Hyphen
      @   At sign
      {   Left brace
      }   Right brace
      ~   Tilde
      !   Exclamation point
      #   Number sign
      (   Opening parenthesis
      )   Closing parenthesis
      &   Ampersand
      _   Underscore
      ^   Caret
*********************************************************/

CheckFileName FRAME pFilename, fSkipSpace
	uses edi,esi,ebx,ecx
	LOCAL BadChar	:D

	mov D[BadChar],1
	invoke lstrlenA,[pFilename]
	mov edi,eax
	; Scan each byte to make sure it is all numeric or alpha
	xor ebx,ebx
	xor edx,edx
	mov esi,[pFilename]
	jmp >>S2
	S1:
		mov al,[esi+ebx]
		cmp al,20h
		jg >
			cmp D[fSkipSpace],1
			je >>S0
				mov D[BadChar],0
				mov edx,20h
		:
		cmp al, 7fh
		jl >
			mov D[BadChar],0
			mov edx,7fh
		:
		cmp al,22h
		jne >
			mov D[BadChar],0
			mov edx,22h
		:
		cmp al,2Ah
		jne >
			mov D[BadChar],0
			mov edx,2Ah
		:
		cmp al,2Ch
		jne >
			mov D[BadChar],0
			mov edx,2Ch
		:
		cmp al,2Fh
		jne >
			mov D[BadChar],0
			mov edx,2Fh
		:
		cmp al,3Ah
		jne >
			mov D[BadChar],0
			mov edx,3Ah
		:
		cmp al,3Bh
		jne >
			mov D[BadChar],0
			mov edx,3Bh
		:
		cmp al,3Ch
		jne >
			mov D[BadChar],0
			mov edx,3Ch
		:
		cmp al,3Dh
		jne >
			mov D[BadChar],0
			mov edx,3Dh
		:
		cmp al,3Eh
		jne >
			mov D[BadChar],0
			mov edx,3Eh
		:
		cmp al,3Fh
		jne >
			mov D[BadChar],0
			mov edx,3Fh
		:
		cmp al,5Bh
		jne >
			mov D[BadChar],0
			mov edx,5Bh
		:
		cmp al,5Ch
		jne >
			mov D[BadChar],0
			mov edx,5Ch
		:
		cmp al,5Dh
		jne >
			mov D[BadChar],0
			mov edx,5Dh
		:
		cmp al,7Ch
		jne >
			mov D[BadChar],0
			mov edx,7Ch
		:
		S0:
		inc ebx
	S2:
	cmp ebx,edi
	jl <<S1

	mov eax,[BadChar]
	RET
	E1:
	movzx edx,al
	xor eax,eax
	ret
ENDF


