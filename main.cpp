#include "raylib.h"
#include "GameManager.h"


void Load();
void Update();
void Draw();
void Unload();

MapManager mapManager;
hudManager HUD;
EnnemieSpawner ennemieSpawner(mapManager);
GameManager gameManager(ennemieSpawner, mapManager, HUD);

int main() {
    Load();

    while (!WindowShouldClose()) {
        ClearBackground(GREEN);

        Draw();
        Update();
    }
    Unload();
    CloseWindow();
    return 0;
}

void Load()
{
    InitWindow(1000, 1000, "Bloons TD7");
    SetTargetFPS(60);
    gameManager.Load();
}

void Update()
{
    gameManager.Update();
}

void Draw()
{
    BeginDrawing();
    gameManager.Draw();
    EndDrawing();
}

void Unload()
{
    gameManager.Unload();
}
