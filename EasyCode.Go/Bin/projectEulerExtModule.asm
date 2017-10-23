;EasyCodeName=projectEulerExtModule,1
;EasyCodeName=projectEuler,1
.Const

.Data

.Code
getProb23Function Frame inputValue, ptrEndOfAbundantNumberArray

	Uses Ebx, Ecx

	Local hHeap:D, subArrayCount:D, ptrSubArray:D

;
; PURPOSE: Returns TRUE if inputValue is sum of two abundant numbers, otherwise FALSE
;
; REGISTERS:
;
; Eax =
; Ebx = inputValue
; Ecx = subArrayCount, outer_loop_counter
; Edx = inner_loop_counter
; Esi = ptrEndOfAbundantNumberArray
; Edi = ptrSubArray
;

	; count number of abundant numbers < N and save to subArrayCount
	Mov Esi, [ptrEndOfAbundantNumberArray]
	Sub Esi, 4	; points to last element in array
	Mov Ecx, 0
	Mov [hHeap], Ecx ; hHeap = 0 (use this at end to check whether necessary to free allocated memory)

L1:

	Mov Eax, [Esi]
	Cmp Eax, [inputValue]
	Jae > D1
		Inc Ecx
		Sub Esi, 4
		Jmp L1

D1:

	Cmp Ecx, 0	; return FALSE if subArrayCount = 0
	Jne > P1
		Mov Eax, FALSE
		Jmp >.functionFinalProcessing

P1:

	; save count
	Mov [subArrayCount], Ecx

	; allocate memory and copy relevant (smaller) abundant numbers into array
	; in ascending order
	Shl Ecx, 4	; = subArrayCount * 4 for double words
	;Invoke HeapCreate, NULL, 0B601H, NULL
	; Push
	Invoke GetProcessHeap
	Mov [hHeap], Eax
	Invoke HeapAlloc, [hHeap], HEAP_ZERO_MEMORY, Ecx
	Mov [ptrSubArray], Eax
	; Pop

	; build array
	Mov Esi, [ptrEndOfAbundantNumberArray]
	Sub Esi, 4	; points to last element in array
	Mov Edi, [ptrSubArray]
	Mov Ecx, [subArrayCount]

L2:
	Mov Eax, [Esi]
 	Mov [Edi], Eax
 	Add Edi, 4
 	Sub Esi, 4
 	Loop L2

	;Mov Edi, [ptrSubArray] ; for debugging

	; now we have our array of abundant numbers at ptrSubArray
	Mov Ebx, [inputValue]
	Mov Ecx, 0 ; outer_loop_counter = 0
	Mov Edi, [ptrSubArray]

L3:

	Mov Edx, Ecx ; inner_loop_counter = outer_loop_counter

	L4:

		; Get sum of two abundant numbers = Eax
		Mov Eax, [Edi + 4 * Ecx]
		Add Eax, [Edi + 4 * Edx]

		; if sum = inputValue THEN return TRUE
		Cmp Eax, Ebx
			Jne > P2
			Mov Eax, TRUE
			Jmp >.functionFinalProcessing

	P2:

		; if sum > inputValue THEN next LOOP1
		Cmp Eax, Ebx
			Ja >.finalProcessing_L3

		.finalProcessing_L4
		Inc Edx
		Cmp Edx, [subArrayCount]
			Jb L4

.finalProcessing_L3
	Inc Ecx
	Cmp Ecx, [subArrayCount]
		Jb L3

	; if we get here (checked all possible sums in loops), return FALSE
	Mov Eax, FALSE

.functionFinalProcessing

	Mov Ebx, [hHeap]	; check whether memory needs to be freed
	Cmp Ebx, 0
		Jne >.needToFreeMemory
		Ret

.needToFreeMemory
	Push Eax
	Invoke HeapFree, [hHeap], NULL, [ptrSubArray]
	Pop Eax
	Ret

EndF

getSqrtDD Frame inputValue

Local fpu_cw_1:W, fpu_cw_2:W

;
; REGISTERS:
;	- Eax
;
; USAGE: "Invoke getSqrtDD, Eax"
;
; INPUT VALUE:
;	- inputValue
;
; RETURN VALUE:
; 	- Eax = integer square root of 32-bit number
;

	; Prepare FPU
	Fstcw W[fpu_cw_1]	; Get current control word to retain all setting bits
                 		; not related to rounding control (RC) bits
	Fwait				; Ensures storage instruction is completed
	Mov Ax, [fpu_cw_1]
;	And Ax, 0F3FFH 		; Clears only RC bits, leaving all other bits unchanged
						; But not necessary here because both bits will be set
	Or Ax, 0C00H  		; This will set both bits of RC field to truncating mode
                  		; without affecting any of other field's bits
    Mov [fpu_cw_2], Ax	; Store modified control word in memory
    Fldcw W[fpu_cw_2] 	; Load modified control word

	;
	; Reminder: restore control word at end of routine --> Fldcw W[fpu_cw_1]
	;
	; Take square root of value
	; Floating point op: load value from memory, take sqrt, save back to memory
	; DUMB MISTAKE: used Fist instead of Fistp, I think FPU stack has to be popped or otherwise gets corrupted
	;

	Fild D[inputValue]
	Fsqrt
	Fistp D[inputValue]

	; get sqrt to return in Eax
	Mov Eax, [inputValue]

	; restore original FPU Control Word
    Fldcw W[fpu_cw_1]

Ret

EndF
getProb18RecursiveFunction_v2 Frame ptrTriangleArray, ptrRowIndexArray

Uses Eax, Ebx, Ecx, Edi

;
; new version tries to prune the tree that is generated
; idea is to check and see if current path could possibly exceed current max sum
;

;
; REGISTERS:
;
; Eax = row
; Ebx = col
; Ecx = max row, e.g. 3, 14
; Edx = path counter
; Esi = max sum of elements
; Edi = current sum, also used to hold value of 4

; save row, col
Push Eax, Ebx

; get current number based on row/column in Eax/Ebx

