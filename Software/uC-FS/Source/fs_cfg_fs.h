/*
*********************************************************************************************************
*                                             uC/FS V4
*                                     The Embedded File System
*
*                         (c) Copyright 2008-2010; Micrium, Inc.; Weston, FL
*
*               All rights reserved. Protected by international copyright laws.
*
*               uC/FS is provided in source form to registered licensees ONLY.  It is
*               illegal to distribute this source code to any third party unless you receive
*               written permission by an authorized Micrium representative.  Knowledge of
*               the source code may NOT be used to develop a similar product.
*
*               Please help us continue to provide the Embedded community with the finest
*               software available.  Your honesty is greatly appreciated.
*
*               You can contact us at www.micrium.com.
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*
*                                      FILE SYSTEM CONFIGURATION
*
* Filename      : fs_cfg_fs.h
* Version       : V4.04
* Programmer(s) : AHFAI
*                 FBJ
*                 BAN
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                          FILE SYSTEM BUILD
*
* Note(s) : (1) Configure FS_CFG_BUILD to select file system build :
*               (a) When FS_BUILD_FULL, the full file system is included in the build.  Generally,
*                   this should be selected.
*               (b) When FS_BUILD_DEV_ONLY, only the device access functions are included in the
*                   build; devices can be read & written.  No volume, file or directory functionality
*                   will be included.
*********************************************************************************************************
*/

                                                                /* Configure file system build (see Note #1) :          */
#define  FS_CFG_BUILD                       FS_BUILD_FULL       /* FS_BUILD_FULL          Full file system build.       */
                                                                /* FS_BUILD_DEV_ONLY      Device-only build.            */

/*
*********************************************************************************************************
*                                         BUILD CONFIGURATION
*********************************************************************************************************
*/

#ifdef   FS_CFG_BUILD
#if     (FS_CFG_BUILD == FS_BUILD_FULL)
#define  FS_FILE_SYSTEM_BUILD_FULL
#endif
#endif

/*
*********************************************************************************************************
*                               FILE SYSTEM BUILD CONFIGURATION ERRORS
*********************************************************************************************************
*/

#ifndef  FS_CFG_BUILD
#error  "FS_CFG_BUILD                                 not #define'd in 'fs_cfg.h'               "
#error  "                                       [MUST be  FS_BUILD_FULL    ]                    "
#error  "                                       [     ||  FS_BUILD_DEV_ONLY]                    "

#elif  ((FS_CFG_BUILD != FS_BUILD_FULL) && \
        (FS_CFG_BUILD != FS_BUILD_DEV_ONLY))
#error  "FS_CFG_BUILD                           illegally #define'd in 'fs_cfg.h'               "
#error  "                                       [MUST be  FS_BUILD_FULL    ]                    "
#error  "                                       [     ||  FS_BUILD_DEV_ONLY]                    "
#endif


/*
*********************************************************************************************************
*********************************************************************************************************
*                                             ALL BUILDS
*********************************************************************************************************
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                           FILE SYSTEM ERROR CHECKING CONFIGURATION ERRORS
*********************************************************************************************************
*/

                                                                /* ------------- FS_CFG_ERR_ARG_CHK_EXT_EN ------------ */
#ifndef  FS_CFG_ERR_ARG_CHK_EXT_EN
#error  "FS_CFG_ERR_ARG_CHK_EXT_EN                    not #define'd in 'fs_cfg.h'               "
#error  "                                       [MUST be  DEF_DISABLED]                         "
#error  "                                       [     ||  DEF_ENABLED ]                         "

#elif  ((FS_CFG_ERR_ARG_CHK_EXT_EN != DEF_DISABLED) && \
        (FS_CFG_ERR_ARG_CHK_EXT_EN != DEF_ENABLED ))
#error  "FS_CFG_ERR_ARG_CHK_EXT_EN              illegally #define'd in 'fs_cfg.h'               "
#error  "                                       [MUST be  DEF_DISABLED]                         "
#error  "                                       [     ||  DEF_ENABLED ]                         "
#endif



                                                                /* ------------- FS_CFG_ERR_ARG_CHK_DBG_EN ------------ */
#ifndef  FS_CFG_ERR_ARG_CHK_DBG_EN
#error  "FS_CFG_ERR_ARG_CHK_DBG_EN                    not #define'd in 'fs_cfg.h'               "
#error  "                                       [MUST be  DEF_DISABLED]                         "
#error  "                                       [     ||  DEF_ENABLED ]                         "

#elif  ((FS_CFG_ERR_ARG_CHK_DBG_EN != DEF_DISABLED) && \
        (FS_CFG_ERR_ARG_CHK_DBG_EN != DEF_ENABLED ))
