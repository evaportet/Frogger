#include "GameplayScene.h"

GameplayScene::GameplayScene()
{
	    score = 0;
	    level = 1;
	    /*LoadLevelFromFile("1");*/
	
		map = Tile(Vector2(272, 208), Vector2(136, 104), ColliderType::SAVE, "resources/Assets/Map.png");

		player = Frog(Vector2(16, 16), Vector2(136, 208-30), ColliderType::SAVE, "resources/Assets/Frog.png");
	
		for (int i = 0; i <= 4; i++)
		{
			endPositions[i] = EndTile(Vector2(43 + 48*i,16));
		}
	
		/*Log newCar = Log(2, Vector2(-10, 150), 2.0f);
		gameObjects.push_back(newCar);*/
}

void GameplayScene::Update(float dt)
{
	player.Update();

	for (int i = 0; i <= 4; i++)
	{
		endPositions[i].Update();
	}

	/*for (int i = 0; i <= gameObjects.size(); i++)
	{
		gameObjects[i].Update();
	}*/
}

void GameplayScene::Render()
{
	//RM->ClearScreen();
	map.Render();
	player.Render();

	for (int i = 0; i <= 4; i++)
	{
		endPositions[i].Render();
	}

	/*for (int i = 0; i <= gameObjects.size(); i++)
	{
		if (gameObjects[i].GetCollider().GetType() != ColliderType::SNK && gameObjects[i].GetCollider().GetType() != ColliderType::FOOD)
			gameObjects[i].Render();
	}

	for (int i = 0; i <= gameObjects.size(); i++)
	{
		if (gameObjects[i].GetCollider().GetType() == ColliderType::SNK || gameObjects[i].GetCollider().GetType() == ColliderType::FOOD)
			gameObjects[i].Render();
	}*/


	//RM->RenderScreen();
}

void GameplayScene::OnEnter()
{
}

void GameplayScene::OnExit()
{
}
