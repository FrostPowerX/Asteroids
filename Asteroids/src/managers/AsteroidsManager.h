#pragma once

#include "entities/Asteroid.h"
#include "entities/PowerUp.h"

namespace game
{
	using namespace asteroid;
	using namespace powerup;

	namespace asteroidsmanager
	{
		const int maxAsteroids = 500;
		const int maxPowers = 10;

		void Init();

		void Update();
		void Draw();

		void ActiveAsteroid();
		void ActivePower();
		void DeactiveAsteroid(int index);
		void DeactivePower(int index);

		Asteroid& GetAsteroid(int index);
		PowerUp& GetPowers(int index);
	}
}