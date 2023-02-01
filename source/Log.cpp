#include "Log.h"

Log::Log()
{

}

Log::Log(int length, Vector2 pos, float spd)
{
	spawnPos = pos;
	transform.position = pos;
	transform.scale = Vector2(48, 16);
	transform.rotation = 0;

	collider = Collider(pos, Vector2(transform.scale.x * length*2, transform.scale.y), ColliderType::LOG);
	CH->AddCollider(&collider);
	speed = spd;
	SetSpeed(spd);
	renderer.Load("resources/assets/Log.png");
	renderer.SetPosition(collider.GetCenterPivot());
	renderer.SetScale(transform.scale);
	renderer.SetSourcePos(Vector2(0, 0));
	renderer.OverrideTargetPixelSize(Vector2(3*length, 3));
}

void Log::Update()
{
	//actualizar la pos
	SetPosition(transform.position + Vector2(speed, 0));
	renderer.SetPosition(transform.position);
	
	if (CH->PlayerCollision(&collider))
	{
		printf_s("Aki con el player");
		//TODO: acabar comunicar al player X
		CH->OnPlayerCollision(&collider);
	}
	

	//mirar cuando sale de la pantalla
	if (!CH->InScreen(&collider))
	{
		//system("pause");
		//delete or reset object
		SetPosition(spawnPos);
		renderer.SetPosition(spawnPos);
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
