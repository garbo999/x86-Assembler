#ifndef BHTYPES_H
#define BHTYPES_H

/* Microsoft Network Monitor definitions */

#define HANDLE_TYPE_INVALID  -1
#define HANDLE_TYPE_CAPTURE  A'CAP$'
#define HANDLE_TYPE_PARSER  A'PSR$'
#define HANDLE_TYPE_ADDRESSDB  A'ADR$'
#define HANDLE_TYPE_PROTOCOL  A'PRT$'
#define HANDLE_TYPE_BUFFER  A'BUF$'

#define MAX_NAME_LENGTH  16
#define MAX_ADDR_LENGTH  6

#define ETYPE_LOOP  0x9000
#define ETYPE_3COM_NETMAP1  0x9001
#define ETYPE_3COM_NETMAP2  0x9002
#define ETYPE_IBM_RT  0x80D5
#define ETYPE_NETWARE  0x8137
#define ETYPE_XNS1  0x0600
#define ETYPE_XNS2  0x0807
#define ETYPE_3COM_NBP0  0x3C00
#define ETYPE_3COM_NBP1  0x3C01
#define ETYPE_3COM_NBP2  0x3C02
#define ETYPE_3COM_NBP3  0x3C03
#define ETYPE_3COM_NBP4  0x3C04
#define ETYPE_3COM_NBP5  0x3C05
#define ETYPE_3COM_NBP6  0x3C06
#define ETYPE_3COM_NBP7  0x3C07
#define ETYPE_3COM_NBP8  0x3C08
#define ETYPE_3COM_NBP9  0x3C09
#define ETYPE_3COM_NBP10  0x3C0A
#define ETYPE_IP  0x0800
#define ETYPE_ARP1  0x0806
#define ETYPE_ARP2  0x0807
#define ETYPE_RARP  0x8035
#define ETYPE_TRLR0  0x1000
#define ETYPE_TRLR1  0x1001
#define ETYPE_TRLR2  0x1002
#define ETYPE_TRLR3  0x1003
#define ETYPE_TRLR4  0x1004
#define ETYPE_TRLR5  0x1005
#define ETYPE_PUP  0x0200
#define ETYPE_PUP_ARP  0x0201
#define ETYPE_APPLETALK_ARP  0x80F3
#define ETYPE_APPLETALK_LAP  0x809B
#define ETYPE_SNMP  0x814C

#define SAP_SNAP  0xAA
#define SAP_BPDU  0x42
#define SAP_IBM_NM  0xF4
#define SAP_IBM_NETBIOS  0xF0
#define SAP_SNA1  0x04
#define SAP_SNA2  0x05
#define SAP_SNA3  0x08
#define SAP_SNA4  0x0C
#define SAP_NETWARE1  0x10
#define SAP_NETWARE2  0xE0
#define SAP_NETWARE3  0xFE
#define SAP_IP  0x06
#define SAP_X25  0x7E
#define SAP_RPL1  0xF8
#define SAP_RPL2  0xFC
#define SAP_UB  0xFA
#define SAP_XNS  0x80

#define PROP_TYPE_VOID  0x00
#define PROP_TYPE_SUMMARY  0x01
#define PROP_TYPE_BYTE  0x02
#define PROP_TYPE_WORD  0x03
#define PROP_TYPE_DWORD  0x04
#define PROP_TYPE_LARGEINT  0x05
#define PROP_TYPE_ADDR  0x06
#define PROP_TYPE_TIME  0x07
#define PROP_TYPE_STRING  0x08
#define PROP_TYPE_IP_ADDRESS  0x09
#define PROP_TYPE_IPX_ADDRESS  0x0A
#define PROP_TYPE_BYTESWAPPED_WORD  0x0B
#define PROP_TYPE_BYTESWAPPED_DWORD 0x0C
#define PROP_TYPE_TYPED_STRING  0x0D
#define PROP_TYPE_RAW_DATA  0x0E
#define PROP_TYPE_COMMENT  0x0F
#define PROP_TYPE_SRCFRIENDLYNAME  0x10
#define PROP_TYPE_DSTFRIENDLYNAME  0x11
#define PROP_TYPE_TOKENRING_ADDRESS 0x12
#define PROP_TYPE_FDDI_ADDRESS  0x13
#define PROP_TYPE_ETHERNET_ADDRESS  0x14
#define PROP_TYPE_OBJECT_IDENTIFIER  0x15
#define PROP_TYPE_VINES_IP_ADDRESS  0x16
#define PROP_TYPE_VAR_LEN_SMALL_INT 0x17

#define PROP_QUAL_NONE  0x00
#define PROP_QUAL_RANGE  0x01
#define PROP_QUAL_SET  0x02
#define PROP_QUAL_BITFIELD  0x03
#define PROP_QUAL_LABELED_SET  0x04
#define PROP_QUAL_LABELED_BITFIELD  0x08
#define PROP_QUAL_CONST  0x09
#define PROP_QUAL_FLAGS  0x0A
#define PROP_QUAL_ARRAY  0x0B

