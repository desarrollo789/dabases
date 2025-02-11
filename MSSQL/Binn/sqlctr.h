// @ File:  sqlctr.h
//
// This file is generated by the description file processor.
// Please do not edit.

#define MB_CLERK 0
#define MB_PERIODIC_EVICTIONS 2
#define MB_INTERNAL_BENEFIT 4
#define MB_SIMULATION_SIZE 6
#define MB_SIMULATION_BENEFIT 8
#define MB_CLERK_SIZE 10
#define MB_PRESSURE_EVICTIONS 12

#define BUFMGR_OBJECT 14
#define BUF_CACHE_HIT_RATIO 16
#define BUF_EXT_QUEUE_LENGTH 18
#define BUF_FREELIST_STALLS 20
#define BUF_EXT_EVICTIONS 22
#define BUF_BLOCK_WRITES 24
#define BUF_HASHED_PAGE_COUNT 26
#define BUF_EXT_UNREFERENCED_TIME 28
#define BUF_LIFE_EXPECTANCY 30
#define BUF_RECOVERY_WRITES 32
#define BUF_CACHE_RATIO_BASE 34
#define BUF_EXT_FREE_PAGE_COUNT 36
#define BUF_READAHEAD_MICROS 38
#define BUF_EXT_PAGE_COUNT 40
#define BUF_EXT_UTILIZATION 42
#define BUF_CHECKPOINT_WRITES 44
#define BUF_LAZY_WRITES 46
#define BUF_EXT_READS 48
#define BUF_BLOCK_READS 50
#define BUF_EXT_WRITES 52
#define BUF_READAHEAD_PAGES 54
#define BUF_SLOPE 56
#define BUF_TARGET_PAGE_COUNT 58
#define BUF_PAGE_REQUESTS 60

#define BUFNODE_OBJECT 62
#define BUFNODE_LOOKUPS_TO_REMOTE_NODE 64
#define BUFNODE_LIFE_EXPECTANCY 66
#define BUFNODE_HASHED_PAGE_COUNT 68
#define BUFNODE_LOOKUPS_TO_LOCAL_NODE 70

#define GENERAL_OBJECT 72
#define GO_MARS_DEADLOCKS_DETECTED 74
#define GO_SOAP_SESSION_INITIATES 76
#define GO_TRACE_EVT_NOTIF_QUEUE_SIZE 78
#define GO_SOAP_SESSION_TERMINATES 80
#define GO_USER_CONNECTIONS 82
#define GO_USERS_BLOCKED 84
#define GO_HTTP_AUTH_REQS 86
#define GO_TEMP_TABLES_CREATION_RATE 88
#define GO_RELOGINS 90
#define GO_TRANSACTIONS 92
#define GO_TEMP_TABLES_IN_USE 94
#define GO_TEMPDB_PRU_DUP_ID 96
#define GO_TEMPDB_ROWSET_DUP_ID 98
#define GO_TEMP_TABLES_FOR_DESTRUCTION 100
#define GO_LOGICAL_CONNECTIONS 102
#define GO_TRACE_IO_PROVIDER_EVENTLOCK 104
#define GO_NON_ATOMIC_YIELD_RATE 106
#define GO_SOAP_EMPTY_REQS 108
#define GO_LOGINS 110
#define GO_SOAP_WSDL_REQS 112
#define GO_SOAP_QUERY_REQS 114
#define GO_SOAP_SP_REQS 116
#define GO_LOGOUTS 118
#define GO_EVT_NOTIF_DELAYED_DROP 120

#define LOCKS_OBJECT 122
#define LCK_NUM_REQUESTS 124
#define LCK_NUM_TIMEOUTS 126
#define LCK_NUM_TIMEOUTS_NONPROBE 128
#define LCK_TOTAL_WAITTIME 130
#define LCK_NUM_DEADLOCKS 132
#define LCK_AVERAGE_WAITTIME_BASE 134
#define LCK_NUM_WAITS 136
#define LCK_AVERAGE_WAITTIME 138

