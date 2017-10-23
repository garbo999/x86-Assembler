#IFNDEF WBEMDISP_H
#define WBEMDISP_H

#IFNDEF RPC_H
	#include "rpc.h"
#ENDIF

#IFNDEF RPCNDR_H
	#include "rpcndr.h"
#ENDIF

#IFNDEF BASECOM_H
	#include "BaseCOM.h"
#ENDIF

#IFNDEF DISPEX_H
	#include "dispex.h"
#ENDIF

wbemChangeFlagCreateOrUpdate = 0
wbemChangeFlagUpdateOnly = 0x1
wbemChangeFlagCreateOnly = 0x2
wbemChangeFlagUpdateCompatible = 0
wbemChangeFlagUpdateSafeMode = 0x20
wbemChangeFlagUpdateForceMode = 0x40
wbemChangeFlagStrongValidation = 0x80
wbemChangeFlagAdvisory = 0x10000

wbemFlagReturnImmediately = 0x10
wbemFlagReturnWhenComplete = 0
wbemFlagBidirectional = 0
wbemFlagForwardOnly = 0x20
wbemFlagNoErrorObject = 0x40
wbemFlagReturnErrorObject = 0
wbemFlagSendStatus = 0x80
wbemFlagDontSendStatus = 0
wbemFlagEnsureLocatable = 0x100
wbemFlagDirectRead = 0x200
wbemFlagSendOnlySelected = 0
wbemFlagUseAmendedQualifiers = 0x20000
wbemFlagGetDefault = 0
wbemFlagSpawnInstance = 0x1
wbemFlagUseCurrentTime = 0x1

wbemQueryFlagDeep = 0
wbemQueryFlagShallow = 1
wbemQueryFlagPrototype = 2

wbemTextFlagNoFlavors = 0x1

wbemTimeoutInfinite = 0xffffffff

wbemComparisonFlagIncludeAll = 0
wbemComparisonFlagIgnoreQualifiers = 0x1
wbemComparisonFlagIgnoreObjectSource = 0x2
wbemComparisonFlagIgnoreDefaultValues = 0x4
wbemComparisonFlagIgnoreClass = 0x8
wbemComparisonFlagIgnoreCase = 0x10
wbemComparisonFlagIgnoreFlavor = 0x20

wbemCimtypeSint8 = 16
wbemCimtypeUint8 = 17
wbemCimtypeSint16 = 2
wbemCimtypeUint16 = 18
wbemCimtypeSint32 = 3
wbemCimtypeUint32 = 19
wbemCimtypeSint64 = 20
wbemCimtypeUint64 = 21
wbemCimtypeReal32 = 4
wbemCimtypeReal64 = 5
wbemCimtypeBoolean = 11
wbemCimtypeString = 8
wbemCimtypeDatetime = 101
wbemCimtypeReference = 102
wbemCimtypeChar16 = 103
wbemCimtypeObject = 13

