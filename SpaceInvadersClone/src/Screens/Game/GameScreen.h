#pragma once
#include "GameInputHandler.h"
#include "GameOverInputHandler"
#include "../Screen.h"

class GameScreen : public Screen
{
private:
	ScreenManagerRemoteControl* m_ScreenManagerRemoteControl;
	std::shared_ptr<GameInputHandler> m_GIH;

	sf::Texture m_BackgroundTexture;
	sf::Sprite m_BackgroundSprite;
public:
	static bool m_GameOver;

	GameScreen(ScreenManagerRemoteControl* smrc, sf::Vector2i res);
	void initialize() override;
	virtual void update(float fps) override;
	virtual void draw(sf::RenderWindow& window);
};