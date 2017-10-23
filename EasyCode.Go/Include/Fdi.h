#ifndef FDI_H
#define FDI_H

#IFDEF LINKFILES
	#dynamiclinkfiles cabinet.dll
#ENDIF

#IFNDEF BASETSD_H
	#include "basetsd.h"
#ENDIF

#ifndef TRUE
	#define TRUE    1
#endif

#ifndef FALSE
	#define FALSE   0
#endif

#ifndef NULL
	#define NULL    0
#endif

/***    ERF - Error structure
 *
 *  This structure returns error information from FCI/FDI.  The caller should
 *  not modify this structure.
 */
ERF struct
	erfOper INT32            // FCI/FDI error code -- see FDIERROR_XXX
                             //  and FCIERR_XXX equates for details.
	erfType INT32            // Optional error value filled in by FCI/FDI.
                             // For FCI, this is usually the C run-time
                             // *errno* value.
	fError BOOL              // TRUE => error present
ENDS

#define CB_MAX_CHUNK            32768
#define CB_MAX_DISK        0x7fffffff
#define CB_MAX_FILENAME            256
#define CB_MAX_CABINET_NAME        256
#define CB_MAX_CAB_PATH            256
#define CB_MAX_DISK_NAME           256

/***    tcompXXX - Diamond compression types
 *
 *  These are passed to FCIAddFile(), and are also stored in the CFFOLDER
 *  structures in cabinet files.
 *
 *  NOTE: We reserve bits for the TYPE, QUANTUM_LEVEL, and QUANTUM_MEM
 *        to provide room for future expansion.  Since this value is stored
 *        in the CFDATA records in the cabinet file, we don't want to
 *        have to change the format for existing compression configurations
 *        if we add new ones in the future.  This will allows us to read
 *        old cabinet files in the future.
 */

#DEFINE TCOMP DW // Not sure how to pass this using GoAsm

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

