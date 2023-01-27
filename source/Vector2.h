#pragma once
#include <math.h>

struct Vector2 {
public:
	float x;
	float y;
	Vector2();
	Vector2(float x, float y);
	void Normalize();
    Vector2 operator+ (const Vector2& other) const {
        return Vector2(this->x + other.x, this->y + other.y);
    }
    Vector2 operator- (const Vector2& other) const {
        return Vector2(this->x - other.x, this->y - other.y);
    }
    Vector2 operator* (float scalar) const {
        return Vector2(this->x * scalar, this->y * scalar);
    }
    Vector2 operator/ (float scalar) const {
        return Vector2(this->x / scalar, this->y / scalar);
    }
    bool operator== (const Vector2& other) const {
        return (this->x == other.x && this->y == other.y);
    }
    bool operator!= (const Vector2& other) const {
        return !(this->x == other.x && this->y == other.y);
    }
};