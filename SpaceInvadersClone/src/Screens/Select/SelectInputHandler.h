#pragma once
#include "../InputHandler.h"

class SelectInputHandler : public InputHandler
{
public:
	void handleKeyPressed(sf::Event& event, sf::RenderWindow& window);
	void handleLeftClick(std::string& buttonsInterfacedWith, sf::RenderWindow& window) override;
};