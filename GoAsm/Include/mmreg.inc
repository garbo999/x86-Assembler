;=============================================================;
;           mmreg.inc file for Easy Code visual IDE           ;
;            (made for the GoAsm compiler version)            ;
;                                                             ;
;           Version 1.0.00 (created on March, 2008)           ;
;                                                             ;
;      Please report any bug you find (asm@easycode.cat)      ;
;                                                             ;
;                Do not modify this file!!                    ;
;=============================================================;

#IFNDEF MMREG_INC
#Define MMREG_INC

#IFNDEF MM_MICROSOFT
	#Define MM_MICROSOFT                    1
#ENDIF

#Define MM_CREATIVE                         2
#Define MM_MEDIAVISION                      3
#Define MM_FUJITSU                          4
#Define MM_ARTISOFT                         20
#Define MM_TURTLE_BEACH                     21
#Define MM_IBM                              22
#Define MM_VOCALTEC                         23
#Define MM_ROLAND                           24
#Define MM_DSP_SOLUTIONS                    25
#Define MM_NEC                              26
#Define MM_ATI                              27
#Define MM_WANGLABS                         28
#Define MM_TANDY                            29
#Define MM_VOYETRA                          30
#Define MM_ANTEX                            31
#Define MM_ICL_PS                           32
#Define MM_INTEL                            33
#Define MM_GRAVIS                           34
#Define MM_VAL                              35
#Define MM_INTERACTIVE                      36
#Define MM_YAMAHA                           37
#Define MM_EVEREX                           38
#Define MM_ECHO                             39
#Define MM_SIERRA                           40
#Define MM_CAT                              41
#Define MM_APPS                             42
#Define MM_DSP_GROUP                        43
#Define MM_MELABS                           44
#Define MM_COMPUTER_FRIENDS                 45
#Define MM_ESS                              46
#Define MM_AUDIOFILE                        47
#Define MM_MOTOROLA                         48
#Define MM_CANOPUS                          49
#Define MM_EPSON                            50
#Define MM_TRUEVISION                       51
#Define MM_AZTECH                           52
#Define MM_VIDEOLOGIC                       53
#Define MM_SCALACS                          54
#Define MM_KORG                             55
#Define MM_APT                              56
#Define MM_ICS                              57
#Define MM_ITERATEDSYS                      58
#Define MM_METHEUS                          59
#Define MM_LOGITECH                         60
#Define MM_WINNOV                           61
#Define MM_NCR                              62
#Define MM_EXAN                             63
#Define MM_AST                              64
#Define MM_WILLOWPOND                       65
#Define MM_SONICFOUNDRY                     66
#Define MM_VITEC                            67
#Define MM_MOSCOM                           68
#Define MM_SILICONSOFT                      69
#Define MM_SUPERMAC                         73
#Define MM_AUDIOPT                          74
#Define MM_SPEECHCOMP                       76
#Define MM_AHEAD                            77
#Define MM_DOLBY                            78
#Define MM_OKI                              79
#Define MM_AURAVISION                       80
#Define MM_OLIVETTI                         81
#Define MM_IOMAGIC                          82
#Define MM_MATSUSHITA                       83
#Define MM_CONTROLRES                       84
#Define MM_XEBEC                            85
#Define MM_NEWMEDIA                         86
#Define MM_NMS                              87
#Define MM_LYRRUS                           88
#Define MM_COMPUSIC                         89
#Define MM_OPTI                             90
#Define MM_ADLACC                           91
#Define MM_COMPAQ                           92
#Define MM_DIALOGIC                         93
#Define MM_INSOFT                           94
#Define MM_MPTUS                            95
#Define MM_WEITEK                           96
#Define MM_LERNOUT_AND_HAUSPIE              97
#Define MM_QCIAR                            98
#Define MM_APPLE                            99
#Define MM_DIGITAL                          100
#Define MM_MOTU                             101
#Define MM_WORKBIT                          102
#Define MM_OSITECH                          103
#Define MM_MIRO                             104
#Define MM_CIRRUSLOGIC                      105
#Define MM_ISOLUTION                        106
#Define MM_HORIZONS                         107
#Define MM_CONCEPTS                         108
#Define MM_VTG                              109
#Define MM_RADIUS                           110
#Define MM_ROCKWELL                         111
#Define MM_XYz                              112
#Define MM_OPCODE                           113
#Define MM_VOXWARE                          114
#Define MM_NORTHERN_TELECOM                 115
#Define MM_APICOM                           116
#Define MM_GRANDE                           117
#Define MM_ADDX                             118
#Define MM_WILDCAT                          119
#Define MM_RHETOREX                         120
#Define MM_BROOKTREE                        121
#Define MM_ENSONIQ                          125
#Define MM_FAST                             126
#Define MM_NVIDIA                           127
#Define MM_OKSORI                           128
#Define MM_DIACOUSTICS                      129
#Define MM_GULBRANSEN                       130
#Define MM_KAY_ELEMETRICS                   131
#Define MM_CRYSTAL                          132
#Define MM_SPLASH_STUDIOS                   133
#Define MM_QUARTERDECK                      134
#Define MM_TDK                              135
#Define MM_DIGITAL_AUDIO_LABS               136
#Define MM_SEERSYS                          137
#Define MM_PICTURETEL                       138
#Define MM_ATT_MICROELECTRONICS             139
#Define MM_OSPREY                           140
#Define MM_MEDIATRIX                        141
#Define MM_SOUNDESIGNS                      142
#Define MM_ALDIGITAL                        143
#Define MM_SPECTRUM_SIGNAL_PROCESSING       144
#Define MM_ECS                              145
#Define MM_AMD                              146
#Define MM_COREDYNAMICS                     147
#Define MM_CANAM                            148
#Define MM_SOFTSOUND                        149
#Define MM_NORRIS                           150
#Define MM_DDD                              151
#Define MM_EUPHONICS                        152
#Define MM_PRECEPT                          153
#Define MM_CRYSTAL_NET                      154
#Define MM_CHROMATIC                        155
#Define MM_VOICEINFO                        156
#Define MM_VIENNASYS                        157
#Define MM_CONNECTIX                        158
#Define MM_GADGETLABS                       159
#Define MM_FRONTIER                         160
#Define MM_VIONA                            161
#Define MM_CASIO                            162
#Define MM_DIAMONDMM                        163
#Define MM_S3                               164
#Define MM_FRAUNHOFER_IIS                   172

#IFNDEF MM_MIDI_MAPPER
	#Define MM_MIDI_MAPPER                  1
	#Define MM_WAVE_MAPPER                  2
	#Define MM_SNDBLST_MIDIOUT              3
	#Define MM_SNDBLST_MIDIIN               4
	#Define MM_SNDBLST_SYNTH                5
	#Define MM_SNDBLST_WAVEOUT              6
	#Define MM_SNDBLST_WAVEIN               7
	#Define MM_ADLIB                        9
	#Define MM_MPU401_MIDIOUT               10
	#Define MM_MPU401_MIDIIN                11
	#Define MM_PC_JOYSTICK                  12
#ENDIF

#Define MM_PCSPEAKER_WAVEOUT                13
#Define MM_MSFT_WSS_WAVEIN                  14
#Define MM_MSFT_WSS_WAVEOUT                 15
#Define MM_MSFT_WSS_FMSYNTH_STEREO          16
#Define MM_MSFT_WSS_MIXER                   17
#Define MM_MSFT_WSS_OEM_WAVEIN              18
#Define MM_MSFT_WSS_OEM_WAVEOUT             19
#Define MM_MSFT_WSS_OEM_FMSYNTH_STEREO      20
#Define MM_MSFT_WSS_AUX                     21
#Define MM_MSFT_WSS_OEM_AUX                 22
#Define MM_MSFT_GENERIC_WAVEIN              23
#Define MM_MSFT_GENERIC_WAVEOUT             24
#Define MM_MSFT_GENERIC_MIDIIN              25
#Define MM_MSFT_GENERIC_MIDIOUT             26
#Define MM_MSFT_GENERIC_MIDISYNTH           27
#Define MM_MSFT_GENERIC_AUX_LINE            28
#Define MM_MSFT_GENERIC_AUX_MIC             29
#Define MM_MSFT_GENERIC_AUX_CD              30
#Define MM_MSFT_WSS_OEM_MIXER               31
#Define MM_MSFT_MSACM                       32
#Define MM_MSFT_ACM_MSADPCM                 33
#Define MM_MSFT_ACM_IMAADPCM                34
#Define MM_MSFT_ACM_MSFILTER                35
#Define MM_MSFT_ACM_GSM610                  36
#Define MM_MSFT_ACM_G711                    37
#Define MM_MSFT_ACM_PCM                     38

#Define MM_WSS_SB16_WAVEIN                  39
#Define MM_WSS_SB16_WAVEOUT                 40
#Define MM_WSS_SB16_MIDIIN                  41
#Define MM_WSS_SB16_MIDIOUT                 42
#Define MM_WSS_SB16_SYNTH                   43
#Define MM_WSS_SB16_AUX_LINE                44
#Define MM_WSS_SB16_AUX_CD                  45
#Define MM_WSS_SB16_MIXER                   46
#Define MM_WSS_SBPRO_WAVEIN                 47
#Define MM_WSS_SBPRO_WAVEOUT                48
#Define MM_WSS_SBPRO_MIDIIN                 49
#Define MM_WSS_SBPRO_MIDIOUT                50
#Define MM_WSS_SBPRO_SYNTH                  51
#Define MM_WSS_SBPRO_AUX_LINE               52
#Define MM_WSS_SBPRO_AUX_CD                 53
#Define MM_WSS_SBPRO_MIXER                  54

#Define MM_MSFT_WSS_NT_WAVEIN               55
#Define MM_MSFT_WSS_NT_WAVEOUT              56
#Define MM_MSFT_WSS_NT_FMSYNTH_STEREO       57
#Define MM_MSFT_WSS_NT_MIXER                58
#Define MM_MSFT_WSS_NT_AUX                  59

#Define MM_MSFT_SB16_WAVEIN                 60
#Define MM_MSFT_SB16_WAVEOUT                61
#define  MM_MSFT_SB16_MIDIIN                62
#Define MM_MSFT_SB16_MIDIOUT                63
#Define MM_MSFT_SB16_SYNTH                  64
#Define MM_MSFT_SB16_AUX_LINE               65
#Define MM_MSFT_SB16_AUX_CD                 66
#Define MM_MSFT_SB16_MIXER                  67
#Define MM_MSFT_SBPRO_WAVEIN                68
#Define MM_MSFT_SBPRO_WAVEOUT               69
#Define MM_MSFT_SBPRO_MIDIIN                70
#Define MM_MSFT_SBPRO_MIDIOUT               71
#Define MM_MSFT_SBPRO_SYNTH                 72
#Define MM_MSFT_SBPRO_AUX_LINE              73
#Define MM_MSFT_SBPRO_AUX_CD                74
#Define MM_MSFT_SBPRO_MIXER                 75

#Define MM_MSFT_MSOPL_SYNTH                 76

