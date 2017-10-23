#ifndef OBJIDL_H
#define OBJIDL_H

#IFNDEF RPC_H
	#include "rpc.h"
#ENDIF

#IFNDEF RPCNDR_H
	#include "rpcndr.h"
#ENDIF

#IFNDEF OLE2_H
	#include "ole2.h"
#ENDIF

#IFNDEF BASECOM_H
	#include "BaseCOM.h"
#ENDIF

#DEFINE OBJIDL_H_REQVER 100

/*
Dependancies
rpc.h
rpcndr.h
ole2.h
*/

/*
Switches used
None
*/

#IFNDEF FILETIME
	FILETIME STRUCT
		dwLowDateTime DD
		dwHighDateTime DD
	ENDS
#ENDIF

/* This is define in BaseCOM.h
#IFNDEF GUID_IID_IUnknown
	#define GUID_IID_IUnknown <0x00000000,0x0000,0x0000,<0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46>>
#ENDIF
*/

/* This is define in BaseCOM.h
#IFNDEF GUID_IID_IClassFactory
	#define GUID_IID_IClassFactory <0x00000001,0x0000,0x0000,<0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46>>
#ENDIF
*/

#define GUID_IID_IMarshal <0x00000003, 0x0000, 0x0000, <0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46>>
#define GUID_IID_IMarshal2 <0x000001cf, 0x0000, 0x0000, <0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46>>
#define GUID_IID_IMalloc <0x00000002, 0x0000, 0x0000, <0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46>>
#define GUID_IID_IMallocSpy <0x0000001d, 0x0000, 0x0000, <0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46>>
#define GUID_IID_IStdMarshalInfo <0x00000018, 0x0000, 0x0000, <0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46>>
#define GUID_IID_IExternalConnection <0x00000019, 0x0000, 0x0000, <0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46>>
#define GUID_IID_IMultiQI <0x00000020, 0x0000, 0x0000, <0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46>>
#define GUID_IID_AsyncIMultiQI <0x000e0020, 0x0000, 0x0000, <0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46>>
#define GUID_IID_IInternalUnknown <0x00000021, 0x0000, 0x0000, <0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46>>
#define GUID_IID_IEnumUnknown <0x00000100, 0x0000, 0x0000, <0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46>>
#define GUID_IID_IBindCtx <0x0000000e, 0x0000, 0x0000, <0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46>>
#define GUID_IID_IEnumMoniker <0x00000102, 0x0000, 0x0000, <0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46>>
#define GUID_IID_IRunnableObject <0x00000126, 0x0000, 0x0000, <0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46>>
#define GUID_IID_IRunningObjectTable <0x00000010, 0x0000, 0x0000, <0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46>>
#define GUID_IID_IPersist <0x0000010c, 0x0000, 0x0000, <0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46>>
#define GUID_IID_IPersistStream <0x00000109, 0x0000, 0x0000, <0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46>>
#define GUID_IID_IMoniker <0x0000000f, 0x0000, 0x0000, <0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46>>
#define GUID_IID_IEnumString <0x00000101, 0x0000, 0x0000, <0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46>>
#define GUID_IID_IStream <0x0000000c, 0x0000, 0x0000, <0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46>>
#define GUID_IID_IEnumSTATSTG <0x0000000d, 0x0000, 0x0000, <0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46>>
#define GUID_IID_IStorage <0x0000000b, 0x0000, 0x0000, <0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46>>
#define GUID_IID_IPersistFile <0x0000010b, 0x0000, 0x0000, <0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46>>
#define GUID_IID_IPersistStorage <0x0000010a, 0x0000, 0x0000, <0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46>>
#define GUID_IID_ILockBytes <0x0000000a, 0x0000, 0x0000, <0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46>>
#define GUID_IID_IEnumFORMATETC <0x00000103, 0x0000, 0x0000, <0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46>>
#define GUID_IID_IEnumSTATDATA <0x00000105, 0x0000, 0x0000, <0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46>>
#define GUID_IID_IRootStorage <0x00000012, 0x0000, 0x0000, <0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46>>
#define GUID_IID_IAdviseSink <0x0000010f, 0x0000, 0x0000, <0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46>>
#define GUID_IID_AsyncIAdviseSink <0x00000150, 0x0000, 0x0000, <0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46>>
#define GUID_IID_IAdviseSink2 <0x00000125, 0x0000, 0x0000, <0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46>>
#define GUID_IID_AsyncIAdviseSink2 <0x00000151, 0x0000, 0x0000, <0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46>>
#define GUID_IID_IDataObject <0x0000010e, 0x0000, 0x0000, <0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46>>
#define GUID_IID_IDataAdviseHolder <0x00000110, 0x0000, 0x0000, <0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46>>
#define GUID_IID_IMessageFilter <0x00000016, 0x0000, 0x0000, <0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46>>
#define GUID_IID_IClientSecurity <0x0000013D, 0x0000, 0x0000, <0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46>>
#define GUID_IID_IServerSecurity <0x0000013E, 0x0000, 0x0000, <0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46>>
#define GUID_IID_IClassActivator <0x00000140, 0x0000, 0x0000, <0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46>>
#define GUID_IID_ISurrogate <0x00000022, 0x0000, 0x0000, <0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46>>
#define GUID_IID_IGlobalInterfaceTable <0x00000146, 0x0000, 0x0000, <0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46>>
#define GUID_IID_ISynchronize <0x00000030, 0x0000, 0x0000, <0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46>>
#define GUID_IID_ISynchronizeHandle <0x00000031, 0x0000, 0x0000, <0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46>>
#define GUID_IID_ISynchronizeEvent <0x00000032, 0x0000, 0x0000, <0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46>>
#define GUID_IID_ISynchronizeContainer <0x00000033, 0x0000, 0x0000, <0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46>>
#define GUID_IID_ISynchronizeMutex <0x00000025, 0x0000, 0x0000, <0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46>>
#define GUID_IID_ICancelMethodCalls <0x00000029, 0x0000, 0x0000, <0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46>>
#define GUID_IID_IAsyncManager <0x0000002A, 0x0000, 0x0000, <0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46>>
#define GUID_IID_IRpcHelper <0x00000149, 0x0000, 0x0000, <0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46>>
#define GUID_IID_IRpcOptions <0x00000144, 0x0000, 0x0000, <0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46>>
#define GUID_IID_IWaitMultiple <0x0000002B, 0x0000, 0x0000, <0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46>>
#define GUID_IID_IUrlMon <0x00000026, 0x0000, 0x0000, <0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46>>
#define GUID_IID_IForegroundTransfer <0x00000145, 0x0000, 0x0000, <0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46>>
#define GUID_IID_ISequentialStream <0x0c733a30, 0x2a1c, 0x11ce, <0xad, 0xe5, 0x00, 0xaa, 0x00, 0x44, 0x77, 0x3d>>

