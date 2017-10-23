#IFNDEF INLINE_ASM
#DEFINE INLINE_ASM

INLINE_ASM_VERSION equ 0x101 // 1.01

// This is a headers standard file, do not add to it, remove or
// rename any function. If you have a function to add visit the
// forum to submit it:
// http://www.masm32.com/board/index.php?topic=15622.msg128310#msg128310

// The reason you are asked not to add or remove functions is so that
// all users of the header files will have exactly the same code base
// and be able to build any project as long as their headers are up to
// date.

// All function names must begin with inl_

// All labels in this inline file use a percent (%) prefix so they
// will not conflict with any user labels. No functions can require
// outside data to be defined.

// This file must be included as the last line in your primary source
// asm file. It will fail otherwise.

// All functions are required to preserve EDI, ESI and EBX

#IFDEF inl_lszCase
CONST SECTION
	%lcase:
		db   0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15
		db  16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31
		db  32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47
		db  48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63
		db  64, 97, 98, 99,100,101,102,103,104,105,106,107,108,109,110,111
		db 112,113,114,115,116,117,118,119,120,121,122, 91, 92, 93, 94, 95
		db  96, 97, 98, 99,100,101,102,103,104,105,106,107,108,109,110,111
		db 112,113,114,115,116,117,118,119,120,121,122,123,124,125,126,127
		db 128,129,130,131,132,133,134,135,136,137,138,139,140,141,142,143
		db 144,145,146,147,148,149,150,151,152,153,154,155,156,156,158,159
		db 160,161,162,163,164,165,166,167,168,169,170,171,172,173,173,175
		db 176,177,178,179,180,181,182,183,184,185,186,187,188,189,190,191
		db 192,193,194,195,196,197,198,199,200,201,202,203,204,205,206,207
		db 208,209,210,211,212,213,214,215,216,217,218,219,220,221,222,223
		db 224,225,226,227,228,229,230,231,232,233,234,235,236,237,238,239
		db 240,241,242,243,244,245,246,247,248,249,250,251,252,253,254,255
	
	align 16
	%ucase:
		db   0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15
		db  16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31
		db  32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47
		db  48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63
		db  64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79
		db  80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95
		db  96, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79
		db  80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90,123,124,125,126,127
		db 128,129,130,131,132,133,134,135,136,137,138,139,140,141,142,143
		db 144,145,146,147,148,149,150,151,152,153,154,155,156,156,158,159
		db 160,161,162,163,164,165,166,167,168,169,170,171,172,173,173,175
		db 176,177,178,179,180,181,182,183,184,185,186,187,188,189,190,191
		db 192,193,194,195,196,197,198,199,200,201,202,203,204,205,206,207
		db 208,209,210,211,212,213,214,215,216,217,218,219,220,221,222,223
		db 224,225,226,227,228,229,230,231,232,233,234,235,236,237,238,239
		db 240,241,242,243,244,245,246,247,248,249,250,251,252,253,254,255

#ENDIF

#IFDEF inl_lszCase
	CODE SECTION
	inl_lszCase FRAME %pString,%fCase
		uses ebx,esi,edi
	
	/*
		Converts a string to upper case or lowercase
		Parameters:
			pString = String to convert
			fCase = TRUE = Upper case, FALSE = Lower case
		Returns the pointer to the buffer
	*/
	
		mov ebx,offset %lcase
		cmp D[%fCase],1
		jne >
		mov ebx,offset %ucase
		:
	
		mov edi,[%pString]
		mov esi,[%pString]
		xor ecx,ecx
		:
		mov al,[esi+ecx]
		xlatb
		mov [edi+ecx],al
		inc ecx
		or al,al
		jnz <
		:
	
		mov eax,edi
		RET
	ENDF
#ENDIF

#IFDEF inl_lszCmp
	CODE SECTION
	inl_lszCmp FRAME %pString1,%pString2
		uses esi,edi
	
		mov edi, [%pString1]
		mov esi, [%pString2]
		:
		mov cl, [edi]
		mov ch, [esi]
		add edi,1
		add esi,1
		sub cl, ch
		jnz >
		or ch, ch
		jnz <
		:
		movsx eax, cl
		ret
	
	ENDF
#ENDIF

#IFDEF inl_MemCopy
	CODE SECTION
	inl_MemCopy FRAME %lpDest,%lpSource,%nBytes
		uses edi,esi,ecx
		cld
		mov edi,[%lpDest]
		mov esi,[%lpSource]
		mov ecx,[%nBytes]
	
		; do the evenly divisible ones
		shr ecx,2
		rep movsd
	
		; do the remainder
		mov ecx,[%nBytes]
		and ecx,3
		rep movsb
	
		RET
	ENDF
