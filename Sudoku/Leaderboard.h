#pragma once

#include "SFML/Window/Event.hpp"

#include <fstream>

#include "State.h"
#include "Game.h"

class Leaderboard : public engine::State
{
private:
	std::shared_ptr<Context> m_context;
	sf::Text m_backButton;
	sf::Text m_leaderboard;

	bool m_isBackButtonSelected;
	bool m_isBackButtonPressed;

public:
	Leaderboard(std::shared_ptr<Context>& context);
	~Leaderboard() = default;

	bool mouseOverText(int x, int y, sf::Text text);

	void init() override;
	void proccesInput() override;
	void update(sf::Time deltaTime) override;
	void draw() override;
};