#error  "FS_CFG_ERR_ARG_CHK_DBG_EN              illegally #define'd in 'fs_cfg.h'               "
#error  "                                       [MUST be  DEF_DISABLED]                         "
#error  "                                       [     ||  DEF_ENABLED ]                         "
#endif

/*
*********************************************************************************************************
*                              FILE SYSTEM COUNTER CONFIGURATION ERRORS
*********************************************************************************************************
*/

                                                                /* ---------------- FS_CFG_CTR_STAT_EN ---------------- */
#ifndef  FS_CFG_CTR_STAT_EN
#error  "FS_CFG_CTR_STAT_EN                           not #define'd in 'fs_cfg.h'               "
#error  "                                       [MUST be  DEF_DISABLED]                         "
#error  "                                       [     ||  DEF_ENABLED ]                         "

#elif  ((FS_CFG_CTR_STAT_EN != DEF_DISABLED) && \
        (FS_CFG_CTR_STAT_EN != DEF_ENABLED ))
#error  "FS_CFG_CTR_STAT_EN                     illegally #define'd in 'fs_cfg.h'               "
#error  "                                       [MUST be  DEF_DISABLED]                         "
#error  "                                       [     ||  DEF_ENABLED ]                         "
#endif



                                                                /* ----------------- FS_CFG_CTR_ERR_EN ---------------- */
#ifndef  FS_CFG_CTR_ERR_EN
#error  "FS_CFG_CTR_ERR_EN                            not #define'd in 'fs_cfg.h'               "
#error  "                                       [MUST be  DEF_DISABLED]                         "
#error  "                                       [     ||  DEF_ENABLED ]                         "

#elif  ((FS_CFG_CTR_ERR_EN != DEF_DISABLED) && \
        (FS_CFG_CTR_ERR_EN != DEF_ENABLED ))
#error  "FS_CFG_CTR_ERR_EN                      illegally #define'd in 'fs_cfg.h'               "
#error  "                                       [MUST be  DEF_DISABLED]                         "
#error  "                                       [     ||  DEF_ENABLED ]                         "
#endif

/*
*********************************************************************************************************
*                               FILE SYSTEM DEBUG CONFIGURATION ERRORS
*********************************************************************************************************
*/

                                                                /* --------------- FS_CFG_DBG_MEM_CLR_EN -------------- */
#ifndef  FS_CFG_DBG_MEM_CLR_EN
#error  "FS_CFG_DBG_MEM_CLR_EN                        not #define'd in 'fs_cfg.h'               "
#error  "                                       [MUST be  DEF_DISABLED]                         "
#error  "                                       [     ||  DEF_ENABLED ]                         "

#elif  ((FS_CFG_DBG_MEM_CLR_EN != DEF_DISABLED) && \
        (FS_CFG_DBG_MEM_CLR_EN != DEF_ENABLED ))
#error  "FS_CFG_DBG_MEM_CLR_EN                  illegally #define'd in 'fs_cfg.h'               "
#error  "                                       [MUST be  DEF_DISABLED]                         "
#error  "                                       [     ||  DEF_ENABLED ]                         "
#endif



                                                                /* -------------- FS_CFG_DBG_WR_VERIFY_EN ------------- */
#ifndef  FS_CFG_DBG_WR_VERIFY_EN
#error  "FS_CFG_DBG_WR_VERIFY_EN                      not #define'd in 'fs_cfg.h'               "
#error  "                                       [MUST be  DEF_DISABLED]                         "
#error  "                                       [     ||  DEF_ENABLED ]                         "

#elif  ((FS_CFG_DBG_WR_VERIFY_EN != DEF_DISABLED) && \
        (FS_CFG_DBG_WR_VERIFY_EN != DEF_ENABLED ))
#error  "FS_CFG_DBG_WR_VERIFY_EN                illegally #define'd in 'fs_cfg.h'               "
#error  "                                       [MUST be  DEF_DISABLED]                         "
#error  "                                       [     ||  DEF_ENABLED ]                         "
#endif

/*
*********************************************************************************************************
*                                EXTERNAL MODULE CONFIGURATION ERRORS
*********************************************************************************************************
*/

#ifndef  LIB_MEM_CFG_ALLOC_EN
#error  "LIB_MEM_CFG_ALLOC_EN                         not #define'd in 'app_cfg.h'              "
#error  "                                       [MUST be  DEF_ENABLED]                          "

#elif   (LIB_MEM_CFG_ALLOC_EN != DEF_ENABLED)
#error  "LIB_MEM_CFG_ALLOC_EN                   illegally #define'd in 'app_cfg.h'              "
#error  "                                       [MUST be  DEF_ENABLED]                          "
#endif

/*
*********************************************************************************************************
*********************************************************************************************************
*                                           ALL BUILDS END
*********************************************************************************************************
*********************************************************************************************************
*/




