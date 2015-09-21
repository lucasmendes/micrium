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
*                                    FILE SYSTEM BUFFER MANAGEMENT
*
* Filename      : fs_buf.h
* Version       : V4.04
* Programmer(s) : BAN
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                               EXTERNS
*********************************************************************************************************
*/

#ifdef   FS_BUF_MODULE
#define  FS_BUF_EXT
#else
#define  FS_BUF_EXT  extern
#endif


/*
*********************************************************************************************************
*                                               DEFINES
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                                         BUFFER FLAG DEFINES
*********************************************************************************************************
*/

#define  FS_BUF_STATE_NONE                                0u
#define  FS_BUF_STATE_USED                                1u
#define  FS_BUF_STATE_DIRTY                               2u

/*
*********************************************************************************************************
*                                         BUFFER TYPE DEFINES
*
* Note(s) : (1) FS_BUF_TYPE_??? #define values specifically chosen as ASCII representations of the buffer
*               types.  Memory displays of buffer types will display the buffer TYPE with the chosen ASCII
*               name.
*********************************************************************************************************
*/

#define  FS_BUF_TYPE_BUF_NONE       FS_TYPE_CREATE(ASCII_CHAR_LATIN_UPPER_N,  \
                                                   ASCII_CHAR_LATIN_UPPER_O,  \
                                                   ASCII_CHAR_LATIN_UPPER_N,  \
                                                   ASCII_CHAR_LATIN_UPPER_E)

#define  FS_BUF_TYPE_BUF            FS_TYPE_CREATE(ASCII_CHAR_LATIN_UPPER_B,  \
                                                   ASCII_CHAR_LATIN_UPPER_U,  \
                                                   ASCII_CHAR_LATIN_UPPER_F,  \
                                                   ASCII_CHAR_LATIN_UPPER_F)


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
*                                    FILE SYSTEM BUFFER DATA TYPE
*
* Note(s) : (1) Forced word-alignment at start of file system suite buffer NOT required since first data
*               member 'Type' is declared as 'CPU_INT32U'.
*********************************************************************************************************
*/

struct  fs_buf {
    FS_TYPE       Type;                                         /* Type cfg'd @ init : FS_BUF_TYPE_BUF.                 */
    FS_SEC_SIZE   Size;                                         /* Size cfg'd @ init.                                   */

    FS_STATE      State;                                        /* Buf state.                                           */
    FS_SEC_NBR    Start;                                        /* Sec nbr.                                             */
    FS_FLAGS      SecType;                                      /* Sector type.                                         */
    void         *DataPtr;                                      /* Ptr to buf data.                                     */
    FS_VOL       *VolPtr;                                       /* Ptr to vol.                                          */
};


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

void     FSBuf_ModuleInit(FS_QTY        buf_cnt,                /* Initialize buffer module.                            */
                          CPU_SIZE_T    buf_size,
                          FS_ERR       *p_err);


FS_BUF  *FSBuf_Get       (FS_VOL       *p_vol);                 /* Allocate & initialize a buffer.                      */

void     FSBuf_Free      (FS_BUF       *p_buf);                 /* Free a buffer.                                       */


void     FSBuf_Flush     (FS_BUF       *p_buf,                  /* Flush buffer.                                        */
                          FS_ERR       *p_err);

#if (FS_CFG_RD_ONLY_EN == DEF_DISABLED)
void     FSBuf_MarkDirty (FS_BUF       *p_buf,                  /* Mark buffer as dirty.                                */
                          FS_ERR       *p_err);
#endif

void     FSBuf_Set       (FS_BUF       *p_buf,                  /* Set buffer sector.                                   */
                          FS_SEC_NBR    start,
                          FS_FLAGS      sec_type,
                          CPU_BOOLEAN   rd,
                          FS_ERR       *p_err);


/*
*********************************************************************************************************
*                                        CONFIGURATION ERRORS
*********************************************************************************************************
*/
