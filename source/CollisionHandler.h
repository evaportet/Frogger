#pragma once
#include "Collider.h"
#include <vector>
#include"RenderManager.h"

#define CH CollisionHandler::GetInstance()

using namespace std;

class CollisionHandler {
private:
	CollisionHandler();
	static CollisionHandler* instance;
	Collider screen;
	Collider* PlayerCollider;
	vector<Collider*> Colliders;
public:
	bool Collides(Collider* A, Collider* B);
	bool PlayerCollision(Collider* other);
	CollisionResult PlayerCollisionType(Collider* other);
	static CollisionHandler* GetInstance();
	CollisionResult Update();
	void SetPlayerCollider(Collider* player);
	void AddCollider(Collider* newElement);
	bool InScreen(Collider* element);
};