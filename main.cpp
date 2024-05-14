#include "raylib.h"
#include "MapManager.h"

void Load();
void Update();
void Draw();
void Unload();

MapManager mapManager;

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
    mapManager.Load();
}

void Update()
{
    mapManager.Update();
}

void Draw()
{
    BeginDrawing();
    mapManager.Draw();

    EndDrawing();
}

void Unload()
{
    mapManager.Unload();
}