/***    fdi_int.h - Diamond File Decompression Interface definitions
 *                      
 *      Copyright (C) Microsoft Corporation 1993-1997
 *      All Rights Reserved.
 *
 *  Author:
 *      Chuck Strouss, Benjamin W. Slivka
 *
 *  History:
 *      30-Nov-1993 chuckst Created
 *      21-Dec-1993 bens    Updated with comments from 12/21/93 design review
 *      09-Mar-1994 bens    Add new error code
 *      17-Mar-1994 bens    Specify structure packing explicitly
 *      21-Mar-1994 bens    Spruce up comments
 *      25-Mar-1994 bens    Add fdintCABINET_INFO notification
 *      31-Mar-1994 bens    Clarify handling of open files when errors occur
 *      01-Apr-1994 bens    Add FDIIsCabinet() function.
 *      07-Apr-1994 bens    Add Decryption interfaces; remove fdintPROGRESS
 *      11-Apr-1994 bens    Add more guidance on how to respond to FDI errors.
 *      13-Apr-1994 bens    Add date & time & attribs to fdintCOPY_FILE
 *      18-Apr-1994 bens    Changed CDECL to DIAMONDAPI
 *      05-May-1994 bens    Clarified error handling (billhu/alanr/migueldc)
 *      11-May-1994 bens    Added setId/iCabinet to fdintNEXT_CABINET
 *      07-Jul-1994 bens    Support Quantum virtual file -- PLEASE note the
 *                              comments about PFNOPEN/PFNCLOSE changes, and
 *                              about reserving memory, if necessary, before
 *                              calling FDICreate()!
 *      19-Aug-1994 bens    Add cpuType parameter to FDICreate().
 *      03-Apr-1995 jeffwe  Added chaining indicators to FDICABINETINFO
 *      22-Nov-1996 msliger Backed out fdintNEXT_FOLDER, added iFolder to
 *                              FDINOTIFICATION for fdintCOPY_FILE calls.
 *      20-Feb-1997 msliger Added fdintENUMERATE message.
 *      11-Nov-2005 kinshu  SAL annotation
 *
 *
 *  ATTENTION:
 *      This is the only documentation on the Diamond File Decompression
 *      Interface (FDI).  Please read it carefully, as there are some subtle
 *      points in FDI that are carefully explained below.
 *
 *  Concepts:
 *      A *cabinet* file contains one or more *folders*.  A folder contains
 *      one or more (pieces of) *files*.  A folder is by definition a
 *      decompression unit, i.e., to extract a file from a folder, all of
 *      the data from the start of the folder up through and including the
 *      desired file must be read and decompressed.
 *
 *      A folder can span one (or more) cabinet boundaries, and by implication
 *      a file can also span one (or more) cabinet boundaries.  Indeed, more
 *      than one file can span a cabinet boundary, since Diamond concatenates
 *      files together into a single data stream before compressing (actually,
 *      at most one file will span any one cabinet boundary, but Diamond does
 *      not know which file this is, since the mapping from uncompressed bytes
 *      to compressed bytes is pretty obscure.  Also, since Diamond compresses
 *      in blocks of 32K (at present), any files with data in a 32K block that
 *      spans a cabinet boundary require Diamond to read both cabinet files
 *      to get the two halves of the compressed block).
 *
 *  Overview:
 *      The File Decompression Interface is used to simplify the reading of
 *      Diamond cabinet files.  A setup program will proceed in a manner very
 *      similar to the pseudo code below.  An FDI context is created, the
 *      setup program calls FDICopy() for each cabinet to be processed.  For
 *      each file in the cabinet, FDICopy() calls a notification callback
 *      routine, asking the setup program if the file should be copied.
 *      This call-back approach is great because it allows the cabinet file
 *      to be read and decompressed in an optimal manner, and also makes FDI
 *      independent of the run-time environment -- FDI makes *no* C run-time
 *      calls whatsoever.  All memory allocation and file I/O functions are
 *      passed into FDI by the client.
 *
 *      main(...)
 *      {
 *          // Read INF file to construct list of desired files.   
 *          //  Ideally, these would be sorted in the same order as the
 *          //  files appear in the cabinets, so that you can just walk
 *          //  down the list in response to fdintCOPY_FILE notifications.
 *
 *          // Construct list of required cabinets. 
 *
 *          hfdi = FDICreate(...);          // Create FDI context
 *          For (cabinet in List of Cabinets) {
 *              FDICopy(hfdi,cabinet,fdiNotify,...);  // Process each cabinet
 *          }
 *          FDIDestroy(hfdi);
 *          ...
 *      }
 *
 *      // Notification callback function 
 *      fdiNotify(fdint,...)
 *      {
 *          If (User Aborted)               // Permit cancellation
 *              if (fdint == fdintCLOSE_FILE_INFO)
 *                  close open file
 *              return -1;
 *          switch (fdint) {
 *              case fdintCOPY_FILE:        // File to copy, maybe
 *                  // Check file against list of desired files 
 *                  if want to copy file
 *                      open destination file and return handle
 *                  else
 *                      return NULL;        // Skip file
 *              case fdintCLOSE_FILE_INFO:
 *                  close file
 *                  set date, time, and attributes
 *
 *              case fdintNEXT_CABINET:
 *                  if not an error callback
 *                      Tell FDI to use suggested directory name
 *                  else
 *                      Tell user what the problem was, and prompt
 *                          for a new disk and/or path.
 *                      if user aborts
 *                          Tell FDI to abort
 *                      else
 *                          return to FDI to try another cabinet
 *                  //NOTE: Be sure to see the (sample) code in EXTRACT.C
 *                  //      for an example of how to do this!
 *              default:
 *                  return 0;               // more messages may be defined
 *              ...
 *      }
 *
 *  Error Handling Suggestions:
 *      Since you the client have passed in *all* of the functions that
 *      FDI uses to interact with the "outside" world, you are in prime
 *      position to understand and deal with errors.
 *
 *      The general philosophy of FDI is to pass all errors back up to
 *      the client.  FDI returns fairly generic error codes in the case
 *      where one of the callback functions (PFNOPEN, PFNREAD, etc.) fail,
 *      since it assumes that the callback function will save enough
 *      information in a static/global so that when FDICopy() returns
 *      fail, the client can examine this information and report enough
 *      detail about the problem that the user can take corrective action.
 *
 *      For very specific errors (CORRUPT_CABINET, for example), FDI returns
 *      very specific error codes.
 *
 *      THE BEST POLICY IS FOR YOUR CALLBACK ROUTINES TO AVOID RETURNING
 *      ERRORS TO FDI!
 *
 *      Examples:
 *          (1) If the disk is getting full, instead of returning an error
 *              from your PFNWRITE function, you should -- inside your
 *              PFNWRITE function -- put up a dialog telling the user to free
 *              some disk space.
 *          (2) When you get the fdintNEXT_CABINET notification, you should
 *              verify that the cabinet you return is the correct one (call
 *              FDIIsCabinet(), and make sure the setID matches the one for
 *              the current cabinet specified in the fdintCABINET_INFO, and
 *              that the disk number is one greater.
 *
 *              NOTE: FDI will continue to call fdintNEXT_CABINET until it
 *                    gets the cabinet it wants, or until you return -1
 *                    to abort the FDICopy() call.
 *
 *      The documentation below on the FDI error codes provides explicit
 *      guidance on how to avoid each error.
 *
 *      If you find you must return a failure to FDI from one of your
 *      callback functions, then FDICopy() frees all resources it allocated
 *      and closes all files.  If you can figure out how to overcome the
 *      problem, you can call FDICopy() again on the last cabinet, and
 *      skip any files that you already copied.  But, note that FDI does
 *      *not* maintain any state between FDICopy() calls, other than possibly
 *      memory allocated for the decompressor.
 *
 *      See FDIERROR for details on FDI error codes and recommended actions.
 *
 *
 *  Progress Indicator Suggestions:
 *      As above, all of the file I/O functions are supplied by you.  So,
 *      updating a progress indicator is very simple.  You keep track of
 *      the target files handles you have opened, along with the uncompressed
 *      size of the target file.  When you see writes to the handle of a
 *      target file, you use the write count to update your status!
 *      Since this method is available, there is no separate callback from
 *      FDI just for progess indication.
 */

