#pragma once
#include<SDL.h>
#include"TimeManager.h"

#define TM TimeManager::GetInstance()

class TimeManager
{
public:
    static TimeManager* GetInstance();
    void Update();
    float GetCurrentTimeInMiliseconds();
    float GetCurrentTimeInSeconds();
    float GetDeltaTimeMS();
    float GetDeltaTimeSeconds();

    static const float FPS;
    static const float TICK;

private:
    TimeManager();
    float deltaTime;
    float elapsedTime;
    static TimeManager* Instance;
};
