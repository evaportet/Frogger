#include "Log.h"

Log::Log()
{

}

Log::Log(int length, Vector2 pos, float spd)
{
	transform.position = pos;
	transform.scale = Vector2(48, 16);
	transform.rotation = 0;

	collider = Collider(pos, transform.scale * 2.f, ColliderType::PLATFORM);
	CH->AddCollider(&collider);
	speed = spd;
	SetSpeed(spd);
	renderer.Load("resources/assets/Log.png");
	renderer.SetPosition(collider.GetCenterPivot());
	renderer.SetScale(transform.scale);
	renderer.SetSourcePos(Vector2(0, 0));
	renderer.OverrideTargetPixelSize(Vector2(3*length, 3));
}

void Log::Update(float dt)
{
	//actualizar la pos
	SetPosition(transform.position + Vector2(speed, 0) * dt);
	renderer.SetPosition(transform.position);
	
	CH->OnPlayerCollision(&collider);
	if (CH->PlayerCollision(&collider))
	{
		//printf_s("VVVVVVV");
		CH->StoreAttachedVel(speed*dt);
	}
	

	//mirar cuando sale de la pantalla TODO
	if (!CH->InScreen(&collider))
	{
		//system("pause");
		//delete or reset object
		SetPosition(transform.position);
		renderer.SetPosition(transform.position);
		//exit(2);
	}
		
		
	/*durationLog = (clock() - startLog) / CLOCKS_PER_SEC;

	if (durationLog >= FRAMERATE)
	{
		transform.position.x += speed;
		Vector2 newTopLeft = collider.GetTopLeft();
		newTopLeft.x += speed;
		collider.SetTopLeft(newTopLeft);

		startLog = clock();
	}*/

}

void Log::Render()
{
	renderer.Render();
}

//bool Log::CheckIfInBoundaries()
//{
//	Vector2 textureSize = renderer.GetTexturePixelSize();
//	bool res = true;
//	speed > 0.f ? 
//		res = transform.position.x <= RM->windowWidth : 
//		res = transform.position.x + textureSize.x <= 0;
//	return res;
//
//	/*return (transform.position.x > 0 && transform.position.x < RM->windowWidth
//		&& transform.position.y > 0 && transform.position.y < RM->windowHeight
//		&& transform.position.x + textureSize.x > 0 && transform.position.x + textureSize.x < RM->windowWidth
//		&& transform.position.y + textureSize.y > 0 && transform.position.y + textureSize.y < RM->windowHeight);*/
//}
