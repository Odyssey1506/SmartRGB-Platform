#pragma once

#include <stdint.h>

struct Color
{
    uint8_t r = 0;
    uint8_t g = 0;
    uint8_t b = 0;
    uint8_t w = 0;

    constexpr Color() = default;

    constexpr Color(uint8_t red,
                    uint8_t green,
                    uint8_t blue,
                    uint8_t white = 0)
        : r(red), g(green), b(blue), w(white)
    {
    }

    static constexpr Color Red()
    {
        return Color(255, 0, 0);
    }

    static constexpr Color Green()
    {
        return Color(0, 255, 0);
    }

    static constexpr Color Blue()
    {
        return Color(0, 0, 255);
    }

    static constexpr Color White()
    {
        return Color(255, 255, 255, 255);
    }

    static constexpr Color Black()
    {
        return Color(0, 0, 0);
    }
};