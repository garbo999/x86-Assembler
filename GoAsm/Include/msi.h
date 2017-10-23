#ifndef MSI_H
#define MSI_H

/* Installer Service definitions */

#IFDEF LINKFILES
	#dynamiclinkfile "Msi.dll"
#ENDIF

#define MAX_FEATURE_CHARS  38

#define INSTALLPROPERTY_TRANSFORMS  "Transforms"
#define INSTALLPROPERTY_LANGUAGE  "Language"
#define INSTALLPROPERTY_PRODUCTNAME  "ProductName"
#define INSTALLPROPERTY_ASSIGNMENTTYPE  "AssignmentType"
#define INSTALLPROPERTY_PACKAGECODE  "PackageCode"
#define INSTALLPROPERTY_VERSION  "Version"
#define INSTALLPROPERTY_PRODUCTICON  "ProductIcon"

#define INSTALLPROPERTY_INSTALLEDPRODUCTNAME  "InstalledProductName"
#define INSTALLPROPERTY_VERSIONSTRING  "VersionString"
#define INSTALLPROPERTY_HELPLINK  "HelpLink"
#define INSTALLPROPERTY_HELPTELEPHONE  "HelpTelephone"
#define INSTALLPROPERTY_INSTALLLOCATION  "InstallLocation"
#define INSTALLPROPERTY_INSTALLSOURCE  "InstallSource"
#define INSTALLPROPERTY_INSTALLDATE  "InstallDate"
#define INSTALLPROPERTY_PUBLISHER  "Publisher"
#define INSTALLPROPERTY_LOCALPACKAGE  "LocalPackage"
#define INSTALLPROPERTY_URLINFOABOUT  "URLInfoAbout"
#define INSTALLPROPERTY_URLUPDATEINFO  "URLUpdateInfo"
#define INSTALLPROPERTY_VERSIONMINOR  "VersionMinor"
#define INSTALLPROPERTY_VERSIONMAJOR  "VersionMajor"

#ifndef ERROR_INSTALL_FAILURE
	#define ERROR_INSTALL_USEREXIT  1602
	#define ERROR_INSTALL_FAILURE  1603
	#define ERROR_INSTALL_SUSPEND  1604
	#define ERROR_UNKNOWN_PRODUCT  1605
	#define ERROR_UNKNOWN_FEATURE  1606
	#define ERROR_UNKNOWN_COMPONENT  1607
	#define ERROR_UNKNOWN_PROPERTY  1608
	#define ERROR_INVALID_HANDLE_STATE  1609
	#define ERROR_BAD_CONFIGURATION  1610
	#define ERROR_INDEX_ABSENT  1611
	#define ERROR_INSTALL_SOURCE_ABSENT 1612
	#define ERROR_PRODUCT_UNINSTALLED  1614
	#define ERROR_BAD_QUERY_SYNTAX  1615
	#define ERROR_INVALID_FIELD  1616
#endif

#ifndef ERROR_INSTALL_SERVICE_FAILURE
	#define ERROR_INSTALL_SERVICE_FAILURE  1601
	#define ERROR_INSTALL_PACKAGE_VERSION  1613
	#define ERROR_INSTALL_ALREADY_RUNNING  1618
	#define ERROR_INSTALL_PACKAGE_OPEN_FAILED  1619
	#define ERROR_INSTALL_PACKAGE_INVALID  1620
	#define ERROR_INSTALL_UI_FAILURE  1621
	#define ERROR_INSTALL_LOG_FAILURE  1622
	#define ERROR_INSTALL_LANGUAGE_UNSUPPORTED 1623
	#define ERROR_INSTALL_PACKAGE_REJECTED  1625
	#define ERROR_FUNCTION_NOT_CALLED  1626
	#define ERROR_FUNCTION_FAILED  1627
	#define ERROR_INVALID_TABLE  1628
	#define ERROR_DATATYPE_MISMATCH  1629
	#define ERROR_UNSUPPORTED_TYPE  1630
	#define ERROR_CREATE_FAILED  1631
#endif

#ifndef ERROR_INSTALL_TEMP_UNWRITABLE
	#define ERROR_INSTALL_TEMP_UNWRITABLE  1632
#endif

#ifndef ERROR_INSTALL_PLATFORM_UNSUPPORTED
	#define ERROR_INSTALL_PLATFORM_UNSUPPORTED 1633
#endif

#ifndef ERROR_INSTALL_NOTUSED
	#define ERROR_INSTALL_NOTUSED  1634
#endif

