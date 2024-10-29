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

			float invencibleT;
			float resetInvT;

			int lives;

			bool tripleShoot;
			bool isAlive;
		};

		SpaceShip Create(Circle cir, Rectangle dest, std::string textureName, float speed, float maxSpeed, float invencibleT = 3.0f, float reloadTime = 0.4f, int lives = 3, bool isAlive = true);

		void TakeDamage(SpaceShip& sp);

		void Update(SpaceShip& sp);
		void Draw(SpaceShip sp);

		bullet::Bullet& GetBullet(SpaceShip& sp, int index);
	}
}
