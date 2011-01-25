/*
 * RollerShutterManager.cpp
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

#include "RollerShutterManager.hpp"
#include "StopShutter.hpp"
#include "WProgram.h"

const StateElement RollerShutterManager::stateMatrix[MAX_STATE][MAX_EVENT] = {
	                        /* UP_EVENT */                  /* DOWN_EVENT */                    /* STOP_EVENT */            /* FINAL_EVENT */
	/* TRANSIT_STATE   */ { {MOVE_UP_STATE,UP_ACTION},      {MOVE_DOWN_STATE,DOWN_ACTION},      {TRANSIT_STATE,NIL_ACTION},  {TRANSIT_STATE,NIL_ACTION}  },
	/* OPEN_STATE      */ { {OPEN_STATE,NIL_ACTION  },      {MOVE_DOWN_STATE,DOWN_ACTION},      {OPEN_STATE,NIL_ACTION},     {OPEN_STATE,NIL_ACTION}     },
	/* MOVE_UP_STATE   */ { {MOVE_UP_STATE,NIL_ACTION},     {MOVE_DOWN_STATE,STOP_DOWN_ACTION}, {TRANSIT_STATE,STOP_ACTION}, {OPEN_STATE,FINAL_ACTION}   },
	/* MOVE_DOWN_STATE */ { {MOVE_UP_STATE,STOP_UP_ACTION}, {MOVE_DOWN_STATE,NIL_ACTION},       {TRANSIT_STATE,STOP_ACTION}, {CLOSED_STATE,FINAL_ACTION} },
	/* CLOSED_STATE    */ { {MOVE_UP_STATE,UP_ACTION},      {CLOSED_STATE,NIL_ACTION},          {CLOSED_STATE,NIL_ACTION},   {CLOSED_STATE,NIL_ACTION}   },
	};


RollerShutterManager::RollerShutterManager(SimpleTimer &timer,
		RollerShutter &shutter,
		const uint16_t inMotionTime,
		const uint16_t remainTime,
		const uint16_t timeOut
		)
:m_timer(timer),
 m_shutter(shutter),
 m_inMotionTime(inMotionTime),
 m_timeOut(timeOut),
 m_remainTime(remainTime),
 m_currState(TRANSIT_STATE),
 m_enableCmd(shutter),
 m_finalCmd((*this)),
 m_finalTimerNum(-1)
{
}

void RollerShutterManager::moveDown()
{
	this->process(DOWN_EVENT);
}

void RollerShutterManager::moveUp()
{
	this->process(UP_EVENT);
}

void RollerShutterManager::stop()
{
	this->process(STOP_EVENT);
}


void RollerShutterManager::final()
{
	this->process(FINAL_EVENT);
}

ShutterAction RollerShutterManager::stateEval(ShutterEvent e)
{
	StateElement elem = stateMatrix[m_currState][e];
	m_currState = elem.nextState;
	return elem.action;
}

void RollerShutterManager::process(ShutterEvent e)
{
	ShutterAction action = stateEval(e);
	switch(action)
	{
		case UP_ACTION:
			action_move_up();
			break;
		case DOWN_ACTION:
			action_move_down();
			break;
		case STOP_ACTION:
			action_stop();
			break;
		case FINAL_ACTION:
			action_final();
			break;
		case STOP_UP_ACTION:
			action_stop_move_up();
			break;
		case STOP_DOWN_ACTION:
			action_move_up();
			break;
		case NIL_ACTION:
		default:
			action_nil();
			break;
	}
}

void RollerShutterManager::action_nil()
{
	;// Do nothing
}

void RollerShutterManager::action_final()
{
	Serial.println("-- stop final --");
	m_shutter.stop();
}

void RollerShutterManager::action_stop()
{
	action_final();
	if(-1 != m_finalTimerNum)
	{
		m_timer.disable(m_finalTimerNum);
		m_finalTimerNum = -1;
	}
	Serial.println("-- stop move --");
}

void RollerShutterManager::action_stop_move_up()
{
	action_stop();
	action_move_up();
}

void RollerShutterManager::action_stop_move_down()
{
	action_stop();
	action_move_down();
}

void RollerShutterManager::action_move_up()
{
	m_shutter.direction(true);
	startMove();
}

void RollerShutterManager::action_move_down()
{
	m_shutter.direction(false);
	startMove();
}

void RollerShutterManager::startMove()
{
	Serial.println("-- start move --");
	m_timer.setTimeout(static_cast<long int>(m_timeOut),&m_enableCmd);
	m_finalTimerNum = m_timer.setTimeout(static_cast<long int>(m_timeOut+m_inMotionTime),&m_finalCmd);
}
