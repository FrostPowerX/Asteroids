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
		const int maxBullets = 25;

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

		SpaceShip Create(Circle cir, Rectangle dest, std::string textureName, float speed, float maxSpeed, int lives, bool isAlive);

		void Update(SpaceShip& sp);
		void Draw(SpaceShip sp);
	}
}
