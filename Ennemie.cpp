#include "Ennemie.h"

Ennemie::Ennemie(MapManager& mapManager, Texture& sprite, Vector2 pos, float speed, int life) : sprite(sprite), position(pos), mapManager(mapManager), targetPosition(pos), life(life), speed(speed)
{
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
            directionsToCheck.push_back({ direction.y, direction.x }); // À droite
            directionsToCheck.push_back({ -direction.y, -direction.x }); // À gauche

            for (int i = 0; i < 3; i++) {
                    Vector2 newPos = mapManager.CheckTile(position, directionsToCheck[i]);
                    if (newPos.x < 0 && newPos.y < 0) {
                        isDead = true;
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
        float scaleDivided = 7;

        DrawTexturePro(sprite, { 0,0,spriteSize.x,spriteSize.y }, { position.x, position.y, spriteSize.x / scaleDivided,spriteSize.y / scaleDivided }, { (spriteSize.x / scaleDivided) / 2,(spriteSize.y / scaleDivided) /2}, 0, WHITE);
    }
}

void Ennemie::Unload()
{
	UnloadTexture(sprite);
}

void Ennemie::TakeDamage(int damage)
{
    life -= damage;

    if (life < 0) {
        isDead = true;
    }
}

bool Ennemie::IsDead()
{
    return isDead;
}
