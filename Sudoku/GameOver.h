#pragma once

#include <memory>

#include "SFML/Window/Event.hpp"
#include <SFML/Graphics/Text.hpp>

#include "State.h"
#include "Game.h"

class GameOver : public engine::State  //clasa derivata din state
{
private:
	std::shared_ptr<Context> m_context;
	sf::Text m_gameOverTitle; //butoanele din main_menu
	sf::Text m_retryButton;
	sf::Text m_exitButton;
	sf::Text m_saveButton;

	bool m_isRetryButtonSelected; // functii pt a determina daca butonul e selectat/apasat
	bool m_isRetryButtonPressed;

	bool m_isSaveButtonSelected;
	bool m_isSaveButtonPressed;

	bool m_isExitButtonSelected;
	bool m_isExitButtonPressed;

public:
	GameOver(std::shared_ptr<Context>& Context); //pt a nu crea fara context
	~GameOver() = default;

	void init() override; //override la functiile virtuale pure din state.h
	void proccesInput() override;
	void update(sf::Time deltaTime) override;
	void draw() override;

	void changeSelected(std::string selected);
	void changePressed(std::string pressed);

	bool mouseOver(int x, int y, sf::Text text);
};