Push Edi, Edx	; save Edi and also Edx since Edx is influenced by multiplication
Mov Edi, 4
Mul Edi
Pop Edx, Edi	; restore Edi and also Edx
Add Eax, [ptrRowIndexArray]
Mov Eax, [Eax]	; Eax = row factor
Add Eax, Ebx	; Eax = row factor + col factor
Add Eax, [ptrTriangleArray] ; add base address of triangle array
Xor Ebx, Ebx
Mov Bl, B[Eax]	; get byte
; current number now in Ebx

; add current number
Add Edi, Ebx

; Determine max possible sum at any step = maxPotentialSum
; = number of remaining rows * 99 + current sum
; = (max row - current row) * 99 + current sum

Pop Ebx, Eax				; restore row, col
Push Eax, Ebx, Ecx, Edx		; save Eax, Ebx, Ecx, Edx
Sub Ecx, Eax				; Ecx = number of remaining rows = (max row - current row)
Mov Eax, Ecx
Mov Ebx, 99
Mul Ebx						; Eax = (max row - current row) * 99
Add Eax, Edi				; Eax = (max row - current row) * 99 + current sum

; If maxPotentialSum < current max sum
;	Then abandon processing of this path
Cmp Eax, Esi
	Ja >.cantPrunePath
	Pop Edx, Ecx, Ebx, Eax	; restore Eax, Ebx, Ecx, Edx
	Ret ; done with this path!

.cantPrunePath

; restore from stack
Pop Edx, Ecx, Ebx, Eax   		; restore Eax, Ebx, Ecx, Edx

; is last row?
Cmp Eax, Ecx
	Jb >.notLastRow
	;increment path counter
	Inc Edx
	;is sum > existing max sum?
	Cmp Edi, Esi
		Jb >.notGreaterSum
			;if so, replace existing max sum
			Mov Esi, Edi

	.notGreaterSum
	Ret

.notLastRow

;process left path
	;row += 1
	Inc Eax
	;col = unchanged
	Invoke getProb18RecursiveFunction_v2, Addr triangleArray, Addr rowIndexArray

;process right path
	;row already increment
	;col += 1
	Inc Ebx
	Invoke getProb18RecursiveFunction_v2, Addr triangleArray, Addr rowIndexArray

Ret

EndF


getProb18RecursiveFunction Frame ptrTriangleArray, ptrRowIndexArray

Uses Eax, Ebx, Ecx, Edi

;
; REGISTERS:
;
; Eax = row
; Ebx = col
; Ecx = max row, e.g. 3, 14
; Edx = path counter
; Esi = max sum of elements
; Edi = current sum, also used to hold value of 4

; save row, col
Push Eax, Ebx

; get current number based on row/column in Eax/Ebx

Push Edi, Edx	; save Edi and also Edx since Edx is influenced by multiplication
Mov Edi, 4
Mul Edi
Pop Edx, Edi	; restore Edi and also Edx
Add Eax, [ptrRowIndexArray]
Mov Eax, [Eax]	; Eax = row factor
Add Eax, Ebx	; Eax = row factor + col factor
Add Eax, [ptrTriangleArray] ; add base address of triangle array
Xor Ebx, Ebx
Mov Bl, B[Eax]	; get byte
; current number now in Ebx

; add current number

Add Edi, Ebx

; restore row, col

Pop Ebx, Eax

; is last row?
Cmp Eax, Ecx
	Jb >.notLastRow
	;increment path counter
	Inc Edx
	;is sum > existing max sum?
	Cmp Edi, Esi
		Jb >.notGreaterSum
			;if so, replace existing max sum
			Mov Esi, Edi

	.notGreaterSum
	Ret

.notLastRow

;process left path
	;row += 1
	Inc Eax
	;col = unchanged
	Invoke getProb18RecursiveFunction, Addr triangleArray, Addr rowIndexArray

;process right path
	;row already increment
	;col += 1
	Inc Ebx
	Invoke getProb18RecursiveFunction, Addr triangleArray, Addr rowIndexArray

Ret

EndF

getPrimeFactors_v2 Frame arrayPointer, primeFactorArray, numberToFactor

	; arrayPointer = array of known primes (DD array) (input value)
	; primeFactorArray = array of prime factors (output value)
	; numberToFactor = pointer to number to factor (input value = low DD, high DD)

 	; Need local versions of candidate, candidateSquareRoot, etc. due to recursion
 	; candidate = numberToFactor = DQ
	Local candidate:Q, candidateDivided:Q, candidateSquareRoot, primeFlag

	; save numberToFactor as local version (candidate)
	;Mov Eax, [numberToFactor + 4]		; high-order 32 bits
	;Mov [candidate + 4], Eax
	Mov Ebx, [numberToFactor]			; why does this get ADDRESS of numberToFactor???
	Mov Eax, [Ebx]						; low-order 32 bits
	Mov [candidate], Eax
	Mov Eax, [Ebx + 4]					; high-order 32 bits
	Mov [candidate + 4], Eax
	; Should now have numberToFactor in candidate (all 64 bits, low -- high)

	; Prepare FPU
	Fstcw W[fpu_controlword_1]	;get the current Control Word to retain all setting bits
                 				;not related to the rounding control (RC) bits
	Fwait						;to insure the storage instruction is completed
	Mov Ax, [fpu_controlword_1]
;	And Ax, 0F3FFH 				;clears only the RC bits, leaving all other bits unchanged
								;not necessary here because both bits will be set
	Or Ax, 0C00H  				;this will set both bits of the RC field to the truncating mode
                  				;without affecting any of the other field's bits
    Mov [fpu_controlword_2], Ax	; store the modified Control Word in memory
    Fldcw W[fpu_controlword_2] 	;load the modified Control Word
	; Remember to restore control word at end of routine --> Fldcw W[fpu_controlword_1]

	; Take square root of candidate since we only need to test primes up to sqrt(candidate)
	; Floating point operations: load candidate into ST0, take sqrt, save ST0 back to candidateSquareRoot
	; (DUMB THING YOU DID: used Fist instead of Fistp, I think FPU stack has to be popped or otherwise gets corrupted)
	Fild Q[candidate]			; was Q instead of D!!! DUMB MISTAKE
	Fsqrt
	Fistp D[candidateSquareRoot]

	; primeFlag = TRUE
	Mov Edx, TRUE
	Mov [primeFlag], Edx

	; Ecx = loop counter
	Mov Ecx, 0

