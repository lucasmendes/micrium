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
*                                    FILE SYSTEM SUITE HEADER FILE
*
* Filename      : fs.h
* Version       : V4.04
* Programmer(s) : FBJ
*                 BAN
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                               MODULE
*
* Note(s) : (1) This main file system suite header file is protected from multiple pre-processor
*               inclusion through use of the file system module present pre-processor macro definition.
*
*               See also 'FILE SYSTEM INCLUDE FILES  Note #5'.
*********************************************************************************************************
*/

#ifndef  FS_MODULE_PRESENT                                      /* See Note #1.                                         */
#define  FS_MODULE_PRESENT


/*
*********************************************************************************************************
*                                     FILE SYSTEM VERSION NUMBER
*
* Note(s) : (1) (a) The file system software version is denoted as follows :
*
*                       Vx.yy
*
*                           where
*                                   V               denotes 'Version' label
*                                   x               denotes major software version revision number
*                                   yy              denotes minor software version revision number
*
*               (b) The software version label #define is formatted as follows :
*
*                       ver = x.yy * 100
*
*                           where
*                                   ver             denotes software version number scaled as an integer value
*                                   x.yy            denotes software version number
*********************************************************************************************************
*/

#define  FS_VERSION                                      404u   /* See Note #1.                                         */


/*
*********************************************************************************************************
*                                               EXTERNS
*********************************************************************************************************
*/

#ifdef   FS_MODULE
#define  FS_EXT
#else
#define  FS_EXT  extern
#endif


/*
*********************************************************************************************************
*                                      FILE SYSTEM INCLUDE FILES
*
* Note(s) : (1) The file system files are located in the following directories :
*
*               (a) (1) \<Your Product Application>\app_cfg.h
*                   (2)                            \fs_cfg.h
*                   (3)                            \fs_bsp.*
*
*               (b) \<File System Suite>\Source\fs.h
*                                              \fs_*.*
*
*               (c) \<File System Suite>\OS\<os>\fs_os.*
*
*               (d) (1) \<File System Suite>\FAT\fs_fat.*
*
*               (e) \<File System Suite>\Dev\<dev>\fs_dev_*.*
*
*                       where
*                               <Your Product Application>     directory path for Your Product's Application
*                               <File System Suite>            directory path for file system suite
*                               <cpu>                          directory name for specific processor        (CPU)
*                               <os>                           directory name for specific operating system (OS)
*                               <dev>                          directory name for specific device
*
*           (2) CPU-configuration software files are located in the following directories :
*
*               (a) \<CPU-Compiler Directory>\cpu_def.h
*
*               (b) \<CPU-Compiler Directory>\<cpu>\<compiler>\cpu*.*
*
*                       where
*                               <CPU-Compiler Directory>        directory path for common   CPU-compiler software
*                               <cpu>                           directory name for specific processor (CPU)
*                               <compiler>                      directory name for specific compiler
*
*           (3) NO compiler-supplied standard library functions are used by the file system suite.
*
*               (a) Standard library functions are implemented in the custom library module(s) :
*
*                       \<Custom Library Directory>\lib*.*
*
*                           where
*                                   <Custom Library Directory>      directory path for custom library software
*
*               (b) File system-specific library functions are implemented in the File System Utility
*                   module, 'fs_util.*' (see 'fs_util.h  Note #1').
*
*           (4) Compiler MUST be configured to include as additional include path directories :
*
*               (a) '\<Your Product Application>\' directory                                See Note #1a
*
*               (b) '\<File System Suite>\'        directory                                See Note #1b
*
*               (c) '\<Custom Library Directory>\' directory                                See Note #3a
*
*               (d) Specific port directories :
*
*                   (1) (A) '\<CPU-Compiler Directory>\'                    directory       See Note #2
*                       (B) '\<CPU-Compiler Directory>\<cpu>\<compiler>'    directory
*
*                   (2) '\<File System Suite>\OS\<os>\'                     directory       See Note #1d
*
*                   (3) '\<File System Suite>\FAT\'                         directory       See Note #1e
*
*                   (4) '\<File System Suite>\Dev'                          directory
*
*                   (5) '\<File System Suite>\Dev\<dev>'                    directory(s)    See Note #1f
*
*                       where
*                               <Your Product Application>      directory path for Your Product's Application
*                               <File System Suite>             directory path for file system suite
*                               <Custom Library Directory>      directory path for custom  library software
*                               <CPU-Compiler Directory>        directory path for common  CPU-compiler software
*                               <cpu>                           directory name for specific processor        (CPU)
*                               <compiler>                      directory name for specific compiler
*                               <os>                            directory name for specific operating system (OS)
*                               <dev>                           directory name for specific file system device
*
*           (5) An application MUST pre-processor include ONLY this main file system suite header file,
*               'fs.h'.  All other file system suite files are included via this main file system header
*               file.
*
*               See also 'MODULE  Note #1'.
*
*               (a) Device-only applications pre-processor include 'fs_dev.h'.  These header files, which
*                   would ideally be included here are included by 'fs_dev.h' instead.
*
*                   See also 'fs_dev.h  FILE SYSTEM DEVICE MODULE INCLUDES'.
*********************************************************************************************************
*/

