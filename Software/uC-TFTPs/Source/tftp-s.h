/*
*********************************************************************************************************
*                                              uC/TFTPs
*                               Trivial File Transfer Protocol (server)
*
*                          (c) Copyright 2005-2010; Micrium, Inc.; Weston, FL
*
*               All rights reserved.  Protected by international copyright laws.
*
*               uC/TFTPs is provided in source form to registered licensees ONLY.  It is
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
*                                             TFTP SERVER
*
* Filename      : tftp-s.h
* Version       : V1.91.01
* Programmer(s) : JJL
*                 JDH
*                 SR
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                                               MODULE
*
* Note(s) : (1) This header file is protected from multiple pre-processor inclusion through use of the
*               TFTPs present pre-processor macro definition.
*********************************************************************************************************
*/

#ifndef  TFTPs_PRESENT                                          /* See Note #1.                                         */
#define  TFTPs_PRESENT


/*
*********************************************************************************************************
*                                        TFTPs VERSION NUMBER
*
* Note(s) : (1) (a) The TFTPs module software version is denoted as follows :
*
*                       Vx.yy.zz
*
*                           where
*                                   V               denotes 'Version' label
*                                   x               denotes     major software version revision number
*                                   yy              denotes     minor software version revision number
*                                   zz              denotes sub-minor software version revision number
*
*               (b) The TFTPs software version label #define is formatted as follows :
*
*                       ver = x.yyzz * 100 * 100
*
*                           where
*                                   ver             denotes software version number scaled as an integer value
*                                   x.yyzz          denotes software version number, where the unscaled integer 
*                                                       portion denotes the major version number & the unscaled 
*                                                       fractional portion denotes the (concatenated) minor 
*                                                       version numbers
*********************************************************************************************************
*/

#define  TFTPs_VERSION                                 19101u   /* See Note #1.                                         */


/*
*********************************************************************************************************
*                                               EXTERNS
*********************************************************************************************************
*/

#ifdef   TFTPs_MODULE
#define  TFTPs_EXT
#else
#define  TFTPs_EXT  extern
#endif


/*$PAGE*/
/*
*********************************************************************************************************
*                                            INCLUDE FILES
*
* Note(s) : (1) The TFTPs module files are located in the following directories :
*
*               (a) \<Your Product Application>\app_cfg.h
*
*               (b) \<Network Protocol Suite>\Source\net_*.*
*
*               (c) (1) \<TFTPs>\Source\tftp-s.h
*                                      \tftp-s.c
*
*                   (2) \<TFTPs>\OS\<os>\tftp-s_os.*
*
*                   (3) \<TFTPs>\FS\<fs>\apps_fs.*
*
*                       where
*                               <Your Product Application>      directory path for Your Product's Application
*                               <Network Protocol Suite>        directory path for network protocol suite
*                               <TFTPs>                         directory path for TFTPs module
*                               <os>                            directory name for specific operating system (OS)
*                               <fs>                            directory name for specific file      system (FS)
*
*           (2) CPU-configuration software files are located in the following directories :
*
*               (a) \<CPU-Compiler Directory>\cpu_*.*
*               (b) \<CPU-Compiler Directory>\<cpu>\<compiler>\cpu*.*
*
*                       where
*                               <CPU-Compiler Directory>        directory path for common CPU-compiler software
*                               <cpu>                           directory name for specific processor (CPU)
*                               <compiler>                      directory name for specific compiler
*
*           (3) NO compiler-supplied standard library functions SHOULD be used.
*
*               (a) Standard library functions are implemented in the custom library module(s) :
*
*                       \<Custom Library Directory>\lib_*.*
*
*                           where
*                                   <Custom Library Directory>      directory path for custom library software
*
*               (b) #### The reference to standard library header files SHOULD be removed once all custom
*                   library functions are implemented WITHOUT reference to ANY standard library function(s).
*
*           (4) Compiler MUST be configured to include as additional include path directories :
*
*               (a) '\<Your Product Application>\' directory                            See Note #1a
*
*               (b) '\<Network Protocol Suite>\'   directory                            See Note #1b
*
*               (c) '\<TFTPs>\' directories                                             See Note #1c
*
*               (d) (1) '\<CPU-Compiler Directory>\'                  directory         See Note #2a
*                   (2) '\<CPU-Compiler Directory>\<cpu>\<compiler>\' directory         See Note #2b
*
*               (e) '\<Custom Library Directory>\' directory                            See Note #3a
*********************************************************************************************************
*/

#include  <cpu.h>                                               /* CPU Configuration              (see Note #2b)        */
#include  <cpu_core.h>                                          /* CPU Core Library               (see Note #2a)        */

