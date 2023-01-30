#pragma once
#include <SDL.h>
#include <vector>
#include "SceneManager.h"
#include "InputManager.h"

#define RM RenderManager::GetInstance()

class RenderManager {
private:
	static RenderManager* instance;
	SDL_Window* window;
	SDL_Renderer* renderer;
	RenderManager(int width, int height, int flags);
public:
	RenderManager();
	int windowWidth;
	int windowHeight;
	static RenderManager* GetInstance();
	SDL_Renderer* GetRenderer();
	void ClearScreen();
	void RenderScreen();
};