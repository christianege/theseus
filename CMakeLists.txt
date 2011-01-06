project(MYPROJECT)

cmake_minimum_required(VERSION 2.6)

include(${CMAKE_SOURCE_DIR}/scripts/arduino_uno.cmake)

set(ARDUINO_SKETCHBOOK "$ENV{HOME}/sketchbook")

set(MYPROJECT_SOURCE_FILES
    ${CMAKE_SOURCE_DIR}/src/shutter.cpp
    ${ARDUINO_SOURCE_FILES}
    ${CMAKE_SOURCE_DIR}/libraries/DS1307/DS1307.cpp
    ${ARDUINO_LIBRARIES_DIR}/Wire/Wire.cpp	 
    ${ARDUINO_LIBRARIES_DIR}/Wire/utility/twi.c	 
    ${CMAKE_SOURCE_DIR}/libraries/SimpleTimer/SimpleTimer.cpp
)

include_directories(
	${CMAKE_SOURCE_DIR}/libraries/DS1307
    	${CMAKE_SOURCE_DIR}/libraries/SimpleTimer
	${ARDUINO_LIBRARIES_DIR}/Wire/utility	 
)

add_executable(firmware ${MYPROJECT_SOURCE_FILES})
