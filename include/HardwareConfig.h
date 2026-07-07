#pragma once

#include <Arduino.h>

struct ZoneConfig
{
    uint8_t firstChannel;
};

struct HardwareConfig
{
    static constexpr uint8_t ZONE_COUNT = 2;

    static constexpr ZoneConfig zones[ZONE_COUNT] =
    {
        {0},
        {4}
    };
};