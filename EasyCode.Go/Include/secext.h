#ifndef SECEXT_H
#define SECEXT_H

/* Security definitions not part of the SSPI interface */

#define SEC_WINNT_AUTH_IDENTITY_MARSHALLED  0x4
#define SEC_WINNT_AUTH_IDENTITY_ONLY  0x8

#define SECPKG_OPTIONS_TYPE_UNKNOWN 0
#define SECPKG_OPTIONS_TYPE_LSA  1
#define SECPKG_OPTIONS_TYPE_SSPI  2

#define SECPKG_OPTIONS_PERMANENT  0x00000001

SEC_WINNT_AUTH_IDENTITY_EXW STRUCT
	Version DD
	Length DD
	User PTR
	UserLength DD
	Domain PTR
	DomainLength DD
	Password PTR
	PasswordLength DD
	Flags DD
	PackageList PTR
	PackageListLength DD
ENDS

SEC_WINNT_AUTH_IDENTITY_EXA STRUCT
	Version DD
	Length DD
	User PTR
	UserLength DD
	Domain PTR
	DomainLength DD
	Password PTR
	PasswordLength DD
	Flags DD
	PackageList PTR
	PackageListLength DD
ENDS

SECURITY_PACKAGE_OPTIONS STRUCT
	Size DD
	Type DD
	Flags DD
	SignatureSize DD
	Signature PTR
ENDS

NameUnknown = 0
NameFullyQualifiedDN = 1
NameSamCompatible = 2
NameDisplay = 3
NameUniqueId = 6
NameCanonical = 7
NameUserPrincipal = 8
NameCanonicalEx = 9
NameServicePrincipal = 10

#IFDEF UNICODE
	#define SEC_WINNT_AUTH_IDENTITY_EX  SEC_WINNT_AUTH_IDENTITY_EXW
	#define AddSecurityPackage  AddSecurityPackageW
	#define DeleteSecurityPackage  DeleteSecurityPackageW
	#define GetUserNameEx  GetUserNameExW
	#define GetComputerObjectName  GetComputerObjectNameW
	#define TranslateName  TranslateNameW
#else
	#define SEC_WINNT_AUTH_IDENTITY_EX  SEC_WINNT_AUTH_IDENTITY_EXA
	#define AddSecurityPackage  AddSecurityPackageA
	#define DeleteSecurityPackage  DeleteSecurityPackageA
	#define GetUserNameEx  GetUserNameExA
	#define GetComputerObjectName  GetComputerObjectNameA
	#define TranslateName  TranslateNameA
#endif /* UNICODE */

#endif /* _SECEXT_H */
