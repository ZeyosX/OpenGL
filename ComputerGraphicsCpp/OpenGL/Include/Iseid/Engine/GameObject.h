#pragma once
#include "Core/Vector2.h"

class GameObject
{
public:
    GameObject();
    explicit GameObject(Vector2 position);
    virtual ~GameObject();
    Vector2 Position;
    Vector2 Size;
    virtual void Draw();
    
};
