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
{
    settingsData.currentScene.zones[0].solidColor = Color::Red();

    lighting.setZone(
        Zone::A,
        settingsData.currentScene.zones[0].solidColor);

    dirtySave.mark();
}
else
{
    settingsData.currentScene.zones[0].solidColor = Color::Blue();

    lighting.setZone(
        Zone::A,
        settingsData.currentScene.zones[0].solidColor);

    dirtySave.mark();
}
}

if (dirtySave.shouldSave())
{
    settings.save(settingsData);

    dirtySave.clear();
}
}