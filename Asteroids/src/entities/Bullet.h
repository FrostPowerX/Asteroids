#pragma once

#include "raylib.h"

#include "utilities/Circle.h"

#include "managers/SpriteManager.h"

namespace bullet
{
	using namespace game::spritemanager;

	struct Bullet
	{
		Circle body;

		Graphic graphic;

		Vector2 target;
		Vector2 dir;

		float rotationAngle;

		float speed;

		float timeAlive;
		float resetTime;

		float dmg;

		bool isAlive;
	};

	Bullet Create(Circle cir, Rectangle rect, std::string textureName, Vector2 target, float speed = 500.f, float timeAlive = 1.f, bool isAlive = false);


	void Update(Bullet& bullet);
	void Draw(Bullet bullet);

	void SetTarget(Bullet& bullet, Vector2 target);
	void Shoot(Bullet& bullet, Vector2 position, Vector2 target, float addAngle = 0);

	void OnCollision(Bullet& bullet);
}