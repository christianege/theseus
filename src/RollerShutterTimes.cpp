/*
 * RollerShutterTimes.cpp
 *
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


#include "RollerShutterTimes.hpp"

namespace shutter {


RollerShutterTimes::RollerShutterTimes(const LineSegment *lines,
			uint8_t lineCount,
			uint16_t minSunrise,
			uint16_t minSunset,
			uint8_t sunriseOffset,
			uint8_t sunsetOffset
			)
:mpe_lines(lines),
 m_lineCount(lineCount),
 m_minSunrise(minSunrise),
 m_minSunset(minSunset),
 m_sunriseOffset(sunriseOffset),
 m_sunsetOffset(sunsetOffset)
{

}


void RollerShutterTimes::getUpOffset(const uint16_t day, uint16_t &offset )
{
	getOffset(true,day,offset);
}

void RollerShutterTimes::getDownOffset(const uint16_t day, uint16_t &offset )
{
	getOffset(false,day,offset);
}

void RollerShutterTimes::getOffset(const bool up, const  uint16_t day, uint16_t &offset)
{
	bool cont = true;
	if((day < MIN_DAY_OF_YEAR) || (day > MAX_DAY_OF_YEAR))
	{
		offset = 0;
		return;
	}
	else
	{
		offset = up?m_minSunrise:m_minSunset;
	}

	for(int i = 0; i < m_lineCount; i++)
	{
		if( (mpe_lines[i].sunrise == up) &&
				(mpe_lines[i].begin <= day) &&
				( mpe_lines[i].end >= day)
		)
		{
			offset += (int)(float)day*mpe_lines[i].slope+mpe_lines[i].yIntercept;
			return;
		}
	}
}

} // End of namespace shutter
