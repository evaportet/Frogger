#include "AnimatedImageRenderer.h"

AnimatedImageRenderer::AnimatedImageRenderer(/*SDL_Color clr, float alph, float rot,*/ SDL_Rect trgtRect, SDL_Rect srcRect, int frmW, int frmH, int FPS, bool loop)
{
	/*color = clr;
	alpha = alph;
	rotation = rot;*/
	targetRect = trgtRect;
	sourceRect = srcRect;
	frameWidth = frmW;
	frameHeight = frmH;
	fps = FPS;
	looping = loop;
}

void AnimatedImageRenderer::Load(std::string path)
{
	SDL_Surface* surface = IMG_Load(path.c_str());
	assert(surface);

	texture = SDL_CreateTextureFromSurface(RM->GetRenderer(), surface);
	assert(texture);

	SDL_FreeSurface(surface);
}

void AnimatedImageRenderer::Update()
{
	targetRect.w = scale.x;
	targetRect.h = scale.y;
}

void AnimatedImageRenderer::Render()
{
	SDL_RenderCopy(RM->GetRenderer(), texture, &sourceRect, &targetRect);
}
