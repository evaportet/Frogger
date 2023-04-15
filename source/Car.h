#pragma once
#include "GameObject.h"
#include"CollisionHandler.h"

class Car : public GameObject {
public:
	Car();
	Car(int length, Vector2 rectPos, Vector2 pos, Vector2 size, float spd, ColliderType ct, std::string path);
	void Update(float dt) override;
	void Render() override;
};