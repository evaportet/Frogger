#include "MainMenuScene.h"


MainMenuScene::MainMenuScene()
{
	audio = true;

	playButton = Button(158, 23, RM->windowWidth/2-158, 150, "PLAY");
	rankingButton = Button(158, 23, RM->windowWidth / 2-158, 150 + 70 *1, "RANKING");
	audioButton = Button(158, 23, RM->windowWidth / 2- 158, 150 + 70 * 2, "AUDIO");
	exitButton = Button(158, 23, RM->windowWidth / 2- 158, 150 + 70 * 3, "EXIT");
	background = Tile(Vector2(RM->windowWidth, RM->windowHeight), Vector2(RM->windowWidth / 2, RM->windowHeight / 2), ColliderType::SAFE, "resources/Assets/Background.png");
}

void MainMenuScene::Update(float dt)
{
	playButton.Update();
	rankingButton.Update();
	audioButton.Update();
	exitButton.Update();

	if (playButton.isPressed)
	{
		SM->SetScene("Gameplay");

		playButton.isPressed = false;
	}

	else if (exitButton.isPressed)
	{
		IM->SetQuitEvent(true);
		exitButton.isPressed=false;
	}

	else if (rankingButton.isPressed)
	{
		//SM->SetScene("ranking");
		rankingButton.isPressed=false;
	}

	else if (audioButton.isPressed)
	{
		audio = !audio;
		AM->SetMute(!audio);
	
		audioButton.isPressed = false;
	}
}

void MainMenuScene::Render()
{
	background.Render();
	playButton.Render();
	rankingButton.Render();
	audioButton.Render();
	exitButton.Render();
}

void MainMenuScene::OnEnter()
{
	AM->PlayMusic("MenuMusic");
}

void MainMenuScene::OnExit()
{
	AM->GetMuted();
}
