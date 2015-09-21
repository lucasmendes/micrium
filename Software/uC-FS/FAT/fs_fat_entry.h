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
*                                            ENTRY ACCESS
*
* Filename      : fs_fat_entry.h
* Version       : V4.04
* Programmer(s) : BAN
*                 AHFAI
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                               MODULE
*
* Note(s) : (1) See 'fs_fat.h  MODULE'.
*********************************************************************************************************
*/

#ifdef   FS_FAT_MODULE_PRESENT                                  /* See Note #1.                                         */


/*
*********************************************************************************************************
*                                               EXTERNS
*********************************************************************************************************
*/

#ifdef   FS_FAT_ENTRY_MODULE
#define  FS_FAT_ENTRY_EXT
#else
#define  FS_FAT_ENTRY_EXT  extern
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

/*
*********************************************************************************************************
*                                  SYSTEM DRIVER FUNCTION PROTOTYPES
*********************************************************************************************************
*/

#if (FS_CFG_RD_ONLY_EN == DEF_DISABLED)
void      FS_FAT_EntryAttribSet(FS_VOL         *p_vol,          /* Set file or directory's attributes.                  */
                                CPU_CHAR       *name_entry,
                                FS_FLAGS        attrib,
                                FS_ERR         *p_err);

void      FS_FAT_EntryCreate   (FS_VOL         *p_vol,          /* Create a file or directory.                          */
                                CPU_CHAR       *name_entry,
                                FS_FLAGS        entry_type,
                                CPU_BOOLEAN     excl,
                                FS_ERR         *p_err);

void      FS_FAT_EntryDel      (FS_VOL         *p_vol,          /* Delete a file or directory.                          */
                                CPU_CHAR       *name_entry,
                                FS_FLAGS        entry_type,
                                FS_ERR         *p_err);
#endif

void      FS_FAT_EntryQuery    (FS_VOL         *p_vol,          /* Delete a file or directory.                          */
                                CPU_CHAR       *name_entry,
                                FS_ENTRY_INFO  *p_info,
                                FS_ERR         *p_err);

#if (FS_CFG_RD_ONLY_EN == DEF_DISABLED)
void      FS_FAT_EntryRename   (FS_VOL         *p_vol,          /* Rename a file or directory.                          */
                                CPU_CHAR       *name_entry_old,
                                CPU_CHAR       *name_entry_new,
                                CPU_BOOLEAN     excl,
                                FS_ERR         *p_err);

void      FS_FAT_EntryTimeSet  (FS_VOL         *p_vol,          /* Set file or directory's date/time.                   */
                                CPU_CHAR       *name_entry,
                                CLK_DATE_TIME  *p_time,
                                CPU_INT08U      time_type,
                                FS_ERR         *p_err);
#endif


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
*********************************************************************************************************
*/

#endif                                                          /* End of FAT module include (see Note #1).             */
