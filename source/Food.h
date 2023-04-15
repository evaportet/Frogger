#pragma once
#include "GameObject.h"
#include "Log.h"

class Food : public GameObject {
private:
	Log* log;
	bool isPicked;

public:
	Food(Log* atachedLog, Vector2 pos, float spd);
	void Update(float dt) override;
	void Render() override;
	bool IsPicked();
};