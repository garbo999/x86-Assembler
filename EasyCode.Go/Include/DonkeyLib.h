;##################################################################
; Library include
;##################################################################

;##################################################################
; String Library
;##################################################################
#IFNDEF DONKEYLIB_H
#DEFINE DONKEYLIB_H

#IFNDEF WIN64

#IFNDEF STRINGLIB
	STRINGLIB = Strings.lib
#ENDIF

; All of these should be easy for Unicode
; Save them for last when the support functions
; are done and tested.
saAddString			= STRINGLIB:AddString
saCreateArray		= STRINGLIB:CreateArray
saDeleteString		= STRINGLIB:DeleteString
saDestroyArray		= STRINGLIB:DestroyArray
saEnumArray			= STRINGLIB:EnumArray
saEnumArrayProc		= STRINGLIB:EnumArrayProc
saExpandArray		= STRINGLIB:ExpandArray
saFindEmptyIndex	= STRINGLIB:FindEmptyIndex
saFindString		= STRINGLIB:FindString
saGetString			= STRINGLIB:GetString
saGetTopIndex		= STRINGLIB:GetTopIndex
saSortArray			= STRINGLIB:SortArray
saReplaceString		= STRINGLIB:ReplaceString

; Need unicode versions of these...
szTrim				= STRINGLIB:lszTrim
szSoundEx			= STRINGLIB:lszSoundEx

; No unicode planned until I clean it up
szCatPlus			= STRINGLIB:lszCatPlus

; Decorated names
szCutA				= STRINGLIB:lszCut
szCutW				= STRINGLIB:lszCutW
szCaseA				= STRINGLIB:lszCase
szCaseW				= STRINGLIB:lszCaseW
szCmpA				= STRINGLIB:lszCmp
szCmpW				= STRINGLIB:lszCmpW
szCmpiA				= STRINGLIB:lszCmpi
szCmpiW				= STRINGLIB:lszCmpiW
szCopynA			= STRINGLIB:lszCopyn
szCopynW			= STRINGLIB:lszCopynW
szSubstA			= STRINGLIB:lszSubst
szSubstW			= STRINGLIB:lszSubstW
szPosA				= STRINGLIB:lszPos
szPosW				= STRINGLIB:lszPosW
szCatA				= STRINGLIB:lszCat
szCatW				= STRINGLIB:lszCatW
szTokenA			= STRINGLIB:lszToken
szTokenW			= STRINGLIB:lszTokenW
szInstrA			= STRINGLIB:lszInstr
szInstrW			= STRINGLIB:lszInstrW
szTrimLeftA			= STRINGLIB:lszTrimLeft
szTrimLeftW			= STRINGLIB:lszTrimLeftW
szCopyA				= STRINGLIB:lszCopy
szCopyW				= STRINGLIB:lszCopyW
szLenA				= STRINGLIB:lszLen
szLenW				= STRINGLIB:lszLenW
szLenMMX			= STRINGLIB:lszLenMMX
szLenMMXW			= STRINGLIB:lszLenMMXW
szReverseA			= STRINGLIB:lszReverse
szReverseW			= STRINGLIB:lszReverseW
szInsertA			= STRINGLIB:lszInsert
szInsertW			= STRINGLIB:lszInsertW
szCopyMMX			= STRINGLIB:lszCopyMMX

; Unicode not necessary
MemCopy				= STRINGLIB:dwMemCopy
MemCopyMMX			= STRINGLIB:MemCopyMMX

; Unicode switch
#IFDEF UNICODE
	szCopy			= STRINGLIB:lszCopyW
	szCmp			= STRINGLIB:lszCmpW
	szInstr			= STRINGLIB:lszInstrW
	szCase			= STRINGLIB:lszCaseW
	szCmpi			= STRINGLIB:lszCmpiW
	szCopyn			= STRINGLIB:lszCopynW
	szSubst			= STRINGLIB:lszSubstW
	szPos			= STRINGLIB:lszPosW
	szCat			= STRINGLIB:lszCatW
	szToken			= STRINGLIB:lszTokenW
	szTrimLeft		= STRINGLIB:lszTrimLeftW
	szReverse		= STRINGLIB:lszReverseW
	szCut			= STRINGLIB:lszCutW
	szLen			= STRINGLIB:lszLenW
	szInsert		= STRINGLIB:lszInsertW
#ELSE
	szCopy			= STRINGLIB:lszCopy
	szCmp			= STRINGLIB:lszCmp
	szInstr			= STRINGLIB:lszInstr
	szCase			= STRINGLIB:lszCase
	szCmpi			= STRINGLIB:lszCmpi
	szCopyn			= STRINGLIB:lszCopyn
	szSubst			= STRINGLIB:lszSubst
	szPos			= STRINGLIB:lszPos
	szCat			= STRINGLIB:lszCat
	szToken			= STRINGLIB:lszToken
	szTrimLeft		= STRINGLIB:lszTrimLeft
	szReverse		= STRINGLIB:lszReverse
	szCut			= STRINGLIB:lszCut
	szLen			= STRINGLIB:lszLen
	szInsert		= STRINGLIB:lszInsert
