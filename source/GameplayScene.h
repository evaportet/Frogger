#pragma once
#include "Scene.h"
#include "InputManager.h"
#include "SceneManager.h"
#include "GameObject.h"
#include "Frog.h"
#include "Tile.h"
#include "EndTile.h"
#include "Spawner.h"
#include <cassert>
#include <vector>

class GameplayScene : public Scene {
private:
	std::vector<GameObject> gameObjects;
	std::vector<Spawner> spawners;
	Tile map;
	EndTile endPositions[5];
	Frog player;
	int level;
	int score;
	
public:
	GameplayScene();
	virtual void Update(float dt) override;
	virtual void Render() override;
	virtual void OnEnter() override;
	virtual void OnExit() override;
};
