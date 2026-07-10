#include "managers/ZoneController.h"

ZoneController::ZoneController(DeviceSettings& settings)
    : settingsData(settings)
{
}

ZoneSettings& ZoneController::zone(Zone zone)
{
    return settingsData.currentScene.zones[
        (zone == Zone::A) ? 0 : 1
    ];
}