#include "Application.h"
#include <Arduino.h>

void Application::begin()
{
   output.begin();

   lighting.begin(output);

   settings.begin();
}

void Application::update()
{
    static bool state = false;

    if (timer.elapsed(2000))
    {
        state = !state;

        if (state)
            lighting.setZone(Zone::A, Color::Red());
        else
            lighting.setZone(Zone::A, Color::Blue());
    }
}