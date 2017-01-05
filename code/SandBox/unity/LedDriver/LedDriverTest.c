/***
 * Excerpted from "Test-Driven Development for Embedded C",
 * published by The Pragmatic Bookshelf.
 * Copyrights apply to this code. It may not be used to create training material, 
 * courses, books, articles, and the like. Contact us if you are in doubt.
 * We make no guarantees that this code is fit for any purpose. 
 * Visit http://www.pragmaticprogrammer.com/titles/jgade for more book information.
***/
/*- ------------------------------------------------------------------ -*/
/*-    Copyright (c) James W. Grenning -- All Rights Reserved          -*/
/*-    For use by owners of Test-Driven Development for Embedded C,    -*/
/*-    and attendees of Renaissance Software Consulting, Co. training  -*/
/*-    classes.                                                        -*/
/*-                                                                    -*/
/*-    Available at http://pragprog.com/titles/jgade/                  -*/
/*-        ISBN 1-934356-62-X, ISBN13 978-1-934356-62-3                -*/
/*-                                                                    -*/
/*-    Authorized users may use this source code in your own           -*/
/*-    projects, however the source code may not be used to            -*/
/*-    create training material, courses, books, articles, and         -*/
/*-    the like. We make no guarantees that this source code is        -*/
/*-    fit for any purpose.                                            -*/
/*-                                                                    -*/
/*-    www.renaissancesoftware.net james@renaissancesoftware.net       -*/
/*- ------------------------------------------------------------------ -*/

#include "unity_fixture.h"
#include "LedDriver.h"
#include "stdlib.h"
#include "stdint.h"
#include "unity_fixture.h"

TEST_GROUP(LedDriver);

TEST_SETUP(LedDriver)
{
}

TEST_TEAR_DOWN(LedDriver)
{
}
uint16_t virtualLeds;

TEST(LedDriver, StartHere)
{
/*    TEST_FAIL_MESSAGE("Start here"); */
    virtualLeds = 0xffff;
    LedDriver_Create(&virtualLeds);
    TEST_ASSERT_EQUAL_HEX16(0, virtualLeds);
}

TEST(LedDriver, TurnOnLedOne)
{
    LedDriver_Create(&virtualLeds);
    LedDriver_TurnOn(1);
    TEST_ASSERT_EQUAL_HEX16(1, virtualLeds);
}

TEST(LedDriver, TurnOffLedOne)
{
    LedDriver_Create(&virtualLeds);
    LedDriver_TurnOn(1);
    LedDriver_TurnOff(1);
    TEST_ASSERT_EQUAL_HEX16(0, virtualLeds);
}

TEST(LedDriver, KeepLedFour)
{
    LedDriver_Create(&virtualLeds);
    LedDriver_TurnOn(4);
    LedDriver_TurnOn(1);
    LedDriver_TurnOn(3);
    LedDriver_TurnOff(1);
    LedDriver_TurnOff(3);
    TEST_ASSERT_EQUAL_HEX16(0b0000000000001000, virtualLeds);
}

TEST(LedDriver, BoundLimits)
{
    LedDriver_Create(&virtualLeds);
    LedDriver_TurnOn(16);
    TEST_ASSERT_EQUAL_HEX16(0b1000000000000000, virtualLeds);
    LedDriver_TurnOn(1);
    TEST_ASSERT_EQUAL_HEX16(0b1000000000000001, virtualLeds);
    LedDriver_TurnOff(16);
    TEST_ASSERT_EQUAL_HEX16(0b0000000000000001, virtualLeds);
    LedDriver_TurnOff(1);
    TEST_ASSERT_EQUAL_HEX16(0b0000000000000000, virtualLeds);
}

TEST(LedDriver, OutofBoundsTurningOn)
{
    LedDriver_Create(&virtualLeds);
    LedDriver_TurnOn(-1);
    LedDriver_TurnOn(3141);
    LedDriver_TurnOn(0);
    LedDriver_TurnOn(17);
    //LedDriver_TurnOff(17);
    TEST_ASSERT_EQUAL_HEX16(0, virtualLeds);
}

TEST(LedDriver, OutofBoundsTurningOff)
{
    LedDriver_TurnAllOn();
    LedDriver_TurnOff(-1);
    LedDriver_TurnOff(3141);
    LedDriver_TurnOff(0);
    LedDriver_TurnOff(17);
    //LedDriver_TurnOff(17);
    TEST_ASSERT_EQUAL_HEX16(0xffff, virtualLeds);
}

TEST(LedDriver, TurnAllOn)
{
    LedDriver_Create(&virtualLeds);
    LedDriver_TurnAllOn();
    TEST_ASSERT_EQUAL_HEX16(0xffff, virtualLeds);
}

TEST(LedDriver, TurnOnAnyLed)
{
    LedDriver_Create(&virtualLeds);
    LedDriver_TurnOn(8);
    TEST_ASSERT_EQUAL_HEX16(0x80, virtualLeds);
}

TEST(LedDriver, TurnOffAll)
{
    LedDriver_Create(&virtualLeds);
    LedDriver_TurnAllOff();
    TEST_ASSERT_EQUAL_HEX16(0, virtualLeds);
}

TEST(LedDriver, TurnOffAnyLed)
{
    LedDriver_Create(&virtualLeds);
    LedDriver_TurnOn(8);
    LedDriver_TurnOff(8);
    TEST_ASSERT_EQUAL_HEX16(0, virtualLeds);
}

TEST(LedDriver, IsOn)
{
    TEST_ASSERT_FALSE(LedDriver_IsOn(11));
    LedDriver_TurnOn(11);
    TEST_ASSERT_TRUE(LedDriver_IsOn(11));
    LedDriver_TurnOff(11);
}
