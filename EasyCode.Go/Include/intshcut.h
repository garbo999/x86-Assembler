#ifndef INTSHCUT_H
#define INTSHCUT_H

/* Windows Internet Shortcut interface definitions */

#IFDEF LINKFILES
	#dynamiclinkfile url.dll
#ENDIF

#include isguids.h

#IFNDEF BASECOM_H
	#include "BaseCOM.h"
#ENDIF

;#define E_FLAGS  MAKE_SCODE(SEVERITY_ERROR,FACILITY_ITF,0x1000)
;#define IS_E_EXEC_FAILED  MAKE_SCODE(SEVERITY_ERROR,FACILITY_ITF,0x2002)
;#define URL_E_INVALID_SYNTAX  MAKE_SCODE(SEVERITY_ERROR,FACILITY_ITF,0x1001)
;#define URL_E_UNREGISTERED_PROTOCOL  MAKE_SCODE(SEVERITY_ERROR,FACILITY_ITF,0x1002)

IURL_SETURL_FL_GUESS_PROTOCOL = 0x0001
IURL_SETURL_FL_USE_DEFAULT_PROTOCOL = 0x0002

IURL_INVOKECOMMAND_FL_ALLOW_UI = 0x0001
IURL_INVOKECOMMAND_FL_USE_DEFAULT_VERB = 0x0002
IURL_INVOKECOMMAND_FL_DDEWAIT = 0x0004

TRANSLATEURL_FL_GUESS_PROTOCOL = 0x0001
TRANSLATEURL_FL_USE_DEFAULT_PROTOCOL = 0x0002

URLASSOCDLG_FL_USE_DEFAULT_NAME = 0x0001
URLASSOCDLG_FL_REGISTER_ASSOC = 0x0002

MIMEASSOCDLG_FL_REGISTER_ASSOC = 0x0001

URLINVOKECOMMANDINFOA STRUCT
	dwcbSize DD
	dwFlags DD
	hwndParent HANDLE
	pcszVerb PTR
ENDS

URLINVOKECOMMANDINFOW STRUCT
	dwcbSize DD
	dwFlags DD
	hwndParent HANDLE
	pcszVerb PTR
ENDS

IUniformResourceLocatorA STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	SetURL PTR
	GetURL PTR
	InvokeCommand PTR
ENDS

IUniformResourceLocatorW STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	SetURL PTR
	GetURL PTR
	InvokeCommand PTR
ENDS

#IFDEF UNICODE
	#define URLINVOKECOMMANDINFO URLINVOKECOMMANDINFOW
	#define IUniformResourceLocator IUniformResourceLocatorW
	#define IUniformResourceLocatorVtbl IUniformResourceLocatorWVtbl
	#define PIUniformResourceLocator PIUniformResourceLocatorW
	#define CIUniformResourceLocator CIUniformResourceLocatorW
	#define PCIUniformResourceLocator PCIUniformResourceLocatorW
	#define TranslateURL TranslateURLW
	#define MIMEAssociationDialog MIMEAssociationDialogW
	#define URLAssociationDialog URLAssociationDialogW
#else
	#define URLINVOKECOMMANDINFO URLINVOKECOMMANDINFOA
	#define IUniformResourceLocator IUniformResourceLocatorA
	#define IUniformResourceLocatorVtbl IUniformResourceLocatorAVtbl
	#define PIUniformResourceLocator PIUniformResourceLocatorA
	#define CIUniformResourceLocator CIUniformResourceLocatorA
	#define PCIUniformResourceLocator PCIUniformResourceLocatorA
	#define TranslateURL TranslateURLA
	#define MIMEAssociationDialog MIMEAssociationDialogA
	#define URLAssociationDialog URLAssociationDialogA
#endif

#endif