#include  <lib_def.h>                                           /* Standard        Defines        (see Note #3a)        */
#include  <lib_str.h>                                           /* Standard String Library        (see Note #3a)        */

#include  <app_cfg.h>                                           /* Application Configuration File (see Note #1a)        */
#include  <apps_fs.h>                                           /* File System Interface          (see Note #1c3)       */

#include  <net.h>                                               /* Network Protocol Suite         (see Note #1b)        */

#if 1                                                           /* See Note #3b.                                        */
#include  <stdio.h>
#endif


/*$PAGE*/
/*
*********************************************************************************************************
*                                        TFTP SPECIFIC DEFINES
*********************************************************************************************************
*/

#define  TFTP_PKT_OFFSET_OPCODE                            0
#define  TFTP_PKT_OFFSET_FILENAME                          2
#define  TFTP_PKT_OFFSET_BLK_NBR                           2
#define  TFTP_PKT_OFFSET_ERR_CODE                          2
#define  TFTP_PKT_OFFSET_ERR_MSG                           4
#define  TFTP_PKT_OFFSET_DATA                              4

#define  TFTP_PKT_SIZE_OPCODE                              2
#define  TFTP_PKT_SIZE_BLK_NBR                             2
#define  TFTP_PKT_SIZE_ERR_CODE                            2
#define  TFTP_PKT_SIZE_FILENAME_NUL                        1
#define  TFTP_PKT_SIZE_MODE_NUL                            1

                                                                /* ---- TFTP opcodes (see Stevens p. 466) ------------- */
#define  TFTP_OPCODE_RD_REQ                                1    /* Read                                                 */
#define  TFTP_OPCODE_WR_REQ                                2    /* Write                                                */
#define  TFTP_OPCODE_DATA                                  3    /* Data                                                 */
#define  TFTP_OPCODE_ACK                                   4    /* Acknowledge                                          */
#define  TFTP_OPCODE_ERR                                   5    /* Error                                                */

                                                                /* ---- TFTP error codes ------------------------------ */
#define  TFTP_ERR_NONE                                     0
#define  TFTP_ERR_RD_REQ                                   1
#define  TFTP_ERR_WR_REQ                                   2
#define  TFTP_ERR_DATA                                     3
#define  TFTP_ERR_ACK                                      4
#define  TFTP_ERR_ERR                                      5
#define  TFTP_ERR_INVALID_STATE                            6
#define  TFTP_ERR_FILE_NOT_FOUND                           7
#define  TFTP_ERR_TX                                       8
#define  TFTP_ERR_FILE_RD                                  9
#define  TFTP_ERR_TIMED_OUT                               10
#define  TFTP_ERR_NO_SOCK                                 11    /* No socket available.                                 */
#define  TFTP_ERR_CANT_BIND                               12    /* Could not bind to the TFTPs port.                    */


/*
*********************************************************************************************************
*                                       TFTPs SPECIFIC DEFINES
*********************************************************************************************************
*/

                                                                /* ---- TFTP Server error codes: (see Stevens p. 467) - */
#define  TFTPs_ERR_ERR_STR                                 0    /* Not defined.                                         */
#define  TFTPs_ERR_FILE_NOT_FOUND                          1    /* File not found.                                      */
#define  TFTPs_ERR_ACCESS_VIOLATION                        2    /* Access violation.                                    */
#define  TFTPs_ERR_DISK_FULL                               3    /* Disk full.                                           */
#define  TFTPs_ERR_ILLEGAL_OP                              4    /* Illegal TFTP operation.                              */
#define  TFTPs_ERR_BAD_PORT_NBR                            5    /* Unknown port number.                                 */
#define  TFTPs_ERR_FILE_EXISTS                             6    /* File already exists.                                 */
#define  TFTPs_ERR_NO_SUCH_USER                            7    /* No such user.                                        */

                                                                /* ---- TFTP Server modes ----------------------------- */
#define  TFTPs_MODE_OCTET                                  1
#define  TFTPs_MODE_NETASCII                               2

                                                                /* ---- TFTP Server states ---------------------------- */
#define  TFTPs_STATE_IDLE                                  0
#define  TFTPs_STATE_DATA_RD                               1
#define  TFTPs_STATE_DATA_WR                               2

#define  TFTPs_BLOCK_SIZE                                512
#define  TFTPs_BUF_SIZE                         (TFTPs_BLOCK_SIZE + TFTP_PKT_SIZE_OPCODE + TFTP_PKT_SIZE_BLK_NBR)


/*
*********************************************************************************************************
*                                         TFTPs TRACE DEFINE
*********************************************************************************************************
*/

#define  TFTPs_TRACE_STR_SIZE                             80    /* Trace string size.                                   */


