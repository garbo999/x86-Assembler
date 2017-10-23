#include Files.Inc

.data
count_table dd 256 DUP (0)

.code

FillTable:
	mov  ecx,0
L1:
	xor  eax,eax
	test ecx,1
	jz  >
	inc   eax
:
	test ecx,2
	jz   >
	inc   eax
:
	test ecx,4
	jz   >
	inc   eax
:
	test ecx,8
	jz   >
	inc   eax
:
	test ecx,16
	jz   >
	inc   eax
:
	test ecx,32
	jz   >
	inc   eax
:
	test ecx,64
	jz   >
	inc   eax
:
	test ecx,128
	jz   >
	inc   eax
:
	mov  [count_table+ecx*4],eax

	inc  ecx
	cmp  ecx,256
	jne  <L1

	RET

ALIGN 16

CountFileLinesMMX FRAME pszFile
   ; This routine just counts the lines in a file
   ; in reality it just counts character 0Ah
	uses ebx,edi,esi
	LOCAL hMapFile		:D
	LOCAL pFilebuffer	:D
	LOCAL cbHigh		:D
	LOCAL cbFile		:D
	LOCAL hFile			:D

	call FillTable

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

	mov eax,0a0a0a0ah
	movd mm7,eax
	pshufw mm7,mm7,0

	xor eax,eax ; initialize line count to zero.
	; pad pFileBuffer with 16 0's on the end, because 
	; pFielbuffer might not be divisible by 16.
	mov edi,[pFilebuffer]

	lea  esi,[esi+edi]

	align 16 ; for P3 and below.
	Z1:
	movq mm0,[edi]
	movq mm1,[edi+8]
	add edi,16

	pcmpeqb mm0,mm7
	pcmpeqb mm1,mm7
	pmovmskb ebx,mm0
	pmovmskb ecx,mm1
	;eax is running count.

	movzx  edx,bl
	movzx  ebx,cl

	add    eax,[count_table+edx*4]
	add    eax,[count_table+ebx*4]

	cmp edi,esi
	jb <Z1

	mov ebx,eax

	invoke UnmapViewOfFile,[pFilebuffer]

	E3:
	invoke CloseHandle,[hMapFile]

	E2:
	invoke CloseHandle,[hFile]

	E1:
	mov eax,ebx

	RET
ENDF
