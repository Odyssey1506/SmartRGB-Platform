#pragma once

#include "animation/IAnimation.h"

class AnimationEngine
{
public:
    void begin(IAnimation* animation);

    void update(LightingScene& scene);

private:
    IAnimation* current = nullptr;
};