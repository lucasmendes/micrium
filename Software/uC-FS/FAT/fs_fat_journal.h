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
*                                     FILE SYSTEM FAT MANAGEMENT
*
*                                             JOURNALING
*
* Filename      : fs_fat_journal.h
* Version       : V4.04
* Programmer(s) : BAN
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                               MODULE
*
* Note(s) : (1) See 'fs_fat.h  MODULE'.
*
*           (2) The following FAT-module-present configuration value MUST be pre-#define'd in
*               'fs_cfg_fs.h' PRIOR to all other file system modules that require FAT Journal Layer
*               Configuration (see 'fs_cfg_fs.h  FAT LAYER CONFIGURATION  Note #2b') :
*
*                   FS_FAT_JOURNAL_MODULE_PRESENT
*********************************************************************************************************
*/

#ifdef   FS_FAT_MODULE_PRESENT                                  /* See Note #1.                                         */
#ifdef   FS_FAT_JOURNAL_MODULE_PRESENT                          /* See Note #2.                                         */


/*
*********************************************************************************************************
*                                               EXTERNS
*********************************************************************************************************
*/

#ifdef   FS_FAT_JOURNAL_MODULE
#define  FS_FAT_JOURNAL_EXT
#else
#define  FS_FAT_JOURNAL_EXT  extern
#endif


/*
*********************************************************************************************************
*                                               DEFINES
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                             DATA TYPES
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                          GLOBAL VARIABLES
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                               MACRO'S
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                         FUNCTION PROTOTYPES
*********************************************************************************************************
*/

void             FS_FAT_JournalOpen               (CPU_CHAR              *name_vol,     /* Open  journal.               */
                                                   FS_ERR                *p_err);

void             FS_FAT_JournalClose              (CPU_CHAR              *name_vol,     /* Close journal.               */
                                                   FS_ERR                *p_err);


void             FS_FAT_JournalStart              (CPU_CHAR              *name_vol,     /* Start journaling.            */
                                                   FS_ERR                *p_err);

void             FS_FAT_JournalStop               (CPU_CHAR              *name_vol,     /* Stop  journaling.            */
                                                   FS_ERR                *p_err);

/*
*********************************************************************************************************
*                                    INTERNAL FUNCTION PROTOTYPES
*********************************************************************************************************
*/

void             FS_FAT_JournalModuleInit         (FS_QTY                 vol_cnt,      /* Init FAT journal module.     */
                                                   FS_ERR                *p_err);


                                                                                        /* ------- JOURNAL CTRL ------- */
void             FS_FAT_JournalInit               (FS_VOL                *p_vol,        /* Init journal.                */
                                                   FS_ERR                *p_err);

void             FS_FAT_JournalExit               (FS_VOL                *p_vol,        /* Exit journal.                */
                                                   FS_ERR                *p_err);

void             FS_FAT_JournalClr                (FS_VOL                *p_vol,        /* Clr  journal.                */
                                                   FS_ERR                *p_err);


                                                                                        /* ------- JOURNAL LOGS ------- */
FS_FAT_CLUS_NBR  FS_FAT_JournalChkClusAlloc       (FS_VOL                *p_vol,        /* Chk for clus alloc       log.*/
                                                   void                  *p_temp,
                                                   FS_FAT_CLUS_NBR        start_clus,
                                                   FS_ERR                *p_err);

void             FS_FAT_JournalChkDirEntryAlloc   (FS_VOL                *p_vol,        /* Chk for dir entry alloc  log.*/
                                                   FS_FAT_SEC_NBR         dir_cur_sec,
                                                   FS_FAT_DIR_POS        *p_dir_cur_start_pos,
                                                   FS_FAT_DIR_ENTRY_QTY  *p_dir_entry_free_cnt,
                                                   FS_ERR                *p_err);

void             FS_FAT_JournalChkDirEntryCreate  (FS_VOL                *p_vol,        /* Chk     dir entry create log.*/
                                                   void                  *p_temp,
                                                   CPU_CHAR              *name,
                                                   FS_FILE_NAME_LEN       name_len,
                                                   FS_FAT_DIR_POS        *p_dir_start_pos,
                                                   FS_FAT_DIR_POS        *p_dir_end_pos,
                                                   FS_ERR                *p_err);


