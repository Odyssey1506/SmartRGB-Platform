#pragma once

#include "DeviceSettings.h"
#include "Zone.h"
#include "Color.h"
#include "Effect.h"

class ZoneController
{
public:
    explicit ZoneController(DeviceSettings& settings);

    ZoneSettings& zone(Zone zone);

private:
    DeviceSettings& settingsData;
};