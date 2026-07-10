#pragma once
#include "Color.h"
#include "Effect.h"
#include "AnimationType.h"

struct ZoneSettings
{
    Color solidColor;

    uint8_t brightness = 255;

    Effect effect;          // Keep this for now

    AnimationType animation = AnimationType::Solid;

    uint8_t speed = 128;

    bool enabled = true;
};