/*
*********************************************************************************************************
*                                             DATA TYPES
*********************************************************************************************************
*/

typedef  CPU_INT16U  TFTP_ERR;


/*$PAGE*/
/*
*********************************************************************************************************
*                                         FUNCTION PROTOTYPES
*********************************************************************************************************
*/

CPU_BOOLEAN  TFTPs_Init       (void);
void         TFTPs_En         (void);
void         TFTPs_Dis        (void);

void         TFTPs_Task       (void        *p_arg);

#if (TFTPs_TRACE_LEVEL >= TRACE_LEVEL_INFO)
void         TFTPs_Disp       (void);
void         TFTPs_DispTrace  (void);
#endif


/*
*********************************************************************************************************
*                                         FUNCTION PROTOTYPES
*                                    DEFINED IN OS'S  tftp-s_os.c
*********************************************************************************************************
*/

CPU_BOOLEAN  TFTPs_OS_Init    (void        *p_arg);

CPU_INT32U   TFTPs_OS_GetTime (void);


/*
*********************************************************************************************************
*                                               TRACING
*********************************************************************************************************
*/

                                                                /* Trace level, default to TRACE_LEVEL_OFF              */
#ifndef  TRACE_LEVEL_OFF
#define  TRACE_LEVEL_OFF                                 0
#endif

#ifndef  TRACE_LEVEL_INFO
#define  TRACE_LEVEL_INFO                                1
#endif

#ifndef  TRACE_LEVEL_DBG
#define  TRACE_LEVEL_DBG                                 2
#endif

#ifndef  TFTPs_TRACE_LEVEL
#define  TFTPs_TRACE_LEVEL                      TRACE_LEVEL_OFF
#endif

#ifndef  TFTPs_TRACE
#define  TFTPs_TRACE                            printf
#endif

#define  TFTPs_TRACE_INFO(x)                  ((TFTPs_TRACE_LEVEL >= TRACE_LEVEL_INFO) ? (void)(TFTPs_TRACE x) : (void)0)
#define  TFTPs_TRACE_DBG(x)                   ((TFTPs_TRACE_LEVEL >= TRACE_LEVEL_DBG)  ? (void)(TFTPs_TRACE x) : (void)0)


/*$PAGE*/
/*
*********************************************************************************************************
*                                        CONFIGURATION ERRORS
*********************************************************************************************************
*/

#ifndef  TFTPs_CFG_IPPORT
#error  "TFTPs_CFG_IPPORT                   not #define'd in 'app_cfg.h'"
#error  "                             see template file in package      "
#error  "                             named 'tftp-s_cfg.h'              "
#endif




#ifndef  TFTPs_CFG_MAX_RX_TIMEOUT_MS
#error  "TFTPs_CFG_MAX_RX_TIMEOUT_MS        not #define'd in 'app_cfg.h'"
#error  "                             see template file in package      "
#error  "                             named 'tftp-s_cfg.h'              "
#endif


#ifndef  TFTPs_CFG_MAX_TX_TIMEOUT_MS
#error  "TFTPs_CFG_MAX_TX_TIMEOUT_MS        not #define'd in 'app_cfg.h'"
#error  "                             see template file in package      "
#error  "                             named 'tftp-s_cfg.h'              "
#endif




#if     (TFTPs_TRACE_LEVEL >= TRACE_LEVEL_INFO)

#ifndef  TFTPs_TRACE_HIST_SIZE
#error  "TFTPs_TRACE_HIST_SIZE              not #define'd in 'app_cfg.h'"
#error  "                             see template file in package      "
#error  "                             named 'tftp-s_cfg.h'              "

#elif   (TFTPs_TRACE_HIST_SIZE < 16)
#error  "TFTPs_TRACE_HIST_SIZE        illegally #define'd in 'app_cfg.h'"
#error  "                             [MUST be  >= 16]                  "
#endif

#endif


/*
*********************************************************************************************************
*                                    NETWORK CONFIGURATION ERRORS
*********************************************************************************************************
*/

#if    ((NET_UDP_CFG_APP_API_SEL != NET_UDP_APP_API_SEL_SOCK    ) && \
        (NET_UDP_CFG_APP_API_SEL != NET_UDP_APP_API_SEL_SOCK_APP))
#error  "NET_UDP_CFG_APP_API_SEL     illegally #define'd in 'net_cfg.h'     "
#error  "                            [MUST be  NET_UDP_APP_API_SEL_SOCK    ]"
#error  "                            [     ||  NET_UDP_APP_API_SEL_SOCK_APP]"
#endif


/*
*********************************************************************************************************
*                                             MODULE END
*********************************************************************************************************
*/

#endif                                                          /* End of TFTPs module include.                         */
