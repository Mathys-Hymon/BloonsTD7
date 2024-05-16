#include "GameManager.h"


GameManager::GameManager(EnnemieSpawner& ennemieSpawner, MapManager& mapManager) : ennemieSpawner(ennemieSpawner), mapManager(mapManager)
{
}

GameManager::~GameManager()
{
}

void GameManager::Load()
{
        mapManager.Load();
        ennemieSpawner.Load();
        ennemieSpawner.newWave(1);
}

void GameManager::Update()
{
    std::cout << playerMoney << std::endl;
    mapManager.Update();
    ennemieSpawner.Update();
}

void GameManager::Draw()
{
    mapManager.Draw();
    ennemieSpawner.Draw();
}

void GameManager::Unload()
{
    mapManager.Unload();
    ennemieSpawner.Unload();
}
