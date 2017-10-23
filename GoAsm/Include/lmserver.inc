;=============================================================;
;         lmserver.inc file for Easy Code visual IDE          ;
;            (made for the GoAsm compiler version)            ;
;                                                             ;
;           Version 1.0.00 (created on March, 2008)           ;
;                                                             ;
;      Please report any bug you find (asm@easycode.cat)      ;
;                                                             ;
;                Do not modify this file!!                    ;
;=============================================================;

#IFNDEF LMSERVER_INC
#Define LMSERVER_INC

#IFNDEF WINSVC_INC
	#Include winsvc.inc
#ENDIF

SERVER_INFO_100 Struct
	sv100_platform_id DD
	sv100_name DD
EndS

SERVER_INFO_101 Struct
	sv101_platform_id DD
	sv101_name DD
	sv101_version_major DD
	sv101_version_minor DD
	sv101_type DD
	sv101_comment DD
EndS

SERVER_INFO_102 Struct
 	sv102_platform_id DD
 	sv102_name DD
 	sv102_version_major DD
 	sv102_version_minor DD
 	sv102_type DD
 	sv102_comment DD
 	sv102_users DD
	sv102_disc DD
 	sv102_hidden DD
 	sv102_announce DD
 	sv102_anndelta DD
 	sv102_licenses DD
 	sv102_userpath DD
EndS

SERVER_INFO_402 Struct
 	sv402_ulist_mtime DD
 	sv402_glist_mtime DD
 	sv402_alist_mtime DD
 	sv402_alerts DD
 	sv402_security DD
 	sv402_numadmin DD
 	sv402_lanmask DD
 	sv402_guestacct DD
 	sv402_chdevs DD
 	sv402_chdevq DD
 	sv402_chdevjobs DD
 	sv402_connections DD
 	sv402_shares DD
 	sv402_openfiles DD
 	sv402_sessopens DD
 	sv402_sessvcs DD
 	sv402_sessreqs DD
 	sv402_opensearch DD
 	sv402_activelocks DD
 	sv402_numreqbuf DD
 	sv402_sizreqbuf DD
 	sv402_numbigbuf DD
 	sv402_numfiletasks DD
 	sv402_alertsched DD
 	sv402_erroralert DD
 	sv402_logonalert DD
 	sv402_accessalert DD
 	sv402_diskalert DD
 	sv402_netioalert DD
 	sv402_maxauditsz DD
 	sv402_srvheuristics DD
EndS

SERVER_INFO_403 Struct
 	sv403_ulist_mtime DD
 	sv403_glist_mtime DD
 	sv403_alist_mtime DD
 	sv403_alerts DD
 	sv403_security DD
 	sv403_numadmin DD
 	sv403_lanmask DD
 	sv403_guestacct DD
 	sv403_chdevs DD
 	sv403_chdevq DD
 	sv403_chdevjobs DD
 	sv403_connections DD
 	sv403_shares DD
 	sv403_openfiles DD
 	sv403_sessopens DD
 	sv403_sessvcs DD
 	sv403_sessreqs DD
 	sv403_opensearch DD
 	sv403_activelocks DD
 	sv403_numreqbuf DD
 	sv403_sizreqbuf DD
 	sv403_numbigbuf DD
 	sv403_numfiletasks DD
 	sv403_alertsched DD
 	sv403_erroralert DD
 	sv403_logonalert DD
 	sv403_accessalert DD
 	sv403_diskalert DD
 	sv403_netioalert DD
 	sv403_maxauditsz DD
 	sv403_srvheuristics DD
 	sv403_auditedevents DD
 	sv403_autoprofile DD
 	sv403_autopath DD
EndS

SERVER_INFO_502 Struct
	sv502_sessopens DD
	sv502_sessvcs DD
	sv502_opensearch DD
	sv502_sizreqbuf DD
	sv502_initworkitems DD
	sv502_maxworkitems DD
	sv502_rawworkitems DD
	sv502_irpstacksize DD
	sv502_maxrawbuflen DD
	sv502_sessusers DD
	sv502_sessconns DD
	sv502_maxpagedmemoryusage DD
	sv502_maxnonpagedmemoryusage DD
	sv502_enablesoftcompat DD
	sv502_enableforcedlogoff DD
	sv502_timesource DD
	sv502_acceptdownlevelapis DD
	sv502_lmannounce DD
EndS

SERVER_INFO_503 Struct
	sv503_sessopens DD
	sv503_sessvcs DD
	sv503_opensearch DD
	sv503_sizreqbuf DD
	sv503_initworkitems DD
	sv503_maxworkitems DD
	sv503_rawworkitems DD
	sv503_irpstacksize DD
	sv503_maxrawbuflen DD
	sv503_sessusers DD
	sv503_sessconns DD
	sv503_maxpagedmemoryusage DD
	sv503_maxnonpagedmemoryusage DD
	sv503_enablesoftcompat DD
	sv503_enableforcedlogoff DD
	sv503_timesource DD
	sv503_acceptdownlevelapis DD
	sv503_lmannounce DD
	sv503_domain DD
	sv503_maxcopyreadlen DD
	sv503_maxcopywritelen DD
	sv503_minkeepsearch DD
	sv503_maxkeepsearch DD
	sv503_minkeepcomplsearch DD
	sv503_maxkeepcomplsearch DD
	sv503_threadcountadd DD
	sv503_numblockthreads DD
	sv503_scavtimeout DD
	sv503_minrcvqueue DD
	sv503_minfreeworkitems DD
	sv503_xactmemsize DD
	sv503_threadpriority DD
	sv503_maxmpxct DD
	sv503_oplockbreakwait DD
	sv503_oplockbreakresponsewait DD
	sv503_enableoplocks DD
	sv503_enableoplockforceclose DD
	sv503_enablefcbopens DD
	sv503_enableraw DD
	sv503_enablesharednetdrives DD
	sv503_minfreeconnections DD
	sv503_maxfreeconnections DD
