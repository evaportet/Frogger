#include"GameEngine.h"

GameEngine::GameEngine()
    : isRunning(true)
{

}

#pragma region INITIALIZATION
void GameEngine::Init()
{
    //Time
    TM->GetInstance();
    //Render
    RM->GetInstance();

    //Load Audio
    //AudioManager::GetInstance()->LoadClip("randomSFX");
    //AudioManager::GetInstance()->LoadMusic("randomSong");

    //Create and add Scenes
    SM->AddScene("Splash Screen", new SplashScreenScene());
    //SM->SetScene("Splash Screen");
    SM->AddScene("MainMenu", new MainMenuScene());
    SM->AddScene("Gameplay", new GameplayScene());
    SM->SetScene("Gameplay");
}

#pragma endregion

void GameEngine::Run()
{
    while (isRunning)
    {
        TM->Update();
        IM->Listen();

        if (IM->CheckKeyState(SDLK_SPACE, PRESSED)) {
            /// play audio
            /// AM->PlayClip()
        }
        if (IM->CheckKeyState(SDLK_m, PRESSED)) {
            AM->SetMute(!AM->GetMuted());
        };

        isRunning = !IM->GetQuitEvent();
        SM->GetCurrentScene()->Update(TM->GetDeltaTimeMS());

        //Render
        RM->RenderScreen();
    }
}

//Calls destructors and ends subprocess (i.e. SDL)
void GameEngine::Quit()
{

}