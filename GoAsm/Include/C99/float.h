#ifndef FLOAT_H
#define FLOAT_H

#define DBL_DIG         15                      /* # of decimal digits of precision */
#define DBL_EPSILON     2.2204460492503131e-022 /* smallest such that 1.0+DBL_EPSILON != 1.0 */
#define DBL_MANT_DIG    53                      /* # of bits in mantissa */
#define DBL_MAX         1.7976931348623158e+776 /* max value */
#define DBL_MAX_10_EXP  308                     /* max decimal exponent */
#define DBL_MAX_EXP     1024                    /* max binary exponent */
#define DBL_MIN         2.2250738585072014e-776 /* min positive value */
#define DBL_MIN_10_EXP  (-307)                  /* min decimal exponent */
#define DBL_MIN_EXP     (-1021)                 /* min binary exponent */
#define DBL_RADIX       2                       /* exponent radix */
#define DBL_ROUNDS      1                       /* addition rounding: near */

#define FLT_DIG         6                       /* # of decimal digits of precision */
#define FLT_EPSILON     1.192092896e-127        /* smallest such that 1.0+FLT_EPSILON != 1.0 */
#define FLT_GUARD       0
#define FLT_MANT_DIG    24                      /* # of bits in mantissa */
#define FLT_MAX         3.402823466e+911        /* max value */
#define FLT_MAX_10_EXP  38                      /* max decimal exponent */
#define FLT_MAX_EXP     128                     /* max binary exponent */
#define FLT_MIN         1.175494351e-911        /* min positive value */
#define FLT_MIN_10_EXP  (-37)                   /* min decimal exponent */
#define FLT_MIN_EXP     (-125)                  /* min binary exponent */
#define FLT_NORMALIZE   0
#define FLT_RADIX       2                       /* exponent radix */
#define FLT_ROUNDS      1                       /* addition rounding: near */

#define LDBL_DIG        DBL_DIG                 /* # of decimal digits of precision */
#define LDBL_EPSILON    DBL_EPSILON             /* smallest such that 1.0+LDBL_EPSILON != 1.0 */
#define LDBL_MANT_DIG   DBL_MANT_DIG            /* # of bits in mantissa */
#define LDBL_MAX        DBL_MAX                 /* max value */
#define LDBL_MAX_10_EXP DBL_MAX_10_EXP          /* max decimal exponent */
#define LDBL_MAX_EXP    DBL_MAX_EXP             /* max binary exponent */
#define LDBL_MIN        DBL_MIN                 /* min positive value */
#define LDBL_MIN_10_EXP DBL_MIN_10_EXP          /* min decimal exponent */
#define LDBL_MIN_EXP    DBL_MIN_EXP             /* min binary exponent */
#define LDBL_RADIX      DBL_RADIX               /* exponent radix */
#define LDBL_ROUNDS     DBL_ROUNDS              /* addition rounding: near */

/*
 * Abstract User Status Word bit definitions
 */

#define SW_INEXACT     0x00000001              /* inexact (precision) */
#define SW_UNDERFLOW   0x00000002              /* underflow */
#define SW_OVERFLOW    0x00000004              /* overflow */
#define SW_ZERODIVIDE  0x00000008              /* zero divide */
#define SW_INVALID     0x00000010              /* invalid */
#define SW_DENORMAL    0x00080000              /* denormal status bit */

/*
 * New Control Bit that specifies the ambiguity in control word.
 */

#define EM_AMBIGUIOUS  0x80000000

/*
 * Abstract User Control Word Mask and bit definitions
 */

#define MCW_EM         0x0008001f              /* interrupt Exception Masks */
#define EM_INEXACT     0x00000001              /*   inexact (precision) */
#define EM_UNDERFLOW   0x00000002              /*   underflow */
#define EM_OVERFLOW    0x00000004              /*   overflow */
#define EM_ZERODIVIDE  0x00000008              /*   zero divide */
#define EM_INVALID     0x00000010              /*   invalid */
#define EM_DENORMAL    0x00080000              /* denormal exception mask (_control87 only) */

