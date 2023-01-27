#include "EndTile.h"

EndTile::EndTile()
{

}

EndTile::EndTile(Vector2 pos)
{
	startEndTile = clock();

	state = EndState::EMPTY;
	duration = 5;
	currentDuration = 0;

	transform.position = pos;
	transform.scale = Vector2(16, 16);
	transform.rotation = 0;

	collider = Collider(pos, transform.scale, ColliderType::END);

	renderer.Load("resources/Assets/EndTiles.png");
	renderer.SetPosition(collider.GetTopLeft());
	renderer.SetScale(transform.scale);
	renderer.SetSourcePos(Vector2(100,0));
}

void EndTile::Update()
{
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
		renderer.SetSourcePos(Vector2(0, 16));
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
