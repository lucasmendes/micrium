/*
*********************************************************************************************************
*                                         BOARD SUPPORT PACKAGE
*
*                            (c) Copyright 2010; Micrium, Inc.; Weston, FL
*
*               All rights reserved. Protected by international copyright laws.
*
*               BSP is provided in source form to registered licensees ONLY.  It is
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
*                                         BOARD SUPPORT PACKAGE
*
*                                              Renesas RX62N
*                                                on the
*                                      RSK-2+RX62N Evaluation Board
*
* Filename      : bsp_ser.c
* Version       : V1.00
* Programmer(s) : FGK
*********************************************************************************************************
*/

#include  <includes.h>
#include  "iodefine.h"
#include  <stdarg.h>
#include  <stdio.h>

int vsnprintf(char *str, size_t str_m, const char *fmt, va_list ap);

/*
*********************************************************************************************************
*                                            LOCAL DEFINES
*********************************************************************************************************
*/

#if   (BSP_CFG_SER_COMM_SEL == 0)
#define  BSP_SER                          SCI0
#elif (BSP_CFG_SER_COMM_SEL == 1)
#define  BSP_SER                          SCI1
#elif (BSP_CFG_SER_COMM_SEL == 2)
#define  BSP_SER                          SCI2
#elif (BSP_CFG_SER_COMM_SEL == 3)
#define  BSP_SER                          SCI3
#elif (BSP_CFG_SER_COMM_SEL == 4)
#define  BSP_SER                          SCI4
#elif (BSP_CFG_SER_COMM_SEL == 5)
#define  BSP_SER                          SCI5
#elif (BSP_CFG_SER_COMM_SEL == 6)
#define  BSP_SER                          SCI6
#endif


/*
*********************************************************************************************************
*                                      LOCAL FUNCTION PROTOTYPES
*********************************************************************************************************
*/

static  void        BSP_Ser_CfgGPIO     (void);

static  void        BSP_Ser_En          (void);

static  void        BSP_Ser_CfgIntCtrl  (void);

static  CPU_INT16U  BSP_Ser_GetBRR      (CPU_INT08U  bclk,
                                         CPU_INT32U  baud_rate);


/*
*********************************************************************************************************
*********************************************************************************************************
*                                         GLOBAL FUNCTIONS
*********************************************************************************************************
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                                           BSP_Ser_Init()
*
* Description : Initialize serial module for communication.
*
* Argument(s) : baud_rate   Baud rate of RS-232.
*
* Return(s)   : none.
*********************************************************************************************************
*/

