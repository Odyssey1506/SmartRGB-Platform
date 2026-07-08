#pragma once

#include "SceneSlot.h"
#include "LightingScene.h"
#include "StartupSettings.h"

struct DeviceSettings
{
    LightingScene currentScene;
    SceneSlot scenes[MAX_SCENES];
    StartupSettings startup;
};