.primeFactorLoop:

		; load current prime to test, start with 1st value in array (arrayPointer[0] = 2)
		Mov Ebx, [arrayPointer]
		Mov Eax, [Ebx + 4 * Ecx]

		; if current prime > candidateSquareRoot, we're done (candidate is prime)
		Cmp Eax, [candidateSquareRoot]
		Ja >>.primeFactorLoopDone

		Push Ecx					; Ecx holds loop counter but needed here for division

		; Limit not yet reached so test this prime
		; Divide candidate by current prime of interest
		; Need to use special division for large number (DQ)
		;Mov Edx, [candidate + 4]	; dividend, high NNNNNNNOOOOO!!!!!
		;Mov Ecx, Eax				; divisor = current prime we are checking
		;Mov Eax, [candidate]		; dividend, low
		;Div Ecx						; Eax = quotient, Edx = remainder

		Mov Edx, 0
		Mov Ecx, Eax				; divisor = current prime we are checking
		Mov Eax, [candidate + 4]
		Div Ecx
		Mov [candidateDivided + 4], Eax

		; 2nd division
		Mov Eax, [candidate]
		Div Ecx
		Mov [candidateDivided], Eax

		Pop Ecx						; Reload loop counter

		; see if candidate/current prime = modulo 0 (--> not prime)
		Cmp Edx, 0
		Jnz >.primeFactorLoopFinalProcessing
			; primeFlag = FALSE
			Mov Edx, FALSE
			Mov [primeFlag], Edx
			Jmp >.primeFactorLoopDone

.primeFactorLoopFinalProcessing:

	; Increment counter and loop back
	Inc Ecx
	Jmp .primeFactorLoop

.primeFactorLoopDone:

	Mov Edx, [primeFlag]
	Cmp Edx, TRUE
	Jnz >.notPrime_2
		; candidate is prime
		Mov Eax, [candidate] ; candidate is DQ but we assume that any factor fits in 32 bits!
		Mov Ebx, [primeFactorArray]
		Mov [Ebx], Eax
		; PushAD
		;Invoke String, Eax, Addr myStringVar, ecDecimal
		;Invoke MessageBoxA, [hWnd], Addr myStringVar, 'Problem 3: Prime factor', MB_ICONINFORMATION
		;PopAD
		Jmp >.finalProcessing_4

.notPrime_2

	; Move saved quotient in candidateDivided as new value for numberToFactor
	Mov Ebx, [numberToFactor]
	Mov Eax, [candidateDivided]
	Mov [Ebx], Eax
	Mov Eax, [candidateDivided + 4]
	Mov [Ebx + 4], Eax

	; Save the prime factor we just discovered (have to reload it)
	Mov Ebx, [arrayPointer]
	Mov Eax, [Ebx + 4 * Ecx]
	Mov Ebx, [primeFactorArray]
	Mov [Ebx], Eax

	; Ebx already holds current primeFactorArray pointer
	; Increment for recursive call
	Add Ebx, 4

	Mov Eax, [numberToFactor]

	; Recursive call to this function
	Invoke getPrimeFactors_v2, Addr knownPrimes, Ebx, Eax

.finalProcessing_4

	; restore original FPU Control Word
    Fldcw W[fpu_controlword_1]

	Ret
EndF
getPrimesArray Frame arrayPointer, numberOfPrimes

; add a Uses statement to save registers
;Uses Ebx, Esi, Edi

	Local candidate, candidateSquareRoot, primeCount, primeFlag, fpu_controlword_1, fpu_controlword_2

.AAA_Breakpoint_1

	; EULER problem 7, version 3 (function version) with local variables
	; Function fills a specified array with the desired number of primes (2, 3, 5, ...)

	; Initialize variables
	; Store 2 and 3 in array
	Mov Ebx, [arrayPointer]			; Ebx = ptr to knownPrimes[0]
	Mov Eax, 2						; first prime = 2
	Mov [Ebx], Eax					; arrayPointer[0] = 2
	Mov Eax, 3						; second prime = 3
	Mov [Ebx + 4], Eax				; arrayPointer[1] = 3

	; Initialise variables
	; First candidate to check = 5
	Mov Eax, 5
	Mov [candidate], Eax

	; Two primes already known (= 2, 3)
	Mov Eax, 2
	Mov [primeCount], Eax

	; Prepare FPU
	Fstcw W[fpu_controlword_1]	;get the current Control Word to retain all setting bits
                 				;not related to the rounding control (RC) bits
	Fwait						;to insure the storage instruction is completed
	Mov Ax, [fpu_controlword_1]
;	And Ax, 0F3FFH 				;clears only the RC bits, leaving all other bits unchanged
								;not necessary here because both bits will be set
	Or Ax, 0C00H  				;this will set both bits of the RC field to the truncating mode
                  				;without affecting any of the other field's bits
    Mov [fpu_controlword_2], Ax	; store the modified Control Word in memory
    Fldcw W[fpu_controlword_2] 	;load the modified Control Word
	; Remember to restore control word at end of routine --> Fldcw W[fpu_controlword_1]

.mainLoopStart_3:

	; Take square root of candidate since we only need to test primes up to sqrt(candidate)
	; Floating point operations: load candidate into ST0, take sqrt, save ST0 back to candidateSquareRoot
	; (DUMB THING YOU DID: used Fist instead of Fistp, I think FPU stack has to be popped or otherwise gets corrupted)
	Fild D[candidate]
	Fsqrt
	Fistp D[candidateSquareRoot]

	; primeFlag = TRUE
	Mov Eax, TRUE
	Mov [primeFlag], Eax

	; Ecx = loop counter
	Mov Ecx, 1

