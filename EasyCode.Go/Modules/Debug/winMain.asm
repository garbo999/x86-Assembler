.Const

.Data

WINMAIN_MESSAGES	DD WM_CREATE, OnwinMainCreate
					DD WM_CLOSE, OnwinMainClose
					DD WM_COMMAND, OnwinMainClickBtn

; General variables
myStringVar			DB 20 Dup 0
myDD1				DD 0
myDD2				DD 0
intArray		    DD 1111H, 22H, 33H, 44H, 55H, 66H, 77H, 88H, 99H, 0AAH  ; 10 dwords for integers
sqrtTest			DD 100
time1				SYSTEMTIME
time2				SYSTEMTIME
timeFT1				FILETIME
timeFT2				FILETIME
clientTime			DB 30 Dup 0
iterCounter1		DD 0			; used to analyze number of iterations to determine primes
iterCounter2		DD 0
fpu_controlword_1	DB 0
fpu_controlword_2	DB 0
bigNumber2			DQ 0

; EULER problem 1

; EULER problem 2
fib1				DD 1
fib2				DD 2

; EULER problem 3
numberToFactor		DD 0			; defined in routine (64-bit unsigned integer)
primeFactorArray	DD 100 Dup 0	; accumulate results here since stack won't work with recursion

; EULER problem 4
maxPalindrome		DD 0

; EULER problem 6
sumOfSquares		DD 0			;
squareOfSum			DD 0			;

; EULER problem 7
candidate			DD 5			; First candidate to check = 5
primeCount			DD 2			; Two primes already known = 2 and 3
primeFlag			DD TRUE			; Flag for use in detecting primes
knownPrimes			DD 170000 Dup 0F00FH	; Space for array of known primes (size is needed for Problem 10, fill pattern is just for debugging and is not essential)
primeLimit1			DD 10001		; Number of primes to calculate (variable counter)
primeLimit2			DD 160001		; Number of primes to calculate (variable counter)
;primeLimitConstant	DD 10001		; Number of primes to calculate (constant, normally 10001)
candidateDividedByTwo	DD 0		;
candidateSquareRoot		DD 0		;

; EULER problem 8
problem8DataBlock DATABLOCK_BEGIN      ;comment
73167176531330624919225119674426574742355349194934
96983520312774506326239578318016984801869478851843
85861560789112949495459501737958331952853208805511
12540698747158523863050715693290963295227443043557
66896648950445244523161731856403098711121722383113
62229893423380308135336276614282806444486645238749
30358907296290491560440772390713810515859307960866
70172427121883998797908792274921901699720888093776
65727333001053367881220235421809751254540594752243
52584907711670556013604839586446706324415722155397
53697817977846174064955149290862569321978468622482
83972241375657056057490261407972968652414535100474
82166370484403199890008895243450658541227588666881
16427171479924442928230863465674813919123162824586
17866458359124566529476545682848912883142607690042
24219022671055626321111109370544217506941658960408
07198403850962455444362981230987879927244284909188
84580156166097919133875499200524063689912560717606
05886116467109405077541002256983155200055935729725
71636269561882670428252483600823257530420752963450
DATABLOCK_END

problem8MaxProduct				DD 0		; also using this as marker for end of data!

; EULER problem 9
arrayOfSquares 		DD 1000 Dup 0
asq					DD 0			; candidate value of asq
a					DD 0			; candidate value of a ("not squared")

; EULER problem 10
bigNumber	DD 0				; Low-order dword (bigNum is a 64-bit number)
			DD 0				; High-order dword

.Code

winMainProcedure Frame hWnd, uMsg, wParam, lParam
	Mov Eax, [uMsg]
	Mov Ecx, SizeOf WINMAIN_MESSAGES / 8
	Mov Edx, Addr WINMAIN_MESSAGES
:	Dec Ecx
	Js > L2
	Cmp [Edx + Ecx * 8], Eax
	Jne <
	Call [Edx + Ecx * 8 + 4]
	Ret
L2:	Xor Eax, Eax	;Return (FALSE)
	Ret
EndF

OnwinMainCreate: UseData winMainProcedure
	;==================================
	;Write the initialization code here
	;==================================
	Xor Eax, Eax	;Return (FALSE)
	Ret
EndU

OnwinMainClose: UseData winMainProcedure
	;=========================
	;Write the final code here
	;=========================
	Invoke IsModal, [hWnd]
	Or Eax, Eax		;Cmp Eax, FALSE
	Jz >
	Invoke EndModal, [hWnd], IDCANCEL
	Mov Eax, TRUE	;Return (TRUE)
:	Ret
EndU
OnwinMainClickBtn: UseData winMainProcedure

; I used to put a label here, but Easy Code seems to want to modify it

	Mov Eax, [wParam]
	Cmp Ax, IDC_WINMAIN_BTN1		; Is this button 1?
		Jnz >>.chkbtn2

	; This IS button 1 so check for left click
	Shr Eax, 16
	Cmp Ax, BN_CLICKED
		Jnz >>.exitProcedure		; Button 1 but not left click

	; Button 1 AND left click so process
	Invoke MessageBoxA, [hWnd], 'Now calculating answer to problem 1...', 'Project Euler', MB_OK

	; EULER problem 1
	; Initialize variables
	Mov Eax, 0				; Eax = Sum
	Mov Ecx, 999			; Ecx = Loop counter (candidate)

	; Processing loop
.loop_start:

.chkMod3:						; Check whether multiple of 3

	; Save variables before division
	Push Eax
	Push Ecx

	Mov Edx, 0					; Clear dividend, high
	Mov Eax, Ecx				; Dividend, low
	Mov Ecx, 3					; Divisor
	Div Ecx						; Eax = quotient, Edx = remainder

	; Restore variables after division
	Pop Ecx
	Pop Eax

	Cmp Edx, 0					; Edx holds remainder from division
		Jnz >>.chkMod5

	Add Eax, Ecx				; Multiple of 3 so add to sum
	Jmp >>.loopEndProcedure

