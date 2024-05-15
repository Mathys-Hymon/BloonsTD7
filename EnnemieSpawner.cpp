#include "EnnemieSpawner.h"

EnnemieSpawner::EnnemieSpawner(MapManager& mapManager) : mapManager(mapManager)
{
}

EnnemieSpawner::~EnnemieSpawner()
{
}

void EnnemieSpawner::Load()
{
    ennemieSprite = LoadTexture("resources/texture/bloon.png");
}

void EnnemieSpawner::Update()
{

    if (spawning) {
        spawnTimer -= GetFrameTime();
        if (spawnTimer <= 0.0f) {
            Ennemie newEnnemie(mapManager, ennemieSprite, mapManager.EnnemieSpawnPos(), ennemieSpeed, ennemieLife);
            ennemies.push_back(newEnnemie);

            if (ennemies.size() >= ennemiePerWave) {
                spawning = false;
            }
            else {
                spawnTimer = 0.5f;
            }
        }
    }

    int ennemiesAlive = 0;

    for (int i = 0; i < ennemies.size(); i++) {

        if (ennemies[i].IsDead()) {
        }
        else {
        ennemies[i].Update();
        ennemiesAlive++;
         }
    }

    if (!spawning && ennemiesAlive == 0) {
        newWave(wave + 1);
    }
}

void EnnemieSpawner::Draw()
{
    for (int i = 0; i < ennemies.size(); i++) {
        ennemies[i].Draw();
    }
}

void EnnemieSpawner::Unload()
{
    UnloadTexture(ennemieSprite);

    for (int i = 0; i < ennemies.size(); i++) {
        ennemies[i].Unload();
    }
}

void EnnemieSpawner::newWave(int _wave)
{
    ennemies.clear();

    wave = _wave;
    ennemiePerWave = 1;
    ennemieSpeed += wave;
    ennemieLife += wave;
    spawning = true;
}