#include  <fs_dev.h>                                            /* Device Access & Management.                          */

#ifndef   FS_FILE_SYSTEM_BUILD_FULL
#error   "fs.h should NOT be #include'd unless FS_CFG_BUILD is FS_BUILD_FULL."
#endif

#include  <fs_buf.h>                                            /* File System Buffer     Management.                   */
#include  <fs_util.h>                                           /* File System Utility Library (see Note #3b).          */
#include  <fs_unicode.h>                                        /* Standard Unicode Library.                            */

#include  <fs_partition.h>                                      /* Partition Access.                                    */

#include  <fs_entry.h>                                          /* File System Entry Access.                            */
#include  <fs_file.h>                                           /* File Access & Management.                            */

#ifdef     FS_DIR_MODULE_PRESENT
#include  <fs_dir.h>                                            /* Directory Access & Management.                       */
#endif

#ifdef     FS_CACHE_MODULE_PRESENT
#include  <fs_cache.h>                                          /* Volume Cache Access & Management.                    */
#endif

#include  <fs_vol.h>                                            /* Volume Access & Management.                          */

#include  <fs_sys.h>                                            /* File System Access & Management.                     */

#ifdef     FS_FAT_MODULE_PRESENT
#include  <fs_fat.h>                                            /* FAT File System Support (see Note #1e).              */
#endif

#ifdef     FS_API_MODULE_PRESENT
#include  <fs_api.h>                                            /* File System stdio.h/POSIX API Functions.             */
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
*                                 FILE SYSTEM CONFIGURATION DATA TYPE
*
* Note(s) : (1) The file system suite is configured at initialization via the 'FS_CFG' structure :
*
*               (a) 'DevCnt' is the maximum number of devices that can be open simultaneously. It MUST
*                    be between 1 & FS_QTY_NBR_MAX, inclusive.
*
*               (b) 'VolCnt' is the maximum number of volumes that can be open simultaneously. It MUST
*                    be between 1 & FS_QTY_NBR_MAX, inclusive.
*
*               (c) 'FileCnt' is the maximum number of files that can be open simultaneously. It MUST
*                    be between 1 & FS_QTY_NBR_MAX, inclusive.
*
*               (d) 'DirCnt' is the maximum number of devices that can be open simultaneously.
*                   (1) If 'DirCnt' is 0, the directory module functions will be blocked after successful
*                       initialization, & the file system will operate as if compiled with directory
*                       support disabled.
*                   (2) If directory support is disabled, 'DirCnt' is ignored.
*                   (3) Otherwise, 'DirCnt' MUST be between 1 & FS_QTY_NBR_MAX, inclusive.
*
*               (e) 'BufCnt' is the maximum number of buffers that can be used simultaneously.
*                   The minimum necessary 'BufCnt' can be calculated from the number of volumes :
*
*                       BufCnt >= VolCnt * 2
*
*                   (1) If 'FSEntry_Copy()' or 'FSEntry_Rename()' is used, then up to one additional
*                       buffer for each volume may be necessary.
*
*               (f) 'DevDrvCnt' is the maximum number of device drivers that can be added.  It MUST
*                    be between 1 & FS_QTY_NBR_MAX, inclusive.
*
*               (g) 'MaxSecSize' is the maximum sector size, in octets.  It MUST be 512, 1024, 2048 or
*                    4096.  No device with a sector size larger than 'MaxSecSize' can be opened.
*********************************************************************************************************
*/

