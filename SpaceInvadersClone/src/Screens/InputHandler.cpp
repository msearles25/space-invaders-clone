#include <sstream>
#include "InputHandler.h"

void InputHandler::initializeInputHandler(
	ScreenManagerRemoteControl* sw,
	std::vector<std::shared_ptr<Button>> buttons,
	sf::View* pointerToView,
	Screen* parentScreen)
{
	m_ScreenManagerRemoteControl = sw;
	m_Buttons = buttons;
	m_PointerToUIPanelView = pointerToView;
	m_ParentScreen = parentScreen;
}

void InputHandler::handleInput(sf::RenderWindow& window, sf::Event& event)
{

}