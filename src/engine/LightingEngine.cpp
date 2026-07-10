#include "engine/LightingEngine.h"
#include "ChannelMap.h"

void LightingEngine::begin(OutputDriver& driver)
{
    output = &driver;
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