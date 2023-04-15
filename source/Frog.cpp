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

	collider = Collider(pos, size * 1.75f, ct);
	CH->SetPlayerCollider(&collider);
	renderer.Load(path);
	renderer.SetScale(transform.scale);
	renderer.SetSourcePos(Vector2(0, 0));
	renderer.OverrideTargetPixelSize(Vector2(3, 3));
	renderer.SetPosition(pos);
	renderer.SetRotation(transform.rotation);

	//food = nullptr;
	hasFood = false;
	moves = false;
	OnMovingSuface = false;
	lives = 3;
	score = 0;
	lastTopY = pos.y;
}

void Frog::SetScore(int newS)
{
	score = newS;
}

int Frog::GetScore()
{
	return score;
}

int Frog::GetLives()
{
	return lives;
}

void Frog::Respawn()
{
	ResetSprite();
	SetPosition(spawnPos);
	renderer.SetPosition(spawnPos);
	SetRotation(0);
	renderer.SetRotation(0);
	hasFood = false;
}

void Frog::Die()
{
	lives--;
	Respawn();
}

void Frog::Movement()
{
	Vector2 newMovement;
	const int MOVEMENT_STEP = 42;
	const int BOUND_OFFSET = 65;

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
			if (newMovement.y < lastTopY) {
				score += 10;
				lastTopY = newMovement.y;
			}
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

void Frog::ChangeToHasFoodSprt()
{
	renderer.SetSourcePos(Vector2(0, 16));
}

void Frog::ResetSprite()
{
	renderer.SetSourcePos(Vector2(0, 0));
}

bool Frog::IsMoving()
{
	return false;
}

void Frog::Update(float dt)
{
	Movement();
	CH->SetPlayerCollider(&collider);
	if (!CH->InBounds(&collider))
	{
		Die();
	}
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
			Die();
			CH->ClearPlayerHits();
			return;
			break;
		case CollisionResult::DROWNED:
			if (OnMovingSuface) break;
			//Respawn || GameOver
			AM->PlaySFX("Dead", 0);
			printf_s("F");
			Die();
			CH->ClearPlayerHits();
			return;
			break;
		case CollisionResult::BORDER:
			//BlockMovement
			break;
		case CollisionResult::BONUS_FLY:
			AM->PlaySFX("GetEnd", 0);
			score += 100;
			if (hasFood) score += 100;
			Respawn();
			CH->ClearPlayerHits();
			return;
			break;
		case CollisionResult::END:
			//Respawn || Win
			AM->PlaySFX("GetEnd", 0);
			if (hasFood) score += 100;
			printf_s("Donee");
			Respawn();
			CH->ClearPlayerHits();
			return;
			break;
		case CollisionResult::FOOD:
			//Add food
			hasFood = true;
			ChangeToHasFoodSprt();
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
