#pragma once

#include "DeviceSettings.h"

class SceneManager
{
public:
    bool saveScene(DeviceSettings& settings,
                   uint8_t slot,
                   const char* name);

    bool loadScene(DeviceSettings& settings,
                   uint8_t slot);

    bool deleteScene(DeviceSettings& settings,
                     uint8_t slot);

    bool renameScene(DeviceSettings& settings,
                     uint8_t slot,
                     const char* name);
};