.chkMod5:

	; Save variables before division
	Push Eax
	Push Ecx

	; Check whether multiple of 5
	Mov Edx, 0					; Clear dividend, high
	Mov Eax, Ecx				; Dividend, low
	Mov Ecx, 5					; Divisor
	Div Ecx						; Eax = quotient, Edx = remainder

	; Restore variables after division
	Pop Ecx
	Pop Eax

	Cmp Edx, 0					; Edx holds remainder from division
		Jnz >>.loopEndProcedure

	Add Eax, Ecx				; Multiple of 5 so add to sum

.loopEndProcedure:

	Loop .loop_start

	; Loop processing done, display result
	Invoke String, Eax, Addr myStringVar, ecDecimal
	Invoke MessageBoxA, [hWnd], Addr myStringVar, 'Project Euler (Problem 1 answer = 233168)', MB_ICONINFORMATION

	Return (TRUE)

; ************************************************************************************
.chkbtn2:						; Previous button not clicked, check button 2

	Cmp Ax, IDC_WINMAIN_BTN2		; Is this button 2?
		Jnz >>.chkbtn14

	; This IS button 2 so check for left click
	Shr Eax, 16
	Cmp Ax, BN_CLICKED
		Jnz >>.exitProcedure

	; Button 2 AND left click so process
	Invoke MessageBoxA, [hWnd], 'Now calculating answer to problem 2...', 'Project Euler', MB_OK

	; EULER problem 2
	; Initialize variables
	Mov Ecx, 2						; Ecx = sum already includes 2
	;Mov Edx, 89					; max value
	Mov Edx, 4000000				; Edx = max value
	Mov Ebx, 2
	Mov [fib1], Ebx
	Mov Ebx, 3
	Mov [fib2], Ebx

	; WHILE loop test
.whileLoop:

	Mov Eax, 0
	Add Eax, [fib1]
	Add Eax, [fib2]

	Cmp Eax, Edx
		Ja >.whileLoopDone

	; Check whether current value is even and if so, add to total
	Test Eax, 1
		Jnz >.notEven
	Add Ecx, Eax

.notEven:

	Push Eax
	Push Ebx
	Push Ecx
	Push Edx

	; Display current loop value
	;Invoke String, Eax, Addr myStringVar, ecDecimal
	;Invoke MessageBoxA, [hWnd], Addr myStringVar, 'WHILE loop test', MB_ICONINFORMATION

	Pop Edx
	Pop Ecx
	Pop Ebx
	Pop Eax

	Mov Ebx, [fib2]
	Mov [fib1], Ebx
	Mov [fib2], Eax

	Jmp .whileLoop

.whileLoopDone:

	; Display answer
	Invoke String, Ecx, Addr myStringVar, ecDecimal
	Invoke MessageBoxA, [hWnd], Addr myStringVar, 'Problem 2 answer = 4613732', MB_ICONINFORMATION

	Return (TRUE)

; ************************************************************************************
.chkbtn14:						; Previous button not clicked, check button 3

	Cmp Ax, IDC_WINMAIN_BTN3		; Is this button 3?
		Jnz >>.chkButton4

	; This IS button 3 so check for left click
	Shr Eax, 16
	Cmp Ax, BN_CLICKED
		Jnz >>.exitProcedure

	; Button 3 AND left click so process
	Invoke MessageBoxA, [hWnd], 'Now calculating answer to problem 7...', 'Project Euler', MB_OK

	; save time1
	Invoke GetSystemTime, Addr time1

	; EULER problem 7
	; Initialize variables
	; Store 2 and 3 in knownPrimes array
	Mov Eax, 2						; first prime = 2
	Mov Ebx, Addr knownPrimes		; Ebx = ptr to knownPrimes[0]
	Mov [Ebx], Eax					; knownPrimes[0] = 2
	Add Ebx, 4						; increment Ebx = ptr to knownPrimes[1]
	Mov Eax, 3						; second prime = 3
	Mov [Ebx], Eax					; knownPrimes[0] = 3

	; Initialise other variables here (in case routine is re-executed)
	; First candidate to check = 5
	Mov Eax, 5
	Mov [candidate], Eax

	; Two primes already known (= 2, 3)
	Mov Eax, 2
	Mov [primeCount], Eax

	; Number of primes to calculate
	; Why not just use primeLimit? Is it modified somewhere? Eliminated in version 3.
	;Mov Eax, [primeLimitConstant]		; normally 10001
	;Mov [primeLimit1], Eax

	; For analysis purposes, count number of iterations in secondary loop
	Mov Eax, 0
	Mov [iterCounter2], Eax

.mainLoopStart:

	; Divide candidate by 2 since we only need to test primes up to candidate / 2
	Mov Edx, 0					; clear dividend, high
	Mov Eax, [candidate]		; dividend, low
	Mov Ecx, 2					; divisor
	Div Ecx						; Eax = quotient, Edx = remainder

	; candidateDividedByTwo = candidate / 2 (divide candidate by 2 and save for comparison)
	Mov [candidateDividedByTwo], Eax

	; primeFlag = TRUE
	Mov Eax, TRUE
	Mov [primeFlag], Eax

	; Ecx = loop counter
	Mov Ecx, 1

	; For analysis purposes, count number of iterations in secondary loop
	Mov Eax, 0
	Mov [iterCounter1], Eax

.secondaryLoop:

		; analysis
		Mov Eax, [iterCounter1]
		Inc Eax
		Mov [iterCounter1], Eax

		; load current prime to test
		Mov Ebx, Addr knownPrimes
		Mov Eax, [Ebx + 4 * Ecx]					; Ebx = 1, Eax = 3

		; if current prime > candidateDividedByTwo, we're done (candidate is prime)
		Cmp Eax, [candidateDividedByTwo]
		Ja >.testDone

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
		Jnz >.secondaryLoopEnd
			; primeFlag = FALSE
			Mov Eax, FALSE
			Mov [primeFlag], Eax
			Jmp >.testDone

.secondaryLoopEnd:

	; Increment counter to check next prime if counter <> primeCount (number of currently known primes)
	Inc Ecx
	Cmp Ecx, [primeCount]
	Jnz .secondaryLoop

