#include "Spawner.h"

Spawner::Spawner(float spwnRatio, SpawnerType t, Vector2 startPos, Vector2 startSpd)
{
	type = t;
	startPosition = startPos;
	startSpeed = startSpd;
	spawnRatio = spwnRatio;
	variationSpawnCount = 0;
}

void Spawner::Update()
{
	if (elapsedTime >= spawnRatio)
	{
		variationSpawnCount++;
	}

	for (int i = 0; i < gameObjects.size(); i++)
	{
		gameObjects[i].Update();
	}
}
