/*
 * RotaryEncoder.cpp
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


#include "RotaryEncoder.h"
#include "WProgram.h"
/*
 * protected
 */
RotaryEncoder::RotaryEncoder()
{
	// TODO Auto-generated constructor stub
}

RotaryEncoder::RotaryEncoder(uint8_t pinA, uint8_t pinB )
:m_counter(0),
 m_encLast(0x01),
 m_pinA(pinA),
 m_pinB(pinB)
{
	 int16_t new_ = 0;
	  if( HIGH == digitalRead(m_pinA) )
	    new_ = 3;
	  if( HIGH == digitalRead(m_pinB) )
	    new_ ^= 1;                   // convert gray to binary
	  m_encLast = new_;              // power on state
	  m_counter = 0;
}


int16_t RotaryEncoder::getCounter()
{
	  int16_t val;

	  cli();
	  val = m_counter;
	  m_counter = val & 1;
	  sei();
	  return val >> 1;
}

void RotaryEncoder::resetCounter()
{
	m_counter = 0;
}

void RotaryEncoder::execute()
{

	int8_t i = 0;
	if( HIGH == digitalRead(m_pinA) )
	{
		i = 1;
	}

	if( HIGH == digitalRead(m_pinB) )
	{
		i ^= 3;        				// convert gray to binary
	}

	i -= m_encLast;      				// difference new - last

	if( i & 1 )
	{        						// bit 0 = value (1)
		m_encLast += i;   			// store new as next last
		m_counter += (i & 2) - 1;   // bit 1 = direction (+/-)
	}
}