.testDone:

	; analysis (add secondary loop counter to main loop counter)
	Mov Eax, [iterCounter1]
	Add Eax, [iterCounter2]
	Mov [iterCounter2], Eax

	; Get primeCount in Ecx
	Mov Ecx, [primeCount]

	; IF primeFlag = TRUE THEN add new prime to array
	Mov Eax, [primeFlag]
	Cmp Eax, TRUE
	Jnz >.mainLoopEnd
		Mov Eax, [candidate]
		Mov Ebx, Addr knownPrimes
		Mov [Ebx + 4 * Ecx], Eax			; save new prime at end of knownPrimes array
		Add Ecx, 1							; primeCount += 1
		Mov [primeCount], Ecx

.mainLoopEnd:

	; candidate += 2 (next odd number)
	Mov Eax, [candidate]
	Add Eax, 2
	Mov [candidate], Eax

	; Compare primeCount and primeLimit1, loop back if primeCount < primeLimit1
	Mov Eax, [primeLimit1]
	Cmp Ecx, Eax
	Jnz .mainLoopStart

.finalProcessing

	; save time2
	Push Ecx
	Invoke GetSystemTime, Addr time2
	Pop Ecx

	; Display final result (nth prime, n = primeCount)
	; Ecx = primeCount
	Mov Ebx, Addr knownPrimes
	Mov Eax, [Ebx + 4 * Ecx - 4]

	Invoke String, Eax, Addr myStringVar, ecDecimal
	Invoke MessageBoxA, [hWnd], Addr myStringVar, 'nth prime (answer = 104743)', MB_ICONINFORMATION

	; process time difference
	Invoke SystemTimeToFileTime, Addr time1, Addr timeFT1
	Invoke SystemTimeToFileTime, Addr time2, Addr timeFT2

	Mov Eax, [timeFT1.dwLowDateTime]
	Mov Ebx, [timeFT2.dwLowDateTime]
	Sub Ebx, Eax		; time difference is x 100 ns (1E-7)

	; Divide result to get ms
	Mov Edx, 0					; clear dividend, high
	Mov Eax, Ebx				; dividend, low
	Mov Ecx, 10000					; divisor
	Div Ecx						; Eax = quotient, Edx = remainder

	Invoke String, Eax, Addr clientTime, ecDecimal
	Invoke MessageBoxA, [hWnd], Addr clientTime, 'time diff in ms', MB_ICONINFORMATION

	; display analysis result
	Mov Eax, [iterCounter2]
	Invoke String, Eax, Addr clientTime, ecDecimal
	Invoke MessageBoxA, [hWnd], Addr clientTime, 'iterations', MB_ICONINFORMATION

	Return (TRUE)

; ************************************************************************************
.chkButton4:						; Previous button not clicked, check button 4

	Cmp Ax, IDC_WINMAIN_BTN4		; Is this button 4?
		Jnz >>.chkButton5

	; This IS button 4 so check for left click
	Shr Eax, 16
	Cmp Ax, BN_CLICKED
		Jnz >>.exitProcedure

	; Button 3 AND left click so process
	;Invoke SetText, [hWnd], "You clicked button 3!!!"
	Invoke MessageBoxA, [hWnd], 'Test area+Bunch of junk here', 'Message box test', MB_ICONINFORMATION

.AAA_breakpoint_7

	; Division of long numbers

	Mov Eax, 0F12345BFH
	Mov [bigNumber2 + 4], Eax
	Mov [bigNumber2], Eax

	Mov Ebx, 177   					; Divisor = 10 (alternative: 177)

	Mov Edx, 0
	Mov Eax, [bigNumber2 + 4]		; Edx:Eax = number to divide = 12345BFD12345BFDh (alternative: F12345BFF12345BFH)
	Div Ebx
	Mov [bigNumber2 + 4], Eax

	Mov Eax, [bigNumber2]
	Div Ebx
	Mov [bigNumber2], Eax			; Edx holds remainder from division
									; Result = 1D20932E8386F99h (alternative: 15CC3A5F73CF1EE)

	Return (TRUE)




	; System time test
	Invoke GetSystemTime, Addr time1
	Mov Eax, [time1.wSecond]
	And Eax, 000FFH						; AND required because time1.wSecond only has 16 bits (WORD)
	Invoke String, Eax, Addr clientTime, ecDecimal
	Invoke MessageBoxA, [hWnd], Addr clientTime, 'system time test', MB_ICONINFORMATION

	Return (TRUE)




	; floating point test
	Mov Eax, 10000
	Mov [sqrtTest], Eax

	; load sqrtTest into ST0, take sqrt, save ST0 back to sqrtTest
	Fild D[sqrtTest]
	Fsqrt
	Fist D[sqrtTest]

	Invoke String, [sqrtTest], Addr myStringVar, ecDecimal
	Invoke MessageBoxA, [hWnd], Addr myStringVar, 'sqrt test', MB_ICONINFORMATION

	Return (TRUE)




	; Test of FOREACH loop
	Mov Ecx, 10
	Mov Ebx, Addr intArray

.forEachLoop:

	Mov Eax, [Ebx + 4 * Ecx - 4]

	Push Eax
	Push Ebx
	Push Ecx
	Push Edx

	Invoke String, Eax, Addr myStringVar, ecHexa
	Invoke MessageBoxA, [hWnd], Addr myStringVar, 'Array test', MB_ICONINFORMATION

	Pop Edx
	Pop Ecx
	Pop Ebx
	Pop Eax

	Loop .forEachLoop

	; Test of displaying a number in message window
	Mov Eax, 0F1234123H
	Invoke String, Eax, Addr myStringVar, ecHexa
	Invoke MessageBoxA, [hWnd], Addr myStringVar, 'Message box test', MB_ICONINFORMATION

	; Try a division with modulo
	Mov Edx, 0					; clear dividend, high
	Mov Eax, 81					; dividend, low
	Mov Ecx, 3H					; divisor
	Div Ecx						; Eax = quotient, Edx = remainder

	; Test moving register value to variable and back
	Mov [myDD1], Eax
	Mov [myDD2], Edx

	Mov Eax, [myDD1]
	Invoke String, Eax, Addr myStringVar, ecHexa
	Invoke MessageBoxA, [hWnd], Addr myStringVar, 'Project Euler + Quotient', MB_ICONINFORMATION

	Mov Edx, [myDD2]
	Cmp Edx, 0
		Jnz >.notModulo3

	Invoke String, Edx, Addr myStringVar, ecHexa
	Invoke MessageBoxA, [hWnd], Addr myStringVar, 'Project Euler + Remainder is Modulo!', MB_YESNO

	; Process return value from message box
	Cmp Ax, IDYES
		Jnz >.notOK

