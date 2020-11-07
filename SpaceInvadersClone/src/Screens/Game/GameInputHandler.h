#pragma once
#include "../InputHandler.h"
#include "../../GameObjects/PlayerUpdateComponent.h"
#include "../../GameObjects/TransformComponent.h"

class GameInputHandler : public InputHandler
{
private:
	std::shared_ptr<PlayerUpdateComponent> m_PUC;
	std::shared_ptr<TransformComponent> m_PTC;

	bool mBButtonPressed{ false };
public:
	void initialize();
	void handleGamepad() override;
	void handleKeyPressed(sf::Event& event, sf::RenderWindow& window) override;
	void handleKeyReleased(sf::Event& event, sf::RenderWindow& window) override;
};