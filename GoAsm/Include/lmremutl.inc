;=============================================================;
;         lmremutl.inc file for Easy Code visual IDE          ;
;            (made for the GoAsm compiler version)            ;
;                                                             ;
;           Version 1.0.00 (created on March, 2008)           ;
;                                                             ;
;      Please report any bug you find (asm@easycode.cat)      ;
;                                                             ;
;                Do not modify this file!!                    ;
;=============================================================;

#IFNDEF LMREMUTL_INC
#Define LMREMUTL_INC

TIME_OF_DAY_INFO Struct
	tod_elapsedt DD
	tod_msecs DD
	tod_hours DD
	tod_mins DD
	tod_secs DD
	tod_hunds DD
	tod_timezone DD
	tod_tinterval DD
	tod_day DD
	tod_month DD
	tod_year DD
	tod_weekday DD
EndS

#Define SUPPORTS_REMOTE_ADMIN_PROTOCOL      000000002H
#Define SUPPORTS_RPC                        000000004H
#Define SUPPORTS_SAM_PROTOCOL               000000008H
#Define SUPPORTS_UNICODE                    000000010H
#Define SUPPORTS_LOCAL                      000000020H
#Define SUPPORTS_ANY                        0FFFFFFFFH

#Define NO_PERMISSION_REQUIRED              000000001H
#Define ALLOCATE_RESPONSE                   000000002H
#Define USE_SPECIFIC_TRANSPORT              080000000H

#ENDIF ;LMREMUTL_INC
