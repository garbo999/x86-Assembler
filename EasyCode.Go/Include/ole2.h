#ifndef OLE2_H
#define OLE2_H

#DEFINE OLE2_H_REQVER 100

/* Windows Linking and Embedding API definitions */

/*
Dependancies
winerror.h
objbase.h
oleauto.h
oleidl.h
*/

/*
Switches used
None
*/

#IFDEF LINKFILES
	#dynamiclinkfile ole32.dll
#ENDIF

#IFNDEF WINERROR_H
	#include winerror.h // WIN32/64
#ENDIF

#IFNDEF OBJBASE_H
	#include objbase.h // WIN32/64
#ENDIF

#IFNDEF OLEAUTO_H
	#include oleauto.h // WIN32/64
#ENDIF

#define E_DRAW  VIEW_E_DRAW

#define DATA_E_FORMATETC  DV_E_FORMATETC

#define OLEIVERB_PRIMARY  (0)
#define OLEIVERB_SHOW  (-1)
#define OLEIVERB_OPEN  (-2)
#define OLEIVERB_HIDE  (-3)
#define OLEIVERB_UIACTIVATE  (-4)
#define OLEIVERB_INPLACEACTIVATE  (-5)
#define OLEIVERB_DISCARDUNDOSTATE  (-6)

#define EMBDHLP_INPROC_HANDLER  0x0000
#define EMBDHLP_INPROC_SERVER  0x0001
#define EMBDHLP_CREATENOW  0x00000000
#define EMBDHLP_DELAYCREATE  0x00010000

#define OLECREATE_LEAVERUNNING  0x00000001

#IFNDEF OLEIDL_H
	#include oleidl.h // WIN32/64
#ENDIF

/* OLE 1.0 declarations */

DRAG_FLAVORINFO STRUCT
	cfFormat DD
	FlavorFlags DD		// Flavor Flags as specified by the DragManager
	fAddData DD			// If true, the data is added with the flavor
	reserved DD			// must be NULL
ENDS

OleMBarRec STRUCT
	reserved DD
ENDS

#define noAxis  3

OLESTREAMVTBL STRUCT
	Get PTR
	Put PTR
ENDS

OLESTREAM STRUCT
	lpstbl PTR
ENDS

#endif

