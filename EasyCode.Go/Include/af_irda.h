#ifndef AF_IRDA_H
#define AF_IRDA_H

/* Winsock 1.1; IrDA 1.1 */

#define WINDOWS_AF_IRDA  26
#define WCE_AF_IRDA  22
#define WCE_PF_IRDA  WCE_AF_IRDA
#define IRDA_PROTO_SOCK_STREAM  1

#if WINVER = NTDDI_WINCE
	#define AF_IRDA  WCE_AF_IRDA
	#define WINDOWS_PF_IRDA WCE_PF_IRDA
#else
	#define AF_IRDA  WINDOWS_AF_IRDA
	#define WINDOWS_PF_IRDA  WINDOWS_AF_IRDA
#endif

#define PF_IRDA  AF_IRDA

#define SOL_IRLMP  0x00FF

#define IRLMP_ENUMDEVICES  0x00000010
#define IRLMP_IAS_SET  0x00000011
#define IRLMP_IAS_QUERY  0x00000012
#define IRLMP_SEND_PDU_LEN  0x00000013
#define IRLMP_EXCLUSIVE_MODE  0x00000014
#define IRLMP_IRLPT_MODE  0x00000015
#define IRLMP_9WIRE_MODE  0x00000016
#define IRLMP_TINYTP_MODE  0x00000017
#define IRLMP_PARAMETERS  0x00000018
#define IRLMP_DISCOVERY_MODE  0x00000019
#define IRLMP_SHARP_MODE  0x00000020

#define IAS_ATTRIB_NO_CLASS  0x00000010
#define IAS_ATTRIB_NO_ATTRIB  0x00000000
#define IAS_ATTRIB_INT  0x00000001
#define IAS_ATTRIB_OCTETSEQ  0x00000002
#define IAS_ATTRIB_STR  0x00000003

#define IAS_MAX_USER_STRING  256
#define IAS_MAX_OCTET_STRING  1024
#define IAS_MAX_CLASSNAME  64
#define IAS_MAX_ATTRIBNAME  256

#define LmCharSetASCII  0
#define LmCharSetISO_8859_1  1
#define LmCharSetISO_8859_2  2
#define LmCharSetISO_8859_3  3
#define LmCharSetISO_8859_4  4
#define LmCharSetISO_8859_5  5
#define LmCharSetISO_8859_6  6
#define LmCharSetISO_8859_7  7
#define LmCharSetISO_8859_8  8
#define LmCharSetISO_8859_9  9
#define LmCharSetUNICODE  0xff

#define LM_BAUD_1200  1200
#define LM_BAUD_2400  2400
#define LM_BAUD_9600  9600
#define LM_BAUD_19200  19200
#define LM_BAUD_38400  38400
#define LM_BAUD_57600  57600
#define LM_BAUD_115200  115200
#define LM_BAUD_576K  576000
#define LM_BAUD_1152K  1152000
#define LM_BAUD_4M  4000000

LM_HB_Extension = 128
LM_HB1_PnP = 1
LM_HB1_PDA_Palmtop = 2
LM_HB1_Computer = 4
LM_HB1_Printer = 8
LM_HB1_Modem = 16
LM_HB1_Fax = 32
LM_HB1_LANAccess = 64
LM_HB2_Telephony = 1
LM_HB2_FileServer = 2

LM_IRPARMS STRUCT
	nTXDataBytes DD
	nRXDataBytes DD
	nBaudRate DD
	thresholdTime DD
	discTime DD
	nMSLinkTurn DD
	nTXPackets DD
	nRXPackets DD
ENDS

SOCKADDR_IRDA STRUCT
	irdaAddressFamily DW
	irdaDeviceID DB 4 DUP
	irdaServiceName DB 25 DUP
ENDS

#IF WINVER > NTDDI_WINCE

WINDOWS_IRDA_DEVICE_INFO STRUCT
	irdaDeviceID DB 4 DUP
	irdaDeviceName DB 22 DUP
	irdaDeviceHints1 DB
	irdaDeviceHints2 DB
	irdaCharSet DB
ENDS

WINDOWS_DEVICELIST STRUCT
	numDevice DD
	Device WINDOWS_IRDA_DEVICE_INFO
ENDS

WINDOWS_IAS_SET STRUCT
	irdaClassName DB IAS_MAX_CLASSNAME DUP
	irdaAttribName DB IAS_MAX_ATTRIBNAME DUP
	irdaAttribType DD
	UNION
		irdaAttribInt DD
		irdaAttribOctetSeq STRUCT
			Len DB
			OctetSeq DB IAS_MAX_OCTET_STRING DUP
		ENDS
		irdaAttribUsrStr STRUCT
			Len DB
			CharSet DB
			UsrStr DB IAS_MAX_USER_STRING DUP
		ENDS
	ENDUNION
ENDS

WINDOWS_IAS_QUERY STRUCT
	irdaDeviceID DB 4 DUP
	irdaClassName DB IAS_MAX_CLASSNAME DUP
	irdaAttribName DB IAS_MAX_ATTRIBNAME DUP
	irdaAttribType DD
	UNION
		irdaAttribInt DD
		irdaAttribOctetSeq STRUCT
			Len DB
			OctetSeq DB IAS_MAX_OCTET_STRING DUP
		ENDS
		irdaAttribUsrStr STRUCT
			Len DB
			CharSet DB
			UsrStr DB IAS_MAX_USER_STRING DUP
		ENDS
	ENDUNION
ENDS

#ELSE

WCE_IRDA_DEVICE_INFO STRUCT
	irdaDeviceID DB 4 DUP
	irdaDeviceName DB 22 DUP
	Reserved DB 2 DUP
ENDS

WCE_DEVICELIST STRUCT
	numDevice DD
	Device WINDOWS_IRDA_DEVICE_INFO
ENDS

WCE_IAS_SET STRUCT
	irdaClassName DB 61 DUP
	irdaAttribName DB 61 DUP
	irdaAttribType DW
	UNION
		irdaAttribInt DD
		irdaAttribOctetSeq STRUCT
			Len DD
			OctetSeq DB
			Reserved DB 3 DUP
		ENDS
		irdaAttribUsrStr STRUCT
			Len DD
			CharSet DB
			UsrStr DB
			Reserved DB 2 DUP
		ENDS
	ENDUNION
ENDS

WCE_IAS_QUERY STRUCT
	irdaDeviceID DB 4 DUP
	irdaClassName DB 61 DUP
	irdaAttribName DB 61 DUP
	irdaAttribType DW
	UNION
		irdaAttribInt DD
		irdaAttribOctetSeq STRUCT
			Len DD
			OctetSeq DB
			Reserved DB 3 DUP
		ENDS
		irdaAttribUsrStr STRUCT
			Len DD
			CharSet DB
			UsrStr DB
			Reserved DB 2 DUP
		ENDS
	ENDUNION
ENDS

	#define WINDOWS_IRDA_DEVICE_INFO WCE_IRDA_DEVICE_INFO
	#define WINDOWS_DEVICELIST WCE_DEVICELIST
	#define WINDOWS_IAS_SET WCE_IAS_SET
	#define WINDOWS_IAS_QUERY WCE_IAS_QUERY
#ENDIF

#endif /* AF_IRDA_H */
