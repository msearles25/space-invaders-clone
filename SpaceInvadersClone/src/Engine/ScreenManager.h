#pragma once
#include <iostream>
#include <map>
#include <SFML/Graphics.hpp>
#include "BitmapStore.h"
#include "GameScreen.h"
#include "ScreenMangerRemoteControl.h"
#include "ScreenSelection"

class ScreenManager : public ScreenManagerRemoteControl
{
private:
	std::map<std::string, unique_ptr<Screen>> m_Screens;
protected:
	std::string m_CurrentScreen = "Select";
public:
	BitmapScroe m_BS;

	ScreenManager(sf::Vector2i res);
	void update(float fps);
	void draw(sf::RenderWindow& window);
	void handleInput(sf::RenderWindow& window);
};