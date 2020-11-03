#include "UIPanel.h"

UIPanel::UIPanel(
	sf::Vector2i res, int x, int y,
	float width, float height,
	int alpha, int red, int green, int blue)
{
	m_UIPanel.setFillColor(sf::Color(red, green, blue, alpha));

	// How big is the UIPanel in pixels
	m_UIPanel.setSize(sf::Vector2f(width, height));

	// How big is the view in pixels
	m_View.setSize(sf::Vector2f(width, height));

	// Where does the center of the view focus, in pixles
	// Most relevant when drawing a portion of the game world
	m_View.setCenter(width / 2, height / 2);

	// Where is the view positioned in the window?
	float viewPortStartX{ 1.f / (res.x / x) };
	float viewPortStartY{ 1.f / (res.y / y) };
	float viewPortSizeX{ 1.f / (res.x / width) };
	float viewPortSizeY{ 1.f / (res.y / height) };

	m_View.setViewport(sf::FloatRect(viewPortStartX, viewPortStartY, 
		viewPortSizeX, viewPortSizeY));
}

std::vector<std::shared_ptr<Button>> UIPanel::getButtons()
{
	return m_Buttons;
}

void UIPanel::addButton(
	float x, float y,
	int width, int height,
	int red, int green, int blue,
	std::string label)
{
	m_Buttons.push_back(std::make_shared<Button>(
		sf::Vector2f(x, y), width, height,
		red, green, blue, label));
}

void UIPanel::draw(sf::RenderWindow& window)
{
	window.setView(m_View);
	if(!m_Hidden)
	{
		window.draw(m_UIPanel);
		for (auto it{ m_Buttons.begin() }; it != m_Buttons.end(); ++it)
		{
			(*it)->draw(window);
		}
	}
}

void UIPanel::show()
{
	m_Hidden = false;
}

void UIPanel::hide()
{
	m_Hidden = true;
}