#pragma once
#include "SFML/Graphics.hpp"
#include "Component.h"

class Component;

class TransformComponent : public Component
{
private:
	const std::string m_Type{ "transform" };
	sf::Vector2f m_Location;
	float m_Height;
	float m_Width;
public:
	TransformComponent(float width, float height, sf::Vector2f location);

	sf::Vector2f& getLoction();
	sf::Vector2f getSize();

	/***********************************************
	***********************************************
	From Component interface base class
	***********************************************
	***********************************************/

	std::string Component::getType()
	{
		return m_Type;
	}

	std::string Component::getSpecificType()
	{
		// Only one type of Transform so we just return the m_Type
		return m_Type;
	}

	void Component::disableComponent() {}
	void Component::enableComponent() {}
	bool Component::enabled()
	{
		return false;
	}

	void Component::start(GameObjectSharer* gos, GameObject* self) {}
};