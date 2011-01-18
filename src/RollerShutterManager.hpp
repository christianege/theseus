/*
 * RollerShutterManager.hpp
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

#ifndef ROLLERSHUTTERMANAGER_HPP_
#define ROLLERSHUTTERMANAGER_HPP_

#include "SimpleTimer.h"
#include "RollerShutter.h"
#include "EnableShutter.hpp"
#include "StopShutter.hpp"

#include <stdint.h>


enum ShutterState {
	TRANSIT_STATE=0,
	OPEN_STATE,
	MOVE_UP_STATE,
	MOVE_DOWN_STATE,
	CLOSED_STATE,
	MAX_STATE
};

enum ShutterAction {
	NIL_ACTION = 0,
	DOWN_ACTION,
	UP_ACTION,
	STOP_ACTION,
	STOP_UP_ACTION,
	STOP_DOWN_ACTION,
	FINAL_ACTION,
	MAX_ACTION
};

enum ShutterEvent {
	UP_EVENT,
	DOWN_EVENT,
	STOP_EVENT,
	FINAL_EVENT,
	MAX_EVENT
};

struct StateElement {
	ShutterState nextState;
	ShutterAction action;
};



class RollerShutterManager
{
public:
	RollerShutterManager(SimpleTimer &timer,
			RollerShutter &shutter,
			const uint16_t inMotionTime=12000,
			const uint16_t remainTime=3000,
			const uint16_t timeOut = 500
			);
	void moveUp();
	void moveDown();
	void moveToShadow();
	void stop();
	void final();

private:
	RollerShutterManager();
	ShutterAction stateEval(ShutterEvent e);
	void process(ShutterEvent e);

	void action_nil();
	void action_final();
	void action_stop();
	void action_stop_move_up();
	void action_stop_move_down();
	void action_move_up();
	void action_move_down();

	void startMove();

	SimpleTimer &m_timer;
	RollerShutter &m_shutter;
	ShutterState m_currState;
	const uint16_t m_inMotionTime;
	const uint16_t m_timeOut;
	const uint16_t m_remainTime;
	StopShutter  m_finalCmd;
	EnableShutter m_enableCmd;
	int m_finalTimerNum;

	static const StateElement stateMatrix[MAX_STATE][MAX_EVENT];


};

#endif /* ROLLERSHUTTERMANAGER_H_ */
