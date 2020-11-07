#include <fstream>
#include <iostream>
#include "ObjectTags.h"
#include "PlayModeObjectLoader.h"

void PlayModeObjectLoader::loadGameObjectForPlayMode(
	std::string pathToFile, std::vector<GameObject>& gameObjects)
{
	std::ifstream reader(pathToFile);
	std::string lineFromFile;

	float x{ 0 }, y{ 0 }, width{ 0 }, height{ 0 };
	std::string value{ "" };

	while (std::getline(reader, lineFromFile))
	{
		if (lineFromFile.find(ObjectTags::START_OF_OBJECT) != std::string::npos)
		{
			GameObjectBluprint bp;
			m_BOP.parseNextObjectForBlueprint(reader, bp);
			m_GOFPM.buildGameObject(bp, gameObjects);
		}
	}
}