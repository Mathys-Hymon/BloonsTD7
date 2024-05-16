#pragma once
#include "MapManager.h"


class Ennemie
{
private:
	Vector2 position;
	Vector2 targetPosition;
	Vector2 direction = {0,1.0};

	int life = 100;
	int damage = 10;
	int coins = 10;

	float speed = 50;

	bool isDead = false;

	Texture& sprite;
	MapManager& mapManager;

public:
	Ennemie(MapManager& mapManager, Texture& sprite, Vector2 pos, float speed, int life);
	~Ennemie();

	bool IsDead();
	void TakeDamage(int damage);
	void Update();
	void Draw();
	void Unload();

};

