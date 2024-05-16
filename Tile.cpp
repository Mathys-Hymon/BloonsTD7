#include "Tile.h"

Tile::Tile(Vector2 position, Vector2 size, TileType type, Texture sprite) : position(position), size(size), type(type), sprite(sprite)
{
}

Tile::~Tile()
{
}

void Tile::Draw()
{
	Vector2 spriteSize = { sprite.height, sprite.width };
	DrawTexturePro(sprite, { 0,0,spriteSize.x,spriteSize.y }, { position.x,position.y, size.x, size.y }, { 0,0 }, 0, WHITE);
}

float Tile::GetSize()
{
	return (float)size.x;
}

Vector2 Tile::GetPosition()
{
	return position;
}

TileType Tile::GetType()
{
	return type;
}

void Tile::SetType(TileType newType)
{
	type = newType;
}

void Tile::Unload()
{
	UnloadTexture(sprite);
}