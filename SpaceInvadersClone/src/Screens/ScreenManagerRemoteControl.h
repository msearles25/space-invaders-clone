#pragma once
#include <string>
#include <vector>
#include "../GameObjects/GameObject.h"
#include "../FileIO/GameObjectSharer.h"

class ScreenManagerRemoteControl
{
public:
	virtual void SwitchScreens(std::string screenToSwitch) = 0;
	virtual void loadLevelInPlayMode(std::string screenToLoad) = 0;
	virtual std::vector<GameObject>& getGameObjects() = 0;
	virtual GameObjectSharer& shareGameObjectSharer() = 0;
};