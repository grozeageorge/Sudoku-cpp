#include "Gameplay.h"
#include "GameOver.h"
#include "PauseGame.h"

Gameplay::Gameplay(std::shared_ptr<Context>& context) : m_context(context), m_keyChar(' '), m_isReleased(false), m_isEscapePressed(false)
{
	singletonTimer = Singleton::getInstance();
}

void setLevel1(std::vector<std::vector<sf::Text>>& m_numbers)
{
	// set level 1 easy 
	//linia 1
	m_numbers[0][2].setString('2');
	m_numbers[0][3].setString('1');
	m_numbers[0][5].setString('4');
	m_numbers[0][8].setString('6');
	//linia 2
	m_numbers[1][0].setString('6');
	m_numbers[1][4].setString('2');
	m_numbers[1][5].setString('7');
	m_numbers[1][7].setString('5');
	m_numbers[1][8].setString('9');
	//linia 3
	m_numbers[2][1].setString('5');
	m_numbers[2][3].setString('3');
	m_numbers[2][4].setString('9');
	m_numbers[2][5].setString('6');
	m_numbers[2][6].setString('7');
	m_numbers[2][8].setString('4');
	//linia 4
	m_numbers[3][1].setString('6');
	m_numbers[3][7].setString('4');
	m_numbers[3][8].setString('1');
	//linia 5
	m_numbers[4][1].setString('8');
	m_numbers[4][2].setString('9');
	m_numbers[4][5].setString('1');
	//linia 6
	m_numbers[5][0].setString('3');
	m_numbers[5][2].setString('7');
	m_numbers[5][3].setString('4');
	m_numbers[5][4].setString('8');
	m_numbers[5][6].setString('9');
	//linia 7
	m_numbers[6][1].setString('3');
	m_numbers[6][2].setString('6');
	m_numbers[6][3].setString('7');
	m_numbers[6][6].setString('5');
	m_numbers[6][7].setString('9');
	//linia 8
	m_numbers[7][1].setString('7');
	m_numbers[7][3].setString('2');
	m_numbers[7][5].setString('5');
	m_numbers[7][7].setString('3');
	m_numbers[7][8].setString('8');
	//linia 9
	m_numbers[8][4].setString('3');
	m_numbers[8][7].setString('1');
}

bool checkLevel(std::vector<std::vector<sf::Text>>& m_numbers)
{
	bool unique[10];
	for (int i = 0; i < 9; i++)
	{
		memset(unique, false, sizeof(unique));
		for (int j = 0; j < 9; j++)
		{
			if (m_numbers[i][j].getString() != ' ')
			{
				std::string x = m_numbers[i][j].getString();
				int y = stoi(x);
				if (unique[y])
					return false;
				unique[y] = true;
			}
			else
				return false;
		}
	}
	for (int i = 0; i < 9; i++)
	{
		memset(unique, false, sizeof(unique));
		for (int j = 0; j < 9; j++)
		{
			if (m_numbers[j][i].getString() != ' ')
			{
				std::string x = m_numbers[j][i].getString();
				int y = stoi(x);
				if (unique[y])
					return false;
				unique[y] = true;
			}
			else
				return false;
		}
	}
	for (int i = 0; i < 7; i += 3)
	{
		for (int j = 0; j < 7; j += 3)
		{
			memset(unique, false, sizeof(unique));
			for (int k = 0; k < 3; k++)
			{
				for (int l = 0; l < 3; l++)
				{
					int x = i + k;
					int y = j + l;
					if (m_numbers[x][y].getString() != ' ')
					{
						std::string a = m_numbers[x][y].getString();
						int b = stoi(a);
						if (unique[b])
							return false;
						unique[b] = true;
					}
					else
						return false;
				}
			}
		}
	}
	return true;
}


