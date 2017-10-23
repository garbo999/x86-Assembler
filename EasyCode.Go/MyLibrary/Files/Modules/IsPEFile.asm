#Include Files.inc

CODE SECTION

IsPEFile FRAME pFilename
	uses edi
	LOCAL hPEFile		:D
	LOCAL hPEMapFile	:D
	LOCAL pPEMapFile	:D
	LOCAL fSize			:D
	LOCAL cbHigh		:D

	; Checks the file for indications that it is a valid Win32 PE file
	; Returns 0 if the file is a valid Win32 executable
	; -1 if there is an error, use GetLastError to obtain more information

	invoke SetLastError,0
	invoke CreateFileA,[pFilename],GENERIC_READ,FILE_SHARE_READ,NULL,OPEN_EXISTING,NULL,NULL
	or eax,eax
	jns >
		ret
	:
	mov [hPEFile],eax
	
	invoke GetFileSize,eax,offset cbHigh
	mov [fSize],eax

	invoke CreateFileMappingA,[hPEFile],0,PAGE_READONLY,0,0,0
	mov [hPEMapFile],eax
	or eax,eax
	jnz >
		invoke CloseHandle,[hPEFile]
		xor eax,eax
		dec eax
		ret
	:

	invoke MapViewOfFile,[hPEMapFile],FILE_MAP_READ,0,0,0
	mov [pPEMapFile],eax
	or eax,eax
	jnz >
		invoke CloseHandle,[hPEMapFile]
		invoke CloseHandle,[hPEFile]
		xor eax,eax
		dec eax
		ret
	:

	mov edi,eax

	cmp W[edi+IMAGE_DOS_HEADER.e_magic],"MZ"
	jne >.INVALID_PE

	mov edi,[edi+IMAGE_DOS_HEADER.e_lfanew]
	add edi,[pPEMapFile]
	jc >.INVALID_PE

	; Get the size of the mapped file
	mov eax,[pPEMapFile]
	add eax,[fSize]
	cmp edi, eax
	ja >.INVALID_PE

	cmp D[edi+IMAGE_NT_HEADERS.Signature],"PE"
	jne >.INVALID_PE

	invoke UnmapViewOfFile,[pPEMapFile]
	invoke CloseHandle,[hPEMapFile]
	invoke CloseHandle,[hPEFile]
	xor eax,eax
	RET
	
	.INVALID_PE
	invoke UnmapViewOfFile,[pPEMapFile]
	invoke CloseHandle,[hPEMapFile]
	invoke CloseHandle,[hPEFile]
	invoke SetLastError,193 ; %1 is not a valid Win32 application. ERROR_BAD_EXE_FORMAT
	xor eax,eax
	dec eax
	ret
ENDF
