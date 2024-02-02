#pragma once

class Singleton {
private:
    int timer;

    static Singleton* instancePtr;
    Singleton()
    {
    }
public:

    // deleting copy constructor
    Singleton(const Singleton& obj) = delete;

    static Singleton* getInstance()
    {
        if (instancePtr == nullptr)
        {
            instancePtr = new Singleton();
            return instancePtr;
        }
        else
        {
            return instancePtr;
        }
    }

    void setTimer(int timer);
    int getTimer() const;
};