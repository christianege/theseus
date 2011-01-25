#
# CMakeLists.txt
#
# Created on: 01.01.2011
#      Author: Christian Ege <chege (at) cybertux.org>
#      Copyright (c) 2011 Markdorf Germany
#
# This Software is free software; you can redistribute it
# and/or modify it under the terms of the GNU Lesser
# General Public License as published by the Free Software
# Foundation; either version 2.1 of the License, or (at
# your option) any later version.
#
# This library is distributed in the hope that it will
# be useful, but WITHOUT ANY WARRANTY; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A
# PARTICULAR PURPOSE.  See the GNU Lesser General Public
# License for more details.
#
# You should have received a copy of the GNU Lesser
# General Public License along with this library; if not,
# write to the Free Software Foundation, Inc.,
# 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
#

project(theseus)

cmake_minimum_required(VERSION 2.6)

include(${CMAKE_SOURCE_DIR}/scripts/arduino_uno.cmake)

set(ARDUINO_SKETCHBOOK "$ENV{HOME}/sketchbook")

include_directories(
    ${CMAKE_SOURCE_DIR}/src
	${CMAKE_SOURCE_DIR}/libraries/DS1307
    ${CMAKE_SOURCE_DIR}/libraries/SimpleTimer
	${ARDUINO_LIBRARIES_DIR}/Wire/utility 
)

set(MYPROJECT_SOURCE_FILES
    ${CMAKE_SOURCE_DIR}/src/shutter.cpp
    ${CMAKE_SOURCE_DIR}/src/RepeatCmd.cpp
    ${CMAKE_SOURCE_DIR}/src/Command.cpp
    ${CMAKE_SOURCE_DIR}/src/RollerShutterTimes.cpp
    ${CMAKE_SOURCE_DIR}/src/RotaryEncoder.cpp
    ${CMAKE_SOURCE_DIR}/src/RollerShutter.cpp
    ${CMAKE_SOURCE_DIR}/src/Debouncer.cpp
    ${CMAKE_SOURCE_DIR}/src/MoveUp.cpp
    ${CMAKE_SOURCE_DIR}/src/MoveDown.cpp
    ${CMAKE_SOURCE_DIR}/src/MoveStop.cpp
    ${CMAKE_SOURCE_DIR}/src/EnableShutter.cpp
    ${CMAKE_SOURCE_DIR}/src/StopShutter.cpp
    ${CMAKE_SOURCE_DIR}/src/RollerShutterManager.cpp
    ${CMAKE_SOURCE_DIR}/src/ShutterClockTimer.cpp
    ${ARDUINO_SOURCE_FILES}
    ${CMAKE_SOURCE_DIR}/libraries/DS1307/DS1307.cpp
    ${ARDUINO_LIBRARIES_DIR}/Wire/Wire.cpp	 
    ${ARDUINO_LIBRARIES_DIR}/Wire/utility/twi.c	 
    ${CMAKE_SOURCE_DIR}/libraries/SimpleTimer/SimpleTimer.cpp
    
)


add_executable(firmware ${MYPROJECT_SOURCE_FILES})
