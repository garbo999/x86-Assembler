#ifndef RPCNDR_H
#define RPCNDR_H

/* Windows RPC Network Data Representation definitions */

/*
switches
WIN32_WINNT (0x500, 0x400 etc)
*/

#IFNDEF RPCNSIP_H
	#include rpcnsip.h // WIN3264
#ENDIF

#define NDR_CHAR_REP_MASK  0x0000000F
#define NDR_INT_REP_MASK  0x000000F0
#define NDR_FLOAT_REP_MASK  0x0000FF00
#define NDR_LITTLE_ENDIAN  0x00000010
#define NDR_BIG_ENDIAN  0x00000000
#define NDR_IEEE_FLOAT  0x00000000
#define NDR_VAX_FLOAT  0x00000100
#define NDR_IBM_FLOAT  0x00000300
#define NDR_ASCII_CHAR  0x00000000
#define NDR_EBCDIC_CHAR  0x00000001
#define NDR_LOCAL_DATA_REPRESENTATION   0x00000010
#define NDR_LOCAL_ENDIAN  NDR_LITTLE_ENDIAN

#if WINVER >= NTDDI_WIN2K
	#define TARGET_IS_NT50_OR_LATER  1
#else
	#define TARGET_IS_NT50_OR_LATER  0
#endif

#if WINVER >= NTDDI_WINNT4
	#define TARGET_IS_NT40_OR_LATER  1
#else
	#define TARGET_IS_NT40_OR_LATER  0
#endif

#define TARGET_IS_NT351_OR_WIN95_OR_LATER   1

#define cbNDRContext 20

#define USER_CALL_IS_ASYNC  0x0100
#define USER_CALL_NEW_CORRELATION_DESC  0x0200

#define USER_MARSHAL_FC_BYTE  1
#define USER_MARSHAL_FC_CHAR  2
#define USER_MARSHAL_FC_SMALL  3
#define USER_MARSHAL_FC_USMALL  4
#define USER_MARSHAL_FC_WCHAR  5
#define USER_MARSHAL_FC_SHORT  6
#define USER_MARSHAL_FC_USHORT  7
#define USER_MARSHAL_FC_LONG  8
#define USER_MARSHAL_FC_ULONG  9
#define USER_MARSHAL_FC_FLOAT  10
#define USER_MARSHAL_FC_HYPER  11
#define USER_MARSHAL_FC_DOUBLE  12

NDR_SCONTEXT struct
	pad DD 2 DUP ?
	userContext PTR
ENDS

SCONTEXT_QUEUE STRUCT
	NumberOfObjects DD
	ArrayOfObjects PTR
ENDS

ARRAY_INFO struct
	Dimension DD
	BufferConformanceMark PTR
	BufferVarianceMark PTR
	MaxCountArray PTR
	OffsetArray PTR
	ActualCountArray PTR
ENDS

MIDL_STUB_MESSAGE STRUCT
	RpcMsg PRPC_MESSAGE
	Buffer PTR
	BufferStart PTR
	BufferEnd PTR
	BufferMark PTR
	BufferLength DD
	MemorySize DD
	Memory PTR
	IsClient DB
	Pad DB
	uFlags2 DW
	ReuseBuffer DD
	pAllocAllNodesContext PTR
	pPointerQueueState PTR
	IgnoreEmbeddedPointers DD
	PointerBufferMark PTR
	CorrDespIncrement DB
	uFlags DB
	UniquePtrCount DW
	MaxCount ULONG_PTR
	Offset DD
	ActualCount DD
	pfnAllocate PTR
	pfnFree PTR
	StackTop PTR
	pPresentedType PTR
	pTransmitType PTR
	SavedHandle HANDLE
	StubDesc PTR
	FullPtrXlatTables PTR
	FullPtrRefId DD
	PointerLength DD
	fInDontFree DD
	fDontCallFreeInst DD
	fInOnlyParam DD
	fHasReturn DD
	fHasExtensions DD
	fHasNewCorrDesc DD
	fIsIn DD
	fIsOut DD
	fIsOicf DD
	fBufferValid DD
	fHasMemoryValidateCallback DD
	fInFree DD
	fNeedMCCP DD
	fUnused DD
	fUnused2 DD
	dwDestContext DD
	pvDestContext PTR
	SavedContextHandles PTR
	ParamNumber DD
	pRpcChannelBuffer PTR
	pArrayInfo PTR
	SizePtrCountArray PTR
	SizePtrOffsetArray PTR
	SizePtrLengthArray PTR
	pArgQueue PTR
	dwStubPhase DD
	LowStackMark PTR
	pAsyncMsg PTR
	pCorrInfo PTR
	pCorrMemory PTR
	pMemoryList PTR
	#if WINVER >= NTDDI_WIN2K 
		pCSInfo INT_PTR
		ConformanceMark PTR
		VarianceMark PTR
		#ifdef IA64
			BackingStoreLowMark PTR
		#else
			Unused INT_PTR
		#endif
		pContext PTR
		ContextHandleHash PTR
		pUserMarshalList PTR
		Reserved51_3 INT_PTR
		Reserved51_4 INT_PTR
		Reserved51_5 INT_PTR
	#endif
