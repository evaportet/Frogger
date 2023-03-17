#pragma once
#include <string>
#include "SDL_ttf.h"
#include "Renderer.h"

class UIText : public Renderer {
private:
	TTF_Font* font;
	std::string text;

public:
	UIText(int _width, int _height, int x, int y/*, std::string text*/);
	UIText();

	void Update()override;
	void Render()override;

	void Load(std::string path);
	void SetText(std::string _text);

};