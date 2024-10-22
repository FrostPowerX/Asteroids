#pragma once

#include "raylib.h"

namespace bullet
{
	struct Bullet
	{
		Rectangle rect;

		Vector2 target;

		float speed;

		float dmg;

		bool isAlive;
	};

	Bullet Create(Rectangle rect, Vector2 direction, float speed = 200, float dmg = 15, bool isAlive = true);

	void Move(Bullet& bullet);

	void Update(Bullet& bullet);
	void Draw(Bullet bullet);

	void OnCollision(Bullet& bullet);
}