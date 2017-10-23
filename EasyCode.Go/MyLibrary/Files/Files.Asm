
/*
CreateLink:
	Creates a shortcut (LNK) file
	Parameters:
		lpLinkTarget = Pointer to the fully qualified path of the link target
		lpOutputFile = Pointer to a link path\name at which to create the link
		lpDescription = A description to add to the link
	This function uses the first icon in the file as the link icon
	lpOutputFile must have the extension .LNK
	CoInitialize must be called at some point in your program before this function
	Returns 0 if successful
	
	Tested GoAsm & MASM

CreateDesktopLink
	This is a wrapper function for CreateLink that creates a link on the desktop
	It works the same as CreateLink except that the path is not supplied with lpLinkName
	Parameters:
		lpLinkTarget = Pointer to the fully qualified path of the link target
		lpLinkName = Pointer to a name for the link file
		lpDescription = A description to add to the link, can be NULL
	The first icon in the file is used for the link icon
	The extension .LNK is added to lpLinkName automatically
	If lpDescription is NULL, no description will be added
	The desktop folder is found through it's PIDL in order to work with Windows 95
	CoInitialize must be called at some point in your program before this function
	Returns 0 if successful
	
	Tested GoAsm & MASM

CreateStartmenuLink:
	This is a wrapper function for CreateLink that creates a link in the Programs menu
	It works the same as CreateLink except that the path is not supplied with lpLinkName
	and you can optionally supply a program group.
	Parameters:
		lpLinkTarget = Pointer to the fully qualified path of the link target
		lpLinkName = Pointer to a name for the link file
		lpDescription = A description to add to the link, can be NULL
		lpProgramGroup = A pointer to a null terminated program group name
	The first icon in the file is used for the link icon
	The extension .LNK is added to lpLinkName automatically
	If lpDescription is NULL, no description will be added
	Use NULL for lpProgramGroup if you do not wish to use one
	The Start menu is found through it's PIDL in order to work with Windows 95
	CoInitialize must be called at some point in your program before this function
	Returns 0 if successful
	
	Tested GoAsm & MASM

CreateSpecialFolderLink:
	This is a wrapper function for CreateLink that creates a link in a special folder
	It works the same as CreateLink except that the path is not supplied with lpLinkName
	Parameters:
		lpLinkTarget = Pointer to the fully qualified path of the link target
		lpLinkName = Pointer to a name for the link file
		lpDescription = A description to add to the link, can be NULL
		csidl = The class ID of the special folder
			see the following url for a list of possible values :
			http://msdn.microsoft.com/library/default.asp?url=/library/en-us/shellcc/platform/shell/reference/enums/csidl.asp
	The first icon in the file is used for the link icon
	The extension .LNK is added to lpLinkName automatically
	If lpDescription is NULL, no description will be added
	CoInitialize must be called at some point in your program before this function
	Returns 0 if successful
	
	Tested GoAsm & MASM

ResolveLink:
	Resolves a shortcut returning the path of the target file
	Parameters:
		lpbuffer = Buffer in which the path is returned
		lpLinkPath = Fully qualified path to the LNK file
	The lpbuffer and lpLinkPath can point to the same buffer, in which case the
	Link target will be copied over the link file buffer.
	CoInitialize must be called at some point in your program before this function
	Returns 0 if successful
	
	Tested GoAsm & MASM

IsShortcut
	Tests to see if the filename provided is a shortcut.
	Parameters:
		lpFilename = Pointer to a filename to be examined
	Returns TRUE is the filename is a shortcut

IsPEFile
	Checks the file for indications that it is a valid Win32 PE file
	Parameters:
		lpFilename = Pointer to a filename to be examined
	
	Returns 0 if the file is a valid Win32 executable
	-1 if there is an error, use GetLastError to obtain more information

CheckFileName: (deprecated)
	Scans a file name for invalid characters based on DOS 8.3 standards
	Parameters:
		pFilename = Pointer to a filename
		fSkipSpace = If true SPACE (20h) will be treated as valid
	Returns FALSE if the filename contains an invalid char
	EDX contains the value of the last invalid char on return
	NOTE: This routine is guaranteed not to modify ECX (for loops)
	
	This function has been replaced by FindBadDOSChar, it is included
	only for compatibility purposes
	
	Tested GoAsm & MASM

FindBadDOSChar:
	Scans a file name for invalid characters based on the DOS 8.3 standard
	Parameters:
		pFilename = Pointer to a filename
		nStartpos = Zero-based position in the filename to start the scan
		fSkipSpace = If true SPACE (20h) will be treated as valid
	Returns the zero-based position of the first invalid character encountered, -1 otherwise
	If nStartpos is greater than the length of pFilename -1 is returned
	NOTE: This routine is guaranteed not to modify ECX (for loops)

	Tested GoAsm & MASM

RecurseFolder:
	This is a callback function that will list all files in a folder
	Parameters:
		lpPth = Pointer to a fully qualified path
		pCallback = Pointer to a call back function
		fRecurse = Set to TRUE to recurse the directory
	The function will send the filenames to the callback one at a time
	Format for callback:
		RecurserFolderProc:
			pFileName = A pointer to the filename being enumerated
			dwAttributes = File attributes
		The callback returns false to stop the enumeration
	Returns the count of enumerated files, -1 if there is an error
	
	Tested GoAsm & MASM

InitCRC32Table:
	Initailizes the CRC32 calculation table
	This function needs to be called only once in an application but
	must be called before the CRC32 function is called.
	Parameters:
		None
	Returns the address of the CRC table (do not modify this data !!!)
	
	Tested GoAsm & MASM

CRC32:
	Returns the CRC32 checksum for a memory buffer
	Parameters:
		lpBuffer = Address of the buffer to be checksummed
		cbBuffer = Size of the buffer
	Returns the CRC32 checksum
	***NOTE the CRC32 table must be initialized before this function is called !!!
	
	Tested GoAsm & MASM

FindNameInPath
	Returns the offset of the file name portion of a path
	Parameters:
		pszFilename = Pointer to a file path
	Returns the memory offset within the supplied path where the file name starts
	In case of error returns the original pointer
	
	Tested GoAsm & MASM

GetCL
	Parameters:
		ArgNum = The 0 based argument number (0=Application path, 1 - Argument 1)
		ItemBuffer = Pointer to a buffer to receive the argument
	Returns 1 = successful
			2 = arg does not exist
			3 = non matching quotation marks
			4 = Empty quotes

	Tested GoAsm & MASM

ResolveLinkIndirect
	Resolves a shortcut returning details about that shortcut. The information is passed
	in a structure
	Parameters:
		pLinkInfo = Pointer to a LINK_INFO structure
	
	LINK_INFO structure members:
		pFilename		Fully qualified path of the LNK file to be examined, cannot be NULL
		pLinkTarget		Pointer to a buffer of MAX_PATH to recieve the target, can be NULL
		pIconLocation	Pointer to a buffer of MAX_PATH to recieve the icon location, can be NULL
		dwIconIndex		Recieves the icon index (ignored if pIconLocation is NULL)
		pDescBuffer		Pointer to a buffer to recieve the description, can be NULL
		cchDesc			Size in bytes of the pDescBuffer buffer
		pArgBuffer		Pointer to a buffer to recieve the command line arguments, can be NULL
		cchArg			Size in bytes of the pArgBuffer buffer
		pStartIn		Pointer to a buffer of MAX_PATH to recieve the startup dir, can be NULL
		dwHotkey		Recieves the assigned hot-key scan code
		dwShowCmd		Recieves the show command 

	Set a buffer pointer to NULL if you do not need that information.
	Returns S_OK or an OLE defined error code.

CreateLinkIndirect
	Creates a shortcut, based on the information passed in a structure
	Parameters:
		pLinkInfo = Pointer to a LINK_INFO structure
	
	LINK_INFO structure members:
		pFilename		Fully qualified path of the LNK file to be created, cannot be NULL
		pLinkTarget		Pointer to a path specifying the target, cannot be NULL
		pIconLocation	Pointer to a path where the icon is located, can be NULL
		dwIconIndex		Specifies the icon index (ignored if pIconLocation is NULL)
		pDescBuffer		Pointer a description, can be NULL
		cchDesc			ignored
		pArgBuffer		Pointer to a string of command line arguments, can be NULL
		cchArg			ignored
		pStartIn		Pointer to a path specifying the startup dir, can be NULL
		dwHotkey		Hot-key scan code (ie VK_S)
		dwShowCmd		Show command (ie SW_SHOWNORMAL) 

	Set a buffer pointer to NULL to skip that information
	Returns S_OK or an OLE defined error code.

StripFilename
	Returns the path portion of a file name in the buffer provided. The buffer must
	be of the size MAX_PATH
	Parameters:
		pszBuffer = Pointer to a buffer in which to copy the path information
		pszFilename = Pointer to a file path (this string is preserved)

	Returns the offset of the file name portion of the path
	ECX is preserved for loop functions

GetFileExists
	Parameters:
		lpszFileName = Pointer to a fully qualified path to the file
	Returns 1 if the file exists

	Tested GoAsm & MASM

ReadFileLines:
	Sequentially reads a file line by line and passes the NULL
	terminated strings to a callback routine
	Parameters:
		pszFile = Pointer to a fully qualified file name
		pCallback = Pointer to a callback function
		
		Format for callback:
		ReadFileLinesProc:
			pLineText = Pointer to a buffer containing the text
			cbLine = Count of characters in pLineText
			nLine = Line number in file
			pLine = Offset of the first character in the file
		The callback returns FALSE to stop the enumeration

	Returns 0, -1 in case of error. Use GetLastError for more information
	If the callback returns FALSE the enumeration is stopped and the function
	returns -1, GetLastError will return ERROR_CANCELLED

	Tested GoAsm & MASM

CountFileLines
	Counts the lines terminated by 0A in a file
	Parameters:
		pszFile = Pointer to a fully qualified file name

	Returns the number of lines, -1 if there is an error

	Tested GoAsm & MASM
	
GetFileInfo:
	Parameters:
		pFileName = Pointer to a fully qualified path to the file
		pFileTitle = Pointer to a buffer to recieve the file title
		pFileSize = Pointer to a DWORD sized buffer to recieve the file size
		pFileTime = Pointer to a FILETIME structure to recieve the file time
		pVer = Pointer to a DWORD buffer to receive the version information

	Returns 0

	Tested GoAsm & MASM

DateStamp2FileTime
	Converts a DateStamp (dword seconds since Jan 1, 1970) to a FILETIME structure
	Parameters:
		DateStamp = The DateStamp DWORD to convert
		pFILETIME = Pointer to a FILETIME structure
	No return value
	This function can be used to convert the DateStamps in PE IMAGE_FILE_HEADERs

	Tested GoAsm & MASM

FileTime2DateStamp
	Converts a FILETIME structure to a DateStamp
	Parameters:
		pFILETIME = Pointer to a FILETIME structure
	Returns the DateStamp value

	Tested GoAsm & MASM

GetModulePath
	Retrieves the path portion of the specified module
	Parameters:
		hInst = The module handle, 0 for the current module
		pszModPath = A pointer to a buffer large enough to hold the path (MAX_PATH)
		cbBuffer = The size of the buffer pointed to by pszModPath

	Copies the module path with terminating \ character to pszModPath

	Tested GoAsm & MASM

RegisterFileExtension
	Registers a shell command for a given file extension
	This command appears in the right click context menu of the shell
	Parameters:
		pFileExt = Pointer to a file extension to register
		pCmd = Pointer to the shell command name (ie Open)
		pCmdLine = The command line to execute (ie 'C:\WinNT\system32\NOTEPAD.EXE "%1"')
	Note the shell will replace %1 in the command line with the file name
	Returns 0

CheckFileName			PROTO	:DWORD,:DWORD
CountFileLines			PROTO	:DWORD
CountFileLinesMMX		PROTO	:DWORD
CRC32					PROTO	:DWORD,:DWORD
InitCRC32Table			PROTO
CreateDesktopLink		PROTO	:DWORD,:DWORD,:DWORD
CreateLink				PROTO	:DWORD,:DWORD,:DWORD
CreateLinkIndirect		PROTO	:DWORD
CreateSpecialFolderLink	PROTO	:DWORD,:DWORD,:DWORD,:DWORD
CreateStartmenuLink		PROTO	:DWORD,:DWORD,:DWORD,:DWORD
DateStamp2FileTime		PROTO	:DWORD,:DWORD
FileTime2DateStamp		PROTO	:DWORD
FindNameInPath			PROTO	:DWORD
GetCL					PROTO	:DWORD,:DWORD
GetFileExist			PROTO	:DWORD
GetFileInfo				PROTO	:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
GetModulePath			PROTO	:DWORD,:DWORD,:DWORD
ReadFileLines			PROTO	:DWORD,:DWORD
RecurseFolder			PROTO	:DWORD,:DWORD,:DWORD
RegisterFileExtension	PROTO	:DWORD,:DWORD,:DWORD
ResolveLink				PROTO	:DWORD,:DWORD
ResolveLinkIndirect		PROTO	:DWORD
StripFilename			PROTO	:DWORD,:DWORD
IsShortcut				PROTO	:DWORD
IsPEFile				PROTO	:DWORD

*/

.data
	hFile	DD	?
	


