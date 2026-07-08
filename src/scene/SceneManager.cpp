#include "scene/SceneManager.h"
#include <string.h>

bool SceneManager::loadScene(DeviceSettings& settings,
                             uint8_t slot)
{
    if (slot >= MAX_SCENES)
        return false;

    if (!settings.scenes[slot].used)
        return false;

    settings.currentScene = settings.scenes[slot].scene;

    return true;
}