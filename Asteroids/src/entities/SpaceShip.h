#pragma once

#include <iostream>

#include "raylib.h"

#include "utilities/Circle.h"

#include "entities/Bullet.h"

#include "managers/SpriteManager.h"

using namespace game::spritemanager;

namespace game
{
	namespace spaceship
	{
		const int maxBullets = 500;

		struct SpaceShip
		{
			Circle body;

			Graphic graphic;

			Vector2 velocity;

			bullet::Bullet bullets[maxBullets];

			float speed;
			float maxSpeed;
			float rotationAngle;

			float reloadTime;
			float resetTime;

			int lives;

			bool isAlive;
		};

		SpaceShip Create(Circle cir, Rectangle dest, std::string textureName, float speed, float maxSpeed, float reloadTime = 0.2f, int lives = 3, bool isAlive = true);

		void TakeDamage(SpaceShip& sp);

		void Update(SpaceShip& sp);
		void Draw(SpaceShip sp);
	}
}
