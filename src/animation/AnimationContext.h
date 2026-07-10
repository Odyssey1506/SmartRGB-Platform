#pragma once

#include <stdint.h>

struct AnimationContext
{
    uint32_t currentTime = 0;
    uint32_t deltaTime = 0;
};