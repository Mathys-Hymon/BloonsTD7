#include "raylib.h"
#include <iostream>

void Load();
void Start();
void Update();
void Draw();
void Unload();

int main() {
    Load();

    while (!WindowShouldClose()) {
        Update();
        Draw();
    }

    Unload();
    CloseWindow();
    return 0;
}

void Load()
{
    InitWindow(500.128, 500.2, "Bloons TD7");
    SetTargetFPS(60);
}

void Start()
{
}

void Update()
{
}

void Draw()
{
    BeginDrawing();
    ClearBackground(GREEN);
    EndDrawing();
}

void Unload()
{
}
