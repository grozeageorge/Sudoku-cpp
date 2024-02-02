#include "Singleton.h"

// initializing instancePtr with NULL
Singleton* Singleton::instancePtr = nullptr;

void Singleton::setTimer(int timer)
{
    this->timer = timer;
}

int Singleton::getTimer() const
{
    return timer;
}