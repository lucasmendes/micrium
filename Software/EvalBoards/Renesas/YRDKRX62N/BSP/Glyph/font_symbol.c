/*
*********************************************************************************************************
*                                            SYMBOL FONT FILE
*
*                            (c) Copyright 2010; Micrium, Inc.; Weston, FL
*
*               All rights reserved. Protected by international copyright laws.
*
*               This font is provided in source form to registered licensees ONLY.  It is
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
*                                            SYMBOL FONT FILE
*
* Filename      : font_symbol.c
* Version       : V1.00
* Programmer(s) : FGK
*********************************************************************************************************
*/

#include "types.h"

const uint8_t Symbol_prev[] = {
    0x07, 0x07, // width=7, height=7
    0x08, 0x1C, 0x36, 0x6B, 0x1C, 0x36, 0x63
};

const uint8_t Symbol_next[] = {
    0x07, 0x07, // width=7, height=7
    0x63, 0x36, 0x1C, 0x6B, 0x36, 0x1C, 0x08
};

const uint8_t Symbol_play[] = {
    0x06, 0x07, // width=6, height=7
    0x00, 0x7F, 0x3E, 0x1C, 0x08, 0x00, 
};

const uint8_t Symbol_stop[] = {
    0x07, 0x07, // width=7, height=7
    0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F
};

const uint8_t Symbol_pause[] = {
    0x07, 0x07, // width=7, height=7
    0x00, 0x7F, 0x7F, 0x00, 0x7F, 0x7F, 0x00
};

const uint8_t Symbol_progress_bar[] = {
    0x5F, 0x07, // width=95, height=7
    0x00, 0x3E, 
    0x41, 0x49, 0x41, 0x49, 0x41, 0x49, 0x41, 0x49, 0x41, 0x49,
    0x41, 0x49, 0x41, 0x49, 0x41, 0x49, 0x41, 0x49, 0x41, 0x49,
    0x41, 0x49, 0x41, 0x49, 0x41, 0x49, 0x41, 0x49, 0x41, 0x49,
    0x41, 0x49, 0x41, 0x49, 0x41, 0x49, 0x41, 0x49, 0x41, 0x49,
    0x41, 0x49, 0x41, 0x49, 0x41, 0x49, 0x41, 0x49, 0x41, 0x49,
    0x41, 0x49, 0x41, 0x49, 0x41, 0x49, 0x41, 0x49, 0x41, 0x49,
    0x41, 0x49, 0x41, 0x49, 0x41, 0x49, 0x41, 0x49, 0x41, 0x49,
    0x41, 0x49, 0x41, 0x49, 0x41, 0x49, 0x41, 0x49, 0x41, 0x49,
    0x41, 0x49, 0x41, 0x49, 0x41, 0x49, 0x41, 0x49, 0x41, 0x49,
    0x41, 0x3E, 0x00
};

const uint8_t Symbol_progress_cursor[] = {
    0x05, 0x05, // width=5, height=7
    0x49, 0x5D, 0x7F, 0x5D, 0x49
};

const uint8_t * const Symbols_table[256] = {
    0,
    Symbol_prev,
    Symbol_next,
    Symbol_play,
    Symbol_stop,
    Symbol_pause,
    Symbol_progress_bar,
    Symbol_progress_cursor,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
};
