#include Files.Inc

.code

CountFileLines FRAME pszFile
	uses ebx,edi,esi
	LOCAL hMapFile		:D
	LOCAL pFilebuffer	:D
	LOCAL cbHigh		:D
	LOCAL cbFile		:D
	LOCAL hFile			:D

	xor ebx,ebx
	dec ebx

	invoke CreateFileA,[pszFile],GENERIC_READ,0,0,OPEN_EXISTING,0,0
	mov [hFile],eax
	or eax,eax
	js >>E1

	invoke GetFileSize,[hFile],offset cbHigh
	mov esi,eax

	invoke CreateFileMappingA,[hFile],0,PAGE_READONLY,0,0,0
	mov [hMapFile],eax
	or eax,eax
	jz >E2

	invoke MapViewOfFile,[hMapFile],FILE_MAP_READ,0,0,0
	mov [pFilebuffer],eax
	or eax,eax
	jz >E3
	; This routine just counts the lines in a file
	; in reality it just counts character 0Ah

	xor ebx,ebx
	inc ebx ; there is always one line, this is a one based count
	mov edi,[pFilebuffer]
	lea esi,[esi+edi+3]

	L1:
	mov eax,[edi]
	add edi,4
	cmp edi,esi
	ja >L2

	xor eax,0a0a0a0ah
	mov edx,eax
	lea ecx,[edx-01010101h]
	not edx
	and ecx,edx
	and ecx,80808080h
	jz <L1

	test ecx,00000080h
	jz >
	inc ebx
	:
	test ecx,00008000h
	jz >
	inc ebx
	:
	test ecx,00800000h
	jz >
	inc ebx
	:
	test ecx,80000000h
	jz <L1
	inc ebx
	jmp <L1


	L2:

	invoke UnmapViewOfFile,[pFilebuffer]

	E3:
	invoke CloseHandle,[hMapFile]

	E2:
	invoke CloseHandle,[hFile]

	E1:
	mov eax,ebx
	RET
ENDF
