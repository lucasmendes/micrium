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
*                                 FILE SYSTEM SUITE DEVICE MANAGEMENT
*
* Filename      : fs_dev.h
* Version       : V4.04
* Programmer(s) : BAN
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                               MODULE
*
* Note(s) : (1) This file system device header file is protected from multiple pre-processor inclusion
*               through use of the file system device module present pre-processor macro definition.
*
*               See also 'FILE SYSTEM DEVICE INCLUDE FILES  Note #5'.
*********************************************************************************************************
*/

#ifndef  FS_DEV_MODULE_PRESENT                                  /* See Note #1.                                         */
#define  FS_DEV_MODULE_PRESENT


/*
*********************************************************************************************************
*                                               EXTERNS
*********************************************************************************************************
*/

#ifdef   FS_DEV_MODULE
#define  FS_DEV_EXT
#else
#define  FS_DEV_EXT  extern
#endif


/*
*********************************************************************************************************
*                                   FILE SYSTEM DEVICE INCLUDE FILES
*
* Note(s) : (1) The file system device files are located in the following directories :
*
*               (a) (1) \<Your Product Application>\app_cfg.h
*                   (2)                            \fs_cfg.h
*
*               (b) \<File System Suite>\Source\fs_dev.h
*                                              \fs_*.*
*
*               (c) \<File System Suite>\OS\<os>\fs_os.*
*
*               (d) \<File System Suite>\Dev\<dev>\fs_dev_*.*
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
*                   (3) '\<File System Suite>\Dev'                          directory
*
*                   (4) '\<File System Suite>\Dev\<dev>'                    directory(s)    See Note #1f
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
*           (5) A device-only application and any file system device drivers MUST pre-processor include
*               ONLY this file system device suite header file, 'fs_dev.h'.  All other file system device
*               suite files are included via this device file system header file.
*
*               See also 'MODULE  Note #1'.
*
*               (a) File system device drivers pre-processor including this file system device suite
*                   header file, 'fs_dev.h', on full file system suite builds require the file system
*                   module includes as well.
*
*                   See also 'fs.h  FILE SYSTEM MODULE INCLUDES'.
*********************************************************************************************************
*/

#include  <cpu.h>                                               /* CPU Configuration        (see Note #2).              */
#include  <cpu_core.h>                                          /* CPU Core Library.                                    */

#include  <lib_def.h>                                           /* Standard         Defines (see Note #3a).             */
#include  <lib_ascii.h>                                         /* Standard ASCII   Library (see Note #3a).             */
#include  <lib_mem.h>                                           /* Standard Memory  Library (see Note #3a).             */
#include  <lib_str.h>                                           /* Standard String  Library (see Note #3a).             */

#include  <clk.h>                                               /* Standard Time Library.                               */

#include  <fs_def.h>                                            /* File System Defines.                                 */
#include  <fs_type.h>                                           /* File System Data Types.                              */

#include  <app_cfg.h>                                           /* Application Configuration File (see Note #1a1).      */
#include  <fs_cfg.h>                                            /* File System Configuration File (see Note #1a2).      */
#include  <fs_cfg_fs.h>                                         /* File System Configuration (based on 'fs_cfg.h').     */

#include  <fs_err.h>                                            /* File System Error Code Management.                   */
#include  <fs_ctr.h>                                            /* File System Counter    Management.                   */
#include  <fs_pool.h>                                           /* File System Pool       Management.                   */
#include  <fs_os.h>                                             /* File System-OS  Interface (see Note #1d).            */

#ifdef     FS_FILE_SYSTEM_BUILD_FULL
#include  <fs.h>                                                /* Main File System Header File (see Note #5a).         */
#endif


/*
*********************************************************************************************************
*                                               DEFINES
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                                    PATH CHARACTER/STRING DEFINES
*
* Note(s) : (1) See 'fs.h  PATH CHARACTER/STRING DEFINES  Note #1'.
*********************************************************************************************************
*/

#define  FS_CHAR_PATH_SEP             ((CPU_CHAR  )ASCII_CHAR_REVERSE_SOLIDUS)
#define  FS_CHAR_PATH_SEP_ALT         ((CPU_CHAR  )ASCII_CHAR_SOLIDUS)
#define  FS_CHAR_DEV_SEP              ((CPU_CHAR  )ASCII_CHAR_COLON)

#define  FS_STR_PATH_SEP              ((CPU_CHAR *)"\\")
#define  FS_STR_DEV_SEP               ((CPU_CHAR *)":")

/*
*********************************************************************************************************
*                                        DEVICE STATE DEFINES
*********************************************************************************************************
*/

