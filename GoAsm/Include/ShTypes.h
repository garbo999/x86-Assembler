#ifndef SHTYPES_H
#define SHTYPES_H

/* header files for imported files */
#IFNDEF WTYPES_H
	#include "wtypes.h"
#ENDIF

//+-------------------------------------------------------------------------
//
//  Microsoft Windows
//  Copyright (c) Microsoft Corporation. All rights reserved.
//
//--------------------------------------------------------------------------
//===========================================================================
//
// Object identifiers in the explorer's name space (ItemID and IDList)
//
//  All the items that the user can browse with the explorer (such as files,
// directories, servers, work-groups, etc.) has an identifier which is unique
// among items within the parent folder. Those identifiers are called item
// IDs (SHITEMID). Since all its parent folders have their own item IDs,
// any items can be uniquely identified by a list of item IDs, which is called
// an ID list (ITEMIDLIST).
//
//  ID lists are almost always allocated by the task allocator (see some
// description below as well as OLE 2.0 SDK) and may be passed across
// some of shell interfaces (such as IShellFolder). Each item ID in an ID list
// is only meaningful to its parent folder (which has generated it), and all
// the clients must treat it as an opaque binary data except the first two
// bytes, which indicates the size of the item ID.
//
//  When a shell extension -- which implements the IShellFolder interace --
// generates an item ID, it may put any information in it, not only the data
// with that it needs to identifies the item, but also some additional
// information, which would help implementing some other functions efficiently.
// For example, the shell's IShellFolder implementation of file system items
// stores the primary (long) name of a file or a directory as the item
// identifier, but it also stores its alternative (short) name, size and date
// etc.
//
//  When an ID list is passed to one of shell APIs (such as SHGetPathFromIDList),
// it is always an absolute path -- relative from the root of the name space,
// which is the desktop folder. When an ID list is passed to one of IShellFolder
// member function, it is always a relative path from the folder (unless it
// is explicitly specified).
//
//===========================================================================
//
// SHITEMID -- Item ID  (mkid)
//     USHORT      cb;             // Size of the ID (including cb itself)
//     BYTE        abID[];         // The item ID (variable length)
//

#IFNDEF SHITEMID
SHITEMID STRUCT
	cb DW
	abID DB
ENDS
#ENDIF // SHITEMID

#IFNDEF ITEMIDLIST
ITEMIDLIST STRUCT
     mkid SHITEMID <>
ENDS
#ENDIF // ITEMIDLIST

//-------------------------------------------------------------------------
//
// struct STRRET
//
// structure for returning strings from IShellFolder member functions
//
//-------------------------------------------------------------------------
//
//  uType indicate which union member to use 
//    STRRET_WSTR    Use STRRET.pOleStr     must be freed by caller of GetDisplayNameOf
//    STRRET_OFFSET  Use STRRET.uOffset     Offset into SHITEMID for ANSI string 
//    STRRET_CSTR    Use STRRET.cStr        ANSI Buffer
//
STRRET_WSTR	= 0
STRRET_OFFSET	= 0x1
STRRET_CSTR	= 0x2

#IFNDEF STRRET
STRRET STRUCT
	uType DD
	UNION
		pOleStr PTR
		uOffset DD
		cStr DB 260 DUP
	ENDUNION
ENDS
#ENDIF // STRRET

//-------------------------------------------------------------------------
//
// struct SHELLDETAILS
//
// structure for returning strings from IShellDetails
//
//-------------------------------------------------------------------------
//
//  fmt;            // LVCFMT_* value (header only)
//  cxChar;         // Number of 'average' characters (header only)
//  str;            // String information
//

#IFNDEF SHELLDETAILS
SHELLDETAILS STRUCT
	fmt DD
	cxChar DD
	str STRRET <>
ENDS
#ENDIF // SHELLDETAILS

#endif


