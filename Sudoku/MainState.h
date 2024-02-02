#pragma once

#include <stack>
#include <memory>
#include "State.h"

namespace engine
{
	class MainState
	{
	private:
		std::stack<std::unique_ptr<State>> m_stateStack; //stack of states
		std::unique_ptr<State> m_newState; // se modifica doar la urmatorul update dupa ce se termina ultimul state

		bool m_add;
		bool m_replace;
		bool m_remove; //modificari la state stack depind de m_add m_replace m_remove 

	public:
		MainState(); 
		~MainState() = default;

		void add(std::unique_ptr<State> toADD, bool replace=false); //adaug alt state, fie peste, fie dupa;
		void popCurrent(); //sterg state-ul curent
		void processStateChange(); //proceses trecerea de la un state la altul, aici modific stack-ul
		std::unique_ptr<State>& getCurrent(); // state-ul curent
	};
}