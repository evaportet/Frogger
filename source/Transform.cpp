#include "Transform.h"

Transform::Transform()
{
	position.x = 0;
	position.y = 0;
	rotation = 0.0f;
	scale.x = 0;
	scale.y = 0;
}

Transform::Transform(float posx, float posy, float rot, float scalex, float scaley)
{
	position.x = posx;
	position.y = posy;
	rotation = rot;
	scale.x = scalex;
	scale.y = scaley;
}
