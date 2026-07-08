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
        output->setRGBW(ChannelMap::ZoneA, color);
    }
    else
    {
       output->setRGBW(ChannelMap::ZoneB, color);
    }
}
void LightingEngine::render(const LightingScene& scene)
{
    output->setRGBW(
        ChannelMap::ZoneA,
        scene.zones[0].solidColor);

    output->setRGBW(
        ChannelMap::ZoneB,
        scene.zones[1].solidColor);
}