#define GUID_IID_ICallFactory <0x1c733a30, 0x2a1c, 0x11ce, <0xad, 0xe5, 0x00, 0xaa, 0x00, 0x44, 0x77, 0x3d>>
#define GUID_IID_IDirectWriterLock <0x0e6d4d92, 0x6738, 0x11cf, <0x96, 0x08, 0x00, 0xaa, 0x00, 0x68, 0x0d, 0xb4>>
#define GUID_IID_IROTData <0xf29f6bc0, 0x5021, 0x11ce, <0xaa, 0x15, 0x00, 0x00, 0x69, 0x01, 0x29, 0x3f>>
#define GUID_IID_IReleaseMarshalBuffers <0xeb0cb9e8, 0x7996, 0x11d2, <0x87, 0x2e, 0x00, 0x00, 0xf8, 0x08, 0x08, 0x59>>
#define GUID_IID_IPipeByte <0xDB2F3ACA, 0x2F86, 0x11d1, <0x8E, 0x04, 0x00, 0xC0, 0x4F, 0xB9, 0x98, 0x9A>>
#define GUID_IID_AsyncIPipeByte <0xDB2F3ACB, 0x2F86, 0x11d1, <0x8E, 0x04, 0x00, 0xC0, 0x4F, 0xB9, 0x98, 0x9A>>
#define GUID_IID_IPipeLong <0xDB2F3ACC, 0x2F86, 0x11d1, <0x8E, 0x04, 0x00, 0xC0, 0x4F, 0xB9, 0x98, 0x9A>>
#define GUID_IID_AsyncIPipeLong <0xDB2F3ACD, 0x2F86, 0x11d1, <0x8E, 0x04, 0x00, 0xC0, 0x4F, 0xB9, 0x98, 0x9A>>
#define GUID_IID_IPipeDouble <0xDB2F3ACE, 0x2F86, 0x11d1, <0x8E, 0x04, 0x00, 0xC0, 0x4F, 0xB9, 0x98, 0x9A>>
#define GUID_IID_AsyncIPipeDouble <0xDB2F3ACF, 0x2F86, 0x11d1, <0x8E, 0x04, 0x00, 0xC0, 0x4F, 0xB9, 0x98, 0x9A>>
#define GUID_IID_IThumbnailExtractor <0x969dc708, 0x5c76, 0x11d1, <0x8d, 0x86, 0x00, 0x00, 0xf8, 0x04, 0xb0, 0x57>>
#define GUID_IID_IDummyHICONIncluder <0x947990de, 0xcc28, 0x11d2, <0xa0, 0xf7, 0x00, 0x80, 0x5f, 0x85, 0x8f, 0xb1>>
#define GUID_IID_IRpcChannelBuffer <0xD5F56B60, 0x593B, 0x101A, <0xB5, 0x69, 0x08, 0x00, 0x2B, 0x2D, 0xBF, 0x7A>>
#define GUID_IID_IRpcChannelBuffer2 <0x594f31d0, 0x7f19, 0x11d0, <0xb1, 0x94, 0x00, 0xa0, 0xc9, 0x0d, 0xc8, 0xbf>>
#define GUID_IID_IAsyncRpcChannelBuffer <0xa5029fb6, 0x3c34, 0x11d1, <0x9c, 0x99, 0x00, 0xc0, 0x4f, 0xb9, 0x98, 0xaa>>
#define GUID_IID_IRpcChannelBuffer3 <0x25B15600, 0x0115, 0x11d0, <0xBF, 0x0D, 0x00, 0xAA, 0x00, 0xB8, 0xDF, 0xD2>>
#define GUID_IID_IRpcProxyBuffer <0xD5F56A34, 0x593B, 0x101A, <0xB5, 0x69, 0x08, 0x00, 0x2B, 0x2D, 0xBF, 0x7A>>
#define GUID_IID_IRpcStubBuffer <0xD5F56AFC, 0x593B, 0x101A, <0xB5, 0x69, 0x08, 0x00, 0x2B, 0x2D, 0xBF, 0x7A>>
#define GUID_IID_IPSFactoryBuffer <0xD5F569D0, 0x593B, 0x101A, <0xB5, 0x69, 0x08, 0x00, 0x2B, 0x2D, 0xBF, 0x7A>>
#define GUID_IID_IChannelHook <0x1008c4a0, 0x7613, 0x11cf, <0x9a, 0xf1, 0x00, 0x20, 0xaf, 0x6e, 0x72, 0xf4>>
#define GUID_IID_IFillLockBytes <0x99caf010, 0x415e, 0x11cf, <0x88, 0x14, 0x00, 0xaa, 0x00, 0xb5, 0x69, 0xf5>>
#define GUID_IID_IProgressNotify <0xa9d758a0, 0x4617, 0x11cf, <0x95, 0xfc, 0x00, 0xaa, 0x00, 0x68, 0x0d, 0xb4>>
#define GUID_IID_ILayoutStorage <0x0e6d4d90, 0x6738, 0x11cf, <0x96, 0x08, 0x00, 0xaa, 0x00, 0x68, 0x0d, 0xb4>>
#define GUID_IID_IBlockingLock <0x30f3d47a, 0x6447, 0x11d1, <0x8e, 0x3c, 0x00, 0xc0, 0x4f, 0xb9, 0x38, 0x6d>>
#define GUID_IID_ITimeAndNoticeControl <0xbc0bf6ae, 0x8878, 0x11d1, <0x83, 0xe9, 0x00, 0xc0, 0x4f, 0xc2, 0xc6, 0xd4>>
#define GUID_IID_IOplockStorage <0x8d19c834, 0x8879, 0x11d1, <0x83, 0xe9, 0x00, 0xc0, 0x4f, 0xc2, 0xc6, 0xd4>>

