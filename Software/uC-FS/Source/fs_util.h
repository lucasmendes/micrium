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
*                                  FILE SYSTEM SUITE UTILITY LIBRARY
*
* Filename      : fs_util.h
* Version       : V4.04
* Programmer(s) : BAN
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                               EXTERNS
*********************************************************************************************************
*/

#ifdef   FS_UTIL_MODULE
#define  FS_UTIL_EXT
#else
#define  FS_UTIL_EXT  extern
#endif


/*
*********************************************************************************************************
*                                               DEFINES
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


/*
*********************************************************************************************************
*                                              MACRO'S
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                                   POWER-2 MULTIPLY/DIVIDE MACRO'S
*
* Note(s) : (1) Multiplications & divisions by powers of 2 are common within the file system suite.
*               If the power-of-2 multiplication or divisor is a constant, a compiler can optimize the
*               calculation (typically encoding it as a logical shift).  However, many of the powers-of-2
*               multiplicands & divisors are known only at run-time, so the integer multiplications &
*               divisions lose important information that could have been used for optimization.
*
*               Multiplications & divisions by powers of 2 within this file system suite are performed
*               with macros 'FS_UTIL_MULT_PWR2' & 'FS_UTIL_DIV_PWR2', using left & right shifts.
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                                         FS_UTIL_MULT_PWR2()
*
* Description : Multiple integer by a power of 2.
*
* Argument(s) : nbr         First multiplicand.
*
*               pwr         Power of second multiplicand.
*
* Return(s)   : Product = nbr * 2^pwr.
*
* Caller(s)   : various.
*
* Note(s)     : (1) As stated in ISO/IEC 9899:TCP 6.5.8(4) :
*
*                      "The result of E1 << E2 is E1 left-shifted E2 bit-positions; vacated bits are
*                       filled with zeros.  If E1 has an unsigned type, the value of the result is E1 x
*                       2^E2, reduces modulo one more than the maximum value representable in the result
*                       type."
*
*                   Even with conforming compilers, this macro MAY ONLY be used with unsigned operands.
*                   Results with signed operands are undefined.
*
*               (2) With a non-conforming compiler, this macro should be commented out & redefined.
*********************************************************************************************************
*/

#define  FS_UTIL_MULT_PWR2(nbr, pwr)                ((nbr) << (pwr))

/*
*********************************************************************************************************
*                                         FS_UTIL_DIV_PWR2()
*
* Description : Divide integer by a power of 2.
*
* Argument(s) : nbr         Dividend.
*
*               pwr         Power of divisor.
*
* Return(s)   : Quotient = nbr / 2^pwr.
*
* Caller(s)   : various.
*
* Note(s)     : (1) As stated in ISO/IEC 9899:TCP 6.5.8(5) :
*
*                      "The result of E1 >> E2 is E1 right-shifted E2 bit-positions.  If E1 has an
*                       unsigned type ..., the value of the result is the integral part of the quotient
*                       of E1 / 2^E2."
*
*                   Even with conforming compilers, this macro MAY ONLY be used with unsigned operands.
*                   Results with signed operands are undefined.
*
*               (2) With a non-conforming compiler, this macro should be commented out & redefined.
*********************************************************************************************************
*/

#define  FS_UTIL_DIV_PWR2(nbr, pwr)                 ((nbr) >> (pwr))

/*
*********************************************************************************************************
*                                          FS_UTIL_IS_ODD()
*
* Description : Determine whether unsigned integer is odd.
*
* Argument(s) : nbr         Unsigned integer.
*
* Return(s)   : DEF_YES, if integer is odd.
*               DEF_NO,  if integer is even.
*
* Caller(s)   : various.
*
* Note(s)     : none
*********************************************************************************************************
*/

#define  FS_UTIL_IS_ODD(nbr)                        (DEF_BIT_IS_SET((nbr), DEF_BIT_00))

/*
*********************************************************************************************************
*                                          FS_UTIL_IS_EVEN()
*
* Description : Determine whether unsigned integer is even.
*
* Argument(s) : nbr         Unsigned integer.
*
* Return(s)   : DEF_YES, if integer is even.
*               DEF_NO,  if integer is odd.
*
* Caller(s)   : various.
*
* Note(s)     : none
*********************************************************************************************************
*/

#define  FS_UTIL_IS_EVEN(nbr)                       (DEF_BIT_IS_CLR((nbr), DEF_BIT_00))

/*
*********************************************************************************************************
*                                    MEMORY VALUE GET/SET MACRO'S
*
* Note(s) : (1) The 'ALIGNED' macros MUST ONLY be used when the alignment of data is known.  When data
*               is retrieved from file system suite sector buffers, which are all 'CPU_DATA'-aligned,
*               alignment can be determined by just examining the offset of data within the sector.
*********************************************************************************************************
*/

#define  FS_UTIL_MEM_VAL_GET_INT32U_ALIGNED(addr)               MEM_VAL_GET_INT32U_LITTLE((addr))
#define  FS_UTIL_MEM_VAL_GET_INT16U_ALIGNED(addr)               MEM_VAL_GET_INT16U_LITTLE((addr))
#define  FS_UTIL_MEM_VAL_GET_INT08U_ALIGNED(addr)               MEM_VAL_GET_INT08U_LITTLE((addr))
#define  FS_UTIL_MEM_VAL_SET_INT32U_ALIGNED(addr, val)          MEM_VAL_SET_INT32U_LITTLE((addr), (val))
#define  FS_UTIL_MEM_VAL_SET_INT16U_ALIGNED(addr, val)          MEM_VAL_SET_INT16U_LITTLE((addr), (val))
#define  FS_UTIL_MEM_VAL_SET_INT08U_ALIGNED(addr, val)          MEM_VAL_SET_INT08U_LITTLE((addr), (val))


/*
*********************************************************************************************************
*                                         FUNCTION PROTOTYPES
*********************************************************************************************************
*/

CPU_INT08U  FSUtil_Log2(CPU_INT32U  val);                       /* Calculate base-2 logarithm of integer.               */


/*
*********************************************************************************************************
*                                        CONFIGURATION ERRORS
*********************************************************************************************************
*/

