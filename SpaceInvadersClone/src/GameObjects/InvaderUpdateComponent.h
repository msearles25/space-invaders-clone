#pragma once
#include "GameObject.h"
#include "../FileIO/GameObjectSharer.h"
#include "RectColliderComponent.h"
#include "TransformComponent.h"
#include "UpdateComponent.h"

class BulletSpawner;

class InvaderUpdateComponent : public UpdateComponent
{
private:
	std::string m_SpecificType{ "invader" };

	std::shared_ptr<TransformComponent> m_TC;
	std::shared_ptr<RectColliderComponent> m_RCC;
	std::shared_ptr<TransformComponent> m_PlayerTC;
	std::shared_ptr<RectColliderComponent> m_PlayerRCC;

	BulletSpawner* m_BulletSpawner;

	float m_Speed{ 10.f };
	bool m_MoveRight{ true };
	float m_TimeSinceLastShot;
	float m_TimeBetweenShots{ 5.0f };
	float m_AccuracyModifier;
	float m_SpeedModifier{ 0.5f };
	int m_RandSeed;
public:
	void dropDownAndReverse();
	bool isMovingRight();
	void initializeBulletSpawner(BulletSpawner* bulletSpawner, int randSeed);

	/***********************************************
	***********************************************
	From Component interface base class
	***********************************************
	***********************************************/

	std::string Component::getSpecificType()
	{
		return m_SpecificType;
	}

	void Component::start(GameObjectSharer* gos, GameObject* self)
	{
		// where is the player?
		m_PlayerTC = std::static_pointer_cast<TransformComponent>(
			gos->findFirstObjectWithTag("Player")
			.getComponentByTypeAndSpecificType("transform", "transform"));

		m_PlayerRCC = std::static_pointer_cast<RectColliderComponent>(
			gos->findFirstObjectWithTag("Player")
			.getComponentByTypeAndSpecificType("collider", "rect"));

		// Where is this specific invader
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