#define DBMGR_OBJECT 140
#define DB_TOTAL_UPDATE_XTRAN 142
#define DB_CLOUDDB_PARTITIONS 144
#define DB_LOG_USED 146
#define DB_LOGPOOL_REQUESTS 148
#define DB_CLOUDDB_SECONDARY_PARTITIONS 150
#define DB_CLOUDDB_FWDPEND_PARTITIONS 152
#define DB_LOGPOOL_DISKREADS 154
#define DB_CLOUDDB_WAITING_COPIES 156
#define DB_GROUP_COMMIT_TIME 158
#define DB_CLOUDDB_DELETION_PARTITIONS 160
#define DB_FLUSH_WRITE_TIME 162
#define DB_BULK_ROWS 164
#define DB_LOG_WRITER_WRITES 166
#define DB_FLUSH_FILE_BUFFER_CALLS 168
#define DB_CLOUDDB_FWD_PARTITIONS 170
#define DB_LOG_GROWTHS 172
#define DB_LOG_TRUNCS 174
#define DB_BULK_KILOBYTES 176
#define DB_TOTAL_NOWAIT_XTRAN 178
#define DB_TOTAL_XTRAN 180
#define DB_DATA_SIZE 182
#define DB_REPLCOUNT 184
#define DB_XTP_MEMORY_USED 186
#define DB_CLOUDDB_NOTHING_PARTITIONS 188
#define DB_REPLTRANS 190
#define DB_ACT_XTRAN 192
#define DB_COMMIT_TABLE_SIZE 194
#define DB_LOGCACHE_RATIO 196
#define DB_FLUSH_WAIT_TIME 198
#define DB_FLUSH_WAITS 200
#define DB_LOGCACHE_READS 202
#define DB_DBCC_MOVERATE 204
#define DB_BYTES_FLUSHED 206
#define DB_LOG_USED_PERCENT 208
#define DB_LOG_Q_MICROS 210
#define DB_CHECKPOINT_DURATION 212
#define DB_CLOUDDB_PRIMARY_PARTITIONS 214
#define DB_TRACKED_XTRAN 216
#define DB_FLUSHES 218
#define DB_RECOVERY_DURATION 220
#define DB_DBCC_SCANRATE 222
#define DB_CLOUDDB_CATCHUP_PARTITIONS 224
#define DB_LOG_SIZE 226
#define DB_LOG_SHRINKS 228
#define DB_CLOUDDB_INBUILD_PARTITIONS 230
#define DB_LOGPOOL_CACHEMISSES 232
#define DB_BCK_DB_THROUGHPUT 234
#define DB_LOGCACHE_BASE 236

#define LC_OBJECT 238
#define LC_PAYLOAD_BYTES 240
#define LC_DEFUNCT_CLEANUPS 242
#define LC_QUEUE_TIME 244
#define LC_THROTTLED_WRITE_TIME 246
#define LC_DIRECT_TO_DATA 248
#define LC_LOG_LOOKUP_TIME 250
#define LC_READ_BYTES 252
#define LC_MAP_STALL_TIME 254
#define LC_READ_BYTES_FROM_LOG 256
#define LC_LOOKUP_TIME 258
#define LC_BACKGROUND_WRITES 260
#define LC_BACKGROUND_STALLS 262
#define LC_READ_BYTES_FROM_DATA 264
#define LC_SECTOR_MAPS 266
#define LC_QUEUE_DEPTH 268
#define LC_MAP_CLEARED_IN_MOVE 270
#define LC_MOVE_TO_DATA 272
#define LC_MAP_INDEX_IOS 274
#define LC_MAP_TABLE_IOS 276
#define LC_THROTTLED_WRITES 278
#define LC_HARDEN_TIME 280
#define LC_MAP_TIME 282

#define DBMIRRORING_OBJECT 284
#define DB_DBMIRRORING_SENDS 286
#define DB_DBM_COMP_LOG_BYTES_SENT 288
#define DB_DBM_ACK_TIME 290
#define DB_DBM_REDO_DELTA 292
#define DB_DBM_COMP_LOG_BYTES_RECEIVED 294
#define DB_DBM_LOG_SEND_QUEUE 296
#define DB_DBMIRRORING_BYTES_SENT 298
#define DB_DBM_LOG_BYTES_SENT 300
#define DB_DBM_LOG_UNDO_REMAINING 302
#define DB_DBM_RECEIVES 304
#define DB_DBM_LOG_HARDEN_TIME 306
#define DB_DBM_BYTES_RECEIVED 308
#define DB_DBM_LOG_FLOW_CONTROL 310
#define DB_DBM_LOG_SENT_FROM_CACHE 312
#define DB_DBM_LOG_REDONE_FROM_CACHE 314
#define DB_DBMIRRORING_TRANSACTION_DELAY 316
#define DB_DBM_UPDATE_XTRAN 318
#define DB_DBM_LOG_BYTES_RECEIVED 320
#define DB_DBM_LOG_UNDONE 322
#define DB_DBM_REDO_RATE 324
#define DB_DBMIRRORING_PAGES_SENT 326