bool notBanned(int i, int j)
{
	if (i == 0 && (j == 2 || j == 3 || j == 5 || j == 8))
		return false;
	if (i == 1 && (j == 0 || j == 4 || j == 5 || j == 7 || j == 8))
		return false;
	if (i == 2 && (j == 1 || j == 3 || j == 4 || j == 5 || j == 6 || j == 8))
		return false;
	if (i == 3 && (j == 1 || j == 7 || j == 8))
		return false;
	if (i == 4 && (j == 1 || j == 2 || j == 5))
		return false;
	if (i == 5 && (j == 0 || j == 2 || j == 3 || j == 4 || j == 6))
		return false;
	if (i == 6 && (j == 1 || j == 2 || j == 3 || j == 6 || j == 7))
		return false;
	if (i == 7 && (j == 1 || j == 3 || j == 5 || j == 7 || j == 8))
		return false;
	if (i == 8 && (j == 4 || j == 7))
		return false;
	return true;
}

void Gameplay::init()
{
	m_timer.Reset();
	m_timer.Pause();
	
	m_context->m_assets->addTexture(backGround, "backGroundGame.png", true);
	m_context->m_assets->addTexture(square, "square.png", true);
	m_context->m_assets->addTexture(squareSelected, "squareSelected.png", true);
	m_context->m_assets->addFont(mainFont, "Pacifico-Regular.ttf");

	m_timerOnDisplay.setFont(m_context->m_assets->getFont(mainFont));
	m_timerOnDisplay.setFillColor(sf::Color::Black);
	m_timerOnDisplay.setOrigin(m_time.getGlobalBounds().width / 2, m_time.getGlobalBounds().height / 2);
	m_timerOnDisplay.setPosition(m_context->m_window->getSize().x / 2 + 165.f, m_context->m_window->getSize().y / 2 - 75.f);

	m_time.setFont(m_context->m_assets->getFont(mainFont));
	m_time.setString("Timer");
	m_time.setFillColor(sf::Color::Black);
	m_time.setOrigin(m_time.getGlobalBounds().width / 2, m_time.getGlobalBounds().height / 2);
	m_time.setPosition(m_context->m_window->getSize().x / 2 + 175.f, m_context->m_window->getSize().y / 2 - 100.f);

	m_backGround.setTexture(m_context->m_assets->getTexture(backGround));
	m_backGround.setTextureRect(m_context->m_window->getViewport(m_context->m_window->getDefaultView()));

	int x, y;
	x = m_context->m_window->getSize().x / 8, y = m_context->m_window->getSize().y / 8;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			m_squares[i][j].setTexture(m_context->m_assets->getTexture(square));
			m_squares[i][j].setOrigin(m_squares[i][j].getLocalBounds().width / 2, m_squares[i][j].getLocalBounds().height / 2);
			m_squares[i][j].setPosition(x, y);
			m_squares[i][j].setScale(2, 2);
			m_squares[i][j].setTextureRect({ 16,16,16,16 });
			x += 31, 5.f;
		}
		x = m_context->m_window->getSize().x / 8;
		y += 32.f;
	}

	x = m_context->m_window->getSize().x / 8 - 10.f; y = m_context->m_window->getSize().y / 16;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			m_numbers[i][j].setFont(m_context->m_assets->getFont(mainFont));
			m_numbers[i][j].setString(" ");
			m_numbers[i][j].setFillColor(sf::Color::Black);
			m_numbers[i][j].setOrigin(m_numbers[i][j].getLocalBounds().width / 2, m_numbers[i][j].getLocalBounds().height / 2);
			m_numbers[i][j].setPosition(x, y);
			m_numbers[i][j].setCharacterSize(35);
			x += 31, 5.f;
		}
		x = m_context->m_window->getSize().x / 8 - 5.f;
		y += 32.f;
	}

	setLevel1(m_numbers);
}

bool mouseOver(int x, int y, sf::Sprite square)
{
	if (square.getGlobalBounds().contains(x, y))
		return true;
	return false;
}

