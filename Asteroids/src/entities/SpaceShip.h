#pragma once

#include <iostream>

#include "raylib.h"

#include "utilities/Circle.h"
#include "entities/Bullet.h"

namespace spaceship
{
	const int maxBullets = 25;

	struct SpaceShip
	{
		Texture2D spriteSheet;
		Rectangle source;
		Rectangle dest;
		Vector2 origin;

		Circle body;

		Vector2 velocity;

		bullet::Bullet bullets[maxBullets];

		float speed;
		float maxSpeed;

		int lives;

		bool isAlive;
	};

	SpaceShip Create(std::string texturePath, Rectangle source, Rectangle dest, Vector2 origin, float speed, float maxSpeed, int lives, bool isAlive);

	void Move(SpaceShip& sp, Vector2 target);
	void Rotate(SpaceShip& sp, Vector2 target);
	void Shoot(SpaceShip& sp);

	void Update(SpaceShip& sp);
	void Draw(SpaceShip sp);
}