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
};