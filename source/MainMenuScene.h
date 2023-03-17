#pragma once
#include "Scene.h"
#include "Tile.h"
#include "UItext.h"
#include "Button.h"
#include "SDL_ttf.h"
#include "Renderer.h"
#include "InputManager.h"
#include "ImageRenderer.h"
#include "SceneManager.h"
#include "AudioManager.h"
#include <cassert>

class MainMenuScene : public Scene {
private:

	bool audio;
	UIText sampleText;
	Button playButton;
	Button rankingButton;
	Button audioButton;
	Button exitButton;
	Tile background;

public:

	MainMenuScene();
	virtual void Update(float dt) override;
	virtual void Render() override;
	virtual void OnEnter() override;
	virtual void OnExit() override;
};