;=============================================================;
;          lmstats.inc file for Easy Code visual IDE          ;
;            (made for the GoAsm compiler version)            ;
;                                                             ;
;           Version 1.0.00 (created on March, 2008)           ;
;                                                             ;
;      Please report any bug you find (asm@easycode.cat)      ;
;                                                             ;
;                Do not modify this file!!                    ;
;=============================================================;

#IFNDEF LMSTATS_INC
#Define LMSTATS_INC

#IFDEF LM20_WORKSTATION_STATISTICS
	STAT_WORKSTATION_0 Struct
		stw0_start DD
		stw0_numNCB_r DD
		stw0_numNCB_s DD
		stw0_numNCB_a DD
		stw0_fiNCB_r DD
		stw0_fiNCB_s DD
		stw0_fiNCB_a DD
		stw0_fcNCB_r DD
		stw0_fcNCB_s DD
		stw0_fcNCB_a DD
		stw0_sesstart DD
		stw0_sessfailcon DD
		stw0_sessbroke DD
		stw0_uses DD
		stw0_usefail DD
		stw0_autorec DD
		stw0_bytessent_r_lo DD
		stw0_bytessent_r_hi DD
		stw0_bytesrcvd_r_lo DD
		stw0_bytesrcvd_r_hi DD
		stw0_bytessent_s_lo DD
		stw0_bytessent_s_hi DD
		stw0_bytesrcvd_s_lo DD
		stw0_bytesrcvd_s_hi DD
		stw0_bytessent_a_lo DD
		stw0_bytessent_a_hi DD
		stw0_bytesrcvd_a_lo DD
		stw0_bytesrcvd_a_hi DD
		stw0_reqbufneed DD
		stw0_bigbufneed DD
	EndS
#ELSE
	STAT_WORKSTATION_0 Struct
		StatisticsStartTime DQ
		BytesReceived DQ
		SmbsReceived DQ
		PagingReadBytesRequested DQ
		NonPagingReadBytesRequested DQ
		CacheReadBytesRequested DQ
		NetworkReadBytesRequested DQ
		BytesTransmitted DQ
		SmbsTransmitted DQ
		PagingWriteBytesRequested DQ
		NonPagingWriteBytesRequested DQ
		CacheWriteBytesRequested DQ
		NetworkWriteBytesRequested DQ
		InitiallyFailedOperations DD
		FailedCompletionOperations DD
		ReadOperations DD
		RandomReadOperations DD
		ReadSmbs DD
		LargeReadSmbs DD
		SmallReadSmbs DD
		WriteOperations DD
		RandomWriteOperations DD
		WriteSmbs DD
		LargeWriteSmbs DD
		SmallWriteSmbs DD
		RawReadsDenied DD
		RawWritesDenied DD
		NetworkErrors DD
		Sessions DD
		FailedSessions DD
		Reconnects DD
		CoreConnects DD
		Lanman20Connects DD
		Lanman21Connects DD
		LanmanNtConnects DD
		ServerDisconnects DD
		HungSessions DD
		UseCount DD
		FailedUseCount DD
		CurrentCommands DD
	EndS
#ENDIF

STAT_SERVER_0 Struct
	sts0_start DD
	sts0_fopens DD
	sts0_devopens DD
	sts0_jobsqueued DD
	sts0_sopens DD
	sts0_stimedout DD
	sts0_serrorout DD
	sts0_pwerrors DD
	sts0_permerrors DD
	sts0_syserrors DD
	sts0_bytessent_low DD
	sts0_bytessent_high DD
	sts0_bytesrcvd_low DD
	sts0_bytesrcvd_high DD
	sts0_avresponse DD
	sts0_reqbufneed DD
	sts0_bigbufneed DD
EndS

#Define STATSOPT_CLR                        1
#Define STATS_NO_VALUE                      (-1)
#Define STATS_OVERFLOW                      (-2)

#ENDIF ;LMSTATS_INC
