#include "Button.h"

Button::Button(int _width, int _height, int x, int y, std::string text)
{
	isClicked = false;
	isPressed = false;

	width = _width*2;
	height = _height*2;
	transform.position.x = x;
	transform.position.y = y;
	//collider = Collider(Vector2(x, y), Vector2(width, height), ColliderType::SAVE);
	sampleText = UIText(20*2, 20*2, x+10, y+4);

	sampleText.SetText(text);
	sampleText.Load("resources/Fonts/ButtonFont.ttf");
	sampleText.SetRotation(0);
	//sampleText.SetPosition(Vector2(x, y));
	//sampleText.SetScale(Vector2(width, height));

	renderer = ImageRenderer();
	renderer.Load("resources/Assets/Button.png");
	renderer.SetPosition(Vector2(transform.position.x, transform.position.y));
	renderer.SetScale(Vector2(width, height));
}

Button::Button()
{
}

void Button::Update()
{
	renderer.Update();
	sampleText.Update();
	CheckIfCollides();
}

void Button::Render()
{
	renderer.Render();
	sampleText.Render();
}

void Button::CheckIfCollides()
{
	int mouseX = IM->GetMouseX();
	int mouseY = IM->GetMouseY();

	bool isInsideAABBX = mouseX > transform.position.x && mouseX < transform.position.x + width;
	bool isInsideAABBY = mouseY > transform.position.y && mouseY < transform.position.y + height;

	if (isInsideAABBX && isInsideAABBY)
	{
		mouseInsideButton = true;
		if (IM->mousePressed)
		{
			isClicked = true;
			AM->PlaySFX("Button", 0);
		}
		else
		{
			if (isClicked)
			{
				isClicked = false;
				isPressed = true;
			}
		}
	}

	else
	{
		mouseInsideButton = false;

		if (!IM->mousePressed && isClicked)
		{
			isClicked = false;
			isPressed = true;
		}
	}
}

