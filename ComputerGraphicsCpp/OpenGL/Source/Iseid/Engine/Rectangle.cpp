#include "Iseid/Engine/Rectangle.h"
#include "Iseid/Engine/Core/Vector2.h"
#include "Iseid/Engine/Core/Colors.h"

Rectangle::Rectangle()
{
    // Color = Colors::White;
    // Position = Vector2::Zero;
    // Size = Vector2::Zero;
}

Rectangle::Rectangle(const Vector2& position, const Vector2& size, const ::Color& color)
{
    Position = position;
    Size = size;
    Color = color;
}


