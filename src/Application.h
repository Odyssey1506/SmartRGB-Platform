#pragma once
#include "drivers/OutputDriver.h"
#include "engine/LightingEngine.h"
#include "Timer.h"
#include "settings/SettingsManager.h"
#include "storage/DirtySaveManager.h"
#include "DeviceSettings.h"
#include "ZoneSettings.h"
#include "Zone.h"
#include "Color.h"
#include "Effect.h"

class Application
{
public:
    void begin();
    void update();
    void render();
    ZoneSettings& getZone(Zone zone);
    void setZoneColor(Zone zone, const Color& color);
    void setBrightness(Zone zone, uint8_t brightness);
    void setEffect(Zone zone, Effect effect);
    void setSpeed(Zone zone, uint8_t speed);
    void setZoneEnabled(Zone zone, bool enabled);
    void stateChanged(bool needsRender = true);
    
    private:
    OutputDriver output;
    LightingEngine lighting;
    SettingsManager settings;
    Timer timer;
    DeviceSettings settingsData;
    DirtySaveManager dirtySave;
};
