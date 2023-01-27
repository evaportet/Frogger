#include "RenderManager.h"

RenderManager* RenderManager::instance = nullptr;

RenderManager::RenderManager()
{
	windowWidth = 272;
	windowHeight = 208;

	int result = SDL_Init(SDL_INIT_VIDEO);

	bool success = result >= 0;
	if (!success)
		throw SDL_GetError();

	result = SDL_CreateWindowAndRenderer(windowWidth, windowHeight, SDL_WINDOW_SHOWN, &window, &renderer);

	success = result >= 0;
	if (!success)
		throw SDL_GetError();
}

RenderManager* RenderManager::GetInstance()
{
	if (instance == nullptr)
		instance = new RenderManager();
	return instance;
}

SDL_Renderer* RenderManager::GetRenderer()
{
	return renderer;
}

void RenderManager::ClearScreen()
{
	SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255);
	SDL_RenderClear(renderer);
}

void RenderManager::RenderScreen()
{
	SM->GetCurrentScene()->Render();
	SDL_RenderPresent(renderer);
}
