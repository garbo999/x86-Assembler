.code

GetCL FRAME ArgNum, ItemBuffer
	; GetCL
	; Shamelessly stolen from the MASM32 library
	; Copyright © The MASM32 Project 1998 - 2003
	;
	; hutch@movsd.com
	;
	; -------------------------------------------------
	; arguments returned in "ItemBuffer"
	;
	; arg 0 = program name
	; arg 1 = 1st arg
	; arg 2 = 2nd arg etc....
	; -------------------------------------------------
	; Return values in eax
	;
	; 1 = successful operation
	; 2 = no argument exists at specified arg number
	; 3 = non matching quotation marks
	; 4 = empty quotation marks
	; -------------------------------------------------

	LOCAL lpCmdLine			:D
	LOCAL cmdBuffer[192]	:B
	LOCAL tmpBuffer[192]	:B

	push esi
	push edi

	invoke GetCommandLineA
	mov [lpCmdLine], eax	; address command line

	; -------------------------------------------------
	; count quotation marks to see if pairs are matched
	; -------------------------------------------------
	xor ecx, ecx            ; zero ecx & use as counter
	mov esi, [lpCmdLine]

	:
		lodsb
		cmp al, 0
		je >
		cmp al, 34		; [ " ] character
		jne<
		inc ecx			; increment counter
		jmp <
	:

	push ecx			; save count

	shr ecx, 1			; integer divide ecx by 2
	shl ecx, 1			; multiply ecx by 2 to get dividend

	pop eax				; put count in eax
	cmp eax, ecx		; check if they are the same
	je >
		pop edi
		pop esi
		mov eax, 3		; return 3 in eax = non matching quotation marks
		ret
	:

	; ------------------------
	; replace tabs with spaces
	; ------------------------
	mov esi, [lpCmdLine]
	lea edi, cmdBuffer

	:
		lodsb
		cmp al, 0
		je >R2 ;.rtOut
		cmp al, 9		; tab
		jne >R1 ;.rtIn
		mov al, 32
	R1: ;.rtIn
		stosb
		jmp <
	R2: ;.rtOut
		stosb			; write last byte

	; -----------------------------------------------------------
	; substitute spaces in quoted text with replacement character
	; -----------------------------------------------------------
	lea eax, cmdBuffer
	mov esi, eax
	mov edi, eax

	S1:
		lodsb
		cmp al, 0
		jne >
		jmp >S2
	:
		cmp al, 34
		jne >S3
		stosb
		jmp >S4		; goto subloop
	S3:
		stosb
		jmp <S1

	S4:
		lodsb
		cmp al, 32		; space
		jne >
		mov al, 254		; substitute character
	:
		cmp al, 34
		jne >
		stosb
		jmp <S1
	:
		stosb
		jmp <S4

	S2:
		stosb			; write last byte

	; ----------------------------------------------------
	; the following code determines the correct arg number
	; and writes the arg into the destination buffer
	; ----------------------------------------------------
	lea eax, cmdBuffer
	mov esi, eax
	lea edi, tmpBuffer

	mov ecx, 0			; use ecx as counter

	; ---------------------------
	; strip leading spaces if any
	; ---------------------------
	:
		lodsb
		cmp al, 32
		je <

	L1:
		cmp ecx, [ArgNum]	; the number of the required cmdline arg
		je >C1
		lodsb
		cmp al, 0
		je >C2
		cmp al, 32
		jne >C3		; if not space
	
	:
		lodsb
		cmp al, 32			; catch consecutive spaces
		je <
	
		inc ecx				; increment arg count
		cmp al, 0
		je >C2

	C3:
		jmp <L1
	
	C1:
		stosb
	:
		lodsb
		cmp al, 32
		je >C2
		cmp al, 0
		je >C2
		stosb
		jmp <

	C2:
		mov al, 0
		stosb

	; ------------------------------
	; exit if arg number not reached
	; ------------------------------
	cmp ecx,[ArgNum]
	jae >
		mov edi, [ItemBuffer]
		mov al, 0
		stosb
		mov eax, 2		; return value of 2 means arg did not exist
		pop edi
		pop esi
		ret
	:

	; -------------------------------------------------------------
	; remove quotation marks and replace the substitution character
	; -------------------------------------------------------------
	lea eax, tmpBuffer
	mov esi, eax
	mov edi, [ItemBuffer]

	Q1:
		lodsb
		cmp al, 0
		je >Q2
		cmp al, 34		; dont write [ " ] mark
		je <Q1
		cmp al, 254
		jne >
		mov al, 32		; substitute space
	:
		stosb
		jmp <Q1

	Q2:
		stosb			; write zero terminator

	; ------------------
	; handle empty quote
	; ------------------
	mov esi, [ItemBuffer]
		lodsb
		cmp al, 0
		jne >
		pop edi
		pop esi
		mov eax, 4		; return value for empty quote
		ret
	:

	mov eax, 1			; return value success

	pop edi
	pop esi

    ret

ENDF


