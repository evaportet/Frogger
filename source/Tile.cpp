#include "Tile.h"

Tile::Tile()
{

}

Tile::Tile(Vector2 size, Vector2 pos, ColliderType ct, std::string path)
{
	transform.position = pos;
	transform.scale = size;
	transform.rotation = 0;

	collider = Collider(pos, size, ct);
	CH->AddCollider(&collider);

	renderer.Load(path);
	renderer.SetPosition(collider.GetTopLeft());
	renderer.SetScale(transform.scale);
	renderer.SetSourcePos(Vector2(0, 0));	
	renderer.SetRotation(transform.rotation);
}

void Tile::Update()
{
	SetPosition(transform.position + Vector2(speed, 0));
	renderer.SetPosition(collider.GetTopLeft());
}

void Tile::Render()
{
	renderer.Render();
}
