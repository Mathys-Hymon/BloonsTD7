#include "EnnemieSpawner.h"

void EnnemieSpawner::newWave(int wave)
{
    float ennemiePerWave = wave * 2.4;

    for (int i = 0; i < (int)ennemiePerWave; ++i) {
        //spawn Ennemie
        // Délai de 1 seconde entre chaque spawn
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}
