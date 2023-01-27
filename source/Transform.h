#pragma once
#include "Vector2.h"

class Transform {
public:
	Vector2 position;
	float rotation;
	Vector2 scale;
	Transform();
	Transform(float posx, float posy, float rot, float scalex, float scaley);
};