typedef  struct  fs_cfg {
    FS_QTY       DevCnt;                                        /* Max nbr devices     that can be open simultaneously. */
    FS_QTY       VolCnt;                                        /* Max nbr volumes     that can be open simultaneously. */
    FS_QTY       FileCnt;                                       /* Max nbr files       that can be open simultaneously. */
    FS_QTY       DirCnt;                                        /* Max nbr directories that can be open simultaneously. */
    FS_QTY       BufCnt;                                        /* Max nbr buffers     that can be used simultaneously. */
    FS_QTY       DevDrvCnt;                                     /* Max nbr device drivers that can be added.            */
    FS_SEC_SIZE  MaxSecSize;                                    /* Max sec size.                                        */
} FS_CFG;


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

                                                                    /* --------------------- CORE --------------------- */
FS_ERR       FS_Init              (FS_CFG        *p_fs_cfg);        /* File system startup function.                    */

CPU_INT16U   FS_VersionGet        (void);                           /* Get file system suite software version.          */

CPU_SIZE_T   FS_MaxSecSizeGet     (void);                           /* Get maximum sector size.                         */


                                                                    /* --------------- WORKING DIRECTORY -------------- */
#if (FS_CFG_WORKING_DIR_EN == DEF_ENABLED)
void         FS_WorkingDirGet     (CPU_CHAR      *path_dir,         /* Get the working directory for current task.      */
                                   CPU_SIZE_T     size,
                                   FS_ERR        *p_err);

void         FS_WorkingDirSet     (CPU_CHAR      *path_dir,         /* Set the working directory for current task.      */
                                   FS_ERR        *p_err);
#endif

/*
*********************************************************************************************************
*                                    INTERNAL FUNCTION PROTOTYPES
*********************************************************************************************************
*/

CPU_CHAR    *FS_PathParse         (CPU_CHAR      *name_full,        /* Parse full entry path.                           */
                                   CPU_CHAR      *name_vol,
                                   FS_ERR        *p_err);

#if (FS_CFG_WORKING_DIR_EN == DEF_ENABLED)
CPU_CHAR    *FS_WorkingDirPathForm(CPU_CHAR      *name_full,        /* Form full entry path.                            */
                                   FS_ERR        *p_err);

void         FS_WorkingDirObjFree (CPU_CHAR      *path_buf);        /* Free working dir obj.                            */
#endif


/*$PAGE*/
/*
*********************************************************************************************************
*                                         FUNCTION PROTOTYPES
*                                      DEFINED IN PRODUCT'S BSP
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                                          FS_BSP_Dly_ms()
*
* Description : Delay for specified time, in milliseconds.
*
* Argument(s) : ms      Time delay value, in milliseconds.
*
* Return(s)   : none.
*
* Caller(s)   : FS_OS_Dly_ms().
*
*               This function is an INTERNAL CPU module function & MUST be implemented by application/
*               BSP function(s) [see Note #1] but MUST NOT be called by application function(s).
*
* Note(s)     : (1) FS_BSP_Dly_ms() is an application/BSP function that MUST be defined by the developer 
*                   if no OS is used (when FS_OS_PRESENT is not #define'd in fs_os.h). Otherwise, the 
*                   function FS_OS_Dly_ms() is used. This function is serviced by the OS, and is defined 
*                   in the user OS port (fs_os.c). 
*********************************************************************************************************
*/

#ifndef FS_OS_PRESENT
void         FS_BSP_Dly_ms        (CPU_INT16U     ms);              /* Delay for specified time, in milliseconds.       */
#endif

/*
*********************************************************************************************************
*                                         FUNCTION PROTOTYPES
*                                      DEFINED IN OS'S  fs_os.c
*********************************************`***********************************************************
*/

#if (FS_CFG_WORKING_DIR_EN == DEF_ENABLED)
CPU_CHAR    *FS_OS_WorkingDirGet  (void);                           /* Get working dir assigned to active task.         */

void         FS_OS_WorkingDirSet  (CPU_CHAR      *p_working_dir);   /* Assign working directory to active task.         */
#endif


/*
*********************************************************************************************************
*                                        CONFIGURATION ERRORS
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                             MODULE END
*********************************************************************************************************
*/

#endif                                                          /* End of fs module include.                            */

