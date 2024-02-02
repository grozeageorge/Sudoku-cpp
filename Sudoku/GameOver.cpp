#include "GameOver.h"
#include "Gameplay.h"
#include "SaveGame.h"

GameOver::GameOver(std::shared_ptr<Context>& context) : m_context(context), //initializez contextul
m_isRetryButtonSelected(false), m_isRetryButtonPressed(false),
m_isExitButtonSelected(false), m_isExitButtonPressed(false),
m_isSaveButtonSelected(false), m_isSaveButtonPressed(false)
{

}

void GameOver::init() //initializare font + textul care va aparea pe main menu
{
	m_context->m_assets->addFont(mainFont, "Pacifico-Regular.ttf");

	//Title
	m_gameOverTitle.setFont(m_context->m_assets->getFont(mainFont)); //pt a folosi Main_font
	m_gameOverTitle.setString("Game Over"); //textul care va aparea in meniu
	m_gameOverTitle.setOrigin(m_gameOverTitle.getLocalBounds().width / 2, m_gameOverTitle.getLocalBounds().height / 2); //pt a seta originea textuluo in mijloc
	m_gameOverTitle.setPosition(m_context->m_window->getSize().x / 2, m_context->m_window->getSize().y / 2 - 150.f); //pt a muta textul in mijloc in functie de marimea ferestrei
	//Play Button
	m_retryButton.setFont(m_context->m_assets->getFont(mainFont));
	m_retryButton.setString("Retry");
	m_retryButton.setOrigin(m_retryButton.getLocalBounds().width / 2, m_retryButton.getLocalBounds().height / 2);
	m_retryButton.setPosition(m_context->m_window->getSize().x / 2, m_context->m_window->getSize().y / 2 - 25.f);
	m_retryButton.setCharacterSize(20); //seteaza marimea textului -> default e 30
	//Save Time
	m_saveButton.setFont(m_context->m_assets->getFont(mainFont));
	m_saveButton.setString("Save Progress");
	m_saveButton.setOrigin(m_saveButton.getLocalBounds().width / 2, m_saveButton.getLocalBounds().height / 2);
	m_saveButton.setPosition(m_context->m_window->getSize().x / 2 + 25.f, m_context->m_window->getSize().y / 2 + 25.f);
	m_saveButton.setCharacterSize(20);
	//ExitButton
	m_exitButton.setFont(m_context->m_assets->getFont(mainFont));
	m_exitButton.setString("Quit");
	m_exitButton.setOrigin(m_exitButton.getLocalBounds().width / 2, m_exitButton.getLocalBounds().height / 2);
	m_exitButton.setPosition(m_context->m_window->getSize().x / 2, m_context->m_window->getSize().y / 2 + 75.f);
	m_exitButton.setCharacterSize(20);
}

bool GameOver::mouseOver(int x, int y, sf::Text text)
{
	if (text.getGlobalBounds().contains(x, y))
		return true;
	return false;
}


void GameOver::changeSelected(std::string selected)
{
	if (selected == "m_isRetryButtonSelected")
	{
		m_isRetryButtonSelected = true;
		m_isSaveButtonSelected = false;
		m_isExitButtonSelected = false;
	}
	else if (selected == "m_isExitButtonSelected")
	{
		m_isSaveButtonSelected = false;
		m_isRetryButtonSelected = false;
		m_isExitButtonSelected = true;
	}
	else if (selected == "m_isSaveButtonSelected")
	{
		m_isSaveButtonSelected = true;
		m_isRetryButtonSelected = false;
		m_isExitButtonSelected = false;
	}
}

void GameOver::changePressed(std::string pressed)
{
	if (pressed == "m_isRetryButtonPressed")
	{
		m_isRetryButtonPressed = true;
		m_isSaveButtonPressed = false;
		m_isExitButtonPressed = false;
	}
	else if (pressed == "m_isExitButtonPressed")
	{
		m_isRetryButtonPressed = false;
		m_isSaveButtonPressed = false;
		m_isExitButtonPressed = true;
	}
	else if (pressed == "m_isSaveButtonPressed")
	{
		m_isRetryButtonPressed = false;
		m_isSaveButtonPressed = true;
		m_isExitButtonPressed = false;
	}
}

