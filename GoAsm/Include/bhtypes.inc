;=============================================================;
;          bhtypes.inc file for Easy Code visual IDE          ;
;            (made for the GoAsm compiler version)            ;
;                                                             ;
;           Version 1.0.00 (created on March, 2008)           ;
;                                                             ;
;      Please report any bug you find (asm@easycode.cat)      ;
;                                                             ;
;                Do not modify this file!!                    ;
;=============================================================;

#IFNDEF BHTYPES_INC
#Define BHTYPES_INC

#Define MAX_NAME_LENGTH                     16
#Define MAX_ADDR_LENGTH                     6

#Define ETYPE_LOOP                          09000H
#Define ETYPE_3COM_NETMAP1                  09001H
#Define ETYPE_3COM_NETMAP2                  09002H
#Define ETYPE_IBM_RT                        080D5H
#Define ETYPE_NETWARE                       08137H
#Define ETYPE_XNS1                          00600H
#Define ETYPE_XNS2                          00807H
#Define ETYPE_3COM_NBP0                     03C00H
#Define ETYPE_3COM_NBP1                     03C01H
#Define ETYPE_3COM_NBP2                     03C02H
#Define ETYPE_3COM_NBP3                     03C03H
#Define ETYPE_3COM_NBP4                     03C04H
#Define ETYPE_3COM_NBP5                     03C05H
#Define ETYPE_3COM_NBP6                     03C06H
#Define ETYPE_3COM_NBP7                     03C07H
#Define ETYPE_3COM_NBP8                     03C08H
#Define ETYPE_3COM_NBP9                     03C09H
#Define ETYPE_3COM_NBP10                    03C0AH
#Define ETYPE_IP                            00800H
#Define ETYPE_ARP1                          00806H
#Define ETYPE_ARP2                          00807H
#Define ETYPE_RARP                          08035H
#Define ETYPE_TRLR0                         01000H
#Define ETYPE_TRLR1                         01001H
#Define ETYPE_TRLR2                         01002H
#Define ETYPE_TRLR3                         01003H
#Define ETYPE_TRLR4                         01004H
#Define ETYPE_TRLR5                         01005H
#Define ETYPE_PUP                           00200H
#Define ETYPE_PUP_ARP                       00201H
#Define ETYPE_APPLETALK_ARP                 080F3H
#Define ETYPE_APPLETALK_LAP                 0809BH
#Define ETYPE_SNMP                          0814CH

#Define SAP_SNAP                            0AAH
#Define SAP_BPDU                            042H
#Define SAP_IBM_NM                          0F4H
#Define SAP_IBM_NETBIOS                     0F0H
#Define SAP_SNA1                            004H
#Define SAP_SNA2                            005H
#Define SAP_SNA3                            008H
#Define SAP_SNA4                            00CH
#Define SAP_NETWARE1                        010H
#Define SAP_NETWARE2                        0E0H
#Define SAP_NETWARE3                        0FEH
#Define SAP_IP                              006H
#Define SAP_X25                             07EH
#Define SAP_RPL1                            0F8H
#Define SAP_RPL2                            0FCH
#Define SAP_UB                              0FAH
#Define SAP_XNS                             080H

#Define PROP_TYPE_VOID                      000H
#Define PROP_TYPE_SUMMARY                   001H
#Define PROP_TYPE_BYTE                      002H
#Define PROP_TYPE_WORD                      003H
#Define PROP_TYPE_DWORD                     004H
#Define PROP_TYPE_LARGEINT                  005H
#Define PROP_TYPE_ADDR                      006H
#Define PROP_TYPE_TIME                      007H
#Define PROP_TYPE_STRING                    008H
#Define PROP_TYPE_IP_ADDRESS                009H
#Define PROP_TYPE_IPX_ADDRESS               00AH
#Define PROP_TYPE_BYTESWAPPED_WORD          00BH
#Define PROP_TYPE_BYTESWAPPED_DWORD         00CH
#Define PROP_TYPE_TYPED_STRING              00DH
#Define PROP_TYPE_RAW_DATA                  00EH
#Define PROP_TYPE_COMMENT                   00FH
#Define PROP_TYPE_SRCFRIENDLYNAME           010H
#Define PROP_TYPE_DSTFRIENDLYNAME           011H
#Define PROP_TYPE_TOKENRING_ADDRESS         012H
#Define PROP_TYPE_FDDI_ADDRESS              013H
#Define PROP_TYPE_ETHERNET_ADDRESS          014H
#Define PROP_TYPE_OBJECT_IDENTIFIER	        015H
#Define PROP_TYPE_VINES_IP_ADDRESS          016H
#Define PROP_TYPE_VAR_LEN_SMALL_INT         017H

#Define PROP_QUAL_NONE                      000H
#Define PROP_QUAL_RANGE                     001H
#Define PROP_QUAL_SET                       002H
#Define PROP_QUAL_BITFIELD                  003H
#Define PROP_QUAL_LABELED_SET               004H
#Define PROP_QUAL_LABELED_BITFIELD          008H
#Define PROP_QUAL_CONST                     009H
#Define PROP_QUAL_FLAGS                     00AH
#Define PROP_QUAL_ARRAY                     00BH

#IFNDEF LARGE_INTEGER
	LARGE_INTEGER Struct
		LowPart DD
		HighPart DD
	EndS
#ENDIF

RANGE Struct
	MinValue DD
	MaxValue DD
EndS

LABELED_BYTE Struct
	Value DB
	Label DD
EndS

LABELED_WORD Struct
	Value DW
	Label DD
