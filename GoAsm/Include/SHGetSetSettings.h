/* Note
This file contains undocumented functions that have not been tested
Use them if you like but don't blame me...
*/

#IFNDEF SHGETSETSETTINGS
#DEFINE SHGETSETSETTINGS

SHELLSTATE STRUCT
	fShowAllObjects BOOL
	fShowExtensions BOOL
	fNoConfirmRecycle BOOL
	fShowSysFiles BOOL
	fShowCompColor BOOL
	fDoubleClickInWebView BOOL
	fDesktopHTML BOOL
	fWin95Classic BOOL
	fDontPrettyPath BOOL
	fShowAttribCol BOOL
	fMapNetDrvBtn BOOL
	fShowInfoTip BOOL
	fHideIcons BOOL
	fWebView BOOL
	fFilter BOOL
	fShowSuperHidden BOOL
	fNoNetCrawling BOOL
	dwWin95Unused DD
	uWin95Unused DD
	lParamSort LONG
	iSortDirection DD
	version DD
	uNotUsed DD
	fSepProcess BOOL
	fStartPanelOn BOOL
	fShowStartPage BOOL
	fSpareFlags DD
ENDS

// under no circumstances is it safe to use these functions (especially InvalidateDriveType and SHGetNetResource)
;InvalidateDriveType SHELL32.DLL:65
IsNetDrive SHELL32.DLL:66 ;(long) IsNetDrive
Shell_MergeMenus SHELL32.DLL:67 ; (long long long long long long) Shell_MergeMenus
SHGetSetSettings SHELL32.DLL:68 ;(long long long) SHGetSetSettings
;SHGetNetResource SHELL32.DLL:69
SHCreateDefClassObject SHELL32.DLL:70 ;(long long long long long)SHCreateDefClassObject

#ENDIF
