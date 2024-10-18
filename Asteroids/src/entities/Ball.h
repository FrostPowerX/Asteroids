#pragma once

#include <iostream>

#include "raylib.h"
#include "..\utilities\Circle.h"

namespace ball
{
	struct Ball
	{
		Circle cir;
		Color color;
		Color colorBorder;

		float dirX;
		float dirY;

		float speed;

		int playerId;

		bool isActive;
	};

	Ball Create(Color, float x, float y, float radius, float speed);

	void Teleport(Ball&, float, float);

	void Move(Ball&);

	void ChangeColor(Ball&, Color);

	void ChangeRadius(Ball&, float);

	void ChangeSpeed(Ball&, float);

	void Draw(Ball&, int screenWidth, int screenHeight);
}