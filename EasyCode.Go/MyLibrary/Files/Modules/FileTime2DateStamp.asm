.code

FileTime2DateStamp FRAME pFileTime
	
	mov ecx,[pFileTime]
	mov eax,[ecx]
	mov edx,[ecx+4]
	sub eax,0D53E8000h
	sbb edx,0019DB1DEh

	mov ecx,10000000
	div ecx
	
	RET
ENDF
