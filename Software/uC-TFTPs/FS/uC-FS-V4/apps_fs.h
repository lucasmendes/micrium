/*
*********************************************************************************************************
*                                                uC/Apps
*                                      Network Application Modules
*
*                          (c) Copyright 2008-2010; Micrium, Inc.; Weston, FL
*
*               All rights reserved.  Protected by international copyright laws.
*
*               File System interface port files are provided in source form to registered
*               licensees ONLY.  It is illegal to distribute this source code to any third
*               party unless you receive written permission by an authorized Micrium
*               representative.  Knowledge of the source code may NOT be used to develop a
*               similar product.
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
*                                    uC/Apps FILE SYSTEM INTERFACE
*
*                                             uC/FS V4.xx
*
* Filename      : apps_fs.h
* Version       : V4.05
* Programmer(s) : FBJ
*                 BAN
*********************************************************************************************************
* Note(s)       : (1) Assumes uC/FS  V4.03 (or more recent version) is included in the project build.
*                 (2) Assumes uC/Clk V3.09 (or more recent version) is included in the project build
                           if µC/FS  V4.04 is used.
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                               MODULE
*********************************************************************************************************
*/

#ifndef  APPS_FS_PRESENT
#define  APPS_FS_PRESENT


/*
*********************************************************************************************************
*                                               EXTERNS
*********************************************************************************************************
*/

#ifdef   APPS_FS_MODULE
#define  APPS_FS_EXT
#else
#define  APPS_FS_EXT  extern
#endif


/*
*********************************************************************************************************
*                                            INCLUDE FILES
*********************************************************************************************************
*/

#include  <cpu.h>
#include  <cpu_core.h>

#include  <lib_def.h>
#include  <lib_str.h>
#include  <lib_ascii.h>

#include  <fs.h>

#if (FS_VERSION >= 404u)
#include  <clk.h>
#endif


/*
*********************************************************************************************************
*                                               DEFINES
*********************************************************************************************************
*/

#define  APPS_FS_PATH_SEP_CHAR                   FS_CHAR_PATH_SEP

#define  APPS_FS_MAX_FILE_NAME_LEN               FS_CFG_MAX_FILE_NAME_LEN
#define  APPS_FS_MAX_PATH_NAME_LEN               FS_CFG_MAX_FULL_NAME_LEN

#define  APPS_FS_SEEK_ORIGIN_START                        1u    /* Origin is beginning of file.                         */
#define  APPS_FS_SEEK_ORIGIN_CUR                          2u    /* Origin is current file position.                     */
#define  APPS_FS_SEEK_ORIGIN_END                          3u    /* Origin is end of file.                               */

#define  APPS_FS_ENTRY_ATTRIB_RD                 DEF_BIT_00     /* Entry is readable.                                   */
#define  APPS_FS_ENTRY_ATTRIB_WR                 DEF_BIT_01     /* Entry is writeable.                                  */
#define  APPS_FS_ENTRY_ATTRIB_HIDDEN             DEF_BIT_02     /* Entry is hidden from user-level processes.           */
#define  APPS_FS_ENTRY_ATTRIB_DIR                DEF_BIT_03     /* Entry is a directory.                                */


/*
*********************************************************************************************************
*                                             DATA TYPES
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                                        DATE / TIME DATA TYPE
*********************************************************************************************************
*/

typedef  struct  apps_fs_date_time {
    CPU_INT16U         Second;                                  /* Seconds [0..60].                                     */
    CPU_INT16U         Minute;                                  /* Minutes [0..59].                                     */
    CPU_INT16U         Hour;                                    /* Hour [0..23].                                        */
    CPU_INT16U         Day;                                     /* Day of month [1..31].                                */
    CPU_INT16U         Month;                                   /* Month of year [1..12].                               */
    CPU_INT16U         Year;                                    /* Year [0, ..., 2000, 2001, ...].                      */
} APPS_FS_DATE_TIME;

/*
*********************************************************************************************************
*                                           ENTRY DATA TYPE
*********************************************************************************************************
*/

typedef  struct  apps_fs_entry {
    CPU_CHAR           Name[APPS_FS_MAX_FILE_NAME_LEN + 1u];    /* Name.                                                */
    CPU_INT16U         Attrib;                                  /* Entry attributes.                                    */
    CPU_INT32U         Size;                                    /* File size in octets.                                 */
    APPS_FS_DATE_TIME  DateTimeCreate;                          /* Date/time of creation.                               */
} APPS_FS_ENTRY;


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

                                                                    /* ------------------- DIR FNCTS ------------------ */
void         *Apps_FS_DirOpen     (CPU_CHAR           *pname);      /* Open directory.                                  */

void          Apps_FS_DirClose    (void               *pdir);       /* Close directory.                                 */

CPU_BOOLEAN   Apps_FS_DirRd       (void               *pdir,        /* Read entry from directory.                       */
                                   APPS_FS_ENTRY      *pentry);


                                                                    /* ------------------ ENTRY FNCTS ----------------- */
CPU_BOOLEAN   Apps_FS_EntryCreate (CPU_CHAR           *pname,       /* Create file or directory.                        */
                                   CPU_BOOLEAN         dir);

CPU_BOOLEAN   Apps_FS_EntryDel    (CPU_CHAR           *pname,       /* Delete file or directory.                        */
                                   CPU_BOOLEAN         file);

CPU_BOOLEAN   Apps_FS_EntryRename (CPU_CHAR           *pname_old,   /* Rename file or directory.                        */
                                   CPU_CHAR           *pname_new);

CPU_BOOLEAN   Apps_FS_EntryTimeSet(CPU_CHAR           *pname,       /* Set a file or directory's date/time.             */
                                   APPS_FS_DATE_TIME  *ptime);


                                                                    /* ------------------ FILE FNCTS ------------------ */
void         *Apps_FS_FileOpen    (CPU_CHAR           *pname,       /* Open file.                                       */
                                   CPU_CHAR           *pmode_str);

void          Apps_FS_FileClose   (void               *pfile);      /* Close file.                                      */

CPU_BOOLEAN   Apps_FS_FileRd      (void               *pfile,       /* Read from file.                                  */
                                   void               *pdest,
                                   CPU_SIZE_T          size,
                                   CPU_SIZE_T         *psize_rd);

CPU_BOOLEAN   Apps_FS_FileWr      (void               *pfile,       /* Write to file.                                   */
                                   void               *psrc,
                                   CPU_SIZE_T          size,
                                   CPU_SIZE_T         *psize_wr);

CPU_BOOLEAN   Apps_FS_FilePosSet  (void               *pfile,       /* Set file position.                               */
                                   CPU_INT32S          offset,
                                   CPU_INT08U          origin);

CPU_BOOLEAN   Apps_FS_FileSizeGet (void               *pfile,       /* Get file size.                                   */
                                   CPU_INT32U         *psize);


/*
*********************************************************************************************************
*                                   EXTERNAL MODULES CONFIGURATION ERRORS
*********************************************************************************************************
*/

                                                                    /* See 'apps_fs.h  Note #1'.                        */
#if (FS_VERSION <  403u)
#error  "FS_VERSION            [SHOULD be >= V4.03]"
#elif (FS_VERSION >= 404u)
                                                                    /* See 'apps_fs.h  Note #2'.                        */
#if (CLK_VERSION < 309u)
#error  "CLK_VERSION           [SHOULD be >= V1.09]"
#endif

#endif


/*
*********************************************************************************************************
*                                             MODULE END
*********************************************************************************************************
*/

#endif                                                          /* End of APPS FS module include.                       */
