#ifndef FENV_H
#define FENV_H

/* fenv.h - C99 standard header; TC1 changes added */

typedef unsigned long fexcept_t;

fenv_t STRUCT
	control DD
	status DD
	reserved DD 5 DUP (?)
ENDS

#define FE_TONEAREST   0x00
#define FE_DOWNWARD    0x01
#define FE_UPWARD      0x02
#define FE_TOWARDZERO  0x03

#define FE_INVALID     0x01
#define FE_DIVBYZERO   0x04
#define FE_OVERFLOW    0x08
#define FE_UNDERFLOW   0x10
#define FE_INEXACT     0x20
#define FE_ALL_EXCEPT  (FE_INVALID|FE_DIVBYZERO|FE_OVERFLOW|FE_UNDERFLOW|FE_INEXACT)

#endif /* _FENV_H */