#ifndef  FS_FILE_SYSTEM_BUILD_FULL
/*
*********************************************************************************************************
*********************************************************************************************************
*                                         DEVICE ONLY BUILD
*********************************************************************************************************
*********************************************************************************************************
*/
#ifdef   FS_CFG_DBG_WR_VERIFY_EN
#undef   FS_CFG_DBG_WR_VERIFY_EN
#define  FS_CFG_DBG_WR_VERIFY_EN    DEF_DISABLED
#endif

#ifdef   FS_CFG_FILE_LOCK_EN
#undef   FS_CFG_FILE_LOCK_EN
#define  FS_CFG_FILE_LOCK_EN        DEF_DISABLED
#endif


                                                                /* ------------ FS_CFG_MAX_DEV_DRV_NAME_LEN ----------- */
#ifndef  FS_CFG_MAX_DEV_DRV_NAME_LEN
#error  "FS_CFG_MAX_DEV_DRV_NAME_LEN                  not #define'd in 'fs_cfg.h'               "
#error  "                                       [MUST be  >= 1]                                 "

#elif   (FS_CFG_MAX_DEV_DRV_NAME_LEN < 1u)
#error  "FS_CFG_MAX_DEV_DRV_NAME_LEN            illegally #define'd in 'fs_cfg.h'               "
#error  "                                       [MUST be  >= 1]                                 "

#elif   (FS_CFG_MAX_DEV_DRV_NAME_LEN > FS_FILE_NAME_LEN_MAX)
#error  "FS_CFG_MAX_DEV_DRV_NAME_LEN            illegally #define'd in 'fs_cfg.h'               "
#error  "                                       [MUST be  >= 1]                                 "
#endif



                                                                /* -------------- FS_CFG_MAX_DEV_NAME_LEN ------------- */
#ifndef  FS_CFG_MAX_DEV_NAME_LEN
#error  "FS_CFG_MAX_DEV_NAME_LEN                      not #define'd in 'fs_cfg.h'               "
#error  "                                       [MUST be  >= 1]                                 "

#elif   (FS_CFG_MAX_DEV_NAME_LEN < 1u)
#error  "FS_CFG_MAX_DEV_NAME_LEN                illegally #define'd in 'fs_cfg.h'               "
#error  "                                       [MUST be  >= 1]                                 "

#elif   (FS_CFG_MAX_DEV_NAME_LEN < FS_CFG_MAX_DEV_DRV_NAME_LEN + 3u)
#error  "FS_CFG_MAX_DEV_NAME_LEN                illegally #define'd in 'fs_cfg.h'               "
#error  "                                       [MUST be  >= FS_CFG_MAX_DEV_DRV_NAME_LEN + 3]   "

#elif   (FS_CFG_MAX_DEV_NAME_LEN > FS_CFG_MAX_DEV_DRV_NAME_LEN + 5u)
#error  "FS_CFG_MAX_DEV_NAME_LEN                illegally #define'd in 'fs_cfg.h'               "
#error  "                                       [MUST be  <= FS_CFG_MAX_DEV_DRV_NAME_LEN + 5]   "
#endif

/*
*********************************************************************************************************
*********************************************************************************************************
*                                       DEVICE ONLY BUILD END
*********************************************************************************************************
*********************************************************************************************************
*/
#endif



#ifdef  FS_FILE_SYSTEM_BUILD_FULL
/*
*********************************************************************************************************
*********************************************************************************************************
*                                             FULL BUILD
*********************************************************************************************************
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                                      FILE SYSTEM CONFIGURATION
*********************************************************************************************************
*/

#ifdef   FS_CFG_SYS_DRV_SEL
#if     (FS_CFG_SYS_DRV_SEL == FS_SYS_DRV_SEL_FAT)
#define  FS_FAT_MODULE_PRESENT
#endif
#endif


#ifdef   FS_CFG_CACHE_EN
#if     (FS_CFG_CACHE_EN    == DEF_ENABLED)
#define  FS_CACHE_MODULE_PRESENT
#endif
#endif


#ifdef   FS_CFG_API_EN
#if     (FS_CFG_API_EN      == DEF_ENABLED)
#define  FS_API_MODULE_PRESENT
#endif
#endif


#ifdef   FS_CFG_DIR_EN
#if     (FS_CFG_DIR_EN      == DEF_ENABLED)
#define  FS_DIR_MODULE_PRESENT
#endif
#endif


#ifdef   FS_FAT_MODULE_PRESENT
#if     (FS_FAT_CFG_LFN_EN   == DEF_ENABLED)
#define  FS_FAT_LFN_MODULE_PRESENT
#endif

#if     (FS_FAT_CFG_FAT12_EN == DEF_ENABLED)
#define  FS_FAT_FAT12_MODULE_PRESENT
#endif

