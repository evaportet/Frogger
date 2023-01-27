#include "LevelLoader.h"

std::vector<Spawner> LevelLoader::LoadLevel(std::string path)
{
	rapidxml::xml_document<> doc;
	std::ifstream file("resources/Files/sample_level.xml");
	std::stringstream buffer;
	buffer << file.rdbuf();
	file.close();
	std::string content(buffer.str());
	doc.parse<0>(&content[0]);

	std::vector<Spawner> level;

	rapidxml::xml_node<>* pRoot = doc.first_node();

	//MAXTIME
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