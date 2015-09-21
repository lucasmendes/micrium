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
*                                          FILE SYSTEM TYPES
*
* Filename      : fs_type.h
* Version       : V4.04
* Programmer(s) : AHFAI
*                 BAN
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                               EXTERNS
*********************************************************************************************************
*/

#ifdef   FS_TYPE_MODULE
#define  FS_TYPE_EXT
#else
#define  FS_TYPE_EXT  extern
#endif


/*
*********************************************************************************************************
*                                               DEFINES
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                               MACRO'S
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                             DATA TYPES
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                        FORWARD DECLARATIONS
*********************************************************************************************************
*/

typedef  struct  fs_buf              FS_BUF;

typedef  struct  fs_dev              FS_DEV;

typedef  struct  fs_dev_api          FS_DEV_API;

typedef  struct  fs_dir              FS_DIR;

typedef  struct  fs_file             FS_FILE;

typedef  struct  fs_partition_entry  FS_PARTITION_ENTRY;

typedef  struct  fs_vol              FS_VOL;

typedef  struct  fs_vol_cache_api    FS_VOL_CACHE_API;

/*
*********************************************************************************************************
*                                          FILE SYSTEM TYPE
*
* Note(s) : (1) 'FS_TYPE' declared as 'CPU_INT32U' & all 'FS_TYPE's #define'd with large, non-trivial
*               values to trap & discard invalid/corrupted file system objects based on 'FS_TYPE'.
*
*           (2) 'FS_TYPE_CREATE()' macro forms 'CPU_INT32U' type value from three 'CPU_CHAR' characters.
*********************************************************************************************************
*/

typedef  CPU_INT32U  FS_TYPE;


#if     (CPU_CFG_ENDIAN_TYPE == CPU_ENDIAN_TYPE_BIG)
#define  FS_TYPE_CREATE(c1, c2, c3, c4)         ((CPU_INT32U)((c1) << (3u * DEF_OCTET_NBR_BITS)) | \
                                                 (CPU_INT32U)((c2) << (2u * DEF_OCTET_NBR_BITS)) | \
                                                 (CPU_INT32U)((c3) << (1u * DEF_OCTET_NBR_BITS)) | \
                                                 (CPU_INT32U)((c4) << (0u * DEF_OCTET_NBR_BITS)))
#else

#if     (CPU_CFG_DATA_SIZE   == CPU_WORD_SIZE_32)
#define  FS_TYPE_CREATE(c1, c2, c3, c4)         ((CPU_INT32U)((c1) << (0u * DEF_OCTET_NBR_BITS)) | \
                                                 (CPU_INT32U)((c2) << (1u * DEF_OCTET_NBR_BITS)) | \
                                                 (CPU_INT32U)((c3) << (2u * DEF_OCTET_NBR_BITS)) | \
                                                 (CPU_INT32U)((c4) << (3u * DEF_OCTET_NBR_BITS)))


#elif   (CPU_CFG_DATA_SIZE   == CPU_WORD_SIZE_16)
#define  FS_TYPE_CREATE(c1, c2, c3, c4)         ((CPU_INT32U)((c1) << (2u * DEF_OCTET_NBR_BITS)) | \
                                                 (CPU_INT32U)((c2) << (3u * DEF_OCTET_NBR_BITS)) | \
                                                 (CPU_INT32U)((c3) << (0u * DEF_OCTET_NBR_BITS)) | \
                                                 (CPU_INT32U)((c4) << (1u * DEF_OCTET_NBR_BITS)))

#else                                                           /* Dflt CPU_WORD_SIZE_08.                               */
#define  FS_TYPE_CREATE(c1, c2, c3, c4)         ((CPU_INT32U)((c1) << (3u * DEF_OCTET_NBR_BITS)) | \
                                                 (CPU_INT32U)((c2) << (2u * DEF_OCTET_NBR_BITS)) | \
                                                 (CPU_INT32U)((c3) << (1u * DEF_OCTET_NBR_BITS)) | \
                                                 (CPU_INT32U)((c4) << (0u * DEF_OCTET_NBR_BITS)))
#endif
#endif


/*
*********************************************************************************************************
*                                          FILE SYSTEM FLAGS
*********************************************************************************************************
*/

typedef  CPU_INT32U  FS_FLAGS;

/*
*********************************************************************************************************
*                                     FILE SYSTEM STATE DATA TYPE
*********************************************************************************************************
*/

typedef  CPU_INT16U  FS_STATE;

/*
*********************************************************************************************************
*                                 STRUCTURE / ITEM QUANTITY DATA TYPE
*********************************************************************************************************
*/

typedef  CPU_INT16U  FS_QTY;

#define  FS_QTY_NBR_MAX                         DEF_INT_16U_MAX_VAL

/*
*********************************************************************************************************
*                                    STRUCTURE / ITEM ID DATA TYPE
*********************************************************************************************************
*/

typedef  CPU_INT16U  FS_ID;

#define  FS_ID_NBR_MAX                          (DEF_INT_16U_MAX_VAL - 1)
#define  FS_ID_INVALID                           DEF_INT_16U_MAX_VAL

/*
*********************************************************************************************************
*                                      ENTRY NAME SIZE DATA TYPE
*********************************************************************************************************
*/

typedef  CPU_INT16U  FS_FILE_NAME_LEN;

#define  FS_FILE_NAME_LEN_MAX                    DEF_INT_16U_MAX_VAL

/*
*********************************************************************************************************
*                                   FILE / DIRECTORY SIZE DATA TYPE
*********************************************************************************************************
*/

typedef  CPU_INT32S  FS_FILE_OFFSET;

#define  FS_FILE_OFFSET_MIN                     DEF_INT_32S_MIN_VAL
#define  FS_FILE_OFFSET_MAX                     DEF_INT_32S_MAX_VAL

/*
*********************************************************************************************************
*                                   FILE / DIRECTORY SIZE DATA TYPE
*********************************************************************************************************
*/

typedef  CPU_INT32U  FS_FILE_SIZE;

#define  FS_FILE_SIZE_MAX                        DEF_INT_32U_MAX_VAL

/*
*********************************************************************************************************
*                                   SEC QTY, NBR & SIZE DATA TYPES
*********************************************************************************************************
*/

typedef  CPU_INT32U  FS_SEC_QTY;
typedef  CPU_INT32U  FS_SEC_NBR;
typedef  CPU_INT32U  FS_SEC_SIZE;

typedef  CPU_INT16U  FS_PARTITION_NBR;

#define  FS_INVALID_PARTITION_NBR                DEF_INT_16U_MAX_VAL

/*
*********************************************************************************************************
*                                          GLOBAL VARIABLES
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

