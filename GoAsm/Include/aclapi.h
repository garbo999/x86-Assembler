#ifndef ACLAPI_H
#define ACLAPI_H

/* Windows Access Control API definitions */

#IFDEF LINKFILES
	#dynamiclinkfile Advapi32.dll
#ENDIF

#IFNDEF WINDOWS_H
	#include windows.h
#ENDIF

#IFNDEF ACCCTRL_H
	#include accctrl.h
#ENDIF

#ifdef UNICODE
	#define SetEntriesInAcl SetEntriesInAclW
	#define GetExplicitEntriesFromAcl GetExplicitEntriesFromAclW
	#define GetEffectiveRightsFromAcl GetEffectiveRightsFromAclW
	#define GetAuditedPermissionsFromAcl GetAuditedPermissionsFromAclW
	#define GetNamedSecurityInfo GetNamedSecurityInfoW
	#define SetNamedSecurityInfo SetNamedSecurityInfoW
	#define BuildSecurityDescriptor BuildSecurityDescriptorW
	#define GetInheritanceSource  GetInheritanceSourceW
	#define LookupSecurityDescriptorParts LookupSecurityDescriptorPartsW
	#define BuildExplicitAccessWithName BuildExplicitAccessWithNameW
	#define BuildImpersonateExplicitAccessWithName BuildImpersonateExplicitAccessWithNameW
	#define BuildTrusteeWithName BuildTrusteeWithNameW
	#define BuildImpersonateTrustee BuildImpersonateTrusteeW
	#define BuildTrusteeWithSid BuildTrusteeWithSidW
	#define BuildTrusteeWithObjectsAndSid BuildTrusteeWithObjectsAndSidW
	#define BuildTrusteeWithObjectsAndName BuildTrusteeWithObjectsAndNameW
	#define GetTrusteeName GetTrusteeNameW
	#define GetTrusteeType GetTrusteeTypeW
	#define GetTrusteeForm GetTrusteeFormW
	#define GetMultipleTrusteeOperation GetMultipleTrusteeOperationW
	#define GetMultipleTrustee GetMultipleTrusteeW
	#define TreeResetNamedSecurityInfo  TreeResetNamedSecurityInfoW
	#define TreeSetNamedSecurityInfo  TreeSetNamedSecurityInfoW
#else
	#define SetEntriesInAcl SetEntriesInAclA
	#define GetExplicitEntriesFromAcl GetExplicitEntriesFromAclA
	#define GetEffectiveRightsFromAcl GetEffectiveRightsFromAclA
	#define GetAuditedPermissionsFromAcl GetAuditedPermissionsFromAclA
	#define GetNamedSecurityInfo GetNamedSecurityInfoA
	#define SetNamedSecurityInfo SetNamedSecurityInfoA
	#define BuildSecurityDescriptor BuildSecurityDescriptorA
	#define GetInheritanceSource  GetInheritanceSourceA
	#define LookupSecurityDescriptorParts LookupSecurityDescriptorPartsA
	#define BuildExplicitAccessWithName BuildExplicitAccessWithNameA
	#define BuildImpersonateExplicitAccessWithName BuildImpersonateExplicitAccessWithNameA
	#define BuildTrusteeWithName BuildTrusteeWithNameA
	#define BuildImpersonateTrustee BuildImpersonateTrusteeA
	#define BuildTrusteeWithSid BuildTrusteeWithSidA
	#define BuildTrusteeWithObjectsAndSid BuildTrusteeWithObjectsAndSidA
	#define BuildTrusteeWithObjectsAndName BuildTrusteeWithObjectsAndNameA
	#define GetTrusteeName GetTrusteeNameA
	#define GetTrusteeType GetTrusteeTypeA
	#define GetTrusteeForm GetTrusteeFormA
	#define GetMultipleTrusteeOperation GetMultipleTrusteeOperationA
	#define GetMultipleTrustee GetMultipleTrusteeA
	#define TreeResetNamedSecurityInfo  TreeResetNamedSecurityInfoA
	#define TreeSetNamedSecurityInfo  TreeSetNamedSecurityInfoA
#endif
#endif
