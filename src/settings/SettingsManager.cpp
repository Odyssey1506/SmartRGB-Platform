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
    putByte(index, "br", zone.brightness);
    putBool(index, "en", zone.enabled);
    putByte(index, "ef", static_cast<uint8_t>(zone.effect));
    putByte(index, "sp", zone.speed);

    saveColor(zone.solidColor, index);

    return true;
}
bool SettingsManager::loadZone(ZoneSettings& zone, uint8_t index)
{
    zone.brightness = getByte(index, "br", 255);
    zone.enabled = getBool(index, "en", true);
    zone.effect = static_cast<Effect>(getByte(index, "ef", 0));
    zone.speed = getByte(index, "sp", 128);

    loadColor(zone.solidColor, index);

    return true;
}

bool SettingsManager::saveColor(const Color& color, uint8_t zone)
{
    putByte(zone, "r", color.r);
    putByte(zone, "g", color.g);
    putByte(zone, "b", color.b);
    putByte(zone, "w", color.w);

    return true;
}

bool SettingsManager::loadColor(Color& color, uint8_t zone)
{
    color.r = getByte(zone, "r", 0);
    color.g = getByte(zone, "g", 0);
    color.b = getByte(zone, "b", 0);
    color.w = getByte(zone, "w", 0);

    return true;
}

String SettingsManager::makeKey(uint8_t zone, const char* field)
{
    return "z" + String(zone) + "_" + field;
}

void SettingsManager::putByte(uint8_t zone,
                              const char* field,
                              uint8_t value)
{
    preferences.putUChar(makeKey(zone, field).c_str(), value);
}

uint8_t SettingsManager::getByte(uint8_t zone,
                                 const char* field,
                                 uint8_t defaultValue)
{
    return preferences.getUChar(makeKey(zone, field).c_str(),
                                defaultValue);
}

void SettingsManager::putBool(uint8_t zone,
                              const char* field,
                              bool value)
{
    preferences.putBool(makeKey(zone, field).c_str(), value);
}

bool SettingsManager::getBool(uint8_t zone,
                              const char* field,
                              bool defaultValue)
{
    return preferences.getBool(makeKey(zone, field).c_str(),
                               defaultValue);
}