#define  FS_DEV_STATE_CLOSED                               0u   /* Dev closed.                                          */
#define  FS_DEV_STATE_CLOSING                              1u   /* Dev closing.                                         */
#define  FS_DEV_STATE_OPENING                              2u   /* Dev opening.                                         */
#define  FS_DEV_STATE_OPEN                                 3u   /* Dev open.                                            */
#define  FS_DEV_STATE_PRESENT                              4u   /* Dev present.                                         */
#define  FS_DEV_STATE_LOW_FMT_VALID                        5u   /* Dev low fmt valid.                                   */

/*
*********************************************************************************************************
*                                     DEVICE I/O CONTROL DEFINES
*********************************************************************************************************
*/

                                                                /* ------------------ GENERIC OPTIONS ----------------- */
#define  FS_DEV_IO_CTRL_REFRESH                            1u   /* Refresh dev.                                         */
#define  FS_DEV_IO_CTRL_LOW_FMT                            2u   /* Low-level fmt dev.                                   */
#define  FS_DEV_IO_CTRL_LOW_MOUNT                          3u   /* Low-level mount dev.                                 */
#define  FS_DEV_IO_CTRL_LOW_UNMOUNT                        4u   /* Low-level unmount dev.                               */
#define  FS_DEV_IO_CTRL_LOW_COMPACT                        5u   /* Low-level compact dev.                               */
#define  FS_DEV_IO_CTRL_LOW_DEFRAG                         6u   /* Low-level defrag dev.                                */
#define  FS_DEV_IO_CTRL_SEC_RELEASE                        7u   /* Release data in sec.                                 */
#define  FS_DEV_IO_CTRL_PHY_RD                             8u   /* Read  physical dev.                                  */
#define  FS_DEV_IO_CTRL_PHY_WR                             9u   /* Write physical dev.                                  */
#define  FS_DEV_IO_CTRL_PHY_RD_PAGE                       10u   /* Read  physical dev page.                             */
#define  FS_DEV_IO_CTRL_PHY_WR_PAGE                       11u   /* Write physical dev page.                             */
#define  FS_DEV_IO_CTRL_PHY_ERASE_BLK                     12u   /* Erase physical dev blk.                              */
#define  FS_DEV_IO_CTRL_PHY_ERASE_CHIP                    13u   /* Erase physical dev.                                  */

                                                                /* ------------ SD-DRIVER SPECIFIC OPTIONS ------------ */
#define  FS_DEV_IO_CTRL_SD_QUERY                          64u   /* Get info about SD/MMC card.                          */
#define  FS_DEV_IO_CTRL_SD_RD_CID                         65u   /* Read SD/MMC card Card ID reg.                        */
#define  FS_DEV_IO_CTRL_SD_RD_CSD                         66u   /* Read SD/MMC card Card-Specific Data reg.             */

/*
*********************************************************************************************************
*                                         DEVICE TYPE DEFINES
*
* Note(s) : (1) FS_DEV_TYPE_??? #define values specifically chosen as ASCII representations of the volume
*               types.  Memory displays of volume types will display the volume TYPE with the chosen
*               ASCII name.
*********************************************************************************************************
*/

#define  FS_DEV_TYPE_NONE           FS_TYPE_CREATE(ASCII_CHAR_LATIN_UPPER_N,  \
                                                   ASCII_CHAR_LATIN_UPPER_O,  \
                                                   ASCII_CHAR_LATIN_UPPER_N,  \
                                                   ASCII_CHAR_LATIN_UPPER_E)

#define  FS_DEV_TYPE_DEV            FS_TYPE_CREATE(ASCII_CHAR_LATIN_UPPER_D,  \
                                                   ASCII_CHAR_LATIN_UPPER_E,  \
                                                   ASCII_CHAR_LATIN_UPPER_V,  \
                                                   ASCII_CHAR_LATIN_UPPER_I)


/*
*********************************************************************************************************
*                                             DATA TYPES
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                                          DEVICE DATA TYPE
*
* Note(s) : (1) Forced word-alignment at start of device NOT required since first data member 'Type'
*               is declared as 'CPU_INT32U'.
*********************************************************************************************************
*/

struct  fs_dev {
    FS_TYPE       Type;                                         /* Type cfg'd @ init : FS_DEV_TYPE_DEV.                 */
    FS_ID         ID;                                           /* Dev ID.                                              */
    FS_STATE      State;                                        /* State.                                               */
    FS_CTR        RefCnt;                                       /* Ref cnts.                                            */
    FS_CTR        RefreshCnt;                                   /* Refresh cnts.                                        */

