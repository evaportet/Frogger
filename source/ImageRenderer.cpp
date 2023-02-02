#include "ImageRenderer.h"

ImageRenderer::ImageRenderer()
{
	targetRect = { 0,0,0,0 };
	sourceRect = { 0,0,0,0 };
	scale = Vector2();
}

ImageRenderer::ImageRenderer(/*SDL_Color clr, float alph, float rot,*/ SDL_Rect trgtRect, SDL_Rect srcRect, Vector2 scl)
{
	//color = clr;
	//alpha = alph;
	//rotation = rot;
	targetRect = trgtRect;
	sourceRect = srcRect;
	scale = scl;
}

void ImageRenderer::Load(std::string path)
{
	SDL_Surface* surface = IMG_Load(path.c_str());
	assert(surface);

	texture = SDL_CreateTextureFromSurface(RM->GetRenderer(), surface);
	assert(texture);
	
	SDL_QueryTexture(texture, nullptr, nullptr, &sourceRect.w, &sourceRect.h);

	SDL_FreeSurface(surface);
}

void ImageRenderer::Update()
{
	
}

void ImageRenderer::Render()
{
	//TODO RC_Ex
	//SDL_RenderCopy(RM->GetRenderer(), texture, &sourceRect, &targetRect);
	SDL_RenderCopyEx(RM->GetRenderer(), texture, &sourceRect, &targetRect, rotation,
		NULL, SDL_FLIP_NONE);
}
