#pragma once

#include <Arduino.h>

#include "Color.h"
#include "Zone.h"
#include "drivers/OutputDriver.h"
#include "LightingScene.h"

class LightingEngine
{
public:

    void begin(OutputDriver& driver);

    void setZone(Zone zone,const Color& color);

    void render(const LightingScene& scene);
private:

    OutputDriver* output=nullptr;

};