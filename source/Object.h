#pragma once
#include "Collider.h"
#include "Transform.h"
#include <fstream>
#include "Types.h"

class Object {
public:
	Collider collider;
	Transform transform;
	float speed;
	Object() = default;
	virtual void Render() = 0;
	virtual void Update(float dt) = 0;
	Transform GetTransform();
	Collider GetCollider();
	float GetSpeed();
	void SetTransform(Transform newTransform);
	void SetSpeed(float newSpeed);
	void SetPosition(Vector2 newPos);
	void SetRotation(float newRotation);
	void SetScale(Vector2 newScale);
};
