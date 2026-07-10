#pragma once

#include "LightingScene.h"
#include "animation/AnimationContext.h"

class IAnimation
{
public:
    virtual ~IAnimation() = default;

    virtual void begin() = 0;

    virtual void update(LightingScene& scene,
                        const AnimationContext& context) = 0;
};