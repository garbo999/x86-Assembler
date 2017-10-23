#ifndef CTYPE_H
#define CTYPE_H

/* ctype.h - C99 standard header */

/* classification bit masks */
#define _DIGIT  0x01    /* decimal digit */
#define _HEX    0x02    /* hexadecimal digit */
#define _LOWER  0x04    /* lower case letter */
#define _UPPER  0x08    /* upper case letter */
#define _CNTRL  0x10    /* control character */
#define _WHITE  0x20    /* white space character */
#define _SPACE  0x40    /* space */
#define _PUNCT  0x80    /* punctuation character */
#define _BLANK  0x100   /* blank (tab) */

#endif /* _CTYPE_H */

