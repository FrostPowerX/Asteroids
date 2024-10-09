#ifndef POWER_UP
#define POWER_UP

#include "raylib.h"

struct PowerUp
{
	Rectangle rect;

	Color rectColor;

	float addHeight;
	float addSpeed;
	int addBalls;

	int toPlayer;

	bool isActive;
};

PowerUp CreatePowerUp(Rectangle rect, Color rectColor, float heightPlus, float speedPlus, int ballsPlus);

void DrawPowerUp(PowerUp& pUp, int screenWidth, int screenHeight);

#endif // !POWER_UP