COSERVERINFO STRUCT
	dwReserved1 DD
	pwszName PTR
	pAuthInfo PTR
	dwReserved2 DD
ENDS

;MIDL_IMarshal("00000003-0000-0000-C000-000000000046")

IMarshal STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetUnmarshalClass PTR
	GetMarshalSizeMax PTR
	MarshalInterface PTR
	UnmarshalInterface PTR
	ReleaseMarshalData PTR
	DisconnectObject PTR
ENDS

;MIDL_IMarshal2("000001cf-0000-0000-C000-000000000046")

IMarshal2 STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetUnmarshalClass PTR
	GetMarshalSizeMax PTR
	MarshalInterface PTR
	UnmarshalInterface PTR
	ReleaseMarshalData PTR
	DisconnectObject PTR
ENDS

;MIDL_IMalloc("00000002-0000-0000-C000-000000000046")

IMalloc STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	Alloc PTR
	Realloc PTR
	Free PTR
	GetSize PTR
	DidAlloc PTR
	HeapMinimize PTR
ENDS

;MIDL_IMallocSpy("0000001d-0000-0000-C000-000000000046")

IMallocSpy STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	PreAlloc PTR
	PostAlloc PTR
	PreFree PTR
	PostFree PTR
	PreRealloc PTR
	PostRealloc PTR
	PreGetSize PTR
	PostGetSize PTR
	PreDidAlloc PTR
	PostDidAlloc PTR
	PreHeapMinimize PTR
	PostHeapMinimize PTR
ENDS

;MIDL_IStdMarshalInfo("00000018-0000-0000-C000-000000000046")

IStdMarshalInfo STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetClassForHandler PTR
ENDS

;MIDL_IExternalConnection("00000019-0000-0000-C000-000000000046")

IExternalConnection STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	AddConnection PTR
	ReleaseConnection PTR
ENDS

MULTI_QI STRUCT
	pIID PTR
	pItf PTR
	hr HANDLE
ENDS

;MIDL_IMultiQI("00000020-0000-0000-C000-000000000046")

IMultiQI STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	QueryMultipleInterfaces PTR
ENDS

;MIDL_AsyncIMultiQI("000e0020-0000-0000-C000-000000000046")

