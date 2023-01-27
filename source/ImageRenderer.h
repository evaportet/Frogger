#pragma once
#include "Renderer.h"

class ImageRenderer : public Renderer
{
public:
	ImageRenderer();
	ImageRenderer(/*SDL_Color clr, float alph, float rot,*/
		SDL_Rect trgtRect, SDL_Rect srcRect, Vector2 scl);
	virtual void Load(std::string path) override;
	virtual void Update() override;
	virtual void Render() override;
};