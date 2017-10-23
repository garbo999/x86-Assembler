.code
GetTopIndex FRAME pArray
	
	mov eax,[pArray]
	mov eax,[eax]
	dec eax
	RET
ENDF
