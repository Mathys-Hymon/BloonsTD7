#pragma once
#include "EnnemieSpawner.h"
class Turret
{
private:
	EnnemieSpawner& ennemieSpawner;
	Vector2 position;

	float rotation = 0;

public:

	Turret();
	~Turret();
};