wbemNoErr = 0
wbemErrFailed = 0x80041001
wbemErrNotFound = 0x80041002
wbemErrAccessDenied = 0x80041003
wbemErrProviderFailure = 0x80041004
wbemErrTypeMismatch = 0x80041005
wbemErrOutOfMemory = 0x80041006
wbemErrInvalidContext = 0x80041007
wbemErrInvalidParameter = 0x80041008
wbemErrNotAvailable = 0x80041009
wbemErrCriticalError = 0x8004100a
wbemErrInvalidStream = 0x8004100b
wbemErrNotSupported = 0x8004100c
wbemErrInvalidSuperclass = 0x8004100d
wbemErrInvalidNamespace = 0x8004100e
wbemErrInvalidObject = 0x8004100f
wbemErrInvalidClass = 0x80041010
wbemErrProviderNotFound = 0x80041011
wbemErrInvalidProviderRegistration = 0x80041012
wbemErrProviderLoadFailure = 0x80041013
wbemErrInitializationFailure = 0x80041014
wbemErrTransportFailure = 0x80041015
wbemErrInvalidOperation = 0x80041016
wbemErrInvalidQuery = 0x80041017
wbemErrInvalidQueryType = 0x80041018
wbemErrAlreadyExists = 0x80041019
wbemErrOverrideNotAllowed = 0x8004101a
wbemErrPropagatedQualifier = 0x8004101b
wbemErrPropagatedProperty = 0x8004101c
wbemErrUnexpected = 0x8004101d
wbemErrIllegalOperation = 0x8004101e
wbemErrCannotBeKey = 0x8004101f
wbemErrIncompleteClass = 0x80041020
wbemErrInvalidSyntax = 0x80041021
wbemErrNondecoratedObject = 0x80041022
wbemErrReadOnly = 0x80041023
wbemErrProviderNotCapable = 0x80041024
wbemErrClassHasChildren = 0x80041025
wbemErrClassHasInstances = 0x80041026
wbemErrQueryNotImplemented = 0x80041027
wbemErrIllegalNull = 0x80041028
wbemErrInvalidQualifierType = 0x80041029
wbemErrInvalidPropertyType = 0x8004102a
wbemErrValueOutOfRange = 0x8004102b
wbemErrCannotBeSingleton = 0x8004102c
wbemErrInvalidCimType = 0x8004102d
wbemErrInvalidMethod = 0x8004102e
wbemErrInvalidMethodParameters = 0x8004102f
wbemErrSystemProperty = 0x80041030
wbemErrInvalidProperty = 0x80041031
wbemErrCallCancelled = 0x80041032
wbemErrShuttingDown = 0x80041033
wbemErrPropagatedMethod = 0x80041034
wbemErrUnsupportedParameter = 0x80041035
wbemErrMissingParameter = 0x80041036
wbemErrInvalidParameterId = 0x80041037
wbemErrNonConsecutiveParameterIds = 0x80041038
wbemErrParameterIdOnRetval = 0x80041039
wbemErrInvalidObjectPath = 0x8004103a
wbemErrOutOfDiskSpace = 0x8004103b
wbemErrBufferTooSmall = 0x8004103c
wbemErrUnsupportedPutExtension = 0x8004103d
wbemErrUnknownObjectType = 0x8004103e
wbemErrUnknownPacketType = 0x8004103f
wbemErrMarshalVersionMismatch = 0x80041040
wbemErrMarshalInvalidSignature = 0x80041041
wbemErrInvalidQualifier = 0x80041042
wbemErrInvalidDuplicateParameter = 0x80041043
wbemErrTooMuchData = 0x80041044
wbemErrServerTooBusy = 0x80041045
wbemErrInvalidFlavor = 0x80041046
wbemErrCircularReference = 0x80041047
wbemErrUnsupportedClassUpdate = 0x80041048
wbemErrCannotChangeKeyInheritance = 0x80041049
wbemErrCannotChangeIndexInheritance = 0x80041050
wbemErrTooManyProperties = 0x80041051
wbemErrUpdateTypeMismatch = 0x80041052
wbemErrUpdateOverrideNotAllowed = 0x80041053
wbemErrUpdatePropagatedMethod = 0x80041054
wbemErrMethodNotImplemented = 0x80041055
wbemErrMethodDisabled = 0x80041056
wbemErrRefresherBusy = 0x80041057
wbemErrUnparsableQuery = 0x80041058
wbemErrNotEventClass = 0x80041059
wbemErrMissingGroupWithin = 0x8004105a
wbemErrMissingAggregationList = 0x8004105b
wbemErrPropertyNotAnObject = 0x8004105c
wbemErrAggregatingByObject = 0x8004105d
wbemErrUninterpretableProviderQuery = 0x8004105f
wbemErrBackupRestoreWinmgmtRunning = 0x80041060
wbemErrQueueOverflow = 0x80041061
wbemErrPrivilegeNotHeld = 0x80041062
wbemErrInvalidOperator = 0x80041063
wbemErrLocalCredentials = 0x80041064
wbemErrCannotBeAbstract = 0x80041065
wbemErrAmendedObject = 0x80041066
wbemErrClientTooSlow = 0x80041067
wbemErrNullSecurityDescriptor = 0x80041068
wbemErrTimeout = 0x80041069
wbemErrInvalidAssociation = 0x8004106a
wbemErrAmbiguousOperation = 0x8004106b
wbemErrQuotaViolation = 0x8004106c
wbemErrTransactionConflict = 0x8004106d
wbemErrForcedRollback = 0x8004106e
wbemErrUnsupportedLocale = 0x8004106f
wbemErrHandleOutOfDate = 0x80041070
wbemErrConnectionFailed = 0x80041071
wbemErrInvalidHandleRequest = 0x80041072
wbemErrPropertyNameTooWide = 0x80041073
wbemErrClassNameTooWide = 0x80041074
wbemErrMethodNameTooWide = 0x80041075
wbemErrQualifierNameTooWide = 0x80041076
wbemErrRerunCommand = 0x80041077
wbemErrDatabaseVerMismatch = 0x80041078
wbemErrVetoPut = 0x80041079
wbemErrVetoDelete = 0x8004107a
wbemErrInvalidLocale = 0x80041080
wbemErrProviderSuspended = 0x80041081
wbemErrSynchronizationRequired = 0x80041082
wbemErrNoSchema = 0x80041083
wbemErrProviderAlreadyRegistered = 0x80041084
wbemErrProviderNotRegistered = 0x80041085
wbemErrFatalTransportError = 0x80041086
wbemErrEncryptedConnectionRequired = 0x80041087
wbemErrRegistrationTooBroad = 0x80042001
wbemErrRegistrationTooPrecise = 0x80042002
wbemErrTimedout = 0x80043001
wbemErrResetToDefault = 0x80043002

