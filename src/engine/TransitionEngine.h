#pragma once

#include "LightingScene.h"

class TransitionEngine
{
public:

    void start(const LightingScene& from,
               const LightingScene& to,
               uint32_t duration);

    bool update(LightingScene& output);

    bool running() const;

private:

    LightingScene startScene;

    LightingScene targetScene;

    uint32_t startTime = 0;

    uint32_t durationMs = 0;

    bool active = false;
};
