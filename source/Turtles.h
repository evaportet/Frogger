#pragma once
#include "GameObject.h"
#include "CollisionHandler.h"

class Turtles : public GameObject {
public:
	Turtles();
	Turtles(int length, Vector2 pos, float spd);
	void Update(float dt) override;
	void Render() override;
};