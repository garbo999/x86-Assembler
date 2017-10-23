#ifndef LMJOIN_H
#define LMJOIN_H

/* NetSetup API definitions */

#define NETSETUP_JOIN_DOMAIN  0x00000001
#define NETSETUP_ACCT_CREATE  0x00000002
#define NETSETUP_ACCT_DELETE  0x00000004
#define NETSETUP_WIN9X_UPGRADE  0x00000010
#define NETSETUP_DOMAIN_JOIN_IF_JOINED  0x00000020
#define NETSETUP_JOIN_UNSECURE  0x00000040
#define NETSETUP_INSTALL_INVOCATION  0x00040000

NetSetupUnknown = 0
NetSetupMachine = 1
NetSetupWorkgroup = 2
NetSetupDomain = 3
NetSetupNonExistentDomain = 4
NetSetupDnsMachine = 5

NetSetupUnknownStatus = 0
NetSetupUnjoined = 1
NetSetupWorkgroupName = 2
NetSetupDomainName = 3

#endif /* _LMJOIN_H */
