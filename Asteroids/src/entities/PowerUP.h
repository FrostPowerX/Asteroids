#pragma once

#include "raylib.h"

namespace powerup
{
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

	PowerUp Create(Rectangle rect, Color rectColor, float heightPlus, float speedPlus, int ballsPlus);

	void Draw(PowerUp& pUp, int screenWidth, int screenHeight);
}