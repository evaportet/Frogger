#include "Vector2.h"

Vector2::Vector2()
{
	x = 0.0f;
	y = 0.0f;
}

Vector2::Vector2(float newx, float newy)
{
	x = newx;
	y = newy;
}

void Vector2::Normalize()
{
	int modulo = sqrt(pow(x, 2) + pow(y, 2));
	x = x / modulo;
	y = y / modulo;
}


