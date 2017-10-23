;=============================================================;
;          shlguid.inc file for Easy Code visual IDE          ;
;            (made for the GoAsm compiler version)            ;
;                                                             ;
;         Version 1.0.00 (created on February, 2007)          ;
;                                                             ;
;      Please report any bug you find (asm@easycode.cat)      ;
;                                                             ;
;                Do not modify this file!!                    ;
;=============================================================;

#IFNDEF SHLGUID_INC
#Define SHLGUID_INC

#Define CLSID_ShellDesktop					<000021400H, 0, 0, 0C0H, 0, 0, 0, 0, 0, 0, 046H>
#Define CLSID_ShellLink 					<000021401H, 0, 0, 0C0H, 0, 0, 0, 0, 0, 0, 046H>

#Define CATID_BrowsableShellExt				<000021490H, 0, 0, 0C0H, 0, 0, 0, 0, 0, 0, 046H>
#Define CATID_BrowseInPlace					<000021491H, 0, 0, 0C0H, 0, 0, 0, 0, 0, 0, 046H>
#Define CATID_DeskBand						<000021492H, 0, 0, 0C0H, 0, 0, 0, 0, 0, 0, 046H>
#Define CATID_InfoBand						<000021493H, 0, 0, 0C0H, 0, 0, 0, 0, 0, 0, 046H>
#Define CATID_CommBand						<000021494H, 0, 0, 0C0H, 0, 0, 0, 0, 0, 0, 046H>

#Define FMTID_Intshcut						<0000214A0H, 0, 0, 0C0H, 0, 0, 0, 0, 0, 0, 046H>
#Define FMTID_InternetSite					<0000214A1H, 0, 0, 0C0H, 0, 0, 0, 0, 0, 0, 046H>

#Define CGID_Explorer						<0000214D0H, 0, 0, 0C0H, 0, 0, 0, 0, 0, 0, 046H>
#Define CGID_ShellDocView					<0000214D1H, 0, 0, 0C0H, 0, 0, 0, 0, 0, 0, 046H>

#Define CGID_ShellServiceObject				<0000214D2H, 0, 0, 0C0H, 0, 0, 0, 0, 0, 0, 046H>
#Define CGID_ExplorerBarDoc					<0000214D3H, 0, 0, 0C0H, 0, 0, 0, 0, 0, 0, 046H>

#Define IID_INewShortcutHookA				<0000214E1H, 0, 0, 0C0H, 0, 0, 0, 0, 0, 0, 046H>
#Define IID_IShellBrowser					<0000214E2H, 0, 0, 0C0H, 0, 0, 0, 0, 0, 0, 046H>
#Define IID_IShellView						<0000214E3H, 0, 0, 0C0H, 0, 0, 0, 0, 0, 0, 046H>
#Define IID_IContextMenu					<0000214E4H, 0, 0, 0C0H, 0, 0, 0, 0, 0, 0, 046H>
#Define IID_IShellIcon						<0000214E5H, 0, 0, 0C0H, 0, 0, 0, 0, 0, 0, 046H>
#Define IID_IShellFolder					<0000214E6H, 0, 0, 0C0H, 0, 0, 0, 0, 0, 0, 046H>

