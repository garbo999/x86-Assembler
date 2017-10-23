#ifndef DPADDR_H
#define DPADDR_H

/* DirectPlayAddress definitions */

#IFNDEF OLE2_H
	#include "ole2.h"
#ENDIF

#IFNDEF DPLAY8_H
	#include "dplay8.h"
#ENDIF

#IFNDEF BASECOM_H
	#include "BaseCOM.h"
#ENDIF

#define GUID_CLSID_DirectPlay8Address <0x934a9523,0xa3ca,0x4bc5,<0xad,0xa0,0xd6,0xd9,0x5d,0x97,0x94,0x21>>
#define GUID_IID_IDirectPlay8Address <0x83783300,0x4063,0x4c8a,<0x9d,0xb3,0x82,0x83,0xa,0x7f,0xeb,0x31>>
#define GUID_IID_IDirectPlay8AddressIP <0xe5a0e990,0x2bad,0x430b,<0x87,0xda,0xa1,0x42,0xcf,0x75,0xde,0x58>>

#define DPNA_DATATYPE_STRING  0x00000001
#define DPNA_DATATYPE_DWORD  0x00000002
#define DPNA_DATATYPE_GUID  0x00000003
#define DPNA_DATATYPE_BINARY  0x00000004
#define DPNA_DATATYPE_STRING_ANSI  0x00000005

#define DPNA_DPNSVR_PORT  6073

#define DPNA_INDEX_INVALID  0xFFFFFFFF

#define DPNA_SEPARATOR_KEYVALUE  L'='
#define DPNA_SEPARATOR_USERDATA  L'#'
#define DPNA_SEPARATOR_COMPONENT  L';'
#define DPNA_ESCAPECHAR  L'%'

#define DPNA_HEADER  L"x-directplay:/"

#define DPNA_KEY_APPLICATION_INSTANCE  L"applicationinstance"
#define DPNA_KEY_BAUD  L"baud"
#define DPNA_KEY_DEVICE  L"device"
#define DPNA_KEY_FLOWCONTROL  L"flowcontrol"
#define DPNA_KEY_HOSTNAME  L"hostname"
#define DPNA_KEY_PARITY  L"parity"
#define DPNA_KEY_PHONENUMBER  L"phonenumber"
#define DPNA_KEY_PORT  L"port"
#define DPNA_KEY_PROGRAM  L"program"
#define DPNA_KEY_PROVIDER  L"provider"
#define DPNA_KEY_STOPBITS  L"stopbits"

#define DPNA_BAUD_RATE_9600  9600
#define DPNA_BAUD_RATE_14400  14400
#define DPNA_BAUD_RATE_19200  19200
#define DPNA_BAUD_RATE_38400  38400
#define DPNA_BAUD_RATE_56000  56000
#define DPNA_BAUD_RATE_57600  57600
#define DPNA_BAUD_RATE_115200  115200

#define DPNA_STOP_BITS_ONE  L"1"
#define DPNA_STOP_BITS_ONE_FIVE  L"1.5"
#define DPNA_STOP_BITS_TWO  L"2"

#define DPNA_PARITY_NONE  L"NONE"
#define DPNA_PARITY_EVEN  L"EVEN"
#define DPNA_PARITY_ODD  L"ODD"
#define DPNA_PARITY_MARK  L"MARK"
#define DPNA_PARITY_SPACE  L"SPACE"

#define DPNA_FLOW_CONTROL_NONE  L"NONE"
#define DPNA_FLOW_CONTROL_XONXOFF  L"XONXOFF"
#define DPNA_FLOW_CONTROL_RTS  L"RTS"
#define DPNA_FLOW_CONTROL_DTR  L"DTR"
#define DPNA_FLOW_CONTROL_RTSDTR  L"RTSDTR"

#define DPNA_VALUE_TCPIPPROVIDER  L"IP"
#define DPNA_VALUE_IPXPROVIDER  L"IPX"
#define DPNA_VALUE_MODEMPROVIDER  L"MODEM"
#define DPNA_VALUE_SERIALPROVIDER  L"SERIAL"

#define DPNA_HEADER_A  A"x-directplay:/"

#define DPNA_SEPARATOR_KEYVALUE_A  A'='
#define DPNA_SEPARATOR_USERDATA_A  A'#'
#define DPNA_SEPARATOR_COMPONENT_A  A';'
#define DPNA_ESCAPECHAR_A  A'%'

#define DPNA_KEY_APPLICATION_INSTANCE_A  A"applicationinstance"
#define DPNA_KEY_BAUD_A  A"baud"
#define DPNA_KEY_DEVICE_A  A"device"
#define DPNA_KEY_FLOWCONTROL_A  A"flowcontrol"
#define DPNA_KEY_HOSTNAME_A  A"hostname"
#define DPNA_KEY_PARITY_A  A"parity"
#define DPNA_KEY_PHONENUMBER_A  A"phonenumber"
#define DPNA_KEY_PORT_A  A"port"
#define DPNA_KEY_PROGRAM_A  A"program"
#define DPNA_KEY_PROVIDER_A  A"provider"
#define DPNA_KEY_STOPBITS_A  A"stopbits"

#define DPNA_STOP_BITS_ONE_A  A"1"
#define DPNA_STOP_BITS_ONE_FIVE_A  A"1.5"
#define DPNA_STOP_BITS_TWO_A  A"2"

#define DPNA_PARITY_NONE_A  A"NONE"
#define DPNA_PARITY_EVEN_A  A"EVEN"
#define DPNA_PARITY_ODD_A  A"ODD"
#define DPNA_PARITY_MARK_A  A"MARK"
#define DPNA_PARITY_SPACE_A  A"SPACE"

#define DPNA_FLOW_CONTROL_NONE_A  A"NONE"
#define DPNA_FLOW_CONTROL_XONXOFF_A  A"XONXOFF"
#define DPNA_FLOW_CONTROL_RTS_A  A"RTS"
#define DPNA_FLOW_CONTROL_DTR_A  A"DTR"
#define DPNA_FLOW_CONTROL_RTSDTR_A  A"RTSDTR"

#define DPNA_VALUE_TCPIPPROVIDER_A  A"IP"
#define DPNA_VALUE_IPXPROVIDER_A  A"IPX"
#define DPNA_VALUE_MODEMPROVIDER_A  A"MODEM"
#define DPNA_VALUE_SERIALPROVIDER_A  A"SERIAL"

IDirectPlay8Address STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	BuildFromURLW PTR
	BuildFromURLA PTR
	Duplicate PTR
	SetEqual PTR
	IsEqual PTR
	Clear PTR
	GetURLW PTR
	GetURLA PTR
	GetSP PTR
	GetUserData PTR
	SetSP PTR
	SetUserData PTR
	GetNumComponents PTR
	GetComponentByName PTR
	GetComponentByIndex PTR
	AddComponent PTR
	GetDevice PTR
	SetDevice PTR
	BuildFromDPADDRESS PTR
ENDS

IDirectPlay8AddressIP STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	BuildFromSockAddr PTR
	BuildAddress PTR
	BuildLocalAddress PTR
	GetSockAddress PTR
	GetLocalAddress PTR
	GetAddress PTR
ENDS

#endif /* DPADDR_H */
