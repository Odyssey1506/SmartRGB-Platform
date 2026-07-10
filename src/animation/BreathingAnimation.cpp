#include "animation/BreathingAnimation.h"

void BreathingAnimation::begin()
{
    brightness = 0;
    increasing = true;
}

void BreathingAnimation::update(
    LightingScene& scene,
    const AnimationContext& context)
{
    if (increasing)
    {
        if (brightness < 255)
            brightness++;
        else
            increasing = false;
    }
    else
    {
        if (brightness > 0)
            brightness--;
        else
            increasing = true;
    }

    scene.zones[0].brightness = brightness;
    scene.zones[1].brightness = brightness;
}