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
#include "unity_fixture.h"
#include "CircularBuffer.h"
#include "stdlib.h"
#include "stdint.h"
#include "unity_fixture.h"

TEST_GROUP(CircularBuffer);

TEST_SETUP(CircularBuffer)
{
}

TEST_TEAR_DOWN(CircularBuffer)
{
}

TEST(CircularBuffer, StartHere)
{
/*    TEST_FAIL_MESSAGE("Start here"); */
    uint16_t circbuffer[16];
    CircularBuffer_Create(&circbuffer[0]);
    for (int i = 0; i<16; i++){ 
        TEST_ASSERT_EQUAL_HEX16(0, circbuffer[i]);
    }
}

TEST(CircularBuffer, writefirstPos)
{
    uint16_t circbuffer[16];
    CircularBuffer_Create(&circbuffer[0]);
    CircularBuffer_Write(1564);
    TEST_ASSERT_EQUAL_HEX16(1564, circbuffer[0]);
}

TEST(CircularBuffer, KeepWriting)
{
    uint16_t circbuffer[16];
    CircularBuffer_Create(&circbuffer[0]);
    CircularBuffer_Write(1564);
    CircularBuffer_Write(1200);
    CircularBuffer_Write(100);
    TEST_ASSERT_EQUAL(1564, circbuffer[0]);
    TEST_ASSERT_EQUAL(1200, circbuffer[1]);
    TEST_ASSERT_EQUAL(100, circbuffer[2]);
}

TEST(CircularBuffer, ReachEndAndLoop)
{
    uint16_t circbuffer[16];
    CircularBuffer_Create(&circbuffer[0]);
    for(int i = 0; i<17; i++)
    {
        CircularBuffer_Write(i);
        if(i<16)
            TEST_ASSERT_EQUAL(i, circbuffer[i]);
        else
            TEST_ASSERT_EQUAL(i, circbuffer[i-16]);
    }
}
