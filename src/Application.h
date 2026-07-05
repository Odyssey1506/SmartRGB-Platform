#pragma once
#include "drivers/OutputDriver.h"
class Application
{
public:
    void begin();
    void NewFunction();
    void update();

    private:
    OutputDriver output;
};