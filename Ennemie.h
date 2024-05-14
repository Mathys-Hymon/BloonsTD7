#pragma once
#include "MapManager.h"


class Ennemie
{
private:
	Vector2 position;
	Vector2 targetPosition;
	Vector2 direction;

	float life;
	float speed;

	Texture sprite;
	MapManager& mapManager;

public:
	Ennemie(MapManager& mapManager, Texture sprite, Vector2 pos);
	~Ennemie();

	void Update();
	void Draw();
	void Unload();

};

