#pragma once
#include "GameObject.h"

class EndTile : public GameObject{
private:
	clock_t startEndTile;
	float duration;
	float currentDuration;
	EndState state;
public:
	EndTile();
	EndTile(Vector2 pos);
	void Update() override;
	void Render() override;
	EndState GetState();
};