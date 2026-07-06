#pragma once

#include <Arduino.h>

class Timer
{
public:
    bool elapsed(uint32_t interval);

private:
    uint32_t lastTime = 0;
};