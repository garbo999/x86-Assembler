#ifndef BASETSD_H
#define BASETSD_H

/* Windows Basic sized type definitions (01-05-29) */

#IFDEF X64
#define ADDRESS_TAG_BIT  0x40000000000
#ELSE
#define ADDRESS_TAG_BIT  0x80000000
#ENDIF

#endif

