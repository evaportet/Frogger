#pragma once
#include"Scene.h"

class Ranking : public Scene
{
private:
	void LoadScores();
public:
	Ranking() = default;

	void Update(float dt)override;;
	void Render(SDL_Renderer*)override;;
	void OnEnter() override;
	void OnExit() override;;

};
