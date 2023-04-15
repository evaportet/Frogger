#include "UIText.h"

UIText::UIText(int _width, int _height, int x, int y, std::string text, SDL_Color color)
{
	TTF_Init();
	scale = Vector2(_width, _height);
	targetRect = SDL_Rect
	{
		x,
		y,
		(int)(scale.x * text.length() * 20),
		(int)(scale.y * 20)
	};
	SetRotation(0);
	this->color = color;
	sourceRect = targetRect;
	this->text=text;
}

UIText::UIText()
{
}

void UIText::Load(std::string path)
{
	font = TTF_OpenFont(path.c_str(), 20);

	//color
	//SDL_Color color = { 0, 0, 0, 255 };

	//surface
	SDL_Surface* surface = TTF_RenderText_Solid(font, text.c_str(), color);
	assert(surface != nullptr);

	/*if (texture != nullptr)
	{
		SDL_DestroyTexture(texture);
	}*/

	texture = SDL_CreateTextureFromSurface(RM->GetRenderer(), surface);
	assert(texture != nullptr);

	SDL_SetTextureAlphaMod(texture, 255); //alpha = transparencia, 255 -> opaque, 0 -> transparent

	targetRect = SDL_Rect
	{
		targetRect.x,
		targetRect.y,
		(int)(scale.x * text.length()),
		(int)(scale.y)
	};

	SDL_FreeSurface(surface);
}

void UIText::Update()
{
	
}

void UIText::Render()
{
	SDL_RenderCopyEx(RM->GetRenderer(), texture, nullptr, &targetRect, rotation, nullptr, SDL_FLIP_NONE);
}

void UIText::SetText(std::string _text)
{
	text = _text;

	//color
	//SDL_Color color = { 0, 0, 0 };

	//SDL_Surface* surface = TTF_RenderText_Solid(font, text.c_str(), color);
	//assert(surface != nullptr);

	///*if (texture != nullptr)
	//{
	//	SDL_DestroyTexture(texture);
	//}*/

	//texture = SDL_CreateTextureFromSurface(RM->GetRenderer(), surface);
	//assert(texture != nullptr);

	//SDL_SetTextureAlphaMod(texture, 255); //alpha = transparencia, 255 -> opaque, 0 -> transparent

	//targetRect = SDL_Rect
	//{
	//	targetRect.x,
	//	targetRect.y,
	//	(int)(scale.x * text.length()),
	//	(int)(scale.y)
	//};

	//SDL_FreeSurface(surface);
}

