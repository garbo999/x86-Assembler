#ifndef LMCONS_H
#define LMCONS_H

/* LAN Manager API constants */

/*
 * NOTE: Lengths of strings are given in number of characters
 * without counting the terminating 0-character.
 */

#define MESSAGE_FILENAME  "NETMSG"
#define OS2MSG_FILENAME  "BASE"
#define HELP_MSG_FILENAME  "NETH"

#define MIN_LANMAN_MESSAGE_ID  NERR_BASE
#define MAX_LANMAN_MESSAGE_ID  5799

#define CNLEN  15
#define LM20_CNLEN  15
#define DNLEN  CNLEN
#define LM20_DNLEN  LM20_CNLEN

#define UNCLEN  (CNLEN+2)
#define LM20_UNCLEN  (LM20_CNLEN+2)

#define NNLEN  80
#define LM20_NNLEN  12

#define RMLEN  (UNCLEN+1+NNLEN)
#define LM20_RMLEN  (LM20_UNCLEN+1+LM20_NNLEN)

#define SNLEN  80
#define LM20_SNLEN  15
#define STXTLEN  256
#define LM20_STXTLEN  63

#define PATHLEN  256
#define LM20_PATHLEN  256

#define DEVLEN  80
#define LM20_DEVLEN  8

#define EVLEN  16

#define UNLEN  256
#define LM20_UNLEN  20

#define GNLEN  UNLEN
#define LM20_GNLEN  LM20_UNLEN

#define PWLEN  256
#define LM20_PWLEN  14

#define SHPWLEN  8

#define CLTYPE_LEN  12

#define MAXCOMMENTSZ  256
#define LM20_MAXCOMMENTSZ  48

#define QNLEN  NNLEN
#define LM20_QNLEN  LM20_NNLEN

#define ALERTSZ  128
#define MAXDEVENTRIES  32

#define NETBIOS_NAME_LEN  16

#define MAX_PREFERRED_LENGTH  -1

#define CRYPT_KEY_LEN  7
#define CRYPT_TXT_LEN  8
#define ENCRYPTED_PWLEN  16
#define SESSION_PWLEN  24
#define SESSION_CRYPT_KLEN  21

#ifndef PARMNUM_ALL
	#define PARMNUM_ALL  0
#endif

#define PARM_ERROR_UNKNOWN -1
#define PARM_ERROR_NONE  0
#define PARMNUM_BASE_INFOLEVEL  1000

#define PLATFORM_ID_DOS  300
#define PLATFORM_ID_OS2  400
#define PLATFORM_ID_NT  500
#define PLATFORM_ID_OSF  600
#define PLATFORM_ID_VMS  700

#endif /* _LMCONS_H */
