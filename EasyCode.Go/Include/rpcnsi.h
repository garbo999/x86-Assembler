#ifndef RPCNSI_H
#define RPCNSI_H

/* Windows Name Service Independent API definitions */

#IFDEF LINKFILES
	#dynamiclinkfile Rpcns4.dll
#ENDIF

#define RPC_C_NS_SYNTAX_DEFAULT  0
#define RPC_C_NS_SYNTAX_DCE  3

#define RPC_C_PROFILE_DEFAULT_ELT  0
#define RPC_C_PROFILE_ALL_ELT  1
#define RPC_C_PROFILE_ALL_ELTS  RPC_C_PROFILE_ALL_ELT
#define RPC_C_PROFILE_MATCH_BY_IF  2
#define RPC_C_PROFILE_MATCH_BY_MBR  3
#define RPC_C_PROFILE_MATCH_BY_BOTH  4

#define RPC_C_NS_DEFAULT_EXP_AGE  (-1)

#IFDEF UNICODE
	#define RpcNsBindingLookupBegin RpcNsBindingLookupBeginW
	#define RpcNsBindingImportBegin RpcNsBindingImportBeginW
	#define RpcNsBindingExport RpcNsBindingExportW
	#define RpcNsBindingUnexport RpcNsBindingUnexportW
	#define RpcNsGroupDelete RpcNsGroupDeleteW
	#define RpcNsGroupMbrAdd RpcNsGroupMbrAddW
	#define RpcNsGroupMbrRemove RpcNsGroupMbrRemoveW
	#define RpcNsGroupMbrInqBegin RpcNsGroupMbrInqBeginW
	#define RpcNsGroupMbrInqNext RpcNsGroupMbrInqNextW
	#define RpcNsEntryExpandName RpcNsEntryExpandNameW
	#define RpcNsEntryObjectInqBegin RpcNsEntryObjectInqBeginW
	#define RpcNsMgmtBindingUnexport RpcNsMgmtBindingUnexportW
	#define RpcNsMgmtEntryCreate RpcNsMgmtEntryCreateW
	#define RpcNsMgmtEntryDelete RpcNsMgmtEntryDeleteW
	#define RpcNsMgmtEntryInqIfIds RpcNsMgmtEntryInqIfIdsW
	#define RpcNsProfileDelete RpcNsProfileDeleteW
	#define RpcNsProfileEltAdd RpcNsProfileEltAddW
	#define RpcNsProfileEltRemove RpcNsProfileEltRemoveW
	#define RpcNsProfileEltInqBegin RpcNsProfileEltInqBeginW
	#define RpcNsProfileEltInqNext RpcNsProfileEltInqNextW
#else
	#define RpcNsBindingLookupBegin RpcNsBindingLookupBeginA
	#define RpcNsBindingImportBegin RpcNsBindingImportBeginA
	#define RpcNsBindingExport RpcNsBindingExportA
	#define RpcNsBindingUnexport RpcNsBindingUnexportA
	#define RpcNsGroupDelete RpcNsGroupDeleteA
	#define RpcNsGroupMbrAdd RpcNsGroupMbrAddA
	#define RpcNsGroupMbrRemove RpcNsGroupMbrRemoveA
	#define RpcNsGroupMbrInqBegin RpcNsGroupMbrInqBeginA
	#define RpcNsGroupMbrInqNext RpcNsGroupMbrInqNextA
	#define RpcNsEntryExpandName RpcNsEntryExpandNameA
	#define RpcNsEntryObjectInqBegin RpcNsEntryObjectInqBeginA
	#define RpcNsMgmtBindingUnexport RpcNsMgmtBindingUnexportA
	#define RpcNsMgmtEntryCreate RpcNsMgmtEntryCreateA
	#define RpcNsMgmtEntryDelete RpcNsMgmtEntryDeleteA
	#define RpcNsMgmtEntryInqIfIds RpcNsMgmtEntryInqIfIdsA
	#define RpcNsProfileDelete RpcNsProfileDeleteA
	#define RpcNsProfileEltAdd RpcNsProfileEltAddA
	#define RpcNsProfileEltRemove RpcNsProfileEltRemoveA
	#define RpcNsProfileEltInqBegin RpcNsProfileEltInqBeginA
	#define RpcNsProfileEltInqNext RpcNsProfileEltInqNextA
#endif /* UNICODE */

#endif /* _RPCNSI_H */
