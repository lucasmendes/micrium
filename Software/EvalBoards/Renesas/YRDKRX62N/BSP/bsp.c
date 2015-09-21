/*
*********************************************************************************************************
*                                         BOARD SUPPORT PACKAGE
*
*                            (c) Copyright 2011; Micrium, Inc.; Weston, FL
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
* Filename      : bsp.c
* Version       : V1.00
* Programmer(s) : FGK
*********************************************************************************************************
*/

#include  <includes.h>
#include  "iodefine.h"

/*
*********************************************************************************************************
*                                              CONSTANTS
*********************************************************************************************************
*/

#define  LED4                   PORTD.DR.BIT.B5
#define  LED5                   PORTE.DR.BIT.B3
#define  LED6                   PORTD.DR.BIT.B2
#define  LED7                   PORTE.DR.BIT.B0
#define  LED8                   PORTD.DR.BIT.B4
#define  LED9                   PORTE.DR.BIT.B2
#define  LED10                  PORTD.DR.BIT.B1
#define  LED11                  PORTD.DR.BIT.B7
#define  LED12                  PORTD.DR.BIT.B3
#define  LED13                  PORTE.DR.BIT.B1
#define  LED14                  PORTD.DR.BIT.B0
#define  LED15                  PORTD.DR.BIT.B6

#define  LED_ON                 0
#define  LED_OFF                1


/*$PAGE*/
/*
*********************************************************************************************************
*                                          LOCAL PROTOTYPES
*********************************************************************************************************
*/

static  void  LED_Init(void);


/*
*********************************************************************************************************
*                                     RENESAS I2C INITIALIZATION
*********************************************************************************************************
*/

void  BSP_RIIC0_Init (void)
{
    CPU_INT32U  dly;


                                                 /* Create Mutex used for exclusive                    */
                                                 /* access of low level RIIC ch 0 access               */
    if (BSP_OS_RIIC0_MutexCreate() != DEF_OK) {
        return;                                  /* mutex could not be created                         */
    }

    BSP_OS_RIIC0_MutexPend();                    /* Request mutex, block until mutex obtained          */

    MSTP(RIIC0)            =  0;                 /* enable RIIC channel 0 in module stop register      */

    PORT1.ICR.BIT.B2       =  1;
    PORT1.ICR.BIT.B3       =  1;

    RIIC0.ICCR1.BIT.ICE    =  0;                 /* RIIC0 disabled                                     */
    RIIC0.ICCR1.BIT.IICRST =  1;                 /* RIIC0 internal reset                               */

    for (dly = 0; dly < 1000000; dly++) {
        ;
    }

    RIIC0.ICCR1.BIT.IICRST =  0;                 /* cancel internal reset                              */

    RIIC0.ICSER.BIT.SAR0E  =  0;                 /* Slave addr in SARL0 and SARU0 disabled             */

    RIIC0.ICMR1.BIT.CKS    =  3;                 /* Pclk / 8                                           */
    RIIC0.ICBRL.BYTE       = 0xFD;
    RIIC0.ICBRH.BYTE       = 0xF8;               /* 96kbps operation                                   */

    RIIC0.ICMR3.BIT.ACKWP  =  1;                 /* enable access to the ACKBT bit in ICMR3            */

    RIIC0.ICFER.BIT.TMOE   =  0;                 /* timeout function disabled                          */
    RIIC0.ICFER.BIT.MALE   =  1;                 /* master arbitration lost detection enabled          */

    RIIC0.ICCR1.BIT.ICE    =  1;                 /* RIIC0 enabled                                      */

    BSP_OS_RIIC0_MutexPost();                    /* release mutex                                      */
}


/*
*********************************************************************************************************
*                                        BSP_RIIC0_MasterRd
*
* Description : This function reads one or more bytes from an I2C connected device.
*
* Argument(s) : addr        is address on the I2C bus of the peripheral.
*
*               p_data      is a pointer for storage of the read data.
*
*               len         is the number of bytes to read.
*
*               start       generate a start condition at the start of the frame.
*********************************************************************************************************
*/

