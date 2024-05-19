#pragma once
#include "EnnemieSpawner.h"
class Turret
{
private:

	EnnemieSpawner& ennemieSpawner;
	Vector2 position;

	float rotation = 0;
	float shootRate = 0.5f;
	float damages = 101;
	float shootRange = 200;
	float spriteScale;

	Texture& sprite;

public:

	Turret(Vector2 pos, EnnemieSpawner& ennemieSpawnerRef, Texture& sprite, float spriteScale);
	~Turret();

	Vector2 GetPosition() const;

	void Shoot(Ennemie* target);
	void Update();
	void Draw();
	void Unload();
};

