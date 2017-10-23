#ifndef STDLIB_H
#define STDLIB_H

/* stdlib.h - C99 standard header */

/* macros */
#ifndef NULL
	#define NULL 0
#endif

#define EXIT_FAILURE  1
#define EXIT_SUCCESS  0

#define MB_CUR_MAX  __mbcurmax
#define RAND_MAX  0x3fffffff

div_t struct
	quot DD
	rem DD
ENDS

ldiv_t struct
	quot DD
	rem DD
ENDS

lldiv_t struct
	quot DQ
	rem DQ
ENDS

#endif /* _STDLIB_H */

