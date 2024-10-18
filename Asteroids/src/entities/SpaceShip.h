#pragma once

#include <iostream>

#include "raylib.h"

#include "utilities/Circle.h"

struct SpaceShip
{
	Texture2D spriteSheet;
	Rectangle source;
	Rectangle dest;
	Vector2 origin;

	Circle body;

	Vector2 velocity;

	float speed;
	float maxSpeed;

	int lives;

	bool isAlive;
};

SpaceShip CreateShip(std::string path, Rectangle source, Rectangle dest, Vector2 origin);