/***    FDIERROR - Error codes returned in erf.erfOper field
 *
 *  In general, FDI will only fail if one of the passed in memory or
 *  file I/O functions fails.  Other errors are pretty unlikely, and are
 *  caused by corrupted cabinet files, passing in a file which is not a
 *  cabinet file, or cabinet files out of order.
 *
 *  Description:    Summary of error.
 *  Cause:          List of possible causes of this error.
 *  Response:       How client might respond to this error, or avoid it in
 *                  the first place.
 */

; enum FDIERROR
FDIERROR_NONE = 0
    // Description: No error
    // Cause:       Function was successfull.
    // Response:    Keep going!

FDIERROR_CABINET_NOT_FOUND = 1
    // Description: Cabinet not found
    // Cause:       Bad file name or path passed to FDICopy(), or returned
    //              to fdintNEXT_CABINET.
    // Response:    To prevent this error, validate the existence of the
    //              the cabinet *before* passing the path to FDI.

FDIERROR_NOT_A_CABINET = 2
    // Description: Cabinet file does not have the correct format
    // Cause:       File passed to to FDICopy(), or returned to
    //              fdintNEXT_CABINET, is too small to be a cabinet file,
    //              or does not have the cabinet signature in its first
    //              four bytes.
    // Response:    To prevent this error, call FDIIsCabinet() to check a
    //              cabinet before calling FDICopy() or returning the
    //              cabinet path to fdintNEXT_CABINET.

FDIERROR_UNKNOWN_CABINET_VERSION = 3
    // Description: Cabinet file has an unknown version number.
    // Cause:       File passed to to FDICopy(), or returned to
    //              fdintNEXT_CABINET, has what looks like a cabinet file
    //              header, but the version of the cabinet file format
    //              is not one understood by this version of FDI.  The
    //              erf.erfType field is filled in with the version number
    //              found in the cabinet file.
    // Response:    To prevent this error, call FDIIsCabinet() to check a
    //              cabinet before calling FDICopy() or returning the
    //              cabinet path to fdintNEXT_CABINET.

FDIERROR_CORRUPT_CABINET = 4
    // Description: Cabinet file is corrupt
    // Cause:       FDI returns this error any time it finds a problem
    //              with the logical format of a cabinet file, and any
    //              time one of the passed-in file I/O calls fails when
    //              operating on a cabinet (PFNOPEN, PFNSEEK, PFNREAD,
    //              or PFNCLOSE).  The client can distinguish these two
    //              cases based upon whether the last file I/O call
    //              failed or not.
    // Response:    Assuming this is not a real corruption problem in
    //              a cabinet file, the file I/O functions could attempt
    //              to do retries on failure (for example, if there is a
    //              temporary network connection problem).  If this does
    //              not work, and the file I/O call has to fail, then the
    //              FDI client will have to clean up and call the
    //              FDICopy() function again.