wbemAuthenticationLevelDefault = 0
wbemAuthenticationLevelNone = 1
wbemAuthenticationLevelConnect = 2
wbemAuthenticationLevelCall = 3
wbemAuthenticationLevelPkt = 4
wbemAuthenticationLevelPktIntegrity = 5
wbemAuthenticationLevelPktPrivacy = 6

wbemImpersonationLevelAnonymous = 1
wbemImpersonationLevelIdentify = 2
wbemImpersonationLevelImpersonate = 3
wbemImpersonationLevelDelegate = 4

wbemPrivilegeCreateToken = 1
wbemPrivilegePrimaryToken = 2
wbemPrivilegeLockMemory = 3
wbemPrivilegeIncreaseQuota = 4
wbemPrivilegeMachineAccount = 5
wbemPrivilegeTcb = 6
wbemPrivilegeSecurity = 7
wbemPrivilegeTakeOwnership = 8
wbemPrivilegeLoadDriver = 9
wbemPrivilegeSystemProfile = 10
wbemPrivilegeSystemtime = 11
wbemPrivilegeProfileSingleProcess = 12
wbemPrivilegeIncreaseBasePriority = 13
wbemPrivilegeCreatePagefile = 14
wbemPrivilegeCreatePermanent = 15
wbemPrivilegeBackup = 16
wbemPrivilegeRestore = 17
wbemPrivilegeShutdown = 18
wbemPrivilegeDebug = 19
wbemPrivilegeAudit = 20
wbemPrivilegeSystemEnvironment = 21
wbemPrivilegeChangeNotify = 22
wbemPrivilegeRemoteShutdown = 23
wbemPrivilegeUndock = 24
wbemPrivilegeSyncAgent = 25
wbemPrivilegeEnableDelegation = 26
wbemPrivilegeManageVolume = 27

wbemObjectTextFormatCIMDTD20 = 1
wbemObjectTextFormatWMIDTD20 = 2

wbemConnectFlagUseMaxWait = 0x80

#define GUID_IID_ISWbemServices <0x76A6415C,0xCB41,0x11d1,<0x8B,0x02,0x00,0x60,0x08,0x06,0xD9,0xB6>>
ISWbemServices STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	Get PTR
	GetAsync PTR
	Delete PTR
	DeleteAsync PTR
	InstancesOf PTR
	InstancesOfAsync PTR
	SubclassesOf PTR
	SubclassesOfAsync PTR
	ExecQuery PTR
	ExecQueryAsync PTR
	AssociatorsOf PTR
	AssociatorsOfAsync PTR
	ReferencesTo PTR
	ReferencesToAsync PTR
	ExecNotificationQuery PTR
	ExecNotificationQueryAsync PTR
	ExecMethod PTR
	ExecMethodAsync PTR
	get_Security PTR
ENDS

#define GUID_IID_ISWbemLocator <0x76A6415B,0xCB41,0x11d1,<0x8B,0x02,0x00,0x60,0x08,0x06,0xD9,0xB6>>
ISWbemLocator STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	ConnectServer PTR
	get_Security PTR
ENDS

