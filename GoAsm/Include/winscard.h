#ifndef WINSCARD_H
#define WINSCARD_H

/* Windows SmartCard Subsystem definitions */

#IFNDEF WTYPES_H
	#include wtypes.h // WIN3264
#ENDIF
#IFNDEF WINIOCTL_H
	#include winioctl.h // WIN3264
#ENDIF
#IFNDEF WINSMCRD_H
	#include winsmcrd.h // WIN3264
#ENDIF

#ifndef SCARD_S_SUCCESS
	#include SCardErr.h // WIN3264
#endif

#IFDEF LINKFILES
	#dynamiclinkfile Winscard.dll
#ENDIF

#define SCARD_AUTOALLOCATE  -1

#define SCARD_SCOPE_USER  0
#define SCARD_SCOPE_TERMINAL  1
#define SCARD_SCOPE_SYSTEM  2

#define SCARD_ALL_READERS  "SCard$AllReaders\000"
#define SCARD_DEFAULT_READERS  "SCard$DefaultReaders\000"
#define SCARD_LOCAL_READERS  "SCard$LocalReaders\000"
#define SCARD_SYSTEM_READERS  "SCard$SystemReaders\000"

#define SCARD_PROVIDER_PRIMARY  1
#define SCARD_PROVIDER_CSP  2

#define SCARD_STATE_UNAWARE  0x00000000
#define SCARD_STATE_IGNORE  0x00000001
#define SCARD_STATE_CHANGED  0x00000002
#define SCARD_STATE_UNKNOWN  0x00000004
#define SCARD_STATE_UNAVAILABLE  0x00000008
#define SCARD_STATE_EMPTY  0x00000010
#define SCARD_STATE_PRESENT  0x00000020
#define SCARD_STATE_ATRMATCH  0x00000040
#define SCARD_STATE_EXCLUSIVE  0x00000080
#define SCARD_STATE_INUSE  0x00000100
#define SCARD_STATE_MUTE  0x00000200
#define SCARD_STATE_UNPOWERED  0x00000400

#define SCARD_SHARE_EXCLUSIVE  1
#define SCARD_SHARE_SHARED  2
#define SCARD_SHARE_DIRECT  3

#define SCARD_LEAVE_CARD  0
#define SCARD_RESET_CARD  1
#define SCARD_UNPOWER_CARD  2
#define SCARD_EJECT_CARD  3

#define SC_DLG_MINIMAL_UI  0x01
#define SC_DLG_NO_UI  0x02
#define SC_DLG_FORCE_UI  0x04

#define SCERR_NOCARDNAME  0x4000
#define SCERR_NOGUIDS  0x8000

SCARD_READERSTATEA STRUCT
	szReader PTR
	pvUserData PTR
	dwCurrentState DD
	dwEventState DD
	cbAtr DD
	rgbAtr DB 36 DUP (?)
ENDS

SCARD_READERSTATEW STRUCT
	szReader PTR
	pvUserData PTR
	dwCurrentState DD
	dwEventState DD
	cbAtr DD
	rgbAtr DW 36 DUP (?)
ENDS

OPENCARD_SEARCH_CRITERIAA STRUCT
	dwStructSize DD
	lpstrGroupNames PTR
	nMaxGroupNames DD
	rgguidInterfaces PTR
	cguidInterfaces DD
	lpstrCardNames PTR
	nMaxCardNames DD
	lpfnCheck PTR
	lpfnConnect PTR
	lpfnDisconnect PTR
	pvUserData PTR
	dwShareMode DD
	dwPreferredProtocols DD
ENDS

OPENCARD_SEARCH_CRITERIAW STRUCT
	dwStructSize DD
	lpstrGroupNames PTR
	nMaxGroupNames DD
	rgguidInterfaces PTR
	cguidInterfaces DD
	lpstrCardNames PTR
	nMaxCardNames DD
	lpfnCheck PTR
	lpfnConnect PTR
	lpfnDisconnect PTR
	pvUserData PTR
	dwShareMode DD
	dwPreferredProtocols DD
ENDS

OPENCARDNAME_EXA STRUCT
	dwStructSize DD
	hSCardContext HANDLE
	hwndOwner HANDLE
	dwFlags DD
	lpstrTitle PTR
	lpstrSearchDesc PTR
	hIcon HANDLE
	pOpenCardSearchCriteria PTR
	lpfnConnect PTR
	pvUserData PTR
	dwShareMode DD
	dwPreferredProtocols DD
	lpstrRdr PTR
	nMaxRdr DD
	lpstrCard PTR
	nMaxCard DD
	dwActiveProtocol DD
	hCardHandle HANDLE
ENDS

OPENCARDNAME_EXW STRUCT
	dwStructSize DD
	hSCardContext HANDLE
	hwndOwner HANDLE
	dwFlags DD
	lpstrTitle PTR
	lpstrSearchDesc PTR
	hIcon HANDLE
	pOpenCardSearchCriteria PTR
	lpfnConnect PTR
	pvUserData PTR
	dwShareMode DD
	dwPreferredProtocols DD
	lpstrRdr PTR
	nMaxRdr DD
	lpstrCard PTR
	nMaxCard DD
	dwActiveProtocol DD
	hCardHandle HANDLE
