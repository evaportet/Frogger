#pragma once
#include "Scene.h"
#include <iostream>
#include "InputManager.h"
#include "Types.h"
#include "SceneManager.h"
#include "ImageRenderer.h"
#include "TimeManager.h"
#include "Tile.h"

class SplashScreenScene : public Scene {
private:
	float startTime;
	std::vector<ImageRenderer*> title;
	Tile frogger;

public:
	virtual void Update(float dt) override;
	virtual void Render() override;
	virtual void OnEnter() override;
	virtual void OnExit() override;
};
