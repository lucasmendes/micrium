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
*                                                TYPES
*
* Filename      : fs_fat_type.h
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

#ifdef   FS_FAT_TYPE_MODULE
#define  FS_FAT_TYPE_EXT
#else
#define  FS_FAT_TYPE_EXT  extern
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

typedef  struct  fs_fat_data       FS_FAT_DATA;

typedef  struct  fs_fat_file_data  FS_FAT_FILE_DATA;

typedef          CPU_INT32U        FS_FAT_CLUS_NBR;             /* Number of clusters/cluster index.                    */

typedef          CPU_INT32U        FS_FAT_SEC_NBR;              /* Number of sectors/sector index.                      */

typedef          CPU_INT16U        FS_FAT_DATE;                 /* FAT date.                                            */

typedef          CPU_INT16U        FS_FAT_TIME;                 /* FAT time.                                            */

typedef          CPU_INT08U        FS_FAT_DIR_ENTRY_QTY;        /* Quantity of directory entries.                       */

typedef          CPU_INT32U        FS_FAT_FILE_SIZE;            /* Size of file, in octets.                             */

/*
*********************************************************************************************************
*                                   FAT FORMAT CONFIGURATION DATA TYPE
*********************************************************************************************************
*/

typedef  struct  fs_fat_sys_cfg {
    FS_SEC_QTY        ClusSize;
    FS_FAT_SEC_NBR    RsvdAreaSize;
    CPU_INT16U        RootDirEntryCnt;
    CPU_INT08U        FAT_Type;
    CPU_INT08U        NbrFATs;
} FS_FAT_SYS_CFG;

/*
*********************************************************************************************************
*                                  FAT DIRECTORY ENTRY POSITION TYPE
*********************************************************************************************************
*/

typedef  struct  fs_fat_dir_pos {
    FS_FAT_SEC_NBR    SecNbr;
    FS_SEC_SIZE       SecPos;
} FS_FAT_DIR_POS;

/*
*********************************************************************************************************
*                                         FAT TYPE API DATA TYPE
*********************************************************************************************************
*/

typedef  struct  fs_fat_type_api {
#if (FS_CFG_RD_ONLY_EN      == DEF_DISABLED)
    FS_FAT_CLUS_NBR  (*ClusAlloc)       (FS_VOL            *p_vol,
                                         FS_BUF            *p_buf,
                                         CPU_BOOLEAN        clr,
                                         FS_ERR            *p_err);

#ifdef  FS_FAT_JOURNAL_MODULE_PRESENT
    void             (*ClusLink)        (FS_VOL            *p_vol,
                                         FS_BUF            *p_buf,
                                         FS_FAT_CLUS_NBR    start_clus,
                                         FS_FAT_CLUS_NBR    next_clus,
                                         FS_ERR            *p_err);
#endif

    void             (*ClusChainDel)    (FS_VOL            *p_vol,
                                         FS_BUF            *p_buf,
                                         FS_FAT_CLUS_NBR    start_clus,
                                         FS_FAT_CLUS_NBR    len,
                                         CPU_BOOLEAN        del_first,
                                         FS_ERR            *p_err);
#endif

    FS_FAT_CLUS_NBR  (*ClusChainFollow) (FS_VOL            *p_vol,
                                         FS_BUF            *p_buf,
                                         FS_FAT_CLUS_NBR    start_clus,
                                         FS_FAT_CLUS_NBR    len,
                                         FS_ERR            *p_err);

    FS_FAT_CLUS_NBR  (*ClusNextGet)     (FS_VOL            *p_vol,
                                         FS_BUF            *p_buf,
                                         FS_FAT_CLUS_NBR    start_clus,
                                         FS_ERR            *p_err);

#if (FS_CFG_RD_ONLY_EN      == DEF_DISABLED)
    FS_FAT_CLUS_NBR  (*ClusNextGetAlloc)(FS_VOL            *p_vol,
                                         FS_BUF            *p_buf,
                                         FS_FAT_CLUS_NBR    start_clus,
                                         CPU_BOOLEAN        clr,
                                         FS_ERR            *p_err);
#endif

    FS_FAT_SEC_NBR   (*SecNextGet)      (FS_VOL            *p_vol,
                                         FS_BUF            *p_buf,
                                         FS_FAT_SEC_NBR     start_sec,
                                         FS_ERR            *p_err);

#if (FS_CFG_RD_ONLY_EN      == DEF_DISABLED)
    FS_FAT_SEC_NBR   (*SecNextGetAlloc) (FS_VOL            *p_vol,
                                         FS_BUF            *p_buf,
                                         FS_FAT_SEC_NBR     start_sec,
                                         CPU_BOOLEAN        clr,
                                         FS_ERR            *p_err);

    void             (*MakeBootSec)     (void              *p_temp,
                                         FS_FAT_SYS_CFG    *p_fmt_cfg,
                                         FS_SEC_SIZE        sec_size,
                                         FS_FAT_SEC_NBR     size,
                                         FS_FAT_SEC_NBR     fat_size,
                                         FS_SEC_NBR         partition_start);
#endif

    void             (*Query)           (FS_VOL            *p_vol,
                                         FS_BUF            *p_buf,
                                         FS_SYS_INFO       *p_info,
                                         FS_ERR            *p_err);
} FS_FAT_TYPE_API;

