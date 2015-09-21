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
*                                         STATIC FILE SYSTEM
*
* Filename      : apps_fs.h
* Version       : V1.02
* Programmer(s) : SR
*********************************************************************************************************
* Note(s)       : (1) All files MUST be added prior to the first file or directory access.
*
*                 (2) The application is responsible for validating file name compatibility with external
*                     code modules, if additional restrictions must be imposed (e.g., certain characters
*                     are not allowed).
*                     (a) Importantly, file names should use ONLY the selected path separator character,
*                         ASCII_CHAR_REVERSE_SOLIDUS (= '\\'), to separate path components.  This software
*                         does not check for the common alternative, ASCII_CHAR_SOLIDUS (= '/'), when
*                         parsing file names, so any ASCII_CHAR_SOLIDUS character will be considered part
*                         of the file name component in which it is embedded.  This may break external
*                         code modules that convert names from this module's convention to the other.
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

#include  <app_cfg.h>


/*
*********************************************************************************************************
*                                        DEFAULT CONFIGURATION
*********************************************************************************************************
*/

#ifndef  APPS_FS_CFG_ARG_CHK_EXT_EN
#define  APPS_FS_CFG_ARG_CHK_EXT_EN     DEF_DISABLED
#endif


/*
*********************************************************************************************************
*                                               DEFINES
*********************************************************************************************************
*/

#define  APPS_FS_PATH_SEP_CHAR                   ASCII_CHAR_REVERSE_SOLIDUS

#define  APPS_FS_MAX_FILE_NAME_LEN               APPS_FS_CFG_MAX_FILE_NAME_LEN
#define  APPS_FS_MAX_PATH_NAME_LEN               APPS_FS_CFG_MAX_FILE_NAME_LEN

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
    CPU_INT16U         Year;                                    /* Year.                                                */
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

CPU_BOOLEAN   Apps_FS_Init        (void);                           /* Init file system.                                */

CPU_BOOLEAN   Apps_FS_AddFile     (CPU_CHAR           *pname,       /* Add file to file system.                         */
                                   void               *pdata,
                                   CPU_INT32U          size);

CPU_BOOLEAN   Apps_FS_SetTime     (APPS_FS_DATE_TIME  *ptime);      /* Set time for files & directories.                */


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
*                                        CONFIGURATION ERRORS
*********************************************************************************************************
*/

#ifndef  APPS_FS_CFG_ARG_CHK_EXT_EN
#error  "APPS_FS_CFG_ARG_CHK_EXT_EN            not #define'd in 'app_cfg.h'"
#error  "                                [MUST be  DEF_DISABLED]           "
#error  "                                [     ||  DEF_ENABLED ]           "

#elif  ((APPS_FS_CFG_ARG_CHK_EXT_EN != DEF_DISABLED) && \
        (APPS_FS_CFG_ARG_CHK_EXT_EN != DEF_ENABLED ))
#error  "APPS_FS_CFG_ARG_CHK_EXT_EN      illegally #define'd in 'app_cfg.h'"
#error  "                                [MUST be  DEF_DISABLED]           "
#error  "                                [     ||  DEF_ENABLED ]           "
#endif



#ifndef  APPS_FS_CFG_NBR_FILES
#error  "APPS_FS_CFG_NBR_FILES                 not #define'd in 'app_cfg.h'"
#error  "                                [MUST be >= 1]                    "

#elif   (APPS_FS_CFG_NBR_FILES < 1u)
#error  "APPS_FS_CFG_NBR_FILES           illegally #define'd in 'app_cfg.h'"
#error  "                                [MUST be >= 1]                    "
#endif



#ifndef  APPS_FS_CFG_NBR_DIRS
#error  "APPS_FS_CFG_NBR_DIRS                  not #define'd in 'app_cfg.h'"
#error  "                                [MUST be >= 1]                    "

#elif   (APPS_FS_CFG_NBR_DIRS < 1u)
#error  "APPS_FS_CFG_NBR_DIRS            illegally #define'd in 'app_cfg.h'"
#error  "                                [MUST be >= 1]                    "
#endif



#ifndef  APPS_FS_CFG_MAX_FILE_NAME_LEN
#error  "APPS_FS_CFG_MAX_FILE_NAME_LEN         not #define'd in 'app_cfg.h'"
#error  "                                [MUST be >= 1]                    "

#elif   (APPS_FS_CFG_MAX_FILE_NAME_LEN < 1u)
#error  "APPS_FS_CFG_MAX_FILE_NAME_LEN   illegally #define'd in 'app_cfg.h'"
#error  "                                [MUST be >= 1]                    "
#endif


/*
*********************************************************************************************************
*                                             MODULE END
*********************************************************************************************************
*/

#endif                                                          /* End of APPS FS module include.                       */
