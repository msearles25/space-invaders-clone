#include <iostream>
#include "../Engine/DevelopState.h"
#include "GameObject.h"
#include "RectColliderComponent.h"
#include "UpdateComponent.h"

void GameObject::update(float fps)
{
	if (m_Active && m_HasUpdateComponent)
	{
		for (int i{ m_FirstUpdateComponentLocation }; i <
			m_FirstUpdateComponentLocation + m_NumberUpdateComponents; i++)
		{
			std::shared_ptr<UpdateComponent> tempUpdate{ std::static_pointer_cast<
				UpdateComponent>(m_Components[i]) };

			if (tempUpdate->enabled())
			{
				tempUpdate->update(fps);
			}
		}
	}
}

void GameObject::draw(sf::RenderWindow& window)
{
	if (m_Active && m_HasGraphicsComponent)
	{
		if (m_Components[m_GraphicsComponentLocation]->enabled())
		{
			getGraphicsComponent()->draw(window, getTransformComponent());
		}
	}
}

std::shared_ptr<GraphicsComponent> GameObject::getGraphicsComponent()
{
	return std::static_pointer_cast<GraphicsComponent>(
		m_Components[m_GraphicsComponentLocation]);
}

std::shared_ptr<TransformComponent> GameObject::getTransformComponent()
{
	return std::static_pointer_cast<TransformComponent>(
		m_Components[m_TransformComponentLocation]);
}

