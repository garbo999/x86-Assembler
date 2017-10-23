#include Link.inc

DATA SECTION
	RLI_IID_IShellLink	GUID <0000214eeh, 00000h, 00000h, 0c0h, 000h, 000h, 000h, 000h, 000h, 000h, 046h>
	RLI_CLSID_ShellLink	GUID <000021401h, 00000h, 00000h, 0c0h, 000h, 000h, 000h, 000h, 000h, 000h, 046h>
	RLI_IID_IPersistFile	GUID <00000010bH, 00000H, 00000H, 0C0H, 000H, 000H, 000H, 000H, 000H, 000H, 046H>


CODE SECTION

ResolveLinkIndirect FRAME pLinkInfo
	uses edi,esi
	LOCAL psl	:D
	LOCAL ppf	:D
	LOCAL pwsz	:D
	LOCAL error	:D

	mov esi,[pLinkInfo]

	invoke GlobalAlloc,40h,540
	mov [pwsz],eax

	invoke CoCreateInstance, addr RLI_CLSID_ShellLink,NULL,CLSCTX_INPROC_SERVER,ADDR RLI_IID_IShellLink,addr psl
	mov [error],eax
	cmp eax,S_OK
	jne >>.OLEBAD

	lea eax,ppf
	push eax
	lea eax,RLI_IID_IPersistFile
	push eax
	push [psl]
	mov edi,[psl]
	mov edi,[edi]
	call [edi+IShellLink.IUnknown.QueryInterface]
	mov [error],eax
	cmp eax,S_OK
	jne >>.NOPERSIST

	invoke MultiByteToWideChar,CP_ACP,NULL,[esi+LINK_INFO.pFilename],-1,[pwsz],MAX_PATH

	push STGM_READ
	push [pwsz]
	push [ppf]
	mov edi,[ppf]
	mov edi,[edi]
	call [edi+IPersistFile.Load]
	mov [error],eax
	cmp eax,S_OK
	jne >>.ALLDONE

	mov eax,[esi+LINK_INFO.pLinkTarget]
	or eax,eax
	jz >
	push NULL
	push NULL
	push MAX_PATH
	push [esi+LINK_INFO.pLinkTarget]
	push [psl]
	mov edi,[psl]
	mov edi,[edi]
	call [edi+IShellLink.GetPath]
	mov [error],eax
	cmp eax,S_OK
	jne >>.ALLDONE
	:

	mov eax,[esi+LINK_INFO.pStartIn]
	or eax,eax
	jz >
	; Working Directory
	push MAX_PATH
	push [esi+LINK_INFO.pStartIn]
	push [psl]
	mov edi,[psl]
	mov edi,[edi]
	call [edi+IShellLink.GetWorkingDirectory]
	mov [error],eax
	cmp eax,S_OK
	jne >>.ALLDONE
	:
	
	mov eax,[esi+LINK_INFO.pDescBuffer]
	or eax,eax
	jz >
	; Description
	push [esi+LINK_INFO.cchDesc]
	push [esi+LINK_INFO.pDescBuffer]
	push [psl]
	mov edi,[psl]
	mov edi,[edi]
	call [edi+IShellLink.GetDescription]
	mov [error],eax
	cmp eax,S_OK
	jne >>.ALLDONE
	:
	
	mov eax,[esi+LINK_INFO.pIconLocation]
	or eax,eax
	jz >
	; Icon information
	mov eax,esi
	add eax,LINK_INFO.dwIconIndex
	push eax
	push MAX_PATH
	push [esi+LINK_INFO.pIconLocation]
	push [psl]
	mov edi,[psl]
	mov edi,[edi]
	call [edi+IShellLink.GetIconLocation]
	mov [error],eax
	cmp eax,S_OK
	jne >>.ALLDONE
	:

	mov eax,[esi+LINK_INFO.pArgBuffer]
	or eax,eax
	jz >
	; Arguments
	push [esi+LINK_INFO.cchArg]
	push [esi+LINK_INFO.pArgBuffer]
	push [psl]
	mov edi,[psl]
	mov edi,[edi]
	call [edi+IShellLink.GetArguments]
	mov [error],eax
	cmp eax,S_OK
	jne >>.ALLDONE
	:

	mov eax,esi
	add eax,LINK_INFO.dwHotkey
	push eax
	push [psl]
	mov edi,[psl]
	mov edi,[edi]
	call [edi+IShellLink.GetHotkey]
	mov [error],eax
	cmp eax,S_OK
	jne >>.ALLDONE

	mov eax,esi
	add eax,LINK_INFO.dwShowCmd
	push eax
	push [psl]
	mov edi,[psl]
	mov edi,[edi]
	call [edi+IShellLink.GetShowCmd]
	mov [error],eax
	cmp eax,S_OK
	jne >>.ALLDONE

	.ALLDONE
	push [ppf]
	mov edi,[ppf]
	mov edi,[edi]
	call [edi+IPersistFile.IUnknown.Release]

	.NOPERSIST
	push [psl]
	mov edi,[psl]
	mov edi,[edi]
	call [edi+IShellLink.IUnknown.Release]

	.OLEBAD
	invoke GlobalFree,[pwsz]

	mov eax,[error]
   ret
endf
