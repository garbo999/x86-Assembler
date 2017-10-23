
.code

DateStamp2FileTime FRAME DateStamp,pFILETIME
	mov eax,[DateStamp]
	mov edx,10000000
	mul edx
	add eax,0D53E8000h
	adc edx,0019DB1DEh
	mov ecx,[pFILETIME]
	mov [ecx],eax
	mov [ecx+4],edx
	ret
ENDF

