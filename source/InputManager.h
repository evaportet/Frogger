#pragma once
#include <unordered_map>
#include <SDL.h>


enum KeyState { 
	UNDEFINED = 1,	//Code tries to access key but it hasn't been registered yet
	DOWN = 2,		//Frame that the key is pressed
	PRESSED = 4,	//The key is pressed
	UP = 8,			//Frame that the key is released
	RELEASED = 16	//Released
};

using namespace std;

#define IM InputManager::GetInstance()

class InputManager {
private:
	unordered_map<Sint32, KeyState> keys;
	int mouseX, mouseY;
	bool quitEvent;
	bool resizeEvent;
	SDL_Event windowEvent;
	InputManager() : quitEvent(false), mouseX(0), mouseY(0) {};
	static InputManager* instance;
public:
	bool mousePressed;
	static InputManager* GetInstance();
	void Listen();
	bool CheckKeyState(Sint32 key, KeyState state);
	int GetMouseX();
	int GetMouseY();
	bool GetQuitEvent();
	void SetQuitEvent(bool newQuitState);
	bool GetResizeEvent(int&, int&);
};