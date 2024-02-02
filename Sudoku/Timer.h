#pragma once

#include "SFML/System/Clock.hpp"

class Timer
{
public:
	sf::Clock mC;
	float runTime;
	bool bPaused;

	Timer();
	void Reset();
	void Start();
	void Pause();
	float GetElapsedSeconds();
};