#define HADR_DB_OBJECT 328
#define HADR_DB_LOG_QUEUE 330
#define HADR_DB_UNDO_LOG_REMAINING 332
#define HADR_DB_LOG_REDONE 334
#define HADR_DB_LOG_RECEIVED 336
#define HADR_DB_RECOVERY_QUEUE 338
#define HADR_DB_UPDATE_XTRAN 340
#define HADR_DB_REDO_BLOCKED 342
#define HADR_DB_FILEBYTES_RECEIVED 344
#define HADR_DB_TRANSACTION_DELAY 346
#define HADR_DB_REDO_REMAINING 348
#define HADR_DB_UNDO_LOG_TOTAL 350

#define HADR_OBJECT 352
#define HADR_SEND 354
#define HADR_FLOW_CONTROLS 356
#define HADR_RESENDS 358
#define HADR_FLOW_CONTROL_MS 360
#define HADR_BYTES_RECEIVED 362
#define HADR_BYTES_SENT_TRANSPORT 364
#define HADR_SEND_TRANSPORT 366
#define HADR_BYTES_SENT 368
#define HADR_RECEIVES 370

#define LATCH_OBJECT 372
#define LATCH_WAITS_NP 374
#define LATCH_DEMOTIONS 376
#define LATCH_TOTAL_WAIT_NP 378
#define LATCH_AVG_WAIT_BASE 380
#define LATCH_PROMOTIONS 382
#define LATCH_SUPERLATCHES 384
#define LATCH_AVG_WAIT_NP 386

#define ACCESS_METHODS_OBJECT 388
#define LEAF_PAGE_COOKIE_FAIL 390
#define AM_GHOSTED_SKIPS 392
#define AM_SCAN_REPOSITION 394
#define AM_DEFDROPPEDROWSETSCLEANED 396
#define AM_LOBSS_LOBHANDLES_CREATED 398
#define AM_ORPHANS_CREATED 400
#define AM_PROBE_SCAN 402
#define AM_LOB_READAHEAD_ISSUED 404
#define TREE_PAGE_COOKIE_SUCCEED 406
#define AM_WORKTABLES_FROM_CACHE_BASE 408
#define AM_EXTENTS_ALLOCATED 410
#define AM_COLS_PUSHED_OFFROW 412
#define AM_PAGE_COMPRESSION_SUCCESSES 414
#define AM_DDALLOCUNITBATCHESCOMPLETED 416
#define AM_WORKTABLES_FROM_CACHE 418
#define AM_RANGE_SCAN 420
#define AM_PAGE_COMPRESSION_ATTEMPTS 422
#define AM_COLS_PULLED_INROW 424
#define AM_DDALLOCUNITBATCHESFAILED 426
#define AM_FREESPACE_SCANS 428
#define TREE_PAGE_COOKIE_FAIL 430
#define AM_PAGE_DEALLOCS 432
#define AM_FULL_SCAN 434
#define AM_LOCKESCALATIONS 436
#define AM_FORWARDED_RECS 438
#define AM_ORPHANS_INSERTED 440
#define AM_DEFDROPPEDROWSETQUEUELENGTH 442
#define AM_PAGE_SPLITS 444
#define AM_INSYSXACT_WAITS 446
#define AM_LOBSS_PROVIDERS_TRUNCATED 448
#define AM_DEFDROPPEDROWSETSSKIPPED 450
#define LEAF_PAGE_COOKIE_SUCCEED 452
#define AM_FREESPACE_PAGES 454
#define AM_DDALLOCUNITQUEUELENGTH 456
#define AM_PAGES_ALLOCATED 458
#define AM_LOBSS_PROVIDERS_CREATED 460
#define AM_WORKFILES_CREATED 462
#define AM_EXTENTS_DEALLOCATED 464
#define AM_LOBSS_LOBHANDLES_DESTROYED 466
#define AM_INDEX_SEARCHES 468
#define AM_DDALLOCUNITSCLEANED 470
#define AM_SINGLE_PAGE_ALLOCS 472
#define AM_WORKTABLES_CREATED 474
#define AM_LOBSS_PROVIDERS_DESTROYED 476

#define SQL_ERROR_OBJECT 478
#define SQL_ERROR_RATE 480

