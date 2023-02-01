#include "GameEngine.h"

int main(int argc, char* args[]) {
	
	srand(time(NULL));
	GameEngine game;
	game.Init();
	game.Run();
	game.Quit();
	
	return 0;
}