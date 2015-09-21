/*
*********************************************************************************************************
*                                         BOARD SUPPORT PACKAGE
*
*                            (c) Copyright 2010; Micrium, Inc.; Weston, FL
*                    All rights reserved.  Protected by international copyright laws.
*
*                                      Renesas RX Specific code
*
* File      : BSP_TICK_C.C
* By        : FGK
*
* LICENSING TERMS:
* ---------------
*             BSP is provided in source form to registered licensees ONLY.  It is 
*             illegal to distribute this source code to any third party unless you receive 
*             written permission by an authorized Micrium representative.  Knowledge of 
*             the source code may NOT be used to develop a similar product.
*
*             Please help us continue to provide the Embedded community with the finest
*             software available.  Your honesty is greatly appreciated.
*
*             You can contact us at www.micrium.com.
*********************************************************************************************************
*/

#ifdef VSC_INCLUDE_SOURCE_FILE_NAMES
const  CPU_CHAR  *bsp_tick_c__c = "$Id: $";
#endif

/*$PAGE*/
/*
*********************************************************************************************************
*                                             INCLUDE FILES
*********************************************************************************************************
*/

#include  <includes.h>
#include  <bsp.h>
#include  "iodefine.h"


/*$PAGE*/
/*
*********************************************************************************************************
*                                       OS_CPU_TickInit()
*
* Description : Initialize the timer 0 to generate the tick interrupt.
*
* Argument(s) : none.
*
* Caller(s)   : Application.
*
* Return(s)   : none.
*
* Note(s)     : (1) This function MUST be called after OSStart() & after processor initialization.
*********************************************************************************************************
*/

void  OS_CPU_TickInit (void)
{
    CPU_INT16U  cmcor;


#if (OS_VERSION >= 300u)
    cmcor = BSP_CPU_PerClkFreq() / (32u * OSCfg_TickRate_Hz);
#else
    cmcor = BSP_CPU_PerClkFreq() / (32u * OS_TICKS_PER_SEC);
#endif

    MSTP(CMT0) = 0;                                             /* Enable CMT0 module.                                  */

    CMT.CMSTR0.BIT.STR0 = 0;                                    /* Stop timer channel 0.                                */
    CMT0.CMCR.BIT.CKS   = 1;                                    /* Set peripheral clock divider.                        */

    CMT0.CMCOR = cmcor - 1u;                                    /* Set compare-match value.                             */
    CMT0.CMCNT = 0;                                             /* Clear counter register.                              */

    IR(CMT0, CMI0)  = 0;                                        /* Clear any pending ISR.                               */
    IPR(CMT0,)      = 3;                                        /* Set interrupt priority.                              */
    IEN(CMT0, CMI0) = 1;                                        /* Enable interrupt source.                             */

    CMT0.CMCR.BIT.CMIE = 1;                                     /* Enable interrupt.                                    */

    CMT.CMSTR0.BIT.STR0 = 1;                                    /* Start timer.                                         */
}

