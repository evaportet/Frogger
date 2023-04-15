#pragma once
#include "Object.h"
#include "ImageRenderer.h"
#include <SDL.h>
#include <string>
#include <SDL_image.h>
class GameObject : public Object
{
protected:
	ImageRenderer renderer;
public:
	GameObject() = default;
	virtual void Update(float dt) = 0;
	virtual void Render() = 0;
	//Renderer* GetRenderer();
};

