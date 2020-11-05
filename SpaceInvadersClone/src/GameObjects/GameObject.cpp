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

void GameObject::addComponent(std::shared_ptr<Component> component)
{
	m_Components.push_back(component);
	component->enableComponent();

	if (component->getType() == "update")
	{
		m_HasUpdateComponent = true;
		m_NumberUpdateComponents++;
		if (m_NumberUpdateComponents == 1)
		{
			m_FirstUpdateComponentLocation = m_Components.size() - 1;
		}
	}
	else if (component->getType() == "graphics")
	{
		// No iteration in draw method needed
		m_HasGraphicsComponent = true;
		m_GraphicsComponentLocation = m_Components.size() - 1;
	}
	else if (component->getType() == "transform")
	{
		// Remember where the transform component is
		m_TransformComponentLocation = m_Components.size() - 1;
	}
	else if (component->getType() == "collider" && component->getSpecificType() == "rect")
	{
		// Remember where the collider component is 
		m_HasCollider = true;
		m_NumberRectColliderComponents++;
		if (m_NumberRectColliderComponents == 1)
		{
			m_FirstRectCollderComponentLocation = m_Components.size() - 1;
		}
	}
}

