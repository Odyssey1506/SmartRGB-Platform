#pragma once

#include "Event.h"

class EventBus
{
public:
    void publish(Event event);
};