#if     (FS_FAT_CFG_FAT16_EN == DEF_ENABLED)
#define  FS_FAT_FAT16_MODULE_PRESENT
#endif

#if     (FS_FAT_CFG_FAT32_EN == DEF_ENABLED)
#define  FS_FAT_FAT32_MODULE_PRESENT
#endif

#ifdef   FS_FAT_CFG_JOURNAL_EN
#if     (FS_FAT_CFG_JOURNAL_EN  == DEF_ENABLED)
#define  FS_FAT_JOURNAL_MODULE_PRESENT
#endif
#endif
#endif


/*
*********************************************************************************************************
*                                   FILE SYSTEM NAME CONFIGURATION
*
* Note(s) : (1) Ideally, the Type module would define ALL file system lengths
*********************************************************************************************************
*/

#ifdef   FS_CFG_MAX_VOL_NAME_LEN
#ifdef   FS_CFG_MAX_PATH_NAME_LEN
#define  FS_CFG_MAX_FULL_NAME_LEN               (FS_CFG_MAX_VOL_NAME_LEN + FS_CFG_MAX_PATH_NAME_LEN)
#endif
#endif

/*
*********************************************************************************************************
*                                  FILE SYSTEM CONFIGURATION ERRORS
*
* Note(s) : (1) Only FAT currently supported.
*********************************************************************************************************
*/
                                                                /* ---------------- FS_CFG_SYS_DRV_SEL ---------------- */
                                                                /* See Note #1.                                         */
#ifndef  FS_CFG_SYS_DRV_SEL
#error  "FS_CFG_SYS_DRV_SEL                           not #define'd in 'fs_cfg.h'               "
#error  "                                       [MUST be  FS_SYS_DRV_SEL_FAT]                   "

#elif   (FS_CFG_SYS_DRV_SEL != FS_SYS_DRV_SEL_FAT)
#error  "FS_CFG_SYS_DRV_SEL                     illegally #define'd in 'fs_cfg.h'               "
#error  "                                       [MUST be  FS_SYS_DRV_SEL_FAT]                   "
#endif



                                                                /* ------------------ FS_CFG_CACHE_EN ----------------- */
                                                                /* See Note #2.                                         */
#ifndef  FS_CFG_CACHE_EN
#error  "FS_CFG_CACHE_EN                              not #define'd in 'fs_cfg.h'               "
#error  "                                       [MUST be  DEF_DISABLED]                         "
#error  "                                       [     ||  DEF_ENABLED ]                         "

#elif  ((FS_CFG_CACHE_EN != DEF_DISABLED) && \
        (FS_CFG_CACHE_EN != DEF_ENABLED ))
#error  "FS_CFG_CACHE_EN                        illegally #define'd in 'fs_cfg.h'               "
#error  "                                       [MUST be  DEF_DISABLED]                         "
#error  "                                       [     ||  DEF_ENABLED ]                         "
#endif



                                                                /* ------------------- FS_CFG_API_EN ------------------ */
#ifndef  FS_CFG_API_EN
#error  "FS_CFG_API_EN                                not #define'd in 'fs_cfg.h'               "
#error  "                                       [MUST be  DEF_DISABLED]                         "
#error  "                                       [     ||  DEF_ENABLED ]                         "

#elif  ((FS_CFG_API_EN != DEF_DISABLED) && \
        (FS_CFG_API_EN != DEF_ENABLED ))
#error  "FS_CFG_API_EN                          illegally #define'd in 'fs_cfg.h'               "
#error  "                                       [MUST be  DEF_DISABLED]                         "
#error  "                                       [     ||  DEF_ENABLED ]                         "
#endif



                                                                /* ------------------- FS_CFG_DIR_EN ------------------ */
#ifndef  FS_CFG_DIR_EN
#error  "FS_CFG_DIR_EN                                not #define'd in 'fs_cfg.h'               "
#error  "                                       [MUST be  DEF_DISABLED]                         "
#error  "                                       [     ||  DEF_ENABLED ]                         "

#elif  ((FS_CFG_DIR_EN != DEF_DISABLED) && \
        (FS_CFG_DIR_EN != DEF_ENABLED ))
#error  "FS_CFG_DIR_EN                          illegally #define'd in 'fs_cfg.h'               "
#error  "                                       [MUST be  DEF_DISABLED]                         "
#error  "                                       [     ||  DEF_ENABLED ]                         "
#endif

/*
*********************************************************************************************************
*                            FILE SYSTEM NAME LENGTH CONFIGURATION ERRORS
*********************************************************************************************************
*/

                                                                /* ------------- FS_CFG_MAX_FILE_NAME_LEN ------------- */
