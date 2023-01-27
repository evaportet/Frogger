#pragma once
#include "GameObject.h"

class Tile : public GameObject {
public:
	Tile();
	Tile(Vector2 size, Vector2 pos, ColliderType ct, std::string path);
	void Update() override;
	void Render() override;
};