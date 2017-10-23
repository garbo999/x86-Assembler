CODE SECTION

StripFilename FRAME pBuffer,pFilename
	uses edi,ecx
	invoke lstrcpyA,[pBuffer],[pFilename]
	; Scan back to the first \
	invoke lstrlenA,[pBuffer]
	mov edi,[pBuffer]
	add edi,eax
	std
	mov ecx,eax
	mov eax,"\"
	repne scasb
	cld
	inc edi
	mov B[edi],0
	mov eax,edi
	inc eax
	RET
ENDF