#pragma once
#include "GameObject.h"
#include "Log.h"

class Food : public GameObject {
private:
	Log* log;
public:
	Food(Log* atachedLog, Vector2 pos, float spd);
	void Update() override;
	void Render() override;
};