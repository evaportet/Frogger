#pragma once
#include "GameObject.h"
#include "Tile.h"
#include "Car.h"
#include "Turtles.h"
#include "Log.h"
#include "Food.h"
#include"Vector2.h"
#include"Types.h"
#include"TimeManager.h"
#include <vector>

class Spawner {
private:
	int variationSpawnCount;
	float elapsedTime;
	static float foodCooldown;
	float spawnRatio;
	SpawnerType type;
	Vector2 startPosition;
	Vector2 startSpeed;
	std::vector<GameObject*> gameObjects;
	static bool foodSpawned;
public:
	Spawner(float spwnRatio, SpawnerType t, Vector2 startPos, Vector2 startSpd);
	void Update(float dt);
	void Render();
};