#include "Application.h"
#include <Arduino.h>

void Application::begin()
{
    Serial.begin(115200);

    output.begin();
    lighting.begin(output);

    settings.begin();

    settings.load(settingsData);

    Serial.print("Loaded brightness = ");
    Serial.println(settingsData.currentScene.zones[0].brightness);
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