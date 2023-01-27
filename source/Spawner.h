#pragma once
#include "GameObject.h"
#include <vector>

class Spawner {
private:
	int variationSpawnCount;
	float elapsedTime;
	float spawnRatio;
	SpawnerType type;
	Vector2 startPosition;
	Vector2 startSpeed;
	std::vector<GameObject> gameObjects;
public:
	Spawner(float spwnRatio, SpawnerType t, Vector2 startPos, Vector2 startSpd);
	void Update();
};