AsyncIMultiQI STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	Begin_QueryMultipleInterfaces PTR
	Finish_QueryMultipleInterfaces PTR
ENDS

;MIDL_IInternalUnknown("00000021-0000-0000-C000-000000000046")

IInternalUnknown STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	QueryInternalInterface PTR
ENDS

;MIDL_IEnumUnknown("00000100-0000-0000-C000-000000000046")

IEnumUnknown STRUCT
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
ENDS

BIND_OPTS STRUCT
	cbStruct DD
	grfFlags DD
	grfMode DD
	dwTickCountDeadline DD
ENDS

BIND_OPTS2 STRUCT
	cbStruct DD
	grfFlags DD
	grfMode DD
	dwTickCountDeadline DD
	dwTrackFlags DD
	dwClassContext DD
	locale LCID
	pServerInfo PTR
ENDS

BIND_OPTS3 STRUCT
	cbStruct DD
	grfFlags DD
	grfMode DD
	dwTickCountDeadline DD
	dwTrackFlags DD
	dwClassContext DD
	locale LCID
	pServerInfo PTR // to COSERVERINFO
	hwnd HANDLE
ENDS

;MIDL_IBindCtx("0000000e-0000-0000-C000-000000000046")

IBindCtx STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	RegisterObjectBound PTR
	RevokeObjectBound PTR
	ReleaseBoundObjects PTR
	SetBindOptions PTR
	GetBindOptions PTR
	GetRunningObjectTable PTR
	RegisterObjectParam PTR
	GetObjectParam PTR
	EnumObjectParam PTR
	RevokeObjectParam PTR
ENDS

;MIDL_IEnumMoniker("00000102-0000-0000-C000-000000000046")

IEnumMoniker STRUCT
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
ENDS

;MIDL_IRunnableObject("00000126-0000-0000-C000-000000000046")

IRunnableObject STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetRunningClass PTR
	Run PTR
	IsRunning PTR
	LockRunning PTR
	SetContainedObject PTR
ENDS

;MIDL_IRunningObjectTable("00000010-0000-0000-C000-000000000046")

IRunningObjectTable STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	Register PTR
	Revoke PTR
	IsRunning PTR
	GetObject PTR
	NoteChangeTime PTR
	GetTimeOfLastChange PTR
	EnumRunning PTR
ENDS

;MIDL_IPersist("0000010c-0000-0000-C000-000000000046")

IPersist STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetClassID PTR
ENDS

;MIDL_IPersistStream("00000109-0000-0000-C000-000000000046")

IPersistStream STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetClassID PTR
	IsDirty PTR
	Load PTR
	Save PTR
	GetSizeMax PTR
ENDS

MKSYS_NONE = 0
MKSYS_GENERICCOMPOSITE = 1
MKSYS_FILEMONIKER = 2
MKSYS_ANTIMONIKER = 3
MKSYS_ITEMMONIKER = 4
MKSYS_POINTERMONIKER = 5
MKSYS_CLASSMONIKER = 7
MKSYS_OBJREFMONIKER = 8
MKSYS_SESSIONMONIKER = 9

MKRREDUCE_ONE = 00030000h
MKRREDUCE_TOUSER = 00020000h
MKRREDUCE_THROUGHUSER = 00010000h
MKRREDUCE_ALL = 0

;MIDL_IMoniker("0000000f-0000-0000-C000-000000000046")

IMoniker STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetClassID PTR
	IsDirty PTR
	Load PTR
	Save PTR
	GetSizeMax PTR
	BindToObject PTR
	BindToStorage PTR
	Reduce PTR
	ComposeWith PTR
	Enum PTR
	IsEqual PTR
	Hash PTR
	IsRunning PTR
	GetTimeOfLastChange PTR
	Inverse PTR
	CommonPrefixWith PTR
	RelativePathTo PTR
	GetDisplayName PTR
	ParseDisplayName PTR
	IsSystemMoniker PTR
ENDS

;MIDL_IROTData("f29f6bc0-5021-11ce-aa15-00006901293f")

IROTData STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetComparisonData PTR
ENDS

;MIDL_IEnumString("00000101-0000-0000-C000-000000000046")

IEnumString STRUCT
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
ENDS

;MIDL_ISequentialStream("0c733a30-2a1c-11ce-ade5-00aa0044773d")

ISequentialStream STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	Read PTR
	Write PTR
ENDS

STATSTG STRUCT
	pwcsName PTR
	type DD
	cbSize DQ
	mtime FILETIME
	ctime FILETIME
	atime FILETIME
	grfMode DD
	grfLocksSupported DD
	clsid GUID
	grfStateBits DD
	reserved DD
ENDS

STGTY_STORAGE = 1
STGTY_STREAM = 2
STGTY_LOCKBYTES = 3
STGTY_PROPERTY = 4

STREAM_SEEK_SET = 0
STREAM_SEEK_CUR = 1
STREAM_SEEK_END = 2

LOCK_WRITE = 1
LOCK_EXCLUSIVE = 2
LOCK_ONLYONCE = 4