EndS

SERVER_INFO_599 Struct
	sv599_sessopens DD
	sv599_sessvcs DD
	sv599_opensearch DD
	sv599_sizreqbuf DD
	sv599_initworkitems DD
	sv599_maxworkitems DD
	sv599_rawworkitems DD
	sv599_irpstacksize DD
	sv599_maxrawbuflen DD
	sv599_sessusers DD
	sv599_sessconns DD
	sv599_maxpagedmemoryusage DD
	sv599_maxnonpagedmemoryusage DD
	sv599_enablesoftcompat DD
	sv599_enableforcedlogoff DD
	sv599_timesource DD
	sv599_acceptdownlevelapis DD
	sv599_lmannounce DD
	sv599_domain DD
	sv599_maxcopyreadlen DD
	sv599_maxcopywritelen DD
	sv599_minkeepsearch DD
	sv599_maxkeepsearch DD
	sv599_minkeepcomplsearch DD
	sv599_maxkeepcomplsearch DD
	sv599_threadcountadd DD
	sv599_numblockthreads DD
	sv599_scavtimeout DD
	sv599_minrcvqueue DD
	sv599_minfreeworkitems DD
	sv599_xactmemsize DD
	sv599_threadpriority DD
	sv599_maxmpxct DD
	sv599_oplockbreakwait DD
	sv599_oplockbreakresponsewait DD
	sv599_enableoplocks DD
	sv599_enableoplockforceclose DD
	sv599_enablefcbopens DD
	sv599_enableraw DD
	sv599_enablesharednetdrives DD
	sv599_minfreeconnections DD
	sv599_maxfreeconnections DD
	sv599_initsesstable DD
	sv599_initconntable DD
	sv599_initfiletable DD
	sv599_initsearchtable DD
	sv599_alertschedule DD
	sv599_errorthreshold DD
	sv599_networkerrorthreshold DD
	sv599_diskspacethreshold DD
	sv599_reserved DD
	sv599_maxlinkdelay DD
	sv599_minlinkthroughput DD
	sv599_linkinfovalidtime DD
	sv599_scavqosinfoupdatetime DD
	sv599_maxworkitemidletime DD
EndS

SERVER_INFO_598 Struct
	sv598_maxrawworkitems DD
	sv598_maxthreadsperqueue DD
	sv598_producttype DD
	sv598_serversize DD
	sv598_connectionlessautodisc DD
	sv598_sharingviolationretries DD
	sv598_sharingviolationdelay DD
	sv598_maxglobalopensearch DD
	sv598_removeduplicatesearches DD
	sv598_lockviolationoffset DD
	sv598_lockviolationdelay DD
	sv598_mdlreadswitchover DD
	sv598_cachedopenlimit DD
	sv598_otherqueueaffinity DD
	sv598_restrictnullsessaccess DD
	sv598_enablewfw311directipx DD
	sv598_queuesamplesecs DD
	sv598_balancecount DD
	sv598_preferredaffinity DD
	sv598_maxfreerfcbs DD
	sv598_maxfreemfcbs DD
	sv598_maxfreelfcbs DD
	sv598_maxfreepagedpoolchunks DD
	sv598_minpagedpoolchunksize DD
	sv598_maxpagedpoolchunksize DD
	sv598_sendsfrompreferredprocessor DD
	sv598_cacheddirectorylimit DD
	sv598_maxcopylength DD
	sv598_enablecompression DD
	sv598_autosharewks DD
	sv598_autoshareserver DD
	sv598_enablesecuritysignature DD
	sv598_requiresecuritysignature DD
	sv598_minclientbuffersize DD
	sv598_serverguid GUID <>
	sv598_ConnectionNoSessionsTimeout DD
	sv598_IdleThreadTimeOut DD
	sv598_enableW9xsecuritysignature DD
EndS

SERVER_INFO_1005 Struct
	sv1005_comment DD
EndS

SERVER_INFO_1107 Struct
	sv1107_users DD
EndS

SERVER_INFO_1010 Struct
    LONG sv1010_disc DD
EndS

SERVER_INFO_1016 Struct
	sv1016_hidden DD
EndS

SERVER_INFO_1017 Struct
	sv1017_announce DD
EndS

SERVER_INFO_1018 Struct
	sv1018_anndelta DD
EndS

SERVER_INFO_1501 Struct
	sv1501_sessopens DD
EndS

SERVER_INFO_1502 Struct
	sv1502_sessvcs DD
EndS

SERVER_INFO_1503 Struct
	sv1503_opensearch DD
EndS

SERVER_INFO_1506 Struct
	sv1506_maxworkitems DD
EndS

SERVER_INFO_1509 Struct
	sv1509_maxrawbuflen DD
EndS

SERVER_INFO_1510 Struct
	sv1510_sessusers DD
EndS

SERVER_INFO_1511 Struct
	sv1511_sessconns DD
EndS

SERVER_INFO_1512 Struct
	sv1512_maxnonpagedmemoryusage DD
EndS

SERVER_INFO_1513 Struct
	sv1513_maxpagedmemoryusage DD
EndS

SERVER_INFO_1514 Struct
	sv1514_enablesoftcompat DD
EndS

SERVER_INFO_1515 Struct
	sv1515_enableforcedlogoff DD
EndS

SERVER_INFO_1516 Struct
	sv1516_timesource DD
EndS

SERVER_INFO_1518 Struct
	sv1518_lmannounce DD
EndS

SERVER_INFO_1520 Struct
	sv1520_maxcopyreadlen DD
EndS

SERVER_INFO_1521 Struct
	sv1521_maxcopywritelen DD
EndS

SERVER_INFO_1522 Struct
	sv1522_minkeepsearch DD
EndS

SERVER_INFO_1523 Struct
	sv1523_maxkeepsearch DD
EndS

SERVER_INFO_1524 Struct
	sv1524_minkeepcomplsearch DD