/*
*********************************************************************************************************
*                                       FILE NAME API DATA TYPE
*********************************************************************************************************
*/

typedef  struct  fs_fat_fn_api {
#if (FS_CFG_RD_ONLY_EN == DEF_DISABLED)
    void             (*DirEntryCreate)  (FS_VOL            *p_vol,      /* Create dir entry.                            */
                                         FS_BUF            *p_buf,
                                         CPU_CHAR          *name,
                                         CPU_BOOLEAN        is_dir,
                                         FS_FAT_CLUS_NBR    file_first_clus,
                                         FS_FAT_DIR_POS    *p_dir_start_pos,
                                         FS_FAT_DIR_POS    *p_dir_end_pos,
                                         FS_ERR            *p_err);

    void             (*DirEntryCreateAt)(FS_VOL            *p_vol,      /* Create dir entry at sec pos.                 */
                                         FS_BUF            *p_buf,
                                         CPU_CHAR          *name,
                                         FS_FILE_NAME_LEN   name_len,
                                         CPU_INT32U         name_8_3[],
                                         CPU_BOOLEAN        is_dir,
                                         FS_FAT_CLUS_NBR    file_first_clus,
                                         FS_FAT_DIR_POS    *p_dir_pos,
                                         FS_FAT_DIR_POS    *p_dir_end_pos,
                                         FS_ERR            *p_err);

    void             (*DirEntryDel)     (FS_VOL            *p_vol,      /* Del dir entry.                               */
                                         FS_BUF            *p_buf,
                                         FS_FAT_DIR_POS    *p_dir_start_pos,
                                         FS_FAT_DIR_POS    *p_dir_end_pos,
                                         FS_ERR            *p_err);
#endif

    void             (*DirEntryFind)    (FS_VOL            *p_vol,      /* Srch dir for dir entry.                      */
                                         FS_BUF            *p_buf,
                                         CPU_CHAR          *name,
                                         CPU_CHAR         **p_name_next,
                                         FS_FAT_DIR_POS    *p_dir_start_pos,
                                         FS_FAT_DIR_POS    *p_dir_end_pos,
                                         FS_ERR            *p_err);

    void             (*NextDirEntryGet) (FS_VOL            *p_vol,      /* Get next dir entry in dir.                   */
                                         FS_BUF            *p_buf,
                                         void              *name,
                                         FS_FAT_DIR_POS    *p_dir_start_pos,
                                         FS_FAT_DIR_POS    *p_dir_end_pos,
                                         FS_ERR            *p_err);
} FS_FAT_FN_API;


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