#ENDIF

; SSE switch
#IFDEF USESSE
	#IFDEF szLenA
		#UNDEF szLenA
	#ENDIF
	#IFDEF szLenW
		#UNDEF szLenW
	#ENDIF
	#IFDEF szLen
		#UNDEF szLen
	#ENDIF
	#IFDEF szCopy
		#UNDEF szCopy
	#ENDIF
	#IFDEF UNICODE
		szLen			= STRINGLIB:lszLenMMXW
	#ELSE
		szLen			= STRINGLIB:lszLenMMX
	#ENDIF
	szLenA			= STRINGLIB:lszLenMMX
	szLenW			= STRINGLIB:lszLenMMXW
	szCopy			= STRINGLIB:lszCopyMMX
#ENDIF

;#IFNDEF USEMMX
;	#IFDEF MemCopy
;		#UNDEF MemCopy
;	#ENDIF
;	MemCopy			= STRINGLIB:dwMemCopy
;#ELSE
;	#IFDEF MemCopy
;		#UNDEF MemCopy
;	#ENDIF
;	MemCopy			= STRINGLIB:MemCopyMMX
;#ENDIF

;##################################################################
; System Library
;##################################################################

#IFNDEF SYSLIB
	SYSLIB = System.lib
#ENDIF

GetPEExports = SYSLIB:GetPEExports
GetPEImports = SYSLIB:GetPEImports
GetModuleByAddrNT = SYSLIB:GetModuleByAddrNT
GetModuleByAddr9x = SYSLIB:GetModuleByAddr9x
IsFeaturePresent = SYSLIB:IsFeaturePresent
PostVKeyPress = SYSLIB:PostVKeyPress
SendKeys = SYSLIB:SendKeys
ErrorToString = SYSLIB:ErrorToString
GetPIDFromhProcess = SYSLIB:GetPIDFromhProcess
GetParentPID9x = SYSLIB:GetParentPID9x
ExceptionMessage = SYSLIB:ExceptionMessage
ListProcessesNT = SYSLIB:ListProcessesNT
ListProcesses9x = SYSLIB:ListProcesses9x
CPUSpeed = SYSLIB:CPUSpeed
NETErrorToString = SYSLIB:NETErrorToString
GetVersionString = SYSLIB:GetVersionString
ListModulesNT = SYSLIB:ListModulesNT
ListModules9x = SYSLIB:ListModules9x
WaitForProcess = SYSLIB:WaitForProcess
GetWindowsString = SYSLIB:GetWindowsString
GetParentPIDNT = SYSLIB:GetParentPIDNT
DLLErrorToString = SYSLIB:DLLErrorToString
NTSTATUSToString = SYSLIB:NTSTATUSToString ;FRAME dwNTSTATUSCODE,pString,cbString
DLLMsgIdToString = SYSLIB:DLLMsgIdToString
FindProcessByNameNT = SYSLIB:FindProcessByNameNT
SingleInstance = SYSLIB:SingleInstance
Shell = SYSLIB:Shell
ShellMsg = SYSLIB:ShellMsg

;##################################################################
; Files Library
;##################################################################

#IFNDEF FILESLIB
	FILESLIB = Files.lib
#ENDIF

CheckFileName = FILESLIB:CheckFileName
CountFileLines = FILESLIB:CountFileLines
CountFileLinesMMX = FILESLIB:CountFileLinesMMX
CRC32 = FILESLIB:CRC32
InitCRC32Table = FILESLIB:InitCRC32Table
CreateDesktopLink = FILESLIB:CreateDesktopLink
CreateLink = FILESLIB:CreateLink
CreateLinkIndirect = FILESLIB:CreateLinkIndirect
CreateSpecialFolderLink = FILESLIB:CreateSpecialFolderLink
CreateStartmenuLink = FILESLIB:CreateStartmenuLink
DateStamp2FileTime = FILESLIB:DateStamp2FileTime
FileTime2DateStamp = FILESLIB:FileTime2DateStamp
FindNameInPath = FILESLIB:FindNameInPath
GetCL = FILESLIB:GetCL
GetFileExists = FILESLIB:GetFileExists
GetFileInfo = FILESLIB:GetFileInfo
GetModulePath = FILESLIB:GetModulePath
ReadFileLines = FILESLIB:ReadFileLines
RecurseFolder = FILESLIB:RecurseFolder
RegisterFileExtension = FILESLIB:RegisterFileExtension
ResolveLink = FILESLIB:ResolveLink
ResolveLinkIndirect = FILESLIB:ResolveLinkIndirect
StripFilename = FILESLIB:StripFilename
IsShortcut = FILESLIB:IsShortcut
IsPEFile = FILESLIB:IsPEFile

