#pragma once
#include "Tile.h"
#include "raylib.h"
#include <vector>
#include <iostream>

class MapManager
{
private:
	Tile* Map[20][20];
	float floorGrip;
	Texture RoadTexture;
	Texture GrassTexture;
	Texture CastleTexture;

public:
	MapManager();
	~MapManager();

	void Initialize();
	void Load();
	void Update();
	void Draw();
	TileType GetTileType(int posX, int posY);
	void Unload();
};

