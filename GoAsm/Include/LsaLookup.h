/*++

Copyright (c) Microsoft Corporation, 1992 -

Module Name:

    lsalookup.h

Abstract:

    LSA Policy Lookup API

--*/

#ifndef LSALOOKUP_H
#define LSALOOKUP_H

LSA_UNICODE_STRING STRUCT
	Length SHORT
	MaximumLength SHORT
	Buffer PTR
ENDS

LSA_STRING STRUCT
	Length SHORT
	MaximumLength SHORT
	Buffer PTR
ENDS

LSA_OBJECT_ATTRIBUTES STRUCT
	Length DD
	RootDirectory DD
	ObjectName PTR
	Attributes DD
	SecurityDescriptor PTR
	SecurityQualityOfService PTR
ENDS

LSA_TRUST_INFORMATION STRUCT
	Name LSA_UNICODE_STRING
	Sid PTR
ENDS

LSA_REFERENCED_DOMAIN_LIST STRUCT
	Entries LONG
	Domains PTR
ENDS

#if WINVER >= NTDDI_WINXP
	LSA_TRANSLATED_SID2 STRUCT
		Use ENUM
		Sid PTR
		DomainIndex LONG
		Flags LONG
	ENDS
#endif

LSA_TRANSLATED_NAME STRUCT
	Use ENUM
	Name LSA_UNICODE_STRING
	DomainIndex LONG
ENDS

POLICY_ACCOUNT_DOMAIN_INFO STRUCT
	DomainName LSA_UNICODE_STRING
	DomainSid PTR
ENDS

POLICY_DNS_DOMAIN_INFO STRUCT
	Name LSA_UNICODE_STRING
	DnsDomainName LSA_UNICODE_STRING
	DnsForestName LSA_UNICODE_STRING
	DomainGuid GUID
	Sid PTR
ENDS

#define LOOKUP_VIEW_LOCAL_INFORMATION 0x00000001
#define LOOKUP_TRANSLATE_NAMES 0x00000800

AccountDomainInformation = 5
DnsDomainInformation = 12

#endif

