#include "GameplayScene.h"

GameplayScene::GameplayScene()
{
	score = 0;
	level = 1;
	/*LoadLevelFromFile("1");*/
	
	map = Tile(Vector2(RM->windowWidth, RM->windowHeight), Vector2(RM->windowWidth/2, RM->windowHeight/2), ColliderType::SAVE, "resources/Assets/Map.png");

	player = Frog(Vector2(16, 16), Vector2(RM->windowWidth/2, RM->windowHeight -30), ColliderType::SAVE, "resources/Assets/Frog.png");

	log = Log(1, Vector2(RM->windowWidth/2, RM->windowHeight/2), 0.002/*0.010*/);
	
	for (int i = 0; i <= 4; i++)
	{
		endPositions[i] = EndTile(Vector2(120 + 48*3*i, 40));
	}
	
	LevelLoader::LoadLevel("resources/Files/sample_level.xml", spawners, row_tiles);
	/*Log newCar = Log(2, Vector2(-10, 150), 2.0f);
	gameObjects.push_back(newCar);*/
}

void GameplayScene::Update(float dt)
{
	for (auto& spawner : spawners)
	{
		spawner->Update();
	}

	log.Update();
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
	log.Render();

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
