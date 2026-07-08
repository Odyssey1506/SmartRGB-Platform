#include "storage/DirtySaveManager.h"
#include <Arduino.h>

void DirtySaveManager::mark()
{
    dirty = true;
    lastChange = millis();
}

void DirtySaveManager::update()
{
    // Nothing yet.
}

bool DirtySaveManager::shouldSave() const
{
    if (!dirty)
        return false;

    return (millis() - lastChange) >= SAVE_DELAY_MS;
}

void DirtySaveManager::clear()
{
    dirty = false;
}