void  BSP_Ser_Init (CPU_INT32U  baud_rate)
{
    CPU_INT08U  baud_clk;
    CPU_INT16U  brr;
    CPU_REG32   i;


    BSP_Ser_En();
    
    BSP_SER.SCR.BIT.TIE  = 0;                                   /* Disable transmit interrupts                          */
    BSP_SER.SCR.BIT.RIE  = 0;                                   /* Disable receive interrupts                           */
    BSP_SER.SCR.BIT.TE   = 0;                                   /* Disable transmitter                                  */
    BSP_SER.SCR.BIT.RE   = 0;                                   /* Disable receiver                                     */
    BSP_SER.SCR.BIT.TEIE = 0;                                   /* Disable transmit end interrupts                      */

    BSP_Ser_CfgGPIO();
    BSP_Ser_CfgIntCtrl();

                                                                /* Read each flag before clearing                       */
    BSP_SER.SSR.BIT.TEND;
    BSP_SER.SSR.BIT.TEND = 0;
    BSP_SER.SSR.BIT.PER;
    BSP_SER.SSR.BIT.PER  = 0;
    BSP_SER.SSR.BIT.FER;
    BSP_SER.SSR.BIT.FER  = 0;
    BSP_SER.SSR.BIT.ORER;
    BSP_SER.SSR.BIT.ORER = 0;

    BSP_SER.SCR.BIT.CKE  = 0;                                   /* Use internal clock, set SCK pin as input pin         */
    BSP_SER.SMR.BIT.CM   = 0;                                   /* Set for asynchronous mode                            */
    BSP_SER.SMR.BIT.CHR  = 0;                                   /* 8-bit data                                           */
    BSP_SER.SMR.BIT.PE   = 0;                                   /* Parity mode disabled                                 */
    BSP_SER.SMR.BIT.PM   = 0;                                   /* No parity                                            */
    BSP_SER.SMR.BIT.STOP = 0;                                   /* 1 stop bit                                           */

    baud_clk = 0;                                               /* Algorithm for finding BRR value                      */
    do {                                                        /* N = BRR (0-255), B = bit rate, n = baud clock        */
        brr = BSP_Ser_GetBRR(baud_clk, baud_rate);              /* N = Pclk / (64 * 2^(2 * n - 1) * B) - 1              */
        if (brr > 255) {
             baud_clk++;
        }
    } while (brr > 255);

    BSP_SER.SMR.BIT.CKS = baud_clk;
//    BSP_SER.BRR         = brr + 1;
    BSP_SER.BRR         = brr;

    for (i = 0; i < 10000; i++);                                /* Wait for at least 1 bit time                         */

    BSP_SER.SCR.BIT.TIE = 0;                                    /* Enable Transmit Interrupts                           */
    BSP_SER.SCR.BIT.RIE = 1;                                    /* Enable Receive Interrupts                            */
    BSP_SER.SCR.BYTE |= DEF_BIT_05 | DEF_BIT_04;                /* Enable Tx & Rx (cannot be done thru bit-fields).     */
}

/*
*********************************************************************************************************
*                                        BSP_Ser_CfgIntCtrl()
*
* Description : Set interrupt vectors within interrupt table.
*
* Argument(s) : none.
*
* Return(s)   : none.
*********************************************************************************************************
*/

