#include <iostream>
#include "LevelManager.h"
#include "PlayModeObjectLoader.h"

void LevelManager::loadGameObjectsForPlayMode(std::string screenToLoad)
{
	m_GameObjects.clear();
	std::string levelToLoad{ "" + WORLD_FOLDER + SLASH + screenToLoad};

	PlayModeObjectLoader pmol;
	pmol.loadGameObjectForPlayMode(levelToLoad, m_GameObjects);

	runStartPhase();
}

std::vector<GameObject>& LevelManager::getGameObjects()
{
	return m_GameObjects;
}

void LevelManager::runStartPhase()
{
	auto it{ m_GameObjects.begin() };
	auto end{ m_GameObjects.end() };

	for (it; it < end; ++it)
	{
		(*it).setActive();
	}
}