void             FS_FAT_JournalEnterClusAlloc     (FS_VOL                *p_vol,        /* Enter   clus alloc       log.*/
                                                   FS_FAT_CLUS_NBR        start_clus,
                                                   FS_FAT_CLUS_NBR        next_clus,
                                                   FS_ERR                *p_err);

void             FS_FAT_JournalEnterDirEntryAlloc (FS_VOL                *p_vol,        /* Enter   dir entry alloc  log.*/
                                                   FS_FAT_SEC_NBR         dir_cur_sec,
                                                   FS_FAT_DIR_POS        *p_dir_cur_start_pos,
                                                   FS_FAT_DIR_ENTRY_QTY   dir_entry_free_cnt,
                                                   FS_ERR                *p_err);

void             FS_FAT_JournalEnterDirEntryCreate(FS_VOL                *p_vol,        /* Enter   dir entry create log.*/
                                                   CPU_INT32U             name_8_3[],
                                                   CPU_BOOLEAN            is_lfn,
                                                   CPU_BOOLEAN            is_dir,
                                                   FS_FAT_CLUS_NBR        file_first_clus,
                                                   FS_FAT_DIR_POS        *p_dir_pos,
                                                   FS_ERR                *p_err);

void             FS_FAT_JournalEnterEntryCreate   (FS_VOL                *p_vol,        /* Enter   entry create     log.*/
                                                   CPU_CHAR              *name,
                                                   FS_FAT_SEC_NBR         dir_first_sec,
                                                   CPU_BOOLEAN            is_dir,
                                                   FS_ERR                *p_err);

void             FS_FAT_JournalEnterEntryDel      (FS_VOL                *p_vol,        /* Enter   entry del        log.*/
                                                   FS_FAT_FILE_DATA      *p_entry_data,
                                                   FS_ERR                *p_err);

void             FS_FAT_JournalEnterEntryRename   (FS_VOL                *p_vol,        /* Enter   entry rename     log.*/
                                                   FS_FAT_FILE_DATA      *p_entry_data_old,
                                                   FS_FAT_FILE_DATA      *p_entry_data_new,
                                                   CPU_BOOLEAN            exists,
                                                   CPU_CHAR              *name_new,
                                                   FS_ERR                *p_err);

void             FS_FAT_JournalEnterEntryTruncate (FS_VOL                *p_vol,        /* Enter   entry truncate   log.*/
                                                   FS_FAT_FILE_DATA      *p_entry_data,
                                                   FS_FAT_FILE_SIZE       file_size_truncated,
                                                   FS_ERR                *p_err);

void             FS_FAT_JournalEnterFileWr        (FS_VOL                *p_vol,        /* Enter   file wr process.     */
                                                   FS_ERR                *p_err);



void             FS_FAT_JournalExitClusAlloc      (FS_VOL                *p_vol,        /* Exit    clus alloc       log.*/
                                                   FS_ERR                *p_err);

void             FS_FAT_JournalExitDirEntryCreate (FS_VOL                *p_vol,        /* Exit    dir entry create log.*/
                                                   FS_ERR                *p_err);

void             FS_FAT_JournalExitEntryCreate    (FS_VOL                *p_vol,        /* Exit    entry create     log.*/
                                                   FS_ERR                *p_err);

void             FS_FAT_JournalExitEntryDel       (FS_VOL                *p_vol,        /* Exit    entry del        log.*/
                                                   FS_ERR                *p_err);

void             FS_FAT_JournalExitEntryRename    (FS_VOL                *p_vol,        /* Exit    entry rename     log.*/
                                                   FS_ERR                *p_err);

void             FS_FAT_JournalExitEntryTruncate  (FS_VOL                *p_vol,        /* Exit    entry truncate   log.*/
                                                   FS_ERR                *p_err);

void             FS_FAT_JournalExitFileWr         (FS_VOL                *p_vol,        /* Exit    file wr process.     */
                                                   FS_ERR                *p_err);

/*
*********************************************************************************************************
*                                        CONFIGURATION ERRORS
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                             MODULE END
*
* Note(s) : (1) See 'MODULE  Note #1'.
*
*           (2) See 'MODULE  Note #2'.
*********************************************************************************************************
*/

#endif                                                          /* End of journaling module include (see Note #2).      */
#endif                                                          /* End of FAT        module include (see Note #1).      */
