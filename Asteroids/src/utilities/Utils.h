#pragma once

#include <iostream>

#include "raylib.h"

#include "Circle.h"
//#include "entities\Ball.h"

//using namespace ball;

enum TYPE_PENETRATION
{
	HORIZONTAL,
	VERTICAL,
	NONE
};

bool CheckCollision(Rectangle, Rectangle);
bool CheckCollision(Rectangle, Circle);

bool CheckCollision(Circle, Circle);
bool CheckCollision(Circle, Rectangle);

bool CheckBorderCollision(Circle, int maxWidth, int minWidth, int maxHeight, int minHeight);
bool CheckBorderCollision(Rectangle, int maxWidth, int minWidth, int maxHeight, int minHeight);

TYPE_PENETRATION SolveCollision(Rectangle&, Circle&);
TYPE_PENETRATION SolveCollision(Circle& entityA, Circle& entityB);

//TYPE_PENETRATION SolveCollisionMap(Ball&, int maxWidth, int minWidth, int maxHeight, int minHeight);
TYPE_PENETRATION SolveCollisionMap(Rectangle&, int maxWidth, int minWidth, int maxHeight, int minHeight);

Vector2 NormalizeVector(Vector2 vector);
void NormalizeVector(float& x, float& y);

float GetMagnitud(Vector2 vector);

double RadiansToGrades(double r);

//void BouncingAngle(Ball& ball, Rectangle& rect);

//void BouncingBalls(Ball& c1, Ball& c2);