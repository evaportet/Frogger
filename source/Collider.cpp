#include "Collider.h"

Collider::Collider()
{
	topLeft = Vector2();
	size = Vector2();
	type = ColliderType::LOG;
}

Collider::Collider(Vector2 center, Vector2 s, ColliderType t)
{
	topLeft.x = center.x - s.x / 2;
	topLeft.y = center.y - s.y / 2;
	size = s;
	type = t;
}

void Collider::SetTopLeft(Vector2 newPos)
{
	topLeft = newPos;
}

void Collider::SetType(ColliderType t)
{
	type = t;
}

void Collider::SetCenter(Vector2 newCenter)
{
	topLeft.x = newCenter.x - size.x / 2;
	topLeft.y = newCenter.y - size.y / 2;
}

Vector2 Collider::GetTopLeft()
{
	return topLeft;
}

Vector2 Collider::GetSize()
{
	return size;
}

ColliderType Collider::GetType()
{
	return type;
}
