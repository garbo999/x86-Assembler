#ifndef LZEXPAND_H
#define LZEXPAND_H

#define LZEXPAND_H_REQVER 100

#IFDEF LINKFILES
	#dynamiclinkfile Lz32.dll
	#IF WINVER <= NTDDI_WIN9XALL
	#dynamiclinkfile lzexpand.dll
	#ENDIF
#ENDIF

/* Data decompression library definitions */

#define LZERROR_BADINHANDLE  -1
#define LZERROR_BADOUTHANDLE  -2
#define LZERROR_READ  -3
#define LZERROR_WRITE  -4
#define LZERROR_GLOBALLOC  -5
#define LZERROR_GLOBLOCK  -6
#define LZERROR_BADVALUE  -7
#define LZERROR_UNKNOWNALG  -8

#IFDEF UNICODE
	#define GetExpandedName GetExpandedNameW
	#define LZOpenFile LZOpenFileW
#else
	#define GetExpandedName GetExpandedNameA
	#define LZOpenFile LZOpenFileA
#endif

#endif /* _LZEXPAND_H */
