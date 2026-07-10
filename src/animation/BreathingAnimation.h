#pragma once

#include "IAnimation.h"

class BreathingAnimation : public IAnimation
{
public:
    void begin() override;

  void update(LightingScene& scene,
            const AnimationContext& context) override;
private:
    uint8_t brightness = 0;
    bool increasing = true;
};
