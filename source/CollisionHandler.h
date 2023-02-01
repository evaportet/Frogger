#pragma once
#include "Collider.h"
//#include "Frog.h"
#include <vector>
#include"RenderManager.h"
#include <list>

#define CH CollisionHandler::GetInstance()

using namespace std;

class CollisionHandler {
private:
	CollisionHandler();
	static CollisionHandler* instance;
	Collider screen;
	Collider* PlayerCollider;
	vector<Collider*> Colliders;
	list<CollisionResult> playerHits;
public:
	void StorePlayerHits();
	bool Collides(Collider* A, Collider* B);
	bool PlayerCollision(Collider* other);
	void OnPlayerCollision(Collider* other);
	CollisionResult PlayerCollisionType(Collider* other);
	static CollisionHandler* GetInstance();
	CollisionResult Update();
	void SetPlayerCollider(Collider * player);
	void AddCollider(Collider* newElement);
	bool InScreen(Collider* element);
	bool InBounds(Collider* element);
	list<CollisionResult> GetPlayerHits();
	void ClearPlayerHits();
};