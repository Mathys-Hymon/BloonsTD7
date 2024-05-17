#pragma once
#include "Turret.h"

class GameManager
{
private :
	float turretDelay = 0;
	EnnemieSpawner& ennemieSpawner;
	MapManager& mapManager;
	Texture turretSprite;
	
	std::vector<Turret> turrets;

	int turretPrice = 100;

public:
	GameManager(EnnemieSpawner& ennemieSpawner, MapManager& mapManager);
	~GameManager();

	void Load();
	void Update();
	void Draw();
	void Unload();
};

