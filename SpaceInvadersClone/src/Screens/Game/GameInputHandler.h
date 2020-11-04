#pragma once
#include "../InputHandler.h"

class GameInputHandler : public InputHandler
{
public:
	void initialize();
	void handleGamepad() override;
	void handleKeyPressed(sf::Event& event, sf::RenderWindow& window) override;
	void handleKeyReleased(sf::Event& event, sf::RenderWindow& window) override;
};