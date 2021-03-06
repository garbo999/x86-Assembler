/*

All functions preserve EDI ESI and EBX
All other registers may be changed

String array functions:

CreateArray:
	Creates a string array
	Parameters:
		MaxIndex = the number of elements in the array
	Returns the base address of the array

GetTopIndex:
	Retrieves the current top index of the array
	Parameters:
		pArray = Base address of array
	Returns the highest index assigned using AddString

AddString:
	Adds a string to the end of the array
	Parameters:
		pArray = Base address of array
		pString = Pointer to the string to add
	Returns the index of the new string

GetString:
	Retrieves a string from the array
	Parameters:
		pArray = Base address of array
		iString = 1 based index of the string to retrieve
	Returns a pointer to the string, 0 if not found

ReplaceString:
	Replaces a string in the array
	Parameters:
		pArray = Base address of array
		iString = 1 based index of the string to replace
		pString = Pointer to the new string
	Returns the index of the new string

FindEmptyIndex:
	Finds the first empty index in the array
	Parameters:
		pArray = Base address of array
		InitialIndex = 1 based index at which to start the search
	Returns the first empty index

FindString:
	Finds the given string in the array
	Parameters:
		pArray = Base address of array
		pString = Pointer to the string to find
		fMatchCase = TRUE = Case sensitive, FALSE = Case insensitive
	Returns the index of the first occurance of the string in the array, -1 = not found

EnumArray:
	Enumerates all items in the array
	Parameters:
		pArray = Base address of array
		pCallBack = Pointer to a callback function.
		Format of callback
			EnumArrayProc FRAME pArray,iString,pString
				pArray = Pointer to the base address of the array
				iString = Index of the string being enumerated
				pString = Pointer to the string being enumerated
	No return value

DeleteString:
	Removes a string from the array
	Parameters:
		pArray = Base address of array
		iString = 1 based index of the string to delete
	Returns 0 if successful

DestroyArray:
	Destroys the array and frees all memory associated with it
	Parameters:
		pArray = Base address of array
	No return value

ExpandArray:
	Resizes the array, (grows only) 
	Parameters:
		pArray = Base address of array
		MaxIndex = New number of elements in the array
	Returns the address of the new array, 0 if there was an error

SortArray:
	Sorts the array alphabetically (uses QuickSort)
	Parameters:
		pArray = Base address of array
		fAscend = TRUE = ascending, FALSE = Descending
		fMatchCase = TRUE = Case Sensitive, FALSE = Case insensitive
	No return value

String manipulation functions:

lszLen/lszLenW:
	Calculates the length of a string
	Parameters:
		pString = Pointer to a null terminated string
	Returns the length of the supplied string not including the NULL terminator

lszPos/lszPosW:
	Finds a character in a string
	Parameters:
		pString = Pointer to a null terminated string
		SearchChar = Value of character to find (this is not a pointer)
		StartChar = 0 based offset to begin the search
	Returns the 1 based position of the first instance of the character in the string 

lszCmp/lszCmpW:
	Performs a case sensitive comparison of two strings
	Parameters:
		pString1 = Pointer to a null terminated string
		pString2 = Pointer to a null terminated string
	Returns 0 if the strings are equal
	Returns -1 if string 1 is lexically less than string 2
	Returns 1 if string 2 is lexically less than string 1

lszCmpi/lszCmpiW:
	Performs a case insensitive comparison of two strings
	Parameters:
		pString1 = Pointer to a null terminated string
		pString2 = Pointer to a null terminated string
	Returns 0 if the strings are equal

lszCopyn/lszCopynW:
	Copies n bytes from one buffer to another
	Parameters:
		lpDest = Pointer to destination buffer
		lpSource = Pointer to source string
		Len = Number of bytes to copy
	Returns the address of the destination buffer
	Will not copy past the end of the lpSource string

lszCopy/lszCopyW:
	Copies a zero terminated string
	Parameters:
		Dest = Pointer to destination buffer
		Source = Pointer to source string
	Returns the address of the destination buffer

lszInstr/lszInstrW:
	Finds an instance of one string in another beginning at a supplied point
	Parameters:
		pString = Pointer to a null terminated string to search
		pFind = Pointer to a null terminated string to find
		StartChar = 0 based index of the character at which to begin the search
	Returns the 0 based index where the string was found, -1 if not found

lszCat/lszCatW:
	Performs a concatenation of two strings
	Parameters:
		lpDest = Pointer to a null terminated string
		lpAdd = Pointer to a null terminated string to append
	Returns the address of the destination buffer

lszCase/lszCaseW:
	Converts a string to upper case or lowercase
	Parameters:
		pString = String to convert
		fCase = TRUE = Upper case, FALSE = Lower case
	Returns the pointer to the buffer

lszTrimLeft/lszTrimLeftW:
	Trims spaces and tabs from the left side a string up to the first
	non-white space character
	Parameters:
		pString = String to trim
	No return value

lszToken/lszTokenW:
	Parses a string for tokens
	Parameters:
		pString = Pointer to a string to parse, pass NULL for subsequent calls
		pToken = Pointer to a single character token

		Pass the address of the string the first time it's call
		or when you want to reset it, in subsequent calls pass
		NULL for the address.
		This function destroys the original string
	Returns the address of the string terminated at the next token

lszSubst/lszSubstW:
	Substitutes characters in a string
	(Note uses MMX register 0. Register is preserved)
	Parameters:
		pString = Pointer to a string to parse, pass NULL for subsequent calls
		pReplace = Pointer to an array of replacement characters
			format for pReplace:
				"char,Susbtwith,char,Susbtwith,...",0,0 (double null termination)
				example "aAbBcC",0,0
	No return value

lszCut/lszCutW:
	Deletes a portion of a string
	Parameters:
		pString = Pointer to a string
		StartChar = 0 based character at which to start the cut
		nLen = Number of characters to remove
	Returns pString

lszInsert/lszInsertW:
	Inserts one string in another
	Parameters:
		pOutput = Pointer to an output string
		pString = Pointer to a string to insert into
		pInsert = Pointer to a string to insert
		nPos = 0 based position to insert
	Returns a pointer to the modified string

lszReverse/lszReverseW:
	Reverses the order of a string
	Parameters:
		lpString = Pointer to a NULL terminated string
	No return value

ANSI only functions

lszTrim:
	Trims extra spaces and tabs from a string (replaces tabs with space)
	Parameters:
		pString = String to trim
	No return value

lszSoundEx:
	Creates a modified SoundEx key and places it in EAX on exit. The SoundEx
	generated allows duplicates that are separated by vowels unlike the more
	standard SoundEx. This can be used to find words that sound alike
	Parameters:
		pString = String to parse (MAX = 1024 characters including NULL terminator)
	Returns a SoundEx key

lszCatPlus:
	Performs a formatted multiple concatentation
	This is a C calling convention function, the caller is responsible for the stack
	ECX is guaranteed to be preserved for counting loops
	Parameters:
		buffer = Pointer to a buffer to hold the resulting string
		szFmt = Pointer to a format string that controls that concatenation
		arg0..arg9 = Pointers to null term. strings or dwords, index of arg matches the format

		The buffer must be large enough to hold the entire string.

		szFmt has the following format:
			where # is the 0 based parameter for that position
			ie %[type]0 = arg0, %[type]1 = arg1 etc...
			You can repeat parameters ie "%u0 %x1 %x1 %s2"
			Or put them out of order "%s2 %u0 %i3 %x1"

			Types:
			%s# = Inserts a string pointed to by argument
			%i# = Converts argument to a signed integer (i must be lower case)
			%u# = Converts argument to an unsigned integer (u must be lower case)
			%x# = Converts argument to a hex string (x must be lower case)

		It is then followed by up to 10 arguments (0-9)
		For a % sign use %%
		Strings arguments are limited to a maximum of 1023 bytes
		Returns the pointer to the buffer

Other functions

dwMemCopy
	Fast copy of medium size blocks of data using DWORDs
	Parameters:
		pDest = Pointer to the destination buffer
		pSource = Pointer to the source buffer
		cbLen = Number of bytes to copy

MemCopyMMX
	Fast copy of large blocks of data using the MMX registers (not preserved)
	Parameters:
		pDest = Pointer to the destination buffer
		pSource = Pointer to the source buffer
		cbLen = Number of bytes to copy
	This function copies memory in 64 byte blocks. The source and destination
	should be aligned and the total size must be a multiple of 64.

lszLenMMX/lszLenMMXW
	NOTE: These functions require a Pentium 3 or better with SSE instructions
	Calculates the length of a string, the string should be aligned.
	lszLenMMXW is a Unicode variant.
	Parameters:
		pString = Pointer to a null terminated string
	Returns the length of the supplied string not including the NULL terminator

lszCopyMMX
	NOTE: This function requires a Pentium 3 or better with SSE instructions
	Copies a zero terminated string using the MMX registers (not preserved)
	Parameters:
		Dest = Pointer to destination buffer
		Source = Pointer to source string
	Returns the address of the destination buffer

AddString				PROTO	:DWORD,:DWORD
Compare					PROTO	:DWORD,:DWORD,:DWORD,:DWORD
CreateArray				PROTO	:DWORD
DeleteString			PROTO	:DWORD,:DWORD
DestroyArray			PROTO	:DWORD
EnumArray				PROTO	:DWORD,:DWORD
ExpandArray				PROTO	:DWORD,:DWORD
FindEmptyIndex			PROTO	:DWORD,:DWORD
FindString				PROTO	:DWORD,:DWORD,:DWORD
GetString				PROTO	:DWORD,:DWORD
GetTopIndex				PROTO	:DWORD
ReplaceString			PROTO	:DWORD,:DWORD,:DWORD

lszCase					PROTO	:DWORD,:DWORD
lszCaseW				PROTO	:DWORD,:DWORD
lszCat					PROTO	:DWORD,:DWORD
lszCatW					PROTO	:DWORD,:DWORD
lszCmp					PROTO	:DWORD,:DWORD
lszCmpW					PROTO	:DWORD,:DWORD
lszCmpi					PROTO	:DWORD,:DWORD
lszCmpiW				PROTO	:DWORD,:DWORD
lszCopy					PROTO	:DWORD,:DWORD
lszCopyW				PROTO	:DWORD,:DWORD
lszCopyn				PROTO	:DWORD,:DWORD,:DWORD
lszCopynW				PROTO	:DWORD,:DWORD,:DWORD
lszCut					PROTO	:DWORD,:DWORD,:DWORD
lszCutW					PROTO	:DWORD,:DWORD,:DWORD
lszInsert				PROTO	:DWORD,:DWORD,:DWORD,:DWORD
lszInsertW				PROTO	:DWORD,:DWORD,:DWORD,:DWORD
lszInstr				PROTO	:DWORD,:DWORD,:DWORD
lszInstrW				PROTO	:DWORD,:DWORD,:DWORD
lszLen					PROTO	:DWORD
lszLenW					PROTO	:DWORD
lszPos					PROTO	:DWORD,:DWORD,:DWORD
lszPosW					PROTO	:DWORD,:DWORD,:DWORD
lszReverse				PROTO	:DWORD
lszReverseW				PROTO	:DWORD
lszSubst				PROTO	:DWORD,:DWORD
lszSubstW				PROTO	:DWORD,:DWORD
lszToken				PROTO	:DWORD,:DWORD
lszTokenW				PROTO	:DWORD,:DWORD

lszTrim					PROTO	:DWORD
lszSoundEx				PROTO	:DWORD
lszCatPlus equ <lszCatPlus@0>
lszCatPlus				PROTO C :VARARG

lszCopyMMX				PROTO	:DWORD,:DWORD
lszLenMMX				PROTO	:DWORD
lszLenMMXW				PROTO	:DWORD
dwMemCopy				PROTO	:DWORD,:DWORD,:DWORD
MemCopyMMX				PROTO	:DWORD,:DWORD,:DWORD
*/

VERSIONINFO struct
	dwMajorVersion DD ?
	dwMinorVersion	DD ?
	dwBuildNumber DD ?
ENDS

.data
; DO NOT MODIFY
_StringLibName db "No Name String library",0
_StringLibInfo	VERSIONINFO <0,1,1>
