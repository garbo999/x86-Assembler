#ifndef _STDIO_H
#define _STDIO_H

/* stdio.h - C99 standard header */

#ifndef NULL
#define NULL 0
#endif

#define IOFBF  0
#define IOLBF  1
#define IONBF  2

#define BUFSIZ  512
#define EOF  (-1)

#define FOPEN_MAX  256 /*16*/
#define FILENAME_MAX  260

#define L_tmpnam  16
#define TMP_MAX  32

#define SEEK_SET  0
#define SEEK_CUR  1
#define SEEK_END  2

#ifndef MBSTATE_T_DEFINED
#define MBSTATE_T_DEFINED
mbstate_t STRUCT
	wchar DD
	rsrv DW
	state DW
ENDS
#endif

FILE STRUCT
	mode DW
	fh DD
	buf DD
	bufend DD
	ptr DD
	getend DD
	putend DD
	backptr DD
	wbackptr DD
	wbackbuf DW 2 DUP (?)
	getback DD
	wgetend DD
	wputend DD
	wstate mbstate_t <>
	tmpnam DD
	backbuf DB 8 DUP (?)
	cbuf DB
ENDS

fpos_t STRUCT
	off DD  /* system dependent */
	wstate mbstate_t <>
ENDS

#endif /* _STDIO_H */

