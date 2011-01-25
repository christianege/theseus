/*  
 *  shutter.cpp - A arduino roller shutter controller
 *  Author: Christian Ege <chege(at)cybertux.org>
 *  Copyright (c) 2011 Markdorf Germany
 *
 * This Class is free software; you can redistribute it
 * and/or modify it under the terms of the GNU Lesser
 * General Public License as published by the Free Software
 * Foundation; either version 2.1 of the License, or (at
 * your option) any later version.
 *
 * This library is distributed in the hope that it will
 * be useful, but WITHOUT ANY WARRANTY; without even the
 * implied warranty of MERCHANTABILITY or FITNESS FOR A
 * PARTICULAR PURPOSE.  See the GNU Lesser General Public
 * License for more details.
 *
 * You should have received a copy of the GNU Lesser
 * General Public License along with this library; if not,
 * write to the Free Software Foundation, Inc.,
 * 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
 */

#include "DS1307.h"
#include "ShutterClockTimer.hpp"
#include "SimpleTimer.h"
#include "RepeatCmd.hpp"
#include "RollerShutter.h"
#include "RollerShutterTimes.hpp"
#include "RollerShutterManager.hpp"
#include "RotaryEncoder.h"
#include "Debouncer.hpp"
#include "MoveDown.hpp"
#include "MoveUp.hpp"
#include "MoveStop.hpp"
#include "ShutterClockTimer.hpp"
#include "HardwareSerial.h"
//#include <WProgram.h>

// There must be one global SimpleTimer object.
// More SimpleTimer objects can be created and run,
// although there is little point in doing so.
SimpleTimer timer;
RollerShutter rollerShutter(11,12);

RollerShutterManager mgr(timer,rollerShutter);
MoveDown moveDown(mgr);
MoveUp moveUp(mgr);
MoveStop MoveStop(mgr);

Debouncer debUp(moveUp,8);
Debouncer debStop(moveDown,9);
Debouncer debDown(MoveStop,10);



static const uint8_t line_count = 10;
const LineSegment lines[line_count] = {
		{true,    0,  19, 0.000,  228.000 },
		{true,   20, 149,-1.753 , 261.600 },
		{true,  150, 184, 0.000,    0.000 },
		{true,  185, 354, 1.349, -250.100 },
		{true,  354, 364, 0.000,  228.000 },
		{false,   0, 156, 1.436,    9.668 },
		{false, 157, 195, 0.000,  234.000 },
		{false, 196, 327,-1.778,  582.300 },
		{false, 328, 357, 0.000,    0.000 },
		{false, 358, 364, 1.436, -514.000 },
};

RollerShutterTimes shutter_times( lines,
								  line_count,
								  263,
								  990,
								  0,
								  20
		);

DS1307 rtc;
ShutterClockTimer clockTimer(mgr,rtc,shutter_times);

void loop()
{
	timer.run();
}

void setup()
{
	Serial.begin(9600);

	pinMode (11,OUTPUT);
	pinMode (12,OUTPUT);

	pinMode(8, INPUT);    // Set the switch pin as input
	pinMode(9, INPUT);    // Set the switch pin as input
	pinMode(10, INPUT);    // Set the switch pin as input


    // Pin 13 has an LED connected on most Arduino boards
    pinMode(13, OUTPUT);


    timer.setInterval(10,&debDown);
    timer.setInterval(10,&debUp);
    timer.setInterval(10,&debStop);
    timer.setInterval(10000,&clockTimer);
    mgr.moveUp();
}

