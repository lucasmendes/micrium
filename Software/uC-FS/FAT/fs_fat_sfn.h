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
*                                       SHORT FILE NAME SUPPORT
*
* Filename      : fs_fat_sfn.h
* Version       : V4.04
* Programmer(s) : BAN
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

#ifdef   FS_FAT_SFN_MODULE
#define  FS_FAT_SFN_EXT
#else
#define  FS_FAT_SFN_EXT  extern
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

extern  const  FS_FAT_FN_API  FS_FAT_SFN_API;                   /* Short file name API.                                 */


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

#if (FS_CFG_RD_ONLY_EN == DEF_DISABLED)
void  FS_FAT_SFN_DirEntryFmt(void              *p_dir_entry,    /* Fmt dir entry for SFN.                               */
                             CPU_INT32U         name_8_3[],
                             CPU_BOOLEAN        is_dir,
                             FS_FAT_CLUS_NBR    file_first_clus,
                             CPU_BOOLEAN        name_lower_case,
                             CPU_BOOLEAN        ext_lower_case);
#endif

void  FS_FAT_SFN_Chk        (CPU_CHAR          *name,           /* Chk file name as SFN.                                */
                             FS_FILE_NAME_LEN  *p_name_len,
                             FS_ERR            *p_err);

void  FS_FAT_SFN_Create     (CPU_CHAR          *name,           /* Create SFN.                                          */
                             CPU_INT32U         name_8_3[],
                             CPU_BOOLEAN       *p_name_lower_case,
                             CPU_BOOLEAN       *p_ext_lower_case,
                             FS_ERR            *p_err);

void  FS_FAT_SFN_SFN_Find   (FS_VOL            *p_vol,          /* Srch dir for SFN dir entry.                          */
                             FS_BUF            *p_buf,
                             CPU_INT32U         name_8_3[],
                             FS_FAT_DIR_POS    *p_dir_start_pos,
                             FS_FAT_DIR_POS    *p_dir_end_pos,
                             FS_ERR            *p_err);

void  FS_FAT_SFN_LabelGet   (FS_VOL            *p_vol,          /* Get volume label.                                    */
                             CPU_CHAR          *label,
                             FS_ERR            *p_err);

#if (FS_CFG_RD_ONLY_EN == DEF_DISABLED)
void  FS_FAT_SFN_LabelSet   (FS_VOL            *p_vol,          /* Set volume label.                                    */
                             CPU_CHAR          *label,
                             FS_ERR            *p_err);
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
