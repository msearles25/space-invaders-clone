#include "GameScreen.h"
#include "GameInputHandler.h"
#include "../../Engine/SoundEngine.h"

void GameInputHandler::initialize() {}

void GameInputHandler::handleGamepad() {}

void GameInputHandler::handleKeyPressed(sf::Event& event, sf::RenderWindow& window)
{
	// Handle the key presses
	if (event.key.code == sf::Keyboard::Escape)
	{
		SoundEngine::playClick();
		getPointerToScreenManagerRemoteControl()->SwitchScreens("Select");
	}
}

void GameInputHandler::handleKeyReleased(sf::Event& event, sf::RenderWindow& window) {}