#define SQL_OBJECT 482
#define SQL_AUTOPARAM_FAIL 484
#define SQL_AUTOPARAM_UNSAFE 486
#define PLAN_CACHE_MISGUIDED_PER_SEC 488
#define SQL_ATTENTION_RATE 490
#define SQL_UNIVPARAM 492
#define SQL_AUTOPARAM_SAFE 494
#define SQL_BATCH_REQ 496
#define PLAN_CACHE_GUIDED_PER_SEC 498
#define SQL_RECOMPILES 500
#define SQL_COMPILES 502
#define SQL_AUTOPARAM_REQ 504

#define PLAN_CACHE 506
#define PLAN_CACHE_OBJECT_COUNT 508
#define PLAN_CACHE_HIT_RATIO_BASE 510
#define PLAN_CACHE_PGS_IN_USE 512
#define PLAN_CACHE_HIT_RATIO 514
#define PLAN_CACHE_USE_COUNT 516

#define CURSOR_OBJECT_BY_TYPE 518
#define CURSOR_MEMORY_USAGE 520
#define CURSOR_CACHE_HIT_RATIO 522
#define CURSOR_CACHE_USE_COUNT 524
#define CURSOR_PLANS 526
#define CURSOR_CACHE_COUNT 528
#define CURSOR_REQ 530
#define CURSOR_CACHE_HIT_RATIO_BASE 532
#define CURSOR_WORKTABLE_USAGE 534
#define CURSOR_IN_USE 536

#define CURSOR_OBJECT_TOTAL 538
#define CURSOR_CONVERSION_RATE 540
#define CURSOR_XSTMT_FLUSH 542
#define CURSOR_ASYNC_POPULATION 544

#define MEMORY_OBJECT 546
#define MEMORY_SQL_CACHE_MEMORY 548
#define MEMORY_MEMGRANT_MAXIMUM 550
#define MEMORY_LOG_POOL_MEMORY 552
#define MEMORY_EXTERNAL_BENEFIT 554
#define MEMORY_SERVER_MEMORY_TARGET 556
#define MEMORY_SERVER_FREE 558
#define MEMORY_LOCKOWNERS_ALLOCATED 560
#define MEMORY_MEMGRANT_ACQUIRES 562
#define MEMORY_SERVER_MEMORY 564
#define MEMORY_LOCKS 566
#define MEMORY_SERVER_STOLEN 568
#define MEMORY_MEMGRANT_WAITERS 570
#define MEMORY_SERVER_DATABASE 572
#define MEMORY_LOCK_MEMORY 574
#define MEMORY_LOCKOWNERS 576
#define MEMORY_CONNECTION_MEMORY 578
#define MEMORY_LOCKS_ALLOCATED 580
#define MEMORY_OPTIMIZER_MEMORY 582
#define MEMORY_SERVER_RESERVED 584
#define MEMORY_MEMGRANT_OUTSTANDING 586

#define MEMNODE_OBJECT 588
#define MEMNODE_FOREIGN 590
#define MEMNODE_FREE 592
#define MEMNODE_TARGET 594
#define MEMNODE_DATABASE 596
#define MEMNODE_TOTAL 598
#define MEMNODE_STOLEN 600

#define USER_QUERY_OBJECT 602
#define QUERY_INSTANCE 604

#define REPLICATION_AGENT_OBJECT 606
#define RUNNING_INSTANCE 608

#define MERGE_AGENT_OBJECT 610
#define UPLOAD_INSTANCE 612
#define MERGE_CONFLICTS_INSTANCE 614
#define DOWNLOAD_INSTANCE 616

#define LOGREADER_AGENT_OBJECT 618
#define LOGREADER_COMMANDS_INSTANCE 620
#define LOGREADER_LATENCY_INSTANCE 622
#define LOGREADER_TRANSACTIONS_INSTANCE 624

#define DISTRIBUTION_AGENT_OBJECT 626
#define DISTRIBUTION_TRANS_INSTANCE 628
#define DISTRIBUTION_COMMANDS_INSTANCE 630
#define DISTRIBUTION_LATENCY_INSTANCE 632

#define SNAPSHOT_AGENT_OBJECT 634
#define SNAPSHOT_TRANSACTIONS_BCPED 636
#define SNAPSHOT_COMMANDS_BCPED 638

#define BACKUP_DEV_OBJECT 640
#define BACKUP_DEV_THROUGHPUT 642

