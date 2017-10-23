#Define CLSCTX_INPROC_SERVER 1
#Define TRUE 1
#Define FALSE 0
#Define NULL 0
#Define S_OK 0
#Define CP_ACP 0
#Define STGM_READ 0
#Define MAX_PATH 260
#Define CSIDL_DESKTOP 0
#Define CSIDL_COMMON_STARTMENU 16h
#Define CSIDL_COMMON_PROGRAMS 17h
#Define CSIDL_COMMON_STARTUP 18h

GUID STRUCT
    Data1     dd
    Data2     dw
    Data3     dw
    Data4     db
        db
        db
        db
        db
        db
        db
        db
ENDS

Unknown STRUCT
   QueryInterface         DD
   AddRef               DD
   Release               DD
ENDS

IShellLink STRUCT
   IUnknown            Unknown      <>

   GetPath               DD
   GetIDList             DD
   SetIDList            DD
   GetDescription         DD
   SetDescription         DD
   GetWorkingDirectory      DD
   SetWorkingDirectory      DD
   GetArguments         DD
   SetArguments         DD
   GetHotkey            DD
   SetHotkey            DD
   GetShowCmd            DD
   SetShowCmd            DD
   GetIconLocation         DD
   SetIconLocation         DD
   SetRelativePath         DD
   Resolve               DD
   SetPath               DD
ENDS

IPersistFile STRUCT
   IUnknown      Unknown      <>

   GetClassID      DD
   IsDirty         DD
   Load         DD
   Save         DD
   SaveCompleted   DD
   GetCurFile      DD
ENDS

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
