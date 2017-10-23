#include Link.inc

DATA SECTION
	CLI_IID_IShellLink	GUID <0000214eeh, 00000h, 00000h, 0c0h, 000h, 000h, 000h, 000h, 000h, 000h, 046h>
	CLI_CLSID_ShellLink	GUID <000021401h, 00000h, 00000h, 0c0h, 000h, 000h, 000h, 000h, 000h, 000h, 046h>
	CLI_IID_IPersistFile	GUID <00000010bH, 00000H, 00000H, 0C0H, 000H, 000H, 000H, 000H, 000H, 000H, 046H>

CODE SECTION

CreateLinkIndirect FRAME pLinkInfo
	uses edi,esi
	LOCAL psl			:D
	LOCAL ppf			:D
	LOCAL pwsz			:D
	LOCAL error			:D

	mov esi,[pLinkInfo]

	invoke GlobalAlloc,40h,540
	mov [pwsz],eax

	invoke CoCreateInstance, addr CLI_CLSID_ShellLink,NULL,CLSCTX_INPROC_SERVER,ADDR CLI_IID_IShellLink,addr psl
	mov [error],eax
	cmp eax,S_OK
	jne >>O1

	lea eax,ppf
	push eax
	lea eax,CLI_IID_IPersistFile
	push eax
	push [psl]
	mov edi,[psl]
	mov edi,[edi]
	add edi,IShellLink.IUnknown.QueryInterface
	call [edi]
	mov [error],eax
	cmp eax,S_OK
	jne >>P1

	push [esi+LINK_INFO.pLinkTarget]
	push [psl]
	mov edi,[psl]
	mov edi,[edi]
	add edi,IShellLink.SetPath
	call [edi]
	mov [error],eax
	cmp eax,S_OK
	jne >>A1

	cmp D[esi+LINK_INFO.pDescBuffer],NULL
	je >
	push [esi+LINK_INFO.pDescBuffer]
	push [psl]
	mov edi,[psl]
	mov edi,[edi]
	add edi,IShellLink.SetDescription
	call [edi]
	mov [error],eax
	cmp eax,S_OK
	jne >>A1
	:
	
	cmp D[esi+LINK_INFO.pIconLocation],NULL
	je >
	push [esi+LINK_INFO.dwIconIndex]
	push [esi+LINK_INFO.pIconLocation]
	push [psl]
	mov edi,[psl]
	mov edi,[edi]
	add edi,IShellLink.SetIconLocation
	call [edi]
	mov [error],eax
	cmp eax,S_OK
	jne >>A1
	jmp >W1

	:
	push 0
	push [esi+LINK_INFO.pLinkTarget]
	push [psl]
	mov edi,[psl]
	mov edi,[edi]
	add edi,IShellLink.SetIconLocation
	call [edi]
	mov [error],eax
	cmp eax,S_OK
	jne >>A1
	W1:
	
	cmp D[esi+LINK_INFO.pStartIn],NULL
	je >
	push [esi+LINK_INFO.pStartIn]
	push [psl]
	mov edi,[psl]
	mov edi,[edi]
	add edi,IShellLink.SetWorkingDirectory
	call [edi]
	mov [error],eax
	cmp eax,S_OK
	jne >>A1
	:

	push [esi+LINK_INFO.dwHotkey]
	push [psl]
	mov edi,[psl]
	mov edi,[edi]
	add edi,IShellLink.SetHotkey 
	call [edi]
	mov [error],eax
	cmp eax,S_OK
	jne >>A1

	push [esi+LINK_INFO.dwShowCmd]
	push [psl]
	mov edi,[psl]
	mov edi,[edi]
	add edi,IShellLink.SetShowCmd 
	call [edi]
	mov [error],eax
	cmp eax,S_OK
	jne >>A1

	invoke MultiByteToWideChar,CP_ACP,NULL,[esi+LINK_INFO.pFilename],-1,[pwsz],MAX_PATH

	push TRUE
	push [pwsz]
	push [ppf]
	mov edi,[ppf]
	mov edi,[edi]
	add edi,IPersistFile.Save
	call [edi]
	mov [error],eax
	cmp eax,S_OK
	jne >>A1


	A1: ;AllDone
	push [ppf]
	mov edi,[ppf]
	mov edi,[edi]
	add edi,IPersistFile.IUnknown.Release
	call [edi]
	mov [error],eax

	P1: ;NoPersist
	push [psl]
	mov edi,[psl]
	mov edi,[edi]
	add edi,IShellLink.IUnknown.Release
	call [edi]

   O1: ;OleBad
   invoke GlobalFree,[pwsz]
   mov eax,[error]

   ret
endf
