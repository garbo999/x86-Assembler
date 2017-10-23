#ifndef MAPIX_H
#define MAPIX_H

/* Extended Messaging Applications Programming Interface (MAPI) definitions */

#IFNDEF MAPIDEFS_H
	#include "mapidefs.h"
#ENDIF

#IFNDEF MAPICODE_H
	#include "mapicode.h"
#ENDIF

#IFNDEF MAPIGUID_H
	#include "mapiguid.h"
#ENDIF

#IFNDEF MAPITAGS_H
	#include "mapitags.h"
#ENDIF

#IFNDEF BASECOM_H
	#include "BaseCOM.h"
#ENDIF

#define MAPI_LOGON_UI  0x00000001
#define MAPI_NEW_SESSION  0x00000002
#define MAPI_ALLOW_OTHERS  0x00000008
#define MAPI_EXPLICIT_PROFILE  0x00000010
#define MAPI_EXTENDED  0x00000020
#define MAPI_FORCE_DOWNLOAD  0x00001000
#define MAPI_SERVICE_UI_ALWAYS  0x00002000
#define MAPI_NO_MAIL  0x00008000
#ifndef MAPI_PASSWORD_UI
#define MAPI_PASSWORD_UI  0x00020000
#endif
#define MAPI_TIMEOUT_SHORT  0x00100000

#define MAPI_SIMPLE_DEFAULT  (MAPI_LOGON_UI|MAPI_FORCE_DOWNLOAD|MAPI_ALLOW_OTHERS)
#define MAPI_SIMPLE_EXPLICIT  (MAPI_NEW_SESSION|MAPI_FORCE_DOWNLOAD|MAPI_EXPLICIT_PROFILE)

#define MAPI_INIT_VERSION  0

#define MAPI_MULTITHREAD_NOTIFICATIONS  0x00000001

#define MAPI_LOGOFF_SHARED  0x00000001
#define MAPI_LOGOFF_UI  0x00000002

#define MAPI_DEFAULT_STORE  0x00000001
#define MAPI_SIMPLE_STORE_TEMPORARY  0x00000002
#define MAPI_SIMPLE_STORE_PERMANENT  0x00000003
#define MAPI_PRIMARY_STORE  0x00000004
#define MAPI_SECONDARY_STORE  0x00000005

#define MAPI_POST_MESSAGE  0x00000001
#define MAPI_NEW_MESSAGE  0x00000002

#define MAPI_DEFAULT_SERVICES  0x00000001

#define SERVICE_DEFAULT_STORE  0x00000001
#define SERVICE_SINGLE_COPY  0x00000002
#define SERVICE_CREATE_WITH_STORE  0x00000004
#define SERVICE_PRIMARY_IDENTITY  0x00000008
#define SERVICE_NO_PRIMARY_IDENTITY  0x00000020

MAPIINIT_0 STRUCT
	ulVersion DD
	ulFlags DD
ENDS

IMAPISession STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetLastError PTR
	GetMsgStoresTable PTR
	OpenMsgStore PTR
	OpenAddressBook PTR
	OpenProfileSection PTR
	GetStatusTable PTR
	OpenEntry PTR
	CompareEntryIDs PTR
	Advise PTR
	Unadvise PTR
	MessageOptions PTR
	QueryDefaultMessageOpt PTR
	EnumAdrTypes PTR
	QueryIdentity PTR
	Logoff PTR
	SetDefaultStore PTR
	AdminServices PTR
	ShowForm PTR
	PrepareForm PTR
ENDS

IAddrBook STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	OpenEntry PTR
	CompareEntryIDs PTR
	Advise PTR
	Unadvise PTR
	CreateOneOff PTR
	NewEntry PTR
	ResolveName PTR
	Address PTR
	Details PTR
	RecipOptions PTR
	QueryDefaultRecipOpt PTR
	GetPAB PTR
	SetPAB PTR
	GetDefaultDir PTR
	SetDefaultDir PTR
	GetSearchPath PTR
	SetSearchPath PTR
	PrepareRecips PTR
ENDS

IProfAdmin STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetLastError PTR
	GetProfileTable PTR
	CreateProfile PTR
	DeleteProfile PTR
	ChangeProfilePassword PTR
	CopyProfile PTR
	RenameProfile PTR
	SetDefaultProfile PTR
	AdminServices PTR
ENDS

IMsgServiceAdmin STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetLastError PTR
	GetMsgServiceTable PTR
	CreateMsgService PTR
	DeleteMsgService PTR
	CopyMsgService PTR
	RenameMsgService PTR
	ConfigureMsgService PTR
	OpenProfileSection PTR
	MsgServiceTransportOrder PTR
	AdminProviders PTR
	SetPrimaryIdentity PTR
	GetProviderTable PTR
ENDS

#endif /* _MAPIX_H */