static  void  BSP_Ser_CfgIntCtrl (void)
{
#if   (BSP_CFG_SER_COMM_SEL == 0)
    IR(SCI0, ERI0) = 0;                                         /* Clear any pending ISR.                               */
    IR(SCI0, RXI0) = 0;
    IR(SCI0, TXI0) = 0;
    IR(SCI0, TEI0) = 0;

    IPR(SCI0, ERI0) = 3;                                        /* Set interrupt priority.                              */
    IPR(SCI0, RXI0) = 3;
    IPR(SCI0, TXI0) = 3;
    IPR(SCI0, TEI0) = 3;
    
    IEN(SCI0, ERI0) = 1;                                        /* Enable interrupt source.                             */
    IEN(SCI0, RXI0) = 1;
    IEN(SCI0, TXI0) = 1;
    IEN(SCI0, TEI0) = 1;

#elif (BSP_CFG_SER_COMM_SEL == 1)
    IR(SCI1, ERI1) = 0;                                         /* Clear any pending ISR.                               */
    IR(SCI1, RXI1) = 0;
    IR(SCI1, TXI1) = 0;
    IR(SCI1, TEI1) = 0;

    IPR(SCI1, ERI1) = 3;                                        /* Set interrupt priority.                              */
    IPR(SCI1, RXI1) = 3;
    IPR(SCI1, TXI1) = 3;
    IPR(SCI1, TEI1) = 3;

    IEN(SCI1, ERI1) = 1;                                        /* Enable interrupt source.                             */
    IEN(SCI1, RXI1) = 1;
    IEN(SCI1, TXI1) = 1;
    IEN(SCI1, TEI1) = 1;

#elif (BSP_CFG_SER_COMM_SEL == 2)
    IR(SCI2, ERI2) = 0;                                         /* Clear any pending ISR.                               */
    IR(SCI2, RXI2) = 0;
    IR(SCI2, TXI2) = 0;
    IR(SCI2, TEI2) = 0;

    IPR(SCI2, ERI2) = 3;                                        /* Set interrupt priority.                              */
    IPR(SCI2, RXI2) = 3;
    IPR(SCI2, TXI2) = 3;
    IPR(SCI2, TEI2) = 3;

    IEN(SCI2, ERI2) = 1;                                        /* Enable interrupt source.                             */
    IEN(SCI2, RXI2) = 1;
    IEN(SCI2, TXI2) = 1;
    IEN(SCI2, TEI2) = 1;

#elif (BSP_CFG_SER_COMM_SEL == 3)
    IR(SCI3, ERI3) = 0;                                         /* Clear any pending ISR.                               */
    IR(SCI3, RXI3) = 0;
    IR(SCI3, TXI3) = 0;
    IR(SCI3, TEI3) = 0;

    IPR(SCI3, ERI3) = 3;                                        /* Set interrupt priority.                              */
    IPR(SCI3, RXI3) = 3;
    IPR(SCI3, TXI3) = 3;
    IPR(SCI3, TEI3) = 3;

    IEN(SCI3, ERI3) = 1;                                        /* Enable interrupt source.                             */
    IEN(SCI3, RXI3) = 1;
    IEN(SCI3, TXI3) = 1;
    IEN(SCI3, TEI3) = 1;

#elif (BSP_CFG_SER_COMM_SEL == 4)
    IR(SCI4, ERI4) = 0;                                         /* Clear any pending ISR.                               */
    IR(SCI4, RXI4) = 0;
    IR(SCI4, TXI4) = 0;
    IR(SCI4, TEI4) = 0;

    IPR(SCI4, ERI4) = 3;                                        /* Set interrupt priority.                              */
    IPR(SCI4, RXI4) = 3;
    IPR(SCI4, TXI4) = 3;
    IPR(SCI4, TEI4) = 3;

    IEN(SCI4, ERI4) = 1;                                        /* Enable interrupt source.                             */
    IEN(SCI4, RXI4) = 1;
    IEN(SCI4, TXI4) = 1;
    IEN(SCI4, TEI4) = 1;

#elif (BSP_CFG_SER_COMM_SEL == 5)
    IR(SCI5, ERI5) = 0;                                         /* Clear any pending ISR.                               */
    IR(SCI5, RXI5) = 0;
    IR(SCI5, TXI5) = 0;
    IR(SCI5, TEI5) = 0;

    IPR(SCI5, ERI5) = 3;                                        /* Set interrupt priority.                              */
    IPR(SCI5, RXI5) = 3;
    IPR(SCI5, TXI5) = 3;
    IPR(SCI5, TEI5) = 3;

    IEN(SCI5, ERI5) = 1;                                        /* Enable interrupt source.                             */
    IEN(SCI5, RXI5) = 1;
    IEN(SCI5, TXI5) = 1;
    IEN(SCI5, TEI5) = 1;

#elif (BSP_CFG_SER_COMM_SEL == 6)
    IR(SCI6, ERI6) = 0;                                         /* Clear any pending ISR.                               */
    IR(SCI6, RXI6) = 0;
    IR(SCI6, TXI6) = 0;
    IR(SCI6, TEI6) = 0;

    IPR(SCI6, ERI6) = 3;                                        /* Set interrupt priority.                              */
    IPR(SCI6, RXI6) = 3;
    IPR(SCI6, TXI6) = 3;
    IPR(SCI6, TEI6) = 3;

    IEN(SCI6, ERI6) = 1;                                        /* Enable interrupt source.                             */
    IEN(SCI6, RXI6) = 1;
    IEN(SCI6, TXI6) = 1;
    IEN(SCI6, TEI6) = 1;
#endif
}


/*
*********************************************************************************************************
*                                            BSP_Ser_En()
*
* Description : Enable serial module.
*
* Argument(s) : none.
*
* Return(s)   : none.
*********************************************************************************************************
*/

