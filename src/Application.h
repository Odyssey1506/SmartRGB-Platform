#pragma once
#include "drivers/OutputDriver.h"
#include "engine/LightingEngine.h"
#include "Timer.h"

class Application
{
public:
    void begin();
    void update();

    private:
    OutputDriver output;
    LightingEngine lighting;

    Timer timer;
};