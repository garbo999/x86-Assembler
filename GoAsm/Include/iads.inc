;=============================================================;
;           iads.inc file for Easy Code visual IDE            ;
;            (made for the GoAsm compiler version)            ;
;                                                             ;
;         Version 1.0.00 (created on February, 2007)          ;
;                                                             ;
;      Please report any bug you find (asm@easycode.cat)      ;
;                                                             ;
;                Do not modify this file!!                    ;
;=============================================================;

#IFNDEF IADS_INC
#Define IADS_INC

;ADSTYPEENUM enumeration
ADSTYPE_INVALID							Equ 0
ADSTYPE_DN_STRING						Equ (ADSTYPE_INVALID + 1)
ADSTYPE_CASE_EXACT_STRING				Equ (ADSTYPE_DN_STRING + 1)
ADSTYPE_CASE_IGNORE_STRING				Equ (ADSTYPE_CASE_EXACT_STRING + 1)
ADSTYPE_PRINTABLE_STRING				Equ (ADSTYPE_CASE_IGNORE_STRING + 1)
ADSTYPE_NUMERIC_STRING					Equ (ADSTYPE_PRINTABLE_STRING + 1)
ADSTYPE_BOOLEAN							Equ (ADSTYPE_NUMERIC_STRING + 1)
ADSTYPE_INTEGER							Equ (ADSTYPE_BOOLEAN + 1)
ADSTYPE_OCTET_STRING					Equ (ADSTYPE_INTEGER + 1)
ADSTYPE_UTC_TIME						Equ (ADSTYPE_OCTET_STRING + 1)
ADSTYPE_LARGE_INTEGER					Equ (ADSTYPE_UTC_TIME + 1)
ADSTYPE_PROV_SPECIFIC					Equ (ADSTYPE_LARGE_INTEGER + 1)
ADSTYPE_OBJECT_CLASS					Equ (ADSTYPE_PROV_SPECIFIC + 1)

#Define ADS_SECURE_AUTHENTICATION		01H
#Define ADS_USE_ENCRYPTION				02H
#Define ADS_READONLY_SERVER				04H
#Define ADS_PROMPT_CREDENTIALS			08H
#Define ADS_ATTR_CLEAR					1
#Define ADS_ATTR_UPDATE					2
#Define ADS_ATTR_APPEND					3
#Define ADS_ATTR_DELETE					4

;ADS_STATUSENUM enumeration
ADS_STATUS_S_OK							Equ 0
ADS_STATUS_INVALID_SEARCHPREF			Equ (ADS_STATUS_S_OK + 1)
ADS_STATUS_INVALID_SEARCHPREFVALUE		Equ (ADS_STATUS_INVALID_SEARCHPREF + 1)

;ADS_DEREFENUM enumeration
ADS_DEREF_NEVER							Equ 0
ADS_DEREF_SEARCHING						Equ 1
ADS_DEREF_FINDING						Equ 2
ADS_DEREF_ALWAYS						Equ 3

;ADS_SCOPEENUM enumeration
ADS_SCOPE_BASE							Equ 0
ADS_SCOPE_ONELEVEL						Equ 1
ADS_SCOPE_SUBTREE						Equ 2

#Define ADS_CHASE_REFERRALS_NEVER		0
#Define ADS_CHASE_REFERRALS_SUBORDINATE	020H
#Define ADS_CHASE_REFERRALS_EXTERNAL	040H
#Define ADS_CHASE_REFERRALS_ALWAYS		(ADS_CHASE_REFERRALS_SUBORDINATE | ADS_CHASE_REFERRALS_EXTERNAL)

