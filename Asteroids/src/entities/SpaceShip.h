#pragma once

#include <iostream>

#include "raylib.h"

#include "utilities/Circle.h"
#include "entities/Bullet.h"

namespace game
{
	namespace spaceship
	{
		const int maxBullets = 25;

		struct Graphic
		{
			Texture2D spriteSheet;

			Rectangle source;
			Rectangle dest;
			Vector2 origin;
		};

		struct SpaceShip
		{
			Circle body;

			Graphic graphic;

			Vector2 velocity;

			bullet::Bullet bullets[maxBullets];

			float speed;
			float maxSpeed;
			float rotationAngle;

			int lives;

			bool isAlive;
		};

		SpaceShip Create(Circle cir, Graphic graph, std::string textureName, float speed, float maxSpeed, int lives, bool isAlive);

		void Move(SpaceShip& sp, Vector2 target);
		void Rotate(SpaceShip& sp, Vector2 target);
		void Shoot(SpaceShip& sp);

		void Update(SpaceShip& sp);
		void Draw(SpaceShip sp);
	}
}