#ifndef  FS_CFG_MAX_FILE_NAME_LEN
#error  "FS_CFG_MAX_FILE_NAME_LEN                     not #define'd in 'fs_cfg.h'               "
#error  "                                       [MUST be  >= 1]                                 "

#elif   (FS_CFG_MAX_FILE_NAME_LEN < 1u)
#error  "FS_CFG_MAX_FILE_NAME_LEN               illegally #define'd in 'fs_cfg.h'               "
#error  "                                       [MUST be  >= 1]                                 "

#elif   (FS_CFG_MAX_FILE_NAME_LEN > FS_FILE_NAME_LEN_MAX)
#error  "FS_CFG_MAX_FILE_NAME_LEN               illegally #define'd in 'fs_cfg.h'               "
#error  "                                       [MUST be  >= 1]                                 "
#endif



                                                                /* ------------- FS_CFG_MAX_PATH_NAME_LEN ------------- */
#ifndef  FS_CFG_MAX_PATH_NAME_LEN
#error  "FS_CFG_MAX_PATH_NAME_LEN                     not #define'd in 'fs_cfg.h'               "
#error  "                                       [MUST be  >= 1]                                 "

#elif   (FS_CFG_MAX_PATH_NAME_LEN < 1u)
#error  "FS_CFG_MAX_PATH_NAME_LEN               illegally #define'd in 'fs_cfg.h'               "
#error  "                                       [MUST be  >= 1]                                 "

#elif   (FS_CFG_MAX_PATH_NAME_LEN <= FS_CFG_MAX_FILE_NAME_LEN)
#error  "FS_CFG_MAX_PATH_NAME_LEN               illegally #define'd in 'fs_cfg.h'               "
#error  "                                       [MUST be  >= FS_CFG_MAX_FILE_NAME_LEN]          "

#elif   (FS_CFG_MAX_PATH_NAME_LEN > FS_FILE_NAME_LEN_MAX)
#error  "FS_CFG_MAX_PATH_NAME_LEN               illegally #define'd in 'fs_cfg.h'               "
#error  "                                       [MUST be  >= 1]                                 "
#endif



                                                                /* ------------ FS_CFG_MAX_DEV_DRV_NAME_LEN ----------- */
#ifndef  FS_CFG_MAX_DEV_DRV_NAME_LEN
#error  "FS_CFG_MAX_DEV_DRV_NAME_LEN              not #define'd in 'fs_cfg.h'               "
#error  "                                   [MUST be  >= 1]                                 "

#elif   (FS_CFG_MAX_DEV_DRV_NAME_LEN < 1u)
#error  "FS_CFG_MAX_DEV_DRV_NAME_LEN        illegally #define'd in 'fs_cfg.h'               "
#error  "                                   [MUST be  >= 1]                                 "

#elif   (FS_CFG_MAX_DEV_DRV_NAME_LEN > FS_FILE_NAME_LEN_MAX)
#error  "FS_CFG_MAX_DEV_DRV_NAME_LEN        illegally #define'd in 'fs_cfg.h'               "
#error  "                                   [MUST be  >= 1]                                 "
#endif



                                                                /* -------------- FS_CFG_MAX_DEV_NAME_LEN ------------- */
#ifndef  FS_CFG_MAX_DEV_NAME_LEN
#error  "FS_CFG_MAX_DEV_NAME_LEN                      not #define'd in 'fs_cfg.h'               "
#error  "                                       [MUST be  >= 1]                                 "

#elif   (FS_CFG_MAX_DEV_NAME_LEN < 1u)
#error  "FS_CFG_MAX_DEV_NAME_LEN                illegally #define'd in 'fs_cfg.h'               "
#error  "                                       [MUST be  >= 1]                                 "

#elif   (FS_CFG_MAX_DEV_NAME_LEN < FS_CFG_MAX_DEV_DRV_NAME_LEN + 3u)
#error  "FS_CFG_MAX_DEV_NAME_LEN                illegally #define'd in 'fs_cfg.h'               "
#error  "                                       [MUST be  >= FS_CFG_MAX_DEV_DRV_NAME_LEN + 3]   "

#elif   (FS_CFG_MAX_DEV_NAME_LEN > FS_CFG_MAX_DEV_DRV_NAME_LEN + 5u)
#error  "FS_CFG_MAX_DEV_NAME_LEN                illegally #define'd in 'fs_cfg.h'               "
#error  "                                       [MUST be  <= FS_CFG_MAX_DEV_DRV_NAME_LEN + 5]   "

#elif   (FS_CFG_MAX_DEV_NAME_LEN > FS_FILE_NAME_LEN_MAX)
#error  "FS_CFG_MAX_DEV_NAME_LEN                illegally #define'd in 'fs_cfg.h'               "
#error  "                                       [MUST be  >= 1]                                 "
#endif



                                                                /* -------------- FS_CFG_MAX_VOL_NAME_LEN ------------- */
