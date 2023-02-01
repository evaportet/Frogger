#pragma once
#include <ios>
#include <iostream>
#include <sstream>
#include "../dep/inc/xml/rapidxml.hpp"
#include "../dep/inc/xml/rapidxml_iterators.hpp"
#include "../dep/inc/xml/rapidxml_print.hpp"
#include "../dep/inc/xml/rapidxml_utils.hpp"
#include "Spawner.h"
#include <vector>
#include <cstdlib>
#include "Spawner.h"


class LevelLoader {
public:
	LevelLoader();
	std::vector<Spawner*> LoadLevel(std::string path);
};