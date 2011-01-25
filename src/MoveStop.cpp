/*
 * MoveStop.cpp
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

#include "MoveStop.hpp"
#include "HardwareSerial.h"

MoveStop::MoveStop(RollerShutterManager &mgr)
:m_mgr(mgr)
{
	;
}

void MoveStop::execute()
{
	Serial.println("move stop");
	m_mgr.stop();
}
