#pragma once

#include "raylib.h"

#include "utilities/Circle.h"

#include "managers/SpriteManager.h"

namespace game
{
	using namespace spritemanager;

	namespace asteroid
	{
		struct Asteroid
		{
			Circle body;

			Graphic graphic;

			Vector2 velocity;

			float speed;
			float maxSpeed;
			float rotationAngle;

			bool isAlive;
		};

		Asteroid Create(Circle cir, Rectangle dest, std::string textureName, float speed, float maxSpeed, bool isAlive);

		void Update(Asteroid a);
		void Draw(Asteroid a);

		bool IsAlive(Asteroid a);
	}
}