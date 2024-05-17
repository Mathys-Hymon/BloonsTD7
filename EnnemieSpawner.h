#pragma once
#include "Ennemie.h"
#include <chrono>
#include <thread>

class EnnemieSpawner
{
private :
	std::vector<Ennemie> ennemies;
	Texture ennemieSprite;
	MapManager& mapManager;
	int wave = 0;

	float spawnTimer = 1;
	float timer = 0;
	float restTime = 10;
	float ennemiePerWave;
	float ennemieSpeed = 300;
	int ennemieLife = 100;
	bool spawning;

public :
	EnnemieSpawner(MapManager& mapManager);
	~EnnemieSpawner();
	void Load();
	void Update();
	void Draw();
	void Unload();
	std::vector<Ennemie>& GetEnnemies();

	void newWave(int wave);

};

