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
        if (timer <= restTime) {
            timer += GetFrameTime();
        }
        else {
            newWave(wave + 1);
            timer = 0;
        }
    }
}

void EnnemieSpawner::Draw()
{
    for (int i = 0; i < ennemies.size(); i++) {
        ennemies[i].Draw();
    }
    if (timer != 0) {
        DrawText(TextFormat("NEW WAVE IN %s", std::to_string((int)(restTime - timer)).c_str()), 500 - MeasureText(TextFormat("NEW WAVE IN %s", std::to_string((int)(restTime - timer)).c_str()), 30)/2, 900, 30, WHITE);
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
    ennemiePerWave = (int)((float)_wave * 2.4f);
    ennemieSpeed += wave;
    ennemieLife += wave;
    spawning = true;
}
