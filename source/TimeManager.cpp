#include "TimeManager.h"

TimeManager* TimeManager::Instance = nullptr;

const float TimeManager::FPS = 60.f;
const float TimeManager::TICK = 1.f / 60.f;

TimeManager::TimeManager() : deltaTime(0.f), elapsedTime(0.f)
{

}

TimeManager* TimeManager::GetInstance()
{
    if (Instance == nullptr)
    {
        Instance = new TimeManager();
    }

    return Instance;
}

void TimeManager::Update()
{
    deltaTime = float(SDL_GetTicks()) - elapsedTime;
    elapsedTime = float(SDL_GetTicks());
}

float TimeManager::GetCurrentTimeInMiliseconds()
{
    return elapsedTime;
}

float TimeManager::GetCurrentTimeInSeconds()
{
    return elapsedTime / 1000.f;
}

float TimeManager::GetDeltaTimeMS()
{
    return deltaTime;
}

float TimeManager::GetDeltaTimeSeconds()
{
    return deltaTime / 1000.f;
}