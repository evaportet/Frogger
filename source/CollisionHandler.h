#pragma once
#include "Collider.h"
#include <vector>

#define CH CollisionHandler::GetInstance();

using namespace std;

class CollisionHandler {
private:
	CollisionHandler();
	static CollisionHandler* instance;
	Collider* PlayerCollider;
	vector<Collider*> Colliders;
	bool Collides(Collider* A, Collider* B);
public:
	static CollisionHandler* GetInstance();
	CollisionResult Update();
	void SetPlayerCollider(Collider* player);
	void AddCollider(Collider* newElement);
};