    CPU_CHAR      Name[FS_CFG_MAX_DEV_NAME_LEN + 1u];           /* Dev name.                                            */
    FS_QTY        UnitNbr;                                      /* Dev unit nbr.                                        */
    FS_SEC_QTY    Size;                                         /* Size of dev (in secs).                               */
    FS_SEC_SIZE   SecSize;                                      /* Size of dev sec.                                     */
    CPU_BOOLEAN   Fixed;                                        /* Indicates whether device is fixed or removable.      */

#ifdef FS_FILE_SYSTEM_BUILD_FULL
    FS_QTY        VolCnt;                                       /* Nbr of open vols on this dev.                        */
#endif

    FS_DEV_API   *DevDrvPtr;                                    /* Ptr to dev drv for this dev.                         */
    void         *DataPtr;                                      /* Ptr to data specific for a device driver.            */

#if (FS_CFG_CTR_STAT_EN == DEF_ENABLED)
    FS_CTR        StatRdSecCtr;                                 /* Nbr rd secs.                                         */
    FS_CTR        StatWrSecCtr;                                 /* Nbr wr secs.                                         */
#endif
};

/*
*********************************************************************************************************
*                                        DEVICE INFO DATA TYPE
*********************************************************************************************************
*/

typedef  struct  fs_dev_info {
    FS_STATE      State;                                        /* Device state.                                        */
    FS_SEC_QTY    Size;                                         /* Size of dev (in secs).                               */
    FS_SEC_SIZE   SecSize;                                      /* Size of dev sec.                                     */
    CPU_BOOLEAN   Fixed;                                        /* Indicates whether device is fixed or removable.      */
} FS_DEV_INFO;

/*
*********************************************************************************************************
*                                     DEVICE DRIVER API DATA TYPE
*********************************************************************************************************
*/

struct  fs_dev_api {
    const  CPU_CHAR  *(*NameGet) (void);                        /* Get base name of driver.                             */

    void              (*Init)    (FS_ERR       *p_err);         /* Initialize driver.                                   */

    void              (*Open)    (FS_DEV       *p_dev,          /* Open        a  device instance.                      */
                                  void         *p_dev_cfg,
                                  FS_ERR       *p_err);

    void              (*Close)   (FS_DEV       *p_dev);         /* Close       a  device instance.                      */

    void              (*Rd)      (FS_DEV       *p_dev,          /* Read from   a  device instance.                      */
                                  void         *p_dest,
                                  FS_SEC_NBR    start,
                                  FS_SEC_QTY    cnt,
                                  FS_ERR       *p_err);

#if (FS_CFG_RD_ONLY_EN == DEF_DISABLED)
    void              (*Wr)      (FS_DEV       *p_dev,          /* Write to    a  device instance.                      */
                                  void         *p_src,
                                  FS_SEC_NBR    start,
                                  FS_SEC_QTY    cnt,
                                  FS_ERR       *p_err);
#endif

    void              (*Query)   (FS_DEV       *p_dev,          /* Get info about device instance.                      */
                                  FS_DEV_INFO  *p_dev_info,
                                  FS_ERR       *p_err);

    void              (*IO_Ctrl) (FS_DEV       *p_dev,          /* Ctrl req to a  device instance.                      */
                                  CPU_INT08U    opt,
                                  void         *p_data,
                                  FS_ERR       *p_err);
};

/*
*********************************************************************************************************
*                                   DEVICE DRIVER SPI API DATA TYPE
*********************************************************************************************************
*/

typedef  struct  fs_dev_spi_api {
    CPU_BOOLEAN  (*Open)      (FS_QTY       unit_nbr);          /* Open (initialize) SPI.                               */

    void         (*Close)     (FS_QTY       unit_nbr);          /* Close (uninitialize) SPI.                            */

    void         (*Lock)      (FS_QTY       unit_nbr);          /* Acquire SPI lock.                                    */

    void         (*Unlock)    (FS_QTY       unit_nbr);          /* Release SPI lock.                                    */

    void         (*Rd)        (FS_QTY       unit_nbr,           /* Read from SPI.                                       */
                               void        *p_dest,
                               CPU_SIZE_T   cnt);

    void         (*Wr)        (FS_QTY       unit_nbr,           /* Write to SPI.                                        */
                               void        *p_src,
                               CPU_SIZE_T   cnt);

    void         (*ChipSelEn) (FS_QTY       unit_nbr);          /* Enable chip select.                                  */

    void         (*ChipSelDis)(FS_QTY       unit_nbr);          /* Disable chip select.                                 */

    void         (*SetClkFreq)(FS_QTY       unit_nbr,           /* Set SPI clock frequency.                             */
                               CPU_INT32U   freq);
} FS_DEV_SPI_API;


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