#Define IID_IShellExtInit					<0000214E8H, 0, 0, 0C0H, 0, 0, 0, 0, 0, 0, 046H>
#Define IID_IShellPropSheetExt				<0000214E9H, 0, 0, 0C0H, 0, 0, 0, 0, 0, 0, 046H>
#Define IID_IPersistFolder					<0000214EAH, 0, 0, 0C0H, 0, 0, 0, 0, 0, 0, 046H>
#Define IID_IExtractIconA					<0000214EBH, 0, 0, 0C0H, 0, 0, 0, 0, 0, 0, 046H>
#Define ID_IShellDetails					<0000214ECH, 0, 0, 0C0H, 0, 0, 0, 0, 0, 0, 046H>
#Define ID_IDelayedRelease					<0000214EDH, 0, 0, 0C0H, 0, 0, 0, 0, 0, 0, 046H>
#Define IID_IShellLinkA						<0000214EEH, 0, 0, 0C0H, 0, 0, 0, 0, 0, 0, 046H>
#Define IID_IShellCopyHookA					<0000214EFH, 0, 0, 0C0H, 0, 0, 0, 0, 0, 0, 046H>
#Define IID_IFileViewerA					<0000214F0H, 0, 0, 0C0H, 0, 0, 0, 0, 0, 0, 046H>
#Define IID_ICommDlgBrowser					<0000214F1H, 0, 0, 0C0H, 0, 0, 0, 0, 0, 0, 046H>
#Define IID_IEnumIDList						<0000214F2H, 0, 0, 0C0H, 0, 0, 0, 0, 0, 0, 046H>
#Define IID_IFileViewerSite					<0000214F3H, 0, 0, 0C0H, 0, 0, 0, 0, 0, 0, 046H>
#Define IID_IContextMenu2					<0000214F4H, 0, 0, 0C0H, 0, 0, 0, 0, 0, 0, 046H>
#Define IID_IShellExecuteHookA				<0000214F5H, 0, 0, 0C0H, 0, 0, 0, 0, 0, 0, 046H>
#Define IID_IPropSheetPage					<0000214F6H, 0, 0, 0C0H, 0, 0, 0, 0, 0, 0, 046H>
#Define IID_INewShortcutHookW				<0000214F7H, 0, 0, 0C0H, 0, 0, 0, 0, 0, 0, 046H>
#Define IID_IFileViewerW					<0000214F8H, 0, 0, 0C0H, 0, 0, 0, 0, 0, 0, 046H>
#Define IID_IShellLinkW						<0000214F9H, 0, 0, 0C0H, 0, 0, 0, 0, 0, 0, 046H>
#Define IID_IExtractIconW					<0000214FAH, 0, 0, 0C0H, 0, 0, 0, 0, 0, 0, 046H>
#Define IID_IShellExecuteHookW				<0000214FBH, 0, 0, 0C0H, 0, 0, 0, 0, 0, 0, 046H>
#Define IID_IShellCopyHookW					<0000214FCH, 0, 0, 0C0H, 0, 0, 0, 0, 0, 0, 046H>
#Define IID_IRemoteComputerA				<0000214FDH, 0, 0, 0C0H, 0, 0, 0, 0, 0, 0, 046H>
#Define IID_IRemoteComputerW				<0000214FEH, 0, 0, 0C0H, 0, 0, 0, 0, 0, 0, 046H>

#Define IID_IQueryInfo						<000021500H, 0, 0, 0C0H, 0, 0, 0, 0, 0, 0, 046H>

#Define IID_IBriefcaseStg					<08BCE1FA1H, 00921H, 0101BH, 0B1H, 0FFH, 000H, 0DDH, 001H, 00CH, 0CCH, 048H>
#Define IID_IShellView2						<088E39E80H, 03578H, 011CFH, 0AEH, 069H, 008H, 000H, 02BH, 02EH, 012H, 062H>

#Define IID_IURLSearchHook					<0AC60F6A0H, 00FD9H, 011D0H, 099H, 0CBH, 000H, 0C0H, 04FH, 0D6H, 044H, 097H>
#Define IID_IDelegateFolder					<0ADD8BA80H, 0002BH, 011D0H, 08FH, 00FH, 000H, 0C0H, 04FH, 0D7H, 0D0H, 062H>

#Define IID_IInputObject					<068284FAAH, 06A48H, 011D0H, 08CH, 078H, 000H, 0C0H, 04FH, 0D9H, 018H, 0B4H>
#Define IID_IInputObjectSite				<0F1DB8392H, 07331H, 011D0H, 08CH, 099H, 000H, 0A0H, 0C9H, 02DH, 0BFH, 0E8H>

#Define IID_IDockingWindow					<0012DD920H, 07B26H, 011D0H, 08CH, 0A9H, 000H, 0A0H, 0C9H, 02DH, 0BFH, 0E8H>
#Define IID_IDockingWindowSite				<02A342FC2H, 07B26H, 011D0H, 08CH, 0A9H, 000H, 0A0H, 0C9H, 02DH, 0BFH, 0E8H>
#Define IID_IDockingWindowFrame				<047D2657AH, 07B27H, 011D0H, 08CH, 0A9H, 000H, 0A0H, 0C9H, 02DH, 0BFH, 0E8H>

#Define IID_IShellIconOverlay				<07D688A70H, 0C613H, 011D0H, 099H, 09BH, 000H, 0C0H, 04FH, 0D6H, 055H, 0E1H>
#Define IID_IShellIconOverlayManager		<063B51F80H, 0C868H, 011D0H, 099H, 09CH, 000H, 0C0H, 04FH, 0D6H, 055H, 0E1H>
#Define IID_IShellIconOverlayIdentifier		<00C6C4200H, 0C589H, 011D0H, 099H, 09AH, 000H, 0C0H, 04FH, 0D6H, 055H, 0E1H>

