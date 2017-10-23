;=============================================================;
;          aclapi.inc file for Easy Code visual IDE           ;
;            (made for the GoAsm compiler version)            ;
;                                                             ;
;         Version 1.0.00 (created on February, 2007)          ;
;                                                             ;
;      Please report any bug you find (asm@easycode.cat)      ;
;                                                             ;
;                Do not modify this file!!                    ;
;=============================================================;

#IFNDEF ACLAPI_INC
#Define ACLAPI_INC

#IF STRINGS UNICODE
	#Define SetEntriesInAcl SetEntriesInAclW
	#Define GetExplicitEntriesFromAcl GetExplicitEntriesFromAclW
	#Define GetEffectiveRightsFromAcl GetEffectiveRightsFromAclW
	#Define GetAuditedPermissionsFromAcl GetAuditedPermissionsFromAclW
	#Define GetNamedSecurityInfo GetNamedSecurityInfoW
	#Define SetNamedSecurityInfo SetNamedSecurityInfoW
	#Define BuildSecurityDescriptor BuildSecurityDescriptorW
	#Define LookupSecurityDescriptorParts LookupSecurityDescriptorPartsW
	#Define BuildExplicitAccessWithName BuildExplicitAccessWithNameW
	#Define BuildImpersonateExplicitAccessWithName BuildImpersonateExplicitAccessWithNameW
	#Define BuildTrusteeWithName BuildTrusteeWithNameW
	#Define BuildImpersonateTrustee BuildImpersonateTrusteeW
	#Define BuildTrusteeWithSid BuildTrusteeWithSidW
	#Define GetTrusteeName GetTrusteeNameW
	#Define GetTrusteeType GetTrusteeTypeW
	#Define GetTrusteeForm GetTrusteeFormW
	#Define GetMultipleTrusteeOperation GetMultipleTrusteeOperationW
	#Define GetMultipleTrustee GetMultipleTrusteeW
	#Define GetNamedSecurityInfoEx GetNamedSecurityInfoExW
	#Define SetNamedSecurityInfoEx SetNamedSecurityInfoExW
	#Define GetSecurityInfoEx GetSecurityInfoExW
	#Define SetSecurityInfoEx SetSecurityInfoExW
	#Define ConvertAccessToSecurityDescriptor ConvertAccessToSecurityDescriptorW
	#Define ConvertSecurityDescriptorToAccess ConvertSecurityDescriptorToAccessW
	#Define ConvertSecurityDescriptorToAccessNamed ConvertSecurityDescriptorToAccessNamedW
	#Define SetEntriesInAccessList SetEntriesInAccessListW
	#Define SetEntriesInAuditList SetEntriesInAuditListW
	#Define TrusteeAccessToObject TrusteeAccessToObjectW
	#Define GetAccessPermissionsForObject GetAccessPermissionsForObjectW
#ELSE
	#Define SetEntriesInAcl SetEntriesInAclA
	#Define GetExplicitEntriesFromAcl GetExplicitEntriesFromAclA
	#Define GetEffectiveRightsFromAcl GetEffectiveRightsFromAclA
	#Define GetAuditedPermissionsFromAcl GetAuditedPermissionsFromAclA
	#Define GetNamedSecurityInfo GetNamedSecurityInfoA
	#Define SetNamedSecurityInfo SetNamedSecurityInfoA
	#Define BuildSecurityDescriptor BuildSecurityDescriptorA
	#Define LookupSecurityDescriptorParts LookupSecurityDescriptorPartsA
	#Define BuildExplicitAccessWithName BuildExplicitAccessWithNameA
	#Define BuildImpersonateExplicitAccessWithName BuildImpersonateExplicitAccessWithNameA
	#Define BuildTrusteeWithName BuildTrusteeWithNameA
	#Define BuildImpersonateTrustee BuildImpersonateTrusteeA
	#Define BuildTrusteeWithSid BuildTrusteeWithSidA
	#Define GetTrusteeName GetTrusteeNameA
	#Define GetTrusteeType GetTrusteeTypeA
	#Define GetTrusteeForm GetTrusteeFormA
	#Define GetMultipleTrusteeOperation GetMultipleTrusteeOperationA
	#Define GetMultipleTrustee GetMultipleTrusteeA
	#Define GetNamedSecurityInfoEx GetNamedSecurityInfoExA
	#Define SetNamedSecurityInfoEx SetNamedSecurityInfoExA
	#Define GetSecurityInfoEx GetSecurityInfoExA
	#Define SetSecurityInfoEx SetSecurityInfoExA
	#Define ConvertAccessToSecurityDescriptor ConvertAccessToSecurityDescriptorA
	#Define ConvertSecurityDescriptorToAccess ConvertSecurityDescriptorToAccessA
	#Define ConvertSecurityDescriptorToAccessNamed ConvertSecurityDescriptorToAccessNamedA
	#Define SetEntriesInAccessList SetEntriesInAccessListA
	#Define SetEntriesInAuditList SetEntriesInAuditListA
	#Define TrusteeAccessToObject TrusteeAccessToObjectA
	#Define GetAccessPermissionsForObject GetAccessPermissionsForObjectA
#ENDIF

#ENDIF ;ACLAPI_INC