#ifndef ERROR_INSTALL_TRANSFORM_FAILURE
	#define ERROR_INSTALL_TRANSFORM_FAILURE  1624
#endif

#ifndef ERROR_PATCH_PACKAGE_OPEN_FAILED
	#define ERROR_PATCH_PACKAGE_OPEN_FAILED  1635
	#define ERROR_PATCH_PACKAGE_INVALID  1636
	#define ERROR_PATCH_PACKAGE_UNSUPPORTED  1637
#endif

#ifndef ERROR_PRODUCT_VERSION
	#define ERROR_PRODUCT_VERSION  1638
#endif

#ifndef ERROR_INVALID_COMMAND_LINE
	#define ERROR_INVALID_COMMAND_LINE  1639
#endif

#ifndef ERROR_INSTALL_REMOTE_DISALLOWED
#define ERROR_INSTALL_REMOTE_DISALLOWED  1640
#endif

#ifndef ERROR_SUCCESS_REBOOT_INITIATED
	#define ERROR_SUCCESS_REBOOT_INITIATED  1641
#endif

#ifndef ERROR_PATCH_TARGET_NOT_FOUND
	#define ERROR_PATCH_TARGET_NOT_FOUND  1642
#endif

INSTALLMESSAGE_FATALEXIT = 0x00000000
INSTALLMESSAGE_ERROR = 0x01000000
INSTALLMESSAGE_WARNING = 0x02000000
INSTALLMESSAGE_USER = 0x03000000
INSTALLMESSAGE_INFO = 0x04000000
INSTALLMESSAGE_FILESINUSE = 0x05000000
INSTALLMESSAGE_RESOLVESOURCE = 0x06000000
INSTALLMESSAGE_OUTOFDISKSPACE = 0x07000000
INSTALLMESSAGE_ACTIONSTART = 0x08000000
INSTALLMESSAGE_ACTIONDATA = 0x09000000
INSTALLMESSAGE_PROGRESS = 0x0A000000
INSTALLMESSAGE_COMMONDATA = 0x0B000000
INSTALLMESSAGE_INITIALIZE = 0x0C000000
INSTALLMESSAGE_TERMINATE = 0x0D000000
INSTALLMESSAGE_SHOWDIALOG = 0x0E000000

INSTALLUILEVEL_NOCHANGE = 0
INSTALLUILEVEL_DEFAULT = 1
INSTALLUILEVEL_NONE = 2
INSTALLUILEVEL_BASIC = 3
INSTALLUILEVEL_REDUCED = 4
INSTALLUILEVEL_FULL = 5
INSTALLUILEVEL_ENDDIALOG = 0x80
INSTALLUILEVEL_PROGRESSONLY = 0x40

INSTALLSTATE_NOTUSED = -7
INSTALLSTATE_BADCONFIG = -6
INSTALLSTATE_INCOMPLETE = -5
INSTALLSTATE_SOURCEABSENT = -4
INSTALLSTATE_MOREDATA = -3
INSTALLSTATE_INVALIDARG = -2
INSTALLSTATE_UNKNOWN = -1
INSTALLSTATE_BROKEN = 0
INSTALLSTATE_ADVERTISED = 1
INSTALLSTATE_REMOVED = 1
INSTALLSTATE_ABSENT = 2
INSTALLSTATE_LOCAL = 3
INSTALLSTATE_SOURCE = 4
INSTALLSTATE_DEFAULT = 5

USERINFOSTATE_MOREDATA = -3
USERINFOSTATE_INVALIDARG = -2
USERINFOSTATE_UNKNOWN = -1
USERINFOSTATE_ABSENT = 0
USERINFOSTATE_PRESENT = 1

INSTALLLEVEL_DEFAULT = 0
INSTALLLEVEL_MINIMUM = 1
INSTALLLEVEL_MAXIMUM = 0xFFFF

REINSTALLMODE_REPAIR = 0x00000001
REINSTALLMODE_FILEMISSING = 0x00000002
REINSTALLMODE_FILEOLDERVERSION = 0x00000004
REINSTALLMODE_FILEEQUALVERSION = 0x00000008
REINSTALLMODE_FILEEXACT = 0x00000010
REINSTALLMODE_FILEVERIFY = 0x00000020
REINSTALLMODE_FILEREPLACE = 0x00000040
REINSTALLMODE_MACHINEDATA = 0x00000080
REINSTALLMODE_USERDATA = 0x00000100
REINSTALLMODE_SHORTCUT = 0x00000200
REINSTALLMODE_PACKAGE = 0x00000400

