#include "scene/SceneManager.h"

SceneManager::SceneManager(DeviceSettings& settings)
    : settingsData(settings)
{
}

bool SceneManager::save(uint8_t slot)
{
    if (slot >= MaxScenes)
        return false;

    scenes[slot] = settingsData.currentScene;

    return true;
}

bool SceneManager::load(uint8_t slot)
{
    if (slot >= MaxScenes)
        return false;

    settingsData.currentScene = scenes[slot];

    return true;
}

uint8_t SceneManager::count() const
{
    return MaxScenes;
}