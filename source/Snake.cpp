#include "Snake.h"

clock_t startSnake = 0;
double durationSnake;

Snake::Snake(Log* atachedLog, Vector2 pos, float spd)
{
	log = atachedLog;

	transform.position = pos;
	transform.scale = Vector2(16, 16);
	transform.rotation = 0;

	collider = Collider(pos, transform.scale, ColliderType::SNK);
	speed = spd;
}

void Snake::Update()
{
	durationSnake = (clock() - startSnake) / CLOCKS_PER_SEC;
	CH->OnPlayerCollision(&collider);

	if (durationSnake >= FRAMERATE)
	{
		transform.position.x += speed;
		Vector2 newTopLeft = collider.GetTopLeft();
		newTopLeft.x += speed;
		collider.SetTopLeft(newTopLeft);

		startSnake = clock();
	}

	if (transform.position.x >= log->GetCollider().GetTopLeft().x + log->GetCollider().GetSize().x / 2 - 6 && speed > 0
		|| transform.position.x <= log->GetCollider().GetTopLeft().x - log->GetCollider().GetSize().x / 2 + 6 && speed < 0)
		speed *= -1;
}

void Snake::Render()
{
	renderer.Render();
}
