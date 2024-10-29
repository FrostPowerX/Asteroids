#pragma once

#include "entities/Asteroid.h"

namespace game
{
	using namespace asteroid;

	namespace asteroidsmanager
	{
		const int maxAsteroids = 500;

		void Init();

		void Update();
		void Draw();

		void ActiveAsteroid();
		void DeactiveAsteroid(int index);

		Asteroid& GetAsteroid(int index);
	}
}