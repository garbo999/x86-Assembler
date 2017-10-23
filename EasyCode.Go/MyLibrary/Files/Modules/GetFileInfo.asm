#include Files.Inc

/*
Files.lib(GetFileInfo.obj) : error LNK2001: ???????????????????????????? _GetFileVersionInfoSize@8
Files.lib(GetFileInfo.obj) : error LNK2001: ???????????????????????????? _GetFileVersionInfoA@16
Files.lib(GetFileInfo.obj) : error LNK2001: ???????????????????????????? _VerQueryValueA@16
TestFileLib.exe : fatal error LNK1120: 3 ?????????????????????????
*/

.code

GetFileInfo FRAME pFileName,pFileTitle,pFileSize,pFileTime,pVer
	uses ebx,ecx
	LOCAL fi			:BY_HANDLE_FILE_INFORMATION
	LOCAL Verifictaion	:D
	LOCAL RootPath		:D
	LOCAL pVersion		:D
	LOCAL pVersionLen	:D
	LOCAL pProdName		:D
	LOCAL wfd			:WIN32_FIND_DATA

	/*
	Returns various file information

	This procedure requires a fully qualified path !
	*/

	/*
	Errors returned
	-1 = File not found
	*/

	; Zero the returns so that random data is eliminated
	mov eax,[pVer]
	mov D[eax],0
	mov D[eax+4],0

	mov eax,[pFileTime]
	mov D[eax],0
	mov D[eax+4],0

	; Verify that the file exists
	invoke FindFirstFileA,[pFileName],OFFSET wfd
	or eax,eax
	jns >
		; Return -1 to indicate that the file was not found
		ret
	:
	invoke FindClose,eax

	; WIN32_FIND_DATA contains alot of the info we need
	; The file time is a QWORD so it has to be split into H/L
	mov ecx,[pFileTime]
	mov eax,[wfd.ftLastWriteTime]
	mov [ecx],eax
	mov eax,[wfd.ftLastWriteTime+4]
	mov [ecx+4],eax

	; We are only concerned with FileSizeLow
	mov eax,[wfd.nFileSizeLow]
	mov ecx,[pFileSize]
	mov [ecx],eax

	; Get the filename without the path if not NULL pointer
	cmp D[pFileTitle],0
	je >
		invoke lstrcpyA,[pFileTitle],OFFSET wfd.cFileName
	:

	; Get the version information only if present
	invoke GetFileVersionInfoSizeA,[pFileName],OFFSET Verifictaion
	or eax,eax
	jz >>.EXIT
		push eax
		invoke GlobalAlloc,040h,eax
		mov ebx,eax
		pop eax
		invoke GetFileVersionInfoA,[pFileName],NULL,eax,ebx
		mov D[RootPath],"\"
		invoke VerQueryValueA,ebx,OFFSET RootPath,OFFSET pVersion,OFFSET pVersionLen
		mov eax,[pVersion]
		mov edx,[pVer]
		mov ecx,[eax+VS_FIXEDFILEINFO.dwFileVersionLS]
		mov [edx],ecx
		mov ecx,[eax+VS_FIXEDFILEINFO.dwFileVersionMS]
		mov [edx+4],ecx

		invoke GlobalFree,ebx

	.EXIT

	xor eax,eax
	ret
ENDF
