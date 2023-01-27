#pragma once
#include <SDL.h>
#include <vector>
#include "SceneManager.h"

#define RM RenderManager::GetInstance()

class RenderManager {
private:
	static RenderManager* instance;
	SDL_Window* window;
	SDL_Renderer* renderer;
	RenderManager(int width, int height, int flags);
public:
	RenderManager();
	float windowWidth;
	float windowHeight;
	static RenderManager* GetInstance();
	SDL_Renderer* GetRenderer();
	void ClearScreen();
	void RenderScreen();

	
};