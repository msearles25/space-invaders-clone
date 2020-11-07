#include "GameScreen.h"
#include "GameInputHandler.h"
#include "../../Engine/SoundEngine.h"

class BulletSpawner;

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

	if (event.key.code == sf::Keyboard::Left)
	{
		m_PUC->moveLeft();
	}
	if (event.key.code == sf::Keyboard::Right)
	{
		m_PUC->moveRight();
	}
	if (event.key.code == sf::Keyboard::Up)
	{
		m_PUC->moveUp();
	}
	if (event.key.code == sf::Keyboard::Down)
	{
		m_PUC->moveDown();
	}
}

void GameInputHandler::handleKeyReleased(sf::Event& event, sf::RenderWindow& window) 
{
	if (event.key.code == sf::Keyboard::Left)
	{
		m_PUC->stopLeft();
	}
	else if (event.key.code == sf::Keyboard::Right)
	{
		m_PUC->stopRight();
	}
	else if (event.key.code == sf::Keyboard::Up)
	{
		m_PUC->stopUp();
	}
	else if (event.key.code == sf::Keyboard::Down)
	{
		m_PUC->stopDown();
	}
	else if (event.key.code == sf::Keyboard::Space)
	{
		// Shoot a bullet
		SoundEngine::playShoot();
		sf::Vector2f spawnLocation;
		spawnLocation.x = m_PTC->getLocation().x + m_PTC->getSize().x / 2;

		spawnLocation.y = m_PTC->getLocation().y;

		static_cast<GameScreen*>(getParentScreen())->spawnBullet(spawnLocation, true);
	}
}