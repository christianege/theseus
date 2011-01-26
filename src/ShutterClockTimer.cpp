/*
 * ShutterClockTimer.cpp
 *
 *  Created on: 21.01.2011
 *      Author: Christian Ege <chege(at)cybertux.org
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

#include "ShutterClockTimer.hpp"
#include <RollerShutterManager.hpp>
#include <DS1307.h>
#include <stdint.h>
#include "HardwareSerial.h"


ShutterClockTimer::ShutterClockTimer(RollerShutterManager &mgr,
		DS1307 &rtc,
		RollerShutterTimes &times
		)
:m_mgr(mgr),
 m_rtc(rtc),
 m_times(times)
{

}


void ShutterClockTimer::execute()
{
	int day = m_rtc.get(DS1307_DATE,true);
	int hour = m_rtc.get(DS1307_HR,false);
	int minute = m_rtc.get(DS1307_MIN,false);
	const uint16_t current = (hour * 60) + minute;

	uint16_t down_offset = 0;
	uint16_t up_offset = 0;

	m_times.getDownOffset(day,down_offset);
	m_times.getUpOffset(day,up_offset);

	if(current == up_offset)
	{
		m_mgr.moveUp();
	}
	else if(current == down_offset)
	{
		m_mgr.moveDown();
	}
	Serial.print("Time curr: ");
	Serial.print(current);
	Serial.print(" down: ");
	Serial.print(down_offset);
	Serial.print(" up: ");
	Serial.print(up_offset);
	Serial.print(" day: ");
	Serial.println(day);
}