.OK:
	Invoke MessageBoxA, [hWnd], 'You clicked yes!', 'Message box test', MB_OK
	Return (TRUE)

.notOK:
	Invoke MessageBoxA, [hWnd], 'I guess you clicked no!', 'Message box test', MB_OK
	Return (TRUE)

.notModulo3:

	Invoke String, Edx, Addr myStringVar, ecHexa
	Invoke MessageBoxA, [hWnd], Addr myStringVar, 'Project Euler + Remainder is NOT Modulo!', MB_YESNO

	Return (TRUE)

; ************************************************************************************
.chkButton5:						; Previous button not clicked, check button 5

	Cmp Ax, IDC_WINMAIN_BTN5		; Is this button 5?
		Jnz >>.chkButton7

	; This IS button 5 so check for left click
	Shr Eax, 16
	Cmp Ax, BN_CLICKED
		Jnz >>.exitProcedure

	; Button 3 AND left click so process
	Invoke MessageBoxA, [hWnd], 'Now calculating answer to problem 7, version 2', 'Project Euler', MB_OK

	; save time1
	Invoke GetSystemTime, Addr time1

	; EULER problem 7, version 2
	; Initialize variables
	; Store 2 and 3 in knownPrimes array
	Mov Eax, 2						; first prime = 2
	Mov Ebx, Addr knownPrimes		; Ebx = ptr to knownPrimes[0]
	Mov [Ebx], Eax					; knownPrimes[0] = 2
	Add Ebx, 4						; increment Ebx = ptr to knownPrimes[1]
	Mov Eax, 3						; second prime = 3
	Mov [Ebx], Eax					; knownPrimes[0] = 3

	; Initialise other variables here (in case routine is re-executed)
	; First candidate to check = 5
	Mov Eax, 5
	Mov [candidate], Eax

	; Two primes already known (= 2, 3)
	Mov Eax, 2
	Mov [primeCount], Eax

	; Number of primes to calculate
	; Why not just use primeLimit? Is it modified somewhere? Eliminated in version 3.
	;Mov Eax, [primeLimitConstant]		; normally 10001
	;Mov [primeLimit1], Eax

	; Iteration analysis: count number of iterations in secondary loop
	Mov Eax, 0
	Mov [iterCounter2], Eax

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

.mainLoopStart_2:

	; Take square root of candidate since we only need to test primes up to sqrt(candidate)
	; Floating point operations: load candidate into ST0, take sqrt, save ST0 back to candidateSquareRoot
	; (DUMB THING YOU DID: used Fist instead of Fistp, I think stack has to be popped or otherwise gets corrupted)
	Fild D[candidate]
	Fsqrt
	Fistp D[candidateSquareRoot]

	; primeFlag = TRUE
	Mov Eax, TRUE
	Mov [primeFlag], Eax

	; Ecx = loop counter
	Mov Ecx, 1

	; For analysis purposes, count number of iterations in secondary loop
	Mov Eax, 0
	Mov [iterCounter1], Eax

.secondaryLoop_2:

		; Iteration analysis
		Mov Eax, [iterCounter1]
		Inc Eax
		Mov [iterCounter1], Eax

		; load current prime to test
		Mov Ebx, Addr knownPrimes
		Mov Eax, [Ebx + 4 * Ecx]					; Ebx = 1, Eax = 3

		; if current prime > candidateSquareRoot, we're done (candidate is prime)
		Cmp Eax, [candidateSquareRoot]
		Ja >>.testDone_2

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
		Jnz >.secondaryLoopEnd_2
			; primeFlag = FALSE
			Mov Eax, FALSE
			Mov [primeFlag], Eax
			Jmp >.testDone_2

.secondaryLoopEnd_2:

	; Increment counter and loop back
	Inc Ecx
	Jmp .secondaryLoop_2

.testDone_2:

	; Iteration analysis (add secondary loop counter to main loop counter)
	Mov Eax, [iterCounter1]
	Add Eax, [iterCounter2]
	Mov [iterCounter2], Eax

	; Get primeCount in Ecx for final processing
	Mov Ecx, [primeCount]

	; IF primeFlag = TRUE THEN add new prime to array
	Mov Eax, [primeFlag]
	Cmp Eax, TRUE
	Jnz >.mainLoopEnd_2
		Mov Eax, [candidate]
		Mov Ebx, Addr knownPrimes
		Mov [Ebx + 4 * Ecx], Eax			; save new prime at end of knownPrimes array
		Add Ecx, 1							; primeCount += 1
		Mov [primeCount], Ecx

.mainLoopEnd_2:

	; candidate += 2 (next odd number)
	Mov Eax, [candidate]
	Add Eax, 2
	Mov [candidate], Eax

	; Compare primeCount and primeLimit1, loop back if primeCount < primeLimit1
	Mov Eax, [primeLimit1]
	Cmp Ecx, Eax
	Jnz .mainLoopStart_2

.finalProcessing_2

	; save time2
	Push Ecx
	Invoke GetSystemTime, Addr time2
	Pop Ecx

	; Display final result (nth prime, n = primeCount)
	; (Ecx = primeCount)
	Mov Ebx, Addr knownPrimes
	Mov Eax, [Ebx + 4 * Ecx - 4]

	Invoke String, Eax, Addr myStringVar, ecDecimal
	Invoke MessageBoxA, [hWnd], Addr myStringVar, 'version 2: nth prime (answer = 104743)', MB_ICONINFORMATION

	; process time difference
	Invoke SystemTimeToFileTime, Addr time1, Addr timeFT1
	Invoke SystemTimeToFileTime, Addr time2, Addr timeFT2

	Mov Eax, [timeFT1.dwLowDateTime]
	Mov Ebx, [timeFT2.dwLowDateTime]
	Sub Ebx, Eax		; time difference is x 100 ns (1E-7)

	; Divide result to get ms
	Mov Edx, 0					; clear dividend, high
	Mov Eax, Ebx				; dividend, low
	Mov Ecx, 10000					; divisor
	Div Ecx						; Eax = quotient, Edx = remainder

	Invoke String, Eax, Addr clientTime, ecDecimal
	Invoke MessageBoxA, [hWnd], Addr clientTime, 'time diff in ms', MB_ICONINFORMATION

	; display analysis result
	Mov Eax, [iterCounter2]
	Invoke String, Eax, Addr clientTime, ecDecimal
	Invoke MessageBoxA, [hWnd], Addr clientTime, 'iterations', MB_ICONINFORMATION

	; restore original FPU Control Word
    Fldcw W[fpu_controlword_1]

	Return (TRUE)

