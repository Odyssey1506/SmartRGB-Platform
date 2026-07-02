#pragma once

#include <Arduino.h>

namespace Config
{
    constexpr uint16_t PWM_RANGE = 255;
    constexpr uint16_t PWM_FREQUENCY = 1000;

    constexpr char DEVICE_NAME[] = "SmartRGB Platform";
}