;MIDL_IStream("0000000c-0000-0000-C000-000000000046")

IStream STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	Read PTR
	Write PTR
	Seek PTR
	SetSize PTR
	CopyTo PTR
	Commit PTR
	Revert PTR
	LockRegion PTR
	UnlockRegion PTR
	Stat PTR
	Clone PTR
ENDS

;MIDL_IEnumSTATSTG("0000000d-0000-0000-C000-000000000046")

IEnumSTATSTG STRUCT
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
ENDS

RemSNB STRUCT
	ulCntStr DD
	ulCntChar DD
	rgString DW
ENDS

;MIDL_IStorage("0000000b-0000-0000-C000-000000000046")

IStorage STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	CreateStream PTR
	OpenStream PTR
	CreateStorage PTR
	OpenStorage PTR
	CopyTo PTR
	MoveElementTo PTR
	Commit PTR
	Revert PTR
	EnumElements PTR
	DestroyElement PTR
	RenameElement PTR
	SetElementTimes PTR
	SetClass PTR
	SetStateBits PTR
	Stat PTR
ENDS

;MIDL_IPersistFile("0000010b-0000-0000-C000-000000000046")

IPersistFile STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetClassID PTR
	IsDirty PTR
	Load PTR
	Save PTR
	SaveCompleted PTR
	GetCurFile PTR
ENDS

;MIDL_IPersistStorage("0000010a-0000-0000-C000-000000000046")

IPersistStorage STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetClassID PTR
	IsDirty PTR
	InitNew PTR
	Load PTR
	Save PTR
	SaveCompleted PTR
	HandsOffStorage PTR
ENDS

;MIDL_ILockBytes("0000000a-0000-0000-C000-000000000046")

ILockBytes STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	ReadAt PTR
	WriteAt PTR
	Flush PTR
	SetSize PTR
	LockRegion PTR
	UnlockRegion PTR
	Stat PTR
ENDS

DVTARGETDEVICE STRUCT
	tdSize DD
	tdDriverNameOffset DW
	tdDeviceNameOffset DW
	tdPortNameOffset DW
	tdExtDevmodeOffsetDW
	tdData DB
ENDS

FORMATETC STRUCT
	cfFormat DD
	ptd PTR
	dwAspect DD
	lindex DD
	tymed DD
ENDS

;MIDL_IEnumFORMATETC("00000103-0000-0000-C000-000000000046")

IEnumFORMATETC STRUCT
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
ENDS

ADVF_NODATA = 1
ADVF_PRIMEFIRST = 2
ADVF_ONLYONCE = 4
ADVF_DATAONSTOP = 64
ADVFCACHE_NOHANDLER = 8
ADVFCACHE_FORCEBUILTIN = 16
ADVFCACHE_ONSAVE = 32

STATDATA STRUCT
	formatetc FORMATETC
	advf PTR
	pAdvSink PTR
	dwConnection PTR
ENDS

;MIDL_IEnumSTATDATA("00000105-0000-0000-C000-000000000046")

IEnumSTATDATA STRUCT
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
ENDS

;MIDL_IRootStorage("00000012-0000-0000-C000-000000000046")

IRootStorage STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	SwitchToFile PTR
ENDS

TYMED_HGLOBAL = 1
TYMED_FILE = 2
TYMED_ISTREAM = 4
TYMED_ISTORAGE = 8
TYMED_GDI = 16
TYMED_MFPICT = 32
TYMED_ENHMF = 64
TYMED_NULL = 0

/*
STGMEDIUM STRUCT
	tymed DD
	dwHandleType DD
	pData DD
	pUnkForRelease DD
	cbData DD
	data DB
ENDS
*/

STGMEDIUM STRUCT
	tymed DD
	UNION
		hBitmap HANDLE
		hMetaFilePict HANDLE
		hEnhMetaFile HANDLE
		hGlobal HANDLE
		lpszFileName PTR
		pstm PTR
		pstg PTR
	ENDUNION
	pUnkForRelease PTR
ENDS

GDI_OBJECT STRUCT
	ObjectType DD
	UNION
		hBitmap HANDLE
		hPalette HANDLE
		hGeneric HANDLE
	ENDUNION
ENDS

userSTGMEDIUM STRUCT
	tymed DD
	UNION
		hMetaFilePict HANDLE
		hHEnhMetaFile HANDLE
		hGdiHandle HANDLE
		hGlobal HANDLE
		lpszFileName PTR
		pstm PTR
		pstg PTR
	ENDUNION
	pUnkForRelease PTR
ENDS

userFLAG_STGMEDIUM STRUCT
	ContextFlags DD
	fPassOwnership DD
	Stgmed userSTGMEDIUM
ENDS

FLAG_STGMEDIUM STRUCT
	ContextFlags DD
	fPassOwnership DD
	Stgmed STGMEDIUM
ENDS

;MIDL_IAdviseSink("0000010f-0000-0000-C000-000000000046")