EndS

LABELED_DWORD Struct
	Value DD
	Label DD
EndS

LABELED_LARGEINT Struct
	Value LARGE_INTEGER <>
	Label DD
EndS

LABELED_SYSTEMTIME Struct
	Value SYSTEMTIME <>
	Label DD
EndS

LABELED_BIT Struct
	BitNumber DB
	LabelOff DD
	LabelOn DD
EndS

#Define TYPED_STRING_NORMAL                 1
#Define TYPED_STRING_UNICODE                2

#Define TYPED_STRING_EXFLAG                 1

TYPED_STRING Struct
	StringType DB 7 Dup ?
	fStringEx DB
	lpString DD
	Byte DB
EndS

OBJECT_IDENTIFIER Struct
	Length DD
	lpIdentifier DD
EndS

SET Struct
	nEntries DD
	Union
		lpVoidTable DD
		lpByteTable DD
		lpWordTable DD
		lpDwordTable DD
		lpLargeIntTable DD
		lpSystemTimeTable DD
		lpLabeledByteTable DD
		lpLabeledWordTable DD
		lpLabeledDwordTable DD
		lpLabeledLargeIntTable DD
		lpLabeledSystemTimeTable DD
		lpLabeledBit DD
	EndUnion
EndS

STRINGTABLE Struct
	nStrings DD
	String DD
EndS

#Define STRINGTABLE_SIZE                    SizeOf(STRINGTABLE)

RECOGNIZEDATA Struct
	ProtocolID DW
	nProtocolOffset DW
	InstData DD
EndS

RECOGNIZEDATATABLE Struct
	nRecognizeDatas DW
	RECOGNIZEDATA RECOGNIZEDATA <>
EndS

PROPERTYINFO Struct
	hProperty DD
	Version DD
	Label DD
	Comment DD
	DataType DB
	DataQualifier DB
	Union
		lpExtendedInfo DD
		lpRange DD
		lpSet DD
		Bitmask DD
		Value DD
	EndUnion
	FormatStringSize DW
	InstanceData DW
EndS

#Define PROPERTYINFO_SIZE                   SizeOf(PROPERTYINFO)

PROPERTYINSTEX Struct
	Length DW
	LengthEx DW
	lpData DD
	Union
        BYTE Byte DB
        WORD Word DW
        DWORD Dword DD
        LARGE_INTEGER LargeInt DQ
        SYSTEMTIME SysTime SYSTEMTIME <>
        TypedString TYPED_STRING <>
	EndUnion
EndS

#Define PROPERTYINSTEX_SIZE                 SizeOf(PROPERTYINSTEX)

PROPERTYINST Struct
	lpPropertyInfo DD
	szPropertyText DD
	Union
		lpData DD
		lpByte DD
		lpWord DD
		lpDword DD
		lpLargeInt DD
		lpSysTime DD
		lpPropertyInstEx DD
	EndUnion
	DataLength DW
	Level DW 4 Dup ?
	HelpID DW 12 Dup ?
	IFlags DD
EndS

#Define PROPERTYINST_SIZE                   SizeOf(PROPERTYINST)

#Define IFLAG_ERROR                         000000001H
#Define IFLAG_SWAPPED                       000000002H
#Define IFLAG_UNICODE                       000000004H

PROPERTYINSTTABLE Struct
	nPropertyInsts DW
	nPropertyInstIndex DW
EndS

#Define PROPERTYINSTTABLE_SIZE              SizeOf(PROPERTYINSTTABLE)

PROPERTYTABLE Struct
	lpFormatBuffer DD
	FormatBufferLength DD
	nTotalPropertyInsts DD
	lpFirstPropertyInst DD
	nPropertyInstTables DB
	PropertyInstTable PROPERTYINSTTABLE <>
EndS

#Define PROPERTYTABLE_SIZE                  SizeOf(PROPERTYTABLE)

ENTRYPOINTS Struct
	Register DD
	Deregister DD
	RecognizeFrame DD
	AttachProperties DD
	FormatProperties DD
EndS

#Define ENTRYPOINTS_SIZE                    SizeOf(ENTRYPOINTS)

PROPERTYDATABASE Struct
    nProperties DD
    PropertyInfo DD
EndS

#Define PROPERTYDATABASE_SIZE               SizeOf(PROPERTYDATABASE)

PROTOCOLINFO Struct
	ProtocolID DD
	PropertyDatabase DD
	ProtocolName DB 16 Dup ?
	HelpFile DB 16 Dup ?
	Comment DB 128 Dup ?
EndS

#Define PROTOCOLINFO_SIZE                   SizeOf(PROTOCOLINFO)

PROTOCOLTABLE Struct
	nProtocols DD
	hProtocol DD
EndS

#Define PROTOCOLTABLE_SIZE                  SizeOf(PROTOCOLTABLE) - 4 ;SizeOf(HPROTOCOL)

#Define SORT_BYADDRESS                      0
#Define SORT_BYNAME                         1

#Define PERMANENT_NAME                      000000100H

ADDRESSINFO Struct
	Address DD
	Name DW MAX_NAME_SIZE Dup ?
	Flags DD
	lpAddressInstData DD
EndS

#Define ADDRESSINFO_SIZE                    SizeOf(ADDRESSINFO)

ADDRESSINFOTABLE Struct
	nAddressInfos DD
	lpAddressInfo DD
EndS

#Define ADDRESSINFOTABLE_SIZE               SizeOf(ADDRESSINFOTABLE)

#ENDIF ;BHTYPES_INC