FDIERROR_ALLOC_FAIL = 5
    // Description: Could not allocate enough memory
    // Cause:       FDI tried to allocate memory with the PFNALLOC
    //              function, but it failed.
    // Response:    If possible, PFNALLOC should take whatever steps
    //              are possible to allocate the memory requested.  If
    //              memory is not immediately available, it might post a
    //              dialog asking the user to free memory, for example.
    //              Note that the bulk of FDI's memory allocations are
    //              made at FDICreate() time and when the first cabinet
    //              file is opened during FDICopy().

FDIERROR_BAD_COMPR_TYPE = 6
    // Description: Unknown compression type in a cabinet folder
    // Cause:       [Should never happen.]  A folder in a cabinet has an
    //              unknown compression type.  This is probably caused by
    //              a mismatch between the version of Diamond used to
    //              create the cabinet and the FDI. LIB used to read the
    //              cabinet.
    // Response:    Abort.

FDIERROR_MDI_FAIL = 7
    // Description: Failure decompressing data from a cabinet file
    // Cause:       The decompressor found an error in the data coming
    //              from the file cabinet.  The cabinet file was corrupted.
    //              [11-Apr-1994 bens When checksuming is turned on, this
    //              error should never occur.]
    // Response:    Probably should abort; only other choice is to cleanup
    //              and call FDICopy() again, and hope there was some
    //              intermittent data error that will not reoccur.

FDIERROR_TARGET_FILE = 8
    // Description: Failure writing to target file
    // Cause:       FDI returns this error any time it gets an error back
    //              from one of the passed-in file I/O calls fails when
    //              writing to a file being extracted from a cabinet.
    // Response:    To avoid or minimize this error, the file I/O functions
    //              could attempt to avoid failing.  A common cause might
    //              be disk full -- in this case, the PFNWRITE function
    //              could have a check for free space, and put up a dialog
    //              asking the user to free some disk space.

FDIERROR_RESERVE_MISMATCH = 9
    // Description: Cabinets in a set do not have the same RESERVE sizes
    // Cause:       [Should never happen]. FDI requires that the sizes of
    //              the per-cabinet, per-folder, and per-data block
    //              RESERVE sections be consistent across all the cabinet
    //              in a set.  Diamond will only generate cabinet sets
    //              with these properties.
    // Response:    Abort.

FDIERROR_WRONG_CABINET = 10
    // Description: Cabinet returned on fdintNEXT_CABINET is incorrect
    // Cause:       NOTE: THIS ERROR IS NEVER RETURNED BY FDICopy()!
    //              Rather, FDICopy() keeps calling the fdintNEXT_CABINET
    //              callback until either the correct cabinet is specified,
    //              or you return ABORT.
    //              When FDICopy() is extracting a file that crosses a
    //              cabinet boundary, it calls fdintNEXT_CABINET to ask
    //              for the path to the next cabinet.  Not being very
    //              trusting, FDI then checks to make sure that the
    //              correct continuation cabinet was supplied!  It does
    //              this by checking the "setID" and "iCabinet" fields
    //              in the cabinet.  When DIAMOND.EXE creates a set of
    //              cabinets, it constructs the "setID" using the sum
    //              of the bytes of all the destination file names in
    //              the cabinet set.  FDI makes sure that the 16-bit
    //              setID of the continuation cabinet matches the
    //              cabinet file just processed.  FDI then checks that
    //              the cabinet number (iCabinet) is one more than the
    //              cabinet number for the cabinet just processed.
    // Response:    You need code in your fdintNEXT_CABINET (see below)
    //              handler to do retries if you get recalled with this
    //              error.  See the sample code (EXTRACT.C) to see how
    //              this should be handled.

FDIERROR_USER_ABORT = 11
    // Description: FDI aborted.
    // Cause:       An FDI callback returnd -1 (usually).
    // Response:    Up to client.


/*
 * FAT file attribute flag used by FCI/FDI to indicate that
 * the filename in the CAB is a UTF string
 */
#ifndef _A_NAME_IS_UTF
	#define _A_NAME_IS_UTF  0x80
