#include "RankingScene.h"

RankingScene::RankingScene()
{
	background = ImageRenderer();
	background.Load("resources/Assets/Background.png");
	background.SetSourcePos(Vector2(0, 0));
	background.SetTexturePixelSize(Vector2(RM->windowWidth, RM->windowHeight));
	background.SetRotation(0);

	backToMenu = Button(90, 25, RM->windowWidth - 205, 35, "Back");

	rankingText = UIText(70, 60, 40, 25, "RANKING", { 255,255,255 });
	rankingText.Load("resources/Fonts/Pixellari.ttf");

	//highScores = HSM->GetScoresMap();

	/*auto itr = highScores.begin();*/
	for (int i = 0; i < 10; i++)
	{
		topScoresText[i] = UIText(35, 30, 50, 40 + i * 40, "Player " + std::to_string(i) + ": " + std::to_string(0), {0,255,0});
	}
}

void RankingScene::Update(float dt)
{
	backToMenu.Update(dt);
	if (backToMenu.isPressed)
	{
		SM->SetScene("MainMenu");
		backToMenu.isPressed = false;
	}
}

void RankingScene::Render()
{
	background.Render();
	rankingText.Render();
	backToMenu.Render();

	for (int i = 0; i < 10; i++)
	{
		topScoresText[i].Render();
	}
}

void RankingScene::OnEnter()
{
	highScores = HSM->GetScoresMap();

	//auto itr = highScores.begin();
	//for (int i = 0; i < 10; i++)
	//{
		topScoresText[0] = UIText(35, 30, 50, 40 + /*i **/ 40, "Player 1: " + /*std::to_string(i) + ": " +*/ std::to_string(0), { 0,255,0 });
	//}
}

void RankingScene::OnExit()
{
}

