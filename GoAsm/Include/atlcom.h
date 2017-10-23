// This is a part of the Active Template Library.
// Copyright (C) 1996-1998 Microsoft Corporation
// All rights reserved.
//
// This source code is only intended as a supplement to the
// Active Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Active Template Library product.

#ifndef ATLCOM_H
#define ATLCOM_H

#ifndef ATLBASE_H
	#include atlbase.h
#endif

#define CComConnectionPointContainerImpl IConnectionPointContainerImpl
#define CComISupportErrorInfoImpl ISupportErrorInfoImpl
#define CComProvideClassInfo2Impl IProvideClassInfoImpl
#define CComDualImpl IDispatchImpl

ATL_PROPMAP_ENTRY STRUCT
	szDesc DD
	dispid DD
	pclsidPropPage PTR
	piidDispatch PTR
	dwOffsetData DD
	dwSizeData DD
	vt DW
ENDS

ATL_CREATORDATA STRUCT
	pFunc PTR
ENDS

ATL_CACHEDATA STRUCT
	dwOffsetVar DD
	pFunc PTR
ENDS

ATL_CHAINDATA STRUCT
	dwOffset DD
	pFunc PTR
ENDS

#endif // ATLCOM_H