#Define MM_MSFT_VMDMS_LINE_WAVEIN           80
#Define MM_MSFT_VMDMS_LINE_WAVEOUT          81
#Define MM_MSFT_VMDMS_HANDSET_WAVEIN        82
#Define MM_MSFT_VMDMS_HANDSET_WAVEOUT       83
#Define MM_MSFT_VMDMW_LINE_WAVEIN           84
#Define MM_MSFT_VMDMW_LINE_WAVEOUT          85
#Define MM_MSFT_VMDMW_HANDSET_WAVEIN        86
#Define MM_MSFT_VMDMW_HANDSET_WAVEOUT       87
#Define MM_MSFT_VMDMW_MIXER                 88
#Define MM_MSFT_VMDM_GAME_WAVEOUT           89
#Define MM_MSFT_VMDM_GAME_WAVEIN            90

#Define MM_MSFT_ACM_MSNAUDIO                91
#Define MM_MSFT_ACM_MSG723                  92

#Define MM_MSFT_WDMAUDIO_WAVEOUT            100
#Define MM_MSFT_WDMAUDIO_WAVEIN             101
#Define MM_MSFT_WDMAUDIO_MIDIOUT            102
#Define MM_MSFT_WDMAUDIO_MIDIIN             103
#Define MM_MSFT_WDMAUDIO_MIXER              104


#Define MM_CREATIVE_SB15_WAVEIN             1
#Define MM_CREATIVE_SB20_WAVEIN             2
#Define MM_CREATIVE_SBPRO_WAVEIN            3
#Define MM_CREATIVE_SBP16_WAVEIN            4
#Define MM_CREATIVE_PHNBLST_WAVEIN          5
#Define MM_CREATIVE_SB15_WAVEOUT            101
#Define MM_CREATIVE_SB20_WAVEOUT            102
#Define MM_CREATIVE_SBPRO_WAVEOUT           103
#Define MM_CREATIVE_SBP16_WAVEOUT           104
#Define MM_CREATIVE_PHNBLST_WAVEOUT         105
#Define MM_CREATIVE_MIDIOUT                 201
#Define MM_CREATIVE_MIDIIN                  202
#Define MM_CREATIVE_FMSYNTH_MONO            301
#Define MM_CREATIVE_FMSYNTH_STEREO          302
#Define MM_CREATIVE_MIDI_AWE32              303
#Define MM_CREATIVE_AUX_CD                  401
#Define MM_CREATIVE_AUX_LINE                402
#Define MM_CREATIVE_AUX_MIC                 403
#Define MM_CREATIVE_AUX_MASTER              404
#Define MM_CREATIVE_AUX_PCSPK               405
#Define MM_CREATIVE_AUX_WAVE                406
#Define MM_CREATIVE_AUX_MIDI                407
#Define MM_CREATIVE_SBPRO_MIXER             408
#Define MM_CREATIVE_SB16_MIXER              409

#Define MM_MEDIAVISION_PROAUDIO             010H
#Define MM_PROAUD_MIDIOUT                   (MM_MEDIAVISION_PROAUDIO + 1)
#Define MM_PROAUD_MIDIIN                    (MM_MEDIAVISION_PROAUDIO + 2)
#Define MM_PROAUD_SYNTH                     (MM_MEDIAVISION_PROAUDIO + 3)
#Define MM_PROAUD_WAVEOUT                   (MM_MEDIAVISION_PROAUDIO + 4)
#Define MM_PROAUD_WAVEIN                    (MM_MEDIAVISION_PROAUDIO + 5)
#Define MM_PROAUD_MIXER                     (MM_MEDIAVISION_PROAUDIO + 6)
#Define MM_PROAUD_AUX                       (MM_MEDIAVISION_PROAUDIO + 7)

#Define MM_MEDIAVISION_THUNDER              020H
#Define MM_THUNDER_SYNTH                    (MM_MEDIAVISION_THUNDER + 3)
#Define MM_THUNDER_WAVEOUT                  (MM_MEDIAVISION_THUNDER + 4)
#Define MM_THUNDER_WAVEIN                   (MM_MEDIAVISION_THUNDER + 5)
#Define MM_THUNDER_AUX                      (MM_MEDIAVISION_THUNDER + 7)

#Define MM_MEDIAVISION_TPORT                040H
#Define MM_TPORT_WAVEOUT                    (MM_MEDIAVISION_TPORT + 1)
#Define MM_TPORT_WAVEIN                     (MM_MEDIAVISION_TPORT + 2)
#Define MM_TPORT_SYNTH                      (MM_MEDIAVISION_TPORT + 3)

#Define MM_MEDIAVISION_PROAUDIO_PLUS        050H
#Define MM_PROAUD_PLUS_MIDIOUT              (MM_MEDIAVISION_PROAUDIO_PLUS + 1)
#Define MM_PROAUD_PLUS_MIDIIN               (MM_MEDIAVISION_PROAUDIO_PLUS + 2)
#Define MM_PROAUD_PLUS_SYNTH                (MM_MEDIAVISION_PROAUDIO_PLUS + 3)
#Define MM_PROAUD_PLUS_WAVEOUT              (MM_MEDIAVISION_PROAUDIO_PLUS + 4)
#Define MM_PROAUD_PLUS_WAVEIN               (MM_MEDIAVISION_PROAUDIO_PLUS + 5)
#Define MM_PROAUD_PLUS_MIXER                (MM_MEDIAVISION_PROAUDIO_PLUS + 6)
#Define MM_PROAUD_PLUS_AUX                  (MM_MEDIAVISION_PROAUDIO_PLUS + 7)

#Define MM_MEDIAVISION_PROAUDIO_16          060H
#Define MM_PROAUD_16_MIDIOUT                (MM_MEDIAVISION_PROAUDIO_16 + 1)
#Define MM_PROAUD_16_MIDIIN                 (MM_MEDIAVISION_PROAUDIO_16 + 2)
#Define MM_PROAUD_16_SYNTH                  (MM_MEDIAVISION_PROAUDIO_16 + 3)
#Define MM_PROAUD_16_WAVEOUT                (MM_MEDIAVISION_PROAUDIO_16 + 4)
#Define MM_PROAUD_16_WAVEIN                 (MM_MEDIAVISION_PROAUDIO_16 + 5)
#Define MM_PROAUD_16_MIXER                  (MM_MEDIAVISION_PROAUDIO_16 + 6)
#Define MM_PROAUD_16_AUX                    (MM_MEDIAVISION_PROAUDIO_16 + 7)

#Define MM_MEDIAVISION_PROSTUDIO_16         060H
#Define MM_STUDIO_16_MIDIOUT                (MM_MEDIAVISION_PROSTUDIO_16 + 1)
#Define MM_STUDIO_16_MIDIIN                 (MM_MEDIAVISION_PROSTUDIO_16 + 2)
#Define MM_STUDIO_16_SYNTH                  (MM_MEDIAVISION_PROSTUDIO_16 + 3)
#Define MM_STUDIO_16_WAVEOUT                (MM_MEDIAVISION_PROSTUDIO_16 + 4)
#Define MM_STUDIO_16_WAVEIN                 (MM_MEDIAVISION_PROSTUDIO_16 + 5)
#Define MM_STUDIO_16_MIXER                  (MM_MEDIAVISION_PROSTUDIO_16 + 6)
#Define MM_STUDIO_16_AUX                    (MM_MEDIAVISION_PROSTUDIO_16 + 7)

#Define MM_MEDIAVISION_CDPC                 070H
#Define MM_CDPC_MIDIOUT                     (MM_MEDIAVISION_CDPC + 1)
#Define MM_CDPC_MIDIIN                      (MM_MEDIAVISION_CDPC + 2)
#Define MM_CDPC_SYNTH                       (MM_MEDIAVISION_CDPC + 3)
#Define MM_CDPC_WAVEOUT                     (MM_MEDIAVISION_CDPC + 4)
#Define MM_CDPC_WAVEIN                      (MM_MEDIAVISION_CDPC + 5)
#Define MM_CDPC_MIXER                       (MM_MEDIAVISION_CDPC + 6)
#Define MM_CDPC_AUX                         (MM_MEDIAVISION_CDPC + 7)

#Define MM_MEDIAVISION_OPUS1208             080H
#Define MM_OPUS401_MIDIOUT                  (MM_MEDIAVISION_OPUS1208 + 1)
#Define MM_OPUS401_MIDIIN                   (MM_MEDIAVISION_OPUS1208 + 2)
#Define MM_OPUS1208_SYNTH                   (MM_MEDIAVISION_OPUS1208 + 3)
#Define MM_OPUS1208_WAVEOUT                 (MM_MEDIAVISION_OPUS1208 + 4)
#Define MM_OPUS1208_WAVEIN                  (MM_MEDIAVISION_OPUS1208 + 5)
#Define MM_OPUS1208_MIXER                   (MM_MEDIAVISION_OPUS1208 + 6)
#Define MM_OPUS1208_AUX                     (MM_MEDIAVISION_OPUS1208 + 7)

#Define MM_MEDIAVISION_OPUS1216             090H
#Define MM_OPUS1216_MIDIOUT                 (MM_MEDIAVISION_OPUS1216 + 1)
#Define MM_OPUS1216_MIDIIN                  (MM_MEDIAVISION_OPUS1216 + 2)
#Define MM_OPUS1216_SYNTH                   (MM_MEDIAVISION_OPUS1216 + 3)
#Define MM_OPUS1216_WAVEOUT                 (MM_MEDIAVISION_OPUS1216 + 4)
#Define MM_OPUS1216_WAVEIN                  (MM_MEDIAVISION_OPUS1216 + 5)
#Define MM_OPUS1216_MIXER                   (MM_MEDIAVISION_OPUS1216 + 6)
#Define MM_OPUS1216_AUX                     (MM_MEDIAVISION_OPUS1216 + 7)

#Define MM_ARTISOFT_SBWAVEIN                1
#Define MM_ARTISOFT_SBWAVEOUT               2

#Define MM_MMOTION_WAVEAUX                  1
#Define MM_MMOTION_WAVEOUT                  2
#Define MM_MMOTION_WAVEIN                   3
#Define MM_IBM_PCMCIA_WAVEIN                11
#Define MM_IBM_PCMCIA_WAVEOUT               12
#Define MM_IBM_PCMCIA_SYNTH                 13
#Define MM_IBM_PCMCIA_MIDIIN                14
#Define MM_IBM_PCMCIA_MIDIOUT               15
#Define MM_IBM_PCMCIA_AUX                   16
#Define MM_IBM_THINKPAD200                  17
#Define MM_IBM_MWAVE_WAVEIN                 18
#Define MM_IBM_MWAVE_WAVEOUT                19
#Define MM_IBM_MWAVE_MIXER                  20
#Define MM_IBM_MWAVE_MIDIIN                 21
#Define MM_IBM_MWAVE_MIDIOUT                22
#Define MM_IBM_MWAVE_AUX                    23
#Define MM_IBM_WC_MIDIOUT                   30
#Define MM_IBM_WC_WAVEOUT                   31
#Define MM_IBM_WC_MIXEROUT                  33

#Define MM_VOCALTEC_WAVEOUT                 1
#Define MM_VOCALTEC_WAVEIN                  2