EndS

SERVER_INFO_1525 Struct
	sv1525_maxkeepcomplsearch DD
EndS

SERVER_INFO_1528 Struct
	sv1528_scavtimeout DD
EndS

SERVER_INFO_1529 Struct
	sv1529_minrcvqueue DD
EndS

SERVER_INFO_1530 Struct
	sv1530_minfreeworkitems DD
EndS

SERVER_INFO_1533 Struct
	sv1533_maxmpxct DD
EndS

SERVER_INFO_1534 Struct
	sv1534_oplockbreakwait DD
EndS

SERVER_INFO_1535 Struct
	sv1535_oplockbreakresponsewait DD
EndS

SERVER_INFO_1536 Struct
	sv1536_enableoplocks DD
EndS

SERVER_INFO_1537 Struct
	sv1537_enableoplockforceclose DD
EndS

SERVER_INFO_1538 Struct
	sv1538_enablefcbopens DD
EndS

SERVER_INFO_1539 Struct
	sv1539_enableraw DD
EndS

SERVER_INFO_1540 Struct
	sv1540_enablesharednetdrives DD
EndS

SERVER_INFO_1541 Struct
	sv1541_minfreeconnections DD
EndS

SERVER_INFO_1542 Struct
	sv1542_maxfreeconnections DD
EndS

SERVER_INFO_1543 Struct
	sv1543_initsesstable DD
EndS

SERVER_INFO_1544 Struct
	sv1544_initconntable DD
EndS

SERVER_INFO_1545 Struct
	sv1545_initfiletable DD
EndS

SERVER_INFO_1546 Struct
	sv1546_initsearchtable DD
EndS

SERVER_INFO_1547 Struct
	sv1547_alertschedule DD
EndS

SERVER_INFO_1548 Struct
	sv1548_errorthreshold DD
EndS

SERVER_INFO_1549 Struct
	sv1549_networkerrorthreshold DD
EndS

SERVER_INFO_1550 Struct
	sv1550_diskspacethreshold DD
EndS

SERVER_INFO_1552 Struct
	sv1552_maxlinkdelay DD
EndS

SERVER_INFO_1553 Struct
	sv1553_minlinkthroughput DD
EndS

SERVER_INFO_1554 Struct
	sv1554_linkinfovalidtime DD
EndS

SERVER_INFO_1555 Struct
	sv1555_scavqosinfoupdatetime DD
EndS

SERVER_INFO_1556 Struct
	sv1556_maxworkitemidletime DD
EndS

SERVER_INFO_1557 Struct
	sv1557_maxrawworkitems DD
EndS

SERVER_INFO_1560 Struct
	sv1560_producttype DD
EndS

SERVER_INFO_1561 Struct
	sv1561_serversize DD
EndS

SERVER_INFO_1562 Struct
	sv1562_connectionlessautodisc DD
EndS

SERVER_INFO_1563 Struct
	sv1563_sharingviolationretries DD
EndS

SERVER_INFO_1564 Struct
	sv1564_sharingviolationdelay DD
EndS

SERVER_INFO_1565 Struct
	sv1565_maxglobalopensearch DD
EndS

SERVER_INFO_1566 Struct
	sv1566_removeduplicatesearches DD
EndS

SERVER_INFO_1567 Struct
	sv1567_lockviolationretries DD
EndS

SERVER_INFO_1568 Struct
	sv1568_lockviolationoffset DD
EndS

SERVER_INFO_1569 Struct
	sv1569_lockviolationdelay DD
EndS

SERVER_INFO_1570 Struct
	sv1570_mdlreadswitchover DD
EndS

SERVER_INFO_1571 Struct
	sv1571_cachedopenlimit DD
EndS

SERVER_INFO_1572 Struct
	sv1572_criticalthreads DD
EndS

SERVER_INFO_1573 Struct
	sv1573_restrictnullsessaccess DD
EndS

SERVER_INFO_1574 Struct
	sv1574_enablewfw311directipx DD
EndS

SERVER_INFO_1575 Struct
	sv1575_otherqueueaffinity DD
EndS

SERVER_INFO_1576 Struct
	sv1576_queuesamplesecs DD
EndS

SERVER_INFO_1577 Struct
	sv1577_balancecount DD
EndS

SERVER_INFO_1578 Struct
	sv1578_preferredaffinity DD
EndS

SERVER_INFO_1579 Struct
	sv1579_maxfreerfcbs DD
EndS

SERVER_INFO_1580 Struct
	sv1580_maxfreemfcbs DD
EndS

SERVER_INFO_1581 Struct
	sv1581_maxfreemlcbs DD
EndS

SERVER_INFO_1582 Struct
	sv1582_maxfreepagedpoolchunks DD
EndS

SERVER_INFO_1583 Struct
	sv1583_minpagedpoolchunksize DD
EndS

SERVER_INFO_1584 Struct
	sv1584_maxpagedpoolchunksize DD
EndS

SERVER_INFO_1585 Struct
	sv1585_sendsfrompreferredprocessor DD
EndS

SERVER_INFO_1586 Struct
	sv1586_maxthreadsperqueue DD
EndS

SERVER_INFO_1587 Struct
	sv1587_cacheddirectorylimit DD
EndS

SERVER_INFO_1588 Struct
	sv1588_maxcopylength DD
EndS

SERVER_INFO_1589 Struct
	sv1589_enablebulktransfer DD
EndS

SERVER_INFO_1590 Struct
	sv1590_enablecompression DD
EndS

SERVER_INFO_1591 Struct
	sv1591_autosharewks DD
EndS

SERVER_INFO_1592 Struct
	sv1592_autosharewks DD
EndS

SERVER_INFO_1593 Struct
	sv1593_enablesecuritysignature DD
EndS

SERVER_INFO_1594 Struct
	sv1594_requiresecuritysignature DD
EndS

SERVER_INFO_1595 Struct
	sv1595_minclientbuffersize DD
