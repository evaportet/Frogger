#include "CollisionHandler.h"

CollisionHandler* CollisionHandler::instance = nullptr;

CollisionHandler::CollisionHandler()
{
}
bool CollisionHandler::Collides(Collider* A, Collider* B)
{
	Vector2 ATop = A->GetTopLeft();
	Vector2 ASize = A->GetSize();
	Vector2 BTop = B->GetTopLeft();
	Vector2 BSize = B->GetSize();

	if (ATop.x <= (BTop.x + BSize.x) && 
		ATop.x + ASize.x >= BTop.x &&
		ATop.y <= (BTop.y + BSize.y) &&
		ATop.y + ASize.y >= BTop.y)
		return true;
	else
		return false;
}

CollisionHandler* CollisionHandler::GetInstance()
{
	if (instance == nullptr)
		instance = new CollisionHandler();
	return instance;
}

CollisionResult CollisionHandler::Update()
{
	for (int i = 0; i < Colliders.size(); i++)
	{
		if (Colliders[i]->GetType() == ColliderType::SNK)
		{
			if(Collides(Colliders[i], PlayerCollider))
				return CollisionResult::DIE;
		}
		else if (Colliders[i]->GetType() == ColliderType::FOOD)
		{
			if (Collides(Colliders[i], PlayerCollider))
				return CollisionResult::FOOD;
		}
		else if (Colliders[i]->GetType() == ColliderType::LOG)
		{
			if (Collides(Colliders[i], PlayerCollider))
				return CollisionResult::SAFE;
		}
		else if (Colliders[i]->GetType() == ColliderType::DMG)
		{
			if (Collides(Colliders[i], PlayerCollider))
				return CollisionResult::DIE;
		}
		else if (Colliders[i]->GetType() == ColliderType::END)
		{
			if (Collides(Colliders[i], PlayerCollider))
				return CollisionResult::END;
		}
	}
}

void CollisionHandler::SetPlayerCollider(Collider* player)
{
	PlayerCollider = player;
}

void CollisionHandler::AddCollider(Collider* newElement)
{
	Colliders.push_back(newElement);
}
