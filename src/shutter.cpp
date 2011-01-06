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

