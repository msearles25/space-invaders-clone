#pragma once
#include "../InputHandler.h"

class SelectInputHandler : public InputHandler
{
public:
	void handleKeyPressed(sf::Event& event, sf::RenderWindow& window) override;
	void handleLeftClick(std::string& buttonsInterfacedWith, sf::RenderWindow& window) override;
};