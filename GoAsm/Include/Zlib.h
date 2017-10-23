#IFNDEF ZLIB_H
#DEFINE ZLIB_H

#IFNDEF WIN64 // No WIN64 support !!!

#IFNDEF ZLibStat
	ZLibStat = zlibstat.lib
#ENDIF

; zlibstat.lib
; ~~~~~~~~~~~~~~~~~~~~~~~
adler32 = ZLibStat:adler32
compress = ZLibStat:compress
compress2 = ZLibStat:compress2
crc32 = ZLibStat:crc32
deflate = ZLibStat:deflate
deflateCopy = ZLibStat:deflateCopy
deflateEnd = ZLibStat:deflateEnd
deflateInit2 = ZLibStat:deflateInit2
deflateInit_ = ZLibStat:deflateInit_
deflateParams = ZLibStat:deflateParams
deflateReset = ZLibStat:deflateReset
deflateSetDictionary = ZLibStat:deflateSetDictionary
fclose_file_func = ZLibStat:fclose_file_func
ferror_file_func = ZLibStat:ferror_file_func
fopen_file_func = ZLibStat:fopen_file_func
fread_file_func = ZLibStat:fread_file_func
fseek_file_func = ZLibStat:fseek_file_func
ftell_file_func = ZLibStat:ftell_file_func
fwrite_file_func = ZLibStat:fwrite_file_func
get_crc_table = ZLibStat:get_crc_table

; WARNING!!!
; Gz functions supported but in order to use them you should link with  C runtime libraries

#IFDEF LINKFILES
	#dynamiclinkfile msvcrt.dll
#ENDIF

gzclose = ZLibStat:gzclose
gzdopen = ZLibStat:gzdopen
gzeof = ZLibStat:gzeof
gzerror = ZLibStat:gzerror
gzflush = ZLibStat:gzflush
gzgetc = ZLibStat:gzgetc
gzgets = ZLibStat:gzgets
gzopen = ZLibStat:gzopen
gzputc = ZLibStat:gzputc
gzputs = ZLibStat:gzputs
gzread = ZLibStat:gzread
gzrewind  = ZLibStat:gzrewind
gzseek = ZLibStat:gzseek
gzsetparams = ZLibStat:gzsetparams
gztell = ZLibStat:gztell
gzwrite = ZLibStat:gzwrite

inflate = ZLibStat:inflate
inflateEnd = ZLibStat:inflateEnd
inflateInit2_ = ZLibStat:inflateInit2_
inflateInit_ = ZLibStat:inflateInit_
inflateReset = ZLibStat:inflateReset
inflateSetDictionary = ZLibStat:inflateSetDictionary
inflateSync = ZLibStat:inflateSync
inflateSyncPoint = ZLibStat:inflateSyncPoint
uncompress = ZLibStat:uncompress
unzClose = ZLibStat:unzClose
unzCloseCurrentFile = ZLibStat:unzCloseCurrentFile
unzGetCurrentFileInfo = ZLibStat:unzGetCurrentFileInfo
unzGetGlobalComment = ZLibStat:unzGetGlobalComment
unzGetGlobalInfo = ZLibStat:unzGetGlobalInfo
unzGetLocalExtrafield = ZLibStat:unzGetLocalExtrafield
unzGoToFirstFile = ZLibStat:unzGoToFirstFile
unzGoToNextFile = ZLibStat:unzGoToNextFile
unzLocateFile = ZLibStat:unzLocateFile
unzOpen = ZLibStat:unzOpen
unzOpen2 = ZLibStat:unzOpen2
unzOpenCurrentFile = ZLibStat:unzOpenCurrentFile
unzOpenCurrentFile2 = ZLibStat:unzOpenCurrentFile2
unzReadCurrentFile = ZLibStat:unzReadCurrentFile
unzStringFileNameCompare = ZLibStat:unzStringFileNameCompare
unzeof = ZLibStat:unzeof
unztell = ZLibStat:unztell
zError = ZLibStat:zError
zipClose = ZLibStat:zipClose
zipCloseFileInZip = ZLibStat:zipCloseFileInZip
zipCloseFileInZipRaw = ZLibStat:zipCloseFileInZipRaw
zipOpen = ZLibStat:zipOpen
zipOpen2 = ZLibStat:zipOpen2
zipOpenNewFileInZip = ZLibStat:zipOpenNewFileInZip
zipOpenNewFileInZip2 = ZLibStat:zipOpenNewFileInZip2
zipWriteInFileInZip = ZLibStat:zipWriteInFileInZip
zlibVersion = ZLibStat:zlibVersion

;--------------------Structures-----------------------------
;internal_state		STRUCT 
;dummy		DWORD
;internal_state		ENDS

zlib_filefunc_def STRUCT 
	zopen_file		DD
	zread_file		DD
	zwrite_file		DD
	ztell_file		DD
	zseek_file		DD
	zclose_file		DD
	zerror_file		DD
	opaque			DD
ENDS

linkedlist_datablock_internal STRUCT
	next_datablock			DD ;PTR linkedlist_datablock_internal
	avail_in_this_block		DD
	filled_in_this_block	DD
	unused					DD
	data					DB	4080 DUP
ENDS

linkedlist_data STRUCT 
	first_block		DD ;linkedlist_datablock_internal
	last_block		DD ;linkedlist_datablock_internal
ENDS

z_stream STRUCT
	next_in		DD
	avail_in	DD
	total_in	DD
	next_out	DD
	avail_out	DD
	total_out	DD
	msg			DD
	state		DD
	zalloc		DD
	zfree		DD
	opaque		DD
	data_type	DD
	adler		DD
	reserved	DD
