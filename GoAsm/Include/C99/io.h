#ifndef IO_H
#define IO_H

/* io.h - private header for low-level I/O definitions */

finddata_t struct
	attrib dd
	time_create dd
	time_access dd
	time_write dd
	size dd
	name db 260 dup (?)
ends

/* file attributes for _findfirst() */
#define A_NORMAL   0x00
#define A_RDONLY   0x01
#define A_HIDDEN   0x02
#define A_SYSTEM   0x04
#define A_SUBDIR   0x10
#define A_ARCH     0x20

/* file sharing modes for _sopen() */
#define SH_DENYRW  0x10
#define SH_DENYWR  0x20
#define SH_DENYRD  0x30
#define SH_DENYNO  0x40

/* flags for _open() and _chmod() */
#define S_IREAD    0x100
#define S_IWRITE   0x80

/* locking modes for _locking() */
#define LK_UNLCK   0
#define LK_LOCK    1
#define LK_NBLCK   2
#define LK_RLCK    3
#define LK_NBRLCK  4

#endif /* _IO_H */

