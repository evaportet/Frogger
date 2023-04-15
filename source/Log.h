#pragma once
#include "GameObject.h"
#include"CollisionHandler.h"

class Log : public GameObject
{
public:
	Log();
	Log(int length, Vector2 pos, float spd);
	void Update(float dt) override;
	void Render() override;
	//bool CheckIfInBoundaries() override;
	//Vector2 spawnPos;
};