;ADS_SEARCHPREF_ENUM enumeration
ADS_SEARCHPREF_ASYNCHRONOUS				Equ 0
ADS_SEARCHPREF_DEREF_ALIASES			Equ (ADS_SEARCHPREF_ASYNCHRONOUS + 1)
ADS_SEARCHPREF_SIZE_LIMIT				Equ (ADS_SEARCHPREF_DEREF_ALIASES + 1)
ADS_SEARCHPREF_TIME_LIMIT				Equ (ADS_SEARCHPREF_SIZE_LIMIT + 1)
ADS_SEARCHPREF_ATTRIBTYPES_ONLY			Equ (ADS_SEARCHPREF_TIME_LIMIT + 1)
ADS_SEARCHPREF_SEARCH_SCOPE				Equ (ADS_SEARCHPREF_ATTRIBTYPES_ONLY + 1)
ADS_SEARCHPREF_TIMEOUT					Equ (ADS_SEARCHPREF_SEARCH_SCOPE + 1)
ADS_SEARCHPREF_PAGESIZE					Equ (ADS_SEARCHPREF_TIMEOUT + 1)
ADS_SEARCHPREF_PAGED_TIME_LIMIT			Equ (ADS_SEARCHPREF_PAGESIZE + 1)
ADS_SEARCHPREF_CHASE_REFERRALS			Equ (ADS_SEARCHPREF_PAGED_TIME_LIMIT + 1)
ADS_SEARCHPREF_SORT_ON					Equ (ADS_SEARCHPREF_CHASE_REFERRALS + 1)

;__MIDL___MIDL__intf_0000_0009 enumeration
ADS_PROPERTY_CLEAR						Equ 1
ADS_PROPERTY_UPDATE						Equ 2
ADS_PROPERTY_APPEND						Equ 3
ADS_PROPERTY_DELETE						Equ 4

;__MIDL___MIDL__intf_0115_0001 enumeration
ADS_SETTYPE_FULL						Equ 1
ADS_SETTYPE_PROVIDER					Equ 2
ADS_SETTYPE_SERVER						Equ 3
ADS_SETTYPE_DN							Equ 4

;__MIDL___MIDL__intf_0115_0002 enumeration
ADS_FORMAT_WINDOWS						Equ 1
ADS_FORMAT_WINDOWS_NO_SERVER			Equ 2
ADS_FORMAT_WINDOWS_DN					Equ 3
ADS_FORMAT_WINDOWS_PARENT				Equ 4
ADS_FORMAT_X500							Equ 5
ADS_FORMAT_X500_NO_SERVER				Equ 6
ADS_FORMAT_X500_DN						Equ 7
ADS_FORMAT_X500_PARENT					Equ 8
ADS_FORMAT_SERVER						Equ 9
ADS_FORMAT_PROVIDER						Equ 10
ADS_FORMAT_LEAF							Equ 11

;__MIDL___MIDL__intf_0115_0003 enumeration
ADS_DISPLAY_FULL						Equ 1
ADS_DISPLAY_VALUE_ONLY					Equ 2


ADS_OCTET_STRING Struct
	dwLength DD
	lpValue DD
EndS

ADS_PROV_SPECIFIC Struct
	dwLength DD
	lpValue DD
EndS

ADSVALUE Struct
    ADSTYPE dwType DD
	Union
		DNString DD
		CaseExactString DD
		CaseIgnoreString DD
		PrintableString DD
		NumericString DD
		Boolean DD
		Integer DD
		OctetString ADS_OCTET_STRING <>
		UTCTime SYSTEMTIME <>
		LargeInteger LARGE_INTEGER <>
		ClassName DD
		ProviderSpecific ADS_PROV_SPECIFIC <>
	EndUnion
EndS

ADS_ATTR_INFO Struct
	pszAttrName DD
	dwControlCode DD
    dwADsType DD
	pADsValues DD
	dwNumValues DD
EndS

ADS_OBJECT_INFO Struct
	pszRDN DD
	pszObjectDN DD
	pszParentDN DD
	pszSchemaDN DD
	pszClassName DD
EndS

ADS_SEARCHPREF_INFO Struct
	dwSearchPref DD
	vValue ADSVALUE <>
	dwStatus DD
EndS

ADS_SEARCH_COLUMN Struct
	pszAttrName DD
	dwADsType DD
	pADsValues DD
	dwNumValues DD
	hReserved DD
EndS

ADS_ATTR_DEF Struct
	pszAttrName DD
	dwADsType DD
	dwMinRange DD
	dwMaxRange DD
	fMultiValued DD
EndS

ADS_SORTKEY Struct
	pszAttrType DD
	pszReserved DD
	fReverseorder DB
EndS

#ENDIF _IADS_INC
