#ifndef LMMSG_H
#define LMMSG_H

/* NetMessage API definitions */

#define MSGNAME_NOT_FORWARDED  0
#define MSGNAME_FORWARDED_TO  0x04
#define MSGNAME_FORWARDED_FROM  0x10

MSG_INFO_0 STRUCT
	msgi0_name PTR
ENDS

MSG_INFO_1 STRUCT
	msgi1_name PTR
	msgi1_forward_flag DD
	msgi1_forward PTR
ENDS

#endif /* _LMMSG_H */
