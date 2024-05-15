#include "MapManager.h"

MapManager::MapManager()
{
}

MapManager::~MapManager()
{
}

void MapManager::Initialize()
{
}

void MapManager::Load()
{

	RoadTexture = LoadTexture("resources/texture/road.png");
	CastleTexture = LoadTexture("resources/texture/castle.png");
	GrassTexture = LoadTexture("resources/texture/grass.png");

	Image mapImage = LoadImage("resources/maps/Map1.png");
	Color* colors = LoadImageColors(mapImage);

	float tileSize = GetScreenWidth() / (float)mapImage.height;

	for (int y = 0; y < 20; y++) {
		for (int x = 0; x < 20; x++) {

			if (colors[y * mapImage.width + x].r == 255) {
				Map[y][x] = new Tile({ x * tileSize ,y * tileSize }, { tileSize, tileSize }, TileType::PATH, RoadTexture);
			}
			else if (colors[y * mapImage.width + x].g == 255) {
				Map[y][x] = new Tile({ x * tileSize ,y * tileSize }, { tileSize, tileSize }, TileType::GRASS, GrassTexture);
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

				Map[i][j]->Draw();

		}
	}
}

Vector2 MapManager::CheckTile(Vector2 position, Vector2 direction)
{
	int GridPositionX = (position.x / (GetScreenWidth() / (sizeof(Map) / sizeof(Map[0]))));
	int GridPositionY = (position.y / (GetScreenHeight() / (sizeof(Map) / sizeof(Map[0]))));

	if (Map[GridPositionY + (int)direction.y][GridPositionX + (int)direction.x]->GetType() == TileType::PATH) {
		return Map[GridPositionY][GridPositionX]->GetPosition();
	}
	else {
		return { 0,0 };
	}


}


void MapManager::Unload()
{
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			if (Map[i][j] != NULL) {
				Map[i][j]->Unload();
			}
		}
	}
	UnloadTexture(RoadTexture);
	UnloadTexture(GrassTexture);
	UnloadTexture(CastleTexture);

}
