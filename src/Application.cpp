#include "Application.h"
#include <Arduino.h>
#include "pins.h"


void Application::begin()
{
      output.begin();
}

void Application::update()
{
    // Fade up
for(uint16_t i = 0; i <= 4095; i++)
{
    output.setRed(i);
    delay(1);
}
    // Fade down
for(int i = 4095; i >= 0; i--)

{
    output.setRed(i);
    delay(1);
}
}
