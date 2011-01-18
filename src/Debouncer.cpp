/*
 * Debouncer.cpp
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

#include "Debouncer.hpp"
#include "WProgram.h"

Debouncer::Debouncer(Command &command, uint8_t port,uint8_t threshold)
:m_command(command),
 m_port(port),
 m_state(LOW),
 m_counter(0),
 m_threshold(threshold)
{
	// TODO Auto-generated constructor stub

}

void Debouncer::execute()
{
	uint8_t val = digitalRead(m_port);
	if(m_state != val)
	{
		if(LOW == val)
		{
			m_counter++;
		}
		else
		{
			m_counter = 0;
		}
	}
	else
	{
		if(LOW == val)
		{
			m_counter++;
		}
	}
	if(m_threshold == m_counter)
	{
		m_command.execute();
		//Serial.println("Button pressed");
		m_counter = m_threshold + 1;
	}
	else if(m_threshold < m_counter)
	{
		m_counter = m_threshold + 1;
	}
	m_state = val;
}
