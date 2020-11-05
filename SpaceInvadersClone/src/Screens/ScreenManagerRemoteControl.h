#pragma once
#include <string>
#include <vector>

class ScreenManagerRemoteControl
{
public:
	virtual void SwitchScreens(std::string screenToSwitch) = 0;
	virtual void loadLevelInPlayMode(std::string screenToLoad) = 0;
};