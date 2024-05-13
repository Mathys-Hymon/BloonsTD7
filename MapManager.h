#pragma once
#include "Tile.h"
#include "raylib.h"
#include <vector>

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
	void ChooseMap(Image mapImage);
	void Update();
	void Draw();
	void Unload();
};