void               FS_DevDrvAdd          (FS_DEV_API          *p_dev_drv,   /* Add device driver to file system.        */
                                          FS_ERR              *p_err);

void               FSDev_Close           (CPU_CHAR            *name_dev,    /* Remove a device from the file system.    */
                                          FS_ERR              *p_err);

#ifdef FS_FILE_SYSTEM_BUILD_FULL
#if (FS_CFG_PARTITION_EN == DEF_ENABLED)
FS_PARTITION_NBR   FSDev_GetNbrPartitions(CPU_CHAR            *name_dev,    /* Get number of partitions on a device.    */
                                          FS_ERR              *p_err);
#endif
#endif

void               FSDev_IO_Ctrl         (CPU_CHAR            *name_dev,    /* Perform device I/O control operation.    */
                                          CPU_INT08U           opt,
                                          void                *p_data,
                                          FS_ERR              *p_err);

void               FSDev_Open            (CPU_CHAR            *name_dev,    /* Add a device to the file system.         */
                                          void                *p_dev_cfg,
                                          FS_ERR              *p_err);

#ifdef FS_FILE_SYSTEM_BUILD_FULL
#if (FS_CFG_PARTITION_EN == DEF_ENABLED)
#if (FS_CFG_RD_ONLY_EN   == DEF_DISABLED)
FS_PARTITION_NBR   FSDev_PartitionAdd    (CPU_CHAR            *name_dev,    /* Add partition to a device.               */
                                          FS_SEC_QTY           partition_size,
                                          FS_ERR              *p_err);
#endif

void               FSDev_PartitionFind   (CPU_CHAR            *name_dev,    /* Find partition on a device.              */
                                          FS_PARTITION_NBR     partition_nbr,
                                          FS_PARTITION_ENTRY  *p_partition_entry,
                                          FS_ERR              *p_err);
#endif

#if (FS_CFG_RD_ONLY_EN == DEF_DISABLED)
void               FSDev_PartitionInit   (CPU_CHAR            *name_dev,    /* Initialize the partition on a device.    */
                                          FS_SEC_QTY           partition_size,
                                          FS_ERR              *p_err);
#endif
#endif

void               FSDev_Query           (CPU_CHAR            *name_dev,    /* Obtain information about a device.       */
                                          FS_DEV_INFO         *p_info,
                                          FS_ERR              *p_err);

void               FSDev_Rd              (CPU_CHAR            *name_dev,    /* Read data from device sector(s).         */
                                          void                *p_dest,
                                          FS_SEC_NBR           start,
                                          FS_SEC_QTY           cnt,
                                          FS_ERR              *p_err);

CPU_BOOLEAN        FSDev_Refresh         (CPU_CHAR            *name_dev,    /* Refresh device.                          */
                                          FS_ERR              *p_err);

#if (FS_CFG_RD_ONLY_EN == DEF_DISABLED)
void               FSDev_Wr              (CPU_CHAR            *name_dev,    /* Write data to device sector(s).          */
                                          void                *p_src,
                                          FS_SEC_NBR           start,
                                          FS_SEC_QTY           cnt,
                                          FS_ERR              *p_err);
#endif

/*
*********************************************************************************************************
*                                   MANAGEMENT FUNCTION PROTOTYPES
*********************************************************************************************************
*/

FS_QTY             FSDev_GetDevCnt       (void);                            /* Get number of open devices.              */

FS_QTY             FSDev_GetDevCntMax    (void);                            /* Get max possible number of open devices. */

void               FSDev_GetDevName      (FS_QTY               dev_nbr,     /* Get name of nth open device.             */
                                          CPU_CHAR            *name_dev);

/*
*********************************************************************************************************
*                                    INTERNAL FUNCTION PROTOTYPES
*********************************************************************************************************
*/

                                                                            /* ------------ INITIALIZATION ------------ */
void               FSDev_ModuleInit      (FS_QTY               dev_cnt,     /* Initialize device module.                */
                                          FS_QTY               dev_drv_cnt,
                                          FS_ERR              *p_err);


                                                                            /* ------------ ACCESS CONTROL ------------ */
FS_DEV            *FSDev_AcquireLockChk  (CPU_CHAR            *name_dev,    /* Acquire device reference & lock.         */
                                          FS_ERR              *p_err);

FS_DEV            *FSDev_Acquire         (CPU_CHAR            *name_dev);   /* Acquire device reference.                */

void               FSDev_Release         (FS_DEV              *p_dev);      /* Release device reference.                */

void               FSDev_ReleaseUnlock   (FS_DEV              *p_dev);      /* Release device reference & lock.         */

