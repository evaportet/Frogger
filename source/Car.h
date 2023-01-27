#pragma once
#include "GameObject.h"

class Car : public GameObject {
public:
	Car();
	Car(int length, Vector2 pos, float spd);
	void Update() override;
	void Render() override;
};