#define TYPED_STRING_NORMAL  1
#define TYPED_STRING_UNICODE  2
#define TYPED_STRING_EXFLAG  1


#define IFLAG_ERROR  0x00000001
#define IFLAG_SWAPPED  0x00000002
#define IFLAG_UNICODE  0x00000004

#define SORT_BYADDRESS  0
#define SORT_BYNAME  1

#define PERMANENT_NAME  0x00000100

RANGE STRUCT
	MinValue DD
	MaxValue DD
ENDS

LABELED_BYTE STRUCT
	Value DB
	Label PTR
ENDS

LABELED_WORD STRUCT
	Value DW
	Label PTR
ENDS

LABELED_DWORD STRUCT
	Value DD
	Label DD
ENDS

LABELED_LARGEINT STRUCT
	Value DQ
	Label PTR
ENDS

LABELED_SYSTEMTIME STRUCT
	Value SYSTEMTIME
	Label PTR
ENDS

LABELED_BIT STRUCT
	BitNumber DB
	LabelOff PTR
	LabelOn PTR
ENDS

TYPED_STRING STRUCT
	StringType DB 7 DUP
	fStringEx DB
	lpString PTR
	Byte DB
ENDS

OBJECT_IDENTIFIER STRUCT
	Length DD
	lpIdentifier PTR
ENDS

SET STRUCT
	nEntries DD
	UNION
		lpVoidTable PTR
		lpByteTable PTR
		lpWordTable PTR
		lpDwordTable PTR
		lpLargeIntTable PTR
		lpSystemTimeTable PTR
		lpLabeledByteTable PTR
		lpLabeledWordTable PTR
		lpLabeledDwordTable PTR
		lpLabeledLargeIntTable PTR
		lpLabeledSystemTimeTable PTR
		lpLabeledBit PTR
	ENDUNION
ENDS

STRINGTABLE STRUCT
	nStrings DD
	String PTR
ENDS

RECOGNIZEDATA STRUCT
	ProtocolID DW
	nProtocolOffset DW
	InstData PTR
ENDS

RECOGNIZEDATATABLE STRUCT
	nRecognizeDatas DW
	RecognizeData RECOGNIZEDATA
ENDS

PROPERTYINFO STRUCT
	hProperty DD
	Version DD
	Label PTR
	Comment PTR
	DataType DB
	DataQualifier DB
	UNION
		lpExtendedInfo PTR
		lpRange PTR
		lpSet PTR
		Bitmask DD
		Value DD
	ENDUNION
	FormatStringSize DW
	InstanceData PTR
ENDS

PROPERTYINSTEX STRUCT
	Length DW
	LengthEx DW
	lpData PTR
	UNION
		Byte DB
		Word DW
		Dword DD
		LargeInt DQ
		SysTime SYSTEMTIME
		TypedString TYPED_STRING
	ENDUNION
ENDS

PROPERTYINST STRUCT
	lpPropertyInfo PTR
	szPropertyText PTR
	UNION
		lpData PTR
		lpByte PTR
		lpWord PTR
		lpDword PTR
		lpLargeInt PTR
		lpSysTime PTR
		lpPropertyInstEx PTR
	ENDUNION
	DataLength DW
	Level DW 4 DUP
	HelpID DW 12 DUP
	IFlags DD
ENDS

PROPERTYINSTTABLE STRUCT
	nPropertyInsts DW
	nPropertyInstIndex DW
ENDS

PROPERTYTABLE STRUCT
	lpFormatBuffer PTR
	FormatBufferLength DD
	nTotalPropertyInsts DD
	lpFirstPropertyInst PTR
	nPropertyInstTables DB
	PropertyInstTable PROPERTYINSTTABLE
ENDS

ENTRYPOINTS STRUCT
	Register PTR
	Deregister PTR
	RecognizeFrame PTR
	AttachProperties PTR
	FormatProperties PTR
ENDS

PROPERTYDATABASE STRUCT
	nProperties DD
	PropertyInfo PTR
ENDS

PROTOCOLINFO STRUCT
	ProtocolID DD
	PropertyDatabase DD
	ProtocolName DB 16 DUP
	HelpFile DB 16 DUP
	Comment DB 128 DUP
ENDS

PROTOCOLTABLE STRUCT
	nProtocols DD
	hProtocol DD
ENDS

ADDRESSINFO STRUCT
	Address PTR
	Name DW MAX_NAME_SIZE DUP
	Flags DD
	lpAddressInstData PTR
ENDS

ADDRESSINFOTABLE STRUCT
	nAddressInfos DD
	lpAddressInfo PTR
ENDS

#endif /* _BHTYPES_H */
