#include "SaveGame.h"
#include "MainMenu.h"
#include "Gameplay.h"

SaveGame::SaveGame(std::shared_ptr<Context>& context) : m_context(context), m_isTextboxPressed(false), m_isSaveButtonPressed(false), m_position(0.f), m_timeSeconds(0)
{
	
}

void SaveGame::init()
{

	m_context->m_assets->addFont(mainFont, "Pacifico-Regular.ttf");
	m_context->m_assets->addTexture(square, "square.png", true);

	m_insertName.setFont(m_context->m_assets->getFont(mainFont));
	m_insertName.setString("Insert your name below:");
	m_insertName.setFillColor(sf::Color::Green);
	m_insertName.setOrigin(m_insertName.getLocalBounds().width / 2, m_insertName.getLocalBounds().height / 2);
	m_insertName.setPosition(m_context->m_window->getSize().x / 2, m_context->m_window->getSize().y / 2 - 125.f);

	m_timeToSave.setFont(m_context->m_assets->getFont(mainFont));
	m_timeToSave.setFillColor(sf::Color::Green);
	m_timeToSave.setOrigin(m_timeToSave.getLocalBounds().width / 2, m_timeToSave.getLocalBounds().height / 2);
	m_timeToSave.setPosition(m_context->m_window->getSize().x / 2, m_context->m_window->getSize().y / 2 - 75.f);
	Singleton* singletonTimer = Singleton::getInstance();
	m_timeSeconds = singletonTimer->getTimer();
	m_timeToSave.setString(std::to_string(m_timeSeconds));

	m_textbox.setTexture(m_context->m_assets->getTexture(square));
	m_textbox.setOrigin(m_textbox.getLocalBounds().width / 2, m_textbox.getLocalBounds().height / 2);
	m_textbox.setPosition(m_context->m_window->getSize().x / 2, m_context->m_window->getSize().y / 2 + 25.f);
	m_textbox.setScale(18, 3);
	m_textbox.setTextureRect({ 16,16,16,16 });

	m_output.setFont(m_context->m_assets->getFont(mainFont));
	m_output.setFillColor(sf::Color::Green);
	m_output.setOrigin(m_output.getLocalBounds().width / 2, m_output.getLocalBounds().height / 2);
	m_output.setPosition(m_context->m_window->getSize().x / 2 - 10.f, m_context->m_window->getSize().y / 2 + 10.f);

	m_saveButton.setFont(m_context->m_assets->getFont(mainFont));
	m_saveButton.setFillColor(sf::Color::Green);
	m_saveButton.setString("Save");
	m_saveButton.setOrigin(m_saveButton.getLocalBounds().width / 2, m_saveButton.getLocalBounds().height / 2);
	m_saveButton.setPosition(m_context->m_window->getSize().x / 2, m_context->m_window->getSize().y / 2 + 75.f);
}

bool SaveGame::mouseOverSprite(int x, int y, sf::Sprite square)
{
	if (square.getGlobalBounds().contains(x, y))
		return true;
	return false;
}

bool SaveGame::mouseOverText(int x, int y, sf::Text text)
{
	if (text.getGlobalBounds().contains(x, y))
		return true;
	return false;
}

void SaveGame::proccesInput()
{
	sf::Event event;
	while (m_context->m_window->pollEvent(event));
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			m_context->m_window->close();
			break;
		case sf::Event::MouseButtonPressed:
			int x, y;
			x = event.mouseButton.x;
			y = event.mouseButton.y;
			if (mouseOverSprite(x, y, m_textbox) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				m_isTextboxPressed = true;
			}
			else
			{
				m_isTextboxPressed = false;
			}
			if (mouseOverText(x, y, m_saveButton) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				m_isSaveButtonPressed = true;
			}
			else
			{
				m_isSaveButtonPressed = false;
			}
			break;
		case sf::Event::TextEntered:
		{
			int x = m_textbox.getGlobalBounds().width - 60.f;
			if (!m_input.empty() && event.key.code == 8 && m_isTextboxPressed == true)
			{
				m_input.pop_back();
				m_position -= 7, 5.f;
				m_output.setPosition(m_context->m_window->getSize().x / 2 - m_position, m_context->m_window->getSize().y / 2 + 10.f);
			}
			else if (event.text.unicode < 128 && event.text.unicode != 8 && m_isTextboxPressed == true && m_output.getGlobalBounds().width < x)
			{
				m_input += event.text.unicode;
				m_position += 7, 5.f;
				m_output.setPosition(m_context->m_window->getSize().x / 2 - m_position, m_context->m_window->getSize().y / 2 + 10.f);
			}
			break;
		}
		default:
			break;
		}
	}
}

void SaveGame::update(sf::Time deltaTime)
{
	if (m_isTextboxPressed == true)
	{
		m_output.setString(m_input);
		m_output.setFillColor(sf::Color::Green);
	}
	std::ofstream f("Leaderboard.txt", std::ios_base::app);
	if (m_isSaveButtonPressed == true && !m_input.empty())
	{
		std::string x = m_output.getString();
		f << x << " with the time: " << m_timeSeconds << " seconds" << '\n';
		m_context->m_states->add(std::make_unique<MainMenu>(m_context), true);
	}
}

void SaveGame::draw()
{
	m_context->m_window->clear();
	m_context->m_window->draw(m_insertName);
	m_context->m_window->draw(m_timeToSave);
	m_context->m_window->draw(m_textbox);
	m_context->m_window->draw(m_saveButton);
	m_context->m_window->draw(m_output);
	m_context->m_window->display();
}