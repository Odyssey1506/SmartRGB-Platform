#pragma once

#include <stdint.h>

enum class Event : uint8_t
{
    None = 0,

    BrightnessChanged,

    ColorChanged,

    EffectChanged,

    SceneChanged,

    StartupChanged,

    SettingsSaved
};