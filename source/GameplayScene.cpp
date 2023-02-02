#include "GameplayScene.h"

GameplayScene::GameplayScene()
{
	score = 0;
	level = 1;
	
	map = Tile(Vector2(RM->windowWidth, RM->windowHeight), Vector2(RM->windowWidth/2, RM->windowHeight/2), ColliderType::SAVE, "resources/Assets/NewMap.png");
										
	player = Frog(Vector2(16, 16), Vector2(RM->windowWidth/2-20, RM->windowHeight -105), ColliderType::SAVE, "resources/Assets/Frog.png");
	
	//water = Collider(Vector2(256 / 2, 80 / 2), Vector2(256, 80), ColliderType::DMG);
	//CH->AddCollider(&water);
	//	//8, 14

	for (int i = 0; i <= 4; i++)
	{
		endPositions[i] = EndTile(Vector2(120 + 48*3*i, 40));
	}
	
	LevelLoader::LoadLevel("resources/Files/sample_level.xml", spawners, row_tiles);
}

void GameplayScene::Update(float dt)
{
	for (auto& spawner : spawners)
	{
		spawner->Update();
	}

	player.Update();
	//CH->OnPlayerCollision(&water);

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
	AM->PlayMusic("GameplayMusic");
}

void GameplayScene::OnExit()
{
}