#ifndef  FS_CFG_MAX_VOL_NAME_LEN
#error  "FS_CFG_MAX_VOL_NAME_LEN                      not #define'd in 'fs_cfg.h'               "
#error  "                                       [MUST be  >= 1]                                 "

#elif   (FS_CFG_MAX_VOL_NAME_LEN < 1u)
#error  "FS_CFG_MAX_VOL_NAME_LEN                illegally #define'd in 'fs_cfg.h'               "
#error  "                                       [MUST be  >= 1]                                 "

#elif   (FS_CFG_MAX_VOL_NAME_LEN > FS_FILE_NAME_LEN_MAX)
#error  "FS_CFG_MAX_VOL_NAME_LEN                illegally #define'd in 'fs_cfg.h'               "
#error  "                                       [MUST be  >= 1]                                 "
#endif

/*
*********************************************************************************************************
*                         FILE SYSTEM FEATURE INCLUSION CONFIGURATION ERRORS
*********************************************************************************************************
*/

                                                                /* ---------------- FS_CFG_FILE_BUF_EN ---------------- */
#ifndef  FS_CFG_FILE_BUF_EN
#error  "FS_CFG_FILE_BUF_EN                           not #define'd in 'fs_cfg.h'               "
#error  "                                       [MUST be DEF_DISABLED]                          "
#error  "                                       [     || DEF_ENABLED ]                          "

#elif  ((FS_CFG_FILE_BUF_EN != DEF_ENABLED ) && \
        (FS_CFG_FILE_BUF_EN != DEF_DISABLED))
#error  "FS_CFG_FILE_BUF_EN                     illegally #define'd in 'fs_cfg.h'               "
#error  "                                       [MUST be DEF_DISABLED]                          "
#error  "                                       [     || DEF_ENABLED ]                          "
#endif



                                                                /* ---------------- FS_CFG_FILE_LOCK_EN --------------- */
#ifndef  FS_CFG_FILE_LOCK_EN
#error  "FS_CFG_FILE_LOCK_EN                          not #define'd in 'fs_cfg.h'               "
#error  "                                       [MUST be DEF_DISABLED]                          "

#elif  ((FS_CFG_FILE_LOCK_EN != DEF_ENABLED ) && \
        (FS_CFG_FILE_LOCK_EN != DEF_DISABLED))
#error  "FS_CFG_FILE_LOCK_EN                    illegally #define'd in 'fs_cfg.h'               "
#error  "                                       [MUST be DEF_DISABLED]                          "
#error  "                                       [     || DEF_ENABLED ]                          "
#endif



                                                                /* ---------------- FS_CFG_PARTITION_EN --------------- */
#ifndef  FS_CFG_PARTITION_EN
#error  "FS_CFG_PARTITION_EN                          not #define'd in 'fs_cfg.h'               "
#error  "                                       [MUST be DEF_DISABLED]                          "
#error  "                                       [     || DEF_ENABLED ]                          "

#elif  ((FS_CFG_PARTITION_EN != DEF_ENABLED ) && \
        (FS_CFG_PARTITION_EN != DEF_DISABLED))
#error  "FS_CFG_PARTITION_EN                    illegally #define'd in 'fs_cfg.h'               "
#error  "                                       [MUST be DEF_DISABLED]                          "
#error  "                                       [     || DEF_ENABLED ]                          "
#endif



                                                                /* --------------- FS_CFG_WORKING_DIR_EN -------------- */
                                                                /* See Note #1.                                         */
#ifndef  FS_CFG_WORKING_DIR_EN
#error  "FS_CFG_WORKING_DIR_EN                        not #define'd in 'fs_cfg.h'               "
#error  "                                       [MUST be DEF_DISABLED]                          "
#error  "                                       [     || DEF_ENABLED ]                          "

#elif  ((FS_CFG_WORKING_DIR_EN != DEF_ENABLED ) && \
        (FS_CFG_WORKING_DIR_EN != DEF_DISABLED))
#error  "FS_CFG_WORKING_DIR_EN                  illegally #define'd in 'fs_cfg.h'               "
#error  "                                       [MUST be DEF_DISABLED]                          "
#error  "                                       [     || DEF_ENABLED ]                          "
#endif



                                                                /* ------------------ FS_CFG_UTF8_EN ------------------ */
#ifndef  FS_CFG_UTF8_EN
#error  "FS_CFG_UTF8_EN                               not #define'd in 'fs_cfg.h'               "
#error  "                                       [     || DEF_ENABLED ]                          "
#error  "                                       [MUST be  DEF_DISABLED]                         "