ENDS

GENERIC_BINDING_ROUTINE_PAIR STRUCT
	pfnBind PTR
	pfnUnbind PTR
ENDS

GENERIC_BINDING_INFO STRUCT
	pObj PTR
	Size DD
	pfnBind PTR
	pfnUnbind PTR
ENDS

XMIT_ROUTINE_QUINTUPLE STRUCT
	pfnTranslateToXmit PTR
	pfnTranslateFromXmit PTR
	pfnFreeXmit PTR
	pfnFreeInst PTR
ENDS

USER_MARSHAL_ROUTINE_QUADRUPLE STRUCT
	pfnBufferSize PTR
	pfnMarshall PTR
	pfnUnmarshall PTR
	pfnFree PTR
ENDS

USER_MARSHAL_CB_BUFFER_SIZE = 0
USER_MARSHAL_CB_MARSHALL = 1
USER_MARSHAL_CB_UNMARSHALL =2
USER_MARSHAL_CB_FREE = 3

USER_MARSHAL_CB STRUCT
	Flags DD
	pStubMsg PTR
	pReserve PTR
	Signature DD
	CBType DD
	pFormat PTR
	pTypeFormat PTR
ENDS

MALLOC_FREE STRUCT
	pfnAllocate PTR
	pfnFree PTR
ENDS

COMM_FAULT_OFFSETS STRUCT
	CommOffset DW
	FaultOffset DW
ENDS

MIDL_STUB_DESC STRUCT
	RpcInterfaceInformation PTR
	pfnAllocate PTR
	pfnFree PTR
	UNION
		pAutoHandle PTR
		pPrimitiveHandle PTR
		pGenericBindingInfo PTR
	ENDUNION
	apfnNdrRundownRoutines PTR
	aGenericBindingRoutinePairs PTR
	apfnExprEval PTR
	aXmitQuintuple PTR
	pFormatTypes PTR
	fCheckBounds DD
	Version DD
	pMallocFreeStruct PTR
	MIDLVersion DD
	CommFaultOffsets PTR
	aUserMarshalQuadruple PTR
	NotifyRoutineTable PTR
	mFlags ULONG_PTR
	CsRoutineTables PTR
	Reserved4 PTR
	Reserved5 ULONG_PTR
ENDS

MIDL_FORMAT_STRING  STRUCT
	Pad DW
	Format DB
ENDS

MIDL_SERVER_INFO STRUCT
	pStubDesc PTR
	DispatchTable PTR
	ProcString PTR
	FmtStringOffset PTR
	ThunkTable PTR
	pTransferSyntax PTR
	nCount ULONG_PTR
	pSyntaxInfo PTR
ENDS

MIDL_STUBLESS_PROXY_INFO STRUCT
	pStubDesc PTR
	ProcFormatString PTR
	FormatStringOffset PTR
	pTransferSyntax PTR
	nCount ULONG_PTR
	pSyntaxInfo PTR
ENDS

MIDL_SYNTAX_INFO STRUCT
	TransferSyntax DD
	DispatchTable PTR
	ProcString PTR
	FmtStringOffset PTR
	TypeString PTR
	aUserMarshalQuadruple PTR
	pReserved1 ULONG_PTR
	pReserved2 ULONG_PTR
ENDS

CLIENT_CALL_RETURN STRUCT
	Pointer PTR
	Simple LONG_PTR
ENDS

#Define XLAT_SERVER 1
#Define XLAT_CLIENT 2

FULL_PTR_XLAT_TABLES STRUCT
	Next PTR
	Pointer PTR
	RefId DD
	State DB
ENDS

#Define STUB_UNMARSHAL 0
#Define STUB_CALL_SERVER 1
#Define STUB_MARSHAL 2
#Define STUB_CALL_SERVER_NO_HRESULT 3

#Define PROXY_CALCSIZE 0
#Define PROXY_GETBUFFER 1
#Define PROXY_MARSHAL 2
#Define PROXY_SENDRECEIVE 3
#Define PROXY_UNMARSHAL 4

NDR_USER_MARSHAL_INFO_LEVEL1 STRUCT
	Buffer PTR
	BufferSize DD
	pfnAllocate PTR
	pfnFree PTR
	pRpcChannelBuffer PTR
	Reserved ULONG_PTR 5 DUP
ENDS

NDR_USER_MARSHAL_INFO STRUCT
	InformationLevel DD
	Level1 NDR_USER_MARSHAL_INFO_LEVEL1
ENDS

#endif /* _RPCNDR_H */
