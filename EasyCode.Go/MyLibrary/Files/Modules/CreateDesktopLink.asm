#Include Link.inc

.data
CDLShl32	DB "Shell32.dll",0

.code

CreateDesktopLink FRAME lpLinkTarget,lpLinkName,lpDescription
	LOCAL DesktopPath[260]	:B
	LOCAL PIDL[32]			:D
	LOCAL BackSlash			:D
	LOCAL LnkExt			:Q
	LOCAL hLib				:D
	LOCAL pFreePIDL			:D

	invoke LoadLibraryA,offset CDLShl32
	mov [hLib],eax
	invoke GetProcAddress,eax,155
	mov [pFreePIDL],eax

	mov D[BackSlash],0
	mov B[BackSlash],5Ch
	
	mov D[LnkExt],04B4E4C2Eh
	mov D[LnkExt+4],0

	invoke SHGetSpecialFolderLocation,NULL,CSIDL_DESKTOP,offset PIDL
	invoke SHGetPathFromIDListA,[PIDL],offset DesktopPath
	invoke [pFreePIDL],[PIDL] ; ILFree
	invoke lstrcatA,offset DesktopPath,offset BackSlash
	invoke lstrcatA,offset DesktopPath,[lpLinkName]
	invoke lstrcatA,offset DesktopPath,offset LnkExt
	invoke CreateLink,[lpLinkTarget],OFFSET DesktopPath,[lpDescription]
	invoke FreeLibrary,[hLib]

	RET
ENDF
