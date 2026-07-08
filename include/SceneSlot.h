#pragma once

#include "LightingScene.h"

constexpr uint8_t MAX_SCENES = 10;

struct SceneSlot
{
    bool used = false;

    char name[24] = "";

    LightingScene scene;
};