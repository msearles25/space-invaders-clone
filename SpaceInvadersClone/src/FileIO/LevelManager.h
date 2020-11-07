#pragma once
#include "../Engine/DevelopState.h"
#include <string>
#include <vector>
#include "../GameObjects/GameObject.h"
#include "GameObjectSharer.h"

class LevelManager : public GameObjectSharer
{
private:
	std::vector<GameObject> m_GameObjects;

	const std::string CONTENT_FOLDER{ "Content" };
	const std::string WORLD_FOLDER{ "world" };
	const std::string SLASH{ "/" };

	void runStartPhase();
	void activateAllGameObjects();
public:
	std::vector<GameObject>& getGameObjects();
	void loadGameObjectsForPlayMode(std::string screenToLoad);

	/***********************************************
	***********************************************
	From GameObjectSharer interface
	***********************************************
	***********************************************/

	std::vector<GameObject>& GameObjectSharer::getGameObjectsWithGOS()
	{
		return m_GameObjects;
	}
	
	GameObject& GameObjectSharer::findFirstObjectWithTag(std::string tag)
	{
		auto it{ m_GameObjects.begin() };
		auto end{ m_GameObjects.end() };

		for (it; it != end; ++it)
		{
			if ((*it).getTag() == tag)
			{
				return (*it);
			}
		}
#ifdef debuggingErrors
		std::cout << "LevelManager.h findFirstObjectWithTag() " 
			<< "Tag: " + tag
			<< " - NOT FOUND, ERROR!\n";
#endif // debuggingErrors
		return m_GameObjects[0];
	}
};