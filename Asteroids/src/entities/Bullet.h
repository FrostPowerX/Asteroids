#pragma once

#include "raylib.h"

namespace bullet
{
	struct Bullet
	{
		Vector2 target;
		Vector2 position;

		float speed;

		float dmg;

		bool isAlive;
	};

	Bullet Create(Vector2 position, Vector2 direction, float speed = 200, float dmg = 15, bool isAlive = true);

	void Move(Bullet& bullet);

	void Update(Bullet& bullet);
	void Draw(Bullet bullet);

	void OnCollision(Bullet& bullet);
}