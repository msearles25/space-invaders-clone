#include <iostream>
#include "SelectInputHandler.h"
#include "../../Engine/SoundEngine.h"
#include "../../Engine/WorldState.h"

int WorldState::WAVE_NUMBER;

void SelectInputHandler::handleKeyPressed(sf::Event& event, sf::RenderWindow& window)
{
	// Quit the game 
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		window.close();
	}
}

void SelectInputHandler::handleLeftClick(std::string& buttonIneteractedWith, sf::RenderWindow& window)
{
	if (buttonIneteractedWith == "Play")
	{
		SoundEngine::playClick();
		WorldState::WAVE_NUMBER = 0;
		getPointerToScreenManagerRemoteControl()->loadLevelInPlayMode("level1");
	}

	if (buttonIneteractedWith == "Quit")
	{
		SoundEngine::playClick();
		window.close();
	}
}