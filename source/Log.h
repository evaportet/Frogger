#pragma once
#include "GameObject.h"

class Log : public GameObject {
public:
	Log();
	Log(int length, Vector2 pos, float spd);
	void Update() override;
	void Render() override;
};