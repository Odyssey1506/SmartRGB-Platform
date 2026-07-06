#include "OutputDriver.h"
#include "pins.h"

constexpr uint32_t PWM_FREQUENCY = 1000;
constexpr uint8_t PWM_RESOLUTION = 12;


void OutputDriver::begin()
{
    // Map channels to GPIO pins
    pinMap[0] = Pins::RED;
    pinMap[1] = Pins::GREEN;
    pinMap[2] = Pins::BLUE;
    pinMap[3] = Pins::WHITE;

    pinMap[4] = 21;
    pinMap[5] = 22;
    pinMap[6] = 23;
    pinMap[7] = 25;

    // Initialize all PWM channels
    for (uint8_t channel = 0; channel < OutputDriver::CHANNEL_COUNT; channel++)
    {
       ledcSetup(channel, PWM_FREQUENCY, PWM_RESOLUTION);
ledcAttachPin(pinMap[channel], channel);
ledcWrite(channel, 0);
    }
}
void OutputDriver::write(uint8_t channel, uint16_t value)
{
    ledcWrite(channel, value);
}
void OutputDriver::setChannel(uint8_t channel, uint16_t value)
{
    write(channel, value);
}

void OutputDriver::setRGBW(uint8_t firstChannel, const Color& color)
{
    setChannel(firstChannel + 0, color.red);
    setChannel(firstChannel + 1, color.green);
    setChannel(firstChannel + 2, color.blue);
    setChannel(firstChannel + 3, color.white);
}