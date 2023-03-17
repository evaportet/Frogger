#include "Frog.h"

Frog::Frog()
{
}

Frog::Frog(Vector2 size, Vector2 pos, ColliderType ct, std::string path)
{
	spawnPos = pos;
	transform.position = pos;
	transform.scale = size;
	transform.rotation = 0;

	collider = Collider(pos, size, ct);
	CH->SetPlayerCollider(&collider);
	renderer.Load(path);
	//renderer.SetPosition(collider.GetTopLeft());
	renderer.SetScale(transform.scale);
	renderer.SetPosition(pos);
	renderer.SetSourcePos(Vector2(0, 0));
	renderer.OverrideTargetPixelSize(Vector2(3, 3));
	renderer.SetRotation(transform.rotation);

	food = nullptr;
	hasFood = false;
	moves = false;
	lives = 3;
}

void Frog::Respawn()
{
	//frogTransform.position()
	SetPosition(spawnPos);
	renderer.SetPosition(spawnPos + Vector2(0, 20));
	lives--;
}

void Frog::Movement()
{
	Vector2 newMovement;

	if (IM->CheckKeyState(SDLK_UP, DOWN))
	{
		AM->PlaySFX("Jump", 0);
		newMovement = Vector2(transform.position.x, transform.position.y - 20);
		SetPosition(newMovement);
		renderer.SetPosition(newMovement);
		SetRotation(0);
		renderer.SetRotation(0);
	}

	else if (IM->CheckKeyState(SDLK_DOWN, DOWN))
	{
		AM->PlaySFX("Jump", 0);
		newMovement = Vector2(transform.position.x, transform.position.y + 20);
		SetPosition(newMovement);
		renderer.SetPosition(newMovement);
		SetRotation(180);
		renderer.SetRotation(180);
	}

	else if (IM->CheckKeyState(SDLK_LEFT, DOWN))
	{
		AM->PlaySFX("Jump", 0);
		newMovement = Vector2(transform.position.x - 20, transform.position.y );
		SetPosition(newMovement);
		renderer.SetPosition(newMovement);
		SetRotation(270);
		renderer.SetRotation(270);
	}

	else if (IM->CheckKeyState(SDLK_RIGHT, DOWN))
	{
		AM->PlaySFX("Jump", 0);
		newMovement = Vector2(transform.position.x + 20, transform.position.y);
		SetPosition(newMovement);
		renderer.SetPosition(newMovement);
		SetRotation(90);
		renderer.SetRotation(90);
	}
}

bool Frog::IsMoving()
{
	return false;
}

void Frog::Update()
{
	Movement();
	CH->SetPlayerCollider(&collider);
	//CH->StorePlayerHits();
	HandleHits(CH->GetPlayerHits());
}

void Frog::Render()
{
	renderer.Render();
}

void Frog::AddFood(Food* food)
{
}

void Frog::HandleHits(std::list<CollisionResult> hits)
{
	for (CollisionResult& hit : hits)
	{
		switch (hit)
		{
		case CollisionResult::DIE:
			//Respawn || GameOver
			AM->PlaySFX("Dead", 0);
			Respawn();
			break;
		case CollisionResult::BORDER:
			//BlockMovement
			break;
		case CollisionResult::END:
			AM->PlaySFX("GetEnd", 0);
			Respawn();
			//Respawn || Win
			break;
		case CollisionResult::FOOD:
			//Add food
			break;
		case CollisionResult::SAFE:
		case CollisionResult::NONE:
			break;
		default:
			break;
		}
	}
	CH->ClearPlayerHits();
}
