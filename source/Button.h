#pragma once
#include "UItext.h"
#include "AudioManager.h"
#include "GameObject.h"
#include "SDL_rect.h"
#include <string>

class Button : public GameObject {
private:
	UIText sampleText;
	SDL_Rect renderRect;
	int width;
	int height;

public:
	Button(int _width, int _height, int x, int y, std::string text);
	Button();
	bool mouseInsideButton;
	bool isClicked;
	bool isPressed;
	virtual void Update(float dt) override;
	virtual void Render() override;
	void CheckIfCollides();
};