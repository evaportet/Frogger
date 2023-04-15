#pragma once
#include "GameObject.h"
#include"CollisionHandler.h"

class Tile : public GameObject {
public:
	Tile();
	Tile(Vector2 size, Vector2 pos, ColliderType ct, std::string path);
	void Update(float dt) override;
	void Render() override;
};