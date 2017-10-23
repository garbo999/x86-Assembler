//+---------------------------------------------------------------------------
//
//  Microsoft Windows
//  Copyright (C) Microsoft Corporation, 1997-1999.
//
//  File:       macwin32.h
//
//  Contents:   Macintosh Win32 function overrides for porting Win32 applications.
//
//
//----------------------------------------------------------------------------

#ifdef MACWIN32_H
#define MACWIN32_H

// These functions in the Win32 SDK already exist on the native Macintosh OS.
// To clarify that the user is calling the Win32 ported version rather than the
// native MacOS version, the Win32 versions are prefixed Afx.

//   mmsystem.h
#ifdef MMSYSTEM_H

#define CloseDriver AfxCloseDriver
#define OpenDriver AfxOpenDriver

#endif //INC_MMSYSTEM

//  winbase.h
#ifdef WINBASE_H

#define FlushInstructionCache		AfxFlushInstructionCache
#define GetCurrentProcess			AfxGetCurrentProcess
#define GetCurrentThread			AfxGetCurrentThread
#define LoadResource				AfxLoadResource
#define GetFileSize					AfxGetFileSize

#endif // WINBASE_H

// **************   wingdi.h
#ifdef WINGDI_H

#define AnimatePalette				AfxAnimatePalette
#define EqualRgn					AfxEqualRgn
#define FillRgn						AfxFillRgn
#define FrameRgn					AfxFrameRgn
#define GetPixel					AfxGetPixel
#define InvertRgn					AfxInvertRgn
#define LineTo						AfxLineTo
#define OffsetRgn					AfxOffsetRgn
#define PaintRgn					AfxPaintRgn
#define ResizePalette				AfxResizePalette
#define SetRectRgn					AfxSetRectRgn
#define GetPath						AfxGetPath
#define Polygon						AfxPolygon

#endif // WINGDI_H

// winnls.h
#ifdef  WINNLS_H

#define CompareStringA				AfxCompareStringA
#define CompareStringW				AfxCompareStringW
#define GetLocaleInfoA				AfxGetLocaleInfoA
#define GetLocaleInfoW				AfxGetLocaleInfoW

#endif // WINNLS_H

// winreg.h
#ifdef WINREG_H

#define RegCloseKey					AfxRegCloseKey
#define RegCreateKeyA				AfxRegCreateKeyA
#define RegCreateKeyW				AfxRegCreateKeyW
#define	RegDeleteKeyA				AfxRegDeleteKeyA
#define RegDeleteKeyW				AfxRegDeleteKeyW
#define RegDeleteValueA				AfxRegDeleteValueA	
#define RegDeleteValueW				AfxRegDeleteValueW
#define RegEnumKeyA					AfxRegEnumKeyA
#define RegEnumKeyW					AfxRegEnumKeyW
#define RegEnumValueA				AfxRegEnumValueA
#define RegEnumValueW				AfxRegEnumValueW
#define RegOpenKeyA					AfxRegOpenKeyA
#define RegOpenKeyW					AfxRegOpenKeyW
#define RegQueryValueA				AfxRegQueryValueA
#define RegQueryValueW				AfxRegQueryValueW
#define RegQueryValueExA			AfxRegQueryValueExA
#define RegQueryValueExW			AfxRegQueryValueExW
#define RegSetValueA				AfxRegSetValueA
#define RegSetValueW				AfxRegSetValueW
#define RegSetValueExA				AfxRegSetValueExA
#define RegSetValueExW				AfxRegSetValueExW

#endif // WINREG_H

//  winuser.h
#ifdef WINUSER_H

#define SendMessageA				AfxSendMessageA
#define SendMessageW				AfxSendMessageW
#define GetDoubleClickTime			AfxGetDoubleClickTime
#define GetClassInfoA				AfxGetClassInfoA
#define GetClassInfoW				AfxGetClassInfoW
#define ShowWindow					AfxShowWindow
#define CloseWindow					AfxCloseWindow
#define MoveWindow					AfxMoveWindow
#define IsWindowVisible				AfxIsWindowVisible
#define GetMenu						AfxGetMenu
#define DrawMenuBar					AfxDrawMenuBar
#define InsertMenuA					AfxInsertMenuA
#define InsertMenuW					AfxInsertMenuW
#define AppendMenuA					AfxAppendMenuA
#define AppendMenuW					AfxAppendMenuW
#define DeleteMenu					AfxDeleteMenu
#define InsertMenuItemA				AfxInsertMenuItemA
#define InsertMenuItemW				AfxInsertMenuItemW
#define DrawTextA					AfxDrawTextA			
#define DrawTextW					AfxDrawTextW
#define ShowCursor					AfxShowCursor
#define SetCursor					AfxSetCursor
#define GetCursor					AfxGetCursor
#define FillRect					AfxFillRect
#define FrameRect					AfxFrameRect
#define InvertRect					AfxInvertRect
#define SetRect						AfxSetRect
#define UnionRect					AfxUnionRect
#define OffsetRect					AfxOffsetRect
#define EqualRect					AfxEqualRect
#define PtInRect					AfxPtInRect
#define GetParent					AfxGetParent	
#define FindWindowA					AfxFindWindowA
#define FindWindowW					AfxFindWindowW

;#define AfxGetNextWindow(hWnd, wCmd) GetWindow(hWnd, wCmd)

#endif // WINUSER_H

#endif


