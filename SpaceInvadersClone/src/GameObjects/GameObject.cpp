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