#Define MM_ROLAND_RAP10_MIDIOUT             10
#Define MM_ROLAND_RAP10_MIDIIN              11
#Define MM_ROLAND_RAP10_SYNTH               12
#Define MM_ROLAND_RAP10_WAVEOUT             13
#Define MM_ROLAND_RAP10_WAVEIN              14
#Define MM_ROLAND_MPU401_MIDIOUT            15
#Define MM_ROLAND_MPU401_MIDIIN             16
#Define MM_ROLAND_SMPU_MIDIOUTA             17
#Define MM_ROLAND_SMPU_MIDIOUTB             18
#Define MM_ROLAND_SMPU_MIDIINA              19
#Define MM_ROLAND_SMPU_MIDIINB              20
#Define MM_ROLAND_SC7_MIDIOUT               21
#Define MM_ROLAND_SC7_MIDIIN                22
#Define MM_ROLAND_SERIAL_MIDIOUT            23
#Define MM_ROLAND_SERIAL_MIDIIN             24
#Define MM_ROLAND_SCP_MIDIOUT               38
#Define MM_ROLAND_SCP_MIDIIN                39
#Define MM_ROLAND_SCP_WAVEOUT               40
#Define MM_ROLAND_SCP_WAVEIN                41
#Define MM_ROLAND_SCP_MIXER                 42
#Define MM_ROLAND_SCP_AUX                   48

#Define MM_DSP_SOLUTIONS_WAVEOUT            1
#Define MM_DSP_SOLUTIONS_WAVEIN             2
#Define MM_DSP_SOLUTIONS_SYNTH              3
#Define MM_DSP_SOLUTIONS_AUX                4

#Define MM_WANGLABS_WAVEIN1                 1
#Define MM_WANGLABS_WAVEOUT1                2

#Define MM_TANDY_VISWAVEIN                  1
#Define MM_TANDY_VISWAVEOUT                 2
#Define MM_TANDY_VISBIOSSYNTH               3
#Define MM_TANDY_SENS_MMAWAVEIN             4
#Define MM_TANDY_SENS_MMAWAVEOUT            5
#Define MM_TANDY_SENS_MMAMIDIIN             6
#Define MM_TANDY_SENS_MMAMIDIOUT            7
#Define MM_TANDY_SENS_VISWAVEOUT            8
#Define MM_TANDY_PSSJWAVEIN                 9
#Define MM_TANDY_PSSJWAVEOUT                10

#Define MM_INTELOPD_WAVEIN                  1
#Define MM_INTELOPD_WAVEOUT                 101
#Define MM_INTELOPD_AUX                     401
#Define MM_INTEL_NSPMODEMLINE               501

#Define MM_INTERACTIVE_WAVEIN               045H
#Define MM_INTERACTIVE_WAVEOUT              045H

#Define MM_YAMAHA_GSS_SYNTH                 001H
#Define MM_YAMAHA_GSS_WAVEOUT               002H
#Define MM_YAMAHA_GSS_WAVEIN                003H
#Define MM_YAMAHA_GSS_MIDIOUT               004H
#Define MM_YAMAHA_GSS_MIDIIN                005H
#Define MM_YAMAHA_GSS_AUX                   006H
#Define MM_YAMAHA_SERIAL_MIDIOUT            007H
#Define MM_YAMAHA_SERIAL_MIDIIN             008H
#Define MM_YAMAHA_OPL3SA_WAVEOUT            010H
#Define MM_YAMAHA_OPL3SA_WAVEIN             011H
#Define MM_YAMAHA_OPL3SA_FMSYNTH            012H
#Define MM_YAMAHA_OPL3SA_YSYNTH             013H
#Define MM_YAMAHA_OPL3SA_MIDIOUT            014H
#Define MM_YAMAHA_OPL3SA_MIDIIN             015H
#Define MM_YAMAHA_OPL3SA_MIXER              017H
#Define MM_YAMAHA_OPL3SA_JOYSTICK           018H

#Define MM_EVEREX_CARRIER                   001H

#Define MM_ECHO_SYNTH                       001H
#Define MM_ECHO_WAVEOUT                     002H
#Define MM_ECHO_WAVEIN                      003H
#Define MM_ECHO_MIDIOUT                     004H
#Define MM_ECHO_MIDIIN                      005H
#Define MM_ECHO_AUX                         006H

#Define MM_SIERRA_ARIA_MIDIOUT              014H
#Define MM_SIERRA_ARIA_MIDIIN               015H
#Define MM_SIERRA_ARIA_SYNTH                016H
#Define MM_SIERRA_ARIA_WAVEOUT              017H
#Define MM_SIERRA_ARIA_WAVEIN               018H
#Define MM_SIERRA_ARIA_AUX                  019H
#Define MM_SIERRA_ARIA_AUX2                 020H
#Define MM_SIERRA_QUARTET_WAVEIN            050H
#Define MM_SIERRA_QUARTET_WAVEOUT           051H
#Define MM_SIERRA_QUARTET_MIDIIN            052H
#Define MM_SIERRA_QUARTET_MIDIOUT           053H
#Define MM_SIERRA_QUARTET_SYNTH             054H
#Define MM_SIERRA_QUARTET_AUX_CD            055H
#Define MM_SIERRA_QUARTET_AUX_LINE          056H
#Define MM_SIERRA_QUARTET_AUX_MODEM         057H
#Define MM_SIERRA_QUARTET_MIXER             058H

#Define MM_CAT_WAVEOUT                      1

#Define MM_DSP_GROUP_TRUESPEECH            001H

#Define MM_MELABS_MIDI2GO                  001H

#Define MM_ESS_AMWAVEOUT                    001H
#Define MM_ESS_AMWAVEIN                     002H
#Define MM_ESS_AMAUX                        003H
#Define MM_ESS_AMSYNTH                      004H
#Define MM_ESS_AMMIDIOUT                    005H
#Define MM_ESS_AMMIDIIN                     006H
#Define MM_ESS_MIXER                        007H
#Define MM_ESS_AUX_CD                       008H
#Define MM_ESS_MPU401_MIDIOUT               009H
#Define MM_ESS_MPU401_MIDIIN                00AH
#Define MM_ESS_ES488_WAVEOUT                010H
#Define MM_ESS_ES488_WAVEIN                 011H
#Define MM_ESS_ES488_MIXER                  012H
#Define MM_ESS_ES688_WAVEOUT                013H
#Define MM_ESS_ES688_WAVEIN                 014H
#Define MM_ESS_ES688_MIXER                  015H
#Define MM_ESS_ES1488_WAVEOUT               016H
#Define MM_ESS_ES1488_WAVEIN                017H
#Define MM_ESS_ES1488_MIXER                 018H
#Define MM_ESS_ES1688_WAVEOUT               019H
#Define MM_ESS_ES1688_WAVEIN                01AH
#Define MM_ESS_ES1688_MIXER                 01BH
#Define MM_ESS_ES1788_WAVEOUT               01CH
#Define MM_ESS_ES1788_WAVEIN                01DH
#Define MM_ESS_ES1788_MIXER                 01EH
#Define MM_ESS_ES1888_WAVEOUT               01FH
#Define MM_ESS_ES1888_WAVEIN                020H
#Define MM_ESS_ES1888_MIXER                 021H
#Define MM_ESS_ES1868_WAVEOUT               022H
#Define MM_ESS_ES1868_WAVEIN                023H
#Define MM_ESS_ES1868_MIXER                 024H
#Define MM_ESS_ES1878_WAVEOUT               025H
#Define MM_ESS_ES1878_WAVEIN                026H
#Define MM_ESS_ES1878_MIXER                 027H

#Define MM_EPS_FMSND                        1

#Define MM_TRUEVISION_WAVEIN1               1
#Define MM_TRUEVISION_WAVEOUT1              2

#Define MM_AZTECH_MIDIOUT                   3
#Define MM_AZTECH_MIDIIN                    4
#Define MM_AZTECH_WAVEIN                    17
#Define MM_AZTECH_WAVEOUT                   18
#Define MM_AZTECH_FMSYNTH                   20
#Define MM_AZTECH_MIXER                     21
#Define MM_AZTECH_PRO16_WAVEIN              33
#Define MM_AZTECH_PRO16_WAVEOUT             34
#Define MM_AZTECH_PRO16_FMSYNTH             38
#Define MM_AZTECH_DSP16_WAVEIN              65
#Define MM_AZTECH_DSP16_WAVEOUT             66
#Define MM_AZTECH_DSP16_FMSYNTH             68
#Define MM_AZTECH_DSP16_WAVESYNTH           70
#Define MM_AZTECH_NOVA16_WAVEIN             71
#Define MM_AZTECH_NOVA16_WAVEOUT            72
#Define MM_AZTECH_NOVA16_MIXER              73
#Define MM_AZTECH_WASH16_WAVEIN             74
#Define MM_AZTECH_WASH16_WAVEOUT            75
#Define MM_AZTECH_WASH16_MIXER              76
#Define MM_AZTECH_AUX_CD                    401
#Define MM_AZTECH_AUX_LINE                  402
#Define MM_AZTECH_AUX_MIC                   403
#Define MM_AZTECH_AUX                       404

#Define MM_VIDEOLOGIC_MSWAVEIN              1
#Define MM_VIDEOLOGIC_MSWAVEOUT             2

#Define MM_KORG_PCIF_MIDIOUT                1
#Define MM_KORG_PCIF_MIDIIN                 2

#Define MM_APT_ACE100CD                     1

#Define MM_ICS_WAVEDECK_WAVEOUT             1
#Define MM_ICS_WAVEDECK_WAVEIN              2
#Define MM_ICS_WAVEDECK_MIXER               3
#Define MM_ICS_WAVEDECK_AUX                 4
#Define MM_ICS_WAVEDECK_SYNTH               5
#Define MM_ICS_WAVEDEC_SB_WAVEOUT           6
#Define MM_ICS_WAVEDEC_SB_WAVEIN            7
#Define MM_ICS_WAVEDEC_SB_FM_MIDIOUT        8
#Define MM_ICS_WAVEDEC_SB_MPU401_MIDIOUT    9
#Define MM_ICS_WAVEDEC_SB_MPU401_MIDIIN     10
#Define MM_ICS_WAVEDEC_SB_MIXER             11
#Define MM_ICS_WAVEDEC_SB_AUX               12
#Define MM_ICS_2115_LITE_MIDIOUT            13
#Define MM_ICS_2120_LITE_MIDIOUT            14

#Define MM_ITERATEDSYS_FUFCODEC             1

#Define MM_METHEUS_ZIPPER                   1

#Define MM_WINNOV_CAVIAR_WAVEIN             1
#Define MM_WINNOV_CAVIAR_WAVEOUT            2
#Define MM_WINNOV_CAVIAR_VIDC               3
#Define MM_WINNOV_CAVIAR_CHAMPAGNE          4
#Define MM_WINNOV_CAVIAR_YUV8               5

#Define MM_NCR_BA_WAVEIN                    1
#Define MM_NCR_BA_WAVEOUT                   2
#Define MM_NCR_BA_SYNTH                     3
#Define MM_NCR_BA_AUX                       4
#Define MM_NCR_BA_MIXER                     5

#Define MM_VITEC_VMAKER                     1
#Define MM_VITEC_VMPRO                      2

#Define MM_MOSCOM_VPC2400_IN                1
#Define MM_MOSCOM_VPC2400_OUT               2

