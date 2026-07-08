#pragma once

#include "StartupMode.h"

struct StartupSettings
{
    StartupMode mode = StartupMode::ResumeLastState;

    uint8_t defaultScene = 0;
};