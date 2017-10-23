.data
CRCtable	dd	256 DUP (?)

.code
/*
Thomas Bleeker
http://www.madwizard.org/

Some of the best assembly tutorials on the web
*/

InitCRC32Table:
	uses ebx, esi, edi
	mov		edi, offset CRCtable  - 4
	xor		ecx, ecx
	
	M1:
	mov		eax, ecx
	mov		ebx, 0EDB88320h
	add		edi, 4
	mov		esi, 8
	:
		shr eax, 1    
		sbb edx, edx  
		and edx, ebx
		xor eax, edx
	dec	esi
	jnz	<
	inc		ecx
	mov		[edi], eax
	cmp		ecx, 256
	jb 		<M1

	mov eax,offset CRCtable
	ret
ENDU

CRC32 FRAME lpBuffer, cbBuffer
	uses ebx, esi, edi

	mov		esi, [lpBuffer]
	mov		edi, offset CRCtable
	mov		edx, [cbBuffer]
	shr		edx, 1
	or		ecx, -1
	xor		eax, eax

	:
	mov		al, [esi]
	xor		al, cl
	shr		ecx, 8
	mov		ebx, [edi+4*eax]
	xor		ecx, ebx

	mov		al, [esi+1]
	xor		al, cl
	shr		ecx, 8
	mov		ebx, [edi+4*eax]
	add		esi,2
	xor		ecx, ebx

	dec		edx
	jnz		<

	test	D[cbBuffer], 1
	jz		>
	mov		al, [esi]
	xor		al, cl
	inc		esi
	shr		ecx, 8
	mov		ebx, [edi+4*eax]
	xor		ecx, ebx
	:

	mov		eax, ecx   
	not		eax
    ret
ENDF
