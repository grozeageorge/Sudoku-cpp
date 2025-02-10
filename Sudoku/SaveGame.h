#pragma once

#include <fstream>

#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "SFML/Window/Event.hpp"

#include "State.h"
#include "Game.h"
#include "Singleton.h"

class SaveGame : public engine::State
{
private:
	float m_position;
	int m_timeSeconds;
	std::shared_ptr<Context> m_context;
	sf::Text m_insertName;
	std::string m_input;
	sf::Text m_output;
	sf::Text m_saveButton;
	sf::Text m_timeToSave;
	sf::Sprite m_textbox;

	bool m_isTextboxPressed;
	bool m_isSaveButtonPressed;

public:
	SaveGame(std::shared_ptr<Context>& context);
	~SaveGame() = default;

	void init() override;
	void proccesInput() override;
	void update(sf::Time deltaTime) override;
	void draw() override;

	bool mouseOverSprite(int x, int y, sf::Sprite sprite);
	bool mouseOverText(int x, int y, sf::Text text);
};