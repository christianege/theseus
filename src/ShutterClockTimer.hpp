/*
 * ShutterClockTimer.hpp
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

#ifndef SHUTTERCLOCKTIMER_HPP_
#define SHUTTERCLOCKTIMER_HPP_
#include "Command.hpp"
#include "RollerShutterTimes.hpp"
#include "DS1307.h"

#include "RollerShutterManager.hpp"


class ShutterClockTimer :public Command
{

public:
	ShutterClockTimer(RollerShutterManager &mgr,
			DS1307 &rtc,
			RollerShutterTimes &times
			);
	void execute();

private:
	RollerShutterManager &m_mgr;
	DS1307 &m_rtc;
	RollerShutterTimes &m_times;
};

#endif /* SHUTTERCLOCKTIMER_HPP_ */
