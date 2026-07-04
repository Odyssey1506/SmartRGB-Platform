#include "Application.h"
#include <Arduino.h>
#include "pins.h"

void Application::begin()
{
    pinMode(Pins::RED, OUTPUT);

    digitalWrite(Pins::RED, LOW);
    //analogWriteRange(1023);
//analogWriteFreq(1000);
}

void Application::update()
{
    // Fade up
    for (int i = 0; i <= 1023; i++)
    {
        analogWrite(Pins::RED, i);
        delay(2);
    }

    // Fade down
    for (int i = 1023; i >= 0; i--)
    {
        analogWrite(Pins::RED, i);
        delay(2);
    }
}