static  void  BSP_Ser_En (void)
{
#if   (BSP_CFG_SER_COMM_SEL == 0)
    MSTP(SCI0) = 0;
#elif (BSP_CFG_SER_COMM_SEL == 1)
    MSTP(SCI1) = 0;
#elif (BSP_CFG_SER_COMM_SEL == 2)
    MSTP(SCI2) = 0;
#elif (BSP_CFG_SER_COMM_SEL == 3)
    MSTP(SCI3) = 0;
#elif (BSP_CFG_SER_COMM_SEL == 4)
    MSTP(SCI4) = 0;
#elif (BSP_CFG_SER_COMM_SEL == 5)
    MSTP(SCI5) = 0;
#elif (BSP_CFG_SER_COMM_SEL == 6)
    MSTP(SCI6) = 0;
#endif
}


/*
*********************************************************************************************************
*                                          BSP_Ser_CfgGPIO()
*
* Description : Configures the necessary port pins.
*
* Argument(s) : none.
*
* Return(s)   : none.
*********************************************************************************************************
*/

static  void  BSP_Ser_CfgGPIO (void)
{
#if   (BSP_CFG_SER_COMM_SEL == 0)
    PORT2.ICR.BIT.B0 = 0;                                       /* TxD0                                                 */
	PORT2.DDR.BIT.B0 = 1;
    PORT2.ICR.BIT.B1 = 1;                                       /* RxD0                                                 */
	PORT2.DDR.BIT.B1 = 0;


#elif (BSP_CFG_SER_COMM_SEL == 1)

#ifndef BSP_CFG_SER_ALT_SEL
    IOPORT.PFFSCI.BIT.SCI1S = 0;
    PORT2.ICR.BIT.B6 = 0;                                       /* TxD1-A                                               */
	PORT2.DDR.BIT.B6 = 1;
    PORT3.ICR.BIT.B0 = 1;                                       /* RxD1-A                                               */
	PORT3.DDR.BIT.B0 = 0;
#else
    IOPORT.PFFSCI.BIT.SCI1S = 1;
    PORTF.ICR.BIT.B0 = 0;                                       /* TxD1-B                                               */
	PORTF.DDR.BIT.B0 = 1;
    PORTF.ICR.BIT.B2 = 1;                                       /* RxD1-B                                               */
	PORTF.DDR.BIT.B2 = 0;
#endif


#elif (BSP_CFG_SER_COMM_SEL == 2)
#ifndef BSP_CFG_SER_ALT_SEL
    IOPORT.PFFSCI.BIT.SCI2S = 0;
    PORT1.ICR.BIT.B3 = 0;                                       /* TxD2-A                                               */
	PORT1.DDR.BIT.B3 = 1;
    PORT1.ICR.BIT.B2 = 1;                                       /* RxD2-A                                               */
	PORT1.DDR.BIT.B2 = 0;
#else
    IOPORT.PFFSCI.BIT.SCI2S = 1;
    PORT5.ICR.BIT.B0 = 0;                                       /* TxD2-B                                               */
	PORT5.DDR.BIT.B0 = 1;
    PORT5.ICR.BIT.B2 = 1;                                       /* RxD2-B                                               */
	PORT5.DDR.BIT.B2 = 0;
#endif


#elif (BSP_CFG_SER_COMM_SEL == 3)
#ifndef BSP_CFG_SER_ALT_SEL
    IOPORT.PFFSCI.BIT.SCI3S = 0;
    PORT1.ICR.BIT.B7 = 0;                                       /* TxD3-A                                               */
	PORT1.DDR.BIT.B7 = 1;
    PORT1.ICR.BIT.B6 = 1;                                       /* RxD3-A                                               */
	PORT1.DDR.BIT.B6 = 0;
#else
    IOPORT.PFFSCI.BIT.SCI3S = 1;
    PORT2.ICR.BIT.B3 = 0;                                       /* TxD3-B                                               */
	PORT2.DDR.BIT.B3 = 1;
    PORT2.ICR.BIT.B5 = 1;                                       /* RxD3-B                                               */
	PORT2.DDR.BIT.B5 = 0;
#endif


#elif (BSP_CFG_SER_COMM_SEL == 4)

#elif (BSP_CFG_SER_COMM_SEL == 5)
    PORTC.ICR.BIT.B3 = 0;                                       /* TxD5                                                 */
	PORTC.DDR.BIT.B3 = 1;
    PORTC.ICR.BIT.B2 = 1;                                       /* RxD5                                                 */
	PORTC.DDR.BIT.B2 = 0;

#elif (BSP_CFG_SER_COMM_SEL == 6)
#ifndef BSP_CFG_SER_ALT_SEL
    IOPORT.PFFSCI.BIT.SCI6S = 0;
    PORT0.ICR.BIT.B0 = 0;                                       /* TxD6-A                                               */
	PORT0.DDR.BIT.B0 = 1;
    PORT0.ICR.BIT.B1 = 1;                                       /* RxD6-A                                               */
	PORT0.DDR.BIT.B1 = 0;
#else
    IOPORT.PFFSCI.BIT.SCI6S = 1;
    PORT3.ICR.BIT.B2 = 0;                                       /* TxD6-B                                               */
	PORT3.DDR.BIT.B2 = 1;
    PORT3.ICR.BIT.B3 = 1;                                       /* RxD6-B                                               */
	PORT3.DDR.BIT.B3 = 0;
#endif
#endif
}