; ************************************************************************************
.chkButton7:						; Previous button not clicked, check button 7

	Cmp Ax, IDC_WINMAIN_BTN7		; Is this button 7?
		Jnz >>.chkButton8

	; This IS button 7 so check for left click
	Shr Eax, 16
	Cmp Ax, BN_CLICKED
		Jnz >>.exitProcedure

	; Project Euler Problem 3
	; remember the term SANITY CHECK???

	; Set value to test (600851475143 = 8BE589EAC7h)
	Mov Eax, 999999 				; (factors = 3 3 3 7 11 13 37)
	Mov Eax, 10005784 				; (no no no factors = 03H, 1DH, 2FH, 98FH)
	Mov Eax, 10005784 				; (factors = 2, 2, 2, 107, 11689)
	;Mov Eax, 338BH  				; (= 13195d --> factors = 5, 7, 13 and 29)
	;Mov Eax, 8BH					; value to factor = 600851475143d = 8BE589EAC7h
	Mov Eax, 30
	;Mov [numberToFactor + 4], Eax	; high-order 32 bits
	;Mov Eax, 0E589EAC7H
	Mov [numberToFactor], Eax		; low-order 32 bits

.AAA_Breakpoint_5

	; Get array of primes, first define primeLimit2 (need enough primes and big enough array!)
	;Mov Eax, 160001
	;Mov [primeLimit2], Eax			; primeLimit2 = 16001
	Invoke getPrimesArray, Addr knownPrimes, [primeLimit1]

.AAA_Breakpoint_4

	Invoke getPrimeFactors, Addr knownPrimes, Addr primeFactorArray, Addr numberToFactor
	; DUMBASS MISTAKE: forgot the comma after "Invoke getPrimeFactors_v2" and lost a day
	; trying to understand why the address of knownPrimes was not pushed onto stack

	;Invoke String, Eax, Addr myStringVar, ecDecimal
	;Invoke MessageBoxA, [hWnd], Addr myStringVar, 'Problem 3: Eax value', MB_ICONINFORMATION

	Mov Ebx, Addr primeFactorArray
	Mov Eax, [Ebx]

.problem3DisplayLoop

	Push Eax
	Push Ebx

	Invoke String, Eax, Addr myStringVar, ecDecimal
	Invoke MessageBoxA, [hWnd], Addr myStringVar, 'Problem 3: One factor', MB_ICONINFORMATION

	Pop Ebx
	Pop Eax

	Add Ebx, 4
	Mov Eax, [Ebx]
	Cmp Eax, 0
		Jnz .problem3DisplayLoop


.problem3End

	Return (TRUE)

; ************************************************************************************
.chkButton8:						; Previous button not clicked, check button 8

	Cmp Ax, IDC_WINMAIN_BTN8		; Is this button 8?
		Jnz >>.chkButton9

	; This IS button 8 so check for left click
	Shr Eax, 16
	Cmp Ax, BN_CLICKED
		Jnz >>.exitProcedure

	; Project Euler Problem 3 - 64-bit version
	Invoke MessageBoxA, [hWnd], 'Now calculating answer to problem 3, 64-bit...', 'Project Euler', MB_OK	; Project Euler Problem 3
	; remember the term SANITY CHECK???

	; Set value to test (600851475143 = 8BE589EAC7h)
	Mov Eax, 999999 				; (factors = 3 3 3 7 11 13 37)
	Mov Eax, 10005784 				; (no no no factors = 03H, 1DH, 2FH, 98FH)
	Mov Eax, 10005784 				; (factors = 2, 2, 2, 107, 11689)
	;Mov Eax, 338BH  				; (= 13195d --> factors = 5, 7, 13 and 29)
	;Mov Eax, 8BH					; value to factor = 600851475143d = 8BE589EAC7h
	Mov Eax, 30
	;Mov [numberToFactor + 4], Eax	; high-order 32 bits
	;Mov Eax, 0E589EAC7H
	Mov [numberToFactor], Eax		; low-order 32 bits

.problem3b_Breakpoint_5

	; Get array of primes, first define primeLimit2 (need enough primes and big enough array!)
	;Mov Eax, 160001
	;Mov [primeLimit2], Eax			; primeLimit2 = 16001
	Invoke getPrimesArray, Addr knownPrimes, [primeLimit1]

.problem3b_Breakpoint_4

	Invoke getPrimeFactors, Addr knownPrimes, Addr primeFactorArray, Addr numberToFactor
	; DUMBASS MISTAKE: forgot the comma after "Invoke getPrimeFactors_v2" and lost a day
	; trying to understand why the address of knownPrimes was not pushed onto stack

	;Invoke String, Eax, Addr myStringVar, ecDecimal
	;Invoke MessageBoxA, [hWnd], Addr myStringVar, 'Problem 3: Eax value', MB_ICONINFORMATION

	Mov Ebx, Addr primeFactorArray
	Mov Eax, [Ebx]

.problem3b_DisplayLoop

	Push Eax
	Push Ebx

	Invoke String, Eax, Addr myStringVar, ecDecimal
	Invoke MessageBoxA, [hWnd], Addr myStringVar, 'Problem 3: One factor', MB_ICONINFORMATION

	Pop Ebx
	Pop Eax

	Add Ebx, 4
	Mov Eax, [Ebx]
	Cmp Eax, 0
		Jnz .problem3b_DisplayLoop


.problem3b_End

	Return (TRUE)

