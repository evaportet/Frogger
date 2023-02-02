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
	case SpawnerType::TRUCK: {
		Car* newTile = new Car(1, Vector2(33, 0), startPos, Vector2(31, 16), startSpd.x, ColliderType::DMG, "resources/Assets/Cars.png");
		gameObjects.emplace_back(newTile);
	}break;
	case SpawnerType::RACING0: {
		Car* newTile = new Car(1, Vector2(80, 0), startPos, Vector2(16, 16), startSpd.x, ColliderType::DMG, "resources/Assets/Cars.png");
		gameObjects.emplace_back(newTile);
	}break;
	case SpawnerType::FAMILY: {
		Car* newTile = new Car(1, Vector2(64, 0), startPos, Vector2(16, 16), startSpd.x, ColliderType::DMG, "resources/Assets/Cars.png");
		gameObjects.emplace_back(newTile);
	}break;
	case SpawnerType::FARMING: {
		Car* newTile = new Car(1, Vector2(16, 0), startPos, Vector2(16, 16), startSpd.x, ColliderType::DMG, "resources/Assets/Cars.png");
		gameObjects.emplace_back(newTile);
	}break;
	case SpawnerType::RACING1: {
		Car* newTile = new Car(1, Vector2(0,0), startPos, Vector2(16, 16), startSpd.x, ColliderType::DMG, "resources/Assets/Cars.png");
		gameObjects.emplace_back(newTile);
	} break;
	case SpawnerType::LOG: {
		Log* newTile = new Log(1, startPos, startSpd.x);
		gameObjects.emplace_back(newTile);
	}break;
	case SpawnerType::TURTLES: {
		Turtles* newTile = new Turtles(1, startPos, startSpd.x);
		Turtles* newTile2 = new Turtles(1, startPos+Vector2(40, 0), startSpd.x);
		Turtles* newTile3 = new Turtles(1, startPos+Vector2(80, 0), startSpd.x);
		gameObjects.emplace_back(newTile);
		gameObjects.emplace_back(newTile2);
		gameObjects.emplace_back(newTile3);
	}break;
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
		case SpawnerType::TRUCK: {
			Car* newTile = new Car(1, Vector2(35, 0), startPosition, Vector2(27, 16), startSpeed.x, ColliderType::DMG, "resources/Assets/Cars.png");
			gameObjects.emplace_back(newTile);
		}break;
		case SpawnerType::RACING0: {
			Car* newTile = new Car(1, Vector2(80, 0), startPosition, Vector2(16, 16), startSpeed.x, ColliderType::DMG, "resources/Assets/Cars.png");
			gameObjects.emplace_back(newTile);
		}break;
		case SpawnerType::FAMILY: {
			Car* newTile = new Car(1, Vector2(65, 0), startPosition, Vector2(15, 16), startSpeed.x, ColliderType::DMG, "resources/Assets/Cars.png");
			gameObjects.emplace_back(newTile);
		}break;
		case SpawnerType::FARMING: {
			Car* newTile = new Car(1, Vector2(17, 0), startPosition, Vector2(14, 16), startSpeed.x, ColliderType::DMG, "resources/Assets/Cars.png");
			gameObjects.emplace_back(newTile);
		}break;
		case SpawnerType::RACING1: {
			Car* newTile = new Car(1, Vector2(0, 0), startPosition, Vector2(16, 16), startSpeed.x, ColliderType::DMG, "resources/Assets/Cars.png");
			gameObjects.emplace_back(newTile);
		}	break;
		case SpawnerType::LOG: {
			Log* newTile = new Log(1, startPosition, startSpeed.x);
			gameObjects.emplace_back(newTile);
		}break;
		case SpawnerType::TURTLES: {
			Turtles* newTile = new Turtles(1, startPosition, startSpeed.x);
			Turtles* newTile2 = new Turtles(1, startPosition + Vector2(40, 0), startSpeed.x);
			Turtles* newTile3 = new Turtles(1, startPosition + Vector2(80, 0), startSpeed.x);
			gameObjects.emplace_back(newTile);
			gameObjects.emplace_back(newTile2);
			gameObjects.emplace_back(newTile3);
		}break;
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
