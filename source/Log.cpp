#include "Log.h"

clock_t startLog = 0;
double durationLog;

Log::Log()
{

}

Log::Log(int length, Vector2 pos, float spd)
{
	transform.position = pos;
	transform.scale = Vector2(16 * length, 16);
	transform.rotation = 0;

	collider = Collider(pos, transform.scale, ColliderType::LOG);
	speed = spd;

	renderer.Load("resources/assets/Log.png");
	renderer.SetPosition(collider.GetTopLeft());
	renderer.SetScale(transform.scale);
	renderer.SetSourcePos(Vector2(48-16*length, 0));
}

void Log::Update()
{
	durationLog = (clock() - startLog) / CLOCKS_PER_SEC;

	if (durationLog >= FRAMERATE)
	{
		transform.position.x += speed;
		Vector2 newTopLeft = collider.GetTopLeft();
		newTopLeft.x += speed;
		collider.SetTopLeft(newTopLeft);

		startLog = clock();
	}
}

void Log::Render()
{
	renderer.Render();
}
