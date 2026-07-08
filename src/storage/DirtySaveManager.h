#pragma once

#include <stdint.h>

class DirtySaveManager
{
public:
    void mark();

    void update();

    bool shouldSave() const;

    void clear();

private:
    bool dirty = false;

    uint32_t lastChange = 0;

    static constexpr uint32_t SAVE_DELAY_MS = 2000;
};