#Define MM_SILICONSOFT_SC1_WAVEIN           1
#Define MM_SILICONSOFT_SC1_WAVEOUT          2
#Define MM_SILICONSOFT_SC2_WAVEIN           3
#Define MM_SILICONSOFT_SC2_WAVEOUT          4
#Define MM_SILICONSOFT_SOUNDJR2_WAVEOUT     5
#Define MM_SILICONSOFT_SOUNDJR2PR_WAVEIN    6
#Define MM_SILICONSOFT_SOUNDJR2PR_WAVEOUT   7
#Define MM_SILICONSOFT_SOUNDJR3_WAVEOUT     8

#Define MM_OLIVETTI_WAVEIN                  1
#Define MM_OLIVETTI_WAVEOUT                 2
#Define MM_OLIVETTI_MIXER                   3
#Define MM_OLIVETTI_AUX                     4
#Define MM_OLIVETTI_MIDIIN                  5
#Define MM_OLIVETTI_MIDIOUT                 6
#Define MM_OLIVETTI_SYNTH                   7
#Define MM_OLIVETTI_JOYSTICK                8
#Define MM_OLIVETTI_ACM_GSM                 9
#Define MM_OLIVETTI_ACM_ADPCM               10
#Define MM_OLIVETTI_ACM_CELP                11
#Define MM_OLIVETTI_ACM_SBC                 12
#Define MM_OLIVETTI_ACM_OPR                 13

#Define MM_IOMAGIC_TEMPO_WAVEOUT            1
#Define MM_IOMAGIC_TEMPO_WAVEIN             2
#Define MM_IOMAGIC_TEMPO_SYNTH              3
#Define MM_IOMAGIC_TEMPO_MIDIOUT            4
#Define MM_IOMAGIC_TEMPO_MXDOUT             5
#Define MM_IOMAGIC_TEMPO_AUXOUT             6

#Define MM_MATSUSHITA_WAVEIN                1
#Define MM_MATSUSHITA_WAVEOUT               2
#Define MM_MATSUSHITA_FMSYNTH_STEREO        3
#Define MM_MATSUSHITA_MIXER                 4
#Define MM_MATSUSHITA_AUX                   5

#Define MM_NEWMEDIA_WAVJAMMER               1

#Define MM_LYRRUS_BRIDGE_GUITAR             1

#Define MM_OPTI_M16_FMSYNTH_STEREO          00001H
#Define MM_OPTI_M16_MIDIIN                  00002H
#Define MM_OPTI_M16_MIDIOUT                 00003H
#Define MM_OPTI_M16_WAVEIN                  00004H
#Define MM_OPTI_M16_WAVEOUT                 00005H
#Define MM_OPTI_M16_MIXER                   00006H
#Define MM_OPTI_M16_AUX                     00007H
#Define MM_OPTI_P16_FMSYNTH_STEREO          00010H
#Define MM_OPTI_P16_MIDIIN                  00011H
#Define MM_OPTI_P16_MIDIOUT                 00012H
#Define MM_OPTI_P16_WAVEIN                  00013H
#Define MM_OPTI_P16_WAVEOUT                 00014H
#Define MM_OPTI_P16_MIXER                   00015H
#Define MM_OPTI_P16_AUX                     00016H
#Define MM_OPTI_M32_WAVEIN                  00020H
#Define MM_OPTI_M32_WAVEOUT                 00021H
#Define MM_OPTI_M32_MIDIIN                  00022H
#Define MM_OPTI_M32_MIDIOUT                 00023H
#Define MM_OPTI_M32_SYNTH_STEREO            00024H
#Define MM_OPTI_M32_MIXER                   00025H
#Define MM_OPTI_M32_AUX                     00026H

#Define MM_ADDX_PCTV_DIGITALMIX             1
#Define MM_ADDX_PCTV_WAVEIN                 2
#Define MM_ADDX_PCTV_WAVEOUT                3
#Define MM_ADDX_PCTV_MIXER                  4
#Define MM_ADDX_PCTV_AUX_CD                 5
#Define MM_ADDX_PCTV_AUX_LINE               6

#Define MM_AHEAD_MULTISOUND                 1
#Define MM_AHEAD_SOUNDBLASTER               2
#Define MM_AHEAD_PROAUDIO                   3
#Define MM_AHEAD_GENERIC                    4

#Define MM_AMD_INTERWAVE_WAVEIN             1
#Define MM_AMD_INTERWAVE_WAVEOUT            2
#Define MM_AMD_INTERWAVE_SYNTH              3
#Define MM_AMD_INTERWAVE_MIXER1             4
#Define MM_AMD_INTERWAVE_MIXER2             5
#Define MM_AMD_INTERWAVE_JOYSTICK           6
#Define MM_AMD_INTERWAVE_EX_CD              7
#Define MM_AMD_INTERWAVE_MIDIIN             8
#Define MM_AMD_INTERWAVE_MIDIOUT            9
#Define MM_AMD_INTERWAVE_AUX1               10
#Define MM_AMD_INTERWAVE_AUX2               11
#Define MM_AMD_INTERWAVE_AUX_MIC            12
#Define MM_AMD_INTERWAVE_AUX_CD             13
#Define MM_AMD_INTERWAVE_MONO_IN            14
#Define MM_AMD_INTERWAVE_MONO_OUT           15
#Define MM_AMD_INTERWAVE_EX_TELEPHONY       16
#Define MM_AMD_INTERWAVE_WAVEOUT_BASE       17
#Define MM_AMD_INTERWAVE_WAVEOUT_TREBLE     18
#Define MM_AMD_INTERWAVE_STEREO_ENHANCED    19

#Define MM_AST_MODEMWAVE_WAVEIN             13
#Define MM_AST_MODEMWAVE_WAVEOUT            14

#Define MM_BTV_WAVEIN                       1
#Define MM_BTV_WAVEOUT                      2
#Define MM_BTV_MIDIIN                       3
#Define MM_BTV_MIDIOUT                      4
#Define MM_BTV_MIDISYNTH                    5
#Define MM_BTV_AUX_LINE                     6
#Define MM_BTV_AUX_MIC                      7
#Define MM_BTV_AUX_CD                       8
#Define MM_BTV_DIGITALIN                    9
#Define MM_BTV_DIGITALOUT                   10
#Define MM_BTV_MIDIWAVESTREAM               11
#Define MM_BTV_MIXER                        12

#Define MM_CANAM_CBXWAVEOUT                 1
#Define MM_CANAM_CBXWAVEIN                  2

#Define MM_CASIO_WP150_MIDIOUT              1
#Define MM_CASIO_WP150_MIDIIN               2

#define  MM_COMPAQ_BB_WAVEIN                1
#Define MM_COMPAQ_BB_WAVEOUT               2
#define  MM_COMPAQ_BB_WAVEAUX               3

#Define MM_COREDYNAMICS_DYNAMIXHR           1
#Define MM_COREDYNAMICS_DYNASONIX_SYNTH     2
#Define MM_COREDYNAMICS_DYNASONIX_MIDI_IN   3
#Define MM_COREDYNAMICS_DYNASONIX_MIDI_OUT  4
#Define MM_COREDYNAMICS_DYNASONIX_WAVE_IN   5
#Define MM_COREDYNAMICS_DYNASONIX_WAVE_OUT  6
#Define MM_COREDYNAMICS_DYNASONIX_AUDIO_IN  7
#Define MM_COREDYNAMICS_DYNASONIX_AUDIO_OUT 8
#Define MM_COREDYNAMICS_DYNAGRAFX_VGA       9
#Define MM_COREDYNAMICS_DYNAGRAFX_WAVE_IN   10
#Define MM_COREDYNAMICS_DYNAGRAFX_WAVE_OUT  11

#Define MM_CRYSTAL_CS4232_WAVEIN            1
#Define MM_CRYSTAL_CS4232_WAVEOUT           2
#Define MM_CRYSTAL_CS4232_WAVEMIXER         3
#Define MM_CRYSTAL_CS4232_WAVEAUX_AUX1      4
#Define MM_CRYSTAL_CS4232_WAVEAUX_AUX2      5
#Define MM_CRYSTAL_CS4232_WAVEAUX_LINE      6
#Define MM_CRYSTAL_CS4232_WAVEAUX_MONO      7
#Define MM_CRYSTAL_CS4232_WAVEAUX_MASTER    8
#Define MM_CRYSTAL_CS4232_MIDIIN            9
#Define MM_CRYSTAL_CS4232_MIDIOUT           10
#Define MM_CRYSTAL_CS4232_INPUTGAIN_AUX1    13
#Define MM_CRYSTAL_CS4232_INPUTGAIN_LOOP    14

#Define MM_DDD_MIDILINK_MIDIIN              1
#Define MM_DDD_MIDILINK_MIDIOUT             2

#Define MM_DIACOUSTICS_DRUM_ACTION          1

#Define MM_DIMD_PLATFORM                    0
#Define MM_DIMD_DIRSOUND                    1
#Define MM_DIMD_VIRTMPU                     2
#Define MM_DIMD_VIRTSB                      3
#Define MM_DIMD_VIRTJOY                     4
#Define MM_DIMD_WAVEIN                      5
#Define MM_DIMD_WAVEOUT                     6
#Define MM_DIMD_MIDIIN                      7
#Define MM_DIMD_MIDIOUT                     8
#Define MM_DIMD_AUX_LINE                    9
#Define MM_DIMD_MIXER                       10

#Define MM_DIGITAL_AUDIO_LABS_V8            010H
#Define MM_DIGITAL_AUDIO_LABS_CPRO          011H

#Define MM_DIGITAL_AV320_WAVEIN             1
#Define MM_DIGITAL_AV320_WAVEOUT            2

#Define MM_ECS_AADF_MIDI_IN                 10
#Define MM_ECS_AADF_MIDI_OUT                11
#Define MM_ECS_AADF_WAVE2MIDI_IN            12

#Define MM_ENSONIQ_SOUNDSCAPE               010H
#Define MM_SOUNDSCAPE_WAVEOUT               MM_ENSONIQ_SOUNDSCAPE + 1
#Define MM_SOUNDSCAPE_WAVEOUT_AUX           MM_ENSONIQ_SOUNDSCAPE + 2
#Define MM_SOUNDSCAPE_WAVEIN                MM_ENSONIQ_SOUNDSCAPE + 3
#Define MM_SOUNDSCAPE_MIDIOUT               MM_ENSONIQ_SOUNDSCAPE + 4
#Define MM_SOUNDSCAPE_MIDIIN                MM_ENSONIQ_SOUNDSCAPE + 5
#Define MM_SOUNDSCAPE_SYNTH                 MM_ENSONIQ_SOUNDSCAPE + 6
#Define MM_SOUNDSCAPE_MIXER                 MM_ENSONIQ_SOUNDSCAPE + 7
#Define MM_SOUNDSCAPE_AUX                   MM_ENSONIQ_SOUNDSCAPE + 8

#Define MM_FRONTIER_WAVECENTER_MIDIIN       1
#Define MM_FRONTIER_WAVECENTER_MIDIOUT      2
#Define MM_FRONTIER_WAVECENTER_WAVEIN       3
#Define MM_FRONTIER_WAVECENTER_WAVEOUT      4

#Define MM_GADGETLABS_WAVE44_WAVEIN         1
#Define MM_GADGETLABS_WAVE44_WAVEOUT        2
#Define MM_GADGETLABS_WAVE42_WAVEIN         3
#Define MM_GADGETLABS_WAVE42_WAVEOUT        4
#Define MM_GADGETLABS_WAVE4_MIDIIN          5
#Define MM_GADGETLABS_WAVE4_MIDIOUT         6