#define XACT_OBJECT 644
#define XACT_VER_STORE_SIZE 646
#define XACT_LONGEST_RUNNING 648
#define XACT_NUM 650
#define XACT_VER_STORE_UNIT_TRUNCATION 652
#define XACT_NSNP_VER_NUM 654
#define XACT_SNP_NUM 656
#define XACT_UPD_SNP_NUM 658
#define XACT_VER_STORE_UNIT_COUNT 660
#define XACT_VER_STORE_UNIT_CREATION 662
#define XACT_VER_STORE_GEN_RATE 664
#define XACT_VER_STORE_CLEANUP_RATE 666
#define XACT_TEMPDB_FREE_SPACE 668
#define XACT_UPD_CONFLICTS_RATIO 670
#define XACT_UPD_CONFLICTS_RATIO_BASE 672

#define BROKER_OBJECT 674
#define BO_ENQUEUED_PRI8_MSG_RATE 676
#define BO_ENQUEUED_PRI3_MSG_RATE 678
#define BO_ENQUEUED_PRI7_MSG_RATE 680
#define BO_ENQUEUED_TRANSPORT_FRAG_RATE 682
#define BO_ENQUEUED_PRI4_MSG_RATE 684
#define BO_TOTAL_SENDS 686
#define BO_ENQUEUED_TRANSPORT_FRAGS_TOT 688
#define BO_RECEIVE_RATE 690
#define BO_ENQUEUED_MSGS_TOTAL 692
#define BO_ENQUEUED_PRI10_MSG_RATE 694
#define BO_CORRUPTED_MSGS 696
#define BO_XMITQ_DEQUEUE_RATE 698
#define BO_ENQUEUED_MSG_RATE 700
#define BO_SEND_RATE 702
#define BO_FORWARDED_DISCARDED_MSG_TOTAL 704
#define BO_DEP_TIMER_EVENTS 706
#define BO_ACTIVATION_EXCEPTIONS 708
#define BO_XMITQ_ENQUEUE_RATE 710
#define BO_FORWARDED_MSG_BYTE_RATE 712
#define BO_FORWARDED_PENDING_MSGS 714
#define BO_DROPPED_MSGS 716
#define BO_TOTAL_RECEIVES 718
#define BO_ENQUEUED_TRANSPORT_MSG_RATE 720
#define BO_ENQUEUED_LOCAL_MSGS_TOTAL 722
#define BO_ENQUEUED_PRI1_MSG_RATE 724
#define BO_XACT_ROLLBACKS 726
#define BO_ENQUEUED_PRI9_MSG_RATE 728
#define BO_FORWARDED_PENDING_MSG_BYTES 730
#define BO_FORWARDED_MSG_TOTAL 732
#define BO_ENQUEUED_PRI6_MSG_RATE 734
#define BO_ENQUEUED_LOCAL_MSG_RATE 736
#define BO_FORWARDED_MSG_RATE 738
#define BO_FORWARDED_DISCARDED_MSG_RATE 740
#define BO_ENQUEUED_PRI5_MSG_RATE 742
#define BO_ENQUEUED_TRANSPORT_MSGS_TOTAL 744
#define BO_FORWARDED_MSG_BYTE_TOTAL 746
#define BO_ENQUEUED_PRI2_MSG_RATE 748

#define BROKER_TRANSPORT_OBJECT 750
#define BTO_RECV_FRAG_SIZE_AVG 752
#define BTO_SEND_IO_CURR_FRAG_COUNT 754
#define BTO_SEND_FRAG_RATE 756
#define BTO_SEND_IO_RATE 758
#define BTO_RECEIVE_IO_BYTE_RATE 760
#define BTO_SEND_FRAG_RATE_PRI6 762
#define BTO_SEND_FRAG_RATE_PRI7 764
#define BTO_SEND_IO_LEN_AVG 766
#define BTO_SEND_FRAG_RATE_PRI5 768
#define BTO_SEND_FRAG_SIZE_AVG 770
#define BTO_OPEN_CONNECTIONS 772
#define BTO_SEND_IO_BYTE_RATE 774
#define BTO_SEND_FRAG_RATE_PRI4 776
#define BTO_RECV_IO_COMPACT_MFB 778
#define BTO_RECV_IO_LEN_AVG 780
#define BTO_SEND_IO_LEN_AVG_BASE 782
#define BTO_SEND_FRAG_SIZE_AVG_BASE 784
#define BTO_RECV_IO_LEN_AVG_BASE 786
#define BTO_SEND_FRAG_RATE_PRI1 788
#define BTO_SEND_FRAG_RATE_PRI2 790
#define BTO_RECV_IO_PEND_BYTES 792
#define BTO_RECEIVE_FRAG_RATE 794
#define BTO_RECV_FRAG_SIZE_AVG_BASE 796
#define BTO_SEND_FRAG_RATE_PRI3 798
#define BTO_SEND_FRAG_RATE_PRI9 800
#define BTO_SEND_IO_CURR_BYTES 802
#define BTO_SEND_FRAG_RATE_PRI8 804
#define BTO_RECV_IO_PEND_FRAG_COUNT 806
#define BTO_RECEIVE_IO_RATE 808
#define BTO_SEND_FRAG_RATE_PRI10 810
#define BTO_SEND_IO_PEND_BYTES 812
#define BTO_RECV_IO_COMPACT_MFB_RATE 814
#define BTO_SEND_IO_PEND_FRAG_COUNT 816
#define BTO_RECV_IO_CURR_BYTES 818

