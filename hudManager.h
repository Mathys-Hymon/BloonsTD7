#pragma once
#include "raylib.h"
#include "playerDATA.h"
#include <vector>
#include <iostream>
#include <string>


class hudManager
{
private :
	int _screenIndex;

public :

	hudManager();
	~hudManager();

	void switchScreen(int index);
	void Draw();
	bool button(Vector2 position, std::string text, Vector2 size);
};

