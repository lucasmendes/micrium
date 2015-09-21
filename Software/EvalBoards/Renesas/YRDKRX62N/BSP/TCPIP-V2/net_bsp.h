/*
*********************************************************************************************************
*                                             uC/TCP-IP V2
*                                      The Embedded TCP/IP Suite
*
*                          (c) Copyright 2003-2011; Micrium, Inc.; Weston, FL
*
*               All rights reserved.  Protected by international copyright laws.
*
*               uC/TCP-IP is provided in source form to registered licensees ONLY.  It is 
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
*                            NETWORK BOARD SUPPORT PACKAGE (BSP) FUNCTIONS
*
*                                         Renesas RSK2+RX62N
*
* Filename      : net_bsp.h
* Version       : V2.11.02
* Programmer(s) : ITJ
*********************************************************************************************************
* Note(s)       : (1) To provide the required Board Support Package functionality, insert the appropriate 
*                     board-specific code to perform the stated actions wherever '$$$$' comments are found.
*
*                     #### This note MAY be entirely removed for specific board support packages.
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                               EXTERNS
*********************************************************************************************************
*/

#if ((defined(NET_BSP_MODULE)) && \
     (defined(NET_GLOBALS_EXT)))
#define  NET_BSP_EXT
#else
#define  NET_BSP_EXT  extern
#endif


/*$PAGE*/
/*
*********************************************************************************************************
*                                               DEFINES
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                           NETWORK BOARD SUPPORT PACKAGE (BSP) ERROR CODES
*
* Note(s) : (1) ALL BSP-independent error codes #define'd in      'net_err.h';
*               ALL BSP-specific    error codes #define'd in this 'net_bsp.h'.
*
*           (2) Network error code '10000' series reserved for network BSP errors.
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

extern  const  NET_DEV_BSP_ETHER  NetDev_BSP_RSK2_RX62N;


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

