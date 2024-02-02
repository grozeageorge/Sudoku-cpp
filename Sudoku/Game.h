#pragma once

#include <memory>

#include <SFML/Graphics/RenderWindow.hpp>

#include "MainAsset.h"
#include "MainState.h"

enum AssetID //pt a face diferenta intre fonturi/texturi
{
	mainFont = 0,
	backGround,
	square,
	squareSelected
};

struct Context //pt a retine state-uri, asset-uri si window-ul in care ruleaza jocul 
{
	std::unique_ptr<engine::MainAsset> m_assets;
	std::unique_ptr<engine::MainState> m_states;
	std::unique_ptr<sf::RenderWindow> m_window;

	Context()
	{
		m_assets = std::make_unique<engine::MainAsset>();
		m_states = std::make_unique<engine::MainState>();
		m_window = std::make_unique<sf::RenderWindow>();
	}
};

class Game
{
private:
	std::shared_ptr<Context> m_context; //shared pt ca context e comun pt toate state-urile 
	const sf::Time timePerFrame = sf::seconds(1.f / 60.f); //60 fps
public:
	Game();
	~Game() = default;

	void run(); //functie pt a rula jocul
};