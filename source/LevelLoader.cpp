#include "LevelLoader.h"

bool LevelLoader::LoadLevel(std::string path, std::vector<Spawner*>& spawns, std::vector<Tile*>& tiles)
{
	rapidxml::xml_document<> doc;
	std::ifstream file("resources/Files/sample_level.xml");
	std::stringstream buffer;
	buffer << file.rdbuf();
	file.close();
	std::string content(buffer.str());
	doc.parse<0>(&content[0]);

	std::vector<Spawner*> level;

	rapidxml::xml_node<>* pRoot = doc.first_node();
	rapidxml::xml_node<>* pNode = pRoot->first_node();

	float time = std::stof(pNode->value());

	pNode = pNode->next_sibling(); //Layout
	pNode = pNode->first_node();

	for (; pNode; pNode = pNode->next_sibling())
	{
		//NODE
		if (strcmp(pNode->name(), "EndZone") == 0)
		{
			float hazardChance;

			hazardChance = std::stof(pNode->first_attribute("hazardChance")->value());

			//End tiles


		}
		else if (strcmp(pNode->name(), "LogRiver") == 0)
		{
			int minLength=0;
			int maxLength=0;
			int min=0;
			int max=0;
			int cocodrChance=0;
			int snakeChance=0;

			minLength = std::stoi(pNode->first_attribute("minLength")->value());
			maxLength = std::stoi(pNode->first_attribute("maxLength")->value());

			for (rapidxml::xml_node<>* pSubNode = pNode->first_node(); pSubNode; pSubNode = pSubNode->next_sibling())
			{
				if (strcmp(pSubNode->name(), "SpawnRate") == 0)
				{
					min = std::stoi(pSubNode->first_attribute("min")->value());
					max = std::stoi(pSubNode->first_attribute("max")->value());
				}
				else if (strcmp(pSubNode->name(), "CrocodileChance") == 0)
				{
					cocodrChance = std::stoi(pSubNode->value());
				}
				else if (strcmp(pSubNode->name(), "SnakeChance") == 0)
				{
					snakeChance = std::stoi(pSubNode->value());
					
				}

			}
			//Set crocodile Spawner
			
			//Set snake Spawner

			//Set river Tiles

		}
		else if (strcmp(pNode->name(), "TurtlesRiver") == 0)
		{
			int minLength=0;
			int maxLength=0;
			int min=1;
			int max=0;
			float diveChance=0;

			minLength = std::stoi(pNode->first_attribute("minLength")->value());
			maxLength = std::stoi(pNode->first_attribute("maxLength")->value());

			for (rapidxml::xml_node<>* pSubNode = pNode->first_node(); pSubNode; pSubNode = pSubNode->next_sibling())
			{
				if (strcmp(pSubNode->name(), "SpawnRate") == 0)
				{
					min = std::stoi(pSubNode->first_attribute("min")->value());
					max = std::stoi(pSubNode->first_attribute("max")->value());
				}
				else if (strcmp(pSubNode->name(), "DiveChance") == 0)
				{
					diveChance = std::stof(pSubNode->value());
				}
			}
			//set turtles spawner

			//set river tiles
		}
		else if (strcmp(pNode->name(), "SafeZone") == 0)
		{
			//set save tiles

		}
		else if (strcmp(pNode->name(), "Road") == 0)
		{
			SpawnerType type = SpawnerType::NONE;
			if(strcmp(pNode->first_attribute("cardID")->value(), "truck0") == 0)
			{
				type = SpawnerType::TRUCK;
			}
			else if(strcmp(pNode->first_attribute("cardID")->value(), "racing1") == 0)
			{
				type = SpawnerType::RACING1;
			}
			else if(strcmp(pNode->first_attribute("cardID")->value(), "family0") == 0)
			{
				type = SpawnerType::FAMILY;
			}
			else if(strcmp(pNode->first_attribute("cardID")->value(), "farming0") == 0)
			{
				type = SpawnerType::FARMING;
			}
			else if(strcmp(pNode->first_attribute("cardID")->value(), "racing0") == 0)
			{
				type = SpawnerType::RACING0;
			}
			
			int min=0;
			int max=0;
			int speed=0;
			for (rapidxml::xml_node<>* pSubNode = pNode->first_node(); pSubNode; pSubNode = pSubNode->next_sibling())
			{
				if (strcmp(pSubNode->name(), "SpawnRate") == 0)
				{
					min = std::stoi(pSubNode->first_attribute("min")->value());
					max = std::stoi(pSubNode->first_attribute("max")->value());
				}
				else if (strcmp(pSubNode->name(), "Speed") == 0)
				{
					speed = std::stoi(pSubNode->value());
				}
			}
			//set spawner
			Spawner* carSpawner = new Spawner(float(min + rand() % max), type, Vector2(5, RM->windowHeight - 55), Vector2(speed/70.f, 0));
			spawns.emplace_back(carSpawner);
			//set road tiles
			Tile* road = new Tile(Vector2(RM->windowWidth, 14), Vector2(0, RM->windowHeight - 55), ColliderType::SAVE, "resources/Assets/Log.png");
			tiles.emplace_back(road);
		}
	}
	return true;
}