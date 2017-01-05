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

TEST_GROUP_RUNNER(CircularBuffer)
{
    RUN_TEST_CASE(CircularBuffer, StartHere);
    RUN_TEST_CASE(CircularBuffer, writefirstPos);
    RUN_TEST_CASE(CircularBuffer, KeepWriting);  
    RUN_TEST_CASE(CircularBuffer, ReachEndAndLoop);
    RUN_TEST_CASE(CircularBuffer, ReadFirstPos);
    RUN_TEST_CASE(CircularBuffer, KeepReading);
}

