#include "Screen.h"

void Screen::initialize() {}

void Screen::addPanel(std::unique_ptr<UIPanel> uip,
	ScreenManagerRemoteControl* smrc,
	std::shared_ptr<InputHandler> ih)
{
	ih->initializeInputHandler(smrc, uip->getButtons(), &uip->m_View, this);
	// use move() because otherwise the vector
	// has a copy which is not alowed
	m_Panels.push_back(move(uip));
	m_InputHandlers.push_back(ih);
}

void Screen::handleInput(sf::RenderWindow& window)
{
	sf::Event event;
	auto itr{ m_InputHandlers.begin() };
	auto end{ m_InputHandlers.end() };
	
	while (window.pollEvent(event))
	{
		for (itr; itr < end; ++itr)
		{
			(*itr)->handleInput(window, event);
		}
	}
}

