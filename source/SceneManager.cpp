#include "SceneManager.h"

SceneManager* SceneManager::instance = nullptr;

SceneManager::SceneManager()
{
	hasChangedScene = false;
}

void SceneManager::AddScene(std::string name, Scene* s) {
	scenes.emplace(name, s);
}

SceneManager* SceneManager::GetInstance()
{
	if (instance == nullptr)
		instance = new SceneManager();
	return instance;
}


Scene* SceneManager::GetScene(std::string name) {
	auto scene = scenes.find(name);
	bool sceneFound = scene != scenes.end();
	return sceneFound ? scenes[name] : nullptr;
}

Scene* SceneManager::GetCurrentScene() {
	return currentScene;
}

void SceneManager::SetScene(std::string name) {
	auto scene = scenes.find(name);

	bool sceneFound = scene != scenes.end();
	assert(sceneFound);
	if (sceneFound) {
		hasChangedScene = true;
		if(currentScene != nullptr)
			currentScene->OnExit();
		currentScene = scene->second;
		currentScene->OnEnter();
	}
}

bool SceneManager::GetHasChangedScene()
{
	return hasChangedScene;
}

void SceneManager::ResetChangedScene()
{
	hasChangedScene = false;
}

