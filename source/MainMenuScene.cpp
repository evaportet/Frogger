#include "MainMenuScene.h"


MainMenuScene::MainMenuScene()
{
	exit = false;
	audio = true;

}

void MainMenuScene::Update(float dt)
{
	//Check if the mouse is inside the render rect
	int width = 28 * sampleText.text.length();
	int height = 50;

	int X = sampleText.position[0];
	int Y = sampleText.position[1];

	//sampleText.position <= x, y
	int mouseX = IM->GetMouseX();
	int mouseY = IM->GetMouseY();

	bool isInsideAABBX = mouseX > X - width && mouseX < X + width;
	bool isInsideAABBY = mouseY > Y - height && mouseY < Y + height;

	if (isInsideAABBX && isInsideAABBY)
	{
		buttonAngle += 0.1f;
		if (IM->CheckKeyState(SDLK_j, PRESSED))
			SM->SetScene("SplashScreen");
	}
	else
		buttonAngle = 0;

}

void MainMenuScene::Render()
{
	////Text data
	////width
	//int width = 20 * sampleText.text.length();
	//int height = 50;
	//SDL_Color color = { 0, 0, 0 };

	//SDL_Surface* surface = TTF_RenderText_Solid(font, sampleText.text.c_str(), color);
	//assert(surface != nullptr);

	//SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
	//assert(texture != nullptr);

	////255 -> opaque
	////0 -> transparent
	//SDL_SetTextureAlphaMod(texture, 255);

	//SDL_Rect renderRect =
	//{
	//	sampleText.position[0] - width / 2,
	//	sampleText.position[1] - height / 2,
	//	width,
	//	height
	//};

	//SDL_RenderCopyEx(
	//	renderer,			//Renderer
	//	texture,			//Target texture
	//	NULL,			//Texture part we want to draw
	//	&renderRect,	//Where do we want to draw and what size
	//	buttonAngle,				//Angle
	//	NULL,			//Center of the sprite
	//	SDL_FLIP_NONE		//Flip the sprite
	//);

	//SDL_FreeSurface(surface);
	//SDL_DestroyTexture(texture);
}

void MainMenuScene::OnEnter()
{
	//INIT TTF
	assert(TTF_Init() != -1);

	//Load the font
	font = TTF_OpenFont("resources/fonts/hyperspace.ttf", 28);
	assert(font != nullptr);

	sampleText.text = "HOLA KE ASE!";
	sampleText.position[0] = 250;
	sampleText.position[1] = 250;

	buttonAngle = 0;
}

void MainMenuScene::OnExit()
{
}
