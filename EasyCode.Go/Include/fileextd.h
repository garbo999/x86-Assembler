/************************************************************************
*                                                                       *
*   fileextd.h - This module defines some extensions to the the 32-Bit  *
*                Windows Base APIs based on file handles.               *
*                                                                       *
*   Copyright (c) Microsoft Corp. All rights reserved.                  *
*                                                                       *
************************************************************************/
#ifndef FILEEXTD_H
#define FILEEXTD_H

/*
These definitions are included in Windows Vista and above
They are available through a redistributable for Windows XP

http://www.microsoft.com/downloads/details.aspx?FamilyId=1DECC547-AB00-4963-A360-E4130EC079B8&displaylang=en
*/

// FILE_INFO_BY_HANDLE_CLASS
FileBasicInfo = 0
FileStandardInfo = 1
FileNameInfo = 2
FileRenameInfo = 3
FileDispositionInfo = 4
FileAllocationInfo = 5
FileEndOfFileInfo = 6
FileStreamInfo = 7
FileCompressionInfo = 8
FileAttributeTagInfo = 9
FileIdBothDirectoryInfo = 10
FileIdBothDirectoryRestartInfo = 11
MaximumFileInfoByHandleClass = 11

FILE_BASIC_INFO STRUCT
	CreationTime LARGE_INTEGER
	LastAccessTime LARGE_INTEGER
	LastWriteTime LARGE_INTEGER
	ChangeTime LARGE_INTEGER
	FileAttributes DD
ENDS

FILE_STANDARD_INFO STRUCT
	AllocationSize LARGE_INTEGER
	EndOfFile LARGE_INTEGER
	NumberOfLinks DD
	DeletePending BOOL
	Directory BOOL
ENDS

FILE_NAME_INFO STRUCT
	FileNameLength DD
	FileName WCHAR
ENDS

FILE_RENAME_INFO STRUCT
	ReplaceIfExists BOOL
	RootDirectory HANDLE
	FileNameLength DD
	FileName WCHAR
ENDS

FILE_ALLOCATION_INFO STRUCT
	AllocationSize LARGE_INTEGER
ENDS

FILE_END_OF_FILE_INFO STRUCT
	EndOfFile LARGE_INTEGER
ENDS

FILE_STREAM_INFO STRUCT
	NextEntryOffset DD
	StreamNameLength DD
	StreamSize LARGE_INTEGER
	StreamAllocationSize LARGE_INTEGER
	StreamName WCHAR
ENDS

FILE_COMPRESSION_INFO STRUCT
	CompressedFileSize LARGE_INTEGER
	CompressionFormat DW
	CompressionUnitShift CHAR
	ChunkShift CHAR
	ClusterShift CHAR
	Reserved CHAR 3 DUP
ENDS

FILE_ATTRIBUTE_TAG_INFO STRUCT
	FileAttributes DD
	ReparseTag DD
ENDS

FILE_DISPOSITION_INFO STRUCT
	DeleteFile BOOL
ENDS

FILE_ID_BOTH_DIR_INFO STRUCT
	NextEntryOffset DD
	FileIndex DD
	CreationTime LARGE_INTEGER
	LastAccessTime LARGE_INTEGER
	LastWriteTime LARGE_INTEGER
	ChangeTime LARGE_INTEGER
	EndOfFile LARGE_INTEGER
	AllocationSize LARGE_INTEGER
	FileAttributes DD
	FileNameLength DD
	EaSize DD
	ShortNameLength CHAR
	ShortName WCHAR 12 DUP
	FileId LARGE_INTEGER
	FileName WCHAR
ENDS

// FILE_ID_TYPE
FileIdType = 0
MaximumFileIdType = 1

FILE_ID_DESCRIPTOR STRUCT
	dwSize DD  // Size of the struct
	Type ENUM // FILE_ID_TYPE - Describes the type of identifier passed in.
	UNION
		FileId LARGE_INTEGER
	ENDUNION
ENDS

/*
The following 3 APIs are included in Kernel32 in Vista and above
however they are in a redistributable in XP. The redistributable
uses LIB files to emulate the functions.
*/

#IFNDEF FILEEXTLIB
	// This can be directed to another folder. default is in the build folder
	// for example if you keep all of your libs in C:\ASM\LIBS then use
	// #DEFINE FILEEXTLIB C:\ASM\LIBS\fileextd.lib before including windows.h
	#DEFINE FILEEXTLIB fileextd.lib
#ENDIF

#IF WINVER < NTDDI_VISTA
	OpenFileById equ FILEEXTLIB:OpenFileById
	GetFileInformationByHandleEx equ FILEEXTLIB:GetFileInformationByHandleEx
	SetFileInformationByHandle equ FILEEXTLIB:SetFileInformationByHandle
#ENDIF

#endif
