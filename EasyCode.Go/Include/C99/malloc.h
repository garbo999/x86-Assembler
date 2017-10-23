/***
*malloc.h - declarations and definitions for memory allocation functions
*
*       Copyright (c) Microsoft Corporation. All rights reserved.
*
*Purpose:
*       Contains the function declarations for memory allocation functions;
*       also defines manifest constants and types used by the heap routines.
*       [System V]
*
*       [Public]
*
****/

#ifndef MALLOC_H
#define MALLOC_H

#include "c99\limits.h"

/* Maximum heap request the heap manager will attempt */

#ifdef  _WIN64
#define _HEAP_MAXREQ    0xFFFFFFFFFFFFFFE0
#else
#define _HEAP_MAXREQ    0xFFFFFFE0
#endif

/* Constants for _heapchk/_heapset/_heapwalk routines */

#define _HEAPEMPTY      (-1)
#define _HEAPOK         (-2)
#define _HEAPBADBEGIN   (-3)
#define _HEAPBADNODE    (-4)
#define _HEAPEND        (-5)
#define _HEAPBADPTR     (-6)
#define _FREEENTRY      0
#define _USEDENTRY      1

#ifndef _HEAPINFO
_HEAPINFO STRUCT
	pentry PTR
	size PTR
	useflag PTR
ENDS
#endif

/* Function prototypes */

#define _MAX_WAIT_MALLOC_CRT 60000

#define _ALLOCA_S_THRESHOLD     1024
#define _ALLOCA_S_STACK_MARKER  0xCCCC
#define _ALLOCA_S_HEAP_MARKER   0xDDDD

#ifdef X86
#define _ALLOCA_S_MARKER_SIZE   8
#elif IA64
#define _ALLOCA_S_MARKER_SIZE   16
#elif AMD64
#define _ALLOCA_S_MARKER_SIZE   16
#endif

/* hook function must handle these types */
#define _HEAP_MALLOC    1
#define _HEAP_CALLOC    2
#define _HEAP_FREE      3
#define _HEAP_REALLOC   4
#define _HEAP_MSIZE     5
#define _HEAP_EXPAND    6

#endif 

