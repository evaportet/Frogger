#include "GameplayScene.h"

void GameplayScene::ResetScene()
{
	level = 1;
	isPaused = false;

	map = Tile(Vector2(RM->windowWidth, RM->windowHeight), Vector2(RM->windowWidth / 2, RM->windowHeight / 2), ColliderType::SAFE, "resources/Assets/NewMap.png");

	player = Frog(Vector2(16, 16), Vector2(RM->windowWidth / 2 - 20, RM->windowHeight - 90), ColliderType::SAFE, "resources/Assets/Frog.png");

	water = Collider(Vector2(8 + 256, 24 + 80 / 2), Vector2(256 * 4.f, 190 * 2.5f), ColliderType::WATER);
	CH->AddCollider(&water);

	for (int i = 0; i <= 4; i++)
	{
		endPositions[i] = EndTile(Vector2(112 + 48 * 3 * i, 32));
	}

	//LevelLoader::LoadLevel("resources/Files/sample_level.xml", spawners, row_tiles, levelTime);

	scoreText = UIText(18, 30, 160, RM->windowHeight - 45, "Score: 0", { 255,255,255 });
	scoreText.Load("resources/Fonts/Hyperspace.ttf");

	timeRect = ImageRenderer();
	timeRect.Load("resources/Assets/TimeBar.png");
	timeRect.SetSourcePos(Vector2(0.f, 0.f));
	timeRect.OverrideTargetPixelSize(Vector2(1.8f, 0.9f));
	timeRect.SetPosition(Vector2(500, RM->windowHeight - 30));
	timeRect.SetRotation(0);
	timeSizeAux = timeRect.GetTexturePixelSize();
	time_StartXSize = timeSizeAux.x;

	//pause menu
	pauseBckGrnd = ImageRenderer();
	pauseBckGrnd.Load("resources/Assets/Button.png");
	pauseBckGrnd.SetSourcePos(Vector2(0.f, 0.f));
	pauseBckGrnd.OverrideTargetPixelSize(Vector2(4.f, 11.f));
	pauseBckGrnd.SetPosition(Vector2(RM->windowWidth / 2, RM->windowHeight / 2));
	pauseBckGrnd.SetRotation(0);
	retryButton = Button(110, 25, RM->windowWidth / 2 - 285, RM->windowHeight / 2 + 25, "Retry");
	exitButton = Button(110, 25, RM->windowWidth / 2 + 60, RM->windowHeight / 2 + 25, "Exit");
	gameOverTxt = UIText(55, 65, RM->windowWidth / 2 - 250, RM->windowHeight / 2 - 90, "GAME OVER");
	gameOverTxt.Load("resources/Fonts/Hyperspace.ttf");
	gameOverTxt.SetRotation(0);
}

GameplayScene::GameplayScene()
{
	level = 1;
	isPaused = false;
	
	map = Tile(Vector2(RM->windowWidth, RM->windowHeight), Vector2(RM->windowWidth/2, RM->windowHeight/2), ColliderType::SAFE, "resources/Assets/NewMap.png");
										
	player = Frog(Vector2(16, 16), Vector2(RM->windowWidth/2-20, RM->windowHeight - 90), ColliderType::SAFE, "resources/Assets/Frog.png");
	
	water = Collider(Vector2(8 + 256, 24 + 80 / 2), Vector2(256*4.f, 190*2.5f), ColliderType::WATER);
	CH->AddCollider(&water);

	for (int i = 0; i <= 4; i++)
	{
		endPositions[i] = EndTile(Vector2(112 + 48*3*i, 32));
	}
	
	LevelLoader::LoadLevel("resources/Files/sample_level.xml", spawners, row_tiles, levelTime);
	
	scoreText = UIText(18, 30, 160, RM->windowHeight - 45, "Score: 0", {255,255,255});
	scoreText.Load("resources/Fonts/Pixellari.ttf");

	timeRect = ImageRenderer();
	timeRect.Load("resources/Assets/TimeBar.png");
	timeRect.SetSourcePos(Vector2(0.f, 0.f));
	timeRect.OverrideTargetPixelSize(Vector2(1.8f, 0.9f));
	timeRect.SetPosition(Vector2(500, RM->windowHeight - 30));
	timeRect.SetRotation(0);
	timeSizeAux = timeRect.GetTexturePixelSize();
	time_StartXSize = timeSizeAux.x;

	//end menu
	pauseBckGrnd = ImageRenderer();
	pauseBckGrnd.Load("resources/Assets/Button.png");
	pauseBckGrnd.SetSourcePos(Vector2(0.f, 0.f));
	pauseBckGrnd.OverrideTargetPixelSize(Vector2(4.f, 11.f));
	pauseBckGrnd.SetPosition(Vector2(RM->windowWidth/2, RM->windowHeight/2));
	pauseBckGrnd.SetRotation(0);
	retryButton = Button(110, 25, RM->windowWidth / 2 - 285, RM->windowHeight / 2 + 25, "Retry");
	exitButton = Button(110, 25, RM->windowWidth / 2 + 60, RM->windowHeight / 2 + 25, "Exit");
	gameOverTxt = UIText(55, 65, RM->windowWidth / 2 - 250, RM->windowHeight/2 - 90, "GAME OVER");
	gameOverTxt.Load("resources/Fonts/Pixellari.ttf");
	gameOverTxt.SetRotation(0);
}

