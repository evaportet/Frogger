#include "Car.h"

//clock_t startCar = 0;
//double durationCar;

Car::Car()
{

}

Car::Car(int length, Vector2 pos, Vector2 size, float spd, ColliderType ct, std::string path)
{
	transform.position = pos;
	transform.scale = size;
	transform.rotation = 0;
	speed = spd;
	SetSpeed(spd);
	collider = Collider(pos, size * 3, ct);
	CH->AddCollider(&collider);
	renderer.Load(path);
	renderer.SetPosition(collider.GetTopLeft());
	renderer.SetScale(transform.scale);
	renderer.SetSourcePos(Vector2(0, 0));
	renderer.OverrideTargetPixelSize(Vector2(3, 3));

	/*transform.position = pos;
	transform.scale = Vector2(16 * length, 16);
	transform.rotation = 0;

	collider = Collider(pos, transform.scale, ColliderType::DMG);
	speed = spd;

	renderer.Load("resources/assets/Cars.png");
	renderer.SetPosition(collider.GetTopLeft());
	renderer.SetScale(transform.scale);*/

	/*if (length > 1)
	{
		renderer.SetSourcePos(Vector2(32, 0));
	}
	if (spd >= 0)
	{
		int rightDirectionCar = rand() % 2;
		if(rightDirectionCar == 0)
			renderer.SetSourcePos(Vector2(16, 0));
		else
			renderer.SetSourcePos(Vector2(80, 0));
	}
	else
	{
		int leftDirectionCar = rand() % 2;
		if (leftDirectionCar == 0)
			renderer.SetSourcePos(Vector2(0, 0));
		else
			renderer.SetSourcePos(Vector2(64, 0));
	}*/
}

void Car::Update()
{
	SetPosition(transform.position + Vector2(speed, 0));
	renderer.SetPosition(collider.GetTopLeft());
	/*durationCar = (clock() - startCar) / CLOCKS_PER_SEC;

	if (durationCar >= FRAMERATE)
	{
		transform.position.x += speed;
		Vector2 newTopLeft = collider.GetTopLeft();
		newTopLeft.x += speed;
		collider.SetTopLeft(newTopLeft);

		startCar = clock();
	}*/
}

void Car::Render()
{
	renderer.Render();
}
