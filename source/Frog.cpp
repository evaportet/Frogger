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

	collider = Collider(pos, size*3, ct);
	CH->SetPlayerCollider(&collider);
	renderer.Load(path);
	renderer.SetPosition(collider.GetTopLeft());
	renderer.SetScale(transform.scale);
	renderer.SetPosition(pos);
	renderer.SetSourcePos(Vector2(0, 0));
	renderer.OverrideTargetPixelSize(Vector2(3, 3));

	food = nullptr;
	hasFood = false;
	moves = false;
	lives = 3;
}

void Frog::Respawn()
{
	//frogTransform.position()
	SetPosition(spawnPos);
	renderer.SetPosition(spawnPos);
	lives--;
	printf_s("Current lives : %d", lives);
}

void Frog::Movement()
{
	Vector2 newMovement;

	if (IM->CheckKeyState(SDLK_UP, DOWN))
	{
		newMovement = Vector2(transform.position.x, transform.position.y - 20);
		SetPosition(newMovement);
		renderer.SetPosition(newMovement);
	}

	if (IM->CheckKeyState(SDLK_DOWN, DOWN))
	{
		newMovement = Vector2(transform.position.x, transform.position.y + 20);
		SetPosition(newMovement);
		renderer.SetPosition(newMovement);
		//sprite rotation 180
	}

	if (IM->CheckKeyState(SDLK_LEFT, DOWN))
	{
		newMovement = Vector2(transform.position.x - 20, transform.position.y );
		SetPosition(newMovement);
		renderer.SetPosition(newMovement);
		//sprite rotation 270
	}

	if (IM->CheckKeyState(SDLK_RIGHT, DOWN))
	{
		newMovement = Vector2(transform.position.x + 20, transform.position.y);
		SetPosition(newMovement);
		renderer.SetPosition(newMovement);
		//sprite rotation 90
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
			Respawn();
			break;
		case CollisionResult::BORDER:
			//BlockMovement
			break;
		case CollisionResult::END:
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
	CH->CrearPlayerHits();
}
