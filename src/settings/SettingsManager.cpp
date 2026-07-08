#include "settings/SettingsManager.h"
#include <Arduino.h>

//--------------------------------------------------
// Public Functions
//--------------------------------------------------

bool SettingsManager::begin()
{
    bool ok = preferences.begin("smartrgb", false);
    return ok;
}

bool SettingsManager::load(DeviceSettings& settings)
{
    loadZone(settings.currentScene.zones[0], 0);
    loadZone(settings.currentScene.zones[1], 1);

    return true;
}

bool SettingsManager::save(const DeviceSettings& settings)
{
    saveZone(settings.currentScene.zones[0], 0);
    saveZone(settings.currentScene.zones[1], 1);

    return true;
}

void SettingsManager::reset(DeviceSettings& settings)
{
    settings = DeviceSettings();
}

//--------------------------------------------------
// Private Functions
//--------------------------------------------------

bool SettingsManager::saveZone(const ZoneSettings& zone, uint8_t index)
{
    String key = "z" + String(index) + "_br";

    preferences.putUChar(key.c_str(), zone.brightness);

    return true;
}

bool SettingsManager::loadZone(ZoneSettings& zone, uint8_t index)
{
    String key = "z" + String(index) + "_br";

    zone.brightness = preferences.getUChar(key.c_str(), 255);

    return true;
}