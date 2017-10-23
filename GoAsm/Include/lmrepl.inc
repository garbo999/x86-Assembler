;=============================================================;
;          lmrepl.inc file for Easy Code visual IDE           ;
;            (made for the GoAsm compiler version)            ;
;                                                             ;
;           Version 1.0.00 (created on March, 2008)           ;
;                                                             ;
;      Please report any bug you find (asm@easycode.cat)      ;
;                                                             ;
;                Do not modify this file!!                    ;
;=============================================================;

#IFNDEF LMREPL_INC
#Define LMREPL_INC

#Define REPL_ROLE_EXPORT                    1
#Define REPL_ROLE_IMPORT                    2
#Define REPL_ROLE_BOTH                      3


#Define REPL_INTERVAL_INFOLEVEL             (PARMNUM_BASE_INFOLEVEL + 0)
#Define REPL_PULSE_INFOLEVEL                (PARMNUM_BASE_INFOLEVEL + 1)
#Define REPL_GUARDTIME_INFOLEVEL            (PARMNUM_BASE_INFOLEVEL + 2)
#Define REPL_RANDOM_INFOLEVEL               (PARMNUM_BASE_INFOLEVEL + 3)

REPL_INFO_0 Struct
	rp0_role DD
	rp0_exportpath DD
	rp0_exportlist DD
	rp0_importpath DD
	rp0_importlist DD
	rp0_logonusername DD
	rp0_interval DD
	rp0_pulse DD
	rp0_guardtime DD
	rp0_random DD
EndS

REPL_INFO_1000 Struct
	rp1000_interval DD
EndS

REPL_INFO_1001 Struct
	rp1001_pulse DD
EndS

REPL_INFO_1002 Struct
	rp1002_guardtime DD
EndS

REPL_INFO_1003 Struct
	rp1003_random DD
EndS

#Define REPL_INTEGRITY_FILE                 1
#Define REPL_INTEGRITY_TREE                 2


#Define REPL_EXTENT_FILE                    1
#Define REPL_EXTENT_TREE                    2


#Define REPL_EXPORT_INTEGRITY_INFOLEVEL     (PARMNUM_BASE_INFOLEVEL + 0)
#Define REPL_EXPORT_EXTENT_INFOLEVEL        (PARMNUM_BASE_INFOLEVEL + 1)

REPL_EDIR_INFO_0 Struct
	rped0_dirname DD
EndS

REPL_EDIR_INFO_1 Struct
	rped1_dirname DD
	rped1_integrity DD
	rped1_extent DD
EndS

REPL_EDIR_INFO_2 Struct
	rped2_dirname DD
	rped2_integrity DD
	rped2_extent DD
	rped2_lockcount DD
	rped2_locktime DD
EndS

REPL_EDIR_INFO_1000 Struct
	rped1000_integrity DD
EndS

REPL_EDIR_INFO_1001 Struct
	rped1001_extent DD
EndS

#Define REPL_UNLOCK_NOFORCE                 0
#Define REPL_UNLOCK_FORCE                   1

REPL_IDIR_INFO_0 Struct
	rpid0_dirname DD
EndS

REPL_IDIR_INFO_1 Struct
	rpid1_dirname DD
	rpid1_state DD
	rpid1_mastername DD
	rpid1_last_update_time DD
	rpid1_lockcount DD
	rpid1_locktime DD
EndS

#Define REPL_STATE_OK                       0
#Define REPL_STATE_NO_MASTER                1
#Define REPL_STATE_NO_SYNC                  2
#Define REPL_STATE_NEVER_REPLICATED         3

#ENDIF ;LMREPL_INC
