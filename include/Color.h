#pragma once

#include <Arduino.h>

struct Color
{
    uint16_t red;
    uint16_t green;
    uint16_t blue;
    uint16_t white;

    Color(
        uint16_t r = 0,
        uint16_t g = 0,
        uint16_t b = 0,
        uint16_t w = 0)
        :
        red(r),
        green(g),
        blue(b),
        white(w)
    {
    }

    static Color Off();
    static Color Red();
    static Color Green();
    static Color Blue();
    static Color White();
};