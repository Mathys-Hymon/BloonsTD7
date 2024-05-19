#pragma once
#include "Tile.h"
#include "HUDManager.h"

class MapManager
{
private:
	Tile* Map[20][20];
	float floorGrip;
	Texture RoadTexture;
	Texture GrassTexture;
	Texture CastleTexture;
	Vector2 spawnPos;

public:
	MapManager();
	~MapManager();

	void Load();
	void Update();
	void Draw();
	Vector2 CheckTile(Vector2 position, Vector2 direction);
	TileType CheckTileType(Vector2 position);
	Tile* GetGridTile(Vector2 position);
	Vector2 EnnemieSpawnPos();
	void Unload();
};