#define BROKER_ACTIVATION_OBJECT 820
#define BAO_TASK_LIMIT_RATE 822
#define BAO_TASK_LIMIT_REACHED 824
#define BAO_TASKS_RUNNING 826
#define BAO_SP_INVOKE_RATE 828
#define BAO_TASK_ABORT_RATE 830
#define BAO_TASK_START_RATE 832

#define BROKER_TRANSMISSION_OBJECT 834
#define BTO_WRITE_RATE 836
#define BTO_WRITE_BATCH_LEN 838
#define BTO_WRITE_BATCH_TIME 840
#define BTO_WAIT_BATCH_TIME_BASE 842
#define BTO_WAIT_BATCH_TIME 844
#define BTO_WRITE_BATCH_LEN_BASE 846
#define BTO_DIRTY_RATE 848
#define BTO_GET_RATE 850
#define BTO_WRITE_BATCH_TIME_BASE 852

#define WAITSTATS_OBJECT 854
#define WAITSTATS_XACTWORKSPACE 856
#define WAITSTATS_NPAGELATCH 858
#define WAITSTATS_PAGELATCH 860
#define WAITSTATS_MEMTHREAD 862
#define WAITSTATS_PAGEIOLATCH 864
#define WAITSTATS_SOS_WORKER 866
#define WAITSTATS_WRITELOG 868
#define WAITSTATS_TRANSACTION 870
#define WAITSTATS_LOCKS 872
#define WAITSTATS_NETWORKIO 874
#define WAITSTATS_RESOURCE 876
#define WAITSTATS_LOGBUFFER 878

#define EXECSTATS_OBJECT 880
#define EXECSTATS_OLEDB 882
#define EXECSTATS_DQ 884
#define EXECSTATS_DTC 886
#define EXECSTATS_MSQL_XP 888

#define SQLCLR_OBJECT 890
#define SQLCLR_TOTAL_EXECTIME 892

#define METADATAMGR_OBJECT 894
#define MD_CACHE_ENTRY_COUNT 896
#define MD_CACHE_HIT_RATIO 898
#define MD_CACHE_HIT_RATIO_BASE 900
#define MD_CACHE_PINNED_COUNT 902

#define CLOUD_MSG_OBJECT 904
#define CLOUD_MSG_RECV_RATE 906
#define CLOUD_MSG_SENT_BYTES_RATE 908
#define CLOUD_MSG_SENT_RATE 910
#define CLOUD_MSG_RECV_BYTES_RATE 912

#define CLOUD_REPL_OBJECT 914
#define CLOUD_REPL_ACTIVE_DELETE_SCANS 916
#define CLOUD_REPL_QUEUE_SIZE 918
#define CLOUD_REPL_PENDING_COPY_SCANS 920
#define CLOUD_REPL_ACTIVE_COPY_SCANS 922
#define CLOUD_REPL_PENDING_DELETE_SCANS 924
#define CLOUD_REPL_ACTIVE_CATCHUP_SCANS 926
#define CLOUD_REPL_COMMIT_SECONDARY 928
#define CLOUD_REPL_COMMIT_PRIMARY 930

#define TRACE_STATISTICS 932
#define TS_DROPPED_EVENTS 934
#define TS_BYTES 936
#define TS_EVENTS_FIRED 938
#define TS_EVENTS_FILTERED 940

#define TRACE_EVENT_STATISTICS 942
#define TES_EVENTS_FILTERED 944
#define TES_EVENTS_PREFILTERED 946
#define TES_CPU_USAGE 948
#define TES_BYTES 950
#define TES_EVENTS_FIRED 952

