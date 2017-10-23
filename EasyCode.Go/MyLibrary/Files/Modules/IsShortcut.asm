CODE SECTION

IsShortcut FRAME pFilename
	uses edi
	; Returns TRUE if the filename provided is a shortcut
	; Check to make sure the file exists
	invoke GetFileAttributesA, [pFilename]
	inc eax
	jz >.EXIT
	; Check for the .LNK extension
	invoke lstrlenA,[pFilename]
	mov edi,[pFilename]
	add edi,eax
	sub edi,4
	invoke lstrcmpiA,edi,".LNK"
	jnz >.EXIT
	xor eax,eax
	inc eax
	ret
	.EXIT
	xor eax,eax
	RET
ENDF
