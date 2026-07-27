#pragma once

#include "DeviceSettings.h"

class SceneManager
{
public:
    explicit SceneManager(DeviceSettings& settings);

    bool save(uint8_t slot);

    bool load(uint8_t slot);

    uint8_t count() const;

private:
    static constexpr uint8_t MaxScenes = 5;

    DeviceSettings& settingsData;

    LightingScene scenes[MaxScenes];
};