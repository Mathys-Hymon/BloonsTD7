#pragma once
#include "EnnemieSpawner.h"
class Turret
{
private:
	EnnemieSpawner& ennemieSpawner;
	Vector2 position;

	float rotation = 0;

public:

	Turret(Vector2 pos, EnnemieSpawner& ennemieSpawnerRef);
	~Turret();

	Vector2 GetPosition() const;

	void Update();
	void Draw();
	void Unload();
};

