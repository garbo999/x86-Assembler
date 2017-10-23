;=============================================================;
;          lmcons.inc file for Easy Code visual IDE           ;
;            (made for the GoAsm compiler version)            ;
;                                                             ;
;           Version 1.0.00 (created on March, 2008)           ;
;                                                             ;
;      Please report any bug you find (asm@easycode.cat)      ;
;                                                             ;
;                Do not modify this file!!                    ;
;=============================================================;

#IFNDEF LMCONS_INC
#Define LMCONS_INC

#Define CNLEN                               15
#Define LM20_CNLEN                          15
#Define DNLEN                               CNLEN
#Define LM20_DNLEN                          LM20_CNLEN

#Define UNCLEN                              (CNLEN + 2)
#Define LM20_UNCLEN                         (LM20_CNLEN + 2)

#Define NNLEN                               80
#Define LM20_NNLEN                          12

#Define RMLEN                               (UNCLEN + 1 + NNLEN)
#Define LM20_RMLEN                          (LM20_UNCLEN + 1 + LM20_NNLEN)

#Define SNLEN                               80
#Define LM20_SNLEN                          15
#Define STXTLEN                             256
#Define LM20_STXTLEN                        63

#Define PATHLEN                             256
#Define LM20_PATHLEN                        256

#Define DEVLEN                              80
#Define LM20_DEVLEN                         8

#Define EVLEN                               16

#Define UNLEN                               256
#Define LM20_UNLEN                          20

#Define GNLEN                               UNLEN
#Define LM20_GNLEN                          LM20_UNLEN

#Define PWLEN                               256
#Define LM20_PWLEN                          14

#Define SHPWLEN                             8


#Define CLTYPE_LEN                          12


#Define MAXCOMMENTSZ                        256
#Define LM20_MAXCOMMENTSZ                   48

#Define QNLEN                               NNLEN
#Define LM20_QNLEN                          LM20_NNLEN

#Define ALERTSZ                             128
#Define MAXDEVENTRIES                       32

#Define NETBIOS_NAME_LEN                    16

#Define MAX_PREFERRED_LENGTH                (-1)

#Define CRYPT_KEY_LEN                       7
#Define CRYPT_TXT_LEN                       8
#Define ENCRYPTED_PWLEN                     16
#Define SESSION_PWLEN                       24
#Define SESSION_CRYPT_KLEN                  21

#IFNDEF PARMNUM_ALL
	#Define PARMNUM_ALL                     0
#ENDIF

#Define PARM_ERROR_UNKNOWN                  (-1)
#Define PARM_ERROR_NONE                     0
#Define PARMNUM_BASE_INFOLEVEL              1000

#Define MESSAGE_FILENAME                    "NETMSG"
#Define OS2MSG_FILENAME                     "BASE"
#Define HELP_MSG_FILENAME                   "NETH"

#Define BACKUP_MSG_FILENAME                 "BAK.MSG"

#Define PLATFORM_ID_DOS                     300
#Define PLATFORM_ID_OS2                     400
#Define PLATFORM_ID_NT                      500
#Define PLATFORM_ID_OSF                     600
#Define PLATFORM_ID_VMS                     700

#Define MIN_LANMAN_MESSAGE_ID               NERR_BASE
#Define MAX_LANMAN_MESSAGE_ID               5799

#ENDIF ;LMCONS_INC
