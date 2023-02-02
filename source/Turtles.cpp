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

	collider = Collider(pos, transform.scale, ColliderType::LOG);
	speed = spd;

	renderer.Load("resources/assets/Turtles.png");
	renderer.SetPosition(collider.GetTopLeft());
	renderer.SetScale(transform.scale);
	renderer.OverrideTargetPixelSize(Vector2(3, 3));
}

void Turtles::Update()
{
	durationTurtles = (clock() - startTurtles) / CLOCKS_PER_SEC;
	SetPosition(transform.position + Vector2(speed, 0));
	renderer.SetPosition(transform.position + Vector2(speed, 0));
	CH->OnPlayerCollision(&collider);

	if (durationTurtles >= FRAMERATE)
	{
		transform.position.x += speed;
		Vector2 newTopLeft = collider.GetTopLeft();
		newTopLeft.x += speed;
		collider.SetTopLeft(newTopLeft);

		startTurtles = clock();
	}
}

void Turtles::Render()
{
	renderer.Render();

}
