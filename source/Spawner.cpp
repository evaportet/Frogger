#include "Spawner.h"

Spawner::Spawner(float spwnRatio, SpawnerType t, Vector2 startPos, Vector2 startSpd) : elapsedTime(0.f)
{
	type = t;
	startPosition = startPos;
	startSpeed = startSpd;
	spawnRatio = spwnRatio;
	variationSpawnCount = 0;

	switch (t)
	{
	case SpawnerType::TRUCK:
		break;
	case SpawnerType::RACING0:
		break;
	case SpawnerType::FAMILY:
		break;
	case SpawnerType::FARMING:
		break;
	case SpawnerType::RACING1: {
		Car* newTile = new Car(1, startPos, Vector2(14, 14), startSpd.x, ColliderType::DMG, "resources/Assets/Cars.png");
		gameObjects.emplace_back(newTile);
	} break;
	case SpawnerType::LOG:
		break;
	case SpawnerType::TURTLES:
		break;
	default:
		break;
	}
}

void Spawner::Update()
{
	elapsedTime += TM->GetDeltaTimeSeconds();

	if (elapsedTime >= spawnRatio)
	{
		//variationSpawnCount++;
		elapsedTime = 0.f;
		switch (type)
		{
		case SpawnerType::TRUCK:
			break;
		case SpawnerType::RACING0:
			break;
		case SpawnerType::FAMILY:
			break;
		case SpawnerType::FARMING:
			break;
		case SpawnerType::RACING1: {
			Car* newTile = new Car(1, startPosition, Vector2(14, 14), startSpeed.x, ColliderType::DMG, "resources/Assets/Cars.png");
			gameObjects.emplace_back(newTile);
		} break;
		case SpawnerType::LOG:
			break;
		case SpawnerType::TURTLES:
			break;
		default:
			break;
		}
	}

	for (int i = 0; i < gameObjects.size(); i++)
	{
		gameObjects[i]->Update();
		if (!CH->InScreen(&(gameObjects[i]->collider)))
		{
			delete gameObjects[i];
			gameObjects.erase(gameObjects.cbegin() + i);
		}
	}
}

void Spawner::Render()
{
	for (int i = 0; i < gameObjects.size(); i++)
	{
		gameObjects[i]->Render();
	}
}
