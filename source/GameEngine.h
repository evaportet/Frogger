#pragma once
#include<SDL.h>
#include"GameObject.h"
#include"InputManager.h"
#include"SceneManager.h"
#include"SplashScreenScene.h"
#include"MainMenuScene.h"
#include"GameplayScene.h"
#include"RenderManager.h"
#include"AudioManager.h"
#include"TimeManager.h"

class GameEngine
{
public:
    GameEngine();
    void Init();
    void Run();
    void Quit();

private:
    bool isRunning;
};
