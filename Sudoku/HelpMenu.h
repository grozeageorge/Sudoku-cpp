#pragma once

#include <SFML/Window/Event.hpp>

#include "State.h"
#include "Game.h"

class HelpMenu : public engine::State
{
private:
	std::shared_ptr<Context> m_context;
	sf::Text m_backButton;
	sf::Text m_howToPlay;
	sf::Text m_helpText;

	bool m_isBackButtonPressed;
	bool m_isBackButtonSelected;

public:
	HelpMenu(std::shared_ptr<Context>& context);
	~HelpMenu() = default;

	void init() override; // set up sprites/text and their position
	void proccesInput() override; // procces click arrow
	void update(sf::Time deltaTime) override; //same fps on every machine
	void draw() override; //draw image/sprites/text on render window
};