ENDS

OPENCARDNAMEA STRUCT
	dwStructSize DD
	hwndOwner HANDLE
	hSCardContext HANDLE
	lpstrGroupNames PTR
	nMaxGroupNames DD
	lpstrCardNames PTR
	nMaxCardNames DD
	rgguidInterfaces PTR
	cguidInterfaces DD
	lpstrRdr PTR
	nMaxRdr DD
	lpstrCard PTR
	nMaxCard DD
	lpstrTitle PTR
	dwFlags DD
	pvUserData PTR
	dwShareMode DD
	dwPreferredProtocols DD
	dwActiveProtocol DD
	lpfnConnect PTR
	lpfnCheck PTR
	lpfnDisconnect PTR
	hCardHandle HANDLE
ENDS

OPENCARDNAMEW STRUCT
	dwStructSize DD
	hwndOwner HANDLE
	hSCardContext HANDLE
	lpstrGroupNames PTR
	nMaxGroupNames DD
	lpstrCardNames PTR
	nMaxCardNames DD
	rgguidInterfaces PTR
	cguidInterfaces DD
	lpstrRdr PTR
	nMaxRdr DD
	lpstrCard PTR
	nMaxCard DD
	lpstrTitle PTR
	dwFlags DD
	pvUserData PTR
	dwShareMode DD
	dwPreferredProtocols DD
	dwActiveProtocol DD
	lpfnConnect PTR
	lpfnCheck PTR
	lpfnDisconnect PTR
	hCardHandle HANDLE
ENDS


#IFDEF UNICODE
	#define SCARD_READERSTATE SCARD_READERSTATEW
	#define OPENCARD_SEARCH_CRITERIA OPENCARD_SEARCH_CRITERIAW
	#define OPENCARDNAME_EX OPENCARDNAME_EXW
	#define OPENCARDNAME OPENCARDNAMEW
	#define SCardListReaderGroups SCardListReaderGroupsW
	#define SCardListReaders SCardListReadersW
	#define SCardListCards SCardListCardsW
	#define SCardListInterfaces SCardListInterfacesW
	#define SCardGetProviderId SCardGetProviderIdW
	#define SCardGetCardTypeProviderName SCardGetCardTypeProviderNameW
	#define SCardIntroduceReaderGroup SCardIntroduceReaderGroupW
	#define SCardForgetReaderGroup SCardForgetReaderGroupW
	#define SCardIntroduceReader SCardIntroduceReaderW
	#define SCardForgetReader SCardForgetReaderW
	#define SCardAddReaderToGroup SCardAddReaderToGroupW
	#define SCardRemoveReaderFromGroup SCardRemoveReaderFromGroupW
	#define SCardIntroduceCardType SCardIntroduceCardTypeW
	#define SCardSetCardTypeProviderName SCardSetCardTypeProviderNameW
	#define SCardForgetCardType SCardForgetCardTypeW
	#define SCardLocateCards SCardLocateCardsW
	#define SCardGetStatusChange SCardGetStatusChangeW
	#define SCardConnect SCardConnectW
	#define SCardStatus SCardStatusW
	#define SCardUIDlgSelectCard SCardUIDlgSelectCardW
	#define GetOpenCardName GetOpenCardNameW
#else
	#define SCARD_READERSTATE SCARD_READERSTATEA
	#define OPENCARD_SEARCH_CRITERIA OPENCARD_SEARCH_CRITERIAA
	#define OPENCARDNAME_EX OPENCARDNAME_EXA
	#define OPENCARDNAME OPENCARDNAMEA
	#define SCardListReaderGroups SCardListReaderGroupsA
	#define SCardListReaders SCardListReadersA
	#define SCardListCards SCardListCardsA
	#define SCardListInterfaces SCardListInterfacesA
	#define SCardGetProviderId SCardGetProviderIdA
	#define SCardGetCardTypeProviderName SCardGetCardTypeProviderNameA
	#define SCardIntroduceReaderGroup SCardIntroduceReaderGroupA
	#define SCardForgetReaderGroup SCardForgetReaderGroupA
	#define SCardIntroduceReader SCardIntroduceReaderA
	#define SCardForgetReader SCardForgetReaderA
	#define SCardAddReaderToGroup SCardAddReaderToGroupA
	#define SCardRemoveReaderFromGroup SCardRemoveReaderFromGroupA
	#define SCardIntroduceCardType SCardIntroduceCardTypeA
	#define SCardSetCardTypeProviderName SCardSetCardTypeProviderNameA
	#define SCardForgetCardType SCardForgetCardTypeA
	#define SCardLocateCards SCardLocateCardsA
	#define SCardGetStatusChange SCardGetStatusChangeA
	#define SCardConnect SCardConnectA
	#define SCardStatus SCardStatusA
	#define SCardUIDlgSelectCard SCardUIDlgSelectCardA
	#define GetOpenCardName GetOpenCardNameA
#endif /* UNICODE */

#endif /* _WINSCARD_H */
