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

#include "LedDriver.h"
#include <stdlib.h>
#include <memory.h>
#include "stdint.h"
#include "stdio.h"
#include <stdbool.h>

enum {ALL_LEDS_ON = ~0, ALL_LEDS_OFF = ~ALL_LEDS_ON};

/**Local variables**/
static uint16_t * ledsAddress;
static uint16_t ledsImage;

/**Local Function Prototypes**/
static uint16_t ConvertLedNum2Bit(uint16_t ledNumber);
static bool IsLedOutOfBounds(uint16_t ledNumber);
static void updateHardware(void);
static void setLedImageBit(uint16_t ledNumber);
static void clearLedImageBit(uint16_t ledNumber);

void LedDriver_Create(uint16_t * address)
{
    ledsAddress = address;
    ledsImage = ALL_LEDS_OFF;
    updateHardware();
    return;
}
void LedDriver_TurnOn(uint16_t ledNumber)
{
    if (IsLedOutOfBounds(ledNumber)){
        setLedImageBit(ledNumber);
        updateHardware(); 
        return;
    }
    else return; //printf("\n\nNot a Led Available in this position\n\n");
}

void LedDriver_TurnOff(uint16_t ledNumber)
{
    if (IsLedOutOfBounds(ledNumber)){
        clearLedImageBit(ledNumber);
        updateHardware();
        return;
    }
    else return; //printf("\n\nNot a Led Available in this position\n\n");
}   

void LedDriver_Destroy(void)
{
}


void LedDriver_TurnAllOn(void)
{
    ledsImage = ALL_LEDS_ON;
    updateHardware();
}

void LedDriver_TurnAllOff(void)
{
    ledsImage = ALL_LEDS_OFF;
    updateHardware();
}

bool LedDriver_IsOn(uint16_t ledNumber)
{
    return ledsImage & (ConvertLedNum2Bit(ledNumber));
}

bool LedDriver_IsOff(uint16_t ledNumber)
{
    return !LedDriver_IsOn(ledNumber);
}

/*** Helper functions definition***/
static uint16_t ConvertLedNum2Bit(uint16_t ledNumber)
{
    return (1<<(ledNumber-1));
}

static bool IsLedOutOfBounds(uint16_t ledNumber)
{
    return (ledNumber <= 16 && ledNumber >= 1);
}

static void updateHardware(void)
{
    *ledsAddress = ledsImage;
}

static void setLedImageBit(uint16_t ledNumber)
{
    ledsImage |= ConvertLedNum2Bit(ledNumber);
}

static void clearLedImageBit(uint16_t ledNumber)
{
    ledsImage &= ~ConvertLedNum2Bit(ledNumber);
}