#elif  ((FS_CFG_UTF8_EN != DEF_ENABLED ) && \
        (FS_CFG_UTF8_EN != DEF_DISABLED))
#error  "FS_CFG_UTF8_EN                         illegally #define'd in 'fs_cfg.h'               "
#error  "                                       [MUST be  DEF_DISABLED]                         "
#error  "                                       [     || DEF_ENABLED ]                          "
#endif



                                                                /* -------- FS_CFG_CONCURRENT_ENTRIES_ACCESS_EN ------- */
#ifndef  FS_CFG_CONCURRENT_ENTRIES_ACCESS_EN
#error  "FS_CFG_CONCURRENT_ENTRIES_ACCESS_EN          not #define'd in 'fs_cfg.h'               "
#error  "                                       [MUST be DEF_DISABLED]                          "
#error  "                                       [     || DEF_ENABLED ]                          "

#elif  ((FS_CFG_CONCURRENT_ENTRIES_ACCESS_EN != DEF_ENABLED) && \
        (FS_CFG_CONCURRENT_ENTRIES_ACCESS_EN != DEF_DISABLED))
#error  "FS_CFG_CONCURRENT_ENTRIES_ACCESS_EN    illegally #define'd in 'fs_cfg.h'               "
#error  "                                       [MUST be DEF_DISABLED]                          "
#error  "                                       [     || DEF_ENABLED ]                          "
#endif



                                                                /* ----------------- FS_CFG_RD_ONLY_EN ---------------- */
#ifndef  FS_CFG_RD_ONLY_EN
#error  "FS_CFG_RD_ONLY_EN                            not #define'd in 'fs_cfg.h'               "
#error  "                                       [MUST be DEF_DISABLED]                          "
#error  "                                       [     || DEF_ENABLED ]                          "

#elif  ((FS_CFG_RD_ONLY_EN != DEF_ENABLED) && \
        (FS_CFG_RD_ONLY_EN != DEF_DISABLED))
#error  "FS_CFG_RD_ONLY_EN                      illegally #define'd in 'fs_cfg.h'               "
#error  "                                       [MUST be DEF_DISABLED]                          "
#error  "                                       [     || DEF_ENABLED ]                          "
#endif

/*
*********************************************************************************************************
*                                FILE SYSTEM FAT CONFIGURATION ERRORS
*********************************************************************************************************
*/

#ifdef   FS_FAT_MODULE_PRESENT
                                                                /* ----------------- FS_FAT_CFG_LFN_EN ---------------- */
#ifndef  FS_FAT_CFG_LFN_EN
#error  "FS_FAT_CFG_LFN_EN                            not #define'd in 'fs_cfg.h'               "
#error  "                                       [MUST be  DEF_DISABLED]                         "
#error  "                                       [     ||  DEF_ENABLED ]                         "

#elif  ((FS_FAT_CFG_LFN_EN != DEF_DISABLED) && \
        (FS_FAT_CFG_LFN_EN != DEF_ENABLED ))
#error  "FS_FAT_CFG_LFN_EN                      illegally #define'd in 'fs_cfg.h'               "
#error  "                                       [MUST be  DEF_DISABLED]                         "
#error  "                                       [     ||  DEF_ENABLED ]                         "
#endif



                                                                /* ---------------- FS_FAT_CFG_FAT12_EN --------------- */
                                                                /* See Note #1.                                         */
#ifndef  FS_FAT_CFG_FAT12_EN
#error  "FS_FAT_CFG_FAT12_EN                          not #define'd in 'fs_cfg.h'               "
#error  "                                       [MUST be  DEF_DISABLED]                         "
#error  "                                       [     ||  DEF_ENABLED ]                         "

#elif  ((FS_FAT_CFG_FAT12_EN != DEF_DISABLED) && \
        (FS_FAT_CFG_FAT12_EN != DEF_ENABLED ))
#error  "FS_FAT_CFG_FAT12_EN                    illegally #define'd in 'fs_cfg.h'               "
#error  "                                       [MUST be  DEF_DISABLED]                         "
#error  "                                       [     ||  DEF_ENABLED ]                         "
#endif



                                                                /* ---------------- FS_FAT_CFG_FAT16_EN --------------- */
#ifndef  FS_FAT_CFG_FAT16_EN
#error  "FS_FAT_CFG_FAT16_EN                          not #define'd in 'fs_cfg.h'               "
#error  "                                       [MUST be  DEF_DISABLED]                         "
#error  "                                       [     ||  DEF_ENABLED ]                         "

#elif  ((FS_FAT_CFG_FAT16_EN != DEF_DISABLED) && \
        (FS_FAT_CFG_FAT16_EN != DEF_ENABLED ))
