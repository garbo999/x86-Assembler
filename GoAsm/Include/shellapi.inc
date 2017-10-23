;=============================================================;
;         shellapi.inc file for Easy Code visual IDE          ;
;            (made for the GoAsm compiler version)            ;
;                                                             ;
;         Version 1.0.00 (created on February, 2007)          ;
;                                                             ;
;      Please report any bug you find (asm@easycode.cat)      ;
;                                                             ;
;                Do not modify this file!!                    ;
;=============================================================;

#IFNDEF SHELLAPI_INC
#Define SHELLAPI_INC

#Define ABM_NEW           				000000000H
#Define ABM_REMOVE        				000000001H
#Define ABM_QUERYPOS      				000000002H
#Define ABM_SETPOS        				000000003H
#Define ABM_GETSTATE      				000000004H
#Define ABM_GETTASKBARPOS 				000000005H
#Define ABM_ACTIVATE      				000000006H
#Define ABM_GETAUTOHIDEBAR 				000000007H
#Define ABM_SETAUTOHIDEBAR 				000000008H

#Define ABM_WINDOWPOSCHANGED			000000009H


#Define ABN_STATECHANGE    				000000000H
#Define ABN_POSCHANGED     				000000001H
#Define ABN_FULLSCREENAPP  				000000002H
#Define ABN_WINDOWARRANGE  				000000003H

#Define ABS_AUTOHIDE    				000000001H
#Define ABS_ALWAYSONTOP 				000000002H

#Define ABE_LEFT        				0
#Define ABE_TOP         				1
#Define ABE_RIGHT       				2
#Define ABE_BOTTOM      				3

#Define FO_MOVE           				00001H
#Define FO_COPY           				00002H
#Define FO_DELETE         				00003H
#Define FO_RENAME         				00004H

#Define FOF_MULTIDESTFILES         		00001H
#Define FOF_CONFIRMMOUSE           		00002H
#Define FOF_SILENT                 		00004H
#Define FOF_RENAMEONCOLLISION      		00008H
#Define FOF_NOCONFIRMATION         		00010H
#Define FOF_WANTMAPPINGHANDLE      		00020H

#Define FOF_ALLOWUNDO              		00040H
#Define FOF_FILESONLY              		00080H
#Define FOF_SIMPLEPROGRESS         		00100H
#Define FOF_NOCONFIRMMKDIR         		00200H
#Define FOF_NOERRORUI              		00400H
#Define FOF_NOCOPYSECURITYATTRIBS  		00800H

#Define PO_DELETE       				00013H
#Define PO_RENAME       				00014H
#Define PO_PORTCHANGE   				00020H
#Define PO_REN_PORT     				00034H

#Define SE_ERR_FNF              		2
#Define SE_ERR_PNF              		3
#Define SE_ERR_ACCESSDENIED     		5
#Define SE_ERR_OOM              		8
#Define SE_ERR_DLLNOTFOUND              32

#Define SE_ERR_SHARE                    26
#Define SE_ERR_ASSOCINCOMPLETE          27
#Define SE_ERR_DDETIMEOUT               28
#Define SE_ERR_DDEFAIL                  29
#Define SE_ERR_DDEBUSY                  30
#Define SE_ERR_NOASSOC                  31

#Define SEE_MASK_CLASSNAME        		000000001H
#Define SEE_MASK_CLASSKEY         		000000003H
#Define SEE_MASK_IDLIST           		000000004H
#Define SEE_MASK_INVOKEIDLIST     		00000000CH
#Define SEE_MASK_ICON             		000000010H
#Define SEE_MASK_HOTKEY           		000000020H
#Define SEE_MASK_NOCLOSEPROCESS   		000000040H
#Define SEE_MASK_CONNECTNETDRV    		000000080H
#Define SEE_MASK_FLAG_DDEWAIT     		000000100H
#Define SEE_MASK_DOENVSUBST       		000000200H
#Define SEE_MASK_FLAG_NO_UI       		000000400H
#Define SEE_MASK_UNICODE          		000004000H
#Define SEE_MASK_NO_CONSOLE       		000008000H
#Define SEE_MASK_ASYNCOK          		000100000H
#Define SEE_MASK_HMONITOR         		000200000H

#Define SEE_MASK_CLASSNAME        		000000001H
#Define SEE_MASK_CLASSKEY         		000000003H

