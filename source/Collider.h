#pragma once
#include "Vector2.h"
#include "Types.h"

class Collider {
private:
	Vector2 centerPivot;
	Vector2 topLeft;
	Vector2 size;
	ColliderType type;
public:
	Collider();
	Collider(Vector2 center, Vector2 s, ColliderType t);
	void SetTopLeft(Vector2 newPos);
	void SetType(ColliderType t);
	void SetCenter(Vector2 newCenter);
	Vector2 GetTopLeft();
	Vector2 GetCenterPivot();
	Vector2 GetSize();
	ColliderType GetType();
};