EndS

SERVER_INFO_1596 Struct
	sv1596_ConnectionNoSessionsTimeout DD
EndS

SERVER_TRANSPORT_INFO_0 Struct
	svti0_numberofvcs DD
	svti0_transportname DD
	svti0_transportaddress DD
	svti0_transportaddresslength DD
	svti0_networkaddress DD
EndS

SERVER_TRANSPORT_INFO_1 Struct
	svti1_numberofvcs DD
	svti1_transportname DD
	svti1_transportaddress DD
	svti1_transportaddresslength DD
	svti1_networkaddress DD
	svti1_domain DD
EndS

SERVER_TRANSPORT_INFO_2 Struct
	svti2_numberofvcs DD
	svti2_transportname DD
	svti2_transportaddress DD
	svti2_transportaddresslength DD
	svti2_networkaddress DD
	svti2_domain DD
	svti2_flags DD
EndS

#Define SV_PLATFORM_ID_OS2                  400
#Define SV_PLATFORM_ID_NT                   500

#Define MAJOR_VERSION_MASK                  00FH

#Define SV_TYPE_WORKSTATION                 000000001H
#Define SV_TYPE_SERVER                      000000002H
#Define SV_TYPE_SQLSERVER                   000000004H
#Define SV_TYPE_DOMAIN_CTRL                 000000008H
#Define SV_TYPE_DOMAIN_BAKCTRL              000000010H
#Define SV_TYPE_TIME_SOURCE                 000000020H
#Define SV_TYPE_AFP                         000000040H
#Define SV_TYPE_NOVELL                      000000080H
#Define SV_TYPE_DOMAIN_MEMBER               000000100H
#Define SV_TYPE_PRINTQ_SERVER               000000200H
#Define SV_TYPE_DIALIN_SERVER               000000400H
#Define SV_TYPE_XENIX_SERVER                000000800H
#Define SV_TYPE_SERVER_UNIX                 SV_TYPE_XENIX_SERVER
#Define SV_TYPE_NT                          000001000H
#Define SV_TYPE_WFW                         000002000H
#Define SV_TYPE_SERVER_MFPN                 000004000H
#Define SV_TYPE_SERVER_NT                   000008000H
#Define SV_TYPE_POTENTIAL_BROWSER           000010000H
#Define SV_TYPE_BACKUP_BROWSER              000020000H
#Define SV_TYPE_MASTER_BROWSER              000040000H
#Define SV_TYPE_DOMAIN_MASTER               000080000H
#Define SV_TYPE_SERVER_OSF                  000100000H
#Define SV_TYPE_SERVER_VMS                  000200000H
#Define SV_TYPE_WINDOWS                     000400000H
#Define SV_TYPE_DFS                         000800000H
#Define SV_TYPE_CLUSTER_NT                  001000000H
#Define SV_TYPE_DCE                         010000000H
#Define SV_TYPE_ALTERNATE_XPORT             020000000H
#Define SV_TYPE_LOCAL_LIST_ONLY             040000000H
#Define SV_TYPE_DOMAIN_ENUM                 080000000H
#Define SV_TYPE_ALL                         0FFFFFFFFH

#Define SV_NODISC                           (-1)

#Define SV_USERSECURITY                     1
#Define SV_SHARESECURITY                    0

#Define SV_HIDDEN                           1
#Define SV_VISIBLE                          0

#Define SV_PLATFORM_ID_PARMNUM              101
#Define SV_NAME_PARMNUM                     102
#Define SV_VERSION_MAJOR_PARMNUM            103
#Define SV_VERSION_MINOR_PARMNUM            104
#Define SV_TYPE_PARMNUM                     105
#Define SV_COMMENT_PARMNUM                  5
#Define SV_USERS_PARMNUM                    107
#Define SV_DISC_PARMNUM                     10
#Define SV_HIDDEN_PARMNUM                   16
#Define SV_ANNOUNCE_PARMNUM                 17
#Define SV_ANNDELTA_PARMNUM                 18
#Define SV_USERPATH_PARMNUM                 112

#Define SV_ULIST_MTIME_PARMNUM              401
#Define SV_GLIST_MTIME_PARMNUM              402
#Define SV_ALIST_MTIME_PARMNUM              403
#Define SV_ALERTS_PARMNUM                   11
#Define SV_SECURITY_PARMNUM                 405
#Define SV_NUMADMIN_PARMNUM                 406
#Define SV_LANMASK_PARMNUM                  407
#Define SV_GUESTACC_PARMNUM                 408
#Define SV_CHDEVQ_PARMNUM                   410
#Define SV_CHDEVJOBS_PARMNUM                411
#Define SV_CONNECTIONS_PARMNUM              412
#Define SV_SHARES_PARMNUM                   413
#Define SV_OPENFILES_PARMNUM                414
#Define SV_SESSREQS_PARMNUM                 417
#Define SV_ACTIVELOCKS_PARMNUM              419
#Define SV_NUMREQBUF_PARMNUM                420
#Define SV_NUMBIGBUF_PARMNUM                422
#Define SV_NUMFILETASKS_PARMNUM             423
#Define SV_ALERTSCHED_PARMNUM               37
#Define SV_ERRORALERT_PARMNUM               38
#Define SV_LOGONALERT_PARMNUM               39
#Define SV_ACCESSALERT_PARMNUM              40
#Define SV_DISKALERT_PARMNUM                41
#Define SV_NETIOALERT_PARMNUM               42
#Define SV_MAXAUDITSZ_PARMNUM               43
#Define SV_SRVHEURISTICS_PARMNUM            431