INSTALLLOGMODE_FATALEXIT = (1 << (INSTALLMESSAGE_FATALEXIT >> 24))
INSTALLLOGMODE_ERROR = (1 << (INSTALLMESSAGE_ERROR >> 24))
INSTALLLOGMODE_WARNING = (1 << (INSTALLMESSAGE_WARNING >> 24))
INSTALLLOGMODE_USER = (1 << (INSTALLMESSAGE_USER >> 24))
INSTALLLOGMODE_INFO = (1 << (INSTALLMESSAGE_INFO >> 24))
INSTALLLOGMODE_RESOLVESOURCE = (1 << (INSTALLMESSAGE_RESOLVESOURCE >> 24))
INSTALLLOGMODE_OUTOFDISKSPACE = (1 << (INSTALLMESSAGE_OUTOFDISKSPACE >> 24))
INSTALLLOGMODE_ACTIONSTART = (1 << (INSTALLMESSAGE_ACTIONSTART >> 24))
INSTALLLOGMODE_ACTIONDATA = (1 << (INSTALLMESSAGE_ACTIONDATA >> 24))
INSTALLLOGMODE_COMMONDATA = (1 << (INSTALLMESSAGE_COMMONDATA >> 24))
INSTALLLOGMODE_PROPERTYDUMP = (1 << (INSTALLMESSAGE_PROGRESS >> 24))
INSTALLLOGMODE_VERBOSE = (1 << (INSTALLMESSAGE_INITIALIZE >> 24))
INSTALLLOGMODE_PROGRESS = (1 << (INSTALLMESSAGE_PROGRESS >> 24))
INSTALLLOGMODE_INITIALIZE = (1 << (INSTALLMESSAGE_INITIALIZE >> 24))
INSTALLLOGMODE_TERMINATE = (1 << (INSTALLMESSAGE_TERMINATE >> 24))
INSTALLLOGMODE_SHOWDIALOG = (1 << (INSTALLMESSAGE_SHOWDIALOG >> 24))

INSTALLLOGATTRIBUTES_APPEND = (1 << 0)
INSTALLLOGATTRIBUTES_FLUSHEACHLINE = (1 << 1)

INSTALLFEATUREATTRIBUTE_FAVORLOCAL = 1 << 0
INSTALLFEATUREATTRIBUTE_FAVORSOURCE = 1 << 1
INSTALLFEATUREATTRIBUTE_FOLLOWPARENT = 1 << 2
INSTALLFEATUREATTRIBUTE_FAVORADVERTISE = 1 << 3
INSTALLFEATUREATTRIBUTE_DISALLOWADVERTISE = 1 << 4
INSTALLFEATUREATTRIBUTE_NOUNSUPPORTEDADVERTISE = 1 << 5

INSTALLMODE_NOSOURCERESOLUTION = -3
INSTALLMODE_NODETECTION = -2
INSTALLMODE_EXISTING = -1
INSTALLMODE_DEFAULT = 0

INSTALLTYPE_DEFAULT = 0
INSTALLTYPE_NETWORK_IMAGE = 1

#IFDEF UNICODE
	#define INSTALLUI_HANDLER  INSTALLUI_HANDLERW
	#define MsiSetExternalUI  MsiSetExternalUIW
	#define MsiEnableLog  MsiEnableLogW
	#define MsiQueryProductState  MsiQueryProductStateW
	#define MsiGetProductInfo  MsiGetProductInfoW
	#define MsiInstallProduct  MsiInstallProductW
	#define MsiConfigureProduct  MsiConfigureProductW
	#define MsiConfigureProductEx  MsiConfigureProductExW
	#define MsiReinstallProduct  MsiReinstallProductW
	#define MsiGetProductCode  MsiGetProductCodeW
	#define MsiGetUserInfo  MsiGetUserInfoW
	#define MsiCollectUserInfo  MsiCollectUserInfoW
	#define MsiApplyPatch  MsiApplyPatchW
	#define MsiGetPatchInfo  MsiGetPatchInfoW
	#define MsiEnumPatches  MsiEnumPatchesW
	#define MsiQueryFeatureState  MsiQueryFeatureStateW
	#define MsiUseFeature  MsiUseFeatureW
	#define MsiUseFeatureEx  MsiUseFeatureExW
	#define MsiGetFeatureUsage  MsiGetFeatureUsageW
	#define MsiConfigureFeature  MsiConfigureFeatureW
	#define MsiReinstallFeature  MsiReinstallFeatureW
	#define MsiProvideComponent  MsiProvideComponentW
	#define MsiProvideQualifiedComponent  MsiProvideQualifiedComponentW
	#define MsiProvideQualifiedComponentEx  MsiProvideQualifiedComponentExW
	#define MsiGetComponentPath  MsiGetComponentPathW
	#define MsiEnumProducts  MsiEnumProductsW
	#define MsiEnumRelatedProducts  MsiEnumRelatedProductsW
	#define MsiEnumFeatures  MsiEnumFeaturesW
	#define MsiEnumComponents  MsiEnumComponentsW
	#define MsiEnumClients  MsiEnumClientsW
	#define MsiEnumComponentQualifiers  MsiEnumComponentQualifiersW
	#define MsiOpenProduct  MsiOpenProductW
	#define MsiOpenPackage  MsiOpenPackageW
	#define MsiGetProductProperty  MsiGetProductPropertyW
	#define MsiVerifyPackage  MsiVerifyPackageW
	#define MsiGetFeatureInfo  MsiGetFeatureInfoW
	#define MsiInstallMissingComponent  MsiInstallMissingComponentW
	#define MsiInstallMissingFile  MsiInstallMissingFileW
	#define MsiLocateComponent  MsiLocateComponentW
	#define MsiSourceListClearAll  MsiSourceListClearAllW
	#define MsiSourceListAddSource  MsiSourceListAddSourceW
	#define MsiSourceListForceResolution  MsiSourceListForceResolutionW
	#define MsiGetFileVersion  MsiGetFileVersionW
	#define MsiGetShortcutTarget  MsiGetShortcutTargetW