void  BSP_RIIC0_MasterRd (CPU_INT08U    addr,
                          CPU_INT08U   *p_data,
                          CPU_SIZE_T    len,
                          CPU_BOOLEAN   start)
{
    CPU_REG32    dummy;
    CPU_INT08U  *RxData;
    CPU_SIZE_T   RxBytesLeft;


    RxData      = p_data;
    RxBytesLeft = len;

    BSP_OS_RIIC0_MutexPend();                    /* Request mutex, block until mutex obtained          */

    if (start == DEF_TRUE) {                     /* Generate a frame with a start condition            */

        while (RIIC0.ICCR2.BIT.BBSY == 1) {      /* check bus is available                             */
            ;
        }


        RIIC0.ICCR2.BIT.ST = 1;                  /* issue a start condition                            */
    } else {
                                                 /* Generate a frame with a re-start condition         */
        while (RIIC0.ICCR2.BIT.BBSY == 0) {      /* check bus is busy                                  */
            ;
        }


        RIIC0.ICCR2.BIT.RS = 1;                  /* issue a re-start condition                         */

        while (RIIC0.ICCR2.BIT.RS == 1) {        /* wait for completion of re-start                    */
            ;
        }
    }


    while (RIIC0.ICSR2.BIT.TDRE == 0) {          /* transmit slave address                             */
        ;
    }

    RIIC0.ICDRT = (addr << 1 ) | 0x01;

    while (RIIC0.ICSR2.BIT.RDRF == 0) {          /* check ACK                                          */
        ;
    }

    if (RIIC0.ICSR2.BIT.NACKF == 0) {
        if(len > 1) {
            dummy = RIIC0.ICDRR;                 /* ACK ok                                             */

            while (RIIC0.ICSR2.BIT.RDRF == 0) {  /* read data                                          */
                ;
            }

            while (RxBytesLeft > 2) {
                 RxBytesLeft--;
                *RxData = RIIC0.ICDRR;
                 RxData++;
                 while (RIIC0.ICSR2.BIT.RDRF == 0) {
                     ;
                 }
            }

            RIIC0.ICMR3.BIT.WAIT  = 1;           /* enable wait, final byte - 1                        */
            RIIC0.ICMR3.BIT.ACKBT = 1;
           *RxData                = RIIC0.ICDRR;
            RxData++;
        } else {
                                                 /* single byte read                                   */
            RIIC0.ICMR3.BIT.WAIT  = 1;           /* enable wait, dummy read                            */
            RIIC0.ICMR3.BIT.ACKBT = 1;
            dummy                 = RIIC0.ICDRR;
        }
            
        while (RIIC0.ICSR2.BIT.RDRF == 0) {
                ;
        }

        RIIC0.ICSR2.BIT.STOP = 0;                /* read final byte and issue stop condition           */
        RIIC0.ICCR2.BIT.SP   = 1;
       *RxData               = RIIC0.ICDRR;
        RxData++;
        RIIC0.ICMR3.BIT.WAIT = 0;

    } else {

        RIIC0.ICSR2.BIT.STOP = 0;                /* bad ACK                                            */
        RIIC0.ICCR2.BIT.SP   = 1;
        dummy                = RIIC0.ICDRR;
    }

    while (RIIC0.ICSR2.BIT.STOP == 0) {
        ;
    }

    RIIC0.ICSR2.BIT.NACKF = 0;

    RIIC0.ICSR2.BIT.STOP  = 0;

    BSP_OS_RIIC0_MutexPost();                    /* release mutex                                      */
}


/*
*********************************************************************************************************
*                                        BSP_RIIC0_MasterWr
*
* Description : This function writes one or more bytes to an I2C connected device.
*
* Argument(s) : addr        is address on the I2C bus of the peripheral.
*
*               p_data      is a pointer to the data to be written.
*
*               len         is the number of bytes to write.
*
*               stop        generate a stop condition at the end of the frame
*********************************************************************************************************
*/

