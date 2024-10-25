#pragma once

#include "entities/Asteroid.h"

namespace game
{
	namespace asteroidsmanager
	{
		void Init();


		void AddAsteroid(asteroid::Asteroid ast);
		void Remove(asteroid::Asteroid ast);

		void ActiveAsteroid(asteroid::Asteroid ast);
		void DeactiveAsteroid(asteroid::Asteroid ast);
	}
}