#include "Iseid/Engine/GameObject.h"

#include "Iseid/Engine/Core/Vector2.h"

GameObject::GameObject()
{
    this->Position = Vector2(0, 0);
}

GameObject::GameObject(const Vector2 position)
{
    this->Position = position;
}

GameObject::~GameObject()
= default;

void GameObject::Draw()
{
    // Do nothing
}
