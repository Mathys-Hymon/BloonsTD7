#pragma once
#include "raylib.h"
#include "TileType.h"

class Tile
{
private:
	Vector2 position;
	Vector2 size;

	TileType type;
	Texture sprite;

public:
	Tile(Vector2 position, Vector2 size, TileType type, Texture sprite);
	~Tile();

	void Draw();
	float GetSize();
	Vector2 GetPosition();
	TileType GetType();
	void Unload();
};

