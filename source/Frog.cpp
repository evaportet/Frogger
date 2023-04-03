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

	collider = Collider(pos, size * 1.5f, ct);
	CH->SetPlayerCollider(&collider);
	renderer.Load(path);
	renderer.SetScale(transform.scale);
	renderer.SetPosition(pos);
	renderer.SetSourcePos(Vector2(0, 0));
	renderer.OverrideTargetPixelSize(Vector2(3, 3));
	renderer.SetRotation(transform.rotation);

	food = nullptr;
	hasFood = false;
	moves = false;
	OnMovingSuface = false;
	lives = 3;
}

void Frog::Respawn()
{
	//frogTransform.position()
	SetPosition(spawnPos);
	renderer.SetPosition(spawnPos + Vector2(0, 20));
	SetRotation(0);
	renderer.SetRotation(0);
	lives--;
}

void Frog::Movement()
{
	Vector2 newMovement;
	const int MOVEMENT_STEP = 37;
	const int BOUND_OFFSET = 60;

	if (OnMovingSuface)
	{
		newMovement = Vector2(transform.position.x + movingPlatf_speed, transform.position.y);
		SetPosition(newMovement);
		renderer.SetPosition(newMovement);
		OnMovingSuface = false;
	}

	if (IM->CheckKeyState(SDLK_UP, DOWN))
	{
		if (transform.position.y > MOVEMENT_STEP) {
			AM->PlaySFX("Jump", 0);
			newMovement = Vector2(transform.position.x, transform.position.y - MOVEMENT_STEP);
			SetPosition(newMovement);
			renderer.SetPosition(newMovement);
			SetRotation(0);
			renderer.SetRotation(0);
		}
	}

	else if (IM->CheckKeyState(SDLK_DOWN, DOWN))
	{
		if (transform.position.y < RM->windowHeight - 110) {
			AM->PlaySFX("Jump", 0);
			newMovement = Vector2(transform.position.x, transform.position.y + MOVEMENT_STEP);
			SetPosition(newMovement);
			renderer.SetPosition(newMovement);
			SetRotation(180);
			renderer.SetRotation(180);
		}
	}

	else if (IM->CheckKeyState(SDLK_LEFT, DOWN))
	{
		if (transform.position.x > BOUND_OFFSET) {
			AM->PlaySFX("Jump", 0);
			newMovement = Vector2(transform.position.x - MOVEMENT_STEP, transform.position.y);
			SetPosition(newMovement);
			renderer.SetPosition(newMovement);
			SetRotation(270);
			renderer.SetRotation(270);
		}
	}

	else if (IM->CheckKeyState(SDLK_RIGHT, DOWN))
	{
		if (transform.position.x < RM->windowWidth - BOUND_OFFSET) {
			AM->PlaySFX("Jump", 0);
			newMovement = Vector2(transform.position.x + MOVEMENT_STEP, transform.position.y);
			SetPosition(newMovement);
			renderer.SetPosition(newMovement);
			SetRotation(90);
			renderer.SetRotation(90);
		}
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
		case CollisionResult::DROWNED:
			if (OnMovingSuface) break;
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
		case CollisionResult::ON_PLATFORM:
			OnMovingSuface = true;
			movingPlatf_speed = CH->GetAttachedVel();
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
