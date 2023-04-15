#pragma once
#include "GameObject.h"
#include "AudioManager.h"
#include "Food.h"
#include "Vector2.h"
#include "InputManager.h"
#include "CollisionHandler.h"
//#include "AnimatedImageRenderer.h"
#include <vector>

class Frog : public GameObject
{
private:
	Vector2 spawnPos;
	int lastTopY;
	bool moves;
	bool OnMovingSuface;
	bool hasFood;
	int lives;
	int score;
	//Food* food;
	float movingPlatf_speed;

	void Movement();
	void ChangeToHasFoodSprt();
	void ResetSprite();

public:
	Frog();
	Frog(Vector2 size, Vector2 pos, ColliderType ct, std::string path);

	void SetScore(int newS);
	int GetScore();
	int GetLives();

	void Respawn();
	void Die();
	bool IsMoving();
	void Update(float dt)override; 
	void Render()override; 
	void AddFood(Food* food); 
	void HandleHits(std::list<CollisionResult> hits);
};