void  BSP_RIIC0_MasterWr (CPU_INT08U    addr,
                          CPU_INT08U   *p_data,
                          CPU_SIZE_T    len,
                          CPU_BOOLEAN   stop)
{
    CPU_INT08U  *TxData;
    CPU_SIZE_T   TxBytesLeft;


    TxData      = p_data;
    TxBytesLeft = len;

    BSP_OS_RIIC0_MutexPend();                    /* Request mutex, block until mutex obtained          */

    while (RIIC0.ICCR2.BIT.BBSY == 1) {          /* check bus is available                             */
        ;
    }

    RIIC0.ICCR2.BIT.ST = 1;                      /* issue a start condition                            */

    while (RIIC0.ICSR2.BIT.TDRE == 0) {          /* transmit slave address                             */
        ;
    }

    RIIC0.ICDRT        = addr << 1;

    while (TxBytesLeft > 0) {
        if (RIIC0.ICSR2.BIT.NACKF == 0) {
            if (RIIC0.ICSR2.BIT.TDRE == 1) {     /* Ack                                                */
                RIIC0.ICDRT = *p_data;           /* Send Data                                          */
                p_data++;
                TxBytesLeft--;
            }

        } else {

            break;                               /* bad Ack                                            */
        }
    }

    if (TxBytesLeft == 0) {
        while (RIIC0.ICSR2.BIT.TEND == 0) {      /* All bytes transmitted                              */
            ;
        }
    }

    RIIC0.ICSR2.BIT.STOP  = 0;
    if(stop == DEF_TRUE){                       /* Send a stop condition                               */
        RIIC0.ICCR2.BIT.SP    = 1;

        while (RIIC0.ICSR2.BIT.STOP == 0) {
            ;
        }
    }

    RIIC0.ICSR2.BIT.NACKF = 0;
    RIIC0.ICSR2.BIT.STOP  = 0;

    BSP_OS_RIIC0_MutexPost();                    /* release mutex                                      */
}


/*$PAGE*/
/*
*********************************************************************************************************
*                                         BSP INITIALIZATION
*
* Description: This function should be called by the application code before using any functions in this 
*              module.
*
* Arguments  : none
*********************************************************************************************************
*/

void  BSP_Init (void)
{
                                                 /* ------------------- CPG setting ------------------ */
    SYSTEM.SCKCR.LONG = 0x00020100;              /* Clocking = 12MHz                                   */
                                                 /* I Clock  = 96MHz, B Clock = 24MHz,                 */
                                                 /* P Clock  = 48MHz                                   */

    LED_Init();                                  /* Initialize LEDs                                    */

    BSP_RIIC0_Init();                            /* Initialize Renesas I2C controller                  */
}


/*$PAGE*/
/*
*********************************************************************************************************
*                                     PERIPHERAL CLOCK FREQUENCY
*
* Description: This function is used to retrieve peripheral clock frequency.
*
* Arguments  : none
*
* Return     : Peripheral clock frequency in cycles per second.
*********************************************************************************************************
*/

CPU_INT32U  BSP_CPU_PerClkFreq (void)
{
    CPU_INT32U  sys_clk;
    CPU_INT32U  per_clk;
    CPU_INT32U  per_div;


    sys_clk =  SYSTEM.SCKCR.LONG;
    per_div = (sys_clk >> 8u) & 0xFu;
    if (per_div > 3u) {
        return (0u);
    }

    per_clk =  BSP_CPU_EXT_CLK_FREQ << (3u - per_div);
    return (per_clk);
}


/*$PAGE*/
/*
*********************************************************************************************************
*                                       LED INITIALIZATION
*
* Description: This function is used to initialize the LEDs on the board.
*
* Arguments  : none
*********************************************************************************************************
*/

static  void  LED_Init (void)
{
    PORTD.DDR.BIT.B0 = 1;                                       /* Select port function.                                */
    PORTD.DDR.BIT.B1 = 1;
    PORTD.DDR.BIT.B2 = 1;
    PORTD.DDR.BIT.B3 = 1;
    PORTD.DDR.BIT.B4 = 1;
    PORTD.DDR.BIT.B5 = 1;
    PORTD.DDR.BIT.B6 = 1;
    PORTD.DDR.BIT.B7 = 1;
    PORTE.DDR.BIT.B0 = 1;
    PORTE.DDR.BIT.B1 = 1;
    PORTE.DDR.BIT.B2 = 1;
    PORTE.DDR.BIT.B3 = 1;

    LED_Off(0);                                                 /* Turn OFF all LEDs.                                   */
}


/*$PAGE*/
/*
*********************************************************************************************************
*                                               LED ON
*
* Description: This function is used to control any or all the LEDs on the board.
*
* Arguments  : led    is the number of the LED to control
*                     0    indicates that you want ALL the LEDs to be ON
*                     1    turns ON LED1 on the board
*                     .
*                     .
*                     3    turns ON LED3 on the board
*********************************************************************************************************
*/