#Define SV_SESSOPENS_PARMNUM                501
#Define SV_SESSVCS_PARMNUM                  502
#Define SV_OPENSEARCH_PARMNUM               503
#Define SV_SIZREQBUF_PARMNUM                504
#Define SV_INITWORKITEMS_PARMNUM            505
#Define SV_MAXWORKITEMS_PARMNUM             506
#Define SV_RAWWORKITEMS_PARMNUM             507
#Define SV_IRPSTACKSIZE_PARMNUM             508
#Define SV_MAXRAWBUFLEN_PARMNUM             509
#Define SV_SESSUSERS_PARMNUM                510
#Define SV_SESSCONNS_PARMNUM                511
#Define SV_MAXNONPAGEDMEMORYUSAGE_PARMNUM   512
#Define SV_MAXPAGEDMEMORYUSAGE_PARMNUM      513
#Define SV_ENABLESOFTCOMPAT_PARMNUM         514
#Define SV_ENABLEFORCEDLOGOFF_PARMNUM       515
#Define SV_TIMESOURCE_PARMNUM               516
#Define SV_ACCEPTDOWNLEVELAPIS_PARMNUM      517
#Define SV_LMANNOUNCE_PARMNUM               518
#Define SV_DOMAIN_PARMNUM                   519
#Define SV_MAXCOPYREADLEN_PARMNUM           520
#Define SV_MAXCOPYWRITELEN_PARMNUM          521
#Define SV_MINKEEPSEARCH_PARMNUM            522
#Define SV_MAXKEEPSEARCH_PARMNUM            523
#Define SV_MINKEEPCOMPLSEARCH_PARMNUM       524
#Define SV_MAXKEEPCOMPLSEARCH_PARMNUM       525
#Define SV_THREADCOUNTADD_PARMNUM           526
#Define SV_NUMBLOCKTHREADS_PARMNUM          527
#Define SV_SCAVTIMEOUT_PARMNUM              528
#Define SV_MINRCVQUEUE_PARMNUM              529
#Define SV_MINFREEWORKITEMS_PARMNUM         530
#Define SV_XACTMEMSIZE_PARMNUM              531
#Define SV_THREADPRIORITY_PARMNUM           532
#Define SV_MAXMPXCT_PARMNUM                 533
#Define SV_OPLOCKBREAKWAIT_PARMNUM          534
#Define SV_OPLOCKBREAKRESPONSEWAIT_PARMNUM  535
#Define SV_ENABLEOPLOCKS_PARMNUM            536
#Define SV_ENABLEOPLOCKFORCECLOSE_PARMNUM   537
#Define SV_ENABLEFCBOPENS_PARMNUM           538
#Define SV_ENABLERAW_PARMNUM                539
#Define SV_ENABLESHAREDNETDRIVES_PARMNUM    540
#Define SV_MINFREECONNECTIONS_PARMNUM       541
#Define SV_MAXFREECONNECTIONS_PARMNUM       542
#Define SV_INITSESSTABLE_PARMNUM            543
#Define SV_INITCONNTABLE_PARMNUM            544
#Define SV_INITFILETABLE_PARMNUM            545
#Define SV_INITSEARCHTABLE_PARMNUM          546
#Define SV_ALERTSCHEDULE_PARMNUM            547
#Define SV_ERRORTHRESHOLD_PARMNUM           548
#Define SV_NETWORKERRORTHRESHOLD_PARMNUM    549
#Define SV_DISKSPACETHRESHOLD_PARMNUM       550
#Define SV_MAXLINKDELAY_PARMNUM             552
#Define SV_MINLINKTHROUGHPUT_PARMNUM        553
#Define SV_LINKINFOVALIDTIME_PARMNUM        554
#Define SV_SCAVQOSINFOUPDATETIME_PARMNUM    555
#Define SV_MAXWORKITEMIDLETIME_PARMNUM      556
#Define SV_MAXRAWWORKITEMS_PARMNUM          557
#Define SV_PRODUCTTYPE_PARMNUM              560
#Define SV_SERVERSIZE_PARMNUM               561
#Define SV_CONNECTIONLESSAUTODISC_PARMNUM   562
#Define SV_SHARINGVIOLATIONRETRIES_PARMNUM  563
#Define SV_SHARINGVIOLATIONDELAY_PARMNUM    564
#Define SV_MAXGLOBALOPENSEARCH_PARMNUM      565
#Define SV_REMOVEDUPLICATESEARCHES_PARMNUM  566
#Define SV_LOCKVIOLATIONRETRIES_PARMNUM     567
#Define SV_LOCKVIOLATIONOFFSET_PARMNUM      568
#Define SV_LOCKVIOLATIONDELAY_PARMNUM       569
#Define SV_MDLREADSWITCHOVER_PARMNUM        570
#Define SV_CACHEDOPENLIMIT_PARMNUM          571
#Define SV_CRITICALTHREADS_PARMNUM          572
#Define SV_RESTRICTNULLSESSACCESS_PARMNUM   573
#Define SV_ENABLEWFW311DIRECTIPX_PARMNUM    574
#Define SV_OTHERQUEUEAFFINITY_PARMNUM       575
#Define SV_QUEUESAMPLESECS_PARMNUM          576
#Define SV_BALANCECOUNT_PARMNUM             577
#Define SV_PREFERREDAFFINITY_PARMNUM        578
#Define SV_MAXFREERFCBS_PARMNUM             579
#Define SV_MAXFREEMFCBS_PARMNUM             580
#Define SV_MAXFREELFCBS_PARMNUM             581
#Define SV_MAXFREEPAGEDPOOLCHUNKS_PARMNUM   582
#Define SV_MINPAGEDPOOLCHUNKSIZE_PARMNUM    583
#Define SV_MAXPAGEDPOOLCHUNKSIZE_PARMNUM    584
#Define SV_SENDSFROMPREFERREDPROCESSOR_PARMNUM 585
#Define SV_MAXTHREADSPERQUEUE_PARMNUM       586
#Define SV_CACHEDDIRECTORYLIMIT_PARMNUM     587
#Define SV_MAXCOPYLENGTH_PARMNUM            588
#Define SV_ENABLEBULKTRANSFER_PARMNUM       589
#Define SV_ENABLECOMPRESSION_PARMNUM        590
#Define SV_AUTOSHAREWKS_PARMNUM             591
#Define SV_AUTOSHARESERVER_PARMNUM          592
#Define SV_ENABLESECURITYSIGNATURE_PARMNUM  593
#Define SV_REQUIRESECURITYSIGNATURE_PARMNUM 594
#Define SV_MINCLIENTBUFFERSIZE_PARMNUM      595
#Define SV_CONNECTIONNOSESSIONSTIMEOUT_PARMNUM 596