#Define IID_IPersistFolder2					<01AC3D9F0H, 0175CH, 011D1H, 095H, 0BEH, 000H, 060H, 097H, 097H, 0EAH, 04FH>

#Define CLSID_CFSIconOverlayManager			<063B51F81H, 0C868H, 011D0H, 099H, 09CH, 000H, 0C0H, 04FH, 0D6H, 055H, 0E1H>

#Define CLSID_OverlayIdentifier_SlowFile	<07D688A77H, 0C613H, 011D0H, 099H, 09BH, 000H, 0C0H, 04FH, 0D6H, 055H, 0E1H>

#Define IID_IContextMenu3					<0BCFCE0A0H, 0EC17H, 011D0H, 08DH, 010H, 000H, 0A0H, 0C9H, 00FH, 027H, 019H>

#Define IID_IDeskBand						<0EB0FE172H, 01A3AH, 011D0H, 089H, 0B3H, 000H, 0A0H, 0C9H, 00AH, 090H, 0ACH>
#Define CGID_DeskBand						IID_IDeskBand
#Define IID_IShellToolband					<0EB0FE171H, 01A3AH, 011D0H, 089H, 0B3H, 000H, 0A0H, 0C9H, 00AH, 090H, 0ACH>

#Define SID_SShellBrowser					IID_IShellBrowser
#Define SID_SShellDesktop					CLSID_ShellDesktop

#Define IID_IDiscardableBrowserProperty		<049C3DE7CH, 0D329H, 011D0H, 0ABH, 073H, 000H, 0C0H, 04FH, 0C3H, 03EH, 080H>

#IFNDEF NO_INTSHCUT_GUIDS
	#Include <isguids.inc>
#ENDIF

#IFNDEF NO_SHDOCVW_GUIDS
	#Define CLSID_CUrlHistory				<03C374A40H, 0BAE4H, 011CFH, 0BFH, 07DH, 000H, 0AAH, 000H, 069H, 046H, 0EEH>
	#Define SID_SUrlHistory					CLSID_CUrlHistory
	#Define CLSID_CURLSearchHook			<0CFBFAE00H, 017A6H, 011D0H, 099H, 0CBH, 000H, 0C0H, 04FH, 0D6H, 044H, 097H>
	#Define SID_SInternetExplorer			IID_IWebBrowserApp
	#Define SID_SWebBrowserApp				IID_IWebBrowserApp
	#Define SID_STopLevelBrowser			<04C96BE40H, 0915CH, 011CFH, 099H, 0D3H, 000H, 0AAH, 000H, 04AH, 0E8H, 037H>
#ENDIF

#Define CLSID_ActiveDesktop					<075048700H, 0EF1FH, 011D0H, 098H, 088H, 000H, 060H, 097H, 0DEH, 0ACH, 0F9H>
#Define IID_IActiveDesktop					<0F490EB00H, 01240H, 011D1H, 098H, 088H, 000H, 060H, 097H, 0DEH, 0ACH, 0F9H>
#Define CLSID_TaskbarList					<056FDF344H, 0FD6DH, 011D0H, 095H, 08AH, 000H, 060H, 097H, 0C9H, 0A0H, 090H>
#Define IID_ITaskbarList					<056FDF342H, 0FD6DH, 011D0H, 095H, 08AH, 000H, 060H, 097H, 0C9H, 0A0H, 090H>


#IF STRINGS UNICODE
	#Define IID_IFileViewer IID_IFileViewerW
	#Define IID_IShellLink IID_IShellLinkW
	#Define IID_IExtractIcon IID_IExtractIconW
	#Define IID_IShellCopyHook IID_IShellCopyHookW
	#Define IID_IShellExecuteHook IID_IShellExecuteHookW
	#Define IID_INewShortcutHook IID_INewShortcutHookW
#ELSE
	#Define IID_IFileViewer IID_IFileViewerA
	#Define IID_IShellLink IID_IShellLinkA
	#Define IID_IExtractIcon IID_IExtractIconA
	#Define IID_IShellCopyHook IID_IShellCopyHookA
	#Define IID_IShellExecuteHook IID_IShellExecuteHookA
	#Define IID_INewShortcutHook IID_INewShortcutHookA
#ENDIF

#ENDIF ;SHLGUID_INC
