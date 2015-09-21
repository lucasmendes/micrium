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
*                                             FILE ACCESS
*
* Filename      : fs_fat_file.h
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

#ifdef   FS_FAT_FILE_MODULE
#define  FS_FAT_FILE_EXT
#else
#define  FS_FAT_FILE_EXT  extern
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

void          FS_FAT_FileModuleInit(FS_QTY          file_cnt,   /* Init FAT dir module.                                 */
                                    FS_ERR         *p_err);

/*
*********************************************************************************************************
*                                  SYSTEM DRIVER FUNCTION PROTOTYPES
*********************************************************************************************************
*/

void          FS_FAT_FileClose     (FS_FILE        *p_file,     /* Close a file.                                        */
                                    FS_ERR         *p_err);

void          FS_FAT_FileOpen      (FS_FILE        *p_file,     /* Open a file.                                         */
                                    CPU_CHAR       *name_file,
                                    FS_ERR         *p_err);

void          FS_FAT_FilePosSet    (FS_FILE        *p_file,     /* Set file position indicator.                         */
                                    FS_FILE_SIZE    pos_new,
                                    FS_ERR         *p_err);

void          FS_FAT_FileQuery     (FS_FILE        *p_file,     /* Get info about file.                                 */
                                    FS_ENTRY_INFO  *p_info,
                                    FS_ERR         *p_err);

CPU_SIZE_T    FS_FAT_FileRd        (FS_FILE        *p_file,     /* Read from a file.                                    */
                                    void           *p_dest,
                                    CPU_SIZE_T      size,
                                    FS_ERR         *p_err);

#if (FS_CFG_RD_ONLY_EN == DEF_DISABLED)
void          FS_FAT_FileTruncate  (FS_FILE        *p_file,     /* Truncate a file.                                     */
                                    FS_FILE_SIZE    size,
                                    FS_ERR         *p_err);
#endif

#if (FS_CFG_RD_ONLY_EN == DEF_DISABLED)
CPU_SIZE_T    FS_FAT_FileWr        (FS_FILE        *p_file,     /* Write to a file.                                     */
                                    void           *p_src,
                                    CPU_SIZE_T      size,
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
