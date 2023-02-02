#pragma once
#include "Scene.h"
#include "RenderManager.h"
#include "InputManager.h"
#include "SceneManager.h"
#include "GameObject.h"
#include "LevelLoader.h"
#include "CollisionHandler.h"
#include "Frog.h"
#include "Tile.h"
#include "EndTile.h"
#include "Spawner.h"
#include <cassert>
#include <vector>

class GameplayScene : public Scene {
private:
	std::vector<Tile*> row_tiles;
	std::vector<Spawner*> spawners;
	Tile map;
	EndTile endPositions[5];
	Frog player;
	Collider water;
	int level;
	float time;
	int score;
	
public:
	GameplayScene();
	virtual void Update(float dt) override;
	virtual void Render() override;
	virtual void OnEnter() override;
	virtual void OnExit() override;
};
