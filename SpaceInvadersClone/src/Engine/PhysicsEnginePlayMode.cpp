#include <iostream>
#include "../GameObjects/BulletUpdateComponent.h"
#include "DevelopState.h"
#include "../GameObjects/InvaderUpdateComponent.h"
#include "PhysicsEnginePlayMode.h"
#include "SoundEngine.h"
#include "WorldState.h"

void PhysicsEnginePlayMode::detectInvaderCollisons(
	std::vector<GameObject>& objects,
	const std::vector<int>& bulletPositions)
{
	sf::Vector2f offScreen(-1, -1);

	auto invaderIt{ objects.begin() };
	auto invaderEnd{ objects.end() };

	for (invaderIt; invaderIt < invaderEnd; ++invaderIt)
	{
		if ((*invaderIt).isActive() 
			&& (*invaderIt).getTag() == "invader")
		{
			auto bulletIt{ objects.begin() };
			// Jump to the first bullet
			std::advance(bulletIt, bulletPositions[0]);
			auto bulletEnd{ objects.end() };

			for (bulletIt; bulletIt < bulletEnd; ++bulletIt)
			{
				if ((*invaderIt).getEncompassRectCollider().intersects(
					(*bulletIt).getEncompassRectCollider())
					&& (*bulletIt).getTag() == "bullet"
					&& std::static_pointer_cast<
					BulletUpdateComponent>((*bulletIt).getFirstUpdateComponent())
					->m_BelongsToPlayer)
				{
					SoundEngine::playInvaderExplode();
					(*invaderIt).getTransformComponent()
						->getLocation() = offScreen;

					(*bulletIt).getTransformComponent()
						->getLocation() = offScreen;

					WorldState::SCORE++;
					WorldState::NUM_INVADERS--;

					(*invaderIt).setInactive();
				}
			}
		}
	}
}

void PhysicsEnginePlayMode::detectPlayerCollisionsAndInvaderDirecton(
	std::vector<GameObject>& objects,
	const std::vector<int>& bulletPositions)
{
	sf::Vector2f offScreen(-1, -1);

	sf::FloatRect playerCollider{ m_Player->getEncompassRectCollider() };
	std::shared_ptr<TransformComponent> playerTransform{ m_Player->getTransformComponent() };
	sf::Vector2f playerLocation{ playerTransform->getLocation() };

	auto it{ objects.begin() };
	auto end{ objects.end() };

	for (it; it < end; ++it)
	{
		if((*it).isActive() 
			&& (*it).hasCollider()
			&& (*it).getTag() != "player")
		{
			// Get a reference to all the parts of the current
			// game object that we might need
			sf::FloatRect currentCollider{ (*it).getEncompassRectCollider() };
			
			// Detect collisions between object with the player
			if (currentCollider.intersects(playerCollider))
			{
				if ((*it).getTag() == "bullet")
				{
					SoundEngine::playPlayerExplode();
					WorldState::LIVES--;
					(*it).getTransformComponent()->getLocation() = offScreen;
				}

				if ((*it).getTag() == "invader")
				{
					SoundEngine::playPlayerExplode();
					SoundEngine::playInvaderExplode();
					WorldState::LIVES--;
					(*it).getTransformComponent()->getLocation() = offScreen;
					
					WorldState::SCORE++;
					(*it).setInactive();
				}
			}

			std::shared_ptr<TransformComponent> currentTransfrom{ (*it).getTransformComponent() };
			
			sf::Vector2f currentLocation{ currentTransfrom->getLocation() };

			std::string currentTag{ (*it).getTag() };
			sf::Vector2f currentSize{ currentTransfrom->getSize() };

			// Handle the direction and descent of the invaders
			if (currentTag == "invader")
			{
				// This is an invader
				if (!m_NeedToDropDownAndReverse &&
					!m_InvaderHitWallThisFrame)
				{
					// currently no need to dropdown and reverse from the previous frame
					// or any hits this frame
					if (currentLocation.x >= WorldState::WORLD_WIDTH - currentSize.x)
					{
						// The invader passed it's furthest right position
						if (std::static_pointer_cast<InvaderUpdateComponent>
							((*it).getFirstUpdateComponent())->isMovingRight())
						{
							// The invader is travelling right, so set the flag that an invader
							// has collided with the wall
							m_InvaderHitWallThisFrame = true;
						}
					}
					else if (currentLocation.x < 0)
					{
						// This invader is past the furthes left position
						if (!std::static_pointer_cast<InvaderUpdateComponent>
							((*it).getFirstUpdateComponent())->isMovingRight())
						{
							// The invader is travelling left, so set the flag that an invader
							// has collided
							m_InvaderHitWallThisFrame = true;
						}
					}
				}
				else if (m_NeedToDropDownAndReverse && !m_InvaderHitWallPreviousFrame)
				{
					// Drop down and reverse has been set
					if ((*it).hasUpdateComponent())
					{
						// Drop down and reverse
						std::static_pointer_cast<InvaderUpdateComponent>(
							(*it).getFirstUpdateComponent())->dropDownAndReverse();
					}
				}
			}
		}
	}
}

void PhysicsEnginePlayMode::handleInvaderDirection()
{
	if (m_InvaderHitWallThisFrame)
	{
		m_NeedToDropDownAndReverse = true;
		m_InvaderHitWallThisFrame = false;
	}
	else
	{
		m_NeedToDropDownAndReverse = false;
	}
}

void PhysicsEnginePlayMode::initialize(GameObjectSharer& gos)
{
	m_PUC = std::static_pointer_cast<PlayerUpdateComponent>(
		gos.findFirstObjectWithTag("Player")
		.getComponentByTypeAndSpecificType("update", "player"));

	m_Player = &gos.findFirstObjectWithTag("Player");
}