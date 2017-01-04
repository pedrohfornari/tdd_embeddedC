/****
 * Developer Pedro Henrique Kappler Fornari
 * File to write tests to a circular buffer example
 * Based on Test-Driven Development on Embedded C Book
 * Copyrights apply to this code. It may not be used to create training material, 
 * courses, books, articles, and the like. Contact us if you are in doubt.
 * We make no guarantees that this code is fit for any purpose. 
****/
 /*- ------------------------------------------------------------------ -*/
 /*-    Copyright (c) Pedro H. K. Fornari -- All Rights Reserved        -*/
 /*-    For use by students of Test-Driven Development for Embedded C,  -*/
 /*-    and students of any test-driven development method              -*/
 /*- ------------------------------------------------------------------ -*/

 /*- --------------------Test List----------------------------------- -*/
 /*- All positions are cleared after initialization                   -*/
 /*- The first position can be written                                -*/
 /*- The other positions can be written                               -*/
 /*- One value should be written at a time                            -*/
 /*- Always have to write to the closest position of the last record  -*/
 /*- When the buffer is full it should not accept anything            -*/
 /*- When an output is requested all positions should be moved foward -*/
 /*- ---------------------------------------------------------------- -*/
#include "CircularBuffer.h"
#include <stdlib.h>
#include <memory.h>
#include "stdint.h"
#include "stdio.h"
static uint16_t * PosZero;
static uint8_t current_pos;
void CircularBuffer_Create(uint16_t * address)
{
    uint16_t * init_ptr;
    PosZero = address;
    init_ptr = PosZero;
    current_pos = 0;
    for (int i = 0; i<16; i++)
    {
        *init_ptr = 0;
        init_ptr++;
    }
    
    return;
}

void  CircularBuffer_Write(int value)
{
    uint16_t * temp_ptr;
    temp_ptr = PosZero + current_pos;
    *temp_ptr = value;
    current_pos++;
    if(current_pos > 15)
        current_pos = 0;
    
    return;
}