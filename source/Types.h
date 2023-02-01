#pragma once

#define FRAMERATE 60/100

enum class ColliderType {
	DMG,
	LOG,
	SNK,
	END,
	FOOD,
	SAVE,
	WINDOW
};

enum class CollisionResult {
	DIE,
	BORDER,
	END,
	FOOD,
	SAFE,
	NONE
};

enum class EndState {
	CROC,
	FLY,
	FULL,
	EMPTY
};

enum class SpawnerType {
	TRUCK,
	RACING0,
	FAMILY,
	FARMING,
	RACING1,
	LOG,
	TURTLES,
	NONE
};

enum CarType
{
	TRUCK,
	RACING0,
	FAMILY,
	FARMING,
	RACING1
};

