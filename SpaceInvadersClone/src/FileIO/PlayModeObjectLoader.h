#pragma once
#include <string>
#include <vector>
#include "BlueprintObjectParser.h"
#include "../GameObjects/GameObject.h"
#include "GameObjectFactoryPlayMode.h";

class PlayModeObjectLoader
{
private:
	BlueprintObjectParser m_BOP;
	gameObjectFactoryPlayMode m_GOFPM;
public:
	void loadGameObjectForPlayMode(
		std::string pathTofile, std::vector<GameObject>& mGameObjects);
};