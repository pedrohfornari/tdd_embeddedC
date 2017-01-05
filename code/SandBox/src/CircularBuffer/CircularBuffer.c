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

 /*- --------------------Test List----------------------------------------------------------------------------------------- -*/
 /*- All positions are cleared after initialization  (DONE)                                                                 -*/
 /*- The first position can be written                (DONE)                                                                -*/
 /*- The other positions can be written              (DONE)                                                                 -*/
 /*- One value should be written at a time           (DONE)                                                                 -*/
 /*- Always have to write to the closest position of the last record (DONE)                                                 -*/
 /*- When the buffer is full it should restart the pointer           (DONE)                                                 -*/
 /*- When an output is requested the output pointer should be moved foward  (DONE)                                          -*/
 /*- ---------------------------------------------------------------------------------------------------------------------- -*/
#include "CircularBuffer.h"
#include <stdlib.h>
#include <memory.h>
#include "stdint.h"
#include "stdio.h"
static uint16_t * PosZero;
static uint8_t input_ptr;
static uint8_t output_ptr;
void CircularBuffer_Create(uint16_t * address)
{
    uint16_t * init_ptr;
    PosZero = address;
    init_ptr = PosZero;
    input_ptr = output_ptr = 0;
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
    temp_ptr = PosZero + input_ptr;
    *temp_ptr = value;
    input_ptr++;
    if(input_ptr > 15)
        input_ptr = 0;
    
    return;
}

uint16_t CircularBuffer_Read(void)
{
    uint16_t * temp_ptr;
    uint16_t output;
    temp_ptr = PosZero + output_ptr;
    output = *temp_ptr;
    output_ptr++;
    if(output_ptr > 15)
        output_ptr = 0;
    return output;
}