; ************************************************************************************
.chkButton9:						; Previous button not clicked, check button 9

	Cmp Ax, IDC_WINMAIN_BTN9		; Is this button 9?
		Jnz >>.chkbtn120

	; This IS button 9 so check for left click
	Shr Eax, 16
	Cmp Ax, BN_CLICKED
		Jnz >>.exitProcedure

	; Project Euler Problem 5
	Invoke MessageBoxA, [hWnd], 'Now calculating answer to problem 5...', 'Project Euler', MB_OK

	; Eax = candidate
	Mov Eax, 21

.mainLoopProblem5

	Mov Ecx, 20

	.secondaryLoopProblem5

		Cmp Ecx, 1
		Jz >.foundAnswerProblem5

		Push Eax
		Push Ecx
		
		; Divide candidate by current factor 
		; (dividend = Edx:Eax, divisor = Ecx, quotient = Eax, remainder = Edx)
		Xor Edx, Edx				; 0:Eax = dividend			
		Div Ecx						; Eax = quotient, Edx = remainder
		
		Pop Ecx
		Pop Eax
		
		Cmp Edx, 0
		Jz >.secondaryLoopFinalProcessingProblem5
			Add Eax, 1
			Jmp .mainLoopProblem5
			
	.secondaryLoopFinalProcessingProblem5
	
		Loop .secondaryLoopProblem5
		
.foundAnswerProblem5

	Invoke String, Eax, Addr myStringVar, ecDecimal
	Invoke MessageBoxA, [hWnd], Addr myStringVar, 'Problem 5: Answer (answer = 232792560)', MB_ICONINFORMATION

	Return (TRUE)

; ************************************************************************************
.chkbtn120:						; Previous button not clicked, check button 10

	Cmp Ax, IDC_WINMAIN_BTN10		; Is this button 10?
		Jnz >>.chkbtn121

	; This IS button 10 so check for left click
	Shr Eax, 16
	Cmp Ax, BN_CLICKED
		Jnz >>.exitProcedure

	; Project Euler Problem 5
	Invoke MessageBoxA, [hWnd], 'Now calculating answer to problem 9...', 'Project Euler', MB_OK

	; Build array of integers up to 10E+6 with integral square root (ISR) = csq[i]
	Mov Ecx, 1
	Mov Ebx, Addr arrayOfSquares

	.loop1Problem9

		Mov Eax, Ecx
		Mul Ecx
		Mov [Ebx], Eax
		Add Ebx, 4
		Add Ecx, 1
		Cmp Ecx, 1001
			Jnz .loop1Problem9

	; test and see if value is there
	;Mov Eax, 999
	;Mov Ebx, Addr arrayOfSquares
	;Mov Edx, [Ebx + 4 * Eax]

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



	; Pythagorean triplet
	; csq = asq + bsq
	; asq = csq - bsq

	; Ebx = pointer to arrayOfSquares
	Mov Ebx, Addr arrayOfSquares							; Ebx = pointer to arrayOfSquares

	; i = 999
	Mov Ecx, 999											; Ecx = outer loop counter

	.loop2OuterProblem9

	Mov Edx, 0												; Edx = inner loop counter

		.loop2InnerProblem9

		Mov Eax, [Ebx + 4 * Ecx]							; Eax = csq

		; asq = csq - bsq
		Sub Eax, [Ebx + 4 * Edx]							; Eax = asq
		Jz >>.finalProcessingInnerLoopProblem9
		Jg >.notNegativeProblem9
			; negative number so continue with outer loop
			Loop .loop2OuterProblem9

		.notNegativeProblem9
		; check whether asq has an integer square root
		Mov [asq], Eax										; using asq as temp holder for value
		Fild D[asq]											; since Fild needs to load from memory (?)
		Fsqrt
		Fistp D[asq]
		Mov Eax, [asq]										; Eax = a
		Mov [a], Eax										; copy value to variable a

		Push Ecx
		Push Edx
		Mov Ecx, Eax
		Mul Ecx												; Eax = asq
		Pop Edx
		Pop Ecx

		; Eax now holds asq candidate
		Mov [asq], Eax
		Add Eax, [Ebx + 4 * Edx]								; asq + bsq
		Cmp Eax, [Ebx + 4 * Ecx]
			Jnz >>.finalProcessingInnerLoopProblem9

		.problem9Debug

		; found triplet
		Push Ecx
		Push Edx
		Mov Eax, [asq]											; asq
		; output
		Mov Eax, [Ebx + 4 * Edx]								; bsq
		; output
		Mov Eax, [Ebx + 4 * Ecx]								; csq
		; output
		Pop Edx
		Pop Ecx
	
		;is a + b + c = 1000?
		Mov Eax, [a]
		Add Eax, Ecx
		Add Eax, 1
		Add Eax, Edx
		Add Eax, 1
		Cmp Eax, 1000
			Jnz >.finalProcessingInnerLoopProblem9

			Push Ecx
			Push Edx

			Mov Eax, [a]
			Invoke String, Eax, Addr myStringVar, ecDecimal
			Invoke MessageBoxA, [hWnd], Addr myStringVar, 'Problem 9: Answer 1', MB_ICONINFORMATION

			Pop Edx
			Mov Eax, Edx
			Add Eax, 1
			Invoke String, Eax, Addr myStringVar, ecDecimal
			Invoke MessageBoxA, [hWnd], Addr myStringVar, 'Problem 9: Answer 2', MB_ICONINFORMATION

			Pop Ecx
			Mov Eax, Ecx
			Add Eax, 1
			Invoke String, Eax, Addr myStringVar, ecDecimal
			Invoke MessageBoxA, [hWnd], Addr myStringVar, 'Problem 9: Answer 3', MB_ICONINFORMATION

			; End here or crash hard!
			Return (TRUE)
		
		.finalProcessingInnerLoopProblem9
		Add Edx, 1
		Cmp Edx, 1000
			Jnz .loop2InnerProblem9

		.finalProcessingOuterLoopProblem9
		;Loop .loop2OuterProblem9			; doesn't accept long jump
		Sub Ecx, 1
		Jmp <<.loop2OuterProblem9

	; restore original FPU Control Word
    Fldcw W[fpu_controlword_1]

	Return (TRUE)

