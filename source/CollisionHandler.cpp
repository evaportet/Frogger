#include "CollisionHandler.h"

CollisionHandler* CollisionHandler::instance = nullptr;

CollisionHandler::CollisionHandler()
{
	screen = Collider(Vector2(RM->windowWidth / 2, RM->windowHeight / 2), Vector2(RM->windowWidth, RM->windowHeight), ColliderType::WINDOW);
}

void CollisionHandler::StorePlayerHits()
{
	playerHits.clear();
	for (int i = 0; i < Colliders.size(); i++)
	{
		if (Collides(Colliders[i], PlayerCollider)) {
			switch (Colliders.at(i)->GetType())
			{
			case ColliderType::DMG:
			case ColliderType::SNK:
				playerHits.emplace_back(CollisionResult::DIE);
				break;
			case ColliderType::WATER:
				playerHits.emplace_back(CollisionResult::DROWNED);
				break;
			//case ColliderType::LOG:
			case ColliderType::SAFE:
				playerHits.emplace_back(CollisionResult::SAFE);
				break;
			case ColliderType::PLATFORM:
				playerHits.emplace_back(CollisionResult::ON_PLATFORM);
				break;
			case ColliderType::BONUS_FLY:
				playerHits.emplace_back(CollisionResult::BONUS_FLY);
				break;
			case ColliderType::END:
				playerHits.emplace_back(CollisionResult::END);
				break;
			case ColliderType::FOOD:
				playerHits.emplace_back(CollisionResult::FOOD);
				break;

			default: CollisionResult::NONE; break;
			}
		}		
	}
}

bool CollisionHandler::Collides(Collider* A, Collider* B)
{
	Vector2 ATop = A->GetTopLeft();
	Vector2 ASize = A->GetSize();
	Vector2 BTop = B->GetTopLeft();
	Vector2 BSize = B->GetSize();

	return (ATop.x <= (BTop.x + BSize.x) &&
		ATop.x + ASize.x >= BTop.x &&
		ATop.y <= (BTop.y + BSize.y) &&
		ATop.y + ASize.y >= BTop.y);
}

bool CollisionHandler::PlayerCollision(Collider* other)
{
	return Collides(other, PlayerCollider);
}

void CollisionHandler::OnPlayerCollision(Collider* other)
{
	if (Collides(other, PlayerCollider))
	{
		switch (other->GetType())
		{
		case ColliderType::DMG:
		case ColliderType::SNK:
			playerHits.emplace_back(CollisionResult::DIE);
			break;
		case ColliderType::WATER:
			playerHits.emplace_back(CollisionResult::DROWNED);
			break;
		//case ColliderType::LOG:
		case ColliderType::SAFE:
			playerHits.emplace_back(CollisionResult::SAFE);
			break;
		case ColliderType::PLATFORM:
			playerHits.emplace_back(CollisionResult::ON_PLATFORM);
			break;
		case ColliderType::BONUS_FLY:
			playerHits.emplace_back(CollisionResult::BONUS_FLY);
			break;
		case ColliderType::END:
			playerHits.emplace_back(CollisionResult::END);
			break;
		case ColliderType::FOOD:
			playerHits.emplace_back(CollisionResult::FOOD);
			break;

		default: CollisionResult::NONE; break;
		}
	}
}

CollisionResult CollisionHandler::PlayerCollisionType(Collider* other)
{
	if (Collides(other, PlayerCollider))
	{
		switch (other->GetType())
		{
		case ColliderType::DMG:
		case ColliderType::SNK:
			return CollisionResult::DIE;
			break;
		case ColliderType::WATER:
			 return CollisionResult::DROWNED;
			break;
		case ColliderType::LOG:
		case ColliderType::SAFE:
			return CollisionResult::SAFE;
			break;
		case ColliderType::PLATFORM:
			return CollisionResult::ON_PLATFORM;
			break;
		case ColliderType::BONUS_FLY:
			return CollisionResult::BONUS_FLY;
			break;
		case ColliderType::END:
			return CollisionResult::END;
			break;
		case ColliderType::FOOD:
			return CollisionResult::FOOD;
			break;
		
		default: CollisionResult::NONE; break;
		}
	}
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
		if (Collides(Colliders[i], PlayerCollider)) {
			switch (Colliders.at(i)->GetType())
			{
			case ColliderType::DMG:
			case ColliderType::SNK:
				return CollisionResult::DIE;
				break;
			case ColliderType::WATER:
				return CollisionResult::DROWNED;
				break;
			case ColliderType::LOG:
			case ColliderType::SAFE:
				return CollisionResult::SAFE;
				break;
			case ColliderType::PLATFORM:
				return CollisionResult::ON_PLATFORM;
				break;
			case ColliderType::BONUS_FLY:
				return CollisionResult::BONUS_FLY;
				break;
			case ColliderType::END:
				return CollisionResult::END;
				break;
			case ColliderType::FOOD:
				return CollisionResult::FOOD;
				break;

			default: CollisionResult::NONE; break;
			}
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

bool CollisionHandler::InScreen(Collider* element)
{
	Vector2 screenTop = screen.GetTopLeft();
	Vector2 screenSize = screen.GetSize();
	Vector2 eTop = element->GetTopLeft();
	Vector2 eSize = element->GetSize();

	return (screenTop.x+50 <= (eTop.x + eSize.x) &&
		screenTop.x + screenSize.x-50 >= eTop.x &&
		screenTop.y+50 <= (eTop.y + eSize.y) &&
		screenTop.y + screenSize.y-50 >= eTop.y);
}

bool CollisionHandler::InBounds(Collider* element)
{
	Vector2 screenTop = Vector2(0,0);
	Vector2 screenSize = Vector2(RM->windowWidth, RM->windowHeight);//screen.GetSize();
	Vector2 eTop = element->GetTopLeft();
	Vector2 eSize = element->GetSize();

	return (screenTop.x < eTop.x &&
		screenTop.x + screenSize.x > eTop.x + eSize.x &&

		screenTop.y < eTop.y &&
		screenTop.y + screenSize.y > eSize.y);
}

list<CollisionResult> CollisionHandler::GetPlayerHits()
{
	return playerHits;
}

void CollisionHandler::ClearPlayerHits()
{
	playerHits.clear();
}

void CollisionHandler::StoreAttachedVel(float v)
{
	platformSpeed = v;
}

float CollisionHandler::GetAttachedVel()
{
	return platformSpeed;
}
