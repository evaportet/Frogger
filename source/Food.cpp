#include "Food.h"

clock_t startFood = 0;
double durationFood;

Food::Food(Log* atachedLog, Vector2 pos, float spd)
{
	log = atachedLog;

	transform.position = pos;
	transform.scale = Vector2(16, 16);
	transform.rotation = 0;

	collider = Collider(pos, transform.scale, ColliderType::FOOD);
	speed = spd;
}

void Food::Update()
{
	durationFood = (clock() - startFood) / CLOCKS_PER_SEC;

	if (durationFood >= FRAMERATE)
	{
		transform.position.x += speed;
		Vector2 newTopLeft = collider.GetTopLeft();
		newTopLeft.x += speed;
		collider.SetTopLeft(newTopLeft);

		startFood = clock();
	}

	if (transform.position.x >= log->GetCollider().GetTopLeft().x + log->GetCollider().GetSize().x / 2 - 6 && speed > 0
		|| transform.position.x <= log->GetCollider().GetTopLeft().x - log->GetCollider().GetSize().x / 2 + 6 && speed < 0)
		speed *= -1;
}

void Food::Render()
{
	renderer.Render();
}
