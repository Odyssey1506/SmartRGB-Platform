#pragma once

#include <Preferences.h>
#include "DeviceSettings.h"

class SettingsManager
{
public:
    bool begin();

    bool load(DeviceSettings& settings);

    bool save(const DeviceSettings& settings);

    void reset(DeviceSettings& settings);

private:

    Preferences preferences;

bool saveZone(const ZoneSettings& zone, uint8_t index);

bool loadZone(ZoneSettings& zone, uint8_t index);

bool saveColor(const Color& color,
               const String& prefix);

bool loadColor(Color& color,
               const String& prefix);

               String makeKey(uint8_t zone, const char* field);

void putByte(uint8_t zone, const char* field, uint8_t value);

uint8_t getByte(uint8_t zone, const char* field, uint8_t defaultValue);

void putBool(uint8_t zone, const char* field, bool value);

bool getBool(uint8_t zone, const char* field, bool defaultValue);
};