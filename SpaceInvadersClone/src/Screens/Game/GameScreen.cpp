#include "../../GameObjects/BulletUpdateComponent.h"
#include "../../GameObjects/BulletSpawner.h"
#include "GameInputHandler.h"
#include "GameScreen.h"
#include "GameUIPanel.h"
#include "../../GameObjects/GameObject.h"
#include "GameOverUIPanel.h"
#include "../../GameObjects/InvaderUpdateComponent.h"
#include "../../Engine/WorldState.h"

class BulletSpawner;

int WorldState::WORLD_HEIGHT;
int WorldState::NUM_INVADERS;
int WorldState::NUM_INVADERS_AT_START;

GameScreen::GameScreen(ScreenManagerRemoteControl* smrc, sf::Vector2i res)
{
	m_GIH = std::make_shared<GameInputHandler>();
	auto guip{ std::make_unique<GameUIPanel>(res)};
	addPanel(std::move(guip), smrc, m_GIH);

	auto m_GOIH{ std::make_shared<GameOverInputHandler>() };
	auto gouip{ std::make_unique<GameOverUIPanel>(res) };
	addPanel(std::move(gouip), smrc, m_GOIH);
	
	m_ScreenManagerRemoteControl = smrc;
	float screenRatio{ float(sf::VideoMode::getDesktopMode().width / 
		sf::VideoMode::getDesktopMode().height) };

	WorldState::WORLD_HEIGHT = WorldState::WORLD_WIDTH / screenRatio;

	m_View.setSize(WorldState::WORLD_WIDTH, WorldState::WORLD_HEIGHT);

	m_View.setCenter(sf::Vector2f(WorldState::WORLD_WIDTH / 2, WorldState::WORLD_HEIGHT / 2));
	
	m_BackgroundTexture.loadFromFile("Content/graphics/background.png");
	m_BackgroundSprite.setTexture(m_BackgroundTexture);
	auto textureSize{ m_BackgroundSprite.getTexture()->getSize() };
	m_BackgroundSprite.setScale(float(m_View.getSize().x) / textureSize.x,
		float(m_View.getSize().y / textureSize.y));
}

void GameScreen::initialize()
{
	m_GIH->initialize();
	m_PhysicsEnginePlayMode.initialize(
		m_ScreenManagerRemoteControl->shareGameObjectSharer());

	WorldState::NUM_INVADERS = 0;

	// Store all the bullet locations and Intialize all of the BulletSpawneres
	// in the invaders.
	// Count the number of invaders
	int i{ 0 };
	auto it{ m_ScreenManagerRemoteControl->getGameObjects().begin() };
	auto end{ m_ScreenManagerRemoteControl->getGameObjects().end() };

	for (it; it != end; ++it)
	{
		if ((*it).getTag() == "bullet")
		{
			m_BulletObjecLocations.push_back(i);
		}
		if ((*it).getTag() == "invader")
		{
			std::static_pointer_cast<InvaderUpdateComponent>(
				(*it).getFirstUpdateComponent())
				->initializeBulletSpawner(getBulletSpawner(), i);

			WorldState::NUM_INVADERS++;
		}
		++i;
	}

	m_GameOver = false;

	if (WorldState::WAVE_NUMBER == 0)
	{
		WorldState::NUM_INVADERS_AT_START = WorldState::NUM_INVADERS;

		WorldState::WAVE_NUMBER = 1;
		WorldState::LIVES = 3;
		WorldState::SCORE = 0;
	}
}

void GameScreen::update(float fps)
{
	Screen::update(fps);

	if (!m_GameOver)
	{
		if (m_WaitingToSpawnBulletForPlayer)
		{
			std::static_pointer_cast<BulletUpdateComponent>(
				m_ScreenManagerRemoteControl
				->getGameObjects()[m_BulletObjecLocations[m_NextBullet]]
				.getFirstUpdateComponent())->spawnForPlayer(m_PlayerBulletSpawnLocation);
			
			m_WaitingToSpawnBulletForPlayer = false;
			m_NextBullet;
			
			if (m_NextBullet == m_BulletObjecLocations.size())
			{
				m_NextBullet = 0;
			}
		}

		if (m_WaitingToSpawnBulletForInvader)
		{
			std::static_pointer_cast<BulletUpdateComponent>(
				m_ScreenManagerRemoteControl
				->getGameObjects()[m_BulletObjecLocations[m_NextBullet]]
				.getFirstUpdateComponent())->spawnForInvader(m_InvaderBulletSpawnLocation);

			m_WaitingToSpawnBulletForInvader = false;
			m_NextBullet++;

			if (m_NextBullet == m_BulletObjecLocations.size())
			{
				m_NextBullet = 0;
			}
		}

		auto it{ m_ScreenManagerRemoteControl->getGameObjects().begin() };
		auto end{ m_ScreenManagerRemoteControl->getGameObjects().end() };

		for (it; it != end; ++it)
		{
			(*it).update(fps);
		}

		m_PhysicsEnginePlayMode.detectCollisions(
			m_ScreenManagerRemoteControl->getGameObjects(), m_BulletObjecLocations);

		if (WorldState::NUM_INVADERS < 0)
		{
			WorldState::WAVE_NUMBER++;
			m_ScreenManagerRemoteControl->loadLevelInPlayMode("level1");
		}

		if (WorldState::LIVES <= 0)
		{
			m_GameOver = true;
		}
	}
}

void GameScreen::draw(sf::RenderWindow& window)
{
	// Change to this screen's view to draw on
	window.setView(m_View);
	window.draw(m_BackgroundSprite);

	// Draw the UIPanel view
	Screen::draw(window);
}

BulletSpawner* GameScreen::getBulletSpawner()
{
	return this;
}