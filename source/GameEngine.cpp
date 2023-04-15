#include"GameEngine.h"

GameEngine::GameEngine()
    : isRunning(true)
{

}

#pragma region INITIALIZATION
void GameEngine::Init()
{
    //Time
    TM;
    //Render
    RM;
    //Collisions
    CH;
    //High score
    HSM;

    //Load Audio
    //AudioManager::GetInstance()->LoadClip("randomSFX");
    //AudioManager::GetInstance()->LoadMusic("randomSong");

    //Create and add Scenes
    SM->AddScene("SplashScreen", new SplashScreenScene());
    SM->AddScene("MainMenu", new MainMenuScene());
    SM->AddScene("Gameplay", new GameplayScene());
    SM->AddScene("Ranking", new RankingScene());
    SM->SetScene("SplashScreen");
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
        SM->GetCurrentScene()->Update(TM->GetDeltaTimeSeconds());
        if (SM->GetHasChangedScene())
        {
            SM->ResetChangedScene();
            continue;
        }

        //Render
        RM->RenderScreen();
    }
}

//Calls destructors
void GameEngine::Quit()
{
    
}