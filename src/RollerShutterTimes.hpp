/*
 * RollerShutterTimes.hpp
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

#ifndef ROLLERSHUTTERTIMES_HPP_
#define ROLLERSHUTTERTIMES_HPP_
#include <stdint.h>

namespace shutter {

struct LineSegment  {
	/** @brief is sunrise or sunset */
	bool sunrise;
	/** @brief lower bound of segment range */
	int16_t begin;
	/** @brief upper bound of segment range */
	int16_t end;
	/** @brief slope of the line segment */
	float slope;
	/** @brief intercept on the y axis */
	float yIntercept;
};

/**
 * @brief Class to retrieve the offsets in minutes when
 * to move the shutter up or down.
 *
 * This class supports the controlling an electronic roller shutter.
 * It calculates the offset from midnight of the given day when the
 * shutter have to be moved up or down. This is based on various line
 * segments which interpolates the sunrise and sunset functions segment
 * wise.
 */
class RollerShutterTimes {

public:

	/**
	 * @brief public constructor of the class
	 *
	 * @param lines a reference to the line segments array
	 * @param lineCount amount of line segments
	 * @param minSunrise earliest sunrise as offset from midnight in minutes
	 * @param minSunset earliest sunset as offset from midnight in minutes
	 * @param sunriseOffset offset which is added to the resulting up time
	 * @param sunsetOffset offset which is added to the resulting down time
	 */
	RollerShutterTimes(const LineSegment *lines,
			uint8_t lineCount,
			uint16_t minSunrise,
			uint16_t minSunset,
			uint8_t sunriseOffset,
			uint8_t sunsetOffset
			);

	/**
	 * @brief Get the time when the shutter should move up.
	 *
	 * The offset in minutes returned is relative to the given
	 * days midnight.
	 *
	 * @param day the day for which the times is requested
	 * @param offset the offset in minutes relative to midnight
	 */
	void getUpOffset(const uint16_t day, uint16_t &offset );

	/**
	 * @brief Get the time when the shutter should move down.
	 *
	 * The offset in minutes returned is relative to the given
	 * days midnight.
	 *
	 * @param day the day for which the times is requested
	 * @param offset the offset in minutes relative to midnight
	 */
	void getDownOffset(const uint16_t day, uint16_t &offset );

	static const uint16_t MAX_DAY_OF_YEAR = 364;
	static const uint16_t MIN_DAY_OF_YEAR = 0;

protected:
	void getOffset(const bool up, const uint16_t day, uint16_t &offset);


private:
	const LineSegment* mpe_lines;
	const uint8_t m_lineCount;
	const uint16_t m_minSunrise;
	const uint16_t m_minSunset;
	const uint8_t m_sunriseOffset;
	const uint8_t m_sunsetOffset;
};

}

#endif /* ROLLERSHUTTERTIMES_HPP_ */