#define GUID_IID_ISWbemObject <0x76A6415A,0xCB41,0x11d1,<0x8B,0x02,0x00,0x60,0x08,0x06,0xD9,0xB6>>
ISWbemObject STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	Put PTR
	PutAsync PTR
	Delete PTR
	DeleteAsync PTR
	Instances PTR
	InstancesAsync PTR
	Subclasses PTR
	SubclassesAsync PTR
	Associators PTR
	AssociatorsAsync PTR
	References PTR
	ReferencesAsync PTR
	ExecMethod PTR
	ExecMethodAsync PTR
	Clone PTR
	GetObjectText PTR
	SpawnDerivedClass PTR
	SpawnInstance PTR
	CompareTo PTR
	get_Qualifiers PTR
	get_Properties PTR
	get_Methods PTR
	get_Derivation PTR
	get_Path PTR
	get_Security PTR
ENDS

#define GUID_IID_ISWbemObjectSet <0x76A6415F,0xCB41,0x11d1,<0x8B,0x02,0x00,0x60,0x08,0x06,0xD9,0xB6>>
ISWbemObjectSet STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	get__NewEnum PTR
	Item PTR
	get_Count PTR
	get_Security PTR
ENDS

#define GUID_IID_ISWbemNamedValue <0x76A64164,0xCB41,0x11d1,<0x8B,0x02,0x00,0x60,0x08,0x06,0xD9,0xB6>>
ISWbemNamedValue STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	get_Value PTR
	put_Value PTR
	get_Name PTR
ENDS

#define GUID_IID_ISWbemNamedValueSet <0xCF2376EA,0xCE8C,0x11d1,<0x8B,0x05,0x00,0x60,0x08,0x06,0xD9,0xB6>>
ISWbemNamedValueSet STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	get__NewEnum PTR
	Item PTR
	get_Count PTR
	Add PTR
	Remove PTR
	Clone PTR
	DeleteAll PTR
ENDS

#define GUID_IID_ISWbemQualifier <0x79B05932,0xD3B7,0x11d1,<0x8B,0x06,0x00,0x60,0x08,0x06,0xD9,0xB6>>
ISWbemQualifier STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	get_Value PTR
	put_Value PTR
	get_Name PTR
	get_IsLocal PTR
	get_PropagatesToSubclass PTR
	put_PropagatesToSubclass PTR
	get_PropagatesToInstance PTR
	put_PropagatesToInstance PTR
	get_IsOverridable PTR
	put_IsOverridable PTR
	get_IsAmended PTR
ENDS

#define GUID_IID_ISWbemQualifierSet <0x9B16ED16,0xD3DF,0x11d1,<0x8B,0x08,0x00,0x60,0x08,0x06,0xD9,0xB6>>
ISWbemQualifierSet STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	get__NewEnum PTR
	Item PTR
	get_Count PTR
	Add PTR
	Remove PTR
ENDS

#define GUID_IID_ISWbemProperty <0x1A388F98,0xD4BA,0x11d1,<0x8B,0x09,0x00,0x60,0x08,0x06,0xD9,0xB6>>
ISWbemProperty STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	get_Value PTR
	put_Value PTR
	get_Name PTR
	get_IsLocal PTR
	get_Origin PTR
	get_CIMType PTR
	get_Qualifiers PTR
	get_IsArray PTR
ENDS

#define GUID_IID_ISWbemPropertySet <0xDEA0A7B2,0xD4BA,0x11d1,<0x8B,0x09,0x00,0x60,0x08,0x06,0xD9,0xB6>>
ISWbemPropertySet STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	get__NewEnum PTR
	Item PTR
	get_Count PTR
	Add PTR
	Remove PTR
ENDS

#define GUID_IID_ISWbemMethod <0x422E8E90,0xD955,0x11d1,<0x8B,0x09,0x00,0x60,0x08,0x06,0xD9,0xB6>>
ISWbemMethod STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	get_Name PTR
	get_Origin PTR
	get_InParameters PTR
	get_OutParameters PTR
	get_Qualifiers PTR
ENDS

#define GUID_IID_ISWbemMethodSet <0xC93BA292,0xD955,0x11d1,<0x8B,0x09,0x00,0x60,0x08,0x06,0xD9,0xB6>>
ISWbemMethodSet STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	get__NewEnum PTR
	Item PTR
	get_Count PTR
ENDS

#define GUID_IID_ISWbemEventSource <0x27D54D92,0x0EBE,0x11d2,<0x8B,0x22,0x00,0x60,0x08,0x06,0xD9,0xB6>>
ISWbemEventSource STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	NextEvent PTR
	get_Security PTR
