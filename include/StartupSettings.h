#pragma once

#include "LightingScene.h"

enum class StartupBehavior
{
    RestoreLastState,

    FactoryDefault,

    AlwaysOff,

    CustomScene
};

struct StartupSettings
{
    StartupBehavior behavior = StartupBehavior::RestoreLastState;

    LightingScene customScene;
};