#Define MM_KAY_ELEMETRICS_CSL               04300H
#Define MM_KAY_ELEMETRICS_CSL_DAT           04308H
#Define MM_KAY_ELEMETRICS_CSL_4CHANNEL      04309H

#Define MM_LERNOUT_ANDHAUSPIE_LHCODECACM    1

#Define MM_MPTUS_SPWAVEOUT                  1

#Define MM_MOTU_MTP_MIDIOUT_ALL             100
#Define MM_MOTU_MTP_MIDIIN_1                101
#Define MM_MOTU_MTP_MIDIOUT_1               101
#Define MM_MOTU_MTP_MIDIIN_2                102
#Define MM_MOTU_MTP_MIDIOUT_2               102
#Define MM_MOTU_MTP_MIDIIN_3                103
#Define MM_MOTU_MTP_MIDIOUT_3               103
#Define MM_MOTU_MTP_MIDIIN_4                104
#Define MM_MOTU_MTP_MIDIOUT_4               104
#Define MM_MOTU_MTP_MIDIIN_5                105
#Define MM_MOTU_MTP_MIDIOUT_5               105
#Define MM_MOTU_MTP_MIDIIN_6                106
#Define MM_MOTU_MTP_MIDIOUT_6               106
#Define MM_MOTU_MTP_MIDIIN_7                107
#Define MM_MOTU_MTP_MIDIOUT_7               107
#Define MM_MOTU_MTP_MIDIIN_8                108
#Define MM_MOTU_MTP_MIDIOUT_8               108

#Define MM_MOTU_MTPII_MIDIOUT_ALL           200
#Define MM_MOTU_MTPII_MIDIIN_SYNC           200
#Define MM_MOTU_MTPII_MIDIIN_1              201
#Define MM_MOTU_MTPII_MIDIOUT_1             201
#Define MM_MOTU_MTPII_MIDIIN_2              202
#Define MM_MOTU_MTPII_MIDIOUT_2             202
#Define MM_MOTU_MTPII_MIDIIN_3              203
#Define MM_MOTU_MTPII_MIDIOUT_3             203
#Define MM_MOTU_MTPII_MIDIIN_4              204
#Define MM_MOTU_MTPII_MIDIOUT_4             204
#Define MM_MOTU_MTPII_MIDIIN_5              205
#Define MM_MOTU_MTPII_MIDIOUT_5             205
#Define MM_MOTU_MTPII_MIDIIN_6              206
#Define MM_MOTU_MTPII_MIDIOUT_6             206
#Define MM_MOTU_MTPII_MIDIIN_7              207
#Define MM_MOTU_MTPII_MIDIOUT_7             207
#Define MM_MOTU_MTPII_MIDIIN_8              208
#Define MM_MOTU_MTPII_MIDIOUT_8             208
#Define MM_MOTU_MTPII_NET_MIDIIN_1          209
#Define MM_MOTU_MTPII_NET_MIDIOUT_1         209
#Define MM_MOTU_MTPII_NET_MIDIIN_2          210
#Define MM_MOTU_MTPII_NET_MIDIOUT_2         210
#Define MM_MOTU_MTPII_NET_MIDIIN_3          211
#Define MM_MOTU_MTPII_NET_MIDIOUT_3         211
#Define MM_MOTU_MTPII_NET_MIDIIN_4          212
#Define MM_MOTU_MTPII_NET_MIDIOUT_4         212
#Define MM_MOTU_MTPII_NET_MIDIIN_5          213
#Define MM_MOTU_MTPII_NET_MIDIOUT_5         213
#Define MM_MOTU_MTPII_NET_MIDIIN_6          214
#Define MM_MOTU_MTPII_NET_MIDIOUT_6         214
#Define MM_MOTU_MTPII_NET_MIDIIN_7          215
#Define MM_MOTU_MTPII_NET_MIDIOUT_7         215
#Define MM_MOTU_MTPII_NET_MIDIIN_8          216
#Define MM_MOTU_MTPII_NET_MIDIOUT_8         216

#Define MM_MOTU_MXP_MIDIIN_MIDIOUT_ALL      300
#Define MM_MOTU_MXP_MIDIIN_SYNC             300
#Define MM_MOTU_MXP_MIDIIN_MIDIIN_1         301
#Define MM_MOTU_MXP_MIDIIN_MIDIOUT_1        301
#Define MM_MOTU_MXP_MIDIIN_MIDIIN_2         302
#Define MM_MOTU_MXP_MIDIIN_MIDIOUT_2        302
#Define MM_MOTU_MXP_MIDIIN_MIDIIN_3         303
#Define MM_MOTU_MXP_MIDIIN_MIDIOUT_3        303
#Define MM_MOTU_MXP_MIDIIN_MIDIIN_4         304
#Define MM_MOTU_MXP_MIDIIN_MIDIOUT_4        304
#Define MM_MOTU_MXP_MIDIIN_MIDIIN_5         305
#Define MM_MOTU_MXP_MIDIIN_MIDIOUT_5        305
#Define MM_MOTU_MXP_MIDIIN_MIDIIN_6         306
#Define MM_MOTU_MXP_MIDIIN_MIDIOUT_6        306

#Define MM_MOTU_MXPMPU_MIDIOUT_ALL          400
#Define MM_MOTU_MXPMPU_MIDIIN_SYNC          400
#Define MM_MOTU_MXPMPU_MIDIIN_1             401
#Define MM_MOTU_MXPMPU_MIDIOUT_1            401
#Define MM_MOTU_MXPMPU_MIDIIN_2             402
#Define MM_MOTU_MXPMPU_MIDIOUT_2            402
#Define MM_MOTU_MXPMPU_MIDIIN_3             403
#Define MM_MOTU_MXPMPU_MIDIOUT_3            403
#Define MM_MOTU_MXPMPU_MIDIIN_4             404
#Define MM_MOTU_MXPMPU_MIDIOUT_4            404
#Define MM_MOTU_MXPMPU_MIDIIN_5             405
#Define MM_MOTU_MXPMPU_MIDIOUT_5            405
#Define MM_MOTU_MXPMPU_MIDIIN_6             406
#Define MM_MOTU_MXPMPU_MIDIOUT_6            406

#Define MM_MOTU_MXN_MIDIOUT_ALL             500
#Define MM_MOTU_MXN_MIDIIN_SYNC             500
#Define MM_MOTU_MXN_MIDIIN_1                501
#Define MM_MOTU_MXN_MIDIOUT_1               501
#Define MM_MOTU_MXN_MIDIIN_2                502
#Define MM_MOTU_MXN_MIDIOUT_2               502
#Define MM_MOTU_MXN_MIDIIN_3                503
#Define MM_MOTU_MXN_MIDIOUT_3               503
#Define MM_MOTU_MXN_MIDIIN_4                504
#Define MM_MOTU_MXN_MIDIOUT_4               504

#Define MM_MOTU_FLYER_MIDI_IN_SYNC          600
#Define MM_MOTU_FLYER_MIDI_IN_A             601
#Define MM_MOTU_FLYER_MIDI_OUT_A            601
#Define MM_MOTU_FLYER_MIDI_IN_B             602
#Define MM_MOTU_FLYER_MIDI_OUT_B            602

#Define MM_MOTU_PKX_MIDI_IN_SYNC            700
#Define MM_MOTU_PKX_MIDI_IN_A               701
#Define MM_MOTU_PKX_MIDI_OUT_A              701
#Define MM_MOTU_PKX_MIDI_IN_B               702
#Define MM_MOTU_PKX_MIDI_OUT_B              702

#Define MM_MOTU_DTX_MIDI_IN_SYNC            800
#Define MM_MOTU_DTX_MIDI_IN_A               801
#Define MM_MOTU_DTX_MIDI_OUT_A              801
#Define MM_MOTU_DTX_MIDI_IN_B               802
#Define MM_MOTU_DTX_MIDI_OUT_B              802

#Define MM_MOTU_MTPAV_MIDIOUT_ALL           900
#Define MM_MOTU_MTPAV_MIDIIN_SYNC           900
#Define MM_MOTU_MTPAV_MIDIIN_1              901
#Define MM_MOTU_MTPAV_MIDIOUT_1             901
#Define MM_MOTU_MTPAV_MIDIIN_2              902
#Define MM_MOTU_MTPAV_MIDIOUT_2             902
#Define MM_MOTU_MTPAV_MIDIIN_3              903
#Define MM_MOTU_MTPAV_MIDIOUT_3             903
#Define MM_MOTU_MTPAV_MIDIIN_4              904
#Define MM_MOTU_MTPAV_MIDIOUT_4             904
#Define MM_MOTU_MTPAV_MIDIIN_5              905
#Define MM_MOTU_MTPAV_MIDIOUT_5             905
#Define MM_MOTU_MTPAV_MIDIIN_6              906
#Define MM_MOTU_MTPAV_MIDIOUT_6             906
#Define MM_MOTU_MTPAV_MIDIIN_7              907
#Define MM_MOTU_MTPAV_MIDIOUT_7             907
#Define MM_MOTU_MTPAV_MIDIIN_8              908
#Define MM_MOTU_MTPAV_MIDIOUT_8             908
#Define MM_MOTU_MTPAV_NET_MIDIIN_1          909
#Define MM_MOTU_MTPAV_NET_MIDIOUT_1         909
#Define MM_MOTU_MTPAV_NET_MIDIIN_2          910
#Define MM_MOTU_MTPAV_NET_MIDIOUT_2         910
#Define MM_MOTU_MTPAV_NET_MIDIIN_3          911
#Define MM_MOTU_MTPAV_NET_MIDIOUT_3         911
#Define MM_MOTU_MTPAV_NET_MIDIIN_4          912
#Define MM_MOTU_MTPAV_NET_MIDIOUT_4         912
#Define MM_MOTU_MTPAV_NET_MIDIIN_5          913
#Define MM_MOTU_MTPAV_NET_MIDIOUT_5         913
#Define MM_MOTU_MTPAV_NET_MIDIIN_6          914
#Define MM_MOTU_MTPAV_NET_MIDIOUT_6         914
#Define MM_MOTU_MTPAV_NET_MIDIIN_7          915
#Define MM_MOTU_MTPAV_NET_MIDIOUT_7         915
#Define MM_MOTU_MTPAV_NET_MIDIIN_8          916
#Define MM_MOTU_MTPAV_NET_MIDIOUT_8         916
#Define MM_MOTU_MTPAV_MIDIIN_ADAT           917
#Define MM_MOTU_MTPAV_MIDIOUT_ADAT          917

#Define MM_MIRO_MOVIEPRO                    1
#Define MM_MIRO_VIDEOD1                     2
#Define MM_MIRO_VIDEODC1TV                  3
#Define MM_MIRO_VIDEOTD                     4
#Define MM_MIRO_DC30_WAVEOUT                5
#Define MM_MIRO_DC30_WAVEIN                 6
#Define MM_MIRO_DC30_MIX                    7

#Define MM_NEC_73_86_SYNTH                  5
#Define MM_NEC_73_86_WAVEOUT                6
#Define MM_NEC_73_86_WAVEIN                 7
#Define MM_NEC_26_SYNTH                     9
#Define MM_NEC_MPU401_MIDIOUT               10
#Define MM_NEC_MPU401_MIDIIN                11
#Define MM_NEC_JOYSTICK                     12

