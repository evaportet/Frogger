#pragma once
#include "Scene.h"
#include "UItext.h"
#include "SDL_ttf.h"
#include "InputManager.h"
#include "SceneManager.h"
#include <cassert>

class MainMenuScene : public Scene {
private:
	UItext sampleText;
	TTF_Font* font;
	float buttonAngle;
	bool exit;
	bool audio;
public:
	MainMenuScene();
	virtual void Update(float dt) override;
	virtual void Render() override;
	virtual void OnEnter() override;
	virtual void OnExit() override;
};