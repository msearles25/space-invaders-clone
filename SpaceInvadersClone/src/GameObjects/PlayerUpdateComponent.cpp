#include "PlayerUpdateComponent.h"
#include "../Engine/WorldState.h"

void PlayerUpdateComponent::update(float fps)
{
	if (sf::Joystick::isConnected(0))
	{
		m_TC->getLocation().x += ((m_Speed / 100) * m_YExtent) * fps;
		m_TC->getLocation().y += ((m_Speed / 100) * m_YExtent) * fps;
	}

	// Left and right
	if (m_IsHoldingLeft)
	{
		m_TC->getLocation().x -= m_Speed * fps;
	}
	else if (m_IsHoldingRight)
	{
		m_TC->getLocation().x += m_Speed * fps;
	}

	// Up and down
	if (m_IsHoldingUp)
	{
		m_TC->getLocation().y -= m_Speed * fps;
	}
	else if (m_IsHoldingDown)
	{
		m_TC->getLocation().y += m_Speed * fps;
	}

	// update the collider
	m_RCC->setOrMoveCollider(m_TC->getLocation().x, m_TC->getLocation().y,
		m_TC->getSize().x, m_TC->getSize().y);

	// Make sure the ship doesn't go out of the map/allowed area
	if (m_TC->getLocation().x > WorldState::WORLD_WIDTH - m_TC->getSize())
	{
		m_TC->getLocation().x = WorldState::WORLD_WIDTH - m_TC->getSize().x;
	}
	else if (m_TC->getLocation().x < 0)
	{
		m_TC->getLocation().x = 0;
	}

	if (m_TC->getLocation().y > WorldState::WORLD_HEIGHT - m_TC->getLocation().y)
	{
		m_TC->getLocation().y = WorldState::WORLD_HEIGHT - m_TC->getSize().y;
	}
	else if (m_TC->getLocation().y < WorldState::WORLD_HEIGHT / 2)
	{
		m_TC->getLocation().y = WorldState::WORLD_HEIGHT / 2;
	}
}