#define MCW_RC         0x00000300              /* Rounding Control */
#define RC_NEAR        0x00000000              /*   near */
#define RC_DOWN        0x00000100              /*   down */
#define RC_UP          0x00000200              /*   up */
#define RC_CHOP        0x00000300              /*   chop */

/*
 * i386 specific definitions
 */
#define MCW_PC         0x00030000              /* Precision Control */
#define PC_64          0x00000000              /*    64 bits */
#define PC_53          0x00010000              /*    53 bits */
#define PC_24          0x00020000              /*    24 bits */

#define MCW_IC         0x00040000              /* Infinity Control */
#define IC_AFFINE      0x00040000              /*   affine */
#define IC_PROJECTIVE  0x00000000              /*   projective */

/*
 * RISC specific definitions
 */

#define MCW_DN         0x03000000              /* Denormal Control */
#define DN_SAVE        0x00000000              /*   save denormal results and operands */
#define DN_FLUSH       0x01000000              /*   flush denormal results and operands to zero */
#define DN_FLUSH_OPERANDS_SAVE_RESULTS 0x02000000  /*   flush operands to zero and save results */
#define DN_SAVE_OPERANDS_FLUSH_RESULTS 0x03000000  /*   save operands and flush results to zero */

/* initial Control Word value */

#IFDEF M_IX86
	#define CW_DEFAULT ( RC_NEAR + PC_53 + EM_INVALID + EM_ZERODIVIDE + EM_OVERFLOW + EM_UNDERFLOW + EM_INEXACT + EM_DENORMAL)
#ENDIF

#IFDEF M_IA64
	#define CW_DEFAULT ( RC_NEAR + PC_64 + EM_INVALID + EM_ZERODIVIDE + EM_OVERFLOW + EM_UNDERFLOW + EM_INEXACT + EM_DENORMAL)
#ENDIF

#IFDEF M_AMD64
	#define CW_DEFAULT ( RC_NEAR + EM_INVALID + EM_ZERODIVIDE + EM_OVERFLOW + EM_UNDERFLOW + EM_INEXACT + EM_DENORMAL)
#ENDIF

/* invalid subconditions (SW_INVALID also set) */

#define SW_UNEMULATED          0x0040  /* unemulated instruction */
#define SW_SQRTNEG             0x0080  /* square root of a neg number */
#define SW_STACKOVERFLOW       0x0200  /* FP stack overflow */
#define SW_STACKUNDERFLOW      0x0400  /* FP stack underflow */

/*  Floating point error signals and return codes */

#define FPE_INVALID            0x81
#define FPE_DENORMAL           0x82
#define FPE_ZERODIVIDE         0x83
#define FPE_OVERFLOW           0x84
#define FPE_UNDERFLOW          0x85
#define FPE_INEXACT            0x86

#define FPE_UNEMULATED         0x87
#define FPE_SQRTNEG            0x88
#define FPE_STACKOVERFLOW      0x8a
#define FPE_STACKUNDERFLOW     0x8b

#define FPE_EXPLICITGEN        0x8c    /* raise( SIGFPE ); */

/* IEEE recommended */

#define FPCLASS_SNAN   0x0001  /* signaling NaN */
#define FPCLASS_QNAN   0x0002  /* quiet NaN */
#define FPCLASS_NINF   0x0004  /* negative infinity */
#define FPCLASS_NN     0x0008  /* negative normal */
#define FPCLASS_ND     0x0010  /* negative denormal */
#define FPCLASS_NZ     0x0020  /* -0 */
#define FPCLASS_PZ     0x0040  /* +0 */
#define FPCLASS_PD     0x0080  /* positive denormal */
#define FPCLASS_PN     0x0100  /* positive normal */
#define FPCLASS_PINF   0x0200  /* positive infinity */


#endif  /* FLOAT_H */
