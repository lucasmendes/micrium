;********************************************************************************************************
;                                      uC/Probe Communication
;
;                            (c) Copyright 2010; Micrium, Inc.; Weston, FL
;                    All rights reserved.  Protected by international copyright laws.
;
;                                           Renesas RX62N
;
; File    : PROBE_RS232A.S
;********************************************************************************************************


    .include    "os_cpu_a.inc"          ; Include OS_ISR_ENTER and OS_ISR_EXIT macros


    .global         _ProbeRS232_ErISRHandler
    .global         _ProbeRS232_RxISRHandler
    .global         _ProbeRS232_TxISRHandler
    
    .global         _Probe_ER_ISR
    .global         _Probe_RX_ISR
    .global         _Probe_TX_ISR
    .global         _Probe_TE_ISR
    
    
;/*$PAGE*/
;********************************************************************************************************
;                                          Probe RS232 ISR's
;********************************************************************************************************

    .section    .text

_Probe_ER_ISR:
    OS_ISR_ENTER                        ; Save context & Notify uC/OS about ISR

    MOV.L   #_ProbeRS232_ErISRHandler, R5
    JSR     R5

    OS_ISR_EXIT                         ; Restore context


_Probe_RX_ISR:
    OS_ISR_ENTER                        ; Save context & Notify uC/OS about ISR

    MOV.L   #_ProbeRS232_RxISRHandler, R5
    JSR     R5

    OS_ISR_EXIT                         ; Restore context


_Probe_TX_ISR:
    OS_ISR_ENTER                        ; Save context & Notify uC/OS about ISR

    MOV.L   #_ProbeRS232_TxISRHandler, R5
    JSR     R5

    OS_ISR_EXIT                         ; Restore context


_Probe_TE_ISR:
    OS_ISR_ENTER                        ; Save context & Notify uC/OS about ISR

    MOV.L   #_ProbeRS232_TxISRHandler, R5
    JSR     R5

    OS_ISR_EXIT                         ; Restore context

    .END

