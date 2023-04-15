#include "Renderer.h"

Renderer::Renderer()
{

}

Renderer::Renderer(/*SDL_Color clr, float alph, float rot,*/ SDL_Rect trgtRect, SDL_Rect srcRect, Vector2 scl)
{
	/*color = clr;
	alpha = alph;
	rotation = rot;*/
	targetRect = trgtRect;
	sourceRect = srcRect;
	scale = scl;
}

//void Renderer::SetColor(SDL_Color clr)
//{
//	color = clr;
//}
//
//void Renderer::SetAlpha(float alph)
//{
//	alpha = alph;
//}

SDL_Texture* Renderer::GetTexture()
{
	return texture;
}

void Renderer::SetSourcePos(Vector2 newPos)
{
	sourceRect.x = newPos.x;
	sourceRect.y = newPos.y;
}

void Renderer::OverrideSourcePixelScale(Vector2 scale)
{
	sourceRect.w *= scale.x;
	sourceRect.h *= scale.y;
}

void Renderer::OverrideTargetPixelSize(Vector2 scale)
{
	targetRect.w = sourceRect.w * scale.x;
	targetRect.h = sourceRect.h * scale.y;
}

void Renderer::SetPosition(Vector2 newPos)
{
	targetRect.x = newPos.x - targetRect.w/2.f;
	targetRect.y = newPos.y - targetRect.h/2.f;
}

void Renderer::SetRotation(float rot)
{
	rotation = rot;
}

void Renderer::SetScale(Vector2 scl)
{
	targetRect.w = scl.x;
	targetRect.h = scl.y;
	sourceRect.w = scl.x;
	sourceRect.h = scl.y;
}

Vector2 Renderer::GetTexturePixelSize()
{
	return Vector2(targetRect.w, targetRect.h);
}

void Renderer::SetTexturePixelSize(Vector2 newPixelSize)
{
	targetRect.w = newPixelSize.x;
	targetRect.h = newPixelSize.y;
}

//SDL_Color Renderer::GetColor()
//{
//	return color;
//}

//float Renderer::GetAlpha()
//{
//	return alpha;
//}