IAdviseSink STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	OnDataChange PTR
	OnViewChange PTR
	OnRename PTR
	OnSave PTR
	OnClose PTR
ENDS

;MIDL_AsyncIAdviseSink("00000150-0000-0000-C000-000000000046")

AsyncIAdviseSink STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	Begin_OnDataChange PTR
	Finish_OnDataChange PTR
	Begin_OnViewChange PTR
	Finish_OnViewChange PTR
	Begin_OnRename PTR
	Finish_OnRename PTR
	Begin_OnSave PTR
	Finish_OnSave PTR
	Begin_OnClose PTR
	Finish_OnClose PTR
ENDS

;MIDL_IAdviseSink2("00000125-0000-0000-C000-000000000046")

IAdviseSink2 STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	OnDataChange PTR
	OnViewChange PTR
	OnRename PTR
	OnSave PTR
	OnClose PTR
	OnLinkSrcChange PTR
ENDS

;MIDL_AsyncIAdviseSink2("00000151-0000-0000-C000-000000000046")

AsyncIAdviseSink2 STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	Begin_OnDataChange PTR
	Finish_OnDataChange PTR
	Begin_OnViewChange PTR
	Finish_OnViewChange PTR
	Begin_OnRename PTR
	Finish_OnRename PTR
	Begin_OnSave PTR
	Finish_OnSave PTR
	Begin_OnClose PTR
	Finish_OnClose PTR
	Begin_OnLinkSrcChange PTR
	Finish_OnLinkSrcChange PTR
ENDS

DATADIR_GET = 1
DATADIR_SET = 2

;MIDL_IDataObject("0000010e-0000-0000-C000-000000000046")

IDataObject STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetData PTR
	GetDataHere PTR
	QueryGetData PTR
	GetCanonicalFormatEtc PTR
	SetData PTR
	EnumFormatEtc PTR
	DAdvise PTR
	DUnadvise PTR
	EnumDAdvise PTR
ENDS

;MIDL_IDataAdviseHolder("00000110-0000-0000-C000-000000000046")

IDataAdviseHolder STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	Advise PTR
	Unadvise PTR
	EnumAdvise PTR
	SendOnDataChange PTR
ENDS

CALLTYPE_TOPLEVEL = 1
CALLTYPE_NESTED = 2
CALLTYPE_ASYNC = 3
CALLTYPE_TOPLEVEL_CALLPENDING = 4
CALLTYPE_ASYNC_CALLPENDING = 5

SERVERCALL_ISHANDLED = 0
SERVERCALL_REJECTED = 1
SERVERCALL_RETRYLATER = 2

PENDINGTYPE_TOPLEVEL = 1
PENDINGTYPE_NESTED = 2

PENDINGMSG_CANCELCALL = 0
PENDINGMSG_WAITNOPROCESS = 1
PENDINGMSG_WAITDEFPROCESS = 2

INTERFACEINFO STRUCT
	pUnk PTR
	iid GUID
	wMethod DW
ENDS

;MIDL_IMessageFilter("00000016-0000-0000-C000-000000000046")

IMessageFilter STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	HandleInComingCall PTR
	RetryRejectedCall PTR
	MessagePending PTR
ENDS

RPCOLEMESSAGE STRUCT
	reserved1 PTR
	dataRepresentation DD
	Buffer PTR
	cbBuffer DD
	iMethod DD
	reserved2 PTR 5 DUP (?)
	rpcFlags DD
ENDS

;MIDL_IRpcChannelBuffer("D5F56B60-593B-101A-B569-08002B2DBF7A")

IRpcChannelBuffer STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetBuffer PTR
	SendReceive PTR
	FreeBuffer PTR
	GetDestCtx PTR
	IsConnected PTR
ENDS

;MIDL_IRpcChannelBuffer2("594f31d0-7f19-11d0-b194-00a0c90dc8bf")

IRpcChannelBuffer2 STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetBuffer PTR
	SendReceive PTR
	FreeBuffer PTR
	GetDestCtx PTR
	IsConnected PTR
	GetProtocolVersion PTR
ENDS

;MIDL_IAsyncRpcChannelBuffer("a5029fb6-3c34-11d1-9c99-00c04fb998aa")

IAsyncRpcChannelBuffer STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetBuffer PTR
	SendReceive PTR
	FreeBuffer PTR
	GetDestCtx PTR
	IsConnected PTR
	GetProtocolVersion PTR
	Send PTR
	Receive PTR
	GetDestCtxEx PTR
ENDS

;MIDL_IRpcChannelBuffer3("25B15600-0115-11d0-BF0D-00AA00B8DFD2")

IRpcChannelBuffer3 STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetBuffer PTR
	SendReceive PTR
	FreeBuffer PTR
	GetDestCtx PTR
	IsConnected PTR
	GetProtocolVersion PTR
	Send PTR
	Receive PTR
	Cancel PTR
	GetCallContext PTR
	GetDestCtxEx PTR
	GetState PTR
	RegisterAsync PTR
