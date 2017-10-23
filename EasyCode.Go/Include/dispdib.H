/****************************************************************************/
/*                                                                          */
/*        DISPDIB.H - Include file for DisplayDib() function.               */
/*                                                                          */
/*        Note: You must include WINDOWS.H before including this file.      */
/*                                                                          */
/*        Copyright (c) 1990-1999, Microsoft Corp.  All rights reserved.    */
/*                                                                          */
/****************************************************************************/

#ifndef DISPDIB_H
#define DISPDIB_H

// DisplayDib() error return codes
#define DISPLAYDIB_NOERROR          0x0000  // success
#define DISPLAYDIB_NOTSUPPORTED     0x0001  // function not supported
#define DISPLAYDIB_INVALIDDIB       0x0002  // null or invalid DIB header
#define DISPLAYDIB_INVALIDFORMAT    0x0003  // invalid DIB format
#define DISPLAYDIB_INVALIDTASK      0x0004  // not called from current task
#define DISPLAYDIB_STOP             0x0005  // stop requested
#define DISPLAYDIB_NOTACTIVE	    0x0006  // DisplayDibWindow not foreground
#define DISPLAYDIB_BADSIZE          0x0007  //

// flags for <wFlags> parameter of DisplayDib()
#define DISPLAYDIB_NOPALETTE        0x0010  // don't set palette
#define DISPLAYDIB_NOCENTER         0x0020  // don't center image
#define DISPLAYDIB_NOWAIT           0x0040  // don't wait before returning
#define DISPLAYDIB_NOIMAGE          0x0080  // don't draw image
#define DISPLAYDIB_ZOOM2            0x0100  // stretch by 2
#define DISPLAYDIB_DONTLOCKTASK     0x0200  // don't lock current task
#define DISPLAYDIB_TEST             0x0400  // testing the command
#define DISPLAYDIB_NOFLIP           0x0800  // dont page flip
#define DISPLAYDIB_BEGIN            0x8000  // start of multiple calls
#define DISPLAYDIB_END              0x4000  // end of multiple calls

#define DISPLAYDIB_MODE             0x000F  // mask for display mode
#define DISPLAYDIB_MODE_DEFAULT     0x0000  // default display mode
#define DISPLAYDIB_MODE_320x200x8   0x0001  // 320-by-200
#define DISPLAYDIB_MODE_320x240x8   0x0005  // 320-by-240

//
//  DisplayDibWindow class.
//
//  simple interface to DISPDIB as a window class.
//  draw images and create a fullscreen window in one easy step.
//
//  advantages over calling the APIs directly.
//
//      if you show the window it will handle enabling/disabling
//      fullscreen mode when it has a activation.
//
//      while in fullscreen mode, window will be sized to
//      cover entire display preventing other apps from getting
//      clicked on. (when visible)
//
//      if window looses activation, fullscreen mode will be disabled
//      DDM_DRAW will return DISPLAYDIB_NOTACTIVE if you try to draw
//
//      forwards all mouse and keyboard events to owner, easy way
//      to take over entire screen.
//
//      alows interop with a Win32 application (via WM_COPYDATA)
//      NOTE WM_COPYDATA does not actualy copy anything if the
//      window belongs to the calling thread.  it will do a copy
//      if the window is owned by another thread....
//
//  you can use a DisplayDibWindow in two ways.....
//
//      hidden window
//
//          if the window is hidden, you must use the
//          DDM_BEGIN and DDM_END message to enable/disable
//          fullscreen mode manualy when your app is activated deactivated.
//
//      visible toplevel window
//
//          if you show the window it will take over the entire screen
//          and forward all mouse/keyboard input to its owner.
//
//          it will enter fullscreen automaticly when it is shown.
//
//          it will leave fullscreen and hide it self it another app
//          grabs the focus.
//
//  class name:     "DisplayDibWindow"
//                  class is registered when DISPDIB.DLL is loaded.
//                  as a global class.
//
//  messages:
//
//      DDM_SETFMT  set new DIB format or program a new palette
//
//		    fullscreen mode, will use best mode
//                  for displaying the passed DIB format.
//		    defaul is 320x240x8 tripple buffered
//
//                  the palette will be programed with the color
//                  table of the passed BITMAPINFOHEADER.
//
//                  the format is a BITMAPINFOHEADER followed by a color table.
//
//                  you must set a format before doing a begin, end or draw
//                  you can set a 320x200 or a 320x24 mode by selecting
//                  a DIB of the format you want.
//
//                  if you do a setfmt while fullscreen mode is active only the
//                  the palette will be changed the new size (if any) wont
//                  happen until the next begin.
//
//	    wParam = 0
//          lParam = LPBITMAPINFOHEADER
//
//          returns 0 if success else DISPLAYDIB_* error code.
//
//      DDM_DRAW    draws DIB data to fullscreen
//                  format is assumed the same as format passed to
//                  DDM_BEGIN or DDM_FMT
//
//          wParam = flags
//          lParam = bits pointer.
//
//          returns 0 if success else DISPLAYDIB_* error code.
//
//      DDM_CLOSE   destroy window *and* free the DLL
//
//      DDM_BEGIN   enter DISPDIB mode.
//          wParam = flags
//          lParam = 0
//
//          returns 0 if success else DISPLAYDIB_* error code.
//
//      DDM_END     leave DISPDIB mode.
//          wParam = flags
//          lParam = 0
//
//          returns 0 if success else DISPLAYDIB_* error code.
//
//      WM_COPYDATA allows a Win32 app to send a DDM_ message, that requires
//      a pointer.
//
//          wParam = hwnd of sender
//          lParam = PCOPYDATASTRUCT
//                  dwData      - LOWORD: DDM_* message value.
//                  dwData      - HIWORD: wParam for message
//                  lpData      - lParam (pointer to a BITMAPINFOHEADER or bits)
//                  cbData      - size of data
//
//          returns   0 if success else DISPLAYDIB_* error code.
//

#define DISPLAYDIB_WINDOW_CLASS     "DisplayDibWindow"
#define DISPLAYDIB_DLL              "DISPDIB.DLL"

#define DDM_SETFMT      WM_USER+0
#define DDM_DRAW        WM_USER+1
#define DDM_CLOSE       WM_USER+2
#define DDM_BEGIN       WM_USER+3
#define DDM_END         WM_USER+4

#endif // _DISPDIB_H
