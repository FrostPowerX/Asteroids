#pragma once

#include "raylib.h"

#include "managers/SpriteManager.h"

using namespace game::spritemanager;

namespace powerup
{
	struct PowerUp
	{
		Graphic graph;

		Rectangle sourceUsed;

		Vector2 target;
		Vector2 dir;

		float animTime;
		float resetTime;

		float speed;

		bool isActive;
	};

	PowerUp Create(std::string spriteName, Rectangle rect, Vector2 target, float speed = 20.f, bool isAlive = false);

	void Update(PowerUp& p);

	void Draw(PowerUp& pUp);

	void SetTarget(PowerUp& p, Vector2 target);
}