#define DEPRECATED_FEATURES 954
#define DEPR_USAGE 956

#define RESOURCE_GROUP_STATISTICS 958
#define RGS_QUEUED_REQUESTS 960
#define RGS_READS_STALL_BASE 962
#define RGS_REQUESTS_COMPLETED 964
#define RGS_VIOLATIONS 966
#define RGS_READS_BYTES 968
#define RGS_WRITES_STALL 970
#define RGS_SUBOPTIMAL_PLANS 972
#define RGS_MAX_REQUEST_MEMGRANT 974
#define RGS_CPU_USAGE_BASE 976
#define RGS_READS_STALL 978
#define RGS_ACTIVE_PARALLEL_THREADS 980
#define RGS_WRITES_STALL_BASE 982
#define RGS_WRITES_BYTES 984
#define RGS_ACTIVE_REQUESTS 986
#define RGS_QUERY_OPTIMIZATIONS 988
#define RGS_READS_COMPLETED 990
#define RGS_CPU_USAGE 992
#define RGS_REDUCED_MEMGRANTS_COUNT 994
#define RGS_WRITES_COMPLETED 996
#define RGS_BLOCKED_TASKS 998
#define RGS_MAX_REQUEST_CPU 1000

#define RESOURCE_POOL_STATISTICS 1002
#define RPS_WRITES_THROTTLED 1004
#define RPS_MAX_MEMORY 1006
#define RPS_QUERY_EXEC_MEMORY_TARGET 1008
#define RPS_TARGET_MEMORY 1010
#define RPS_MEMORY_GRANTS_COUNT 1012
#define RPS_CPU_USAGE 1014
#define RPS_READS_THROTTLED 1016
#define RPS_ACTIVE_MEMGRANT 1018
#define RPS_WRITES_BYTES 1020
#define RPS_ACTIVE_MEMGRANTS_COUNT 1022
#define RPS_CPU_USAGE_PROJECTED 1024
#define RPS_CPU_USAGE_NONGOVERNED 1026
#define RPS_WRITES_STALL 1028
#define RPS_READS_STALL_BASE 1030
#define RPS_MEMORY_USAGE 1032
#define RPS_READS_ISSUED 1034
#define RPS_WRITES_ISSUED 1036
#define RPS_WRITES_COMPLETED 1038
#define RPS_READS_STALL 1040
#define RPS_CACHE_MEMORY_TARGET 1042
#define RPS_PENDING_MEMGRANTS 1044
#define RPS_COMPILE_MEMORY_TARGET 1046
#define RPS_CPU_USAGE_BASE 1048
#define RPS_MEMORY_GRANT_TIMEOUT 1050
#define RPS_READS_BYTES 1052
#define RPS_WRITES_STALL_BASE 1054
#define RPS_READS_COMPLETED 1056

#define TCM_STATISTICS 1058
#define AGE_HARDEN_TIME_BASE 1060
#define AGE_HARDEN_TIME 1062
#define AGE_RESPONSES 1064
#define AGE_LIFETIME_BASE 1066
#define ORDERS_BROADCAST 1068
#define AGE_LIFETIME 1070
#define AGE_SIZE_BASE 1072
#define AGE_BROADCASTS 1074
#define AGE_SIZE 1076

#define TCMA_STATISTICS 1078
#define MATRIX_XACT_STARTED 1080
#define MXACT_PARTICIPANTS 1082
#define AGE_PROCESSING_TIME 1084
#define XACTION_REQUESTS_PER_AGE_BASE 1086
#define AGE_PROCESSING_TIME_BASE 1088
#define XACTION_COMMITED_PER_AGE 1090
#define XACTION_REQUESTS_PER_AGE 1092
#define COMMIT_WAITTIME 1094
#define TRANSACTION_PREPARE_TIME 1096
#define MATRIX_XACT_COMMITTED 1098
#define MXACT_BRANCHES 1100
#define COMMIT_WAITTIME_BASE 1102
#define XACTION_COMMITED_PER_AGE_BASE 1104
#define MATRIX_XACT_ROLLEDBACK 1106
#define TRANSACTION_PREPARE_TIME_BASE 1108