ENDS

#define GUID_IID_ISWbemObjectPath <0x5791BC27,0xCE9C,0x11d1,<0x97,0xBF,0x00,0x00,0xF8,0x1E,0x84,0x9C>>
ISWbemObjectPath STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	get_Path PTR
	put_Path PTR
	get_RelPath PTR
	put_RelPath PTR
	get_Server PTR
	put_Server PTR
	get_Namespace PTR
	put_Namespace PTR
	get_ParentNamespace PTR
	get_DisplayName PTR
	put_DisplayName PTR
	get_Class PTR
	put_Class PTR
	get_IsClass PTR
	SetAsClass PTR
	get_IsSingleton PTR
	SetAsSingleton PTR
	get_Keys PTR
	get_Security PTR
	get_Locale PTR
	put_Locale PTR
	get_Authority PTR
	put_Authority PTR
ENDS

#define GUID_IID_ISWbemLastError <0xD962DB84,0xD4BB,0x11d1,<0x8B,0x09,0x00,0x60,0x08,0x06,0xD9,0xB6>>
ISWbemLastError STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	Put PTR
	PutAsync PTR
	Delete PTR
	DeleteAsync PTR
	Instances PTR
	InstancesAsync PTR
	Subclasses PTR
	SubclassesAsync PTR
	Associators PTR
	AssociatorsAsync PTR
	References PTR
	ReferencesAsync PTR
	ExecMethod PTR
	ExecMethodAsync PTR
	Clone PTR
	GetObjectText PTR
	SpawnDerivedClass PTR
	SpawnInstance PTR
	CompareTo PTR
	get_Qualifiers PTR
	get_Properties PTR
	get_Methods PTR
	get_Derivation PTR
	get_Path PTR
	get_Security PTR
ENDS

#define GUID_IID_ISWbemSinkEvents <0x75718CA0,0xF029,0x11d1,<0xA1,0xAC,0x00,0xC0,0x4F,0xB6,0xC2,0x23>>
ISWbemSinkEvents STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
ENDS

#define GUID_IID_ISWbemSink <0x75718C9F,0xF029,0x11d1,<0xA1,0xAC,0x00,0xC0,0x4F,0xB6,0xC2,0x23>>
ISWbemSink STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	Cancel PTR
ENDS

#define GUID_IID_ISWbemSecurity <0xB54D66E6,0x2287,0x11d2,<0x8B,0x33,0x00,0x60,0x08,0x06,0xD9,0xB6>>
ISWbemSecurity STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	get_ImpersonationLevel PTR
	put_ImpersonationLevel PTR
	get_AuthenticationLevel PTR
	put_AuthenticationLevel PTR
	get_Privileges PTR
ENDS

#define GUID_IID_ISWbemPrivilege <0x26EE67BD,0x5804,0x11d2,<0x8B,0x4A,0x00,0x60,0x08,0x06,0xD9,0xB6>>
ISWbemPrivilege STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	get_IsEnabled PTR
	put_IsEnabled PTR
	get_Name PTR
	get_DisplayName PTR
	get_Identifier PTR
ENDS

#define GUID_IID_ISWbemPrivilegeSet <0x26EE67BF,0x5804,0x11d2,<0x8B,0x4A,0x00,0x60,0x08,0x06,0xD9,0xB6>>
ISWbemPrivilegeSet STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	get__NewEnum PTR
	Item PTR
	get_Count PTR
	Add PTR
	Remove PTR
	DeleteAll PTR
	AddAsString PTR
ENDS

#define GUID_IID_ISWbemServicesEx <0xD2F68443,0x85DC,0x427e,<0x91,0xD8,0x36,0x65,0x54,0xCC,0x75,0x4C>>
ISWbemServicesEx STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	Get PTR
	GetAsync PTR
	Delete PTR
	DeleteAsync PTR
	InstancesOf PTR
	InstancesOfAsync PTR
	SubclassesOf PTR
	SubclassesOfAsync PTR
	ExecQuery PTR
	ExecQueryAsync PTR
	AssociatorsOf PTR
	AssociatorsOfAsync PTR
	ReferencesTo PTR
	ReferencesToAsync PTR
	ExecNotificationQuery PTR
	ExecNotificationQueryAsync PTR
	ExecMethod PTR
	ExecMethodAsync PTR
	get_Security PTR
	Put PTR
	PutAsync PTR
