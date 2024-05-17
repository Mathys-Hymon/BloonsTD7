#include "Turret.h"
#include <cmath> // Pour sqrt et pow

Turret::Turret(Vector2 pos, EnnemieSpawner& ennemieSpawnerRef, Texture& sprite, float spriteScale)
    : position(pos), ennemieSpawner(ennemieSpawnerRef), sprite(sprite), spriteScale(spriteScale)
{
}

Turret::~Turret()
{
}

Vector2 Turret::GetPosition() const
{
    return position;
}

void Turret::Update()
{
    std::vector<Ennemie>& ennemies = ennemieSpawner.GetEnnemies();
    float closestDistance = shootRange;
    Ennemie* target = nullptr;

    for (Ennemie& ennemi : ennemies) {

        if (ennemi.IsDead() == false) {
            float distance = sqrt(pow(ennemi.GetPosition().x - position.x, 2) + pow(ennemi.GetPosition().y - position.y, 2));
        if (distance < closestDistance) {
            closestDistance = distance;
            target = &ennemi;
        }
        }
        
    }

    if (target != nullptr) {

        float dx = target->GetPosition().x - position.x;
        float dy = target->GetPosition().y - position.y;
        rotation = atan2(dy, dx) * (180.0f / PI);

        static float timeSinceLastShot = 0.0f;
        timeSinceLastShot += GetFrameTime();
        if (timeSinceLastShot >= shootRate) {
            timeSinceLastShot = 0.0f;
            Shoot(target);
        }
    }
}

void Turret::Shoot(Ennemie* target)
{
    target->TakeDamage(damages);
}

void Turret::Draw()
{
    Vector2 spriteSize = { static_cast<float>(sprite.width), static_cast<float>(sprite.height) };

    DrawTexturePro(sprite, { 0, 0, spriteSize.x, spriteSize.y }, { position.x, position.y, spriteScale, spriteScale }, { spriteScale / 2, spriteScale / 2 }, rotation + 90, WHITE);
    DrawCircleLines(position.x, position.y, shootRange, RED);
}

void Turret::Unload()
{
}