#Define MM_NORRIS_VOICELINK                 1

#Define MM_NORTEL_MPXAC_WAVEIN              1
#Define MM_NORTEL_MPXAC_WAVEOUT             2

#Define MM_NVIDIA_WAVEOUT                   1
#Define MM_NVIDIA_WAVEIN                    2
#Define MM_NVIDIA_MIDIOUT                   3
#Define MM_NVIDIA_MIDIIN                    4
#Define MM_NVIDIA_GAMEPORT                  5
#Define MM_NVIDIA_MIXER                     6
#Define MM_NVIDIA_AUX                       7

#Define MM_OKSORI_BASE                      0
#Define MM_OKSORI_OSR8_WAVEOUT              MM_OKSORI_BASE + 1
#Define MM_OKSORI_OSR8_WAVEIN               MM_OKSORI_BASE + 2
#Define MM_OKSORI_OSR16_WAVEOUT             MM_OKSORI_BASE + 3
#Define MM_OKSORI_OSR16_WAVEIN              MM_OKSORI_BASE + 4
#Define MM_OKSORI_FM_OPL4                   MM_OKSORI_BASE + 5
#Define MM_OKSORI_MIX_MASTER                MM_OKSORI_BASE + 6
#Define MM_OKSORI_MIX_WAVE                  MM_OKSORI_BASE + 7
#Define MM_OKSORI_MIX_FM                    MM_OKSORI_BASE + 8
#Define MM_OKSORI_MIX_LINE                  MM_OKSORI_BASE + 9
#Define MM_OKSORI_MIX_CD                    MM_OKSORI_BASE + 10
#Define MM_OKSORI_MIX_MIC                   MM_OKSORI_BASE + 11
#Define MM_OKSORI_MIX_ECHO                  MM_OKSORI_BASE + 12
#Define MM_OKSORI_MIX_AUX1                  MM_OKSORI_BASE + 13
#Define MM_OKSORI_MIX_LINE1                 MM_OKSORI_BASE + 14
#Define MM_OKSORI_EXT_MIC1                  MM_OKSORI_BASE + 15
#Define MM_OKSORI_EXT_MIC2                  MM_OKSORI_BASE + 16
#Define MM_OKSORI_MIDIOUT                   MM_OKSORI_BASE + 17
#Define MM_OKSORI_MIDIIN                    MM_OKSORI_BASE + 18
#Define MM_OKSORI_MPEG_CDVISION             MM_OKSORI_BASE + 19

#Define MM_OSITECH_TRUMPCARD                1

#Define MM_OSPREY_1000WAVEIN                1
#Define MM_OSPREY_1000WAVEOUT               2

#Define MM_QUARTERDECK_LHWAVEIN             0
#Define MM_QUARTERDECK_LHWAVEOUT            1

#Define MM_RHETOREX_WAVEIN                  1
#Define MM_RHETOREX_WAVEOUT                 2

#Define MM_VOICEMIXER                       1
#Define ROCKWELL_WA1_WAVEIN                 100
#Define ROCKWELL_WA1_WAVEOUT                101
#Define ROCKWELL_WA1_SYNTH                  102
#Define ROCKWELL_WA1_MIXER                  103
#Define ROCKWELL_WA1_MPU401_IN              104
#Define ROCKWELL_WA1_MPU401_OUT             105
#Define ROCKWELL_WA2_WAVEIN                 200
#Define ROCKWELL_WA2_WAVEOUT                201
#Define ROCKWELL_WA2_SYNTH                  202
#Define ROCKWELL_WA2_MIXER                  203
#Define ROCKWELL_WA2_MPU401_IN              204
#Define ROCKWELL_WA2_MPU401_OUT             205

#Define MM_S3_WAVEOUT                       01H
#Define MM_S3_WAVEIN                        02H
#Define MM_S3_MIDIOUT                       03H
#Define MM_S3_MIDIIN                        04H
#Define MM_S3_FMSYNTH                       05H
#Define MM_S3_MIXER                         06H
#Define MM_S3_AUX                           07H

#Define MM_SEERSYS_SEERSYNTH                1
#Define MM_SEERSYS_SEERWAVE                 2
#Define MM_SEERSYS_SEERMIX                  3

#Define MM_SOFTSOUND_CODEC                  1

#Define MM_SOUNDESIGNS_WAVEIN               1
#Define MM_SOUNDESIGNS_WAVEOUT              2

#Define MM_SSP_SNDFESWAVEIN                 1
#Define MM_SSP_SNDFESWAVEOUT                2
#Define MM_SSP_SNDFESMIDIIN                 3
#Define MM_SSP_SNDFESMIDIOUT                4
#Define MM_SSP_SNDFESSYNTH                  5
#Define MM_SSP_SNDFESMIX                    6
#Define MM_SSP_SNDFESAUX                    7

#Define MM_TDK_MW_MIDI_SYNTH                1
#Define MM_TDK_MW_MIDI_IN                   2
#Define MM_TDK_MW_MIDI_OUT                  3
#Define MM_TDK_MW_WAVE_IN                   4
#Define MM_TDK_MW_WAVE_OUT                  5
#Define MM_TDK_MW_AUX                       6
#Define MM_TDK_MW_MIXER                     10
#Define MM_TDK_MW_AUX_MASTER                100
#Define MM_TDK_MW_AUX_BASS                  101
#Define MM_TDK_MW_AUX_TREBLE                102
#Define MM_TDK_MW_AUX_MIDI_VOL              103
#Define MM_TDK_MW_AUX_WAVE_VOL              104
#Define MM_TDK_MW_AUX_WAVE_RVB              105
#Define MM_TDK_MW_AUX_WAVE_CHR              106
#Define MM_TDK_MW_AUX_VOL                   107
#Define MM_TDK_MW_AUX_RVB                   108
#Define MM_TDK_MW_AUX_CHR                   109

#Define MM_TBS_TROPEZ_WAVEIN                37
#Define MM_TBS_TROPEZ_WAVEOUT               38
#Define MM_TBS_TROPEZ_AUX1                  39
#Define MM_TBS_TROPEZ_AUX2                  40
#Define MM_TBS_TROPEZ_LINE                  41

#Define MM_VIENNASYS_TSP_WAVE_DRIVER        1

#Define MM_VIONA_QVINPCI_MIXER              1
#Define MM_VIONA_QVINPCI_WAVEIN             2
#Define MM_VIONAQVINPCI_WAVEOUT             3
#Define MM_VIONA_BUSTER_MIXER               4
#Define MM_VIONA_CINEMASTER_MIXER           5
#Define MM_VIONA_CONCERTO_MIXER             6

#Define MM_WILDCAT_AUTOSCOREMIDIIN          1

#Define MM_WILLOWPOND_FMSYNTH_STEREO        20
#Define MM_WILLOWPOND_SNDPORT_WAVEIN        100
#Define MM_WILLOWPOND_SNDPORT_WAVEOUT       101
#Define MM_WILLOWPOND_SNDPORT_MIXER         102
#Define MM_WILLOWPOND_SNDPORT_AUX           103
#Define MM_WILLOWPOND_PH_WAVEIN             104
#Define MM_WILLOWPOND_PH_WAVEOUT            105
#Define MM_WILLOWPOND_PH_MIXER              106
#Define MM_WILLOWPOND_PH_AUX                107

#Define MM_WORKBIT_MIXER                    1
#Define MM_WORKBIT_WAVEOUT                  2
#Define MM_WORKBIT_WAVEIN                   3
#Define MM_WORKBIT_MIDIIN                   4
#Define MM_WORKBIT_MIDIOUT                  5
#Define MM_WORKBIT_FMSYNTH                  6
#Define MM_WORKBIT_AUX                      7
#Define MM_WORKBIT_JOYSTICK                 8

#Define MM_FHGIIS_MPEGLAYER3                10

#Define RIFFINFO_IARL                       A'IARL'
#Define RIFFINFO_IART                       A'IART'
#Define RIFFINFO_ICMS                       A'ICMS'
#Define RIFFINFO_ICMT                       A'ICMT'
#Define RIFFINFO_ICOP                       A'ICOP'
#Define RIFFINFO_ICRD                       A'ICRD'
#Define RIFFINFO_ICRP                       A'ICRP'
#Define RIFFINFO_IDIM                       A'IDIM'
#Define RIFFINFO_IDPI                       A'IDPI'
#Define RIFFINFO_IENG                       A'IENG'
#Define RIFFINFO_IGNR                       A'IGNR'
#Define RIFFINFO_IKEY                       A'IKEY'
#Define RIFFINFO_ILGT                       A'ILGT'
#Define RIFFINFO_IMED                       A'IMED'
#Define RIFFINFO_INAM                       A'INAM'
#Define RIFFINFO_IPLT                       A'IPLT'
#Define RIFFINFO_IPRD                       A'IPRD'
#Define RIFFINFO_ISBJ                       A'ISBJ'
#Define RIFFINFO_ISFT                       A'ISFT'
#Define RIFFINFO_ISHP                       A'ISHP'
#Define RIFFINFO_ISRC                       A'ISRC'
#Define RIFFINFO_ISRF                       A'ISRF'
#Define RIFFINFO_ITCH                       A'ITCH'

#Define RIFFINFO_ISMP                       A'ISMP'
#Define RIFFINFO_IDIT                       A'IDIT'