CPU_BOOLEAN        FSDev_Lock            (FS_DEV              *p_dev);      /* Acquire device lock.                     */

void               FSDev_Unlock          (FS_DEV              *p_dev);      /* Release device lock.                     */


#ifdef FS_FILE_SYSTEM_BUILD_FULL                                            /* ------------- REGISTRATION ------------- */
void               FSDev_VolAdd          (FS_DEV              *p_dev,       /* Add volume to open volume list.          */
                                          FS_VOL              *p_vol);

void               FSDev_VolRemove       (FS_DEV              *p_dev,       /* Remove volume from open volume list.     */
                                          FS_VOL              *p_vol);
#endif


                                                                            /* ------------- LOCKED ACCESS ------------ */
void               FSDev_QueryLocked     (FS_DEV              *p_dev,       /* Get information about a device.          */
                                          FS_DEV_INFO         *p_info,
                                          FS_ERR              *p_err);

void               FSDev_RdLocked        (FS_DEV              *p_dev,       /* Read data from device sector(s).         */
                                          void                *p_dest,
                                          FS_SEC_NBR           start,
                                          FS_SEC_QTY           cnt,
                                          FS_ERR              *p_err);

CPU_BOOLEAN        FSDev_RefreshLocked   (FS_DEV              *p_dev,       /* Refresh device.                          */
                                          FS_ERR              *p_err);

#if (FS_CFG_RD_ONLY_EN == DEF_DISABLED)
void               FSDev_ReleaseLocked   (FS_DEV              *p_dev,       /* Release device sector(s).                */
                                          FS_SEC_NBR           start,
                                          FS_SEC_QTY           cnt,
                                          FS_ERR              *p_err);
#endif

#if (FS_CFG_RD_ONLY_EN == DEF_DISABLED)
void               FSDev_WrLocked        (FS_DEV              *p_dev,       /* Write data to device sector(s).          */
                                          void                *p_src,
                                          FS_SEC_NBR           start,
                                          FS_SEC_QTY           cnt,
                                          FS_ERR              *p_err);
#endif

/*
*********************************************************************************************************
*                                         FUNCTION PROTOTYPES
*                                      DEFINED IN OS'S  fs_os.c
*********************************************`***********************************************************
*/

void               FS_OS_Init            (FS_ERR              *p_err);      /* Create file system objects.              */

void               FS_OS_Lock            (FS_ERR              *p_err);      /* Acquire access to file system.           */

void               FS_OS_Unlock          (void);                            /* Release access to file system.           */


void               FS_OS_DevInit         (FS_QTY               dev_cnt,     /* Create file system device objects.       */
                                          FS_ERR              *p_err);

void               FS_OS_DevLock         (FS_ID                dev_id,      /* Acquire access to file system device.    */
                                          FS_ERR              *p_err);

void               FS_OS_DevUnlock       (FS_ID                dev_id);     /* Release access to file system device.    */

void               FS_OS_Dly_ms          (CPU_INT16U           ms);         /* Delay for specified time, in ms.         */


/*
*********************************************************************************************************
*                                               TRACING
*********************************************************************************************************
*/

                                                                /* Trace level, default to TRACE_LEVEL_OFF.             */
#ifndef  TRACE_LEVEL_OFF
#define  TRACE_LEVEL_OFF                                   0u
#endif

#ifndef  TRACE_LEVEL_INFO
#define  TRACE_LEVEL_INFO                                  1u
#endif

#ifndef  TRACE_LEVEL_DBG
#define  TRACE_LEVEL_DBG                                   2u
#endif

#ifndef  TRACE_LEVEL_LOG
#define  TRACE_LEVEL_LOG                                   3u
#endif

#ifndef  FS_TRACE_LEVEL
#define  FS_TRACE_LEVEL                          TRACE_LEVEL_OFF
#endif

#ifndef  FS_TRACE
#define  FS_TRACE                                printf
#endif

#if (FS_TRACE_LEVEL >= TRACE_LEVEL_INFO)
#define  FS_TRACE_INFO(x)                     (void)(FS_TRACE x)
#else
#define  FS_TRACE_INFO(x)
#endif

#if (FS_TRACE_LEVEL >= TRACE_LEVEL_DBG)
#define  FS_TRACE_DBG(x)                      (void)(FS_TRACE x)
#else
#define  FS_TRACE_DBG(x)
#endif

#if (FS_TRACE_LEVEL >= TRACE_LEVEL_LOG)
#define  FS_TRACE_LOG(x)                      (void)(FS_TRACE x)
#else
#define  FS_TRACE_LOG(x)
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

#endif                                                          /* End of fs dev module include.                        */
