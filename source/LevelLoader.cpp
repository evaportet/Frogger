#include "LevelLoader.h"

std::vector<Spawner*> LevelLoader::LoadLevel(std::string path)
{
	rapidxml::xml_document<> doc;
	std::ifstream file("resources/Files/sample_level.xml");
	std::stringstream buffer;
	buffer << file.rdbuf();
	file.close();
	std::string content(buffer.str());
	doc.parse<0>(&content[0]);

	enum CarType
	{
		TRUCK,
		RACING0,
		FAMILY,
		FARMING,
		RACING1
	};

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
			int minLength;
			int maxLength;
			int min;
			int max;
			int cocodrChance;
			int snakeChance;

			minLength = std::stoi(pNode->first_attribute("minLength")->value());
			maxLength = std::stoi(pNode->first_attribute("maxLength")->value());

			for (rapidxml::xml_node<>* pSubNode = pNode->first_node(); pSubNode; pNode = pSubNode->next_sibling())
			{
				if (strcmp(pSubNode->name(), "SpawnRate") == 0)
				{
					min = std::stoi(pNode->first_attribute("min")->value());
					min = std::stoi(pNode->first_attribute("max")->value());
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
			int minLength;
			int maxLength;
			int min;
			int max;
			float diveChance;

			minLength = std::stoi(pNode->first_attribute("minLength")->value());
			maxLength = std::stoi(pNode->first_attribute("maxLength")->value());

			for (rapidxml::xml_node<>* pSubNode = pNode->first_node(); pSubNode; pSubNode = pSubNode->next_sibling())
			{
				if (strcmp(pSubNode->name(), "SpawnRate") == 0)
				{
					min = std::stoi(pNode->first_attribute("min")->value());
					min = std::stoi(pNode->first_attribute("max")->value());
				}
				else if (strcmp(pSubNode->name(), "DiveChance") == 0)
				{
					diveChance = std::stoi(pSubNode->value());
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
			CarType type;
			if(strcmp(pNode->first_attribute("cardID")->value(), "truck0") == 0)
			{
				type = TRUCK;
			}
			else if(strcmp(pNode->first_attribute("cardID")->value(), "racing1") == 0)
			{
				type = RACING1;
			}
			else if(strcmp(pNode->first_attribute("cardID")->value(), "family0") == 0)
			{
				type = FAMILY;
			}
			else if(strcmp(pNode->first_attribute("cardID")->value(), "farming0") == 0)
			{
				type = FARMING;
			}
			else if(strcmp(pNode->first_attribute("cardID")->value(), "racing0") == 0)
			{
				type = RACING0;
			}
			
			int min;
			int max;
			int speed;
			for (rapidxml::xml_node<>* pSubNode = pNode->first_node(); pSubNode; pSubNode = pSubNode->next_sibling())
			{
				if (strcmp(pSubNode->name(), "SpawnRate") == 0)
				{
					min = std::stoi(pNode->first_attribute("min")->value());
					min = std::stoi(pNode->first_attribute("max")->value());
				}
				else if (strcmp(pSubNode->name(), "Speed") == 0)
				{
					speed = std::stoi(pSubNode->value());
				}

			}
			//set spawner

			//set road tiles
		}

		
		
		
	}











	for (rapidxml::xml_node<>* pNode = pRoot->first_node("MaxTime"); pNode; pNode = pNode->next_sibling())
		//sscanf_s(pNode->first_attribute("MaxTime")->value(), "%d", &_MaxTime);

	
		//SAFEZONE
		//ROAD
		for (rapidxml::xml_node<>* pNode = pRoot->first_node("Road"); pNode; pNode = pNode->next_sibling())
		{
			//sscanf_s(pNode->first_attribute("Road")->value(), "%d", &_Road);

			for (rapidxml::xml_node<>* pChild = pNode->first_node(); pChild; pChild = pChild->next_sibling())
			{
				std::string childName = pChild->name();
				if (childName == "SpawnRate")
				{
					//if ((std::string)pNode->name() == "SpawnRate")
					//sscanf_s(pNode->first_attribute("min")->value(), "%d", &minSpawnRate);
					//sscanf_s(pNode->first_attribute("max")->value(), "%d", &_maxSpawnRate);
				}
				else if (childName == "Speed")
				{
					//sscanf_s(pNode->first_attribute("Speed")->value(), "%d", &speed);
				}
			}	
		}
	return level;
}