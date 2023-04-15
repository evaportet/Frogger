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
#include "UItext.h"
#include "Button.h"
#include <cassert>
#include <vector>
#include "HighScoreManager.h"

class GameplayScene : public Scene {
private:
	std::vector<Tile*> row_tiles;
	std::vector<Spawner*> spawners;
	Tile map;
	EndTile endPositions[5];
	Frog player;
	Collider water;
	int level;
	float levelTime;
	UIText scoreText;

	ImageRenderer timeRect;
	Vector2 timeSizeAux;
	float time_StartXSize;
	bool isPaused;

	//Pause menu
	ImageRenderer pauseBckGrnd;
	Button retryButton;
	Button exitButton;
	UIText gameOverTxt;
	//

	void ResetScene();
	
public:
	GameplayScene();
	virtual void Update(float dt) override;
	virtual void Render() override;
	virtual void OnEnter() override;
	virtual void OnExit() override;
};
