#ifndef MATH_H
#define MATH_H

/* math.h - C99 standard header */

#define FP_INFINITE   1
#define FP_NAN        2
#define FP_NORMAL     (-1)
#define FP_SUBNORMAL  (-2)
#define FP_ZERO       0

#define FP_ILOGB0    (-0x7fffffff - 1)
#define FP_ILOGBNAN  0x7fffffff

#define MATH_ERRNO        1
#define MATH_ERREXCEPT    2
#define math_errhandling  (MATH_ERRNO|MATH_ERREXCEPT)

#define FP_LT  1
#define FP_EQ  2
#define FP_GT  4

#ifdef MSC_VER
/* values for _exception type */
#define DOMAIN  1
#define SING  2
#define OVERFLOW  3
#define UNDERFLOW  4
#define TLOSS  5
#define PLOSS  6

/* passed to _matherr() when a fp exception is detected */
exception struct
	type dd
	name dd
	arg1 dq
	arg2 dq
	retval dq
ends

#endif /* MSC_VER */

#endif /* MATH_H */

