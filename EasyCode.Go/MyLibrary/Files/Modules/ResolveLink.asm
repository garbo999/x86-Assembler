#include Link.inc

.DATA
	RL_IID_IShellLink	GUID <0000214eeh, 00000h, 00000h, 0c0h, 000h, 000h, 000h, 000h, 000h, 000h, 046h>
	RL_CLSID_ShellLink	GUID <000021401h, 00000h, 00000h, 0c0h, 000h, 000h, 000h, 000h, 000h, 000h, 046h>
	RL_IID_IPersistFile	GUID <00000010bH, 00000H, 00000H, 0C0H, 000H, 000H, 000H, 000H, 000H, 000H, 046H>

.CODE

ResolveLink FRAME lpbuffer,lpLinkPath
	uses edi
	LOCAL psl	:D
	LOCAL ppf	:D
	LOCAL pwsz	:D

	invoke GlobalAlloc,40h,540
	mov [pwsz],eax

	invoke CoCreateInstance, addr RL_CLSID_ShellLink,NULL,CLSCTX_INPROC_SERVER,ADDR RL_IID_IShellLink,addr psl
	cmp eax,S_OK
	je >
		push eax
		jmp >>O1
	:

	lea eax,ppf
	push eax
	lea eax,RL_IID_IPersistFile
	push eax
	push [psl]
	mov edi,[psl]
	mov edi,[edi]
	call [edi+IShellLink.IUnknown.QueryInterface]
	cmp eax,S_OK
	je >
		push eax
		jmp >P1
	:

	invoke MultiByteToWideChar,CP_ACP,NULL,[lpLinkPath],-1,[pwsz],MAX_PATH

	push STGM_READ
	push [pwsz]
	push [ppf]
	mov edi,[ppf]
	mov edi,[edi]
	call [edi+IPersistFile.Load]
	cmp eax,S_OK
	je >
		push eax
		jmp >A1
	:

	push NULL
	push NULL
	push MAX_PATH
	push [lpbuffer]
	push [psl]
	mov edi,[psl]
	mov edi,[edi]
	call [edi+IShellLink.GetPath]
	cmp eax,S_OK
	je >
		push eax
		jmp >A1
	:
	push S_OK

	A1: ;AllDone:
	push [ppf]
	mov edi,[ppf]
	mov edi,[edi]
	call [edi+IPersistFile.IUnknown.Release]

	P1: ;NoPersist:
	push [psl]
	mov edi,[psl]
	mov edi,[edi]
	call [edi+IShellLink.IUnknown.Release]

	O1: ;OleBad:
	invoke GlobalFree,[pwsz]
	pop eax

   ret
endf