#Define SEE_MASK_IDLIST           		000000004H
#Define SEE_MASK_INVOKEIDLIST     		00000000CH
#Define SEE_MASK_ICON             		000000010H
#Define SEE_MASK_HOTKEY           		000000020H
#Define SEE_MASK_NOCLOSEPROCESS   		000000040H
#Define SEE_MASK_CONNECTNETDRV    		000000080H
#Define SEE_MASK_FLAG_DDEWAIT     		000000100H
#Define SEE_MASK_DOENVSUBST       		000000200H
#Define SEE_MASK_FLAG_NO_UI       		000000400H
#Define SEE_MASK_UNICODE          		000004000H
#Define SEE_MASK_NO_CONSOLE       		000008000H
#Define SEE_MASK_ASYNCOK          		000100000H
#Define SEE_MASK_HMONITOR         		000200000H

#Define SHERB_NOCONFIRMATION    		000000001H
#Define SHERB_NOPROGRESSUI      		000000002H
#Define SHERB_NOSOUND           		000000004H

#Define NIM_ADD         				000000000H
#Define NIM_MODIFY      				000000001H
#Define NIM_DELETE      				000000002H

#Define NIF_MESSAGE     				000000001H
#Define NIF_ICON        				000000002H
#Define NIF_TIP         				000000004H

#Define SHGFI_ICON              		0000000100H
#Define SHGFI_DISPLAYNAME       		0000000200H
#Define SHGFI_TYPENAME          		0000000400H
#Define SHGFI_ATTRIBUTES        		0000000800H
#Define SHGFI_ICONLOCATION      		0000001000H
#Define SHGFI_EXETYPE           		0000002000H
#Define SHGFI_SYSICONINDEX      		0000004000H
#Define SHGFI_LINKOVERLAY       		0000008000H
#Define SHGFI_SELECTED          		0000010000H
#Define SHGFI_ATTR_SPECIFIED    		0000020000H
#Define SHGFI_LARGEICON         		0000000000H
#Define SHGFI_SMALLICON         		0000000001H
#Define SHGFI_OPENICON          		0000000002H
#Define SHGFI_SHELLICONSIZE     		0000000004H
#Define SHGFI_PIDL              		0000000008H
#Define SHGFI_USEFILEATTRIBUTES 		0000000010H

#Define SHGNLI_PIDL             		0000000001H
#Define SHGNLI_PREFIXNAME       		0000000002H
#Define SHGNLI_NOUNIQUE         		0000000004H

#Define PRINTACTION_OPEN           		0
#Define PRINTACTION_PROPERTIES     		1
#Define PRINTACTION_NETINSTALL     		2
#Define PRINTACTION_NETINSTALLLINK 		3
#Define PRINTACTION_TESTPAGE       		4
#Define PRINTACTION_OPENNETPRN     		5
#Define PRINTACTION_DOCUMENTDEFAULTS 	6
#Define PRINTACTION_SERVERPROPERTIES 	7


DRAGINFOA Struct
	uSize DD
	pt POINT <>
	fNC DD
	lpFileList DD
	grfKeyState DD
EndS

DRAGINFOW Struct
	uSize DD
	pt POINT <>
	fNC DD
	lpFileList DD
	grfKeyState DD
EndS

APPBARDATA Struct
	cbSize DD
	hWnd DD
	uCallbackMessage DD
	uEdge DD
	rc RECT <>
	lParam DD
EndS

SHFILEOPSTRUCTA Struct
	hwnd DD
	wFunc DD
	pFrom DD
	pTo DD
	fFlags DW
	fAnyOperationsAborted DD
	hNameMappings DD
	lpszProgressTitle DD
EndS

SHFILEOPSTRUCTW Struct
	hwnd DD
	wFunc DD
	pFrom DD
	pTo DD
	fFlags DW
	fAnyOperationsAborted DD
	hNameMappings DD
	lpszProgressTitle DD
EndS

SHNAMEMAPPINGA Struct
	pszOldPath DD
	pszNewPath DD
	cchOldPath DD
	cchNewPath DD
EndS

SHNAMEMAPPINGW Struct
	pszOldPath DD
	pszNewPath DD
	cchOldPath DD
	cchNewPath DD
EndS

SHELLEXECUTEINFOA Struct
	cbSize DD
	fMask DD
	hwnd DD
	lpVerb DD
	lpFile DD
	lpParameters DD
	lpDirectory DD
	nShow DD
	hInstApp DD
	lpIDList DD
	lpClass DD
	hkeyClass DD
	dwHotKey DD
	Union
		hIcon DD
		hMonitor DD
	EndUnion
	hProcess DD
EndS

