#include "Turtles.h"

clock_t startTurtles = 0;
double durationTurtles;

Turtles::Turtles()
{

}

Turtles::Turtles(int length, Vector2 pos, float spd)
{
	transform.position = pos;
	transform.scale = Vector2(16 * length, 16);
	transform.rotation = 0;

	collider = Collider(pos, transform.scale * 2.f, ColliderType::PLATFORM);
	CH->AddCollider(&collider);
	speed = spd;
	SetSpeed(spd);
	renderer.Load("resources/assets/Turtles.png");
	renderer.SetPosition(collider.GetCenterPivot());
	renderer.SetScale(transform.scale);
	renderer.OverrideTargetPixelSize(Vector2(3, 3));
}

void Turtles::Update(float dt)
{
	//durationTurtles = (clock() - startTurtles) / CLOCKS_PER_SEC;
	SetPosition(transform.position + Vector2(speed, 0) * dt);
	renderer.SetPosition(transform.position);
	CH->OnPlayerCollision(&collider);
	if (CH->PlayerCollision(&collider))
	{
		CH->StoreAttachedVel(speed*dt);
	}

	/*if (durationTurtles >= FRAMERATE)
	{
		transform.position.x += speed;
		Vector2 newTopLeft = collider.GetTopLeft();
		newTopLeft.x += speed;
		collider.SetTopLeft(newTopLeft);

		startTurtles = clock();
	}*/
}

void Turtles::Render()
{
	renderer.Render();
}
