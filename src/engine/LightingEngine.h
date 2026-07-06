#pragma once

#include <Arduino.h>

#include "Color.h"
#include "Zone.h"
#include "drivers/OutputDriver.h"

class LightingEngine
{
public:

    void begin(OutputDriver& driver);

    void setZone(Zone zone,const Color& color);

private:

    OutputDriver* output=nullptr;

    Color zones[2];
};