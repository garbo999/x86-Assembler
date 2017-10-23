;=============================================================;
;          winver.inc file for Easy Code visual IDE           ;
;            (made for the GoAsm compiler version)            ;
;                                                             ;
;         Version 1.0.00 (created on February, 2007)          ;
;                                                             ;
;      Please report any bug you find (asm@easycode.cat)      ;
;                                                             ;
;                Do not modify this file!!                    ;
;=============================================================;

#IFNDEF WINVER_INC
#Define WINVER_INC

#Define VS_FILE_INFO            RT_VERSION
#Define VS_VERSION_INFO         1
#Define VS_USER_DEFINED         100

#Define VS_FFI_SIGNATURE        0FEEF04BDH
#Define VS_FFI_STRUCVERSION     000010000H
#Define VS_FFI_FILEFLAGSMASK    00000003FH

#Define VS_FF_DEBUG             000000001H
#Define VS_FF_PRERELEASE        000000002H
#Define VS_FF_PATCHED           000000004H
#Define VS_FF_PRIVATEBUILD      000000008H
#Define VS_FF_INFOINFERRED      000000010H
#Define VS_FF_SPECIALBUILD      000000020H

#Define VOS_UNKNOWN             000000000H
#Define VOS_DOS                 000010000H
#Define VOS_OS216               000020000H
#Define VOS_OS232               000030000H
#Define VOS_NT                  000040000H

#Define VOS__BASE               000000000H
#Define VOS__WINDOWS16          000000001H
#Define VOS__PM16               000000002H
#Define VOS__PM32               000000003H
#Define VOS__WINDOWS32          000000004H

#Define VOS_DOS_WINDOWS16       000010001H
#Define VOS_DOS_WINDOWS32       000010004H
#Define VOS_OS216_PM16          000020002H
#Define VOS_OS232_PM32          000030003H
#Define VOS_NT_WINDOWS32        000040004H

#Define VFT_UNKNOWN             000000000H
#Define VFT_APP                 000000001H
#Define VFT_DLL                 000000002H
#Define VFT_DRV                 000000003H
#Define VFT_FONT                000000004H
#Define VFT_VXD                 000000005H
#Define VFT_STATIC_LIB          000000007H

#Define VFT2_UNKNOWN            000000000H
#Define VFT2_DRV_PRINTER        000000001H
#Define VFT2_DRV_KEYBOARD       000000002H
#Define VFT2_DRV_LANGUAGE       000000003H
#Define VFT2_DRV_DISPLAY        000000004H
#Define VFT2_DRV_MOUSE          000000005H
#Define VFT2_DRV_NETWORK        000000006H
#Define VFT2_DRV_SYSTEM         000000007H
#Define VFT2_DRV_INSTALLABLE    000000008H
#Define VFT2_DRV_SOUND          000000009H
#Define VFT2_DRV_COMM           00000000AH
#Define VFT2_DRV_INPUTMETHOD    00000000BH

#Define VFT2_FONT_RASTER        000000001H
#Define VFT2_FONT_VECTOR        000000002H
#Define VFT2_FONT_TRUETYPE      000000003H

#Define VFFF_ISSHAREDFILE       00001H

#Define VFF_CURNEDEST           00001H
#Define VFF_FILEINUSE           00002H
#Define VFF_BUFFTOOSMALL        00004H

#Define VIFF_FORCEINSTALL       00001H
#Define VIFF_DONTDELETEOLD      00002H

#Define VIF_TEMPFILE            000000001H
#Define VIF_MISMATCH            000000002H
#Define VIF_SRCOLD              000000004H

#Define VIF_DIFFLANG            000000008H
#Define VIF_DIFFCODEPG          000000010H
#Define VIF_DIFFTYPE            000000020H

#Define VIF_WRITEPROT           000000040H
#Define VIF_FILEINUSE           000000080H
#Define VIF_OUTOFSPACE          000000100H
#Define VIF_ACCESSVIOLATION     000000200H
#Define VIF_SHARINGVIOLATION    000000400H
#Define VIF_CANNOTCREATE        000000800H
#Define VIF_CANNOTDELETE        000001000H
#Define VIF_CANNOTRENAME        000002000H
#Define VIF_CANNOTDELETECUR     000004000H
#Define VIF_OUTOFMEMORY         000008000H

#Define VIF_CANNOTREADSRC       000010000H
#Define VIF_CANNOTREADDST       000020000H

#Define VIF_BUFFTOOSMALL        000040000H


VS_FIXEDFILEINFO Struct
	dwSignature DD
	dwStrucVersion DD
	dwFileVersionMS DD
	dwFileVersionLS DD
	dwProductVersionMS DD
	dwProductVersionLS DD
	dwFileFlagsMask DD
	dwFileFlags DD
	dwFileOS DD
	dwFileType DD
	dwFileSubtype DD
	dwFileDateMS DD
	dwFileDateLS DD
EndS


#IF STRINGS UNICODE
	#Define VerFindFile VerFindFileW
	#Define VerInstallFile VerInstallFileW
	#Define GetFileVersionInfoSize GetFileVersionInfoSizeW
	#Define GetFileVersionInfo GetFileVersionInfoW
	#Define VerLanguageName VerLanguageNameW
	#Define VerQueryValue VerQueryValueW
#ELSE
	#Define VerFindFile VerFindFileA
	#Define VerInstallFile VerInstallFileA
	#Define GetFileVersionInfoSize GetFileVersionInfoSizeA
	#Define GetFileVersionInfo GetFileVersionInfoA
	#Define VerLanguageName VerLanguageNameA
	#Define VerQueryValue VerQueryValueA
#ENDIF

#ENDIF ;WINVER_INC
