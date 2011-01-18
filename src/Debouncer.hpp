/*
 * Debouncer.hpp
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


#ifndef DEBOUNCER_HPP_
#define DEBOUNCER_HPP_

#include "Command.hpp"
#include <stdint.h>

class Debouncer :public Command {
public:
	Debouncer(Command &command,uint8_t port,uint8_t threshold = 3);
	void execute();

protected:
	Command &m_command;
	uint8_t m_port;
	uint8_t m_state;
	uint8_t m_counter;
	const uint8_t m_threshold;
};

#endif /* DEBOUNCER_HPP_ */
