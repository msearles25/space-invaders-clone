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
		if ((*invaderIt).getTag() == "invader")
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