;********************************************************************************************************
;                                         BOARD SUPPORT PACKAGE
;
;                            (c) Copyright 2010; Micrium, Inc.; Weston, FL
;                    All rights reserved.  Protected by international copyright laws.
;
;                                              Renesas RX
;
; File    : NET_BSP_A.SRC
;********************************************************************************************************


    .include    "os_cpu_a.inc"          ; Include OS_ISR_ENTER and OS_ISR_EXIT macros

    .global     _NetDev_ISR_Handler
    .global     _NetDevISR

;/*$PAGE*/
;********************************************************************************************************
;                                             OSTickISR()
;********************************************************************************************************

    .section    .text

_NetDevISR:
    OS_ISR_ENTER                        ; Save context & Notify uC/OS about ISR

    MOV.L   #_NetDev_ISR_Handler, R5
    JSR     R5

    OS_ISR_EXIT                         ; Restore context

    .END

