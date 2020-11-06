#include "GameObjectBluprint.h"

float GameObjectBluprint::getWidth()
{
	return m_Width;
}

void GameObjectBluprint::setWidth(float width)
{
	m_Width = width;
}

float GameObjectBluprint::getHeight()
{
	return m_Height;
}

void GameObjectBluprint::setHeight(float height)
{
	m_Height = height;
}

float GameObjectBluprint::getLocationX()
{
	return m_LocationX;
}

void GameObjectBluprint::setLocationX(float locationX)
{
	m_LocationX = locationX;
}

float GameObjectBluprint::getLocationY()
{
	return m_LocationY;
}

void GameObjectBluprint::setLocationY(float locationY)
{
	m_LocationY = locationY;
}

void GameObjectBluprint::setName(std::string name)
{
	m_Name = "" + name;
}

std::string GameObjectBluprint::getName()
{
	return m_Name;
}

std::vector<std::string>& GameObjectBluprint::getComponentList()
{
	return m_ComponentList;
}

void GameObjectBluprint::addComponentList(std::string newComponent)
{
	m_ComponentList.push_back(newComponent);
}

std::string GameObjectBluprint::getBitmapName()
{
	return m_BitmapName;
}

void GameObjectBluprint::setBitmapName(std::string bitmapName)
{
	m_BitmapName = "" + bitmapName;
}

std::string GameObjectBluprint::getEncompassingRectColliderLabel()
{
	return m_EncompassingColliderLabel;
}

bool GameObjectBluprint::getEncompassingRectCollider()
{
	return m_EncompassingRectCollider;
}

void GameObjectBluprint::setEncompassingRectCollider(std::string label)
{
	m_EncompassingRectCollider = true;
	m_EncompassingColliderLabel = "" + label;
}