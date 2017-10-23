#ifndef LMREPL_H
#define LMREPL_H

/* Replicator API definitions */

#define REPL_ROLE_EXPORT  1
#define REPL_ROLE_IMPORT  2
#define REPL_ROLE_BOTH  3

#define REPL_INTERVAL_INFOLEVEL  (PARMNUM_BASE_INFOLEVEL+0)
#define REPL_PULSE_INFOLEVEL  (PARMNUM_BASE_INFOLEVEL+1)
#define REPL_GUARDTIME_INFOLEVEL  (PARMNUM_BASE_INFOLEVEL+2)
#define REPL_RANDOM_INFOLEVEL  (PARMNUM_BASE_INFOLEVEL+3)

#define REPL_INTEGRITY_FILE  1
#define REPL_INTEGRITY_TREE  2

#define REPL_EXTENT_FILE  1
#define REPL_EXTENT_TREE  2

#define REPL_EXPORT_INTEGRITY_INFOLEVEL  (PARMNUM_BASE_INFOLEVEL+0)
#define REPL_EXPORT_EXTENT_INFOLEVEL  (PARMNUM_BASE_INFOLEVEL+1)

#define REPL_UNLOCK_NOFORCE  0
#define REPL_UNLOCK_FORCE  1

#define REPL_STATE_OK  0
#define REPL_STATE_NO_MASTER  1
#define REPL_STATE_NO_SYNC  2
#define REPL_STATE_NEVER_REPLICATED  3

REPL_INFO_0 STRUCT
	rp0_role DD
	rp0_exportpath PTR
	rp0_exportlist PTR
	rp0_importpath PTR
	rp0_importlist PTR
	rp0_logonusername PTR
	rp0_interval DD
	rp0_pulse DD
	rp0_guardtime DD
	rp0_random DD
ENDS

REPL_INFO_1000 STRUCT
	rp1000_interval DD
ENDS

REPL_INFO_1001 STRUCT
	rp1001_pulse DD
ENDS

REPL_INFO_1002 STRUCT
	rp1002_guardtime DD
ENDS

REPL_INFO_1003 STRUCT
	rp1003_random DD
ENDS

REPL_EDIR_INFO_0 STRUCT
	rped0_dirname PTR
ENDS

REPL_EDIR_INFO_1 STRUCT
	rped1_dirname PTR
	rped1_integrity DD
	rped1_extent DD
ENDS

REPL_EDIR_INFO_2 STRUCT
	rped2_dirname PTR
	rped2_integrity DD
	rped2_extent DD
	rped2_lockcount DD
	rped2_locktime DD
ENDS

REPL_EDIR_INFO_1000 STRUCT
	rped1000_integrity DD
ENDS

REPL_EDIR_INFO_1001 STRUCT
	rped1001_extent DD
ENDS

REPL_IDIR_INFO_0 STRUCT
	rpid0_dirname PTR
ENDS

REPL_IDIR_INFO_1 STRUCT
	rpid1_dirname PTR
	rpid1_state DD
	rpid1_mastername PTR
	rpid1_last_update_time DD
	rpid1_lockcount DD
	rpid1_locktime DD
ENDS

#endif /* _LMREPL_H */
