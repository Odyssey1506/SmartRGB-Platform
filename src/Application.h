#pragma once
#include "drivers/OutputDriver.h"
#include "engine/LightingEngine.h"
#include "Timer.h"
#include "settings/SettingsManager.h"
#include "storage/DirtySaveManager.h"

class Application
{
public:
    void begin();
    void update();
    void markSettingsDirty();

    private:
    OutputDriver output;
    LightingEngine lighting;
    SettingsManager settings;
    Timer timer;
    DeviceSettings settingsData;
    DirtySaveManager dirtySave;
};
