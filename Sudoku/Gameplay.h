#pragma once

#include <vector>

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Clock.hpp>
#include "SFML/Window/Event.hpp"
#include "SFML/System/InputStream.hpp"

#include "Singleton.h"
#include "State.h"
#include "Game.h"
#include "Timer.h"

class Gameplay : public engine::State
{
private:
	Singleton* singletonTimer;
	char m_keyChar;
	std::shared_ptr<Context> m_context;
	sf::Text m_time;
	sf::Text m_timerOnDisplay;
	sf::Sprite m_backGround;
	sf::Sprite m_square;
	
	Timer m_timer;

	sf::Text m_number;
	std::vector<std::vector<sf::Text>> m_numbers{
		{m_number,m_number,m_number,m_number,m_number,m_number,m_number,m_number,m_number},
		{m_number,m_number,m_number,m_number,m_number,m_number,m_number,m_number,m_number},
		{m_number,m_number,m_number,m_number,m_number,m_number,m_number,m_number,m_number},
		{m_number,m_number,m_number,m_number,m_number,m_number,m_number,m_number,m_number},
		{m_number,m_number,m_number,m_number,m_number,m_number,m_number,m_number,m_number},
		{m_number,m_number,m_number,m_number,m_number,m_number,m_number,m_number,m_number},
		{m_number,m_number,m_number,m_number,m_number,m_number,m_number,m_number,m_number},
		{m_number,m_number,m_number,m_number,m_number,m_number,m_number,m_number,m_number},
		{m_number,m_number,m_number,m_number,m_number,m_number,m_number,m_number,m_number}
	};

	std::vector<std::vector<sf::Sprite>> m_squares{
		{m_square,m_square,m_square,m_square,m_square,m_square,m_square,m_square,m_square},
		{m_square,m_square,m_square,m_square,m_square,m_square,m_square,m_square,m_square},
		{m_square,m_square,m_square,m_square,m_square,m_square,m_square,m_square,m_square},
		{m_square,m_square,m_square,m_square,m_square,m_square,m_square,m_square,m_square},
		{m_square,m_square,m_square,m_square,m_square,m_square,m_square,m_square,m_square},
		{m_square,m_square,m_square,m_square,m_square,m_square,m_square,m_square,m_square},
		{m_square,m_square,m_square,m_square,m_square,m_square,m_square,m_square,m_square},
		{m_square,m_square,m_square,m_square,m_square,m_square,m_square,m_square,m_square},
		{m_square,m_square,m_square,m_square,m_square,m_square,m_square,m_square,m_square}
	};
	std::vector<std::vector<bool>> m_isSquareSelected{
		{false,false,false,false,false,false,false,false,false},
		{false,false,false,false,false,false,false,false,false},
		{false,false,false,false,false,false,false,false,false},
		{false,false,false,false,false,false,false,false,false},
		{false,false,false,false,false,false,false,false,false},
		{false,false,false,false,false,false,false,false,false},
		{false,false,false,false,false,false,false,false,false},
		{false,false,false,false,false,false,false,false,false},
		{false,false,false,false,false,false,false,false,false}
	};
	std::vector<std::vector<bool>> m_isSquarePressed{
		{false,false,false,false,false,false,false,false,false},
		{false,false,false,false,false,false,false,false,false},
		{false,false,false,false,false,false,false,false,false},
		{false,false,false,false,false,false,false,false,false},
		{false,false,false,false,false,false,false,false,false},
		{false,false,false,false,false,false,false,false,false},
		{false,false,false,false,false,false,false,false,false},
		{false,false,false,false,false,false,false,false,false},
		{false,false,false,false,false,false,false,false,false}
	};

	bool m_isReleased;
	bool m_isEscapePressed;

public:

	Gameplay() = default;
	Gameplay(std::shared_ptr<Context>& context);
	~Gameplay() = default;

	void init() override;
	void proccesInput() override;
	void update(sf::Time deltaTime) override;
	void draw() override;
	
	void pause() override;
	void start() override;
};