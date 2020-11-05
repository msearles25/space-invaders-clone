#include "BulletUpdateComponent.h"
#include "../Engine/WorldState.h"

void BulletUpdateComponent::spawnForPlayer(sf::Vector2f spawnPosition)
{
	m_MovingUp = true;
	m_BelongsToPlayer = true;
	m_IsSpawned = true;

	m_TC->getLocation().x = spawnPosition.x;
	// Tweak the location of the y location based on the height of the bullet
	// The x location is already tweaked to the center of the player
	m_TC->getLocation().y = spawnPosition.y - m_TC->getSize().y;
	// Update the collider
	m_RCC->setOrMoveCollider(
		m_TC->getLocation().x, m_TC->getLocation().y,
		m_TC->getSize().x, m_TC->getSize().y);
}

