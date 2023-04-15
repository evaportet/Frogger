#include "Food.h"

Food::Food(Log* atachedLog, Vector2 pos, float spd) : isPicked(false)
{
	log = atachedLog;

	transform.position = pos;
	transform.scale = Vector2(1204, 670);
	transform.rotation = 0;

	collider = Collider(pos, transform.scale*0.03f, ColliderType::FOOD);
	CH->AddCollider(&collider);
	renderer.Load("resources/Assets/comida_frogger.png");
	renderer.SetScale(transform.scale);
	renderer.SetPosition(pos);
	renderer.SetSourcePos(Vector2(0, 0));
	renderer.OverrideTargetPixelSize(Vector2(0.03f, 0.03f));
	renderer.SetRotation(transform.rotation);
	speed = spd;
	SetSpeed(spd);
}

void Food::Update(float dt)
{
	//durationFood = (clock() - startFood) / CLOCKS_PER_SEC;
	
	SetPosition(transform.position + Vector2(speed, 0)*dt);
	renderer.SetPosition(transform.position);

	CH->OnPlayerCollision(&collider);
	if (CH->PlayerCollision(&collider))
	{
		isPicked = true;
	}

	/*if (durationFood >= FRAMERATE)
	{
		transform.position.x += speed;
		Vector2 newTopLeft = collider.GetTopLeft();
		newTopLeft.x += speed;
		collider.SetTopLeft(newTopLeft);

		startFood = clock();
	}

	if (transform.position.x >= log->GetCollider().GetTopLeft().x + log->GetCollider().GetSize().x / 2 - 6 && speed > 0
		|| transform.position.x <= log->GetCollider().GetTopLeft().x - log->GetCollider().GetSize().x / 2 + 6 && speed < 0)
		speed *= -1;*/
}

void Food::Render()
{
	renderer.Render();
}

bool Food::IsPicked()
{
	return isPicked;
}
