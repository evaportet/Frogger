#pragma once

#define FRAMERATE 60/100

enum class ColliderType {
	DMG,
	LOG,
	SNK,
	END,
	FOOD,
	SAVE
};

enum class CollisionResult {
	DIE,
	BORDER,
	END,
	FOOD,
	SAFE
};

enum class EndState {
	CROC,
	FLY,
	FULL,
	EMPTY
};

enum class SpawnerType {
	CAR1,
	CAR2,
	CAR3,
	LOG1,
	LOG2,
	LOG3
};