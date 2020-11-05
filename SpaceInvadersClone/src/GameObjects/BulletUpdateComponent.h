#pragma once
#include "GameObject.h"
#include "GameObjectSharer.h"
#include "RectColliderComponent.h"
#include "TransformComponent.h"
#include "UpdateComponent.h"

class BulletUpdateComponent : public UpdateComponent
{
	std::string m_SpecificType{ "bullet" };
	std::shared_ptr<TransformComponent> m_TC;
	std::shared_ptr<RectColliderComponent> m_RCC;

	float m_Speed{ 75.0f };

	int m_AlienBulletSpeedModifier;
	int m_ModifierRandomComponent{ 5 };
	int m_MinimumAdditionalModifier{ 5 };

	bool m_MovingUp{ true };
public:
	bool m_BelongsToPlayer{ false };
	bool m_IsSpawned{ false };

	void spawnForPlayer(sf::Vector2f spawnPosition);
	void spawnForInvader(sf::Vector2f spawnPosition);
	void deSpawn();
	bool isMovingUp();

	/***********************************************
	***********************************************
	From Component interface base clss
	***********************************************
	***********************************************/

	std::string Component::getSpecificType()
	{
		return m_SpecificType;
	}

	void Component::start(GameObjectSharer* gos, GameObject* self)
	{
		// Where is this specific invader?
		m_TC = std::static_pointer_cast<TransformComponent>(
			self->getComponentByTypeAndSpecificType("transform", "transform"));

		m_RCC = std::static_pointer_cast<RectColliderComponent>(
			self->getComponentByTypeAndSpecificType("collider", "rect"));
	}

	/***********************************************
	***********************************************
	From UpdateComponent
	***********************************************
	***********************************************/

	void update(float fps) override;
};