#else
	#define INSTALLUI_HANDLER  INSTALLUI_HANDLERA
	#define MsiSetExternalUI  MsiSetExternalUIA
	#define MsiEnableLog  MsiEnableLogA
	#define MsiQueryProductState  MsiQueryProductStateA
	#define MsiGetProductInfo  MsiGetProductInfoA
	#define MsiInstallProduct  MsiInstallProductA
	#define MsiConfigureProduct  MsiConfigureProductA
	#define MsiConfigureProductEx  MsiConfigureProductExA
	#define MsiReinstallProduct  MsiReinstallProductA
	#define MsiGetProductCode  MsiGetProductCodeA
	#define MsiGetUserInfo  MsiGetUserInfoA
	#define MsiCollectUserInfo  MsiCollectUserInfoA
	#define MsiApplyPatch  MsiApplyPatchA
	#define MsiGetPatchInfo  MsiGetPatchInfoA
	#define MsiEnumPatches  MsiEnumPatchesA
	#define MsiQueryFeatureState  MsiQueryFeatureStateA
	#define MsiUseFeature  MsiUseFeatureA
	#define MsiUseFeatureEx  MsiUseFeatureExA
	#define MsiGetFeatureUsage  MsiGetFeatureUsageA
	#define MsiConfigureFeature  MsiConfigureFeatureA
	#define MsiReinstallFeature  MsiReinstallFeatureA
	#define MsiProvideComponent  MsiProvideComponentA
	#define MsiProvideQualifiedComponent  MsiProvideQualifiedComponentA
	#define MsiProvideQualifiedComponentEx  MsiProvideQualifiedComponentExA
	#define MsiGetComponentPath  MsiGetComponentPathA
	#define MsiEnumProducts  MsiEnumProductsA
	#define MsiEnumRelatedProducts  MsiEnumRelatedProductsA
	#define MsiEnumFeatures  MsiEnumFeaturesA
	#define MsiEnumComponents  MsiEnumComponentsA
	#define MsiEnumClients  MsiEnumClientsA
	#define MsiEnumComponentQualifiers  MsiEnumComponentQualifiersA
	#define MsiOpenProduct  MsiOpenProductA
	#define MsiOpenPackage  MsiOpenPackageA
	#define MsiGetProductProperty  MsiGetProductPropertyA
	#define MsiVerifyPackage  MsiVerifyPackageA
	#define MsiGetFeatureInfo  MsiGetFeatureInfoA
	#define MsiInstallMissingComponent  MsiInstallMissingComponentA
	#define MsiInstallMissingFile  MsiInstallMissingFileA
	#define MsiLocateComponent  MsiLocateComponentA
	#define MsiSourceListClearAll  MsiSourceListClearAllA
	#define MsiSourceListAddSource  MsiSourceListAddSourceA
	#define MsiSourceListForceResolution  MsiSourceListForceResolutionA
	#define MsiGetFileVersion  MsiGetFileVersionA
	#define MsiGetShortcutTarget  MsiGetShortcutTargetA
#endif /* UNICODE */

#endif /* _MSI_H */
