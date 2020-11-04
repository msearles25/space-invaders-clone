#include <iostream>
#include "SelectUIPanel.h"

SelectUIPanel::SelectUIPanel(sf::Vector2i res) :
	// Create a new UIPanel by calling the super-class constructor
	UIPanel(res, 
		(res.x /10)*2, // Start 2/10 across
		res.y/3, // 1/3 of the resolution from the top
		(res.x/10) *6, // as wide ad 6/10 of the resolution
		res.y /3, // as tall as 1/3 of the resolution
		50,255,255,255) // a, r, g, b 
{
	m_ButtonWidth = res.x / 20;
	m_ButtonHeight = res.y / 20;
	m_ButtonPadding = res.x / 100;

	m_Text.setFillColor(sf::Color(0, 255, 0, 255));
	m_Text.setString("Space Invaders++");

	m_Font.loadFromFile("Content/fonts/Roboto-Bold.ttf");
	m_Text.setFont(m_Font);

	m_Text.setPosition(sf::Vector2f(m_ButtonPadding, m_ButtonHeight + (m_ButtonPadding * 2)));

	m_Text.setCharacterSize(160);

	initializeButtons();
}

void SelectUIPanel::initializeButtons()
{
	// Buttons are position relative to the top left courner of the UIPanel(m_View in UIPanel)
	addButton(
		m_ButtonPadding,
		m_ButtonPadding,
		m_ButtonWidth,
		m_ButtonHeight,
		0, 255, 0,
		"Play");

	addButton(
		m_ButtonWidth + (m_ButtonPadding * 2),
		m_ButtonPadding,
		m_ButtonWidth,
		m_ButtonHeight,
		255, 0, 0,
		"Quit");
}

void SelectUIPanel::draw(sf::RenderWindow& window)
{
	show();
	UIPanel::draw(window);
	window.draw(m_Text);
}