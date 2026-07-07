#pragma once

#include "ZoneSettings.h"

struct LightingScene
{
    static constexpr uint8_t MAX_ZONES = 2;

    ZoneSettings zones[MAX_ZONES];
};