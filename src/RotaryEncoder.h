/*
 * RotaryEncoder.h
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


#ifndef ROTARYENCODER_H_
#define ROTARYENCODER_H_

#include "Command.hpp"
#include <stdint.h>

class RotaryEncoder :public Command
{
public:
	RotaryEncoder(uint8_t pinA, uint8_t pinB );
	int16_t getCounter();
	void resetCounter();
	void execute();

protected:
	RotaryEncoder();
	int16_t m_counter;
	int16_t m_encLast;
	uint8_t m_pinA;
	uint8_t m_pinB;
};

#endif /* ROTARYENCODER_H_ */
