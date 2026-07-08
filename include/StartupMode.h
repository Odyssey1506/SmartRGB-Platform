#pragma once

#include <stdint.h>

enum class StartupMode : uint8_t
{
    ResumeLastState = 0,
    DefaultScene,
    LightsOff
};