LINK_INFO Struct
	pFilename		DD	?
	pLinkTarget		DD	?
	pIconLocation	DD	?
	dwIconIndex		DD	?
	pDescBuffer		DD	?
	cchDesc			DD	?
	pArgBuffer		DD	?
	cchArg			DD	?
	pStartIn		DD	?
	dwHotkey		DD	?
	dwShowCmd		DD	?
ENDS

;##################################################################
; Graphics Library
;##################################################################

GRAPHLIB = Graphics.lib

ApplySkin = GRAPHLIB:ApplySkin
BresLine = GRAPHLIB:BresLine
ConvertToDIB32 = GRAPHLIB:ConvertToDIB32
CopyDIBImage = GRAPHLIB:CopyDIBImage
CopyDIBRects = GRAPHLIB:CopyDIBRects
CreateIndependantBitmap = GRAPHLIB:CreateIndependantBitmap
Deg2Rad = GRAPHLIB:Deg2Rad
DIBAdjustLuma = GRAPHLIB:DIBAdjustLuma
DIBBlurImage = GRAPHLIB:DIBBlurImage
DIBColorCount = GRAPHLIB:DIBColorCount
DIBDrawEllipse = GRAPHLIB:DIBDrawEllipse
DIBFillEllipse = GRAPHLIB:DIBFillEllipse
DIBGetColors = GRAPHLIB:DIBGetColors
DIBGetHistogram = GRAPHLIB:DIBGetHistogram
DIBRectangle = GRAPHLIB:DIBRectangle
DIBSaveBitmap = GRAPHLIB:DIBSaveBitmap
EmbossImage = GRAPHLIB:EmbossImage
ExchangeColor = GRAPHLIB:ExchangeColor
FloodFillDIB = GRAPHLIB:FloodFillDIB
GetDIBPixel = GRAPHLIB:GetDIBPixel
GetRotatedBitmap = GRAPHLIB:GetRotatedBitmap
GradientFillRectDIB = GRAPHLIB:GradientFillRectDIB
GrayScale = GRAPHLIB:GrayScale
InvertImage = GRAPHLIB:InvertImage
IsBmpDIB = GRAPHLIB:IsBmpDIB
LithoImage = GRAPHLIB:LithoImage
ReplaceColor = GRAPHLIB:ReplaceColor
SaveDIB32 = GRAPHLIB:SaveDIB32
SetDIBPixel = GRAPHLIB:SetDIBPixel
TraceEdges = GRAPHLIB:TraceEdges
Watermark = GRAPHLIB:Watermark

;##################################################################
; Conversions Library
;##################################################################

#IFNDEF CONVLIB
	CONVLIB = Convert.lib
#ENDIF

ascii2dwW = CONVLIB:ascii2dwW
dw2asciiW = CONVLIB:dw2asciiW
dw2binW = CONVLIB:dw2binW
dw2hexW = CONVLIB:dw2hexW
hex2dwW = CONVLIB:hex2dwW
dq2asciiW = CONVLIB:dq2asciiW
dq2hexW = CONVLIB:dq2hexW

dw2asciiA = CONVLIB:dw2ascii
ascii2dwA = CONVLIB:ascii2dw
dw2binA = CONVLIB:dw2bin
dw2hexA = CONVLIB:dw2hex
hex2dwA = CONVLIB:hex2dw
dq2asciiA = CONVLIB:dq2ascii
dq2hexA = CONVLIB:dq2hex

#IFDEF UNICODE
	ascii2dw = CONVLIB:ascii2dwW
	dw2ascii = CONVLIB:dw2asciiW
	dw2bin = CONVLIB:dw2binW
	dw2hex = CONVLIB:dw2hexW
	hex2dw = CONVLIB:hex2dwW
	dq2ascii = CONVLIB:dq2asciiW
	dq2hex = CONVLIB:dq2hexW
#ELSE
	dw2ascii = CONVLIB:dw2ascii
	ascii2dw = CONVLIB:ascii2dw
	dw2bin = CONVLIB:dw2bin
	dw2hex = CONVLIB:dw2hex
	hex2dw = CONVLIB:hex2dw
	dq2ascii = CONVLIB:dq2ascii
	dq2hex = CONVLIB:dq2hex
#ENDIF

popcount = CONVLIB:popcount
BitSaturateEAX = CONVLIB:BitSaturateEAX
EncryptQWord = CONVLIB:EncryptQWord
DecryptQWord = CONVLIB:DecryptQWord
Randomize = CONVLIB:Randomize
RandM = CONVLIB:RandM

#ENDIF

#ENDIF