#Define WAVE_FORMAT_UNKNOWN                 00000H
#Define WAVE_FORMAT_ADPCM                   00002H
#Define WAVE_FORMAT_IEEE_FLOAT              00003H
#Define WAVE_FORMAT_IBM_CVSD                00005H
#Define WAVE_FORMAT_ALAW                    00006H
#Define WAVE_FORMAT_MULAW                   00007H
#Define WAVE_FORMAT_OKI_ADPCM               00010H
#Define WAVE_FORMAT_DVI_ADPCM               00011H
#Define WAVE_FORMAT_IMA_ADPCM               (WAVE_FORMAT_DVI_ADPCM)
#Define WAVE_FORMAT_MEDIASPACE_ADPCM        00012H
#Define WAVE_FORMAT_SIERRA_ADPCM            00013H
#Define WAVE_FORMAT_G723_ADPCM              00014H
#Define WAVE_FORMAT_DIGISTD                 00015H
#Define WAVE_FORMAT_DIGIFIX                 00016H
#Define WAVE_FORMAT_DIALOGIC_OKI_ADPCM      00017H
#Define WAVE_FORMAT_MEDIAVISION_ADPCM       00018H
#Define WAVE_FORMAT_YAMAHA_ADPCM            00020H
#Define WAVE_FORMAT_SONARC                  00021H
#Define WAVE_FORMAT_DSPGROUP_TRUESPEECH     00022H
#Define WAVE_FORMAT_ECHOSC1                 00023H
#Define WAVE_FORMAT_AUDIOFILE_AF36          00024H
#Define WAVE_FORMAT_APTX                    00025H
#Define WAVE_FORMAT_AUDIOFILE_AF10          00026H
#Define WAVE_FORMAT_DOLBY_AC2               00030H
#Define WAVE_FORMAT_GSM610                  00031H
#Define WAVE_FORMAT_MSNAUDIO                00032H
#Define WAVE_FORMAT_ANTEX_ADPCME            00033H
#Define WAVE_FORMAT_CONTROL_RES_VQLPC       00034H
#Define WAVE_FORMAT_DIGIREAL                00035H
#Define WAVE_FORMAT_DIGIADPCM               00036H
#Define WAVE_FORMAT_CONTROL_RES_CR10        00037H
#Define WAVE_FORMAT_NMS_VBXADPCM            00038H
#Define WAVE_FORMAT_CS_IMAADPCM             00039H
#Define WAVE_FORMAT_ECHOSC3                 0003AH
#Define WAVE_FORMAT_ROCKWELL_ADPCM          0003BH
#Define WAVE_FORMAT_ROCKWELL_DIGITALK       0003CH
#Define WAVE_FORMAT_XEBEC                   0003DH
#Define WAVE_FORMAT_G721_ADPCM              00040H
#Define WAVE_FORMAT_G728_CELP               00041H
#Define WAVE_FORMAT_MPEG                    00050H
#Define WAVE_FORMAT_MPEGLAYER3              00055H
#Define WAVE_FORMAT_CIRRUS                  00060H
#Define WAVE_FORMAT_ESPCM                   00061H
#Define WAVE_FORMAT_VOXWARE                 00062H
#Define WAVEFORMAT_CANOPUS_ATRAC            00063H
#Define WAVE_FORMAT_G726_ADPCM              00064H
#Define WAVE_FORMAT_G722_ADPCM              00065H
#Define WAVE_FORMAT_DSAT                    00066H
#Define WAVE_FORMAT_DSAT_DISPLAY            00067H
#Define WAVE_FORMAT_SOFTSOUND               00080H
#Define WAVE_FORMAT_RHETOREX_ADPCM          00100H
#Define WAVE_FORMAT_CREATIVE_ADPCM          00200H
#Define WAVE_FORMAT_CREATIVE_FASTSPEECH8    00202H
#Define WAVE_FORMAT_CREATIVE_FASTSPEECH10   00203H
#Define WAVE_FORMAT_QUARTERDECK             00220H
#Define WAVE_FORMAT_FM_TOWNS_SND            00300H
#Define WAVE_FORMAT_BTV_DIGITAL             00400H
#Define WAVE_FORMAT_OLIGSM                  01000H
#Define WAVE_FORMAT_OLIADPCM                01001H
#Define WAVE_FORMAT_OLICELP                 01002H
#Define WAVE_FORMAT_OLISBC                  01003H
#Define WAVE_FORMAT_OLIOPR                  01004H
#Define WAVE_FORMAT_LH_CODEC                01100H
#Define WAVE_FORMAT_NORRIS                  01400H

#Define WAVE_FORMAT_DEVELOPMENT             0FFFFH

#IFNDEF WAVE_FORMAT_PCM
	#Define WAVE_FORMAT_PCM                 1

	WAVEFORMAT Struct
		wFormatTag DW
		nChannels DW
		nSamplesPerSec DD
		nAvgBytesPerSec DD
		nBlockAlign DW
	EndS

	PCMWAVEFORMAT Struct
		wf WAVEFORMAT <>
		wBitsPerSample DW
	EndS
#ENDIF

#IFNDEF _WAVEFORMATEX_
	#Define _WAVEFORMATEX_                  1

	WAVEFORMATEX Struct
		wFormatTag DW
		nChannels DW
		nSamplesPerSec DD
		nAvgBytesPerSec DD
		nBlockAlign DW
		wBitsPerSample DW
		cbSize DW
	EndS
#ENDIF

ADPCMCOEFSET Struct
	iCoef1 DW
	iCoef2 DW
EndS

ADPCMWAVEFORMAT Struct
	wfx WAVEFORMATEX <>
	wSamplesPerBlock DW
	wNumCoef DW
	aCoef ADPCMCOEFSET <>
EndS

DVIADPCMWAVEFORMAT Struct
	wfx WAVEFORMATEX <>
	wSamplesPerBlock DW
EndS

IMAADPCMWAVEFORMAT Struct
	wfx WAVEFORMATEX <>
	wSamplesPerBlock DW
EndS

MEDIASPACEADPCMWAVEFORMAT Struct
	wfx WAVEFORMATEX <>
	wRevision DW
EndS

SIERRAADPCMWAVEFORMAT Struct
	wfx WAVEFORMATEX <>
	wRevision DW
EndS

G723_ADPCMWAVEFORMAT Struct
	wfx WAVEFORMATEX <>
	cbExtraSize DW
	nAuxBlockSize DW
EndS

DIGISTDWAVEFORMAT Struct
	wfx WAVEFORMATEX <>
EndS

DIGIFIXWAVEFORMAT Struct
	wfx WAVEFORMATEX <>
EndS

DIALOGICOKIADPCMWAVEFORMAT Struct
	ewf WAVEFORMATEX <>
EndS

YAMAHA_ADPCMWAVEFORMAT Struct
	wfx WAVEFORMATEX <>
EndS

SONARCWAVEFORMAT Struct
	wfx WAVEFORMATEX <>
	wCompType DW
EndS

TRUESPEECHWAVEFORMAT Struct
	wfx WAVEFORMATEX <>
	wRevision DW
	wSamplesPerBlock DW
	abReserved DB 28 Dup
EndS

ECHOSC1WAVEFORMAT Struct
	wfx WAVEFORMATEX <>
EndS

AUDIOFILE_AF36WAVEFORMAT Struct
	wfx WAVEFORMATEX <>
EndS

APTXWAVEFORMAT Struct
	wfx WAVEFORMATEX <>
EndS

AUDIOFILE_AF10WAVEFORMAT Struct
	wfx WAVEFORMATEX <>
EndS

DOLBYAC2WAVEFORMAT Struct
	wfx WAVEFORMATEX <>
	nAuxBitsCode DW
EndS

GSM610WAVEFORMAT Struct
	wfx WAVEFORMATEX <>
	wSamplesPerBlock DW
EndS

ADPCMEWAVEFORMAT Struct
	wfx WAVEFORMATEX <>
	wSamplesPerBlock DW
EndS

CONTRESVQLPCWAVEFORMAT Struct
	wfx WAVEFORMATEX <>
	wSamplesPerBlock DW
EndS

DIGIREALWAVEFORMAT Struct
	wfx WAVEFORMATEX <>
	wSamplesPerBlock DW
EndS

DIGIADPCMWAVEFORMAT Struct
	wfx WAVEFORMATEX <>
	wSamplesPerBlock DW
EndS

CONTRESCR10WAVEFORMAT Struct
	wfx WAVEFORMATEX <>
	wSamplesPerBlock DW
EndS

NMS_VBXADPCMWAVEFORMAT Struct
	wfx WAVEFORMATEX <>
	wSamplesPerBlock DW
EndS

G721_ADPCMWAVEFORMAT Struct
	wfx WAVEFORMATEX <>
	nAuxBlockSize DW
EndS

MPEG1WAVEFORMAT Struct
	wfx WAVEFORMATEX <>
	fwHeadLayer DW
	dwHeadBitrate DD
	fwHeadMode DW
	fwHeadModeExt DW
	wHeadEmphasis DW
	fwHeadFlags DW
	dwPTSLow DD
	dwPTSHigh DD
EndS

#Define ACM_MPEG_LAYER1                     00001H
#Define ACM_MPEG_LAYER2                     00002H
#Define ACM_MPEG_LAYER3                     00004H
#Define ACM_MPEG_STEREO                     00001H
#Define ACM_MPEG_JOINTSTEREO                00002H
#Define ACM_MPEG_DUALCHANNEL                00004H
#Define ACM_MPEG_SINGLECHANNEL              00008H
#Define ACM_MPEG_PRIVATEBIT                 00001H
#Define ACM_MPEG_COPYRIGHT                  00002H
#Define ACM_MPEG_ORIGINALHOME               00004H
#Define ACM_MPEG_PROTECTIONBIT              00008H
#Define ACM_MPEG_ID_MPEG1                   00010H

#Define MPEGLAYER3_WFX_EXTRA_BYTES          12

MPEGLAYER3WAVEFORMAT Struct
	wfx WAVEFORMATEX <>
	wID DW
	fdwFlags DD
	nBlockSize DW
	nFramesPerBlock DW
	nCodecDelay DW
EndS

#Define MPEGLAYER3_ID_UNKNOWN               0
#Define MPEGLAYER3_ID_MPEG                  1
#Define MPEGLAYER3_ID_CONSTANTFRAMESIZE     2

#Define MPEGLAYER3_FLAG_PADDING_ISO         000000000H
#Define MPEGLAYER3_FLAG_PADDING_ON          000000001H
#Define MPEGLAYER3_FLAG_PADDING_OFF         000000002H

CREATIVEADPCMWAVEFORMAT Struct
	wfx WAVEFORMATEX <>
	wRevision DW
EndS

CREATIVEFASTSPEECH8WAVEFORMAT Struct
	wfx WAVEFORMATEX <>
	wRevision DW
EndS

CREATIVEFASTSPEECH10WAVEFORMAT Struct
	wfx WAVEFORMATEX <>
	wRevision DW
EndS

FMTOWNS_SND_WAVEFORMAT Struct
	wfx WAVEFORMATEX <>
	wRevision DW
EndS

OLIGSMWAVEFORMAT Struct
	wfx WAVEFORMATEX <>
EndS

OLIADPCMWAVEFORMAT Struct
	wfx WAVEFORMATEX <>
EndS

OLICELPWAVEFORMAT Struct
	wfx WAVEFORMATEX <>
EndS

OLISBCWAVEFORMAT Struct
	wfx WAVEFORMATEX <>
EndS

OLIOPRWAVEFORMAT Struct
	wfx WAVEFORMATEX <>
EndS

CSIMAADPCMWAVEFORMAT Struct
	wfx WAVEFORMATEX <>
EndS

#IFNDEF _ACM_WAVEFILTER
	#Define _ACM_WAVEFILTER                 1
	#Define WAVE_FILTER_UNKNOWN             00000H
	#Define WAVE_FILTER_DEVELOPMENT         0FFFFH

	WAVEFILTER Struct
		cbStruct DD
		dwFilterTag DD
		fdwFilter DD
		dwReserved DD 5 Dup ?
	EndS
#ENDIF

#IFNDEF WAVE_FILTER_VOLUME
	#Define WAVE_FILTER_VOLUME              00001H

	VOLUMEWAVEFILTER Struct
		wfltr WAVEFILTER <>
		dwVolume DD
	EndS
#ENDIF

#IFNDEF WAVE_FILTER_ECHO
	#Define WAVE_FILTER_ECHO                00002H

	ECHOWAVEFILTER Struct
		wfltr WAVEFILTER <>
		dwVolume DD
		dwDelay DD
	EndS
#ENDIF

#Define RIFFWAVE_inst                       A'inst'

RIFFWAVE_STRUCT Struct
	bUnshiftedNote DB
	chFineTune DB
	chGain DB
	bLowNote DB
	bHighNote DB
	bLowVelocity DB
	bHighVelocity DB
EndS

typedef struct tag_s_RIFFWAVE_INST s_RIFFWAVE_inst;

#Define RIFFCPPO                            A'CPPO'

#Define RIFFCPPO_objr                       A'objr'
#Define RIFFCPPO_obji                       A'obji'

#Define RIFFCPPO_clsr                       A'clsr'
#Define RIFFCPPO_clsi                       A'clsi'

