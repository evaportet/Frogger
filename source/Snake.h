#pragma once
#include "GameObject.h"
#include "Log.h"

class Snake : public GameObject {
private:
	Log* log;
public:
	Snake(Log* atachedLog, Vector2 pos, float spd);
	void Update() override;
	void Render() override;
};