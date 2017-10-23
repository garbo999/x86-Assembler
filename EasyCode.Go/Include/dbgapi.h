#ifndef DBGAPI_H
#define DBGAPI_H

/* Debug Message and Zone APIs (Windows CE) */

#IFDEF LINKFILES
	#IFNDEF COREDLL_DLL
	#DEFINE COREDLL_DLL
		#dynamiclinkfile coredll.dll
	#ENDIF
#ENDIF

DBGPARAM STRUCT
	lpszName DW 32 DUP
	rglpszZones DW 512 DUP
	ulZoneMask DD
ENDS

#endif