#Define RIFFCPPO_mbr                        A'mbr '

#Define RIFFCPPO_char                       A'char'

#Define RIFFCPPO_byte                       A'byte'
#Define RIFFCPPO_int                        A'int '
#Define RIFFCPPO_word                       A'word'
#Define RIFFCPPO_long                       A'long'
#Define RIFFCPPO_dwrd                       A'dwrd'
#Define RIFFCPPO_flt                        A'flt '
#Define RIFFCPPO_dbl                        A'dbl '
#Define RIFFCPPO_str                        A'str '

#IFNDEF BI_BITFIELDS
	#Define BI_BITFIELDS                    3
#ENDIF

#IFNDEF QUERYDIBSUPPORT
	#Define QUERYDIBSUPPORT                 3073
	#Define QDI_SETDIBITS                   00001H
	#Define QDI_GETDIBITS                   00002H
	#Define QDI_DIBTOSCREEN                 00004H
	#Define QDI_STRETCHDIB                  00008H
#ENDIF

EXBMINFOHEADER Struct
	bmi BITMAPINFOHEADER <>
	biExtDataOffset DD
EndS

#Define BICOMP_IBMULTIMOTION                A'ULTI'
#Define BICOMP_IBMPHOTOMOTION               A'PHMO'
#Define BICOMP_CREATIVEYUV                  A'cyuv'

#Define JPEG_DIB                            A'JPEG'
#Define MJPG_DIB                            A'MJPG'

#Define JPEG_PROCESS_BASELINE               0

#Define AVIIF_CONTROLFRAME                  000000200H

#Define JIFMK_SOF0                          0FFC0H
#Define JIFMK_SOF1                          0FFC1H
#Define JIFMK_SOF2                          0FFC2H
#Define JIFMK_SOF3                          0FFC3H
#Define JIFMK_SOF5                          0FFC5H
#Define JIFMK_SOF6                          0FFC6H
#Define JIFMK_SOF7                          0FFC7H
#Define JIFMK_JPG                           0FFC8H
#Define JIFMK_SOF9                          0FFC9H
#Define JIFMK_SOF10                         0FFCAH
#Define JIFMK_SOF11                         0FFCBH
#Define JIFMK_SOF13                         0FFCDH
#Define JIFMK_SOF14                         0FFCEH
#Define JIFMK_SOF15                         0FFCFH
#Define JIFMK_DHT                           0FFC4H
#Define JIFMK_DAC                           0FFCCH
#Define JIFMK_RST0                          0FFD0H
#Define JIFMK_RST1                          0FFD1H
#Define JIFMK_RST2                          0FFD2H
#Define JIFMK_RST3                          0FFD3H
#Define JIFMK_RST4                          0FFD4H
#Define JIFMK_RST5                          0FFD5H
#Define JIFMK_RST6                          0FFD6H
#Define JIFMK_RST7                          0FFD7H
#Define JIFMK_SOI                           0FFD8H
#Define JIFMK_EOI                           0FFD9H
#Define JIFMK_SOS                           0FFDAH
#Define JIFMK_DQT                           0FFDBH
#Define JIFMK_DNL                           0FFDCH
#Define JIFMK_DRI                           0FFDDH
#Define JIFMK_DHP                           0FFDEH
#Define JIFMK_EXP                           0FFDFH
#Define JIFMK_APP0                          0FFE0H
#Define JIFMK_APP1                          0FFE1H
#Define JIFMK_APP2                          0FFE2H
#Define JIFMK_APP3                          0FFE3H
#Define JIFMK_APP4                          0FFE4H
#Define JIFMK_APP5                          0FFE5H
#Define JIFMK_APP6                          0FFE6H
#Define JIFMK_APP7                          0FFE7H
#Define JIFMK_JPG0                          0FFF0H
#Define JIFMK_JPG1                          0FFF1H
#Define JIFMK_JPG2                          0FFF2H
#Define JIFMK_JPG3                          0FFF3H
#Define JIFMK_JPG4                          0FFF4H
#Define JIFMK_JPG5                          0FFF5H
#Define JIFMK_JPG6                          0FFF6H
#Define JIFMK_JPG7                          0FFF7H
#Define JIFMK_JPG8                          0FFF8H
#Define JIFMK_JPG9                          0FFF9H
#Define JIFMK_JPG10                         0FFFAH
#Define JIFMK_JPG11                         0FFFBH
#Define JIFMK_JPG12                         0FFFCH
#Define JIFMK_JPG13                         0FFFDH
#Define JIFMK_COM                           0FFFEH
#Define JIFMK_TEM                           0FF01H
#Define JIFMK_RES                           0FF02H
#Define JIFMK_00                            0FF00H
#Define JIFMK_FF                            0FFFFH

#Define JPEG_Y                              1
#Define JPEG_YCbCr                          2
#Define JPEG_RGB                            3

JPEGINFOHEADER Struct
	JPEGSize DD
	JPEGProcess DD
	JPEGColorSpaceID DD
	JPEGBitsPerSample DD
	JPEGHSubSampling DD
	JPEGVSubSampling DD
EndS

#IFDEF MJPGDHTSEG_STORAGE

#Define MJPGHDTSEG_STORAGE                  0FFH, 0C4H, 001H, 0A2H, 000H, 000H, 001H, 005H, 001H, 001H, \
		                                    001H, 001H, 001H, 001H, 000H, 000H, 000H, 000H, 000H, 000H, \
		                                    000H, 000H, 001H, 002H, 003H, 004H, 005H, 006H, 007H, 008H, \
		                                    009H, 00AH, 00BH, 001H, 000H, 003H, 001H, 001H, 001H, 001H, \
		                                    001H, 001H, 001H, 001H, 001H, 000H, 000H, 000H, 000H, 000H, \
		                                    000H, 001H, 002H, 003H, 004H, 005H, 006H, 007H, 008H, 009H, \
		                                    00AH, 00BH, 010H, 000H, 002H, 001H, 003H, 003H, 002H, 004H, \
		                                    003H, 005H, 005H, 004H, 004H, 000H, 000H, 001H, 07DH, 001H, \
		                                    002H, 003H, 000H, 004H, 011H, 005H, 012H, 021H, 031H, 041H, \
		                                    006H, 013H, 051H, 061H, 007H, 022H, 071H, 014H, 032H, 081H, \
		                                    091H, 0A1H, 008H, 023H, 042H, 0B1H, 0C1H, 015H, 052H, 0D1H, \
		                                    0F0H, 024H, 033H, 062H, 072H, 082H, 009H, 00AH, 016H, 017H, \
		                                    018H, 019H, 01AH, 025H, 026H, 027H, 028H, 029H, 02AH, 034H, \
		                                    035H, 036H, 037H, 038H, 039H, 03AH, 043H, 044H, 045H, 046H, \
		                                    047H, 048H, 049H, 04AH, 053H, 054H, 055H, 056H, 057H, 058H, \
		                                    059H, 05AH, 063H, 064H, 065H, 066H, 067H, 068H, 069H, 06AH, \
		                                    073H, 074H, 075H, 076H, 077H, 078H, 079H, 07AH, 083H, 084H, \
		                                    085H, 086H, 087H, 088H, 089H, 08AH, 092H, 093H, 094H, 095H, \
		                                    096H, 097H, 098H, 099H, 09AH, 0A2H, 0A3H, 0A4H, 0A5H, 0A6H, \
		                                    0A7H, 0A8H, 0A9H, 0AAH, 0B2H, 0B3H, 0B4H, 0B5H, 0B6H, 0B7H, \
		                                    0B8H, 0B9H, 0BAH, 0C2H, 0C3H, 0C4H, 0C5H, 0C6H, 0C7H, 0C8H, \
		                                    0C9H, 0CAH, 0D2H, 0D3H, 0D4H, 0D5H, 0D6H, 0D7H, 0D8H, 0D9H, \
		                                    0DAH, 0E1H, 0E2H, 0E3H, 0E4H, 0E5H, 0E6H, 0E7H, 0E8H, 0E9H, \
		                                    0EAH, 0F1H, 0F2H, 0F3H, 0F4H, 0F5H, 0F6H, 0F7H, 0F8H, 0F9H, \
		                                    0FAH, 011H, 000H, 002H, 001H, 002H, 004H, 004H, 003H, 004H, \
		                                    007H, 005H, 004H, 004H, 000H, 001H, 002H, 077H, 000H, 001H, \
		                                    002H, 003H, 011H, 004H, 005H, 021H, 031H, 006H, 012H, 041H, \
		                                    051H, 007H, 061H, 071H, 013H, 022H, 032H, 081H, 008H, 014H, \
		                                    042H, 091H, 0A1H, 0B1H, 0C1H, 009H, 023H, 033H, 052H, 0F0H, \
		                                    015H, 062H, 072H, 0D1H, 00AH, 016H, 024H, 034H, 0E1H, 025H, \
		                                    0F1H, 017H, 018H, 019H, 01AH, 026H, 027H, 028H, 029H, 02AH, \
		                                    035H, 036H, 037H, 038H, 039H, 03AH, 043H, 044H, 045H, 046H, \
		                                    047H, 048H, 049H, 04AH, 053H, 054H, 055H, 056H, 057H, 058H, \
		                                    059H, 05AH, 063H, 064H, 065H, 066H, 067H, 068H, 069H, 06AH, \
		                                    073H, 074H, 075H, 076H, 077H, 078H, 079H, 07AH, 082H, 083H, \
		                                    084H, 085H, 086H, 087H, 088H, 089H, 08AH, 092H, 093H, 094H, \
		                                    095H, 096H, 097H, 098H, 099H, 09AH, 0A2H, 0A3H, 0A4H, 0A5H, \
		                                    0A6H, 0A7H, 0A8H, 0A9H, 0AAH, 0B2H, 0B3H, 0B4H, 0B5H, 0B6H, \
		                                    0B7H, 0B8H, 0B9H, 0BAH, 0C2H, 0C3H, 0C4H, 0C5H, 0C6H, 0C7H, \
		                                    0C8H, 0C9H, 0CAH, 0D2H, 0D3H, 0D4H, 0D5H, 0D6H, 0D7H, 0D8H, \
		                                    0D9H, 0DAH, 0E2H, 0E3H, 0E4H, 0E5H, 0E6H, 0E7H, 0E8H, 0E9H, \
		                                    0EAH, 0F2H, 0F3H, 0F4H, 0F5H, 0F6H, 0F7H, 0F8H, 0F9H, 0FAH

#IFNDEF ICTYPE_VIDEO
	#Define ICTYPE_VIDEO                    A'vidc'
	#Define ICTYPE_AUDIO                    A'audc'
#ENDIF

#Define FOURCC_RDSP                         A'RDSP'

#IFNDEF MMNOMIXER
	#Define MIXERCONTROL_CONTROLTYPE_SRS_MTS         (MIXERCONTROL_CONTROLTYPE_BOOLEAN + 6)
	#Define MIXERCONTROL_CONTROLTYPE_SRS_ONOFF       (MIXERCONTROL_CONTROLTYPE_BOOLEAN + 7)
	#Define MIXERCONTROL_CONTROLTYPE_SRS_SYNTHSELECT (MIXERCONTROL_CONTROLTYPE_BOOLEAN + 8)
#ENDIF

#ENDIF ;MMREG_INC
