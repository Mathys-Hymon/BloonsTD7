#include "Ennemie.h"

Ennemie::Ennemie(MapManager& mapManager, Texture sprite, Vector2 pos) : sprite(sprite), position(pos), mapManager(mapManager), targetPosition(pos)
{
}

Ennemie::~Ennemie()
{
}

void Ennemie::Update()
{
    if (position.x == targetPosition.x && position.y == targetPosition.y) {
		
		Vector2 newPos = mapManager.CheckTile({position.x + direction.x, position.y + direction.y});
	}
}

void Ennemie::Draw()
{
	DrawCircle(position.x, position.y, 5, RED);
}

void Ennemie::Unload()
{
	UnloadTexture(sprite);
}
