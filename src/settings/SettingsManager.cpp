#include "settings/SettingsManager.h"

bool SettingsManager::begin()
{
    return true;
}

bool SettingsManager::load(DeviceState& state)
{
    return true;
}

bool SettingsManager::save(const DeviceState& state)
{
    return true;
}

void SettingsManager::reset(DeviceState& state)
{
    state = DeviceState();
}