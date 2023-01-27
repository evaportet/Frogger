#include "Object.h"

Transform Object::GetTransform()
{
    return transform;
}

Collider Object::GetCollider()
{
    return collider;
}

float Object::GetSpeed()
{
    return speed;
}

void Object::SetTransform(Transform newTransform)
{
    transform = newTransform;
}

void Object::SetSpeed(float newSpeed)
{
    speed = newSpeed;
}

void Object::SetPosition(Vector2 newPos)
{
    transform.position = newPos;
    collider.SetCenter(newPos);
}

void Object::SetRotation(float newRotation)
{
    transform.rotation = newRotation;
}

void Object::SetScale(Vector2 newScale)
{
    transform.scale = newScale;
}
