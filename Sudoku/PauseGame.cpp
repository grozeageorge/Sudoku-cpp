#include "PauseGame.h"
#include "MainMenu.h"

PauseGame::PauseGame(std::shared_ptr<Context>& context) : m_context(context)
{

}

void PauseGame::init()
{
	m_context->m_assets->addFont(mainFont, "Pacifico-Regular.ttf");

	//Title
	m_pauseTitle.setFont(m_context->m_assets->getFont(mainFont));
	m_pauseTitle.setString("Paused");
	m_pauseTitle.setOrigin(m_pauseTitle.getLocalBounds().width / 2, m_pauseTitle.getLocalBounds().height / 2);
	m_pauseTitle.setPosition(m_context->m_window->getSize().x / 2, m_context->m_window->getSize().y / 2 - 25.f);
	m_pauseTitle.setCharacterSize(50);
}

bool PauseGame::mouseOver(int x, int y, sf::Text text)
{
	if (text.getGlobalBounds().contains(x, y))
		return true;
	return false;
}

void PauseGame::proccesInput()
{
	sf::Event event;
	while (m_context->m_window->pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
		{
			m_context->m_window->close();
			break;
		}
		case sf::Event::KeyPressed:
		{
			if (event.key.code == sf::Keyboard::Escape)
				m_context->m_states->popCurrent();
			break;
		}
		}
	}
}



void PauseGame::update(sf::Time deltaTime)
{
	m_pauseTitle.setFillColor(sf::Color::Black);
}

void PauseGame::draw()
{
	m_context->m_window->draw(m_pauseTitle);
	m_context->m_window->display();
}