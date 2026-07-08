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
    String key;

    // Brightness
    key = "z" + String(index) + "_br";
    preferences.putUChar(key.c_str(), zone.brightness);

    // Enabled
    key = "z" + String(index) + "_en";
    preferences.putBool(key.c_str(), zone.enabled);

    // Effect
    key = "z" + String(index) + "_ef";
    preferences.putUChar(key.c_str(),
                         static_cast<uint8_t>(zone.effect));

    // Speed
    key = "z" + String(index) + "_sp";
    preferences.putUChar(key.c_str(), zone.speed);

    // Color
    saveColor(zone.solidColor, "z" + String(index));

    return true;
}
bool SettingsManager::loadZone(ZoneSettings& zone, uint8_t index)
{
    String key;

    // Brightness
    key = "z" + String(index) + "_br";
    zone.brightness = preferences.getUChar(key.c_str(), 255);

    // Enabled
    key = "z" + String(index) + "_en";
    zone.enabled = preferences.getBool(key.c_str(), true);

    // Effect
    key = "z" + String(index) + "_ef";
    zone.effect = static_cast<Effect>(
        preferences.getUChar(key.c_str(), 0));

    // Speed
    key = "z" + String(index) + "_sp";
    zone.speed = preferences.getUChar(key.c_str(), 128);

    // Color
    loadColor(zone.solidColor, "z" + String(index));

    return true;
}

bool SettingsManager::saveColor(
    const Color& color,
    const String& prefix)
{
preferences.putUChar((prefix + "_r").c_str(), color.r);
preferences.putUChar((prefix + "_g").c_str(), color.g);
preferences.putUChar((prefix + "_b").c_str(), color.b);
preferences.putUChar((prefix + "_w").c_str(), color.w);

return true;

}

bool SettingsManager::loadColor(Color& color, const String& prefix)
{
    color.r = preferences.getUChar((prefix + "_r").c_str(), 0);
    color.g = preferences.getUChar((prefix + "_g").c_str(), 0);
    color.b = preferences.getUChar((prefix + "_b").c_str(), 0);
    color.w = preferences.getUChar((prefix + "_w").c_str(), 0);

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