#include "Timer.h"

Timer::Timer()
{
	bPaused = false;
	runTime = 0;
	mC.restart();
}

void Timer::Reset() 
{
	mC.restart();
	runTime = 0;
	bPaused = false;
}

void Timer::Start() 
{
	if (bPaused) {
		mC.restart();
	}
	bPaused = false;
}

void Timer::Pause() 
{
	if (!bPaused) {
		runTime += mC.getElapsedTime().asSeconds();
	}
	bPaused = true;
}

float Timer::GetElapsedSeconds() 
{
	if (!bPaused) {
		return runTime + mC.getElapsedTime().asSeconds();
	}
	return runTime;
}
