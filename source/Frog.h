#pragma once
#include "GameObject.h"
#include "Food.h"
#include "Vector2.h"
#include "InputManager.h"
//#include "AnimatedImageRenderer.h"
#include <vector>

class Frog : public GameObject
{
private:
	bool moves;
	bool hasFood;
	Food* food;
	void Movement();

public:
	Frog();
	Frog(Vector2 size, Vector2 pos, ColliderType ct, std::string path);
	void Respawn();
	bool IsMoving();
	void Update()override; 
	void Render()override; 
	void AddFood(Food* food); 
};

