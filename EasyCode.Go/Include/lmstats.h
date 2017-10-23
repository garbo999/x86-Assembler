#ifndef LMSTATS_H
#define LMSTATS_H

/* NetStatistics API definitions */

#IFNDEF LMCONS_H
	#include lmcons.h
#ENDIF

#define STATSOPT_CLR  1
#define STATS_NO_VALUE  -1
#define STATS_OVERFLOW  -2

STAT_SERVER_0 STRUCT
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
ENDS

#ifdef LM20_WORKSTATION_STATISTICS
	STAT_WORKSTATION_0 STRUCT
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
	ENDS
#else
	STAT_WORKSTATION_0 STRUCT
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
		#IF WINVER >= NTDDI_VISTA
		RawReadsDenied DD
		RawWritesDenied DD
		#ELSE
		unsupported DQ
		#ENDIF
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
	ENDS
#endif

#endif /* _LMSTATS_H */