; ************************************************************************************
.chkbtn121:						; Previous button not clicked, check button 11

	Cmp Ax, IDC_WINMAIN_BTN11		; Is this button 11?
		Jnz >>.chkbtn122

	; This IS button 11 so check for left click
	Shr Eax, 16
	Cmp Ax, BN_CLICKED
		Jnz >>.exitProcedure

	; Project Euler Problem 5
	Invoke MessageBoxA, [hWnd], 'Now calculating answer to problem 6...', 'Project Euler', MB_OK

	; Initialize
	Mov Eax, 0
	Mov [sumOfSquares], Eax
	Mov [squareOfSum], Eax

	Mov Ecx, 100						; loop counter

	.loopProblem6

		; sumOfSquares += i*i
		Mov Eax, Ecx			; multiplicand in Eax
		Mul Ecx					; Ecx * Eax = Edx:Eax
		Cmp Edx, 0
		Jz >.noOverflow
			Invoke MessageBoxA, [hWnd], 'Overflow error in problem 6...', 'Project Euler', MB_OK

		.noOverflow
		Add [sumOfSquares], Eax

		; squareOfSum += i
		Add [squareOfSum], Ecx
		
		Loop .loopProblem6

	; squareOfSum = squareOfSum * squareOfSum
	Mov Eax, [squareOfSum]
	Mov Ecx, [squareOfSum]
	Mul Ecx
	Mov [squareOfSum], Eax

	; diff = squareOfSum - sumOfSquares
	Sub Eax, [sumOfSquares]

	Invoke String, Eax, Addr myStringVar, ecDecimal
	Invoke MessageBoxA, [hWnd], Addr myStringVar, 'Problem 6: Answer (answer = xxx)', MB_ICONINFORMATION

	Return (TRUE)

; ************************************************************************************
.chkbtn122:						; Previous button not clicked, check button 12

	Cmp Ax, IDC_WINMAIN_BTN12		; Is this button 12?
		Jnz >>.chkbtn123

	; This IS button 12 so check for left click
	Shr Eax, 16
	Cmp Ax, BN_CLICKED
		Jnz >>.exitProcedure

	; Project Euler Problem 5
	Invoke MessageBoxA, [hWnd], 'Now calculating answer to problem 8...', 'Project Euler', MB_OK

	Mov Ebx, Addr problem8DataBlock		; Ebx = pointer to start of problem8DataBlock

	.problem8OuterLoop

		.getFirstDigit
		Movzx Eax, B[Ebx]					; Eax = running product

		Cmp Al, 30H							; check if byte < 30H
		Jae >.greater30H_2
			Add Ebx, 1						; Increment Ebx pointer and skip irrelevant byte
			Jmp .getFirstDigit

		.greater30H_2
		Cmp Al, 39H							; check if byte > 39H
		Jbe >.isDigit_2
			Add Ebx, 1						; Increment Ebx pointer and skip irrelevant byte
			Jmp .getFirstDigit

		.isDigit_2
		Sub Al, 30H							; convert ASCII to integer

		Mov Esi, Ebx
		Add Esi, 1							; Esi now points to next byte to examine (2 of 5)

		Mov Ecx, 4							; Ecx = inner loop counter (multiply by next 4 numerical digits)

		.problem8InnerLoop

			Movzx Edx, B[Esi]					; Edx = next multiplicand

			; we want to skip any characters except "0", "1", "2", ..., "9"
			Cmp Dl, 30H
			Jae >.greater30H
				Add Esi, 1					; Increment Esi pointer and skip irrelevant byte
				Jmp .problem8InnerLoop

			.greater30H
			Cmp Dl, 39H
			Jbe >.isDigit
				Add Esi, 1					; Increment Esi pointer and skip irrelevant byte
				Jmp .problem8InnerLoop

			.isDigit
			Sub Dl, 30H
			Mul Edx							; Eax = Eax * Edx
			Add Esi, 1						; Increment Esi pointer
			Loop .problem8InnerLoop			; End of inner loop

		; see if current product of 5 numbers is > existing greatest product
		Cmp Eax, [problem8MaxProduct]
		Jbe >.notBigger
			Mov [problem8MaxProduct], Eax

		.notBigger
		Add Ebx, 1
		Cmp Ebx, Addr problem8MaxProduct - 4	; problem8MaxProduct is defined as next byte after data block
		Jb .problem8OuterLoop					; unsigned comparison (= Jl)

	Mov Eax, [problem8MaxProduct]
	Invoke String, Eax, Addr myStringVar, ecDecimal
	Invoke MessageBoxA, [hWnd], Addr myStringVar, 'Problem 8 answer', MB_ICONINFORMATION

	Return (TRUE)


; ************************************************************************************
.chkbtn123:						; Previous button not clicked, check button 13

	Cmp Ax, IDC_WINMAIN_BTN13		; Is this button 13?
		Jnz >>.chkbtn124

	; This IS button 13 so check for left click
	Shr Eax, 16
	Cmp Ax, BN_CLICKED
		Jnz >>.exitProcedure

	; Project Euler Problem 5
	Invoke MessageBoxA, [hWnd], 'Now calculating answer to problem 4...', 'Project Euler', MB_OK

	; Generate all products of a x b where a = 100 to 999 and b = 100 to 999 (a = 10 to 99 and b = 10 to 99)

	Mov Esi, 100						; counter 1

	.problem4OuterLoop

		Mov Edi, 100					; counter 2

		.problem4InnerLoop

			Mov Eax, Esi
			Mov Ecx, Edi
			Mul Ecx

			Mov Edx, Eax			; save copy of number in Edx

			; value to examine now in Eax = counter 1 x counter 2
			Invoke String, Eax, Addr myStringVar, ecDecimal

			Cmp Eax, 6
			Jnz >.not4DigitNumberOrPalindromeOrGreater

				.problem4Breakpoint1

				Movzx Eax, B[myStringVar]
				Movzx Ebx, B[myStringVar + 5]
				Cmp Eax, Ebx
				Jnz >.not4DigitNumberOrPalindromeOrGreater

					Movzx Eax, B[myStringVar + 1]
					Movzx Ebx, B[myStringVar + 4]
					Cmp Eax, Ebx
					Jnz >.not4DigitNumberOrPalindromeOrGreater

						Movzx Eax, B[myStringVar + 2]
						Movzx Ebx, B[myStringVar + 3]
						Cmp Eax, Ebx
						Jnz >.not4DigitNumberOrPalindromeOrGreater

							; we have found palindrome
							Cmp Edx, [maxPalindrome]
							Jb >.not4DigitNumberOrPalindromeOrGreater
								Mov [maxPalindrome], Edx

								.problem4Breakpoint2

			.not4DigitNumberOrPalindromeOrGreater
			Add Edi, 1
			Cmp Edi, 1000
			Jb .problem4InnerLoop
			
		; end of problem4InnerLoop

		Add Esi, 1
		Cmp Esi, 1000
		Jb .problem4OuterLoop

	; end of problem4OuterLoop

	Mov Eax, [maxPalindrome]

	Invoke String, Eax, Addr myStringVar, ecDecimal
	Invoke MessageBoxA, [hWnd], Addr myStringVar, 'Problem 4 answer', MB_ICONINFORMATION

	Return (TRUE)

