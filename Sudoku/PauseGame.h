#pragma once

#include <SFML/Graphics/Text.hpp>
#include "SFML/Window/Event.hpp"

#include "State.h"
#include "Game.h"

class PauseGame : public engine::State
{
private:
	std::shared_ptr<Context> m_context;
	sf::Text m_pauseTitle;
	
public:

	PauseGame(std::shared_ptr<Context>& context);
	~PauseGame() = default;

	void init() override;
	void proccesInput() override;
	void update(sf::Time deltaTime) override;
	void draw() override;
	

	bool mouseOver(int x, int y, sf::Text text);
};