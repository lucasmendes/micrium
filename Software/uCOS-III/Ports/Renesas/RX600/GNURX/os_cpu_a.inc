;********************************************************************************************************
;                                               uC/OS-III
;                                         The Real-Time Kernel
;
;                            (c) Copyright 2010; Micrium, Inc.; Weston, FL
;                    All rights reserved.  Protected by international copyright laws.
;
;                                              Renesas RX
;
; File    : OS_CPU_A.INC
; Version : V3.01.2
;********************************************************************************************************

;********************************************************************************************************
;                                           PUBLIC FUNCTIONS
;********************************************************************************************************

    .global        _OSTCBCurPtr            ; Declared as OS_TCB *               , 32-bit long
    .global        _OSIntNestingCtr        ; Declared as INT8U                  ,  8-bit long

    .global        _OSIntExit              ; External functions written in C
    .global        _OSTimeTick

   .section        .text

;/*$PAGE*/
;********************************************************************************************************
;                                             OS_CTX_SAVE
;
; Description : Save context.
;
; Note(s)     : 1) Save floating-point status word.
;               2) Save accumulator     register.
;               3) Save general-purpose registers.
;********************************************************************************************************

.macro  OS_CTX_SAVE
    PUSHC   FPSW                        ; Save processor registers on the stack
    PUSHM   R1-R15
    MVFACHI R1
    MVFACMI R2
    PUSHM   R1-R2
.endm


;/*$PAGE*/
;********************************************************************************************************
;                                           OS_CTX_RESTORE
;
; Description : Restore context.
;
; Note(s)     : 1) Restore general-purpose registers.
;               2) Restore accumulator     register.
;               3) Restore floating-point status word.
;********************************************************************************************************

.macro  OS_CTX_RESTORE
    POPM    R1-R2                       ; Restore processor registers from stack
    SHLL    #16, R2
    MVTACLO R2
    MVTACHI R1
    POPM    R1-R15
    POPC    FPSW
.endm


;/*$PAGE*/
;********************************************************************************************************
;                                            OS_ISR_ENTER
;
; Description : Interrupt service routine prologue for kernel-aware handler.
;
; Note(s)     : 1) A kernel-aware handler should be written as follows:
;
;                      MyKernelAwareISR:
;                          OS_ISR_ENTER
;                          :               ; service ISR
;                          OS_ISR_EXIT
;********************************************************************************************************

.macro  OS_ISR_ENTER
    OS_CTX_SAVE                         ; Save processor registers on the stack

    MOV.L   #_OSIntNestingCtr, R5       ; Notify uC/OS-III about ISR
    MOV.B   [R5], R3
    ADD     #1, R3
    MOV.B   R3, [R5]

    CMP     #1, R3                      ; if (OSNestingCtr == 1)
    BNE     ?+
    MOV.L   #_OSTCBCurPtr, R5           ; Save current task's SP into its TCB
    MOV.L   [R5], R3
    MOV.L   R0, [R3]
?:
.endm


;/*$PAGE*/
;********************************************************************************************************
;                                             OS_ISR_EXIT
;
; Description : Interrupt service routine epilog for kernel-aware handler.
;
; Note(s)     : 1) A kernel-aware handler should be written as follows:
;
;                      MyKernelAwareISR:
;                          OS_ISR_ENTER
;                          :               ; service ISR
;                          OS_ISR_EXIT
;********************************************************************************************************

.macro  OS_ISR_EXIT
    MOV.L   #_OSIntExit, R5
    JSR     R5                          ; Notify uC/OS-III about end of ISR

    OS_CTX_RESTORE                      ; Restore processor registers from stack

    RTE
.endm
 