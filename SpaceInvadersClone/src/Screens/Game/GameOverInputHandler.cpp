#include <iostream>
#include "GameOverInputHandler.h"
#include "../../Engine/SoundEngine.h"
#include "../../Engine/WorldState.h"

void GameOverInputHandler::handleKeyPressed(sf::Event& event, sf::RenderWindow& window)
{
	if (event.key.code == sf::Keyboard::Escape)
	{
		SoundEngine::playClick;
		getPointerToScreenManagerRemoteControl()->SwitchScreens("Select");
	}
}

