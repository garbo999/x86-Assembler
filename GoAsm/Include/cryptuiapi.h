#ifndef CRYPTUIAPI_H
#define CRYPTUIAPI_H

#DEFINE CRYPTUIAPI_H_REQVER 100

/*
Depenancies
wincrypt.h
*/

/* Cryptographic UI API definitions */

#IFNDEF WINCRYPT_H
	#include wincrypt.h
#ENDIF

#define CRYPTUI_SELECT_ISSUEDTO_COLUMN  0x000000001
#define CRYPTUI_SELECT_ISSUEDBY_COLUMN  0x000000002
#define CRYPTUI_SELECT_INTENDEDUSE_COLUMN  0x000000004
#define CRYPTUI_SELECT_FRIENDLYNAME_COLUMN  0x000000008
#define CRYPTUI_SELECT_LOCATION_COLUMN  0x000000010
#define CRYPTUI_SELECT_EXPIRATION_COLUMN  0x000000020

#endif /* CRYPTUIAPI_H */
