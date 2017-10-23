/*++

   Copyright    (c)    2004    Microsoft Corporation

   Module  Name :
     hostable_web_core.h

   Abstract:

     Hostable web core enables processes other than the W3WP.exe to load the IISCore 
     and effectively host pages without having to reverse-engineer IIS W3 core 
     functionality (ISAPI filter/extension support, authentication, authorization, 
     configuring http.sys, compression, etc.).  

     This header file defines the interface between the hostable web core and the hosting process

     Note: Only single instance of the hostable web core will be allowed within one process
     Attempt to initialize more than one will result in failure

   Environment:
       Win32 - User Mode

   Project:
      IIS7

--*/

#ifndef HOSTABLE_WEB_CORE_H
#define HOSTABLE_WEB_CORE_H

// 
// The actual names of the hostable webcore DLL and the start/stop entry points
//

#IFDEF LINKFILES
	#IFNDEF HWEBCORE_DLL
	#DEFINE HWEBCORE_DLL
		#dynamiclinkfile hwebcore.dll
	#ENDIF
#ENDIF

#define WEB_CORE_DLL_NAMEW                L"hwebcore.dll"
#define WEB_CORE_DLL_NAMEA                A"hwebcore.dll"
#define WEB_CORE_ACTIVATE_DLL_ENTRY      A"WebCoreActivate"
#define WEB_CORE_SHUTDOWN_DLL_ENTRY      A"WebCoreShutdown"

#IFDEF UNICODE
	#define WEB_CORE_DLL_NAME WEB_CORE_DLL_NAMEW
#ELSE
	#define WEB_CORE_DLL_NAME WEB_CORE_DLL_NAMEA
#ENDIF

#endif


