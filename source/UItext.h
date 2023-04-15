#pragma once
#include <string>
#include "SDL_ttf.h"
#include "Renderer.h"

class UIText : public Renderer {
private:
	TTF_Font* font;
	std::string text;
	//std::string fontPath;
	SDL_Color color;

public:
	UIText(int _width, int _height, int x, int y, std::string text = "", SDL_Color color = {0,0,0});
	UIText();

	void Update()override;
	void Render()override;

	void Load(std::string path);
	void SetText(std::string _text);

};