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


			if (colors[y * mapImage.width + x].r == 255 && colors[y * mapImage.width + x].g == 255 && colors[y * mapImage.width + x].b == 255) {
				Map[y][x] = new Tile({ x * tileSize ,y * tileSize }, { tileSize, tileSize }, TileType::CASTLE, CastleTexture);
			}
			else if (colors[y * mapImage.width + x].r == 255) {
				Map[y][x] = new Tile({ x * tileSize ,y * tileSize }, { tileSize, tileSize }, TileType::PATH, RoadTexture);
			}
			else if (colors[y * mapImage.width + x].g == 255) {
				Map[y][x] = new Tile({ x * tileSize ,y * tileSize }, { tileSize, tileSize }, TileType::GRASS, GrassTexture);
			}
			else if (colors[y * mapImage.width + x].r == 0 && colors[y * mapImage.width + x].g == 0 && colors[y * mapImage.width + x].b == 0) {

				Map[y][x] = new Tile({ x * tileSize ,y * tileSize }, { tileSize, tileSize }, TileType::PATH, RoadTexture);
				spawnPos = { (float)Map[y][x]->GetPosition().x + (Map[y][x]->GetSize() / 2), (float)Map[y][x]->GetPosition().y + (Map[y][x]->GetSize() / 2) };
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
	int GridPositionX = ((int)position.x / (GetScreenWidth() / (sizeof(Map) / sizeof(Map[0])))) + (int)direction.x;
	int GridPositionY = ((int)position.y / (GetScreenHeight() / (sizeof(Map) / sizeof(Map[0])))) + (int)direction.y;

	if (GridPositionX >= 20 || GridPositionX < 0) {
		return { 0,0 };
	}
	else if (GridPositionY >= 20 || GridPositionY < 0) {
		return { 0,0 };
	}
    if (Map[GridPositionY][GridPositionX]->GetType() == TileType::PATH) {

		Vector2 pos = Map[GridPositionY][GridPositionX]->GetPosition();

		return { pos.x + (Map[0][0]->GetSize() / 2), pos.y + (Map[0][0]->GetSize() / 2)};
	}
	else if (Map[GridPositionY][GridPositionX]->GetType() == TileType::CASTLE) {
		return { -1,-1 };
	}
	else {
		return { 0,0 };
	}


}

TileType MapManager::CheckTileType(Vector2 position)
{
	int GridPositionX = ((int)position.x / (GetScreenWidth() / (sizeof(Map) / sizeof(Map[0]))));
	int GridPositionY = ((int)position.y / (GetScreenHeight() / (sizeof(Map) / sizeof(Map[0]))));


	return Map[GridPositionY][GridPositionX]->GetType();

}

Tile* MapManager::GetGridTile(Vector2 position)
{
	int GridPositionX = ((int)position.x / (GetScreenWidth() / (sizeof(Map) / sizeof(Map[0]))));
	int GridPositionY = ((int)position.y / (GetScreenHeight() / (sizeof(Map) / sizeof(Map[0]))));


	return Map[GridPositionY][GridPositionX];
}


Vector2 MapManager::EnnemieSpawnPos()
{
	return spawnPos;
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
