#pragma once

#include <Arduino.h>
#include "Color.h"
class OutputDriver
{
public:

    static constexpr uint8_t CHANNEL_COUNT = 8;

    void begin();

    void write(uint8_t channel, uint16_t value);
    void setChannel(uint8_t channel, uint16_t value);

void setRGBW(uint8_t firstChannel, const Color& color);

private:

    uint8_t pinMap[CHANNEL_COUNT];
};
