#pragma once
#include "Vector2.h"
#include <string>
#include <SDL_image.h>
#include <assert.h>
#include "RenderManager.h"

class Renderer {
protected:
	SDL_Texture* texture;
	//SDL_Renderer* renderer;
	//SDL_Color color;
	//float alpha;
	float rotation;
	Vector2 scale;
	SDL_Rect targetRect;
	SDL_Rect sourceRect;
public:
	Renderer();
	Renderer(/*SDL_Color clr, float alph, float rot,*/
		SDL_Rect trgtRect, SDL_Rect srcRect, Vector2 scl);
	virtual void Load(std::string path) = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;
	SDL_Texture* GetTexture();
	void SetSourcePos(Vector2 newPos);
	void OverrideSourcePixelScale(Vector2 scale);
	void OverrideTargetPixelSize(Vector2 scale);
	//void SetColor(SDL_Color clr);
	//void SetAlpha(float alph);
	void SetPosition(Vector2 newPos);
	void SetRotation(float rot);
	void SetScale(Vector2 scl);
	//SDL_Color GetColor();
	/*float GetAlpha();*/
	Vector2 GetTexturePixelSize();

};