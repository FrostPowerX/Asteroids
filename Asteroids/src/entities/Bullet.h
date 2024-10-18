#pragma once

#include "raylib.h"

struct Bullet
{
	Vector2 direction;
	Vector2 position;

	float speed;

	float dmg;

	float isAlive;
};