#define FILETABLE_STATISTICS 1110
#define FILETABLE_ENUMERATION_REQUESTS 1112
#define FILETABLE_FILEIO_REQ_TIME_BASE 1114
#define FILETABLE_ENUMERATION_TIME 1116
#define FILETABLE_FILEIO_RESP_TIME_BASE 1118
#define FILETABLE_ITEM_RENAME_TIME 1120
#define FILETABLE_FILEIO_RESPONSES 1122
#define FILETABLE_ITEM_MOVE_TIME 1124
#define FILETABLE_TABLE_OPERATIONS 1126
#define FILETABLE_HANDLE_KILL_OPERATIONS 1128
#define FILETABLE_ITEM_RENAME_REQUESTS 1130
#define FILETABLE_ITEM_DELETE_TIME_BASE 1132
#define FILETABLE_HANDLE_KILL_TIME_BASE 1134
#define FILETABLE_FILEIO_REQ_TIME 1136
#define FILETABLE_FILEIO_RESP_TIME 1138
#define FILETABLE_ENUMERATION_TIME_BASE 1140
#define FILETABLE_ITEM_UPDATE_TIME_BASE 1142
#define FILETABLE_ITEM_GET_REQUESTS 1144
#define FILETABLE_ITEM_GET_REQ_TIME 1146
#define FILETABLE_ITEM_MOVE_REQUESTS 1148
#define FILETABLE_FILEIO_REQUESTS 1150
#define FILETABLE_ITEM_MOVE_TIME_BASE 1152
#define FILETABLE_HANDLE_KILL_TIME 1154
#define FILETABLE_ITEM_GET_REQ_TIME_BASE 1156
#define FILETABLE_DATABASE_OPERATIONS 1158
#define FILETABLE_ITEM_UPDATE_TIME 1160
#define FILETABLE_ITEM_DELETE_REQUESTS 1162
#define FILETABLE_ITEM_UPDATE_REQUESTS 1164
#define FILETABLE_ITEM_DELETE_TIME 1166
#define FILETABLE_ITEM_RENAME_TIME_BASE 1168

#define SQL_BATCH_RESPONSE_TIME 1170
#define SQL_BATCH_RES_10 1172
#define SQL_BATCH_RES_2 1174
#define SQL_BATCH_RES_100S 1176
#define SQL_BATCH_RES_50S 1178
#define SQL_BATCH_RES_5S 1180
#define SQL_BATCH_RES_500 1182
#define SQL_BATCH_RES_0 1184
#define SQL_BATCH_RES_1 1186
#define SQL_BATCH_RES_50 1188
#define SQL_BATCH_RES_5 1190
#define SQL_BATCH_RES_20S 1192
#define SQL_BATCH_RES_100 1194
#define SQL_BATCH_RES_2S 1196
#define SQL_BATCH_RES_10S 1198
#define SQL_BATCH_RES_200 1200
#define SQL_BATCH_RES_20 1202
#define SQL_BATCH_RES_1S 1204

#define SOFT_ENGINE_THROTTLING_PARTITION 1206
#define ST_DATA_READ_IO_DELAY 1208
#define ST_LOG_WRITE_IO_DELAY 1210
#define ST_DATA_SPACE 1212
#define ST_BUSY_WORKERS 1214
#define ST_LOG_SPACE 1216

#define HARD_ENGINE_THROTTLING_PARTITION 1218
#define HT_LOG_WRITE_IO_DELAY 1220
#define HT_LOG_SPACE 1222
#define HT_DATA_SPACE 1224
#define HT_DATA_READ_IO_DELAY 1226
#define HT_BUSY_WORKERS 1228

#define HTTP_STORAGE_OBJECT 1230
#define HSO_uSEC_PER_READ_BASE 1232
#define HSO_TRANSFERS 1234
#define HSO_BYTES_PER_WRITE_BASE 1236
#define HSO_REQUEST_RETRY 1238
#define HSO_BYTES_PER_READ 1240
#define HSO_uSEC_PER_WRITE_BASE 1242
#define HSO_READS 1244
#define HSO_uSEC_PER_READ 1246
#define HSO_BYTES_PER_TRANSFER_BASE 1248
#define HSO_TOTAL_BYTES 1250
#define HSO_uSEC_PER_TRANSFER 1252
#define HSO_READ_BYTES 1254
#define HSO_uSEC_PER_WRITE 1256
#define HSO_WRITE_BYTES 1258
#define HSO_WRITES 1260
#define HSO_BYTES_PER_WRITE 1262
#define HSO_BYTES_PER_READ_BASE 1264
#define HSO_uSEC_PER_TRANSFER_BASE 1266
#define HSO_OUTSTANDING_IO 1268
#define HSO_BYTES_PER_TRANSFER 1270
