#pragma once
#include "GameObject.h"
#include "CollisionHandler.h"

class EndTile : public GameObject{
private:
	clock_t startEndTile;
	float duration;
	float currentDuration;
	EndState state;
	bool enabled;
public:
	EndTile();
	EndTile(Vector2 pos);
	void Update(float dt) override;
	void Render() override;
	EndState GetState();
};