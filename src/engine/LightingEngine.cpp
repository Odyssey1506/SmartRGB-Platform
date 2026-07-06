#include "engine/LightingEngine.h"
#include "ChannelMap.h"
void LightingEngine::begin(OutputDriver& driver)
{
    output = &driver;
}

void LightingEngine::setZone(Zone zone, const Color& color)
{
    if (zone == Zone::A)
    {
        zones[0] = color;

        output->setRGBW(ChannelMap::ZoneA, color);
    }
    else
    {
        zones[1] = color;

       output->setRGBW(ChannelMap::ZoneB, color);
    }
}