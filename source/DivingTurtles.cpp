#include "DivingTurtles.h"

clock_t startSurface = 0;
clock_t startDiving = 0;
double durationDivingTurtles;

DivingTurtles::DivingTurtles(int length, Vector2 pos, float spd, float srfD, float divD)
{
	surfaceDuration = srfD;
	divingDuration = divD;

	transform.position = pos;
	transform.scale = Vector2(16 * length, 16);
	transform.rotation = 0;

	collider = Collider(pos, transform.scale, ColliderType::LOG);
	speed = spd;
}

void DivingTurtles::Update(float dt)
{
	currentDuration = (clock() - startDiving) / CLOCKS_PER_SEC;
	CH->OnPlayerCollision(&collider);

	if (currentDuration >= surfaceDuration && collider.GetType() == ColliderType::LOG)
	{
		collider.SetType(ColliderType::DMG);
		startDiving = clock();
	}
	else if (currentDuration >= divingDuration && collider.GetType() == ColliderType::DMG)
	{
		collider.SetType(ColliderType::LOG);
		startDiving = clock();
	}

	durationDivingTurtles = (clock() - startSurface) / (double)CLOCKS_PER_SEC;

	if (durationDivingTurtles >= FRAMERATE)
	{
		transform.position.x += speed;
		Vector2 newTopLeft = collider.GetTopLeft();
		newTopLeft.x += speed;
		collider.SetTopLeft(newTopLeft);

		startSurface = clock();
	}
}

void DivingTurtles::Render()
{
}
