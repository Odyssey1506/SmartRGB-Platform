#include "Color.h"

Color Color::Off()
{
    return Color(0, 0, 0, 0);
}

Color Color::Red()
{
    return Color(1023, 0, 0, 0);
}

Color Color::Green()
{
    return Color(0, 1023, 0, 0);
}

Color Color::Blue()
{
    return Color(0, 0, 1023, 0);
}

Color Color::White()
{
    return Color(0, 0, 0, 1023);
}