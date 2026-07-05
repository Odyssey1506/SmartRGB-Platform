#pragma once

#include <Arduino.h>

class OutputDriver
{
public:

    static constexpr uint8_t CHANNEL_COUNT = 8;

    void begin();

    void write(uint8_t channel, uint16_t value);

private:

    uint8_t pinMap[CHANNEL_COUNT];
};