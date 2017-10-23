;EasyCodeName=projectEuler,1
.Const

.Data

.Code

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