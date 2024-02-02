#include "MainState.h"


engine::MainState::MainState() : m_add(false), m_replace(false), m_remove(false)
{

}

void engine::MainState::add(std::unique_ptr<State> toAdd, bool replace)
{
	m_add = true; //arata faptul ca trb adaugat un nou state
	m_newState = std::move(toAdd); //mutare state cu unique ptr

	m_replace = replace; //acesta arata daca trebuie replaced sau nu
}

void engine::MainState::popCurrent()
{
	m_remove = true; //arata ca state-ul curent trebuie sters din stack
}

void engine::MainState::processStateChange()
{
	if (m_remove && (!m_stateStack.empty())) //daca trebuie sa sterg state-ul curent si stack nu e gol
	{
		m_stateStack.pop(); //sterg state-ul

		if (!m_stateStack.empty()) //daca stack-ul nu e gol
		{
			m_stateStack.top()->start(); // porneste urmatorul state
		}

		m_remove = false; // readuc m_remove la valoarea default
	}

	if (m_add) //daca trebuie sa adaug un state
	{
		if (m_replace && (!m_stateStack.empty())) //daca trebuie sa inlocuiesc state-ul curent si stack nu e gol
		{
			m_stateStack.pop(); //sterg state-ul curent
			m_replace = false; //readuc m_replace la valoarea default
		}

		if (!m_stateStack.empty()) //daca stack-ul nu e gol
		{
			m_stateStack.top()->pause(); //state-ul curent se pune pe pauza
		}

		m_stateStack.push(std::move(m_newState)); //adauga state-ul nou in stack
		m_stateStack.top()->init(); //se initializeaza state-ul din varful stack-ului
		m_stateStack.top()->start(); //incepe state-ul din varf
		m_add = false; //readuc m_add la val default
	}
	
}

std::unique_ptr<engine::State>& engine::MainState::getCurrent()
{
	return m_stateStack.top(); //returneaza state-ul curent
}