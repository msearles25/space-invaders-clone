#pragma once
#include "../../GameObjects/BulletSpawner.h"
#include "GameInputHandler.h"
#include "GameOverInputHandler.h"
#include "../../Engine/PhysicsEnginePlayMode.h"
#include "../Screen.h"

class GameScreen : public Screen, public BulletSpawner
{
private:
	ScreenManagerRemoteControl* m_ScreenManagerRemoteControl;
	std::shared_ptr<GameInputHandler> m_GIH;
	PhysicsEnginePlayMode m_PhysicsEnginePlayMode;

	int m_NumberInvadersInWorldFile{ 0 };

	std::vector<int> m_BulletObjecLocations;
	int m_NextBullet{ 0 };
	bool m_WaitingToSpawnBulletForPlayer{ false };
	bool m_WaitingToSpawnBulletForInvader{ false };
	sf::Vector2f m_PlayerBulletSpawnLocation;
	sf::Vector2f m_InvaderBulletSpawnLocation;
	sf::Clock m_BulletClock;

	sf::Texture m_BackgroundTexture;
	sf::Sprite m_BackgroundSprite;
public:
	static bool m_GameOver;

	GameScreen(ScreenManagerRemoteControl* smrc, sf::Vector2i res);
	void initialize() override;
	virtual void update(float fps) override;
	virtual void draw(sf::RenderWindow& window);

	BulletSpawner* getBulletSpawner();

	/*
	***********************************************
	***********************************************
	From BulletSpawner interface
	***********************************************
	***********************************************
	*/
	
	void BulletSpawner::spawnBullet(sf::Vector2f spawnLocation, bool forPlayer)
	{
		if (forPlayer)
		{
			sf::Time elapsedTime{ m_BulletClock.getElapsedTime() };

			if (elapsedTime.asMilliseconds() > 500)
			{
				m_PlayerBulletSpawnLocation.x = spawnLocation.x;
				m_PlayerBulletSpawnLocation.y = spawnLocation.y;
				m_WaitingToSpawnBulletForPlayer = true;
				m_BulletClock.restart();
			}
		}
		else
		{
			m_InvaderBulletSpawnLocation.x = spawnLocation.x;
			m_InvaderBulletSpawnLocation.y = spawnLocation.y;
			m_WaitingToSpawnBulletForInvader = true;

		}
	}
};