void GameplayScene::Update(float dt)
{
	if (isPaused) {
		retryButton.Update(dt);
		exitButton.Update(dt);

		if (retryButton.isPressed)
		{
			retryButton.isPressed = false;
			isPaused = false;
			ResetScene();
			SM->SetScene("Gameplay");
		}
		
		if (exitButton.isPressed)
		{
			exitButton.isPressed = false;
			HSM->InsertScore("Player: ", player.GetScore());
			SM->SetScene("MainMenu");
		}
		
		return;
	}

	for (auto& spawner : spawners)
	{
		spawner->Update(dt);
	}
	
	for (int i = 0; i <= 4; i++)
	{
		endPositions[i].Update(dt);
	}

	CH->OnPlayerCollision(&water);
	/*if (CH->PlayerCollision(&water))
	{
		printf_s("AAAAAAAAAAAA");
	}*/
	player.Update(dt);

	//set score
	scoreText = UIText(18, 30, 160, RM->windowHeight - 45, "Score: " + std::to_string(player.GetScore()), { 255,255,255 });
	scoreText.Load("resources/Fonts/Hyperspace.ttf");
	

	timeSizeAux = Vector2(timeSizeAux.x - (17.f * 0.033f / levelTime), timeSizeAux.y);

	//update timer GUI & check if time's up
	timeRect.SetTexturePixelSize(timeSizeAux);


	//check if level has been completed / time's up / no lives left
	bool levelCompleted = endPositions[0].GetState() == EndState::FULL
		&& endPositions[1].GetState() == EndState::FULL
		&& endPositions[2].GetState() == EndState::FULL
		&& endPositions[3].GetState() == EndState::FULL
		&& endPositions[4].GetState() == EndState::FULL;
			
	if (levelCompleted) 
	{
		//End level
		SM->SetScene("MainMenu");
		HSM->InsertScore("Player 1", player.GetScore());
		//system("pause");
	}

	if (endPositions[0].GetState() == EndState::FULL)
	{
		timeSizeAux.x = time_StartXSize;
		timeRect.SetTexturePixelSize(timeSizeAux);
	}

	if (timeSizeAux.x <= 0.f)
	{
		player.Die();
		timeSizeAux.x = time_StartXSize;
		timeRect.SetTexturePixelSize(timeSizeAux);
	}

	if (player.GetLives() <= 0)
	{
		//end game (GAME OVER)
		isPaused = true;
	}
}

void GameplayScene::Render()
{
	map.Render();

	for (auto& element : row_tiles)
	{
		element->Render();
	}

	for (auto& spawner : spawners)
	{
		spawner->Render();
	}

	player.Render();

	for (int i = 0; i <= 4; i++)
	{
		endPositions[i].Render();
	}

	scoreText.Render();
	timeRect.Render();

	if (isPaused) {
		pauseBckGrnd.Render();
		gameOverTxt.Render();
		retryButton.Render();
		exitButton.Render();
	}
}

void GameplayScene::OnEnter()
{
	AM->PlayMusic("GameplayMusic");
}

void GameplayScene::OnExit()
{
}
