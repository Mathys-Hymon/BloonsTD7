#include "Turret.h"

Turret::Turret(Vector2 pos, EnnemieSpawner& ennemieSpawnerRef) : position(pos), ennemieSpawner(ennemieSpawnerRef)
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
}

void Turret::Draw()
{
	DrawCircle(position.x, position.y, 10, RED);
}

void Turret::Unload()
{
}
