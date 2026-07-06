#include "Timer.h"

bool Timer::elapsed(uint32_t interval)
{
    uint32_t now = millis();

    if (now - lastTime >= interval)
    {
        lastTime = now;
        return true;
    }

    return false;
}