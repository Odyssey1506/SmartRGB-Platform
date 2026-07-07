#pragma once

#include "DeviceState.h"

class SettingsManager
{
public:

    bool begin();

    bool load(DeviceState& state);

    bool save(const DeviceState& state);

    void reset(DeviceState& state);
};