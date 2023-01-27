#include "Frog.h"

Frog::Frog()
{
}

Frog::Frog(Vector2 size, Vector2 pos, ColliderType ct, std::string path)
{
	transform.position = pos;
	transform.scale = size;
	transform.rotation = 0;

	collider = Collider(pos, size, ct);

	renderer.Load(path);
	renderer.SetPosition(collider.GetTopLeft());
	renderer.SetScale(transform.scale);
	renderer.SetSourcePos(Vector2(0, 0));

	food = nullptr;
	hasFood = false;
	moves = false;
}

void Frog::Respawn()
{
	//frogTransform.position()
}

void Frog::Movement()
{
	Vector2 newMovement;

	if (IM->CheckKeyState(SDLK_UP, DOWN))
	{
		newMovement = Vector2(transform.position.x, transform.position.y - 5);
		SetPosition(newMovement);
		renderer.SetPosition(newMovement);
	}

	if (IM->CheckKeyState(SDLK_DOWN, DOWN))
	{
		newMovement = Vector2(transform.position.x, transform.position.y + 5);
		SetPosition(newMovement);
		renderer.SetPosition(newMovement);
		//sprite rotation 180
	}

	if (IM->CheckKeyState(SDLK_LEFT, DOWN))
	{
		newMovement = Vector2(transform.position.x - 5, transform.position.y );
		SetPosition(newMovement);
		renderer.SetPosition(newMovement);
		//sprite rotation 270
	}

	if (IM->CheckKeyState(SDLK_RIGHT, DOWN))
	{
		newMovement = Vector2(transform.position.x + 5, transform.position.y);
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
}

void Frog::Render()
{
	renderer.Render();
}

void Frog::AddFood(Food* food)
{
}
