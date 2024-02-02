#include "HelpMenu.h"
#include "MainMenu.h"

HelpMenu::HelpMenu(std::shared_ptr<Context>& context) : m_context(context), m_isBackButtonPressed(false), m_isBackButtonSelected(false)
{

}

void HelpMenu::init()
{
	m_context->m_assets->addFont(mainFont, "Pacifico-Regular.ttf");
	//backButton
	m_backButton.setFont(m_context->m_assets->getFont(mainFont));
	m_backButton.setOrigin(m_backButton.getGlobalBounds().width / 2, m_backButton.getGlobalBounds().height / 2);
	m_backButton.setPosition(0.f,0.f);
	m_backButton.setFillColor(sf::Color::White);
	m_backButton.setString("Back");
	//How To Play
	m_howToPlay.setFont(m_context->m_assets->getFont(mainFont));
	m_howToPlay.setOrigin(m_howToPlay.getGlobalBounds().width / 2, m_howToPlay.getGlobalBounds().height / 2);
	m_howToPlay.setPosition(m_context->m_window->getSize().x / 2 - 100.f, m_context->m_window->getSize().y / 2 - 125.f);
	m_howToPlay.setFillColor(sf::Color::White);
	m_howToPlay.setString("How To Play");
	//helpText
	m_helpText.setFont(m_context->m_assets->getFont(mainFont));
	m_helpText.setOrigin(m_helpText.getGlobalBounds().width / 2, m_helpText.getGlobalBounds().height / 2);
	m_helpText.setFillColor(sf::Color::White);
	m_helpText.setString("The 9×9 squares must be filled in with numbers from 1-9.\n No repeated numbers in each line, horizontally or vertically.\n To challenge you more, there are 3×3 squares marked out in the grid.\n Each of these squares can't have any repeated numbers either.");
	int x = m_helpText.getGlobalBounds().width / 4;
	m_helpText.setCharacterSize(15);
	m_helpText.setPosition((m_context->m_window->getSize().x / 2) - x , m_context->m_window->getSize().y / 2 - 25.f);
}

bool mouseOverText(int x, int y, sf::Text text)
{
	if (text.getGlobalBounds().contains(x, y))
		return true;
	return false;
}

void HelpMenu::proccesInput()
{
	sf::Event event;
	while (m_context->m_window->pollEvent(event));
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			m_context->m_window->close();
			break;
		case sf::Event::MouseMoved:
			int x, y;
			x = event.mouseMove.x;
			y = event.mouseMove.y;
			if (mouseOverText(x, y, m_backButton) == true)
			{
				m_isBackButtonSelected = true;
			}
			else
			{
				m_isBackButtonSelected = false;
			}
		case sf::Event::MouseButtonPressed:
			x = event.mouseButton.x;
			y = event.mouseButton.y;
			if (mouseOverText(x, y, m_backButton) == true && sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				m_isBackButtonPressed = true;
			}
			else
			{
				m_isBackButtonPressed = false;
			}
			break;
		}
	}

}

void HelpMenu::update(sf::Time deltaTime)
{
	if (m_isBackButtonSelected == true)
	{
		m_backButton.setFillColor(sf::Color::Green);
	}
	else
	{
		m_backButton.setFillColor(sf::Color::White);
	}
	if (m_isBackButtonPressed == true)
	{
		m_context->m_states->add(std::make_unique<MainMenu>(m_context), true);
	}
}

void HelpMenu::draw()
{
	m_context->m_window->clear();
	m_context->m_window->draw(m_backButton);
	m_context->m_window->draw(m_howToPlay);
	m_context->m_window->draw(m_helpText);
	m_context->m_window->display();

}