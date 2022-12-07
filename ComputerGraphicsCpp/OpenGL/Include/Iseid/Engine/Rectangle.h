#pragma once
#include "GameObject.h"
#include "Core/Color.h"

class Rectangle final : GameObject
{
public:
    Rectangle();
    Rectangle(const Vector2& position, const Vector2& size, const Color& color);
    
    Color Color;
};
