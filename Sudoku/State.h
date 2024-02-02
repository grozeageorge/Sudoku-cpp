#pragma once

#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Text.hpp>

namespace engine
{
	class State
	{
	public:
		State(){};
		virtual ~State(){}; // abstract base class -> virtual destructor

		virtual void init() = 0; // set up sprites/text and their position
		virtual void proccesInput() = 0; // procces click arrow
		virtual void update(sf::Time deltaTime) = 0; //same fps on every machine
		virtual void draw() = 0; //draw image/sprites/text on render window

		virtual void pause(){}; //pause game -> state
		virtual void start(){}; //start/resume game -> state
	};
}