SHELLEXECUTEINFOW Struct
	cbSize DD
	fMask DD
	hwnd DD
	lpVerb DD
	lpFile DD
	lpParameters DD
	lpDirectory DD
	nShow DD
	hInstApp DD
	lpIDList DD
	lpClass DD
	hkeyClass DD
	dwHotKey DD
	Union
		hIcon DD
		hMonitor DD
	EndUnion
	hProcess DD
EndS

SHQUERYRBINFO Struct
	cbSize DD
	i64Size DQ
	i64NumItems DQ
EndS

NOTIFYICONDATAA Struct
	cbSize DD
	hWnd DD
	uID DD
	uFlags DD
	uCallbackMessage DD
	hIcon DD
	szTip DB 64 Dup ?
EndS

NOTIFYICONDATAW Struct
	cbSize DD
	hWnd DD
	uID DD
	uFlags DD
	uCallbackMessage DD
	hIcon DD
	szTip DW 64 Dup ?
EndS

SHFILEINFOA Struct
	hIcon DD
	iIcon DD
	dwAttributes DD
	szDisplayName DB MAX_PATH Dup ?
	szTypeName DB 80 Dup ?
EndS

SHFILEINFOW Struct
	hIcon DD
	iIcon DD
	dwAttributes DD
	szDisplayName DW MAX_PATH Dup ?
	szTypeName DW 80 Dup ?
EndS


#IF STRINGS UNICODE
	#Define DragQueryFile DragQueryFileW
	#Define ShellExecute ShellExecuteW
	#Define FindExecutable FindExecutableW
	#Define ShellAbout ShellAboutW
	#Define ExtractAssociatedIcon ExtractAssociatedIconW
	#Define ExtractIcon ExtractIconW
	#Define DRAGINFO DRAGINFOW
	#Define DoEnvironmentSubst DoEnvironmentSubstW
	#Define FindEnvironmentString FindEnvironmentStringW
	#Define ExtractIconEx ExtractIconExW
	#Define SHFILEOPSTRUCT SHFILEOPSTRUCTW
	#Define SHFileOperation SHFileOperationW
	#Define SHNAMEMAPPING SHNAMEMAPPINGW
	#Define SHELLEXECUTEINFO SHELLEXECUTEINFOW
	#Define ShellExecuteEx ShellExecuteExW
	#Define WinExecError WinExecErrorW
	#Define SHQueryRecycleBin SHQueryRecycleBinW
	#Define SHEmptyRecycleBin SHEmptyRecycleBinW
	#Define NOTIFYICONDATA NOTIFYICONDATAW
	#Define Shell_NotifyIcon Shell_NotifyIconW
	#Define SHFILEINFO SHFILEINFOW
	#Define SHGetFileInfo SHGetFileInfoW
	#Define SHGetDiskFreeSpace SHGetDiskFreeSpaceW
	#Define SHGetNewLinkInfo SHGetNewLinkInfoW
	#Define SHInvokePrinterCommand SHInvokePrinterCommandW
#ELSE
	#Define DragQueryFile DragQueryFileA
	#Define ShellExecute ShellExecuteA
	#Define FindExecutable FindExecutableA
	#Define ShellAbout ShellAboutA
	#Define ExtractAssociatedIcon ExtractAssociatedIconA
	#Define ExtractIcon ExtractIconA
	#Define DRAGINFO DRAGINFOA
	#Define DoEnvironmentSubst DoEnvironmentSubstA
	#Define FindEnvironmentString FindEnvironmentStringA
	#Define ExtractIconEx ExtractIconExA
	#Define SHFILEOPSTRUCT SHFILEOPSTRUCTA
	#Define SHFileOperation SHFileOperationA
	#Define SHNAMEMAPPING SHNAMEMAPPINGA
	#Define SHELLEXECUTEINFO SHELLEXECUTEINFOA
	#Define ShellExecuteEx ShellExecuteExA
	#Define WinExecError WinExecErrorA
	#Define SHQueryRecycleBin SHQueryRecycleBinA
	#Define SHEmptyRecycleBin SHEmptyRecycleBinA
	#Define NOTIFYICONDATA NOTIFYICONDATAA
	#Define Shell_NotifyIcon Shell_NotifyIconA
	#Define SHFILEINFO SHFILEINFOA
	#Define SHGetFileInfo SHGetFileInfoA
	#Define SHGetDiskFreeSpace SHGetDiskFreeSpaceA
	#Define SHGetNewLinkInfo SHGetNewLinkInfoA
	#Define SHInvokePrinterCommand SHInvokePrinterCommandA
#ENDIF

#ENDIF ;SHELLAPI_INC
