#pragma once
#include <ios>
#include <iostream>
#include <sstream>
#include "../dep/inc/xml/rapidxml.hpp"
#include "../dep/inc/xml/rapidxml_iterators.hpp"
#include "../dep/inc/xml/rapidxml_print.hpp"
#include "../dep/inc/xml/rapidxml_utils.hpp"
#include "Spawner.h"
#include "Tile.h"
#include "Types.h"
#include "RenderManager.h"
#include <vector>
#include <cstdlib>


class LevelLoader {
public:
	LevelLoader() = default;
	//static std::vector<Spawner*> LoadLevel(std::string path);
	static bool LoadLevel(std::string path, std::vector<Spawner*>& spawners, std::vector<Tile*>& tiles, float& levelTime);
};