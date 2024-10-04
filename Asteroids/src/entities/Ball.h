#ifndef BALL
#define BALL

#include <iostream>

#include "raylib.h"
#include "..\utilities\Circle.h"

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

Ball CreateBall(Color, float x, float y ,float radius, float speed);

void TeleportBall(Ball&, float, float);

void MoveBall(Ball&);

void ChangeColorBall(Ball&, Color);

void ChangeRadiusBall(Ball&, float);

void ChangeBallSpeed(Ball&, float);

void DrawBall(Ball&);

#endif // !BALL
