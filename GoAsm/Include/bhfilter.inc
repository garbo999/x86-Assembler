;=============================================================;
;         bhfilter.inc file for Easy Code visual IDE          ;
;            (made for the GoAsm compiler version)            ;
;                                                             ;
;           Version 1.0.00 (created on March, 2008)           ;
;                                                             ;
;      Please report any bug you find (asm@easycode.cat)      ;
;                                                             ;
;                Do not modify this file!!                    ;
;=============================================================;

#IFNDEF BHFILTER_INC
#Define BHFILTER_INC

#Define PROTOCOL_NUM_ANY                    (-1)

FILTEROBJECT Struct
	Action DD
	hProperty DD
	Union
		Value DD
		hProtocol DD
		lpArray DD
		lpProtocolTable DD
		lpAddress DD
		lpLargeInt DD
		lpTime DD
		lpOID DD
	EndUnion
	Union
		ByteCount DW
		ByteOffset DW
	EndUnion
	pNext DD
EndS

#Define FILTERINFO_SIZE                     SizeOf(FILTEROBJECT)

FILTERDESC Struct
	NumEntries DW
	Flags DW
	lpStack DD
	lpKeepLast DD
	UIInstanceData DD
	lpFilterBits DD
	lpCheckBits DD
EndS

#Define FILTERDESC_SIZE                     SizeOf(FILTERDESC)

#Define FILTERFREEPOOLSTART                 20

#Define INVALIDELEMENT                      (-1)
#Define INVALIDVALUE                        (-9999)

#Define FILTER_FAIL_WITH_ERROR              (-1)
#Define FILTER_PASSED                       TRUE
#Define FILTER_FAILED                       FALSE

#Define FILTERACTION_INVALID                0
#Define FILTERACTION_PROPERTY               1
#Define FILTERACTION_VALUE                  2
#Define FILTERACTION_STRING                 3
#Define FILTERACTION_ARRAY                  4
#Define FILTERACTION_AND                    5
#Define FILTERACTION_OR                     6
#Define FILTERACTION_XOR                    7
#Define FILTERACTION_PROPERTYEXIST          8
#Define FILTERACTION_CONTAINSNC             9
#Define FILTERACTION_CONTAINS               10
#Define FILTERACTION_NOT                    11
#Define FILTERACTION_EQUALNC                12
#Define FILTERACTION_EQUAL                  13
#Define FILTERACTION_NOTEQUALNC             14
#Define FILTERACTION_NOTEQUAL               15
#Define FILTERACTION_GREATERNC              16
#Define FILTERACTION_GREATER                17
#Define FILTERACTION_LESSNC                 18
#Define FILTERACTION_LESS                   19
#Define FILTERACTION_GREATEREQUALNC         20
#Define FILTERACTION_GREATEREQUAL           21
#Define FILTERACTION_LESSEQUALNC            22
#Define FILTERACTION_LESSEQUAL              23
#Define FILTERACTION_PLUS                   24
#Define FILTERACTION_MINUS                  25
#Define FILTERACTION_ADDRESS                26
#Define FILTERACTION_ADDRESSANY             27
#Define FILTERACTION_FROM                   28
#Define FILTERACTION_TO                     29
#Define FILTERACTION_FROMTO                 30
#Define FILTERACTION_AREBITSON              31
#Define FILTERACTION_AREBITSOFF             32
#Define FILTERACTION_PROTOCOLSEXIST         33
#Define FILTERACTION_PROTOCOLEXIST          34
#Define FILTERACTION_ARRAYEQUAL             35
#Define FILTERACTION_DEREFPROPERTY          36
#Define FILTERACTION_LARGEINT               37
#Define FILTERACTION_TIME                   38
#Define FILTERACTION_ADDR_ETHER             39
#Define FILTERACTION_ADDR_TOKEN             40
#Define FILTERACTION_ADDR_FDDI              41
#Define FILTERACTION_ADDR_IPX               42
#Define FILTERACTION_ADDR_IP                43
#Define FILTERACTION_OID                    44
#Define FILTERACTION_OID_CONTAINS           45
#Define FILTERACTION_OID_BEGINS_WITH        46
#Define FILTERACTION_OID_ENDS_WITH          47
#Define FILTERACTION_ADDR_VINES             48

#Define FILTERACTION_EXPRESSION             97
#Define FILTERACTION_BOOL                   98
#Define FILTERACTION_NOEVAL                 99


#Define FILTER_NO_MORE_FRAMES               0FFFFFFFFH
#Define FILTER_CANCELED                     0FFFFFFFEH
#Define FILTER_DIRECTION_NEXT               TRUE
#Define FILTER_DIRECTION_PREV               FALSE

#ENDIF ;BHFILTER_INC
