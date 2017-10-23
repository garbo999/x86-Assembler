#Include Files.inc

.code

ReadFileLines FRAME pszFile, pCallback
	uses edi,esi,ebx
	LOCAL fSizeLo		:D
	LOCAL fSizeHi		:D
	LOCAL pBuffer		:D
	LOCAL hHeap			:D
	LOCAL LineCount		:D
	LOCAL StripSize		:D
	LOCAL hFile			:D
	LOCAL hFileMapping	:D
	LOCAL pFileMapping	:D

	invoke IsBadCodePtr,[pCallback]
	or eax,eax
	jz >
		invoke SetLastError, 5 ;ERROR_ACCESS_DENIED
		xor eax,eax
		dec eax
		ret
	:

	mov D[LineCount],0

	invoke GetProcessHeap
	mov [hHeap], eax

	xor ebx,ebx
	; Open and map the file
	invoke CreateFileA,[pszFile],GENERIC_READ,FILE_SHARE_READ,ebx,OPEN_EXISTING,ebx,ebx
	mov [hFile], eax
	cmp eax,INVALID_HANDLE_VALUE
	je >>.NOFILEHANDLE
	invoke CreateFileMappingA,[hFile],ebx,PAGE_READONLY,ebx,ebx,ebx
	mov [hFileMapping],eax
	or eax,eax
	jz >>.NOMAPPING
	invoke MapViewOfFile,[hFileMapping],FILE_MAP_READ,ebx,ebx,ebx
	mov [pFileMapping],eax
	or eax,eax
	jz >>.NOMAPVIEW
	invoke GetFileSize,[hFile],offset fSizeHi
	mov [fSizeLo],eax
	or eax,eax
	jz >>.ERROR

	mov esi,[pFileMapping]
	mov edi,[pFileMapping]
	mov ebx,[fSizeLo]
	mov ecx,ebx
	mov eax,0Ah

	L1:
	repne scasb
	push ecx,eax

	mov eax,edi
	sub eax,esi
	push eax
	add eax,0Fh
	and eax,0FFFFFFF0h
	invoke HeapAlloc,[hHeap],HEAP_ZERO_MEMORY,eax
	mov [pBuffer],eax
	pop ecx
	sub ecx,2
	jns >
	mov ecx,0
	:
	inc D[LineCount]
	invoke copymemory,eax,esi,ecx

	sub esi,[pFileMapping]
	invoke [pCallback],[pBuffer],ecx,[LineCount],esi
	or eax,eax
	jz >.EARLYEXIT

	invoke HeapFree,[hHeap],0,[pBuffer]
	mov esi,edi

	pop eax,ecx
	or ecx,ecx
	jnz <L1

	invoke UnmapViewOfFile,[pFileMapping]
	invoke CloseHandle,[hFileMapping]
	invoke CloseHandle,[hFile]
	xor eax,eax
	RET

	.EARLYEXIT
	invoke SetLastError,1223
	invoke HeapFree,[hHeap],0,[pBuffer]

	; ERROR returns
	.ERROR
	invoke UnmapViewOfFile,[pFileMapping]

	.NOMAPVIEW
	invoke CloseHandle,[hFileMapping]

	.NOMAPPING
	invoke CloseHandle,[hFile]

	.NOFILEHANDLE
	xor eax,eax
	dec eax
	RET

ENDF

copymemory FRAME lpDest,lpSource,nBytes
	uses edi,esi,ecx
	cld
	mov edi,[lpDest]
	mov esi,[lpSource]
	mov ecx,[nBytes]

	; do the evenly divisible ones
	shr ecx,2
	rep movsd

	; do the remainder
	mov ecx,[nBytes]
	and ecx,3
	rep movsb

	RET
ENDF
