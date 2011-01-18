/*
 * RollerShutter.cpp
 *  Created on: 13.01.2011
 *      Author: Christian Ege <chege (at) cybertux.org>
 *      Copyright (c) 2011 Markdorf Germany
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


#include "RollerShutter.h"
#include <WProgram.h>

RollerShutter::RollerShutter(uint8_t pinPWR, uint8_t pinDIR)
:m_pinPWR(pinPWR),
 m_pinDIR(pinDIR)
{

}

void RollerShutter::direction(bool up)
{	uint8_t state = LOW;

	if(true == up)
	{
		/* set direction Pin low, this enables up direction */
		state = LOW;
		Serial.println(">move up!");
	}
	else
	{
		/* set direction Pin high, this enables down direction */
		state =  HIGH;
		Serial.println(">move down!");
	}
	digitalWrite(m_pinDIR, state);

}

void RollerShutter::stop()
{
	/* set direction and power low, this disables power and releases relays */
	digitalWrite(m_pinDIR, LOW);
	digitalWrite(m_pinPWR, LOW);
	Serial.println(">stop!");
}

void RollerShutter::start()
{
	/* set power Pin high, this enables power */
	digitalWrite(m_pinPWR, HIGH);
	Serial.println(">start!");
}