#Define SV_COMMENT_INFOLEVEL                (PARMNUM_BASE_INFOLEVEL + SV_COMMENT_PARMNUM)
#Define SV_USERS_INFOLEVEL                  (PARMNUM_BASE_INFOLEVEL + SV_USERS_PARMNUM)
#Define SV_DISC_INFOLEVEL                   (PARMNUM_BASE_INFOLEVEL + SV_DISC_PARMNUM)
#Define SV_HIDDEN_INFOLEVEL                 (PARMNUM_BASE_INFOLEVEL + SV_HIDDEN_PARMNUM)
#Define SV_ANNOUNCE_INFOLEVEL               (PARMNUM_BASE_INFOLEVEL + SV_ANNOUNCE_PARMNUM)
#Define SV_ANNDELTA_INFOLEVEL               (PARMNUM_BASE_INFOLEVEL + SV_ANNDELTA_PARMNUM)
#Define SV_SESSOPENS_INFOLEVEL              (PARMNUM_BASE_INFOLEVEL + SV_SESSOPENS_PARMNUM)
#Define SV_SESSVCS_INFOLEVEL                (PARMNUM_BASE_INFOLEVEL + SV_SESSVCS_PARMNUM)
#Define SV_OPENSEARCH_INFOLEVEL             (PARMNUM_BASE_INFOLEVEL + SV_OPENSEARCH_PARMNUM)
#Define SV_MAXWORKITEMS_INFOLEVEL           (PARMNUM_BASE_INFOLEVEL + SV_MAXWORKITEMS_PARMNUM)
#Define SV_MAXRAWBUFLEN_INFOLEVEL           (PARMNUM_BASE_INFOLEVEL + SV_MAXRAWBUFLEN_PARMNUM)
#Define SV_SESSUSERS_INFOLEVEL              (PARMNUM_BASE_INFOLEVEL + SV_SESSUSERS_PARMNUM)
#Define SV_SESSCONNS_INFOLEVEL              (PARMNUM_BASE_INFOLEVEL + SV_SESSCONNS_PARMNUM)
#Define SV_MAXNONPAGEDMEMORYUSAGE_INFOLEVEL (PARMNUM_BASE_INFOLEVEL + SV_MAXNONPAGEDMEMORYUSAGE_PARMNUM)
#Define SV_MAXPAGEDMEMORYUSAGE_INFOLEVEL    (PARMNUM_BASE_INFOLEVEL + SV_MAXPAGEDMEMORYUSAGE_PARMNUM)
#Define SV_ENABLESOFTCOMPAT_INFOLEVEL       (PARMNUM_BASE_INFOLEVEL + SV_ENABLESOFTCOMPAT_PARMNUM)
#Define SV_ENABLEFORCEDLOGOFF_INFOLEVEL     (PARMNUM_BASE_INFOLEVEL + SV_ENABLEFORCEDLOGOFF_PARMNUM)
#Define SV_TIMESOURCE_INFOLEVEL             (PARMNUM_BASE_INFOLEVEL + SV_TIMESOURCE_PARMNUM)
#Define SV_LMANNOUNCE_INFOLEVEL             (PARMNUM_BASE_INFOLEVEL + SV_LMANNOUNCE_PARMNUM)
#Define SV_MAXCOPYREADLEN_INFOLEVEL         (PARMNUM_BASE_INFOLEVEL + SV_MAXCOPYREADLEN_PARMNUM)
#Define SV_MAXCOPYWRITELEN_INFOLEVEL        (PARMNUM_BASE_INFOLEVEL + SV_MAXCOPYWRITELEN_PARMNUM)
#Define SV_MINKEEPSEARCH_INFOLEVEL          (PARMNUM_BASE_INFOLEVEL + SV_MINKEEPSEARCH_PARMNUM)
#Define SV_MAXKEEPSEARCH_INFOLEVEL          (PARMNUM_BASE_INFOLEVEL + SV_MAXKEEPSEARCH_PARMNUM)
#Define SV_MINKEEPCOMPLSEARCH_INFOLEVEL     (PARMNUM_BASE_INFOLEVEL + SV_MINKEEPCOMPLSEARCH_PARMNUM)
#Define SV_MAXKEEPCOMPLSEARCH_INFOLEVEL     (PARMNUM_BASE_INFOLEVEL + SV_MAXKEEPCOMPLSEARCH_PARMNUM)
#Define SV_SCAVTIMEOUT_INFOLEVEL            (PARMNUM_BASE_INFOLEVEL + SV_SCAVTIMEOUT_PARMNUM)
#Define SV_MINRCVQUEUE_INFOLEVEL            (PARMNUM_BASE_INFOLEVEL + SV_MINRCVQUEUE_PARMNUM)
#Define SV_MINFREEWORKITEMS_INFOLEVEL       (PARMNUM_BASE_INFOLEVEL + SV_MINFREEWORKITEMS_PARMNUM)
#Define SV_MAXMPXCT_INFOLEVEL               (PARMNUM_BASE_INFOLEVEL + SV_MAXMPXCT_PARMNUM)
#Define SV_OPLOCKBREAKWAIT_INFOLEVEL        (PARMNUM_BASE_INFOLEVEL + SV_OPLOCKBREAKWAIT_PARMNUM)
#Define SV_OPLOCKBREAKRESPONSEWAIT_INFOLEVEL (PARMNUM_BASE_INFOLEVEL + SV_OPLOCKBREAKRESPONSEWAIT_PARMNUM)
#Define SV_ENABLEOPLOCKS_INFOLEVEL          (PARMNUM_BASE_INFOLEVEL + SV_ENABLEOPLOCKS_PARMNUM)
#Define SV_ENABLEOPLOCKFORCECLOSE_INFOLEVEL (PARMNUM_BASE_INFOLEVEL + SV_ENABLEOPLOCKFORCECLOSE_PARMNUM)
#Define SV_ENABLEFCBOPENS_INFOLEVEL         (PARMNUM_BASE_INFOLEVEL + SV_ENABLEFCBOPENS_PARMNUM)
#Define SV_ENABLERAW_INFOLEVEL              (PARMNUM_BASE_INFOLEVEL + SV_ENABLERAW_PARMNUM)
#Define SV_ENABLESHAREDNETDRIVES_INFOLEVEL  (PARMNUM_BASE_INFOLEVEL + SV_ENABLESHAREDNETDRIVES_PARMNUM)
#Define SV_MINFREECONNECTIONS_INFOLEVEL     (PARMNUM_BASE_INFOLEVEL + SV_MINFREECONNECTIONS_PARMNUM)
#Define SV_MAXFREECONNECTIONS_INFOLEVEL     (PARMNUM_BASE_INFOLEVEL + SV_MAXFREECONNECTIONS_PARMNUM)
#Define SV_INITSESSTABLE_INFOLEVEL          (PARMNUM_BASE_INFOLEVEL + SV_INITSESSTABLE_PARMNUM)
#Define SV_INITCONNTABLE_INFOLEVEL          (PARMNUM_BASE_INFOLEVEL + SV_INITCONNTABLE_PARMNUM)
#Define SV_INITFILETABLE_INFOLEVEL          (PARMNUM_BASE_INFOLEVEL + SV_INITFILETABLE_PARMNUM)
#Define SV_INITSEARCHTABLE_INFOLEVEL        (PARMNUM_BASE_INFOLEVEL + SV_INITSEARCHTABLE_PARMNUM)
#Define SV_ALERTSCHEDULE_INFOLEVEL          (PARMNUM_BASE_INFOLEVEL + SV_ALERTSCHEDULE_PARMNUM)
#Define SV_ERRORTHRESHOLD_INFOLEVEL         (PARMNUM_BASE_INFOLEVEL + SV_ERRORTHRESHOLD_PARMNUM)
#Define SV_NETWORKERRORTHRESHOLD_INFOLEVEL  (PARMNUM_BASE_INFOLEVEL + SV_NETWORKERRORTHRESHOLD_PARMNUM)
#Define SV_DISKSPACETHRESHOLD_INFOLEVEL     (PARMNUM_BASE_INFOLEVEL + SV_DISKSPACETHRESHOLD_PARMNUM)
#Define SV_MAXLINKDELAY_INFOLEVEL           (PARMNUM_BASE_INFOLEVEL + SV_MAXLINKDELAY_PARMNUM)
#Define SV_MINLINKTHROUGHPUT_INFOLEVEL      (PARMNUM_BASE_INFOLEVEL + SV_MINLINKTHROUGHPUT_PARMNUM)
#Define SV_LINKINFOVALIDTIME_INFOLEVEL      (PARMNUM_BASE_INFOLEVEL + SV_LINKINFOVALIDTIME_PARMNUM)
#Define SV_SCAVQOSINFOUPDATETIME_INFOLEVEL  (PARMNUM_BASE_INFOLEVEL + SV_SCAVQOSINFOUPDATETIME_PARMNUM)
#Define SV_MAXWORKITEMIDLETIME_INFOLEVEL    (PARMNUM_BASE_INFOLEVEL + SV_MAXWORKITEMIDLETIME_PARMNUM)
#Define SV_MAXRAWWORKITEMS_INFOLOEVEL       (PARMNUM_BASE_INFOLEVEL + SV_MAXRAWWORKITEMS_PARMNUM)
#Define SV_PRODUCTTYPE_INFOLOEVEL           (PARMNUM_BASE_INFOLEVEL + SV_PRODUCTTYPE_PARMNUM)
#Define SV_SERVERSIZE_INFOLOEVEL            (PARMNUM_BASE_INFOLEVEL + SV_SERVERSIZE_PARMNUM)
#Define SV_CONNECTIONLESSAUTODISC_INFOLOEVEL (PARMNUM_BASE_INFOLEVEL + SV_CONNECTIONLESSAUTODISC_PARMNUM)
#Define SV_SHARINGVIOLATIONRETRIES_INFOLOEVEL (PARMNUM_BASE_INFOLEVEL + SV_SHARINGVIOLATIONRETRIES_PARMNUM)
#Define SV_SHARINGVIOLATIONDELAY_INFOLOEVEL (PARMNUM_BASE_INFOLEVEL + SV_SHARINGVIOLATIONDELAY_PARMNUM)
#Define SV_MAXGLOBALOPENSEARCH_INFOLOEVEL   (PARMNUM_BASE_INFOLEVEL + SV_MAXGLOBALOPENSEARCH_PARMNUM)
#Define SV_REMOVEDUPLICATESEARCHES_INFOLOEVEL (PARMNUM_BASE_INFOLEVEL + SV_REMOVEDUPLICATESEARCHES_PARMNUM)
#Define SV_LOCKVIOLATIONRETRIES_INFOLOEVEL  (PARMNUM_BASE_INFOLEVEL + SV_LOCKVIOLATIONRETRIES_PARMNUM)
#Define SV_LOCKVIOLATIONOFFSET_INFOLOEVEL   (PARMNUM_BASE_INFOLEVEL + SV_LOCKVIOLATIONOFFSET_PARMNUM)
#Define SV_LOCKVIOLATIONDELAY_INFOLOEVEL    (PARMNUM_BASE_INFOLEVEL + SV_LOCKVIOLATIONDELAY_PARMNUM)
#Define SV_MDLREADSWITCHOVER_INFOLOEVEL     (PARMNUM_BASE_INFOLEVEL + SV_MDLREADSWITCHOVER_PARMNUM)
#Define SV_CACHEDOPENLIMIT_INFOLOEVEL       (PARMNUM_BASE_INFOLEVEL + SV_CACHEDOPENLIMIT_PARMNUM)
#Define SV_CRITICALTHREADS_INFOLOEVEL       (PARMNUM_BASE_INFOLEVEL + SV_CRITICALTHREADS_PARMNUM)
#Define SV_RESTRICTNULLSESSACCESS_INFOLOEVEL (PARMNUM_BASE_INFOLEVEL + SV_RESTRICTNULLSESSACCESS_PARMNUM)
#Define SV_ENABLEWFW311DIRECTIPX_INFOLOEVEL (PARMNUM_BASE_INFOLEVEL + SV_ENABLEWFW311DIRECTIPX_PARMNUM)
#Define SV_OTHERQUEUEAFFINITY_INFOLEVEL     (PARMNUM_BASE_INFOLEVEL + SV_OTHERQUEUEAFFINITY_PARMNUM)
#Define SV_QUEUESAMPLESECS_INFOLEVEL        (PARMNUM_BASE_INFOLEVEL + SV_QUEUESAMPLESECS_PARMNUM)
#Define SV_BALANCECOUNT_INFOLEVEL           (PARMNUM_BASE_INFOLEVEL + SV_BALANCECOUNT_PARMNUM)
#Define SV_PREFERREDAFFINITY_INFOLEVEL      (PARMNUM_BASE_INFOLEVEL + SV_PREFERREDAFFINITY_PARMNUM)
#Define SV_MAXFREERFCBS_INFOLEVEL           (PARMNUM_BASE_INFOLEVEL + SV_MAXFREERFCBS_PARMNUM)
#Define SV_MAXFREEMFCBS_INFOLEVEL           (PARMNUM_BASE_INFOLEVEL + SV_MAXFREEMFCBS_PARMNUM)
#Define SV_MAXFREELFCBS_INFOLEVEL           (PARMNUM_BASE_INFOLEVEL + SV_MAXFREELFCBS_PARMNUM)
#Define SV_MAXFREEPAGEDPOOLCHUNKS_INFOLEVEL (PARMNUM_BASE_INFOLEVEL + SV_MAXFREEPAGEDPOOLCHUNKS_PARMNUM)
#Define SV_MINPAGEDPOOLCHUNKSIZE_INFOLEVEL  (PARMNUM_BASE_INFOLEVEL + SV_MINPAGEDPOOLCHUNKSIZE_PARMNUM)
#Define SV_MAXPAGEDPOOLCHUNKSIZE_INFOLEVEL  (PARMNUM_BASE_INFOLEVEL + SV_MAXPAGEDPOOLCHUNKSIZE_PARMNUM)
#Define SV_SENDSFROMPREFERREDPROCESSOR_INFOLEVEL (PARMNUM_BASE_INFOLEVEL + SV_SENDSFROMPREFERREDPROCESSOR_PARMNUM)
#Define SV_MAXTHREADSPERQUEUE_INFOLEVEL     (PARMNUM_BASE_INFOLEVEL + SV_MAXTHREADSPERQUEUE_PARMNUM)
#Define SV_CACHEDDIRECTORYLIMIT_INFOLEVEL   (PARMNUM_BASE_INFOLEVEL + SV_CACHEDDIRECTORYLIMIT_PARMNUM)
#Define SV_MAXCOPYLENGTH_INFOLEVEL          (PARMNUM_BASE_INFOLEVEL + SV_MAXCOPYLENGTH_PARMNUM)
#Define SV_ENABLEBULKTRANSFER_INFOLEVEL     (PARMNUM_BASE_INFOLEVEL + SV_ENABLEBULKTRANSFER_PARMNUM)
#Define SV_ENABLECOMPRESSION_INFOLEVEL      (PARMNUM_BASE_INFOLEVEL + SV_ENABLECOMPRESSION_PARMNUM)
#Define SV_AUTOSHAREWKS_INFOLEVEL           (PARMNUM_BASE_INFOLEVEL + SV_AUTOSHAREWKS_PARMNUM)
#Define SV_AUTOSHARESERVER_INFOLEVEL        (PARMNUM_BASE_INFOLEVEL + SV_AUTOSHARESERVER_PARMNUM)
#Define SV_ENABLESECURITYSIGNATURE_INFOLEVEL (PARMNUM_BASE_INFOLEVEL + SV_ENABLESECURITYSIGNATURE_PARMNUM)
#Define SV_REQUIRESECURITYSIGNATURE_INFOLEVEL (PARMNUM_BASE_INFOLEVEL + SV_REQUIRESECURITYSIGNATURE_PARMNUM)
#Define SV_MINCLIENTBUFFERSIZE_INFOLEVEL    (PARMNUM_BASE_INFOLEVEL + SV_MINCLIENTBUFFERSIZE_PARMNUM)
#Define SV_CONNECTIONNOSESSIONSTIMEOUT_INFOLEVEL (PARMNUM_BASE_INFOLEVEL + SV_CONNECTIONNOSESSIONSTIMEOUT_PARMNUM)

#Define SVI1_NUM_ELEMENTS                   5
#Define SVI2_NUM_ELEMENTS                   40
#Define SVI3_NUM_ELEMENTS                   44

#Define SV_MAX_CMD_LEN                      PATHLEN

#Define SW_AUTOPROF_LOAD_MASK               01H
#Define SW_AUTOPROF_SAVE_MASK               02H

#Define SV_MAX_SRV_HEUR_LEN                 32

#Define SV_USERS_PER_LICENSE                5

#Define SVTI2_REMAP_PIPE_NAMES              02H

#ENDIF ;LMSERVER_INC