#ENDIF

#IFDEF inl_lszCopy
	CODE SECTION
	inl_lszCopy FRAME %pDest,%pSource
		uses edi,esi
	
		mov edi,[%pDest]
		mov esi,[%pSource]
	
		test esi,7
		jz >L1
		:
			mov al,[esi]
			mov [edi],al
			or al,al
			jz >D1
			inc esi
			inc edi
			test esi,7
		jne <
	
		ALIGN 16
		L1:
			mov eax,[esi]
			; Test for 0 byte
			mov edx,eax
			lea ecx,[edx-01010101h]
			not edx
			and ecx,edx
			and ecx,80808080h
			jnz >
			; No 0 byte so copy the dword
			mov [edi],eax
			add esi,4
			add edi,4
			jmp <L1
		:
		; Remainder
		bsf ecx,ecx
		shr ecx,3
		inc ecx
		rep movsb
	
		lea eax,[edi-1]
		sub eax,[%pDest]
		D1:
	
		RET
	ENDF
#ENDIF

#IFDEF inl_lszCopyn
	CODE SECTION
	inl_lszCopyn FRAME %lpDest,%lpSource,%nBytes
		uses edi,esi,ecx
		cld
		mov edi,[%lpDest]
		mov esi,[%lpSource]
		invoke inl_lszLen,[%lpSource]
		mov ecx,[%nBytes]
	
		cmp ecx,eax
		jle >
			inc eax
			mov ecx,eax
		:
	
		; do the evenly divisible ones
		shr ecx,2
		rep movsd
	
		; do the remainder
		mov ecx,[%nBytes]
		and ecx,3
		rep movsb
	
		mov B[edi],0
	
		mov eax,[%lpDest]
	   RET
	ENDF
#ENDIF

#IFDEF inl_lszCat
	CODE SECTION
	inl_lszCat FRAME %lpDest,%lpAdd
		push edi
	
		invoke inl_lszLen,[%lpDest]
		mov edi,[%lpDest]
		mov ecx,[%lpAdd]
		add edi,eax
		xor edx,edx
		xor eax,eax
	
		:
			mov al, [ecx+edx]
			mov [edi+edx], al
			add edx, 1
			test al,al
			jne <
	
		pop edi
		mov eax,[%lpDest]
	
		ret
	
	ENDF
#ENDIF

#IFDEF inl_lszLen
	CODE SECTION
	inl_lszLen FRAME %pString
		uses ebx,edx,ecx,esi
	
			mov	eax,[%pString]
			mov esi,eax
			test eax,3
			jz >N1
				add eax,3
				and eax,-4
	ALIGN 4
			:
				mov dl,[esi]
				or dl,dl
				jz >E1
				inc esi
				cmp esi,eax
			jl <
	
			N1:
			lea		edx,[eax+3]
	
	ALIGN 4
		:  
			mov		ebx,[eax]
			add		eax,4
			lea		ecx,[ebx-01010101h]
			not		ebx
			and		ecx,ebx
			and		ecx,80808080h    
			jz		<
			test	ecx,00008080h
			jnz		>
			shr		ecx,16
			add		eax,2
		:
			shl		cl,1
			sbb		eax,edx
	
		add eax,esi
		sub eax,[%pString]
		ret
	
		E1:
		mov eax,esi
		sub eax,[%pString]
		ret
	ENDF
#ENDIF

#IFDEF inl_CountFileLines
GOASM_ECHO inl_CountFileLines written by Mark Larson

DATA SECTION
	%count_table DD 256 DUP (?)
CODE SECTION
inl_CountFileLines FRAME %pFilebuffer, %cbFile
	uses edi,esi,ebx
	// This routine just counts the lines in a file
	// in reality it just counts character 0Dh

	// By Mark Larson

	mov eax,0a0a0a0ah
	movd mm7,eax
	pshufw mm7,mm7,00000000b

	xor eax,eax // initialize line count to zero.
	// pad pFileBuffer with 16 0's on the end, because pFielbuffer might not be divisible by 16.
	mov edi,[%pFilebuffer]
	mov esi,[%cbFile]

	lea  esi,[esi+edi]

	align 16 // for P3 and below.
	:
	movq mm0,[edi]
	movq mm1,[edi+8]
	add edi,16

	pcmpeqb mm0,mm7
	pcmpeqb mm1,mm7
	pmovmskb ebx,mm0
	pmovmskb ecx,mm1
	// eax is running count.

	movzx  edx,bl
	movzx  ebx,cl

	add    eax,[%count_table+edx*4]
	add    eax,[%count_table+ebx*4]

	cmp edi,esi
	jb <

	RET
ENDF
#ENDIF

#ENDIF