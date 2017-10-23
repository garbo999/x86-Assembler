#include Files.inc

.code

GetFileExists FRAME lpszFileName

	invoke GetFileAttributesA,[lpszFileName]
	inc eax
	ret
ENDF
