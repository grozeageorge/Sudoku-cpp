#include "Leaderboard.h"
#include "MainMenu.h"

Leaderboard::Leaderboard(std::shared_ptr<Context>& context) : m_context(context), m_isBackButtonSelected(false), m_isBackButtonPressed(false)
{

}

bool is_empty(std::ifstream& pFile)
{
	return pFile.peek() == std::ifstream::traits_type::eof();
}

void Leaderboard::init()
{
	m_context->m_assets->addFont(mainFont, "Pacifico-Regular.ttf");

	m_backButton.setFont(m_context->m_assets->getFont(mainFont));
	m_backButton.setOrigin(m_backButton.getGlobalBounds().width / 2, m_backButton.getGlobalBounds().height / 2);
	m_backButton.setPosition(0.f, 0.f);
	m_backButton.setFillColor(sf::Color::White);
	m_backButton.setString("Back");

	m_leaderboard.setFont(m_context->m_assets->getFont(mainFont));
	m_leaderboard.setOrigin(m_leaderboard.getGlobalBounds().height / 2, m_leaderboard.getGlobalBounds().width / 2);
	m_leaderboard.setPosition(m_context->m_window->getSize().x * 2 / 5, m_context->m_window->getSize().y);
	m_leaderboard.setFillColor(sf::Color::Green);
	m_leaderboard.setString("");
	m_leaderboard.setCharacterSize(20);

	std::ifstream g("Leaderboard.txt");

	if (is_empty(g))
	{
		std::string emptyFile = "No scores saved";
		m_leaderboard.setString(emptyFile);
	}
	else
	{
		std::string readFromFile;
		while (getline(g, readFromFile))
		{
			m_leaderboard.setString(m_leaderboard.getString() + readFromFile + '\n');
		}
	}
}

bool Leaderboard::mouseOverText(int x, int y, sf::Text text)
{
	if (text.getGlobalBounds().contains(x, y))
		return true;
	return false;
}


void Leaderboard::proccesInput()
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

void Leaderboard::update(sf::Time deltaTime)
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

	const int scrollSpeed = -1;
	m_leaderboard.move(0, scrollSpeed);
}

void Leaderboard::draw()
{
	m_context->m_window->clear();
	m_context->m_window->draw(m_backButton);
	m_context->m_window->draw(m_leaderboard);
	m_context->m_window->display();
}