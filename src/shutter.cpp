/*  
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

#include <WProgram.h>
#include <SimpleTimer.h>

void loop() {
    Serial.println("LED on");
    digitalWrite(13, HIGH);   // Set the LED on
    delay(3000);              // Wait for three seconds

    Serial.println("LED off");
    digitalWrite(13, LOW);    // Set the LED off
    delay(3000);              // Wait for three seconds
}

void setup()
{
	Serial.begin(115200);

    // Pin 13 has an LED connected on most Arduino boards
    pinMode(13, OUTPUT);
}