#error  "FS_FAT_CFG_FAT16_EN                    illegally #define'd in 'fs_cfg.h'               "
#error  "                                       [MUST be  DEF_DISABLED]                         "
#error  "                                       [     ||  DEF_ENABLED ]                         "
#endif



                                                                /* ---------------- FS_FAT_CFG_FAT32_EN --------------- */
#ifndef  FS_FAT_CFG_FAT32_EN
#error  "FS_FAT_CFG_FAT32_EN                          not #define'd in 'fs_cfg.h'               "
#error  "                                       [MUST be  DEF_DISABLED]                         "
#error  "                                       [     ||  DEF_ENABLED ]                         "

#elif  ((FS_FAT_CFG_FAT32_EN != DEF_DISABLED) && \
        (FS_FAT_CFG_FAT32_EN != DEF_ENABLED ))
#error  "FS_FAT_CFG_FAT32_EN                    illegally #define'd in 'fs_cfg.h'               "
#error  "                                       [MUST be  DEF_DISABLED]                         "
#error  "                                       [     ||  DEF_ENABLED ]                         "
#endif

                                                                /* Make sure at least one FAT Config. is enabled        */
#if    ((FS_FAT_CFG_FAT12_EN != DEF_ENABLED) && \
        (FS_FAT_CFG_FAT16_EN != DEF_ENABLED) && \
        (FS_FAT_CFG_FAT32_EN != DEF_ENABLED))
#error  "INVALID FS FAT CONFIG                                      in  'fs_cfg.h'              "
#error  "At least one of (FS_FAT_CFG_FAT12_EN, FS_FAT_CFG_FAT16_EN, FS_FAT_CFG_FAT32_EN)        "
#error  "                                       [MUST be  DEF_ENABLED ]                         "
#endif


                                                                /* --------------- FS_FAT_CFG_JOURNAL_EN -------------- */
#ifndef  FS_FAT_CFG_JOURNAL_EN
#error  "FS_FAT_CFG_JOURNAL_EN                        not #define'd in 'fs_cfg.h'               "
#error  "                                       [MUST be  DEF_DISABLED]                         "
#error  "                                       [     ||  DEF_ENABLED ]                         "

#elif  ((FS_FAT_CFG_JOURNAL_EN != DEF_DISABLED) && \
        (FS_FAT_CFG_JOURNAL_EN != DEF_ENABLED ))
#error  "FS_FAT_CFG_JOURNAL_EN                  illegally #define'd in 'fs_cfg.h'               "
#error  "                                       [MUST be  DEF_DISABLED]                         "
#error  "                                       [     ||  DEF_ENABLED ]                         "
#endif

#if    ((FS_FAT_CFG_JOURNAL_EN == DEF_ENABLED) && \
        (FS_CFG_RD_ONLY_EN     == DEF_ENABLED))
#error  "FS_FAT_CFG_JOURNAL_EN                  illegally #define'd in 'fs_cfg.h'               "
#error  "        OR                                                                             "
#error  "FS_CFG_RD_ONLY_EN                      illegally #define'd in 'fs_cfg.h'               "
#error  "                                 [Journaling feature requires read/write operation.]   "
#endif

#endif


/*
*********************************************************************************************************
*                                FILE SYSTEM TIMESTAMPS CONFIGURATION ERRORS
*********************************************************************************************************
*/

                                                                /* ------------------ CLK_CFG_EXT_EN ------------------ */
#ifdef  FS_CFG_GET_TS_FROM_OS
#error  "FS_CFG_GET_TS_FROM_OS should not be #define'd in 'fs_cfg.h' -- replaced by CLK_CFG_EXT_EN in 'clk_cfg.h'   "
#endif


#ifndef  CLK_CFG_STR_CONV_EN
#error  "CLK_CFG_STR_CONV_EN                          not #define'd in 'clk_cfg.h'              "
#error  "                                       [     ||  DEF_ENABLED ]                         "

#elif  (CLK_CFG_STR_CONV_EN != DEF_ENABLED )
#error  "CLK_CFG_STR_CONV_EN                    illegally #define'd in 'clk_cfg.h'              "
#error  "                                       [     ||  DEF_ENABLED ]                         "
#endif


#ifndef  CLK_CFG_UNIX_EN
#error  "CLK_CFG_UNIX_EN                              not #define'd in 'clk_cfg.h'              "
#error  "                                       [     ||  DEF_ENABLED ]                         "

#elif  (CLK_CFG_UNIX_EN != DEF_ENABLED )
#error  "CLK_CFG_UNIX_EN                        illegally #define'd in 'clk_cfg.h'              "
#error  "                                       [     ||  DEF_ENABLED ]                         "
#endif


/*
*********************************************************************************************************
*********************************************************************************************************
*                                           FULL BUILD END
*********************************************************************************************************
*********************************************************************************************************
*/
#endif
