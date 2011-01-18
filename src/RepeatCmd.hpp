/*
 *  RepeatCmd - A repeated Command
 *  Author: Christian Ege <chege(at)cybertux.org>
 *  Copyright (c) 2011 Markdorf Germany
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licens
 */

#include "Command.hpp"
#include "RotaryEncoder.h"

class RepeatCmd :public Command
{
public:
		RepeatCmd(RotaryEncoder &enc);
		virtual void execute();
protected:
		bool high;
		RotaryEncoder& m_enc;
};
