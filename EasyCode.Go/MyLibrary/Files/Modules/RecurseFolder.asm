#include Files.Inc
.data
	rfpszBuffer			db				MAX_PATH DUP (?)
	rfpwfd				WIN32_FIND_DATA	<?>
	rfpszSearchString	db				MAX_PATH DUP (?)
	rfpfEndProc			dd				1
	rfpnFileEnum		dd				0
	rfpBkSColon			db				"\*",0

.code

RecurseFolder FRAME lpPth,pCallback,fRecurse

	invoke IsBadCodePtr,[pCallback]
	or eax,eax
	jz >
		invoke SetLastError, 5 ;ERROR_ACCESS_DENIED
		xor eax,eax
		dec eax
		ret
	:

	mov D[rfpfEndProc],1
	mov D[rfpnFileEnum],0
	invoke xRecurseFolder,[lpPth],[pCallback],[fRecurse]

	mov eax,[rfpnFileEnum]
	RET
ENDF

xRecurseFolder FRAME lpPth,pCallback,fRecurse
	LOCAL hwfd	:D

	cmp D[rfpfEndProc],0
	je >>E2
	invoke lstrcpyA,addr rfpszBuffer,[lpPth]
	invoke lstrcatA,addr rfpszBuffer,offset rfpBkSColon
	invoke FindFirstFileA,addr rfpszBuffer,addr rfpwfd
	cmp eax,INVALID_HANDLE_VALUE
	je >>E2
		;Save returned handle
		mov [hwfd],eax
	  N1:
		;Check if found is a dir
		mov eax,[rfpwfd.dwFileAttributes]
		test eax,FILE_ATTRIBUTE_DIRECTORY
		jz >>C1
			cmp D[fRecurse],FALSE
			je >>C2
			;Do not include '.' and '..'
			mov eax,[rfpwfd.cFileName]
			and eax,0FFFFFFh
			cmp eax,2E2Eh
			je >>C2
			and eax,0FFFFh
			cmp eax,2Eh
			je >>C2
				invoke lstrlenA,addr rfpszBuffer
				mov edx,eax
				push edx
				dec edx
				cmp B[rfpszBuffer+edx],"\"
				jne >
					inc edx
				:
				mov eax,OFFSET rfpszBuffer
				add eax,edx
				invoke lstrcpyA,eax,addr rfpwfd.cFileName
				
				inc D[rfpnFileEnum]
				push [rfpwfd.dwFileAttributes]
				push OFFSET rfpszBuffer
				call [pCallback]
				mov [rfpfEndProc],eax
				or eax,eax
				jz >
				invoke xRecurseFolder,addr rfpszBuffer,[pCallback],[fRecurse]
				:
				pop edx
				mov B[rfpszBuffer+edx],0
				cmp D[rfpfEndProc],0
				je >>E1
				jmp >C2
		C1:
			invoke lstrcpyA,OFFSET rfpszSearchString,OFFSET rfpszBuffer
			invoke lstrlenA,OFFSET rfpszSearchString
			add eax,OFFSET rfpszSearchString
			dec eax
			invoke lstrcpyA,eax,addr rfpwfd.cFileName
			invoke GetFileAttributesA,ADDR rfpszSearchString

			inc D[rfpnFileEnum]
			push eax
			push ADDR rfpszSearchString
			call [pCallback]
			mov [rfpfEndProc],eax
			or eax,eax
			jz >E1
			:
		C2:
		invoke FindNextFileA,[hwfd],addr rfpwfd
		or eax,eax
		jne	<<N1
		E1:
		invoke FindClose,[hwfd]

	E2:

	ret

ENDF
