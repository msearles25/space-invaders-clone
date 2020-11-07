#pragma once
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Component.h"
#include "../FileIO/GameObjectSharer.h"
#include "GraphicsComponent.h"
#include "UpdateComponent.h"

class GameObject
{
	std::vector<std::shared_ptr<Component>> m_Components;

	std::string m_Tag;
	bool m_Active{ false };
	int m_NumberUpdateComponents{ 0 };
	bool m_HasUpdateComponent{ false };
	int m_FirstUpdateComponentLocation{ -1 };
	int m_GraphicsComponentLocation{ -1 };
	bool m_HasGraphicsComponent{ false };
	int m_TransformComponentLocation{ -1 };
	int m_NumberRectColliderComponents{ 0 };
	int m_FirstRectCollderComponentLocation{ -1 };
	bool m_HasCollider{ false };
public:
	void update(float fps);
	void draw(sf::RenderWindow& window);
	void addComponent(std::shared_ptr<Component> component);

	void setActive();
	void setInactive();
	bool isActive();
	void setTag(sf::String tag);
	std::string getTag();

	void start(GameObjectSharer* gos);

	// Only used in init and start
	std::shared_ptr<Component> getComponentByTypeAndSpecificType(
		std::string type, std::string specificType);

	sf::FloatRect& getEncompassRectCollider();
	bool hasCollider();
	bool hasUpdateComponent();
	std::string getEncompassRectColliderTag();
	
	std::shared_ptr<GraphicsComponent> getGraphicsComponent();
	std::shared_ptr<TransformComponent> getTransformComponent();
	std::shared_ptr<UpdateComponent> getFirstUpdateComponent();
};