void Gameplay::proccesInput()
{
	sf::Event event;
	while (m_context->m_window->pollEvent(event))
	{
		int x = event.mouseMove.x;
		int y = event.mouseMove.y;
		int xb = event.mouseButton.x;
		int yb = event.mouseButton.y;

		switch (event.type) {
		case sf::Event::Closed:
			m_context->m_window->close();
			break;
		case sf::Event::MouseMoved:
		{
			for (int i = 0; i < 9; i++)
			{
				for (int j = 0; j < 9; j++)
				{
					if (mouseOver(x, y, m_squares[i][j]))
					{
						m_isSquareSelected[i][j] = true;
					}
					else if (!mouseOver(x, y, m_squares[i][j]))
					{
						m_isSquareSelected[i][j] = false;
					}
				}
			}
			break;
		}
		case sf::Event::MouseButtonPressed:
		{
			for (int i = 0; i < 9; i++)
			{
				for (int j = 0; j < 9; j++)
				{
					if (mouseOver(xb, yb, m_squares[i][j]) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
					{
						m_isSquarePressed[i][j] = true;
					}
					else
					{
						m_isSquarePressed[i][j] = false;
					}
				}
			}
			break;
		}
		case sf::Event::MouseButtonReleased:
		{
			for (int i = 0; i < 9; i++)
			{
				for (int j = 0; j < 9; j++)
				{
					if (m_isSquarePressed[i][j] == true && event.key.code == sf::Mouse::Left && mouseOver(xb, yb, m_squares[i][j]))
					{
						// The box has been selected
						// Toggle the boolean
						m_isReleased = true;
					}
					else
					{
						m_isReleased = false;
					}
				}
			}
			break;
		}
		case sf::Event::TextEntered:
		{
			if (event.text.unicode > 48 && event.text.unicode < 58) // between 0 and 10
			{
				// Here is the character that was typed
				m_keyChar = (char)event.text.unicode;
			}
			break;
		}
		case sf::Event::KeyPressed:
		{
			if (event.key.code == sf::Keyboard::Escape)
			{
				m_isEscapePressed = true;
			}
			break;
		}
		}
	}
}

void Gameplay::update(sf::Time deltaTime)
{
	m_timer.Start();
	int seconds = m_timer.GetElapsedSeconds();
	m_timerOnDisplay.setString(std::to_string(seconds));
	if (seconds > 9)
		m_timerOnDisplay.setPosition(m_context->m_window->getSize().x / 2 + 160.f, m_context->m_window->getSize().y / 2 - 75.f);
	if (seconds > 99)
		m_timerOnDisplay.setPosition(m_context->m_window->getSize().x / 2 + 155.f, m_context->m_window->getSize().y / 2 - 75.f);

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (m_isSquareSelected[i][j] == true && notBanned(i, j))
			{
				m_squares[i][j].setTexture(m_context->m_assets->getTexture(squareSelected));
			}
			else if (m_isSquareSelected[i][j] == false)
			{
				m_squares[i][j].setTexture(m_context->m_assets->getTexture(square));
			}
		}
	}

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (notBanned(i, j) && m_isSquarePressed[i][j] == true && m_isReleased == false)
			{
				m_numbers[i][j].setString(m_keyChar);
			}
		}
	}
	if (m_isEscapePressed == true)
	{
		m_context->m_states->add(std::make_unique<PauseGame>(m_context));
		m_isEscapePressed = false;
		m_timer.Pause();
	}
	if (checkLevel(m_numbers) || seconds == 10)
	{
		singletonTimer->setTimer(seconds);
		m_context->m_states->add(std::make_unique<GameOver>(m_context), true);
	}
}

void Gameplay::draw()
{
	m_context->m_window->clear();
	m_context->m_window->draw(m_backGround);
	m_time.setFont(m_context->m_assets->getFont(mainFont));
	m_context->m_window->draw(m_time);
	m_timerOnDisplay.setFont(m_context->m_assets->getFont(mainFont));
	m_context->m_window->draw(m_timerOnDisplay);

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			m_context->m_window->draw(m_squares[i][j]);
		}
	}

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			m_numbers[i][j].setFont(m_context->m_assets->getFont(mainFont));
			m_context->m_window->draw(m_numbers[i][j]);
		}
	}

	m_context->m_window->display();
}


void Gameplay::pause()
{

}

void Gameplay::start()
{

}
