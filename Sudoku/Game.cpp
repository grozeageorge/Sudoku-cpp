#include "Game.h"
#include "MainMenu.h"

Game::Game() : m_context(std::make_shared<Context>()) //initializez m_context cu un shared ptr cu make shared
{
	m_context->m_window->create(sf::VideoMode(640,360), "Sudoku", sf::Style::Close); //creaza fereastra -> close pt a nu fi maximizata
    m_context->m_states->add(std::make_unique<MainMenu>(m_context));  //adaug primul state -> Main_Menu
}

void Game::run()
{
    sf::Clock clock; //pt a rula blocat la 60 fps
    sf::Time timeSinceLastFrame = sf::Time::Zero;

    while (m_context->m_window->isOpen())
    {
        timeSinceLastFrame += clock.restart(); //incepe de la 0

        while (timeSinceLastFrame > timePerFrame) //daca ajunge la 61 fps
        {
            timeSinceLastFrame -= timePerFrame; //se reduce la 0 

            m_context->m_states->processStateChange(); //pt a schimba state-ul inainte de update
            m_context->m_states->getCurrent()->proccesInput(); //aducem state-ul curent
            m_context->m_states->getCurrent()->update(timePerFrame); //update the state
            m_context->m_states->getCurrent()->draw(); //pt a afisa text/sprite
        }
    }
}