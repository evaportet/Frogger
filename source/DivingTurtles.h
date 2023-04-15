#pragma once
#include "Turtles.h"

class DivingTurtles : public Turtles {
private:
	float divingDuration;
	float surfaceDuration;
	float currentDuration;
public:
	DivingTurtles(int length, Vector2 pos, float spd, float srfD, float divD);
	void Update(float dt) override;
	void Render() override;
};