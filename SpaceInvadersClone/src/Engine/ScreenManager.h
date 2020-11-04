#pragma once
#include <iostream>
#include <map>
#include <SFML/Graphics.hpp>
#include "BitmapStore.h"
#include "GameScreen.h"
#include "../Screens/ScreenManagerRemoteControl.h"
#include "../Screens/Select/SelectScreen.h"

class ScreenManager : public ScreenManagerRemoteControl
{
private:
	std::map<std::string, std::unique_ptr<Screen>> m_Screens;
protected:
	std::string m_CurrentScreen = "Select";
public:
	BitmapStore m_BS;

	ScreenManager(sf::Vector2i res);
	void update(float fps);
	void draw(sf::RenderWindow& window);
	void handleInput(sf::RenderWindow& window);

	/*
	***********************************************
	***********************************************
	From ScreenManagerRemoteControl interface
	***********************************************
	***********************************************
	*/
	void ScreenManagerRemoteControl::SwitchScreens(std::string screenToSwitchTo)
	{
		m_CurrentScreen = "" + screenToSwitchTo;
		m_Screens[m_CurrentScreen]->initialize();
	}

	void ScreenManagerRemoteControl::loadLevelInPlayMode(std::string screenToLoad)
	{
		SwitchScreens("Game");
	}
};