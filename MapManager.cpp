#include "MapManager.h"

MapManager::MapManager()
{
}

MapManager::~MapManager()
{
}

void MapManager::Initialize()
{
	RoadTexture = LoadTexture("resources/texture/road.png");
	CastleTexture = LoadTexture("resources/texture/castle.png");
	GrassTexture = LoadTexture("resources/texture/grass.png");
}

void MapManager::ChooseMap(Image mapImage_)
{
	Image mapImage = mapImage_;
	Color* colors = LoadImageColors(mapImage);

	float tileSize = GetScreenWidth() / (float)mapImage.height;

	for (int y = 0; y < mapImage.height; y++) {
		for (int x = 0; x < mapImage.width; x++) {

		 if (colors[y * mapImage.width + x].r == 255) {
				Map[y][x] = new Tile({ x * tileSize ,y * tileSize }, { tileSize, tileSize }, TileType::PATH, RoadTexture, RoadTexture, 0);
			}
			else if (colors[y * mapImage.width + x].g == 255) {
				Map[y][x] = new Tile({ x * tileSize ,y * tileSize }, { tileSize, tileSize }, TileType::GRASS, GrassTexture, RoadTexture, 0);
			}
		}
	}
}

void MapManager::Update()
{

}

void MapManager::Draw()
{
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {

				Map[i][j]->Draw(false);
		}
	}
}


void MapManager::Unload()
{
	for (int i = 0; i < Map.size(); i++) {
		for (int j = 0; j < Map.size(); j++) {
			if (Map[i][j] != NULL) {
				Map[i][j]->Unload();
			}
		}
	}
	UnloadTexture(RoadTexture);
	UnloadTexture(GrassTexture);
	UnloadTexture(CastleTexture);

}
