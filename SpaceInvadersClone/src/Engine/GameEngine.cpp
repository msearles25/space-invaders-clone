#include "GameEngine.h"

GameEngine::GameEngine()
{
	m_Resolution.x = sf::VideoMode::getDesktopMode().width;
	m_Resolution.y = sf::VideoMode::getDesktopMode().height;
	m_Window.create(sf::VideoMode(m_Resolution.x, m_Resolution.y), 
		"Space Invaders++", sf::Style::Fullscreen);

	m_ScreenManager = unique_ptr<ScreenManager>(new ScreenManager(
		sf::Vector2i(m_Resolution.x, m_Resolution.y)));
}

void GameEngine::run()
{

}