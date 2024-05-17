#include "Ennemie.h"

Ennemie::Ennemie(MapManager& mapManager, Texture& sprite, Vector2 pos, float speed, int life) : sprite(sprite), position(pos), mapManager(mapManager), targetPosition(pos), life(life), speed(speed), maxLife(life)
{
     spriteScale = mapManager.GetGridTile(position)->GetSize();
}

Ennemie::~Ennemie()
{
}

void Ennemie::Update()
{
    if (!isDead) {

        if ((direction.x > 0 && position.x >= targetPosition.x) || (direction.x < 0 && position.x <= targetPosition.x) || (direction.y > 0 && position.y >= targetPosition.y) || (direction.y < 0 && position.y <= targetPosition.y)) {
            std::vector<Vector2> directionsToCheck;
            directionsToCheck.push_back(direction);
            directionsToCheck.push_back({ direction.y, direction.x });
            directionsToCheck.push_back({ -direction.y, -direction.x });

            for (int i = 0; i < 3; i++) {
                    Vector2 newPos = mapManager.CheckTile(position, directionsToCheck[i]);
                    if (newPos.x < 0 && newPos.y < 0) {
                        isDead = true;
                        castleHealth -= damage;
                    }
                    else if (newPos.x > 0 && newPos.y > 0) {
                        targetPosition = newPos;
                        direction = directionsToCheck[i];
                        directionsToCheck.clear();
                        break;
                    }
            }
        }
        else {
            position.x += direction.x * GetFrameTime() * speed;
            position.y += direction.y * GetFrameTime() * speed;
        }
    }
   
}

void Ennemie::Draw()
{
    if (!isDead) {
        Vector2 spriteSize = { sprite.width,sprite.height };

        DrawTexturePro(sprite, { 0,0,spriteSize.x,spriteSize.y }, { position.x, position.y, spriteScale,spriteScale }, { spriteScale / 2,spriteScale /2}, 0, WHITE);
        
        float lifeRation = ((float)life / (float)maxLife) * 30.0;
        DrawRectangle(position.x - 16, position.y - 29, 32, 8, WHITE);
        DrawRectangle(position.x - 15, position.y - 28, lifeRation, 6, RED);
    }
}

void Ennemie::Unload()
{
	UnloadTexture(sprite);
}

void Ennemie::TakeDamage(int damage)
{
    life -= damage;

    if (life <= 0) {
        isDead = true;
        playerMoney += coins;
    }
}

Vector2 Ennemie::GetPosition()
{
    return position;
}

bool Ennemie::IsDead()
{
    return isDead;
}
