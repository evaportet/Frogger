#pragma once
#include "Scene.h"
#include <iostream>
#include "InputManager.h"
#include "SceneManager.h"

class SplashScreenScene : public Scene {
public:
	virtual void Update(float dt) override;
	virtual void Render() override;
	virtual void OnEnter() override;
	virtual void OnExit() override;
};
