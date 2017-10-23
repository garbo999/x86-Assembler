/*  Common defines for FCI/FDI stuff
 *
 *  Copyright (C) Microsoft Corporation
 *  All Rights Reserved.
 *
*/

#ifndef FCI_H
#define FCI_H

#IFDEF LINKFILES
	#dynamiclinkfiles cabinet.dll
#ENDIF

#DEFINE UOFF DD
#DEFINE COFF DD

#ifndef TRUE
	#define TRUE    1
#endif

#ifndef FALSE
	#define FALSE   0
#endif

#ifndef NULL
	#define NULL    0
#endif


/*   ERF - Error structure
 *
 *  This structure returns error information from FCI/FDI.  The caller should
 *  not modify this structure.
*/

ERF STRUCT
	erfOper DD
	erfType DD
	fError BOOL
ENDS

#define CB_MAX_CHUNK            32768
#define CB_MAX_DISK        0x7fffffff
#define CB_MAX_FILENAME            256
#define CB_MAX_CABINET_NAME        256
#define CB_MAX_CAB_PATH            256
#define CB_MAX_DISK_NAME           256

#DEFINE TCOMP DW

#define tcompMASK_TYPE          0x000F  // Mask for compression type
#define tcompTYPE_NONE          0x0000  // No compression
#define tcompTYPE_MSZIP         0x0001  // MSZIP
#define tcompTYPE_QUANTUM       0x0002  // Quantum
#define tcompTYPE_LZX           0x0003  // LZX
#define tcompBAD                0x000F  // Unspecified compression type

#define tcompMASK_LZX_WINDOW    0x1F00  // Mask for LZX Compression Memory
#define tcompLZX_WINDOW_LO      0x0F00  // Lowest LZX Memory (15)
#define tcompLZX_WINDOW_HI      0x1500  // Highest LZX Memory (21)
#define tcompSHIFT_LZX_WINDOW        8  // Amount to shift over to get int

#define tcompMASK_QUANTUM_LEVEL 0x00F0  // Mask for Quantum Compression Level
#define tcompQUANTUM_LEVEL_LO   0x0010  // Lowest Quantum Level (1)
#define tcompQUANTUM_LEVEL_HI   0x0070  // Highest Quantum Level (7)
#define tcompSHIFT_QUANTUM_LEVEL     4  // Amount to shift over to get int

#define tcompMASK_QUANTUM_MEM   0x1F00  // Mask for Quantum Compression Memory
#define tcompQUANTUM_MEM_LO     0x0A00  // Lowest Quantum Memory (10)
#define tcompQUANTUM_MEM_HI     0x1500  // Highest Quantum Memory (21)
#define tcompSHIFT_QUANTUM_MEM       8  // Amount to shift over to get int

#define tcompMASK_RESERVED      0xE000  // Reserved bits (high 3 bits)

FCIERR_NONE = 0                // No error

FCIERR_OPEN_SRC = 1            // Failure opening file to be stored in cabinet
                            //  erf.erfTyp has C run-time *errno* value

FCIERR_READ_SRC = 2            // Failure reading file to be stored in cabinet
                            //  erf.erfTyp has C run-time *errno* value

FCIERR_ALLOC_FAIL = 3          // Out of memory in FCI

FCIERR_TEMP_FILE = 4           // Could not create a temporary file
                            //  erf.erfTyp has C run-time *errno* value

FCIERR_BAD_COMPR_TYPE = 5      // Unknown compression type

FCIERR_CAB_FILE = 6            // Could not create cabinet file
                            //  erf.erfTyp has C run-time *errno* value

FCIERR_USER_ABORT = 7          // Client requested abort

FCIERR_MCI_FAIL = 8            // Failure compressing data

FCIERR_CAB_FORMAT_LIMIT = 9     // Data-size or file-count exceeded CAB format limits
                            // i.e. Total-bytes (uncompressed) in a CAB-folder exceeded 0x7FFF8000 (~ 2GB)
                            //  or, CAB size (compressed) exceeded 0x7FFFFFFF
                            //  or, File-count in CAB exceeded 0xFFFF


#ifndef _A_NAME_IS_UTF
	#define _A_NAME_IS_UTF  0x80
#endif

#ifndef _A_EXEC
	#define _A_EXEC         0x40
#endif


/***    CCAB - Current Cabinet
 *
 *  This structure is used for passing in the cabinet parameters to FCI,
 *  and is passed back on certain FCI callbacks to provide cabinet
 *  information to the client.
 */
CCAB struct
// longs first
	cb LONG                  // size available for cabinet on this media
	cbFolderThresh LONG      // Thresshold for forcing a new Folder
// then ints
	cbReserveCFHeader INT32   // Space to reserve in CFHEADER
	cbReserveCFFolder INT32   // Space to reserve in CFFOLDER
	cbReserveCFData INT32     // Space to reserve in CFDATA
	iCab INT32                // sequential numbers for cabinets
	iDisk INT32               // Disk number
#ifndef REMOVE_CHICAGO_M6_HACK
		fFailOnIncompressible INT32 // TRUE => Fail if a block is incompressible
#endif
//  then shorts
	setID SHORT               // Cabinet set ID
// then chars
	szDisk CHAR CB_MAX_DISK_NAME DUP    // current disk name
	szCab CHAR CB_MAX_CABINET_NAME DUP  // current cabinet name
	szCabPath CHAR CB_MAX_CAB_PATH DUP  // path for creating cabinet
ENDS

#define statusFile      0   // Add File to Folder callback
#define statusFolder    1   // Add Folder to Cabinet callback
#define statusCabinet   2   // Write out a completed cabinet callback

#ENDIF
