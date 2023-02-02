#include "SplashScreenScene.h"

void SplashScreenScene::Update(float dt)
{
	if (startTime + 1.5f > TM->GetCurrentTimeInSeconds())
	{
		
	}

	if (startTime + 3 > TM->GetCurrentTimeInSeconds())
	{
		
	}
	else
	{
		SM->SetScene("Gameplay");
	}
}

void SplashScreenScene::Render()
{
	frogger.Render();
}

void SplashScreenScene::OnEnter()
{
	frogger = Tile(Vector2(RM->windowWidth, RM->windowWidth), Vector2(RM->windowWidth/2, RM->windowWidth/2), ColliderType::SAVE, "resources/Assets/SplashScreen.png");
	
}

void SplashScreenScene::OnExit()
{
	//std::cout << "Exiting Splash Screen" << std::endl;
}
