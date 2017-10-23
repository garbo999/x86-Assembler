;=============================================================;
;          rpcnsi.inc file for Easy Code visual IDE           ;
;            (made for the GoAsm compiler version)            ;
;                                                             ;
;           Version 1.0.00 (created on March, 2008)           ;
;                                                             ;
;      Please report any bug you find (asm@easycode.cat)      ;
;                                                             ;
;                Do not modify this file!!                    ;
;=============================================================;

#IFNDEF RPCNSI_INC
#Define RPCNSI_INC

#Define RPC_C_NS_SYNTAX_DEFAULT             0
#Define RPC_C_NS_SYNTAX_DCE                 3

#Define RPC_C_PROFILE_DEFAULT_ELT           0
#Define RPC_C_PROFILE_ALL_ELT               1
#Define RPC_C_PROFILE_ALL_ELTS              RPC_C_PROFILE_ALL_ELT
#Define RPC_C_PROFILE_MATCH_BY_IF           2
#Define RPC_C_PROFILE_MATCH_BY_MBR          3
#Define RPC_C_PROFILE_MATCH_BY_BOTH         4

#Define RPC_C_NS_DEFAULT_EXP_AGE            (-1)

#IF STRINGS UNICODE
	#Define RpcNsBindingLookupBegin RpcNsBindingLookupBeginW
	#Define RpcNsBindingImportBegin RpcNsBindingImportBeginW
	#Define RpcNsBindingExport RpcNsBindingExportW
	#Define RpcNsBindingUnexport RpcNsBindingUnexportW
	#Define RpcNsGroupDelete RpcNsGroupDeleteW
	#Define RpcNsGroupMbrAdd RpcNsGroupMbrAddW
	#Define RpcNsGroupMbrRemove RpcNsGroupMbrRemoveW
	#Define RpcNsGroupMbrInqBegin RpcNsGroupMbrInqBeginW
	#Define RpcNsGroupMbrInqNext RpcNsGroupMbrInqNextW
	#Define RpcNsEntryExpandName RpcNsEntryExpandNameW
	#Define RpcNsEntryObjectInqBegin RpcNsEntryObjectInqBeginW
	#Define RpcNsMgmtBindingUnexport RpcNsMgmtBindingUnexportW
	#Define RpcNsMgmtEntryCreate RpcNsMgmtEntryCreateW
	#Define RpcNsMgmtEntryDelete RpcNsMgmtEntryDeleteW
	#Define RpcNsMgmtEntryInqIfIds RpcNsMgmtEntryInqIfIdsW
	#Define RpcNsProfileDelete RpcNsProfileDeleteW
	#Define RpcNsProfileEltAdd RpcNsProfileEltAddW
	#Define RpcNsProfileEltRemove RpcNsProfileEltRemoveW
	#Define RpcNsProfileEltInqBegin RpcNsProfileEltInqBeginW
	#Define RpcNsProfileEltInqNext RpcNsProfileEltInqNextW
#ELSE
	#Define RpcNsBindingLookupBegin RpcNsBindingLookupBeginA
	#Define RpcNsBindingImportBegin RpcNsBindingImportBeginA
	#Define RpcNsBindingExport RpcNsBindingExportA
	#Define RpcNsBindingUnexport RpcNsBindingUnexportA
	#Define RpcNsGroupDelete RpcNsGroupDeleteA
	#Define RpcNsGroupMbrAdd RpcNsGroupMbrAddA
	#Define RpcNsGroupMbrRemove RpcNsGroupMbrRemoveA
	#Define RpcNsGroupMbrInqBegin RpcNsGroupMbrInqBeginA
	#Define RpcNsGroupMbrInqNext RpcNsGroupMbrInqNextA
	#Define RpcNsEntryExpandName RpcNsEntryExpandNameA
	#Define RpcNsEntryObjectInqBegin RpcNsEntryObjectInqBeginA
	#Define RpcNsMgmtBindingUnexport RpcNsMgmtBindingUnexportA
	#Define RpcNsMgmtEntryCreate RpcNsMgmtEntryCreateA
	#Define RpcNsMgmtEntryDelete RpcNsMgmtEntryDeleteA
	#Define RpcNsMgmtEntryInqIfIds RpcNsMgmtEntryInqIfIdsA
	#Define RpcNsProfileDelete RpcNsProfileDeleteA
	#Define RpcNsProfileEltAdd RpcNsProfileEltAddA
	#Define RpcNsProfileEltRemove RpcNsProfileEltRemoveA
	#Define RpcNsProfileEltInqBegin RpcNsProfileEltInqBeginA
	#Define RpcNsProfileEltInqNext RpcNsProfileEltInqNextA
#ENDIF

#ENDIF ;RPCNSI_INC
