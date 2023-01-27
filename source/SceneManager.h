#pragma once
#include <map>
#include <string>
#include "Scene.h"
#include "assert.h"

#define SM SceneManager::GetInstance()

class SceneManager {
public:
	//Agregation -> Scene
	void AddScene(std::string, Scene* s);
	//Getters
	Scene* GetScene(std::string name);
	Scene* GetCurrentScene();
	//Setters
	void SetScene(std::string name);
	//Singleton
	static SceneManager* GetInstance();
private:
	SceneManager();
	static SceneManager* instance;
	//Scene management
	std::map<std::string, Scene*> scenes;
	Scene* currentScene;
};