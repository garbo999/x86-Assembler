#Define REG_OPTION_NON_VOLATILE 0
#Define KEY_ALL_ACCESS 000F003Fh
#Define HKEY_CLASSES_ROOT 80000000h
#Define REG_SZ 1

.data
	CmdFmt0	DB	"Shell\",0
	CmdFmt1	DB	"\Command",0

.code

RegisterFileExtension FRAME pFileExt,pCmd,pCmdLine
	uses ebx
	LOCAL hClassKey		:D
	LOCAL hCmdKey		:D
	LOCAL Disposition	:D
	LOCAL szExt[16]		:B
	LOCAL szCmd[260]	:B

	; Set to NULL for API calls
	xor ebx,ebx
	; Be sure the extension starts with .
	mov eax,[pFileExt]
	mov al,[eax]
	cmp al,2EH
	je >
		lea eax,szExt
		mov B[eax],2EH
		inc eax
		jmp >C1
	:
		lea eax,szExt
	C1:
	invoke lstrcpyA,eax,[pFileExt]

	invoke RegCreateKeyExA, HKEY_CLASSES_ROOT, offset szExt, ebx, ebx, \
			REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, ebx, \
			ADDR hClassKey, ADDR Disposition

	invoke lstrcpyA,ADDR szCmd,ADDR CmdFmt0
	invoke lstrcatA,ADDR szCmd,[pCmd]
	invoke lstrcatA,ADDR szCmd,ADDR CmdFmt1

	invoke RegCreateKeyExA, [hClassKey], ADDR szCmd, ebx, ebx, \
			REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, ebx, \
			ADDR hCmdKey,ADDR Disposition
	invoke lstrlenA,[pCmdLine]
	inc eax
	invoke RegSetValueExA,[hCmdKey], ebx, ebx, REG_SZ, [pCmdLine], eax
	invoke RegCloseKey,[hCmdKey]
	invoke RegCloseKey,[hClassKey]

	xor eax,eax
	RET
	
ENDF