.secondaryLoop_3:

		; load current prime to test, start with 3
		; Ebx = arrayPointer[0]
		Mov Eax, [Ebx + 4 * Ecx]

		; if current prime > candidateSquareRoot, we're done (candidate is prime)
		Cmp Eax, [candidateSquareRoot]
		Ja >>.testDone_3

		Push Ecx					; Ecx holds loop counter but needed here for division

		; Limit not yet reached so test this prime
		; Divide candidate by current prime of interest
		Mov Edx, 0					; clear dividend, high
		Mov Ecx, Eax				; divisor = current prime we are checking
		Mov Eax, [candidate]		; dividend, low
		Div Ecx						; Eax = quotient, Edx = remainder

		Pop Ecx						; Reload loop counter

		; see if candidate/current prime = modulo 0 (--> not prime)
		Cmp Edx, 0
		Jnz >.secondaryLoopEnd_3
			; primeFlag = FALSE
			Mov Eax, FALSE
			Mov [primeFlag], Eax
			Jmp >.testDone_3

.secondaryLoopEnd_3:

	; Increment counter and loop back
	Inc Ecx
	Jmp .secondaryLoop_3

.testDone_3:

	; Get primeCount in Ecx for final processing
	Mov Ecx, [primeCount]

	; IF primeFlag = TRUE THEN add new prime to array
	Mov Eax, [primeFlag]
	Cmp Eax, TRUE
	Jnz >.mainLoopEnd_3
		Mov Eax, [candidate]
		Mov Ebx, [arrayPointer]
		Mov [Ebx + 4 * Ecx], Eax			; save new prime at end of knownPrimes array
		Add Ecx, 1							; primeCount += 1
		Mov [primeCount], Ecx

.mainLoopEnd_3:

	; candidate += 2 (next odd number)
	Mov Eax, [candidate]
	Add Eax, 2
	Mov [candidate], Eax

	; Compare primeCount and numberOfPrimes, loop back if primeCount < numberOfPrimes
	Mov Eax, [numberOfPrimes]
	Cmp Ecx, Eax
	Jnz .mainLoopStart_3

.finalProcessing_3

	; restore original FPU Control Word
    Fldcw W[fpu_controlword_1]

   	Ret
EndF