ENDS

;MIDL_IRpcProxyBuffer("D5F56A34-593B-101A-B569-08002B2DBF7A")

IRpcProxyBuffer STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	Connect PTR
	Disconnect PTR
ENDS

;MIDL_IRpcStubBuffer("D5F56AFC-593B-101A-B569-08002B2DBF7A")

IRpcStubBuffer STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	Connect PTR
	Disconnect PTR
	Invoke PTR
	IsIIDSupported PTR
	CountRefs PTR
	DebugServerQueryInterface PTR
	DebugServerRelease PTR
ENDS

;MIDL_IPSFactoryBuffer("D5F569D0-593B-101A-B569-08002B2DBF7A")

IPSFactoryBuffer STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	CreateProxy PTR
	CreateStub PTR
ENDS

SChannelHookCallInfo STRUCT
	iid GUID
	cbSize DD
	uCausality GUID
	dwServerPid DD
	iMethod DD
	pObject PTR
ENDS

;MIDL_IChannelHook("1008c4a0-7613-11cf-9af1-0020af6e72f4")

IChannelHook STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	ClientGetSize PTR
	ClientFillBuffer PTR
	ClientNotify PTR
	ServerNotify PTR
	ServerGetSize PTR
	ServerFillBuffer PTR
ENDS

SOLE_AUTHENTICATION_SERVICE STRUCT
	dwAuthnSvc DD
	dwAuthzSvc DD
	pPrincipalName PTR
	hr HANDLE
ENDS

EOAC_NONE = 0
EOAC_MUTUAL_AUTH = 0x1
EOAC_STATIC_CLOAKING = 0x20
EOAC_DYNAMIC_CLOAKING = 0x40
EOAC_ANY_AUTHORITY = 0x80
EOAC_MAKE_FULLSIC = 0x100
EOAC_DEFAULT = 0x800
EOAC_SECURE_REFS = 0x2
EOAC_ACCESS_CONTROL = 0x4
EOAC_APPID = 0x8
EOAC_DYNAMIC = 0x10
EOAC_REQUIRE_FULLSIC = 0x200
EOAC_AUTO_IMPERSONATE = 0x400
EOAC_NO_CUSTOM_MARSHAL = 0x2000
EOAC_DISABLE_AAA = 0x1000

#define COLE_DEFAULT_PRINCIPAL  (-1 )
#define COLE_DEFAULT_AUTHINFO  (-1 )

SOLE_AUTHENTICATION_INFO STRUCT
	dwAuthnSvc DD
	dwAuthzSvc DD
	pAuthInfo PTR
ENDS

SOLE_AUTHENTICATION_LIST STRUCT
	cAuthInfo DD
	aAuthInfo SOLE_AUTHENTICATION_INFO
ENDS

;MIDL_IClientSecurity("0000013D-0000-0000-C000-000000000046")

IClientSecurity STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	QueryBlanket PTR
	SetBlanket PTR
	CopyProxy PTR
ENDS

;MIDL_IServerSecurity("0000013E-0000-0000-C000-000000000046")

IServerSecurity STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	QueryBlanket PTR
	ImpersonateClient PTR
	RevertToSelf PTR
	IsImpersonating PTR
ENDS

;MIDL_IClassActivator("00000140-0000-0000-C000-000000000046")

IClassActivator STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetClassObject PTR
ENDS

;MIDL_IRpcOptions("00000144-0000-0000-C000-000000000046")

IRpcOptions STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	Set PTR
	Query PTR
ENDS

;MIDL_IFillLockBytes("99caf010-415e-11cf-8814-00aa00b569f5")

IFillLockBytes STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	FillAppend PTR
	FillAt PTR
	SetFillSize PTR
	Terminate PTR
ENDS

;MIDL_IProgressNotify("a9d758a0-4617-11cf-95fc-00aa00680db4")

IProgressNotify STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	OnProgress PTR
ENDS

StorageLayout STRUCT
	LayoutType DD
	pwcsElementName PTR
	cOffset DQ
	cBytes DQ
ENDS

;MIDL_ILayoutStorage("0e6d4d90-6738-11cf-9608-00aa00680db4")

ILayoutStorage STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	LayoutScript PTR
	BeginMonitor PTR
	EndMonitor PTR
	ReLayoutDocfile PTR
	ReLayoutDocfileOnILockBytes PTR
ENDS

;MIDL_IBlockingLock("30f3d47a-6447-11d1-8e3c-00c04fb9386d")

IBlockingLock STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	Lock PTR
	Unlock PTR
ENDS

;MIDL_ITimeAndNoticeControl("bc0bf6ae-8878-11d1-83e9-00c04fc2c6d4")

ITimeAndNoticeControl STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	SuppressChanges PTR
ENDS

;MIDL_IOplockStorage("8d19c834-8879-11d1-83e9-00c04fc2c6d4")

IOplockStorage STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	CreateStorageEx PTR
	OpenStorageEx PTR
