#include "EndTile.h"

EndTile::EndTile()
{

}

EndTile::EndTile(Vector2 pos) : enabled(true)
{
	startEndTile = clock();

	state = EndState::EMPTY;
	duration = 5;
	currentDuration = 0;

	transform.position = pos;
	transform.scale = Vector2(16, 16);
	transform.rotation = 0;

	collider = Collider(pos, Vector2(transform.scale.x * 2.5f, transform.scale.y * 4.f), ColliderType::END);

	renderer.Load("resources/Assets/EndTiles.png");
	renderer.SetPosition(pos);
	renderer.SetScale(transform.scale);
	renderer.SetSourcePos(Vector2(100,0));
	renderer.OverrideTargetPixelSize(Vector2(3, 3));
	renderer.SetRotation(transform.rotation);
}

void EndTile::Update(float dt)
{
	if (!enabled) return;

	currentDuration = (clock() - startEndTile) / CLOCKS_PER_SEC;

	if (currentDuration >= duration && state != EndState::FULL)
	{
		int spawnChance = rand() % 100;

		if (spawnChance <= 10)
		{
			state = EndState::CROC;
			collider.SetType(ColliderType::DMG);
			renderer.SetSourcePos(Vector2(64,0));
		}
		else if (spawnChance <= 30)
		{
			state = EndState::FLY;
			collider.SetType(ColliderType::END);
			renderer.SetSourcePos(Vector2(0, 0));
		}
		else
		{
			state = EndState::EMPTY;
			collider.SetType(ColliderType::END);
			renderer.SetSourcePos(Vector2(0, 80));
		}

		startEndTile = clock();
	}

	if (state == EndState::FULL)
	{
		collider.SetType(ColliderType::DMG);
		renderer.SetSourcePos(Vector2(16, 0));
	}

	CH->OnPlayerCollision(&collider);
	if (CH->PlayerCollision(&collider))
	{
		switch (state)
		{
		case EndState::FULL:
		case EndState::CROC:

			break;
		case EndState::EMPTY:
		case EndState::FLY:
			state = EndState::FULL;
			collider.SetType(ColliderType::DMG);
			renderer.SetSourcePos(Vector2(16, 0));
			enabled = false;
			break;
		default:
			break;
		}
	}
}

void EndTile::Render()
{
	renderer.Render();
}

EndState EndTile::GetState()
{
	return state;
}
