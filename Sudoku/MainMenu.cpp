#include "MainMenu.h"
#include "Gameplay.h"
#include "HelpMenu.h"
#include "Leaderboard.h"

MainMenu::MainMenu(std::shared_ptr<Context>& context) : m_context(context), //initializez contextul
														m_isPlayButtonSelected(false), m_isPlayButtonPressed(false),
														m_isHelpButtonSelected(false), m_isHelpButtonPressed(false),
														m_isLeaderboardButtonSelected(false), m_isLeaderboardButtonPressed(false),
														m_isExitButtonSelected(false), m_isExitButtonPressed(false)

{

}

void MainMenu::init() //initializare font + textul care va aparea pe main menu
{
	m_context->m_assets->addFont(mainFont,"Pacifico-Regular.ttf");
	m_context->m_assets->addTexture(backGround, "Background.png", true);

	//Play Button
	m_playButton.setFont(m_context->m_assets->getFont(mainFont));
	m_playButton.setString("Play");
	m_playButton.setOrigin(m_playButton.getLocalBounds().width / 2, m_playButton.getLocalBounds().height / 2);
	m_playButton.setPosition(m_context->m_window->getSize().x / 2, m_context->m_window->getSize().y / 2 -25.f);
	m_playButton.setCharacterSize(20); //seteaza marimea textului -> default e 30
	//Help Button
	m_helpButton.setFont(m_context->m_assets->getFont(mainFont));
	m_helpButton.setString("Help");
	m_helpButton.setOrigin(m_helpButton.getLocalBounds().width / 2, m_helpButton.getLocalBounds().height / 2);
	m_helpButton.setPosition(m_context->m_window->getSize().x / 2, m_context->m_window->getSize().y / 2 + 25.f);
	m_helpButton.setCharacterSize(20);
	//Leaderboard Button
	m_leaderboardButton.setFont(m_context->m_assets->getFont(mainFont));
	m_leaderboardButton.setString("Leaderboard");
	m_leaderboardButton.setOrigin(m_leaderboardButton.getLocalBounds().width / 2, m_leaderboardButton.getLocalBounds().height / 2);
	m_leaderboardButton.setPosition(m_context->m_window->getSize().x / 2 + 25.f, m_context->m_window->getSize().y / 2 + 75.f);
	m_leaderboardButton.setCharacterSize(20);
	//ExitButton
	m_exitButton.setFont(m_context->m_assets->getFont(mainFont));
	m_exitButton.setString("Quit");
	m_exitButton.setOrigin(m_exitButton.getLocalBounds().width / 2, m_exitButton.getLocalBounds().height / 2);
	m_exitButton.setPosition(m_context->m_window->getSize().x / 2, m_context->m_window->getSize().y / 2 + 125.f);
	m_exitButton.setCharacterSize(20);
	//BackGround
	m_backGround.setTexture(m_context->m_assets->getTexture(backGround));
	m_backGround.setTextureRect(m_context->m_window->getViewport(m_context->m_window->getDefaultView()));
}

bool MainMenu::mouseOver(int x, int y, sf::Text text)
{
	if (text.getGlobalBounds().contains(x, y))
		return true;
	return false;
}

void MainMenu::changeSelected(std::string selected)
{
	if (selected == "m_isPlayButtonSelected")
	{
		m_isPlayButtonSelected = true;
		m_isHelpButtonSelected = false;
		m_isLeaderboardButtonSelected = false;
		m_isExitButtonSelected = false;
	}
	else if (selected == "m_isHelpButtonSelected")
	{
		m_isPlayButtonSelected = false;
		m_isHelpButtonSelected = true;
		m_isLeaderboardButtonSelected = false;
		m_isExitButtonSelected = false;
	}
	else if (selected == "m_isLeaderboardButtonSelected")
	{
		m_isPlayButtonSelected = false;
		m_isHelpButtonSelected = false;
		m_isLeaderboardButtonSelected = true;
		m_isExitButtonSelected = false;
	}
	else if (selected == "m_isExitButtonSelected")
	{
		m_isPlayButtonSelected = false;
		m_isHelpButtonSelected = false;
		m_isLeaderboardButtonSelected = false;
		m_isExitButtonSelected = true;
	}
}

void MainMenu::changePressed(std::string pressed)
{
	if (pressed == "m_isPlayButtonPressed")
	{
		m_isPlayButtonPressed = true;
		m_isHelpButtonPressed = false;
		m_isLeaderboardButtonPressed = false;
		m_isExitButtonPressed = false;
	}
	else if (pressed == "m_isHelpButtonPressed")
	{
		m_isPlayButtonPressed = false;
		m_isHelpButtonPressed = true;
		m_isLeaderboardButtonPressed = false;
		m_isExitButtonPressed = false;
	}
	else if (pressed == "m_isLeaderboardButtonPressed")
	{
		m_isPlayButtonPressed = false;
		m_isHelpButtonPressed = false;
		m_isLeaderboardButtonPressed = true;
		m_isExitButtonPressed = false;
	}
	else if (pressed == "m_isExitButtonPressed")
	{
		m_isPlayButtonPressed = false;
		m_isHelpButtonPressed = false;
		m_isLeaderboardButtonPressed = false;
		m_isExitButtonPressed = true;
	}
}