/*
*********************************************************************************************************
*                                          BSP_Ser_GetBRR()
*
* Description   : Calculate BRR for the settings chosen.
*
* Argument      : bclk          Baud rate generator clock source (0-3)
*
*                 baud_rate     Baud rate.
*
* Returns       : Calculated BRR.
*********************************************************************************************************
*/

static  CPU_INT16U  BSP_Ser_GetBRR (CPU_INT08U  bclk,
                                    CPU_INT32U  baud_rate)
{
    CPU_INT16U  mult;
    CPU_INT16U  val;

                                                                /* Switch for (64 * 2^(2 * baud_clk - 1)) values.       */
    switch (bclk) {
        case 0:
             mult = 32;
             break;
             
        case 1:
             mult = 128;
             break;
             
        case 2:
             mult = 512;
             break;
             
        case 3:
        default:
             mult = 2048;
             break;
    }

    val =  BSP_CPU_PerClkFreq() / (mult * baud_rate) - 1;

    return (val);
}

/*
*********************************************************************************************************
*                                          BSP_Ser_ByteWr()
*
* Description : Transmit one byte.
*
* Argument(s) : data        Byte to transmit.
*
* Return(s)   : none.
*********************************************************************************************************
*/

void  BSP_Ser_ByteWr (CPU_CHAR  data)
{
    BSP_SER.TDR = data;                                         /* Place character to be transmitted into register      */

    while (BSP_SER.SSR.BIT.TEND == 0);
}


void BSP_Ser_printf (const  CPU_CHAR  *fmt, /*args*/ ...)
{
           CPU_CHAR     buf[80 + 1];
    const  CPU_CHAR    *p_buf;
           CPU_SIZE_T   pos;
           va_list      args;


    va_start(args, fmt);
    vsnprintf((char *)buf, sizeof(buf) - 1, (char const *)fmt, args);
    va_end(args);

    p_buf = buf;
    pos   = sizeof(buf) - 1;
    while (( p_buf != (CPU_CHAR *)0) &&
           (*p_buf != '\0') &&
           ( pos   >   0)) {
               
        BSP_Ser_ByteWr(*p_buf);
        
        if (*p_buf == '\n') {
            BSP_Ser_ByteWr('\r');
        }
        
        p_buf++;
        pos++;
    }
}

