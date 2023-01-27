#pragma once
#include "ImageRenderer.h"

class AnimatedImageRenderer : public ImageRenderer
{
private:
	int frameWidth;
	int frameHeight;
	int fps;
	bool looping;
	float frameTime;
	float currentFrameTime;
public:
	AnimatedImageRenderer(/*SDL_Color clr, float alph, float rot,*/
		SDL_Rect trgtRect, SDL_Rect srcRect,
		int frmW, int frmH, int FPS, bool loop);
	virtual void Load(std::string path) override;
	virtual void Update() override;
	virtual void Render() override;
};