ENDS

curfile_info STRUCT
	stream					z_stream
	stream_initialised		DD
	pos_in_buffered_data	DD
	pos_local_header		DD
	central_header			DD
	size_centralheader		DD
	flag					DD
	method					DD
	raw						DD
	buffered_data			DB		16384 DUP
	dosDate					DD
	crc32					DD
ENDS

zip_internal STRUCT
	z_filefunc				zlib_filefunc_def
	filestream				DD
	central_dir				linkedlist_data
	in_opened_file_inzip	DD
	ci						curfile_info
	begin_pos				DD
	number_entry			DD
ENDS

tm_zip STRUCT
	tm_sec	DD
	tm_min	DD
	tm_hour	DD
	tm_mday	DD
	tm_mon	DD
	tm_year	DD
ENDS

zip_fileinfo Struct
	tmz_date	tm_zip
	dosDate		DD
	iflag		DD
	eflag		DD
ENDS

;-----------------Unzip Structures-----------------------------
tm_unz STRUCT
	tm_sec		DD
	tm_min		DD
	tm_hour		DD
	tm_mday		DD
	tm_mon		DD
	tm_year		DD
ENDS

unz_global_info STRUCT
	number_entry		DD
	size_comment		DD
ENDS

unz_file_info STRUCT
	version				DD
	version_needed		DD
	flag				DD
	compression_method	DD
	dosDate				DD
	crc					DD
	compressed_size		DD
	uncompressed_size	DD
	size_filename		DD
	size_file_extra		DD
	size_file_comment	DD
	disk_num_start		DD
	internal_fa			DD
	external_fa			DD
	tmu_date			tm_unz
ENDS

unz_file_info_internal STRUCT
	offset_curfile		DD
ENDS

file_in_zip_read_info STRUCT
	read_buffer					DD
	stream						z_stream
	pos_in_zipfile				DD
	stream_initialised			DD
	offset_local_extrafield		DD
	size_local_extrafield		DD
	pos_local_extrafield		DD
	crc32						DD
	crc32_wait					DD
	rest_read_compressed		DD
	rest_read_uncompressed		DD
	z_filefunc					zlib_filefunc_def
	filestream					DD
	compression_method			DD
	byte_before_the_zipfile		DD
	raw							DD
ENDS

unz_s STRUCT
	z_filefunc					zlib_filefunc_def
	filestream					DD
	gi							unz_global_info
	byte_before_the_zipfile		DD
	num_file					DD
	pos_in_central_dir			DD
	current_file_ok				DD
	central_pos					DD
	size_central_dir			DD
	offset_central_dir			DD
	cur_file_info				unz_file_info
	cur_file_info_internal		unz_file_info_internal
	pfile_in_zip_read			DD
ENDS

;----------------------------------EQU----------------------------
ZIP_OK					EQU		000000000h
ZIP_ERRNO				EQU		0ffffffffh
ZIP_PARAMERROR			EQU		0ffffff9ah
ZIP_INTERNALERROR		EQU		0ffffff98h
;----------------------------------------------------------------
UNZ_OK					EQU		000000000h
UNZ_END_OF_LIST_OF_FILE	EQU		0ffffff9ch
UNZ_ERRNO				EQU		0ffffffffh
UNZ_EOF					EQU		000000000h
UNZ_PARAMERROR			EQU		0ffffff9ah
UNZ_BADZIPFILE			EQU		0ffffff99h
UNZ_INTERNALERROR		EQU		0ffffff98h
UNZ_CRCERROR			EQU		0ffffff97h
;----------------------------------------------------------------
Z_NO_FLUSH				EQU		0
Z_PARTIAL_FLUSH			EQU		1
Z_SYNC_FLUSH			EQU		2
Z_FULL_FLUSH			EQU		3
Z_FINISH				EQU		4
Z_OK					EQU		0
Z_STREAM_END			EQU		1
Z_NEED_DICT				EQU		2
Z_ERRNO					EQU		0ffffffffh
Z_STREAM_ERROR			EQU		0fffffffeh
Z_DATA_ERROR			EQU		0fffffffdh
Z_MEM_ERROR				EQU		0fffffffch
Z_BUF_ERROR				EQU		0fffffffbh
Z_VERSION_ERROR			EQU		0fffffffah
Z_NO_COMPRESSION		EQU		0
Z_BEST_SPEED			EQU		1
Z_BEST_COMPRESSION		EQU		9
Z_DEFAULT_COMPRESSION	EQU		0ffffffffh
Z_FILTERED				EQU		1
Z_HUFFMAN_ONLY			EQU		2
Z_DEFAULT_STRATEGY		EQU		0
Z_BINARY				EQU		0
Z_ASCII					EQU		1
Z_UNKNOWN				EQU		2
Z_DEFLATED				EQU		8
Z_NULL					EQU		0
;-------------------------------------------------------------------
ZLIB_FILEFUNC_SEEK_CUR				EQU		000000001h
ZLIB_FILEFUNC_SEEK_END				EQU		000000002h
ZLIB_FILEFUNC_SEEK_SET				EQU		000000000h
ZLIB_FILEFUNC_MODE_READ				EQU		000000001h
ZLIB_FILEFUNC_MODE_WRITE			EQU		000000002h
ZLIB_FILEFUNC_MODE_READWRITEFILTER	EQU		000000003h
ZLIB_FILEFUNC_MODE_EXISTING			EQU		000000004h
ZLIB_FILEFUNC_MODE_CREATE			EQU		000000008h

#ENDIF // !WIN64
#ENDIF // ZLIBSTAT_H