ENDS

#define GUID_IID_ISWbemObjectEx <0x269AD56A,0x8A67,0x4129,<0xBC,0x8C,0x05,0x06,0xDC,0xFE,0x98,0x80>>
ISWbemObjectEx STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	Put PTR
	PutAsync PTR
	Delete PTR
	DeleteAsync PTR
	Instances PTR
	InstancesAsync PTR
	Subclasses PTR
	SubclassesAsync PTR
	Associators PTR
	AssociatorsAsync PTR
	References PTR
	ReferencesAsync PTR
	ExecMethod PTR
	ExecMethodAsync PTR
	Clone PTR
	GetObjectText PTR
	SpawnDerivedClass PTR
	SpawnInstance PTR
	CompareTo PTR
	get_Qualifiers PTR
	get_Properties PTR
	get_Methods PTR
	get_Derivation PTR
	get_Path PTR
	get_Security PTR
	Refresh PTR
	get_SystemProperties PTR
	GetText PTR
	SetFromText PTR
ENDS

#define GUID_IID_ISWbemDateTime <0x5E97458A,0xCF77,0x11d3,<0xB3,0x8F,0x00,0x10,0x5A,0x1F,0x47,0x3A>>
ISWbemDateTime STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	get_Value PTR
	put_Value PTR
	get_Year PTR
	put_Year PTR
	get_YearSpecified PTR
	put_YearSpecified PTR
	get_Month PTR
	put_Month PTR
	get_MonthSpecified PTR
	put_MonthSpecified PTR
	get_Day PTR
	put_Day PTR
	get_DaySpecified PTR
	put_DaySpecified PTR
	get_Hours PTR
	put_Hours PTR
	get_HoursSpecified PTR
	put_HoursSpecified PTR
	get_Minutes PTR
	put_Minutes PTR
	get_MinutesSpecified PTR
	put_MinutesSpecified PTR
	get_Seconds PTR
	put_Seconds PTR
	get_SecondsSpecified PTR
	put_SecondsSpecified PTR
	get_Microseconds PTR
	put_Microseconds PTR
	get_MicrosecondsSpecified PTR
	put_MicrosecondsSpecified PTR
	get_UTC PTR
	put_UTC PTR
	get_UTCSpecified PTR
	put_UTCSpecified PTR
	get_IsInterval PTR
	put_IsInterval PTR
	GetVarDate PTR
	SetVarDate PTR
	GetFileTime PTR
	SetFileTime PTR
ENDS

#define GUID_IID_ISWbemRefresher <0x14D8250E,0xD9C2,0x11d3,<0xB3,0x8F,0x00,0x10,0x5A,0x1F,0x47,0x3A>>
ISWbemRefresher STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	get__NewEnum PTR
	Item PTR
	get_Count PTR
	Add PTR
	AddEnum PTR
	Remove PTR
	Refresh PTR
	get_AutoReconnect PTR
	put_AutoReconnect PTR
	DeleteAll PTR
ENDS

#define GUID_IID_ISWbemRefreshableItem <0x5AD4BF92,0xDAAB,0x11d3,<0xB3,0x8F,0x00,0x10,0x5A,0x1F,0x47,0x3A>>
ISWbemRefreshableItem STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	get_Index PTR
	get_Refresher PTR
	get_IsSet PTR
	get_Object PTR
	get_ObjectSet PTR
	Remove PTR
ENDS

