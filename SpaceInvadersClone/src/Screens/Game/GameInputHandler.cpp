#include "GameScreen.h"
#include "GameInputHandler.h"
#include "../../Engine/SoundEngine.h"

class BulletSpawner;

void GameInputHandler::initialize() {}

void GameInputHandler::handleGamepad() 
{
	float deadZone{ 10.0f };
	float x{ sf::Joystick::getAxisPosition(0, sf::Joystick::X) };
	float y{ sf::Joystick::getAxisPosition(0, sf::Joystick::Y) };

	if (x < deadZone && x > -deadZone)
	{
		x = 0;
	}
	if (y < deadZone && y > -deadZone)
	{
		y = 0;
	}

	m_PUC->updateShipTravelWithController(x, y);

	// Has the player pressed the B/circle(ps) button
	if (sf::Joystick::isButtonPressed(0, 1))
	{
		mBButtonPressed = true;
	}

	// Has the player released the B/circle(ps) button
	if (!sf::Joystick::isButtonPressed(0, 1) && mBButtonPressed)
	{
		mBButtonPressed = false;

		// Shoot a bullet
		SoundEngine::playShoot();
		sf::Vector2f spawnLocation;
		
		spawnLocation.x = m_PTC->getLocation().x + m_PTC->getSize().x / 2;

		spawnLocation.y = m_PTC->getLocation().y;

		static_cast<GameScreen*>(getParentScreen())->
			getBulletSpawner()->spawnBullet(spawnLocation, true);
	}
}

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