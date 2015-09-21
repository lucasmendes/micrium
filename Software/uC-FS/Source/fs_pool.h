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
*                                  FILE SYSTEM SUITE POOL MANAGEMENT
*
* Filename      : fs_pool.h
* Version       : V4.04
* Programmer(s) : FBJ
*                 BAN
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                               EXTERNS
*********************************************************************************************************
*/

#ifdef   FS_POOL_MODULE
#define  FS_POOL_EXT
#else
#define  FS_POOL_EXT  extern
#endif


/*
*********************************************************************************************************
*                                               DEFINES
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                                    FILE SYSTEM POOL TYPE DEFINES
*
* Note(s) : (1) FS_POOL_TYPE_??? #define values specifically chosen as ASCII representations of the file
*               system pool types.  Memory displays of pools will display the pool TYPE with the chosen
*               ASCII name.
*********************************************************************************************************
*/

#define  FS_POOL_TYPE_NONE          FS_TYPE_CREATE(ASCII_CHAR_LATIN_UPPER_N,  \
                                                   ASCII_CHAR_LATIN_UPPER_O,  \
                                                   ASCII_CHAR_LATIN_UPPER_N,  \
                                                   ASCII_CHAR_LATIN_UPPER_E)

#define  FS_POOL_TYPE_POOL          FS_TYPE_CREATE(ASCII_CHAR_LATIN_UPPER_P,  \
                                                   ASCII_CHAR_LATIN_UPPER_O,  \
                                                   ASCII_CHAR_LATIN_UPPER_O,  \
                                                   ASCII_CHAR_LATIN_UPPER_L)

#define  FS_POOL_TYPE_POOL_BLK      FS_TYPE_CREATE(ASCII_CHAR_LATIN_UPPER_B,  \
                                                   ASCII_CHAR_LATIN_UPPER_L,  \
                                                   ASCII_CHAR_LATIN_UPPER_K,  \
                                                   ASCII_CHAR_SPACE)


/*
*********************************************************************************************************
*                                             DATA TYPES
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                                        POOL BLOCK DATA TYPE
*
* Note(s) : (1) Forced word-alignment at start of pool block NOT required since first data member 'Type'
*               is declared as 'CPU_INT32U'.
*
*           (2) 'Dummy' declared to force 'Data' buffer word-alignment.
*********************************************************************************************************
*/

typedef  struct  fs_pool_blk {
    FS_TYPE        Type;                                        /* Type cfg'd @ init: FS_POOL_TYPE_POOL_BLK.            */
    FS_ID          ID;                                          /* ID   cfg'd @ init.                                   */
    FS_QTY         BlkIx;                                       /* Ix of blk in pool.                                   */

    CPU_ALIGN      Dummy;                                       /* See Note #2.                                         */
    CPU_INT08U     Data[1];
} FS_POOL_BLK;

/*
*********************************************************************************************************
*                                           POOL DATA TYPE
*
* Note(s) : (1) Forced word-alignment at start of pool NOT required since first data member 'Type' is
*               declared as 'CPU_INT32U'.
*********************************************************************************************************
*/

typedef  struct  fs_pool {
    FS_TYPE        Type;                                        /* Type cfg'd @ init: FS_POOL_TYPE_POOL.                */

    FS_POOL_BLK  **PoolPtrs;                                    /* Ptr   to mem pool's array of blk ptrs.               */

    FS_QTY         BlkTot;                                      /* Tot   nbr entries      in   pool.                    */
    FS_QTY         BlkAvail;                                    /* Avail nbr entries      in   pool.                    */
    FS_QTY         BlkUsed;                                     /* Used  nbr entries      from pool.                    */
    FS_QTY         BlkUsedMax;                                  /* Max   nbr entries used from pool.                    */

#if (FS_CFG_CTR_STAT_EN == DEF_ENABLED)
    FS_CTR         StatBlksAllocatedCtr;                        /* Tot   nbr entries successfully allocated.            */
    FS_CTR         StatBlksDeallocatedCtr;                      /* Tol   nbr entries successfully deallocated.          */
#endif

#if (FS_CFG_CTR_ERR_EN == DEF_ENABLED)
    FS_CTR         ErrPoolEmptyCtr;                             /* Tot   nbr empty pool errs.                           */
    FS_CTR         ErrPoolFullCtr;                              /* Tot   nbr full  pool errs.                           */
    FS_CTR         ErrPoolInvalidBlkIxCtr;                      /* Tot   nbr invalid blk ix free errs.                  */
#endif
} FS_POOL;


/*
*********************************************************************************************************
*                                          GLOBAL VARIABLES
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                              MACRO'S
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                         FUNCTION PROTOTYPES
*********************************************************************************************************
*/

void    FSPool_Create   (FS_POOL     *p_pool,                   /* Create a pool.                                       */
                         FS_QTY       blk_nbr,
                         CPU_SIZE_T   blk_size,
                         CPU_SIZE_T  *p_octets_reqd,
                         FS_ERR      *p_err);

void   *FSPool_BlkGet   (FS_POOL     *p_pool,                   /* Get a block from pool.                               */
                         FS_ERR      *p_err);

void    FSPool_BlkFree  (FS_POOL     *p_pool,                   /* Free a block to pool.                                */
                         void        *p_blk,
                         FS_ERR      *p_err);

void   *FSPool_FreeBlkAt(FS_POOL     *p_pool,                   /* Get a free block from pool by index.                 */
                         FS_QTY       blk_ix_free,
                         FS_ERR      *p_err);

void   *FSPool_UsedBlkAt(FS_POOL     *p_pool,                   /* Get a used block from pool by index.                 */
                         FS_QTY       blk_ix_used,
                         FS_ERR      *p_err);

FS_ID   FSPool_GetBlkID (FS_POOL     *p_pool,                   /* Get the ID of a block.                               */
                         void        *p_blk,
                         FS_ERR      *p_err);


/*
*********************************************************************************************************
*                                        CONFIGURATION ERRORS
*********************************************************************************************************
*/
