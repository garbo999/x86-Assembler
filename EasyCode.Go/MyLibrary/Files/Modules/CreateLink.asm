#include Link.inc

.DATA
	CL_IID_IShellLink	GUID <0000214eeh, 00000h, 00000h, 0c0h, 000h, 000h, 000h, 000h, 000h, 000h, 046h>
	CL_CLSID_ShellLink	GUID <000021401h, 00000h, 00000h, 0c0h, 000h, 000h, 000h, 000h, 000h, 000h, 046h>
	CL_IID_IPersistFile	GUID <00000010bH, 00000H, 00000H, 0C0H, 000H, 000H, 000H, 000H, 000H, 000H, 046H>

.CODE

CreateLink FRAME lpLinkTarget,lpOutputFile,lpDescription
	uses edi
	LOCAL psl			:D
	LOCAL ppf			:D
	LOCAL pwsz			:D

	invoke GlobalAlloc,40h,540
	mov [pwsz],eax

	invoke CoCreateInstance, addr CL_CLSID_ShellLink,NULL,CLSCTX_INPROC_SERVER,ADDR CL_IID_IShellLink,addr psl
	cmp eax,S_OK
	je >
		push eax
		jmp >>O1
	:

	lea eax,ppf
	push eax
	lea eax,CL_IID_IPersistFile
	push eax
	push [psl]
	mov edi,[psl]
	mov edi,[edi]
	add edi,IShellLink.IUnknown.QueryInterface
	call [edi]
	cmp eax,S_OK
	je >
		push eax
		jmp >>P1
	:

	push [lpLinkTarget]
	push [psl]
	mov edi,[psl]
	mov edi,[edi]
	add edi,IShellLink.SetPath
	call [edi]
	cmp eax,S_OK
	je >
		push eax
		jmp >>A1
	:

	push 0
	push [lpLinkTarget]
	push [psl]
	mov edi,[psl]
	mov edi,[edi]
	add edi,IShellLink.SetIconLocation
	call [edi]
	cmp eax,S_OK
	je >
		push eax
		jmp >A1
	:
	
	cmp D[lpDescription],NULL
	je >
	push [lpDescription]
	push [psl]
	mov edi,[psl]
	mov edi,[edi]
	add edi,IShellLink.SetDescription
	call [edi]
	cmp eax,S_OK
	je >
		push eax
		jmp >>A1
	:

	invoke MultiByteToWideChar,CP_ACP,NULL,[lpOutputFile],-1,[pwsz],MAX_PATH

	push TRUE
	push [pwsz]
	push [ppf]
	mov edi,[ppf]
	mov edi,[edi]
	add edi,IPersistFile.Save
	call [edi]
	cmp eax,S_OK
	je >
		push eax
		jmp >A1
	:
	push S_OK

	A1: ;AllDone
	push [ppf]
	mov edi,[ppf]
	mov edi,[edi]
	add edi,IPersistFile.IUnknown.Release
	call [edi]
	
	P1: ;NoPersist
	push [psl]
	mov edi,[psl]
	mov edi,[edi]
	add edi,IShellLink.IUnknown.Release
	call [edi]

   O1: ;OleBad
   invoke GlobalFree,[pwsz]
   pop eax

   ret
endf