#endif

/*
 * FAT file attribute flag used by FCI/FDI to indicate that
 * the file should be executed after extraction
 */
#ifndef _A_EXEC
	#define _A_EXEC         0x40
#endif

/***    FDICABINETINFO - Information about a cabinet
 *
 */
FDICABINETINFO struct
	cbCabinet LONG              // Total length of cabinet file
	cFolders SHORT              // Count of folders in cabinet
	cFiles SHORT                // Count of files in cabinet
	setID SHORT                 // Cabinet set ID
	iCabinet SHORT              // Cabinet number in set (0 based)
	fReserve BOOL               // TRUE => RESERVE present in cabinet
	hasprev BOOL                // TRUE => Cabinet is chained prev
	hasnext BOOL                // TRUE => Cabinet is chained next
ENDS

/***    FDIDECRYPTTYPE - PFNFDIDECRYPT command types
 *
 */
// enum FDIDECRYPTTYPE
fdidtNEW_CABINET = 0                   // New cabinet
fdidtNEW_FOLDER = 1                    // New folder
fdidtDECRYPT = 2                       // Decrypt a data block


/***    FDIDECRYPT - Data for PFNFDIDECRYPT function
 *
 */
FDIDECRYPT struct
	fdidt ENUM            // Command type (selects union below)
	pvUser PTR           // Decryption context
	UNION
		cabinet struct                        // fdidtNEW_CABINET
			pHeaderReserve PTR   // RESERVE section from CFHEADER
			cbHeaderReserve SHORT  // Size of pHeaderReserve
			setID SHORT            // Cabinet set ID
			iCabinet INT32         // Cabinet number in set (0 based)
		ENDS

		folder struct                        // fdidtNEW_FOLDER
			pFolderReserve PTR   // RESERVE section from CFFOLDER
			cbFolderReserve SHORT  // Size of pFolderReserve
			iFolder SHORT          // Folder number in cabinet (0 based)
		ENDS

		decrypt struct                        // fdidtDECRYPT
			pDataReserve PTR     // RESERVE section from CFDATA
			cbDataReserve SHORT    // Size of pDataReserve
			pbData PTR           // Data buffer
			cbData SHORT           // Size of data buffer
			fSplit BOOL           // TRUE if this is a split data block
			cbPartial SHORT        // 0 if this is not a split block, or
                                        //  the first piece of a split block;
                                        // Greater than 0 if this is the
                                        //  second piece of a split block.
		ENDS
	ENDUNION
ENDS


/***    FDINOTIFICATION - Notification structure for PFNFDINOTIFY
 *
 *  See the FDINOTIFICATIONTYPE definition for information on usage and
 *  meaning of these fields.
 */
FDINOTIFICATION struct
// long fields
	cb LONG
	psz1 PTR
	psz2 PTR
	psz3 PTR                     // Points to a 256 character buffer
	pv PTR                       // Value for client

// int fields
	hf INT_PTR

// short fields
	date SHORT
	time SHORT
	attribs SHORT

	setID SHORT                    // Cabinet set ID
	iCabinet SHORT                 // Cabinet number (0-based)
	iFolder SHORT                  // Folder number (0-based)

	fdie ENUM
ENDS


// FDINOTIFICATIONTYPE enum
fdintCABINET_INFO = 0              // General information about cabinet
fdintPARTIAL_FILE = 1              // First file in cabinet is continuation
fdintCOPY_FILE = 2                 // File to be copied
fdintCLOSE_FILE_INFO = 3           // close the file, set relevant info
fdintNEXT_CABINET = 4              // File continued to next cabinet
fdintENUMERATE = 5                 // Enumeration status

/** FDISPILLFILE - Pass as pszFile on PFNOPEN to create spill file
 *
 *  ach    - A two byte string to signal to PFNOPEN that a spill file is
 *           requested.  Value is '*','\0'.
 *  cbFile - Required spill file size, in bytes.
 */
FDISPILLFILE struct
	ach CHAR 2 DUP                 // Set to { '*', '\0' }
	cbFile LONG                 // Required spill file size
ENDS

#define     cpuUNKNOWN         -1    /* FDI does detection */
#define     cpu80286           0     /* '286 opcodes only */
#define     cpu80386           1     /* '386 opcodes used */


#ENDIF