void  LED_On (CPU_INT08U  led)
{
    switch (led) {
        case 0:
            LED4  = LED_ON;
            LED5  = LED_ON;
            LED6  = LED_ON;
            LED7  = LED_ON;
            LED8  = LED_ON;
            LED9  = LED_ON;
            LED10 = LED_ON;
            LED11 = LED_ON;
            LED12 = LED_ON;
            LED13 = LED_ON;
            LED14 = LED_ON;
            LED15 = LED_ON;
            break;

        case 4:
            LED4  = LED_ON;
            break;

        case 5:
            LED5  = LED_ON;
            break;

        case 6:
            LED6  = LED_ON;
            break;

        case 7:
            LED7  = LED_ON;
            break;

        case 8:
            LED8  = LED_ON;
            break;

        case 9:
            LED9  = LED_ON;
            break;

        case 10:
            LED10 = LED_ON;
            break;

        case 11:
            LED11 = LED_ON;
            break;

        case 12:
            LED12 = LED_ON;
            break;

       case 13:
            LED13 = LED_ON;
            break;

       case 14:
            LED14 = LED_ON;
            break;

       case 15:
            LED15 = LED_ON;
            break;

       default:
            break;
    }
}


/*$PAGE*/
/*
*********************************************************************************************************
*                                               LED OFF
*
* Description: This function is used to control any or all the LEDs on the board.
*
* Arguments  : led    is the number of the LED to turn OFF
*                     0    indicates that you want ALL the LEDs to be OFF
*                     1    turns OFF LED1 on the board
*                     .
*                     .
*                     3    turns OFF LED3 on the board
*********************************************************************************************************
*/

void  LED_Off (CPU_INT08U  led)
{
    switch (led) {
        case 0:
            LED4  = LED_OFF;
            LED5  = LED_OFF;
            LED6  = LED_OFF;
            LED7  = LED_OFF;
            LED8  = LED_OFF;
            LED9  = LED_OFF;
            LED10 = LED_OFF;
            LED11 = LED_OFF;
            LED12 = LED_OFF;
            LED13 = LED_OFF;
            LED14 = LED_OFF;
            LED15 = LED_OFF;
            break;

        case 4:
            LED4  = LED_OFF;
            break;

        case 5:
            LED5  = LED_OFF;
            break;

        case 6:
            LED6  = LED_OFF;
            break;

        case 7:
            LED7  = LED_OFF;
            break;

        case 8:
            LED8  = LED_OFF;
            break;

        case 9:
            LED9  = LED_OFF;
            break;

        case 10:
            LED10 = LED_OFF;
            break;

        case 11:
            LED11 = LED_OFF;
            break;

        case 12:
            LED12 = LED_OFF;
            break;

       case 13:
            LED13 = LED_OFF;
            break;

       case 14:
            LED14 = LED_OFF;
            break;

       case 15:
            LED15 = LED_OFF;
            break;

       default:
            break;
    }
}


/*$PAGE*/
/*
*********************************************************************************************************
*                                             LED TOGGLE
*
* Description: This function is used to toggle the state of any or all the LEDs on the board.
*
* Arguments  : led    is the number of the LED to toggle
*                     0    indicates that you want ALL the LEDs to toggle
*                     1    Toggle LED1 on the board
*                     .
*                     .
*                     3    Toggle LED3 on the board
*********************************************************************************************************
*/

void  LED_Toggle (CPU_INT08U  led)
{
    switch (led) {
        case 0:
            LED4  = ~LED4;
            LED5  = ~LED5;
            LED6  = ~LED6;
            LED7  = ~LED7;
            LED8  = ~LED8;
            LED9  = ~LED9;
            LED10 = ~LED10;
            LED11 = ~LED11;
            LED12 = ~LED12;
            LED13 = ~LED13;
            LED14 = ~LED14;
            LED15 = ~LED15;
            break;

        case 4:
            LED4  = ~LED4;
            break;

        case 5:
            LED5  = ~LED5;
            break;

        case 6:
            LED6  = ~LED6;
            break;

        case 7:
            LED7  = ~LED7;
            break;

        case 8:
            LED8  = ~LED8;
            break;

        case 9:
            LED9  = ~LED9;
            break;

        case 10:
            LED10 = ~LED10;
            break;

        case 11:
            LED11 = ~LED11;
            break;

        case 12:
            LED12 = ~LED12;
            break;

       case 13:
            LED13 = ~LED13;
            break;

       case 14:
            LED14 = ~LED14;
            break;

       case 15:
            LED15 = ~LED15;
            break;

       default:
            break;
    }
}
