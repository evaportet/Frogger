#pragma once
#include "GameObject.h"

class Turtles : public GameObject {
public:
	Turtles();
	Turtles(int length, Vector2 pos, float spd);
	void Update() override;
	void Render() override;
};