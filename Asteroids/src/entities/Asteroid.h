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

			Vector2 target;
			Vector2 dir;

			float speed;
			float rotationAngle;

			bool isAlive;
		};

		Asteroid Create(Circle cir, Rectangle dest, std::string textureName, Vector2 target, float speed, bool isAlive = false);

		void Update(Asteroid& ast);
		void Draw(Asteroid ast);

		void SetTarget(Asteroid& ast, Vector2 target);
	}
}