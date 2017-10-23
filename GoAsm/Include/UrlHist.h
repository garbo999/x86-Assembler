#IFNDEF URLHIST_H
#DEFINE URLHIST_H

/* header files for imported files */
#IFNDEF OBJIDL_H
	#include "objidl.h"
#ENDIF
#IFNDEF OLEIDL_H
	#include "oleidl.h"
#ENDIF
#IFNDEF OAIDL_H
	#include "oaidl.h"
#ENDIF
#IFNDEF DOCOBJ_H
	#include "docobj.h"
#ENDIF

#IFNDEF BASECOM_H
	#include "BaseCOM.h"
#ENDIF

#define STATURL_QUERYFLAG_ISCACHED 0x00010000
#define STATURL_QUERYFLAG_NOURL 0x00020000
#define STATURL_QUERYFLAG_NOTITLE 0x00040000
#define STATURL_QUERYFLAG_TOPLEVEL 0x00080000
#define STATURLFLAG_ISCACHED 0x00000001
#define STATURLFLAG_ISTOPLEVEL 0x00000002

ADDURL_FIRST	= 0
ADDURL_ADDTOHISTORYANDCACHE	= 0
ADDURL_ADDTOCACHE	= 1
ADDURL_Max	= 2147483647

STATURL STRUCT
	cbSize DD
	pwcsUrl PTR
	pwcsTitle PTR
	ftLastVisited FILETIME
	ftLastUpdated FILETIME
	ftExpires FILETIME
	dwFlags DD
ENDS

#DEFINE GUID_IID_IEnumSTATURL <0x3C374A42,0xBAE4,0x11CF,<0xBF,0x7D,0x00,0xAA,0x00,0x69,0x46,0xEE>>

IEnumSTATURL STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	Next PTR
	Skip PTR
	Reset PTR
	Clone PTR
	SetFilter PTR
ENDS

#DEFINE GUID_IID_IUrlHistoryStg <0x3C374A41,0xBAE4,0x11CF,<0xBF,0x7D,0x00,0xAA,0x00,0x69,0x46,0xEE>>

IUrlHistoryStg STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	AddUrl PTR
	DeleteUrl PTR
	QueryUrl PTR
	BindToObject PTR
	EnumUrls PTR
ENDS

#DEFINE GUID_IID_IUrlHistoryStg2 <0xAFA0DC11,0xC313,0x11d0,<0x83,0x1A,0x00,0xC0,0x4F,0xD5,0xAE,0x38>>

IUrlHistoryStg2 STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	AddUrl PTR
	DeleteUrl PTR
	QueryUrl PTR
	BindToObject PTR
	EnumUrls PTR
	AddUrlAndNotify PTR
	ClearHistory PTR
ENDS

#DEFINE GUID_IID_IUrlHistoryNotify <0xBC40BEC1,0xC493,0x11d0,<0x83,0x1B,0x00,0xC0,0x4F,0xD5,0xAE,0x38>>

IUrlHistoryNotify STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	QueryStatus PTR
	Exec PTR
ENDS

#endif