; ************************************************************************************
.chkbtn124:						; Previous button not clicked, check button 14

	Cmp Ax, IDC_WINMAIN_BTN14		; Is this button 14?
		Jnz >>.chkButton6

	; This IS button 14 so check for left click
	Shr Eax, 16
	Cmp Ax, BN_CLICKED
		Jnz >>.exitProcedure

	; Project Euler Problem 5
	Invoke MessageBoxA, [hWnd], 'Now calculating answer to problem xxx...', 'Project Euler', MB_OK

	Return (TRUE)

; ************************************************************************************
.chkButton6:						; Previous button not clicked, check button 6

	Cmp Ax, IDC_WINMAIN_BTN6		; Is this button 6?
		Jnz >>.exitProcedure

	; This IS button 6 so check for left click
	Shr Eax, 16
	Cmp Ax, BN_CLICKED
		Jnz >>.exitProcedure

.AAA_Breakpoint_2

	; Get array of primes, first define primeLimit2 (need enough primes and big enough array!)
	;Mov Eax, 160001
	;Mov [primeLimit2], Eax			; primeLimit2 = 16001

	Invoke getPrimesArray, Addr knownPrimes, [primeLimit2]

	; Display final result (nth prime, n = primeCount)
	; (Ecx = primeCount)
	Mov Ebx, Addr knownPrimes
	Mov Ecx, [primeLimit2]
	Mov Eax, [Ebx + 4 * Ecx - 4]

	Invoke String, Eax, Addr myStringVar, ecDecimal
	Invoke MessageBoxA, [hWnd], Addr myStringVar, 'version 3: nth prime (answer = xxx)', MB_ICONINFORMATION

	Mov Ebx, Addr knownPrimes
	Mov Ecx, 0						; loop counter
	Mov [bigNumber], Ecx			; initialize bigNumber, low order to 0
	Mov [bigNumber + 4], Ecx		; initialize bigNumber, high order to 0

.forLoopProblem10

	Mov Eax, [Ebx + 4 * Ecx]		; Eax = knownPrimes[i]
	Cmp Eax, 2000000
	Ja >.doneProblem10
		Add D[bigNumber], Eax
 		Adc D[bigNumber + 4], 0
		;Jc >.overflowHandler
		Add Ecx, 1
		Jmp .forLoopProblem10

.doneProblem10

	Invoke String, [bigNumber + 4], Addr myStringVar, ecHexa
	Invoke MessageBoxA, [hWnd], Addr myStringVar, 'Problem 10 high-order result (answer = 21H)', MB_ICONINFORMATION
	Invoke String, [bigNumber], Addr myStringVar, ecHexa
	Invoke MessageBoxA, [hWnd], Addr myStringVar, 'Problem 10 low-order result (answer = 4653F83AH)', MB_ICONINFORMATION

	Return (TRUE)

; ************************************************************************************
.exitProcedure:					; None of checked buttons were clicked

	Return (FALSE)

; End OnwinMainClickBtn
EndU
getPrimeFactors_v2 Frame arrayPointer, primeFactorArray, numberToFactor

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

	; Invoke getPrimeFactors_v2(candidate/primeFactor)
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

winMainbtn1 Frame hWnd, uMsg, wParam, lParam
	Xor Eax, Eax	;Return (FALSE)
	Ret
EndF

winMainbtn2 Frame hWnd, uMsg, wParam, lParam
	Xor Eax, Eax	;Return (FALSE)
	Ret
EndF

winMainbtn4 Frame hWnd, uMsg, wParam, lParam
	Xor Eax, Eax	;Return (FALSE)
	Ret
EndF

winMainbtn3 Frame hWnd, uMsg, wParam, lParam
	Xor Eax, Eax	;Return (FALSE)
	Ret
EndF

winMainbtn5 Frame hWnd, uMsg, wParam, lParam
	Xor Eax, Eax	;Return (FALSE)
	Ret
EndF

winMainbtn6 Frame hWnd, uMsg, wParam, lParam
	Xor Eax, Eax	;Return (FALSE)
	Ret
EndF

winMainbtn7 Frame hWnd, uMsg, wParam, lParam
	Xor Eax, Eax	;Return (FALSE)
	Ret
EndF

winMainbtn8 Frame hWnd, uMsg, wParam, lParam
	Xor Eax, Eax	;Return (FALSE)
	Ret
EndF

winMainbtn9 Frame hWnd, uMsg, wParam, lParam
	Xor Eax, Eax	;Return (FALSE)
	Ret
EndF

winMainbtn11 Frame hWnd, uMsg, wParam, lParam
	Xor Eax, Eax	;Return (FALSE)
	Ret
EndF

winMainbtn10 Frame hWnd, uMsg, wParam, lParam
	Xor Eax, Eax	;Return (FALSE)
	Ret
EndF

winMainbtn12 Frame hWnd, uMsg, wParam, lParam
	Xor Eax, Eax	;Return (FALSE)
	Ret
EndF

winMainbtn13 Frame hWnd, uMsg, wParam, lParam
	Xor Eax, Eax	;Return (FALSE)
	Ret
EndF

winMainbtn14 Frame hWnd, uMsg, wParam, lParam
	Xor Eax, Eax	;Return (FALSE)
	Ret
EndF
