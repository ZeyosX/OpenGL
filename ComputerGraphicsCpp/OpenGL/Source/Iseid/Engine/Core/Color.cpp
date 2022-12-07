#include "Iseid/Engine/Core/Color.h"

Color::Color()
{
    Red = 0;
    Green = 0;
    Blue = 0;
    Alpha = 0;
}

Color::Color(const float red, const float green, const float blue, const float alpha)
{
    this->Red = red;
    this->Green = green;
    this->Blue = blue;
    this->Alpha = alpha;
}
