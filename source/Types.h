#pragma once

#define FRAMERATE 60/100

enum class ColliderType {
	DMG,
	LOG,
	SNK,
	END,
	FOOD,
	SAFE,
	PLATFORM,
	WATER,
	BONUS_FLY,
	WINDOW
};

enum class CollisionResult {
	DIE,
	BORDER,
	END,
	FOOD,
	BONUS_FLY,
	SAFE,
	ON_PLATFORM,
	DROWNED,
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
	FOOD,
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