ENDS

;MIDL_ISurrogate("00000022-0000-0000-C000-000000000046")

ISurrogate STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	LoadDllServer PTR
	FreeSurrogate PTR
ENDS

;MIDL_IGlobalInterfaceTable("00000146-0000-0000-C000-000000000046")

IGlobalInterfaceTable STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	RegisterInterfaceInGlobal PTR
	RevokeInterfaceFromGlobal PTR
	GetInterfaceFromGlobal PTR
ENDS

;MIDL_IDirectWriterLock("0e6d4d92-6738-11cf-9608-00aa00680db4")

IDirectWriterLock STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	WaitForWriteAccess PTR
	ReleaseWriteAccess PTR
	HaveWriteAccess PTR
ENDS

;MIDL_ISynchronize("00000030-0000-0000-C000-000000000046")

ISynchronize STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	Wait PTR
	Signal PTR
	Reset PTR
ENDS

;MIDL_ISynchronizeHandle("00000031-0000-0000-C000-000000000046")

ISynchronizeHandle STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetHandle PTR
ENDS

;MIDL_ISynchronizeEvent("00000032-0000-0000-C000-000000000046")

ISynchronizeEvent STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetHandle PTR
	SetEventHandle PTR
ENDS

;MIDL_ISynchronizeContainer("00000033-0000-0000-C000-000000000046")

ISynchronizeContainer STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	AddSynchronize PTR
	WaitMultiple PTR
ENDS

;MIDL_ISynchronizeMutex("00000025-0000-0000-C000-000000000046")

ISynchronizeMutex STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	Wait PTR
	Signal PTR
	Reset PTR
	ReleaseMutex PTR
ENDS

;MIDL_ICancelMethodCalls("00000029-0000-0000-C000-000000000046")

ICancelMethodCalls STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	Cancel PTR
	TestCancel PTR
ENDS

;MIDL_IAsyncManager("0000002A-0000-0000-C000-000000000046")

IAsyncManager STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	CompleteCall PTR
	GetCallContext PTR
	GetState PTR
ENDS

;MIDL_ICallFactory("1c733a30-2a1c-11ce-ade5-00aa0044773d")

ICallFactory STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	CreateCall PTR
ENDS

;MIDL_IRpcHelper("00000149-0000-0000-C000-000000000046")

IRpcHelper STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetDCOMProtocolVersion PTR
	GetIIDFromOBJREF PTR
ENDS

;MIDL_IReleaseMarshalBuffers("eb0cb9e8-7996-11d2-872e-0000f8080859")

IReleaseMarshalBuffers STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	ReleaseMarshalBuffer PTR
ENDS

;MIDL_IWaitMultiple("0000002B-0000-0000-C000-000000000046")

IWaitMultiple STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	WaitMultiple PTR
	AddSynchronize PTR
ENDS

;MIDL_IUrlMon("00000026-0000-0000-C000-000000000046")

IUrlMon STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	AsyncGetClassBits PTR
ENDS

;MIDL_IForegroundTransfer("00000145-0000-0000-C000-000000000046")

IForegroundTransfer STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	AllowForegroundTransfer PTR
ENDS

;MIDL_IPipeByte("DB2F3ACA-2F86-11d1-8E04-00C04FB9989A")

IPipeByte STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	Pull PTR
	Push PTR
ENDS

;MIDL_AsyncIPipeByte("DB2F3ACB-2F86-11d1-8E04-00C04FB9989A")

AsyncIPipeByte STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	Begin_Pull PTR
	Finish_Pull PTR
	Begin_Push PTR
	Finish_Push PTR
ENDS

;MIDL_IPipeLong("DB2F3ACC-2F86-11d1-8E04-00C04FB9989A")

IPipeLong STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	Pull PTR
	Push PTR
ENDS

;MIDL_AsyncIPipeLong("DB2F3ACD-2F86-11d1-8E04-00C04FB9989A")

AsyncIPipeLong STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	Begin_Pull PTR
	Finish_Pull PTR
	Begin_Push PTR
	Finish_Push PTR
ENDS

;MIDL_IPipeDouble("DB2F3ACE-2F86-11d1-8E04-00C04FB9989A")

IPipeDouble STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	Pull PTR
	Push PTR
ENDS

;MIDL_AsyncIPipeDouble("DB2F3ACF-2F86-11d1-8E04-00C04FB9989A")

AsyncIPipeDouble STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	Begin_Pull PTR
	Finish_Pull PTR
	Begin_Push PTR
	Finish_Push PTR
ENDS

;MIDL_IThumbnailExtractor("969dc708-5c76-11d1-8d86-0000f804b057")

IThumbnailExtractor STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	ExtractThumbnail PTR
	OnFileUpdated PTR
ENDS

;MIDL_IDummyHICONIncluder("947990de-cc28-11d2-a0f7-00805f858fb1")

IDummyHICONIncluder STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	Dummy PTR
ENDS

#endif
