#ifndef PERHIST_H
#define PERHIST_H

#IFNDEF RPC_H
	#include "rpc.h"
#ENDIF
#IFNDEF RPCNDR_H
	#include "rpcndr.h"
#ENDIF

#ifndef COM_NO_WINDOWS_H
	#IFNDEF WINDOWS_H
		#include "windows.h"
	#ENDIF
	#IFNDEF OLE2_H
		#include "ole2.h"
	#ENDIF
#endif /*COM_NO_WINDOWS_H*/


/* header files for imported files */
#IFNDEF OBJIDL_H
#inc	lude "objidl.h"
#ENDIF

#IFNDEF OLEIDL_H
	#include "oleidl.h"
#ENDIF

#IFNDEF BASECOM_H
	#include "BaseCOM.h"
#ENDIF

/* interface __MIDL_itf_perhist_0000_0000 */
/* [local] */ 

//=--------------------------------------------------------------------------=
// perhist.h
//=--------------------------------------------------------------------------=
// (C) Copyright 1995-1998 Microsoft Corporation.  All Rights Reserved.
//
// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
// PARTICULAR PURPOSE.
//=--------------------------------------------------------------------------=


//---------------------------------------------------------------------------=
// IPersistHistory Interface.


#DEFINE GUID_IID_IPersistHistory <0x1A565C1,0xE38F,0x11d0,<0x94,0xBF,0x00,0xA0,0xC9,0x05,0x5C,0xBF>>

IPersistHistory STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetClassID PTR
	LoadHistory PTR
	SaveHistory PTR
	SetPositionCookie PTR
	GetPositionCookie PTR
ENDS

#endif



