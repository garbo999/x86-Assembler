#Include Link.inc

.data
CSMLShl32	DB "Shell32.dll",0

.code

CreateStartmenuLink FRAME lpLinkTarget,lpLinkName,lpDescription,lpProgramGroup
	LOCAL Startmenupath[260]	:B
	LOCAL PIDL[32]				:D
	LOCAL BackSlash				:D
	LOCAL LnkExt				:Q
	LOCAL hLib					:D
	LOCAL pFreePIDL				:D

	invoke LoadLibraryA,offset CSMLShl32
	mov [hLib],eax
	invoke GetProcAddress,eax,155
	mov [pFreePIDL],eax

	mov D[BackSlash],0
	mov B[BackSlash],5Ch

	mov D[LnkExt],04B4E4C2Eh
	mov D[LnkExt+4],0

	invoke SHGetSpecialFolderLocation,NULL,CSIDL_COMMON_PROGRAMS,offset PIDL
	invoke SHGetPathFromIDListA,[PIDL],offset Startmenupath
	invoke [pFreePIDL],[PIDL]
	invoke lstrcatA,offset Startmenupath,offset BackSlash
	cmp D[lpProgramGroup],NULL
	je >
		invoke lstrcatA,offset Startmenupath,[lpProgramGroup]
		invoke lstrcatA,offset Startmenupath,offset BackSlash
	:
	invoke lstrcatA,offset Startmenupath,[lpLinkName]
	invoke lstrcatA,offset Startmenupath,offset LnkExt
	invoke CreateLink,[lpLinkTarget],OFFSET Startmenupath,[lpDescription]
	invoke FreeLibrary,[hLib]

	RET
ENDF