void GameOver::proccesInput()
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
			if (mouseOver(x, y, m_retryButton) == true) //daca mouse-ul e deasupra textului, acesta devine selectat
			{
				changeSelected("m_isRetryButtonSelected");
			}
			else if (mouseOver(x, y, m_exitButton) == true)
			{
				changeSelected("m_isExitButtonSelected");
			}
			else if (mouseOver(x, y, m_saveButton) == true)
			{
				changeSelected("m_isSaveButtonSelected");
			}
			else if (mouseOver(x, y, m_retryButton) == false && mouseOver(x, y, m_exitButton) == false && mouseOver(x,y,m_saveButton) == false)
			{ //in caz ca nu e niciunul selectat
				m_isRetryButtonSelected = false;
				m_isExitButtonSelected = false;
				m_isSaveButtonSelected = false;
			}
		}
		if (event.type == event.MouseButtonPressed) //daca apas un buton al mouse-ului
		{
			int x = event.mouseButton.x; //iau pozitia mouse-ului
			int y = event.mouseButton.y;
			if (mouseOver(x, y, m_retryButton) && (sf::Mouse::isButtonPressed(sf::Mouse::Left))) // daca mouse-ul e deasupra textului si butonul apasat e click stanga, acesta devine apasat
			{
				changePressed("m_isRetryButtonPressed");
			}
			else if (mouseOver(x, y, m_exitButton) && (sf::Mouse::isButtonPressed(sf::Mouse::Left)))
			{
				changePressed("m_isExitButtonPressed");
			}
			else if (mouseOver(x, y, m_saveButton) && (sf::Mouse::isButtonPressed(sf::Mouse::Left)))
			{
				changePressed("m_isSaveButtonPressed");
			}
			else if (mouseOver(x, y, m_retryButton) == false && mouseOver(x, y, m_exitButton) == false && mouseOver(x, y, m_saveButton) == false)
			{
				m_isRetryButtonPressed == false;
				m_isExitButtonPressed == false;
				m_isSaveButtonPressed == false;
			}
		}
	}
}

void GameOver::update(sf::Time DeltaTime)
{
	m_gameOverTitle.setFillColor(sf::Color::Black);
	if (m_isRetryButtonSelected == false && m_isExitButtonSelected == false)
	{ //daca niciun buton nu e selectat toate au culoarea negru
		m_retryButton.setFillColor(sf::Color::Black);
		m_exitButton.setFillColor(sf::Color::Black);
		m_saveButton.setFillColor(sf::Color::Black);
	}
	if (m_isRetryButtonSelected == true) //daca butonul e selectat ii da highlight cu culoarea verde
	{
		m_retryButton.setFillColor(sf::Color::Green);
	}
	if (m_isExitButtonSelected == true)
	{
		m_exitButton.setFillColor(sf::Color::Green);
	}
	if (m_isSaveButtonSelected == true)
	{
		m_saveButton.setFillColor(sf::Color::Green);
	}
	if (m_isRetryButtonPressed) //daca butonul e apasat face actiunea butonului
	{
		m_context->m_states->add(std::make_unique<Gameplay>(m_context), true);
	}
	if (m_isSaveButtonPressed)
	{
		m_context->m_states->add(std::make_unique<SaveGame>(m_context), true);
	}
	if (m_isExitButtonPressed)
	{
		m_context->m_window->close();
	}
}

void GameOver::draw() //arata textul din main menu
{
	m_context->m_window->clear(sf::Color::Blue);
	m_context->m_window->draw(m_gameOverTitle);
	m_context->m_window->draw(m_retryButton);
	m_context->m_window->draw(m_saveButton);
	m_context->m_window->draw(m_exitButton);
	m_context->m_window->display();
}