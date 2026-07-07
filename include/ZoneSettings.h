#pragma once

#include "Color.h"
#include "Effect.h"

struct ZoneSettings
{
    bool enabled = true;

    Color solidColor = Color::White();

    Effect effect = Effect::Solid;

    uint8_t brightness = 255;

    uint8_t speed = 128;
};