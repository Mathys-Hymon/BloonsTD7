#include "hudManager.h"

hudManager::hudManager()
{
}

hudManager::~hudManager()
{
}

void hudManager::switchScreen(int index)
{
	screenIndex = index;
}


void hudManager::Draw()
{
	switch (screenIndex)
	{
	case 0:  //MAIN MENU

		DrawText("BLOONS TD 7", 500 - MeasureText("BLOONS TD 7", 70) /2, 200, 70, BLACK);
		if (button({ 380,500 }, "START", { 150,100 })) {
			screenIndex = 1;
		}
		break;
	case 1:  //INGAME

		DrawText(TextFormat("LIVES : %s", std::to_string(castleHealth).c_str()), 200 - MeasureText(TextFormat("LIVES : %s", std::to_string(castleHealth).c_str()), 30) /2, 50, 30, BLACK);
		DrawText(TextFormat("WAVE : %s", std::to_string(wave).c_str()), 500 - MeasureText(TextFormat("WAVE : %s", std::to_string(wave).c_str()), 30) / 2, 50, 30, BLACK);
		DrawText(TextFormat("MONEY : %s", std::to_string(playerMoney).c_str()), 800 - MeasureText(TextFormat("MONEY : %s", std::to_string(playerMoney).c_str()), 30) / 2, 50, 30, BLACK);
		break;
	case 2: //VICTORY / DEFEAT

		DrawText("CONGRATULATIONS, YOU'VE SURVIVED", 500 - MeasureText("CONGRATULATIONS, YOU'VE SURVIVED", 30) / 2, 200, 30, BLACK);
		DrawText(TextFormat("%s WAVES", std::to_string(wave).c_str()), 150 - MeasureText(TextFormat("%s WAVES", std::to_string(wave).c_str()), 15) / 2, 200, 15, WHITE);

		if (button({ 380,500 }, "RESTART", { 150,100 })) {
			wave = 1;
			screenIndex = 1;
			playerMoney = playerStartMoney;
			castleHealth = castleMaxLife;
		}

		else if (button({ 380,650 }, "MAIN MENU", { 150,100 })) {
			wave = 1;
			screenIndex = 0;
			playerMoney = playerStartMoney;
			castleHealth = castleMaxLife;
		}
		break;


	default:
		break;
	}
}


bool hudManager::button(Vector2 position, std::string text, Vector2 size)
{
	DrawRectangle(position.x, position.y, size.x + static_cast<float>(MeasureText(text.c_str(), 20)), size.y, BLUE);
	DrawText(text.c_str(), position.x + size.x / 2, position.y + size.y / 3, 20, WHITE);

	if (CheckCollisionPointRec(static_cast<Vector2>(GetMousePosition()), { position.x, position.y,size.x + static_cast<float>(MeasureText(text.c_str(), 20)), size.y })) {

		DrawRectangle(position.x, position.y, size.x + static_cast<float>(MeasureText(text.c_str(), 20)), size.y, DARKBLUE);
		DrawText(text.c_str(), position.x + size.x / 2, position.y + size.y / 3, 20, GRAY);
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
			return true;
		}
		else {
			return false;
		}
	}

	return false;
}
