#ifndef LMREMUTL_H
#define LMREMUTL_H

/* NetRemote API definition */

#define SUPPORTS_REMOTE_ADMIN_PROTOCOL  0x00000002
#define SUPPORTS_RPC  0x00000004
#define SUPPORTS_SAM_PROTOCOL  0x00000008
#define SUPPORTS_UNICODE  0x00000010
#define SUPPORTS_LOCAL  0x00000020
#define SUPPORTS_ANY  0xFFFFFFFF

#define NO_PERMISSION_REQUIRED  0x00000001
#define ALLOCATE_RESPONSE  0x00000002
#define USE_SPECIFIC_TRANSPORT  0x80000000

TIME_OF_DAY_INFO STRUCT
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
ENDS

#endif /* _LMREMUTL_H */
