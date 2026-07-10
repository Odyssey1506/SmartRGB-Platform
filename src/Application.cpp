#include "Application.h"
#include <Arduino.h>

void Application::begin()
{
    Serial.begin(115200);

    output.begin();
    lighting.begin(output);

    settings.begin();

    settings.load(settingsData);
    render();

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
            setZoneColor(Zone::A, Color::Red());
        }
        else
        {
            setZoneColor(Zone::A, Color::Blue());
        }
    }

    // Always check for save
    if (dirtySave.shouldSave())
    {
        settings.save(settingsData);
        dirtySave.clear();
    }
}

void Application::render()
{
    lighting.render(settingsData.currentScene);
}

void Application::stateChanged(bool needsRender)
{
    if (needsRender)
    {
        render();
    }

    dirtySave.mark();
}

void Application::setZoneColor(Zone zone, const Color& color)
{
    getZone(zone).solidColor = color;

    stateChanged();
}

void Application::setBrightness(Zone zone, uint8_t brightness)
{
    getZone(zone).brightness = brightness;
    stateChanged();
}

void Application::setZoneEnabled(Zone zone, bool enabled)
{
    getZone(zone).enabled = enabled;

    stateChanged();
}

void Application::setSpeed(Zone zone, uint8_t speed)
{
    getZone(zone).speed = speed;
    stateChanged(false);
}

void Application::setEffect(Zone zone, Effect effect)
{
    getZone(zone).effect = effect;

    stateChanged();
}

ZoneSettings& Application::getZone(Zone zone)
{
    return settingsData.currentScene.zones[
        (zone == Zone::A) ? 0 : 1
    ];
}