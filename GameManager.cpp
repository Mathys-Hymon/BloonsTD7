#include "GameManager.h"


GameManager::GameManager(EnnemieSpawner& ennemieSpawner, MapManager& mapManager) : ennemieSpawner(ennemieSpawner), mapManager(mapManager)
{
}

GameManager::~GameManager()
{
    Unload();
}

void GameManager::Load()
{
    turretSprite = LoadTexture("resources/texture/turret.png");
    mapManager.Load();
    ennemieSpawner.Load();
    ennemieSpawner.newWave(1);
}

void GameManager::Update()
{
    mapManager.Update();
    ennemieSpawner.Update();

    for (int i = 0; i < turrets.size(); i++) {
        turrets[i].Update();
    }

    Vector2 mousePosition = GetMousePosition();

    if (mapManager.CheckTileType(mousePosition) == TileType::GRASS) {


        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && playerMoney >= turretPrice && turretDelay >= 0.1f)
        {
            Tile* tileRef = mapManager.GetGridTile(mousePosition);

            turretDelay = 0;
            playerMoney -= turretPrice;
            mapManager.GetGridTile(mousePosition)->SetType(TileType::TURRET);

            Vector2 turretPos = { tileRef->GetPosition().x + tileRef->GetSize() / 2,tileRef->GetPosition().y + tileRef->GetSize() / 2 };
            turrets.emplace_back(turretPos, ennemieSpawner, turretSprite, tileRef->GetSize());
        }
        else {
            turretDelay += GetFrameTime();
        }
    }
    else if (mapManager.CheckTileType(mousePosition) == TileType::TURRET) {
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && turretDelay >= 0.1f)
        {
            turretDelay = 0;
            playerMoney += turretPrice / 2;
            Tile* tileRef = mapManager.GetGridTile(mousePosition);

            for (size_t i = 0; i < turrets.size(); i++) {
                if (turrets[i].GetPosition().x == tileRef->GetPosition().x + tileRef->GetSize() / 2 && turrets[i].GetPosition().y == tileRef->GetPosition().y + tileRef->GetSize() / 2) {
                    //turrets.erase(turrets.begin() + i);
                    mapManager.GetGridTile(mousePosition)->SetType(TileType::GRASS);
                    playerMoney += turretPrice / 2;
                    break;
                }
            }
        }
        else {
            turretDelay += GetFrameTime();
        }
    }
}

void GameManager::Draw()
{
    mapManager.Draw();
    ennemieSpawner.Draw();

    for (int i = 0; i < turrets.size(); i++) {
        turrets[i].Draw();
    }

    Vector2 mousePosition = GetMousePosition();
    if (mapManager.CheckTileType(mousePosition) == TileType::GRASS) {

        Tile* tileRef = mapManager.GetGridTile(mousePosition);

        if (playerMoney >= turretPrice) {

            DrawText(TextFormat("LMB:%s coins", std::to_string(turretPrice).c_str()), mousePosition.x + 30, mousePosition.y, 20, WHITE);

            DrawRectangleLines(tileRef->GetPosition().x, tileRef->GetPosition().y, tileRef->GetSize(), tileRef->GetSize(), WHITE);
        }
        else {
            DrawText(TextFormat("LMB:%s coins", std::to_string(turretPrice).c_str()), mousePosition.x + 30, mousePosition.y, 20, RED);

            DrawRectangleLines(tileRef->GetPosition().x, tileRef->GetPosition().y, tileRef->GetSize(), tileRef->GetSize(), RED);
        }
    }
    else if(mapManager.CheckTileType(mousePosition) == TileType::TURRET) {

        Tile* tileRef = mapManager.GetGridTile(mousePosition);
            DrawText(TextFormat("LMB to sell:%s coins", std::to_string(turretPrice /2).c_str()), mousePosition.x + 30, mousePosition.y, 20, WHITE);

            DrawRectangleLines(tileRef->GetPosition().x, tileRef->GetPosition().y, tileRef->GetSize(), tileRef->GetSize(), RED);
    }
}

void GameManager::Unload()
{
    mapManager.Unload();
    ennemieSpawner.Unload();

    for (int i = 0; i < turrets.size(); i++) {
        turrets[i].Unload();
    }
}