getJulianDayNumber Frame jYear, jMonth, jDay

	Local jdn:D, jAaa:D

	; jAaa = (14 - jMonth) / 12
	Mov Edx, 0
	Mov Eax, 14				; Edx:Eax = 14
	Sub Eax, [jMonth]
	Mov Ecx, 12
	Div Ecx
	Mov [jAaa], Eax

	; jYear = jYear + 4800 - jAaa
	Mov Eax, [jYear]
	Add Eax, 4800
	Sub Eax, [jAaa]
	Mov [jYear], Eax

	; jMonth = jMonth + 12*jAaa - 3
	Mov Edx, 0
	Mov Eax, [jAaa]
	Mov Ecx, 12
	Mul Ecx
	Add Eax, [jMonth]
	Sub Eax, 3
	Mov [jMonth], Eax

	; calculate big expression (http://en.wikipedia.org/wiki/Julian_day)
	; 365 * jYear
	Mov Edx, 0
	Mov Eax, [jYear]
	Mov Ecx, 365
	Mul Ecx
	Mov [jdn], Eax

	; (153 * jMonth + 2) / 5
	Mov Edx, 0
	Mov Eax, [jMonth]
	Mov Ecx, 153
	Mul Ecx
	Add Eax, 2
	Mov Edx, 0
	Mov Ecx, 5
	Div Ecx
	Add Eax, [jdn]		; add to current result
	Mov [jdn], Eax		; mov back to [jdn]

	; +jYear / 4
	Mov Edx, 0
	Mov Eax, [jYear]
	Mov Ecx, 4
	Div Ecx
	Add Eax, [jdn]		; add to current result
	Mov [jdn], Eax		; mov back to [jdn]

	; +jYear / 400
	Mov Edx, 0
	Mov Eax, [jYear]
	Mov Ecx, 400
	Div Ecx
	Add Eax, [jdn]		; add to current result
	Mov [jdn], Eax		; mov back to [jdn]

	; -jYear / 100
	Mov Edx, 0
	Mov Eax, [jYear]
	Mov Ecx, 100
	Div Ecx
	Mov Ecx, Eax
	Mov Eax, [jdn]		; get current result
	Sub Eax, Ecx
	Mov [jdn], Eax		; mov back to [jdn]

	; +day - 32045
	Mov Eax, [jdn]		; get current result
	Add Eax, [jDay]
	Sub Eax, 32045
	; Mov [jdn], Eax		; mov back to [jdn]
	; result is now in Eax

	Ret
EndF


;******************************************************************************

getProb15RecursiveFunction:

;
; REGISTERS:
;
; Eax = row
; Ebx = col
; Ecx = grid size
; Esi = arrival counter, low DW
; Edi = arrival counter, high DW

; processNode, gridSize, row, col, ptrRouteCounter

;if row = gridSize And col = gridSize
;	inc routeCounter
;	return

	Cmp Eax, Ecx
		Jne > P1
	Cmp Ebx, Ecx
		Jne > P1

	; reached bottom right corner, increment counter
	Inc Esi			; low DW
		Jnz >.prob15_add_done
		Inc Edi		; high DW

	.prob15_add_done

	Ret

P1:

;else if row = gridSize
;	invoke processNode, gridSize, row, col + 1, ptrRouteCounter
;	Return

	Cmp Eax, Ecx
		Jne > P2

	Inc Ebx
	Invoke getProb15RecursiveFunction
	Ret

P2:

;else if col = gridSize
;	invoke processNode, gridSize, row + 1, col, ptrRouteCounter
;	return

	Cmp Ebx, Ecx
		Jne > P3

	Inc Eax
	Invoke getProb15RecursiveFunction
	Ret

P3:

;else
;	invoke processNode, gridSize, row + 1, col, ptrRouteCounter
;	invoke processNode, gridSize, row, col + 1, ptrRouteCounter
;	return

	Push Eax, Ebx
	Inc Eax
	Invoke getProb15RecursiveFunction

	Pop Ebx, Eax
	Inc Ebx
	Invoke getProb15RecursiveFunction

	Ret

;******************************************************************************

getTriangleNumber:

Uses Ebx, Edx

;
; REGISTERS:
;
; Eax = input value = N
;

Xor Edx, Edx
Mov Ebx, Eax
Inc Ebx
Mul Ebx	; Eax = (N + 1) * (N)

Mov Ebx, 2
Xor Edx, Edx
Div Ebx

; Eax = return value = triangle number

Ret

EndU

getSumOfProperDivisors:

;
; derived from "getNumberOfFactors_v3"
;
;
; INPUT:
; 	Eax = N
;
; REGISTERS:
;	Ebx = N
;	Esi = number of factors
;	Edi = sqrt(N)
;	Ecx = i = loop counter
;
; OUTPUT:
; 	Eax = number of factors
;

Uses Ebx, Ecx, Edx, Edi, Esi

Push 1	; this is used later as a marker on stack when summing factors
Mov Ebx, Eax

; check special cases
Cmp Eax, 0
	Jne >.notZero
	Ret ; if 0, return 0 (not sure if this case is correct and logical)

.notZero
Cmp Eax, 1
	Je >.getCount

Cmp Eax, 2
	Jne >.mainRoutine
	Push 2
	Jmp >.getCount

.mainRoutine

Push Eax		; push N itself
Invoke getSqrtDD, Eax
Mov Edi, Eax	; Edi = sqrt(N)
Mov Ecx, 2		; begin testing factors with i = 2

L1:

	Xor Edx, Edx	; Edx = 0
	Mov Eax, Ebx
	Div Ecx
	;if mod = 0, push factor(s) (normally 2, but only 1 if sqrt)
	Cmp Edx, 0
		Jne >.notDivisor
		; Push i
		Push Ecx
		Cmp Ecx, Eax	; check for sqrt
			Je >.notDivisor
			Push Eax

	.notDivisor
	Inc Ecx
	Cmp Ecx, Edi
		Jbe L1

.getCount

Mov Esi, 0

L2:
	Pop Edi
	Add Esi, Edi
	Cmp Edi, 1
		Jne L2

Sub Esi, Ebx	; sum of proper divisors so don't include N
Mov Eax, Esi
Ret

EndU

getNumberOfFactors_v3:

;
; this version is the ULTIMATE
;
;
; INPUT:
; 	Eax = N
;
; REGISTERS:
;	Ebx = N
;	Esi = number of factors
;	Edi = sqrt(N)
;	Ecx = i = loop counter
;
; OUTPUT:
; 	Eax = number of factors
;

Uses Ebx, Ecx, Edx, Edi, Esi

Push 1	; this is used later as a marker on stack when summing factors

; check special cases
Cmp Eax, 1
	Je >.getCount

Cmp Eax, 2
	Jne >.mainRoutine
	Push 2
	Jmp >.getCount

.mainRoutine

Push Eax		; push N itself
Mov Ebx, Eax
Invoke getSqrtDD, Eax
Mov Edi, Eax	; Edi = sqrt(N)
Mov Ecx, 2		; begin testing factors with i = 2

L1:

	Xor Edx, Edx	; Edx = 0
	Mov Eax, Ebx
	Div Ecx
	;if mod = 0, push factor(s) (normally 2, but only 1 if sqrt)
	Cmp Edx, 0
		Jne >.notDivisor
		; Push i
		Push Ecx
		Cmp Ecx, Eax	; check for sqrt
			Je >.notDivisor
			Push Eax

	.notDivisor
	Inc Ecx
	Cmp Ecx, Edi
		Jbe L1

.getCount

Mov Esi, 0

L2:
	Inc Esi
	Pop Edi
	Cmp Edi, 1
		Jne L2

Mov Eax, Esi
Ret

EndU

getNumberOfFactors_v2:

;
; this version is TRASH
;

Uses Ebx, Ecx, Edx, Edi, Esi

;
; INPUT:
; 	Eax = N
;
; REGISTERS:
;	Ebx = N
;	Esi = number of factors
;	Edi = sqrt(N)
;	Ecx = i = loop counter
;

; check special cases
Cmp Eax, 1
	Jne >.not1
	Ret ; Eax = 1 factor

.not1
Cmp Eax, 2
	Jne >.not2
	Ret ; Eax = 2 factors

.not2

Mov Esi, 2 		; N has minimum of 2 factors
Mov Ebx, Eax	; Ebx = N
;Xor Edx, Edx	; Edx = 0
;Div Esi			; divide Eax by 2
Invoke getSqrtDD, Eax
Mov Edi, Eax	; Edi = sqrt(N)
Mov Ecx, 2		; begin testing factors with i = 2

L1:
	Cmp Ecx, Edi		; is i >= sqrt(N) (normally only "equals" matters except in first case where N = 3)
		Ja > D1
		;divide N by i
		Xor Edx, Edx	; Edx = 0
		Mov Eax, Ebx
		Div Ecx
		;if mod = 0, increment number of factors
		Cmp Edx, 0
			Jne >.notDivisor
			;increment number of factors 2x
			Inc Esi
			Inc Esi

		.notDivisor
		Inc Ecx
		Jmp L1


D1:

; see if N has integral sqrt; if so, need to subtract 1 factor
Xor Edx, Edx	; Edx = 0
Mov Eax, Ebx
Div Ecx
Cmp Edx, 0
	Jne > D2
	;increment number of factors 1x for sqrt
	Dec Esi

D2:

Mov Eax, Esi
Ret

EndU


getNumberOfFactors:

; initial version and brutally slow

Uses Ebx, Ecx, Edx, Edi, Esi

;
; REGISTERS:
;	Ebx = N
;	Esi = number of factors
;	Edi = N / 2
;	Ecx = i = loop counter
;

; check special cases
Cmp Eax, 1
	Jne >.not1
	Ret ; Eax = 1 factor

.not1
Cmp Eax, 2
	Jne >.not2
	Ret ; Eax = 2 factors

.not2

Mov Esi, 2 		; N has minimum of 2 factors
Mov Ebx, Eax	; Ebx = N
Xor Edx, Edx	; Edx = 0
Div Esi			; divide Eax by 2
Mov Edi, Eax	; Edx = N / 2
Mov Ecx, 2		; begin testing factors with i = 2

L1:
	Cmp Ecx, Edi		; is i > N / 2 ?
		Ja > D1
		;divide N by i
		Xor Edx, Edx	; Edx = 0
		Mov Eax, Ebx
		Div Ecx
		;if mod = 0, increment number of factors
		Cmp Edx, 0
			Jne >.notDivisor
			;increment number of factors
			Inc Esi

		.notDivisor
		Inc Ecx
		Jmp L1


D1:

Mov Eax, Esi
Ret

EndU

getProb22NameScore Frame pStr, arrayIndex

	Uses Esi, Ebx, Ecx, Edx

	Invoke GetString, [pStr], [arrayIndex]

	Mov Ecx, [arrayIndex]	; for later multiplication
	Mov Esi, Eax			; save pointer to string
	Mov Eax, 0				; sum
	Xor Ebx, Ebx			; current ascii char (clear all bits)

L1:
	Mov Bl, B[Esi]
	Cmp Bl, 0
	Je > D1
		Sub Ebx, 40H
		Add Eax, Ebx
		Inc Esi
		Jmp L1

D1:

	; multiply
	Mov Edx, 0
	Mul Ecx

	Ret
EndF

getProb14IterativeSequence:

Uses Ebx, Edx

; input = n = Eax
Mov Esi, Eax ; save copy of n
Mov Edx, 0	; Edx:Eax = dividend
Mov Ebx, 2
Div Ebx		; Eax = n/2, Edx = remainder

Cmp Edx, 0
	Jnz >.isOdd
	; n is even so return n/2
	Ret

.isOdd
Mov Eax, Esi
Mov Edx, 0	; Edx:Eax = dividend
Mov Ebx, 3
Mul Ebx
Add Eax, 1
Ret

EndU


letterCounter:

Uses Ebx, Ecx, Edx

;***** 0 to 9 *****
Cmp Eax, 0
	Jnz >.not0
	Mov Eax, 0	; zero (don't count zero!)
	Ret
.not0
Cmp Eax, 1
	Jnz >.not1
	Mov Eax, 3	; one
	Ret
.not1
Cmp Eax, 2
	Jnz >.not2
	Mov Eax, 3	; two
	Ret
.not2
Cmp Eax, 3
	Jnz >.not3
	Mov Eax, 5	; three
	Ret
.not3
Cmp Eax, 4
	Jnz >.not4
	Mov Eax, 4	; four
	Ret
.not4
Cmp Eax, 5
	Jnz >.not5
	Mov Eax, 4	; five
	Ret
.not5
Cmp Eax, 6
	Jnz >.not6
	Mov Eax, 3	; six
	Ret
.not6
Cmp Eax, 7
	Jnz >.not7
	Mov Eax, 5	; seven
	Ret
.not7
Cmp Eax, 8
	Jnz >.not8
	Mov Eax, 5	; eight
	Ret
.not8
Cmp Eax, 9
	Jnz >.not9
	Mov Eax, 4	; nine
	Ret
.not9

;***** 10 to 19 *****
Cmp Eax, 10
	Jnz >.not10
	Mov Eax, 3	; ten
	Ret
.not10
Cmp Eax, 11
	Jnz >.not11
	Mov Eax, 6	; eleven
	Ret
.not11
Cmp Eax, 12
	Jnz >.not12
	Mov Eax, 6	; twelve
	Ret
.not12
Cmp Eax, 13
	Jnz >.not13
	Mov Eax, 8	; thirteen
	Ret
.not13
Cmp Eax, 14
	Jnz >.not14
	Mov Eax, 8	; fourteen
	Ret
.not14
Cmp Eax, 15
	Jnz >.not15
	Mov Eax, 7	; fifteen
	Ret
.not15
Cmp Eax, 16
	Jnz >.not16
	Mov Eax, 7	; sixteen
	Ret
.not16
Cmp Eax, 17
	Jnz >.not17
	Mov Eax, 9	; seventeen
	Ret
.not17
Cmp Eax, 18
	Jnz >.not18
	Mov Eax, 8	; eighteen
	Ret
.not18
Cmp Eax, 19
	Jnz >.not19
	Mov Eax, 8	; nineteen
	Ret
.not19

;***** 20 to 90 in steps of 10 *****
Cmp Eax, 20
	Jnz >.not20
	Mov Eax, 6	; twenty
	Ret
.not20
Cmp Eax, 30
	Jnz >.not30
	Mov Eax, 6	; thirty
	Ret
.not30
Cmp Eax, 40
	Jnz >.not40
	Mov Eax, 5	; forty
	Ret
.not40
Cmp Eax, 50
	Jnz >.not50
	Mov Eax, 5	; fifty
	Ret
.not50
Cmp Eax, 60
	Jnz >.not60
	Mov Eax, 5	; sixty
	Ret
.not60
Cmp Eax, 70
	Jnz >.not70
	Mov Eax, 7	; seventy
	Ret
.not70
Cmp Eax, 80
	Jnz >.not80
	Mov Eax, 6	; eighty
	Ret
.not80
Cmp Eax, 90
	Jnz >.not90
	Mov Eax, 6	; ninety
	Ret
.not90

;***** 100 to 1000 in steps of 100 *****
Cmp Eax, 100
	Jnz >.not100
	Mov Eax, 10	; one hundred
	Ret
.not100
Cmp Eax, 200
	Jnz >.not200
	Mov Eax, 10	; two hundred
	Ret
.not200
Cmp Eax, 300
	Jnz >.not300
	Mov Eax, 12	; three hundred
	Ret
.not300
Cmp Eax, 400
	Jnz >.not400
	Mov Eax, 11	; four hundred
	Ret
.not400
Cmp Eax, 500
	Jnz >.not500
	Mov Eax, 11	; five hundred
	Ret
.not500
Cmp Eax, 600
	Jnz >.not600
	Mov Eax, 10	; six hundred
	Ret
.not600
Cmp Eax, 700
	Jnz >.not700
	Mov Eax, 12	; seven hundred
	Ret
.not700
Cmp Eax, 800
	Jnz >.not800
	Mov Eax, 12	; eight hundred
	Ret
.not800
Cmp Eax, 900
	Jnz >.not900
	Mov Eax, 11	; nine hundred
	Ret
.not900
Cmp Eax, 1000
	Jnz >.not1000
	Mov Eax, 11	; one thousand
	Ret
.not1000

; 21 to 99, excluding even multiples of 10
Cmp Eax, 100
Jae >.greater99

	Mov Esi, Eax	; save copy of number in Esi

	Mov Edx, 0		; divisor = Edx:Eax
	Mov Ebx, 10
	Div Ebx			; quotient = Eax, remainder = Edx

	; get 20 to 90 part
	Mov Eax, Esi	; e.g. 94
	Sub Eax, Edx	; Eax = 94 - 4 = 90
	Invoke letterCounter
	Mov Ebx, Eax	; save in Ebx

	; get 1 to 9 part
	Mov Eax, Edx	; e.g. Eax = 4
	Invoke letterCounter
	Add Eax, Ebx

	Ret

.greater99

; 101 to 999, excluding even multiples of 10

	Mov Esi, Eax	; save copy of number in Esi

	Mov Edx, 0		; divisor = Edx:Eax
	Mov Ebx, 100
	Div Ebx			; quotient = Eax, remainder = Edx

	; get 200 to 900 part
	Mov Eax, Esi	; e.g. 727
	Sub Eax, Edx	; Eax = 727 - 27 = 700
	Invoke letterCounter
	Mov Ebx, Eax	; save in Ebx
	Add Ebx, 3		; account for "and"

	; get 1 to 99 part
	Mov Eax, Edx	; e.g. Eax = 27
	Invoke letterCounter
	Add Eax, Ebx

	Ret

EndU

getDecimalStringBigNum Frame pBigNum1, pNumDoubleWords, pDecimalString, pNumDigits

; convert bigNum1 to decimal value
; store digits in pDecimalString
; store number of digits in pNumDigits

; FIXED SOMETHING HERE: the right paran on the next line was on the next line + 2
; PROBLEM: if bigNum1 < 10, returns wrong result (numDigits = 2)

	Local digitCounter, numDoubleWords

	Mov Edx, [pNumDoubleWords]       	; Edx = address pointed to by pNumDoubleWords
    Mov Eax, [Edx]                  	; Eax = value at that address
	Mov [numDoubleWords], Eax
	Mov Esi, [pBigNum1]					; Esi = pointer to big number

	; initialize
	Mov Ebx, 10   						; divisor
	Mov Eax, 0
	Mov [digitCounter], Eax				; digitCounter = 0

.getDecimalStringBigNum_loop4

	Mov Ecx, [numDoubleWords]			; loop counter (number of double words in bigNum1)
 	Mov Edx, 0							; initialize Edx = 0

.getDecimalStringBigNum_loop3

 	Mov Eax, [Esi + 4 * Ecx - 4]		; Edx:Eax = number to divide
 	Div Ebx								; Edx holds remainder from division
 	Mov [Esi + 4 * Ecx - 4], Eax
	Loop .getDecimalStringBigNum_loop3

	Push Edx							; save one digit
	Inc D[digitCounter]

	; check whether done, i.e. Eax < 10 and all higher double words of bigNum1 = 0
	Cmp Eax, 9
	Ja .getDecimalStringBigNum_loop4

	; BEGIN check all higher double words of bigNum1 = 0
	; using Ecx and Edx for this check
	Mov Ecx, [numDoubleWords]			; loop counter (number of double words in bigNum1)
	Sub Ecx, 1							; Ecx = numDoubleWords - 1

	.getDecimalStringBigNum_loop_done_check
 	Mov Edx, [Esi + 4 * Ecx]
	Cmp Edx, 0
	Jne .getDecimalStringBigNum_loop4		; this DW in bigNum1 <> 0, so need to divide again
	Dec Ecx
		Jnz .getDecimalStringBigNum_loop_done_check
	; END check all higher double words of bigNum1 = 0

	; push final digit and increment digitCounter
	Push Eax							; save last digit
	Inc D[digitCounter]

.getDecimalStringBigNum_AAA_1

	; pop digits off stack and add
	; Mov Eax, 0							; sum = 0
	Mov Ecx, [digitCounter]
	;Lea Edi, [pDecimalString]
	Mov Edi, [pDecimalString]
	Cld ; forward direction

.getDecimalStringBigNum_loop5
	Pop Eax
	Add Eax, 30H
	Stosb
	Loop .getDecimalStringBigNum_loop5

	; store digitCounter in global variable numDigits
	Mov Eax, [digitCounter]
	Mov Edx, [pNumDigits]       	; Edx = address pointed to by pNumDigits
    Mov [Edx], Eax

	Ret
EndF

getSumBigNumDigits Frame pBigNum1, pNumDoubleWords

; convert bigNum1 to decimal value and add digits
; return result in Eax

	Local digitCounter, numDoubleWords

	Mov Edx, [pNumDoubleWords]       	; Edx = address pointed to by pNumDoubleWords
    Mov Eax, [Edx]                  	; Eax = value at that address
	Mov [numDoubleWords], Eax
	Mov Esi, [pBigNum1]					; Esi = pointer to big number

	; initialize
	Mov Ebx, 10   						; divisor
	Mov Eax, 0
	Mov [digitCounter], Eax				; digitCounter = 0

.getSumBigNumDigits_loop4

	Mov Ecx, [numDoubleWords]			; loop counter (number of double words in bigNum1)
 	Mov Edx, 0							; initialize Edx = 0

.getSumBigNumDigits_loop3

 	Mov Eax, [Esi + 4 * Ecx - 4]		; Edx:Eax = number to divide
 	Div Ebx								; Edx holds remainder from division
 	Mov [Esi + 4 * Ecx - 4], Eax
	Loop .getSumBigNumDigits_loop3

	Push Edx							; save one digit
	Inc D[digitCounter]

	; check whether done, i.e. Eax < 10 and all higher double words of bigNum1 = 0
	Cmp Eax, 9
	Ja .getSumBigNumDigits_loop4

	; BEGIN check all higher double words of bigNum1 = 0
	; using Ecx and Edx for this check
	Mov Ecx, [numDoubleWords]			; loop counter (number of double words in bigNum1)
	Sub Ecx, 1							; Ecx = numDoubleWords - 1

	.getSumBigNumDigits_loop_done_check
 	Mov Edx, [Esi + 4 * Ecx]
	Cmp Edx, 0
	Jne .getSumBigNumDigits_loop4		; this DW in bigNum1 <> 0, so need to divide again
	Dec Ecx
		Jnz .getSumBigNumDigits_loop_done_check
	; END check all higher double words of bigNum1 = 0

	; push final digit and increment digitCounter
	Push Eax							; save last digit
	Inc D[digitCounter]

	; pop digits off stack and add
	Mov Eax, 0							; sum = 0
	Mov Ecx, [digitCounter]

.getSumBigNumDigits_loop5
	Pop Ebx
	Add Eax, Ebx
	Loop .getSumBigNumDigits_loop5

	Ret
EndF

getPrimeFactors Frame arrayPointer, primeFactorArray, numberToFactor

 	; Need local versions of candidate, candidateSquareRoot, etc. due to recursion
 	; candidate = numberToFactor
	Local candidate, candidateSquareRoot, primeFlag

	; save numberToFactor as local version (candidate)
	;Mov Eax, [numberToFactor + 4]		; high-order 32 bits
	;Mov [candidate + 4], Eax
	Mov Ebx, [numberToFactor]			; why does this get ADDRESS of numberToFactor???
	Mov Eax, [Ebx]			; low-order 32 bits
	Mov [candidate], Eax

	; Prepare FPU
	Fstcw W[fpu_controlword_1]	;get the current Control Word to retain all setting bits
                 				;not related to the rounding control (RC) bits
	Fwait						;to insure the storage instruction is completed
	Mov Ax, [fpu_controlword_1]
;	And Ax, 0F3FFH 				;clears only the RC bits, leaving all other bits unchanged
								;not necessary here because both bits will be set
	Or Ax, 0C00H  				;this will set both bits of the RC field to the truncating mode
                  				;without affecting any of the other field's bits
    Mov [fpu_controlword_2], Ax	; store the modified Control Word in memory
    Fldcw W[fpu_controlword_2] 	;load the modified Control Word
	; Remember to restore control word at end of routine --> Fldcw W[fpu_controlword_1]

	; Take square root of candidate since we only need to test primes up to sqrt(candidate)
	; Floating point operations: load candidate into ST0, take sqrt, save ST0 back to candidateSquareRoot
	; (DUMB THING YOU DID: used Fist instead of Fistp, I think FPU stack has to be popped or otherwise gets corrupted)
	Fild D[candidate]			; was Q instead of D!!! DUMB MISTAKE
	Fsqrt
	Fistp D[candidateSquareRoot]

	; primeFlag = TRUE
	Mov Edx, TRUE
	Mov [primeFlag], Edx

	; Ecx = loop counter
	Mov Ecx, 0

.primeFactorLoop:

		; load current prime to test, start with 1st value in array (arrayPointer[0] = 2)
		Mov Ebx, [arrayPointer]
		Mov Eax, [Ebx + 4 * Ecx]

		; if current prime > candidateSquareRoot, we're done (candidate is prime)
		Cmp Eax, [candidateSquareRoot]
		Ja >>.primeFactorLoopDone

		Push Ecx					; Ecx holds loop counter but needed here for division

		; Limit not yet reached so test this prime
		; Divide candidate by current prime of interest
		Mov Edx, 0					; clear dividend, high
		Mov Ecx, Eax				; divisor = current prime we are checking
		Mov Eax, [candidate]		; dividend, low
		Div Ecx						; Eax = quotient, Edx = remainder

		Pop Ecx						; Reload loop counter

		; see if candidate/current prime = modulo 0 (--> not prime)
		Cmp Edx, 0
		Jnz >.primeFactorLoopFinalProcessing
			; primeFlag = FALSE
			Mov Edx, FALSE
			Mov [primeFlag], Edx
			Jmp >.primeFactorLoopDone

.primeFactorLoopFinalProcessing:

	; Increment counter and loop back
	Inc Ecx
	Jmp .primeFactorLoop

.primeFactorLoopDone:

	Mov Edx, [primeFlag]
	Cmp Edx, TRUE
	Jnz >.notPrime_2
		; candidate is prime
		Mov Eax, [candidate]
		Mov Ebx, [primeFactorArray]
		Mov [Ebx], Eax
		; PushAD
		;Invoke String, Eax, Addr myStringVar, ecDecimal
		;Invoke MessageBoxA, [hWnd], Addr myStringVar, 'Problem 3: Prime factor', MB_ICONINFORMATION
		;PopAD
		Jmp >.finalProcessing_4

.notPrime_2

	; Eax = quotient --> new value for numberToFactor
	;Mov [numberToFactor], Eax
	Mov Ebx, [numberToFactor]
	Mov [Ebx], Eax

	; Save the prime factor we just discovered (have to reload it)
	Mov Ebx, [arrayPointer]
	Mov Eax, [Ebx + 4 * Ecx]
	Mov Ebx, [primeFactorArray]
	Mov [Ebx], Eax

	; Ebx already holds current primeFactorArray pointer
	; Increment for recursive call
	Add Ebx, 4

	Mov Eax, [numberToFactor]

	; Invoke getPrimeFactors(candidate/primeFactor)
	Invoke getPrimeFactors, Addr knownPrimes, Ebx, Eax

.finalProcessing_4

	; restore original FPU Control Word
    Fldcw W[fpu_controlword_1]

	Ret
EndF
