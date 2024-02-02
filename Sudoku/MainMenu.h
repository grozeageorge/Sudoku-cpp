#pragma once

#include "SFML/Window/Event.hpp"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>

#include "State.h"
#include "Game.h"

class MainMenu : public engine::State  //clasa derivata din state
{
private:
	std::shared_ptr<Context> m_context;
	sf::Text m_gameTitle; //butoanele din main_menu
	sf::Text m_playButton;
	sf::Text m_exitButton;
	sf::Text m_helpButton;
	sf::Text m_leaderboardButton;
	sf::Sprite m_backGround;

	bool m_isPlayButtonSelected; // functii pt a determina daca butonul e selectat/apasat
	bool m_isPlayButtonPressed;

	bool m_isHelpButtonSelected;
	bool m_isHelpButtonPressed;

	bool m_isLeaderboardButtonSelected;
	bool m_isLeaderboardButtonPressed;

	bool m_isExitButtonSelected;
	bool m_isExitButtonPressed;

public:
	MainMenu(std::shared_ptr<Context>& Context); //pt a nu crea fara context
	~MainMenu() = default;

	void init() override; //override la functiile virtuale pure din state.h
	void proccesInput() override;
	void update(sf::Time deltaTime) override;
	void draw() override;

	void changeSelected(std::string selected);
	void changePressed(std::string pressed);

	bool mouseOver(int x, int y, sf::Text text);
};