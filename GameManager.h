#pragma once
#include "EnnemieSpawner.h"

class GameManager
{
private :
	int money;
	int lifes;
	EnnemieSpawner& ennemieSpawner;
	MapManager& mapManager;

public:
	GameManager(EnnemieSpawner& ennemieSpawner, MapManager& mapManager);
	~GameManager();

	void Load();
	void Update();
	void Draw();
	void Unload();
};

