;=============================================================;
;            ole.inc file for Easy Code visual IDE            ;
;            (made for the GoAsm compiler version)            ;
;                                                             ;
;         Version 1.0.00 (created on February, 2007)          ;
;                                                             ;
;      Please report any bug you find (asm@easycode.cat)      ;
;                                                             ;
;                Do not modify this file!!                    ;
;=============================================================;

#IFNDEF OLE_INC
#Define OLE_INC

#Define OT_LINK             		1
#Define OT_EMBEDDED         		2
#Define OT_STATIC           		3

#Define OLEVERB_PRIMARY     		0

#Define OF_SET              		00001H
#Define OF_GET              		00002H
#Define OF_HANDLER          		00004H

;OLESTATUS enumeration
OLE_OK								Equ 0
OLE_WAIT_FOR_RELEASE				Equ 1
OLE_BUSY							Equ 2
OLE_ERROR_PROTECT_ONLY				Equ 3
OLE_ERROR_MEMORY					Equ 4
OLE_ERROR_STREAM					Equ 5
OLE_ERROR_STATIC					Equ 6
OLE_ERROR_BLANK						Equ 7
OLE_ERROR_DRAW						Equ 8
OLE_ERROR_METAFILE					Equ 9
OLE_ERROR_ABORT						Equ 10
OLE_ERROR_CLIPBOARD					Equ 11
OLE_ERROR_FORMAT					Equ 12
OLE_ERROR_OBJECT					Equ 13
OLE_ERROR_OPTION					Equ 14
OLE_ERROR_PROTOCOL					Equ 15
OLE_ERROR_ADDRESS					Equ 16
OLE_ERROR_NOT_EQUAL					Equ 17
OLE_ERROR_HANDLE					Equ 18
OLE_ERROR_GENERIC					Equ 19
OLE_ERROR_CLASS						Equ 20
OLE_ERROR_SYNTAX					Equ 21
OLE_ERROR_DATATYPE					Equ 22
OLE_ERROR_PALETTE					Equ 23
OLE_ERROR_NOT_LINK					Equ 24
OLE_ERROR_NOT_EMPTY					Equ 25
OLE_ERROR_SIZE						Equ 26
OLE_ERROR_DRIVE						Equ 27
OLE_ERROR_NETWORK					Equ 28
OLE_ERROR_NAME						Equ 29
OLE_ERROR_TEMPLATE					Equ 30
OLE_ERROR_NEW						Equ 31
OLE_ERROR_EDIT						Equ 32
OLE_ERROR_OPEN						Equ 33
OLE_ERROR_NOT_OPEN					Equ 34
OLE_ERROR_LAUNCH					Equ 35
OLE_ERROR_COMM						Equ 36
OLE_ERROR_TERMINATE					Equ 37
OLE_ERROR_COMMAND					Equ 38
OLE_ERROR_SHOW						Equ 39
OLE_ERROR_DOVERB					Equ 40
OLE_ERROR_ADVISE_NATIVE				Equ 41
OLE_ERROR_ADVISE_PICT				Equ 42
OLE_ERROR_ADVISE_RENAME				Equ 43
OLE_ERROR_POKE_NATIVE				Equ 44
OLE_ERROR_REQUEST_NATIVE			Equ 45
OLE_ERROR_REQUEST_PICT				Equ 46
OLE_ERROR_SERVER_BLOCKED			Equ 47
OLE_ERROR_REGISTRATION				Equ 48
OLE_ERROR_ALREADY_REGISTERED		Equ 49
OLE_ERROR_TASK						Equ 50
OLE_ERROR_OUTOFDATE					Equ 51
OLE_ERROR_CANT_UPDATE_CLIENT		Equ 52
OLE_ERROR_UPDATE					Equ 53
OLE_ERROR_SETDATA_FORMAT			Equ 54
OLE_ERROR_STATIC_FROM_OTHER_OS		Equ 55
OLE_ERROR_FILE_VER					Equ 56

OLE_WARN_DELETE_DATA				Equ 1000

;OLE_NOTIFICATION enumeration
OLE_CHANGED							Equ 0
OLE_SAVED							Equ 1
OLE_CLOSED							Equ 2
OLE_RENAMED							Equ 3
OLE_QUERY_PAINT						Equ 4
OLE_RELEASE							Equ 5
OLE_QUERY_RETRY						Equ 6

;OLE_RELEASE_METHOD enumeration
OLE_NONE							Equ 0
OLE_DELETE							Equ 1
OLE_LNKPASTE						Equ 2
OLE_EMBPASTE						Equ 3
OLE_SHOW							Equ 4
OLE_RUN								Equ 5
OLE_ACTIVATE						Equ 6
OLE_UPDATE							Equ 7
OLE_CLOSE							Equ 8
OLE_RECONNECT						Equ 9
OLE_SETUPDATEOPTIONS				Equ 10
OLE_SERVERUNLAUNCH					Equ 11
OLE_LOADFROMSTREAM					Equ 12
OLE_SETDATA							Equ 13
OLE_REQUESTDATA						Equ 14
OLE_OTHER							Equ 15
OLE_CREATE							Equ 16
OLE_CREATEFROMTEMPLATE				Equ 17
OLE_CREATELINKFROMFILE				Equ 18
OLE_COPYFROMLNK						Equ 19
OLE_CREATEFROMFILE					Equ 20
OLE_CREATEINVISIBLE					Equ 21

;OLEOPT_RENDER enumeration
olerender_none						Equ 0
olerender_draw						Equ 1
olerender_format					Equ 2

;OLEOPT_UPDATE enumeration
oleupdate_always					Equ 0
oleupdate_onsave					Equ 1
oleupdate_oncall					Equ 2
oleupdate_onclose					Equ 3

;OLE_SERVER_USE enumeration
OLE_SERVER_MULTI					Equ 0
OLE_SERVER_SINGLE					Equ 1


OLETARGETDEVICE	Struct
	otdDeviceNameOffset DW
	otdDriverNameOffset DW
	otdPortNameOffset DW
	otdExtDevmodeOffset DW
	otdExtDevmodeSize DW
	otdEnvironmentOffset DW
	otdEnvironmentSize DW
	otdData	DB
EndS

OLEOBJECT Struct
	lpvtbl DD
EndS

OLECLIENT Struct
	lpvtbl DD
EndS

OLESTREAM Struct
	lpstbl DD
EndS

OLESERVER Struct
	lpvtbl DD
EndS

OLESERVERDOC Struct
	lpvtbl DD
EndS

#ENDIF ;OLE_INC
