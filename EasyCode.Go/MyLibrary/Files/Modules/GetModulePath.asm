
.code

GetModulePath FRAME hInst,pszModPath,cbBuffer
	uses edi,ebx
	mov ebx,[cbBuffer]
	invoke GetModuleFileNameA,[hInst],[pszModPath],ebx
	mov edi,[pszModPath]
	mov ecx,ebx
	dec ebx
	add edi,ebx
	mov al,"\"
	std
	repne scasb
	cld
	mov B[edi+2],0
	mov eax,[pszModPath]
	ret
ENDF