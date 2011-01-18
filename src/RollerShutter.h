/*
 * RollerShutter.h
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


#ifndef ROLLERSHUTTER_H_
#define ROLLERSHUTTER_H_

#include <stdint.h>

class RollerShutter
{

public:

	RollerShutter(uint8_t pinA, uint8_t pinB);

	void direction(bool up);
	void start();
	void stop();


protected:
	uint8_t m_pinPWR;
	uint8_t m_pinDIR;
};

#endif /* ROLLERSHUTTER_H_ */