void MainMenu::proccesInput()
{
	sf::Event event;
	while (m_context->m_window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			m_context->m_window->close();
		}
		if (event.type == event.MouseMoved) //cand mouse-ul se misca
		{
			int x = event.mouseMove.x; //iau coordonatele mouse-ului
			int y = event.mouseMove.y;
			if (mouseOver(x, y, m_playButton) == true) //daca mouse-ul e deasupra textului, acesta devine selectat
			{
				changeSelected("m_isPlayButtonSelected");
			}
			else if (mouseOver(x, y, m_helpButton) == true)
			{
				changeSelected("m_isHelpButtonSelected");
			}
			else if (mouseOver(x, y, m_leaderboardButton) == true)
			{
				changeSelected("m_isLeaderboardButtonSelected");
			}
			else if (mouseOver(x, y, m_exitButton) == true)
			{
				changeSelected("m_isExitButtonSelected");
			}
			else if (mouseOver(x, y, m_playButton) == false && mouseOver(x, y, m_helpButton) == false && mouseOver(x, y, m_leaderboardButton) == false && mouseOver(x, y, m_exitButton) == false)
			{ //in caz ca nu e niciunul selectat
				m_isPlayButtonSelected = false;
				m_isHelpButtonSelected = false;
				m_isLeaderboardButtonSelected = false;
				m_isExitButtonSelected = false;
			}
		}
		if (event.type == event.MouseButtonPressed) //daca apas un buton al mouse-ului
		{
			int x = event.mouseButton.x; //iau pozitia mouse-ului
			int y = event.mouseButton.y;
			if (mouseOver(x, y, m_playButton) && (sf::Mouse::isButtonPressed(sf::Mouse::Left))) // daca mouse-ul e deasupra textului si butonul apasat e click stanga, acesta devine apasat
			{
				changePressed("m_isPlayButtonPressed");
			}
			if (mouseOver(x, y, m_helpButton) && (sf::Mouse::isButtonPressed(sf::Mouse::Left)))
			{
				changePressed("m_isHelpButtonPressed");
			}
			if (mouseOver(x, y, m_leaderboardButton) && (sf::Mouse::isButtonPressed(sf::Mouse::Left)))
			{
				changePressed("m_isLeaderboardButtonPressed");
			}
			if (mouseOver(x, y, m_exitButton) && (sf::Mouse::isButtonPressed(sf::Mouse::Left)))
			{
				changePressed("m_isExitButtonPressed");
			}
		}
	}
}

void MainMenu::update(sf::Time DeltaTime)
{
	if (m_isPlayButtonSelected == false && m_isExitButtonSelected == false && m_isHelpButtonSelected == false && m_isLeaderboardButtonSelected == false)
	{ //daca niciun buton nu e selectat toate au culoarea negru
		m_playButton.setFillColor(sf::Color::Black);
		m_helpButton.setFillColor(sf::Color::Black);
		m_leaderboardButton.setFillColor(sf::Color::Black);
		m_exitButton.setFillColor(sf::Color::Black);
	}
	if (m_isPlayButtonSelected == true) //daca butonul e selectat ii da highlight cu culoarea verde
	{
		m_playButton.setFillColor(sf::Color::Green);
	}
	if (m_isHelpButtonSelected == true)
	{
		m_helpButton.setFillColor(sf::Color::Green);
	}
	if (m_isLeaderboardButtonSelected == true)
	{
		m_leaderboardButton.setFillColor(sf::Color::Green);
	}
	if (m_isExitButtonSelected == true)
	{
		m_exitButton.setFillColor(sf::Color::Green);
	}

	if (m_isPlayButtonPressed) //daca butonul e apasat face actiunea butonului
	{
		m_context->m_states->add(std::make_unique<Gameplay>(m_context), true);
	}
	if (m_isHelpButtonPressed)
	{
		//to do help ui
		m_context->m_states->add(std::make_unique<HelpMenu>(m_context), true);
	}
	if (m_isLeaderboardButtonPressed)
	{
		// to do leaderboard ui
		m_context->m_states->add(std::make_unique<Leaderboard>(m_context), true);
	}
	if (m_isExitButtonPressed)
	{
		m_context->m_window->close();
	}
}

void MainMenu::draw() //arata textul din main menu
{
	m_context->m_window->clear();
	m_context->m_window->draw(m_backGround);
	m_context->m_window->draw(m_playButton);
	m_context->m_window->draw(m_helpButton);
	m_context->m_window->draw(m_leaderboardButton);
	m_context->m_window->draw(m_exitButton);
	m_context->m_window->display();
}