#define GUID_CLSID_SWbemLocator <0x76A64158,0xCB41,0x11d1,<0x8B,0x02,0x00,0x60,0x08,0x06,0xD9,0xB6>>
#define GUID_CLSID_SWbemNamedValueSet <0x9AED384E,0xCE8B,0x11d1,<0x8B,0x05,0x00,0x60,0x08,0x06,0xD9,0xB6>>
#define GUID_CLSID_SWbemObjectPath <0x5791BC26,0xCE9C,0x11d1,<0x97,0xBF,0x00,0x00,0xF8,0x1E,0x84,0x9C>>
#define GUID_CLSID_SWbemLastError <0xC2FEEEAC,0xCFCD,0x11d1,<0x8B,0x05,0x00,0x60,0x08,0x06,0xD9,0xB6>>
#define GUID_CLSID_SWbemSink <0x75718C9A,0xF029,0x11d1,<0xA1,0xAC,0x00,0xC0,0x4F,0xB6,0xC2,0x23>>
#define GUID_CLSID_SWbemDateTime <0x47DFBE54,0xCF76,0x11d3,<0xB38F,0x00,0x10,0x5A,0x1F,0x47,0x3A>>
#define GUID_CLSID_SWbemRefresher <0xD269BF5C,0xD9C1,0x11d3,<0xB3,0x8F,0x00,0x10,0x5A,0x1F,0x47,0x3A>>
#define GUID_CLSID_SWbemServices <0x04B83D63,0x21AE,0x11d2,<0x8B,0x33,0x00,0x60,0x08,0x06,0xD9,0xB6>>
#define GUID_CLSID_SWbemServicesEx <0x62E522DC,0x8CF3,0x40a8,<0x8B,0x2E,0x37,0xD5,0x95,0x65,0x1E,0x40>>
#define GUID_CLSID_SWbemObject <0x04B83D62,0x21AE,0x11d2,<0x8B,0x33,0x00,0x60,0x08,0x06,0xD9,0xB6>>
#define GUID_CLSID_SWbemObjectEx <0xD6BDAFB2,0x9435,0x491f,<0xBB,0x87,0x6A,0xA0,0xF0,0xBC,0x31,0xA2>>
#define GUID_CLSID_SWbemObjectSet <0x04B83D61,0x21AE,0x11d2,<0x8B,0x33,0x00,0x60,0x08,0x06,0xD9,0xB6>>
#define GUID_CLSID_SWbemNamedValue <0x04B83D60,0x21AE,0x11d2,<0x8B,0x33,0x00,0x60,0x08,0x06,0xD9,0xB6>>
#define GUID_CLSID_SWbemQualifier <0x04B83D5F,0x21AE,0x11d2,<0x8B,0x33,0x00,0x60,0x08,0x06,0xD9,0xB6>>
#define GUID_CLSID_SWbemQualifierSet <0x04B83D5E,0x21AE,0x11d2,<0x8B,0x33,0x00,0x60,0x08,0x06,0xD9,0xB6>>
#define GUID_CLSID_SWbemProperty <0x04B83D5D,0x21AE,0x11d2,<0x8B,0x33,0x00,0x60,0x08,0x06,0xD9,0xB6>>
#define GUID_CLSID_SWbemPropertySet <0x04B83D5C,0x21AE,0x11d2,<0x8B,0x33,0x00,0x60,0x08,0x06,0xD9,0xB6>>
#define GUID_CLSID_SWbemMethod <0x04B83D5B,0x21AE,0x11d2,<0x8B,0x33,0x00,0x60,0x08,0x06,0xD9,0xB6>>
#define GUID_CLSID_SWbemMethodSet <0x04B83D5A,0x21AE,0x11d2,<0x8B,0x33,0x00,0x60,0x08,0x06,0xD9,0xB6>>
#define GUID_CLSID_SWbemEventSource <0x04B83D58,0x21AE,0x11d2,<0x8B,0x33,0x00,0x60,0x08,0x06,0xD9,0xB6>>
#define GUID_CLSID_SWbemSecurity <0xB54D66E9,0x2287,0x11d2,<0x8B,0x33,0x00,0x60,0x08,0x06,0xD9,0xB6>>
#define GUID_CLSID_SWbemPrivilege <0x26EE67BC,0x5804,0x11d2,<0x8B,0x4A,0x00,0x60,0x08,0x06,0xD9,0xB6>>
#define GUID_CLSID_SWbemPrivilegeSet <0x26EE67BE,0x5804,0x11d2,<0x8B,0x4A,0x00,0x60,0x08,0x06,0xD9,0xB6>>
#define GUID_CLSID_SWbemRefreshableItem <0x8C6854BC,0xDE4B,0x11d3,<0xB3,0x90,0x00,0x10,0x5A,0x1F,0x47,0x3A>>

#define WBEMS_DISPID_OBJECT_READY 1
#define WBEMS_DISPID_COMPLETED 2
#define WBEMS_DISPID_PROGRESS 3
#define WBEMS_DISPID_OBJECT_PUT 4
#define WBEMS_DISPID_CONNECTION_READY 5

#endif /* _WBEMDISH_H */
