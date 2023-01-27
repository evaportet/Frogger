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

	renderer.Load(path);
	renderer.SetPosition(collider.GetTopLeft());
	renderer.SetScale(transform.scale);
	renderer.SetSourcePos(Vector2(0, 0));
}

void Tile::Update()
{

}

void Tile::Render()
{
	renderer.Render();
}
