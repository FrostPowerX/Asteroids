#include "AsteroidsManager.h"

namespace game
{
	namespace asteroidsmanager
	{
		Asteroid asteroids[maxAsteroids];

		PowerUp power[maxPowers];

		float resetCount = 10.f;
		float countDown = 0;

		float resetCountP = 60.f;
		float countDownP = resetCountP;

		int astToSpawn = 2;

		void SpawnAsteroid(Vector2 position, AsteroidType type);

		void CreatePowerUp();

		void Init()
		{
			for (int i = 0; i < maxAsteroids; i++)
			{
				AsteroidType type = static_cast<AsteroidType>(GetRandomValue(0, static_cast<int>(AsteroidType::LARGE)));
				Rectangle rect{};
				Circle cir{};

				float vel = 0;

				switch (type)
				{
				case game::asteroid::AsteroidType::SMALL:
					rect = { 0,0,16,16 };
					cir = { 0,0,8 };
					vel = 75.f;
					break;

				case game::asteroid::AsteroidType::NORMAL:
					rect = { 0,0,32,32 };
					cir = { 0,0,16 };
					vel = 50.f;
					break;

				case game::asteroid::AsteroidType::LARGE:
					rect = { 0,0,64,64 };
					cir = { 0,0,32 };
					vel = 25.f;
					break;

				default:
					break;
				}

				asteroids[i] = Create(cir, rect, "Asteroid", Vector2{ 0,0 }, type, vel);
			}

			CreatePowerUp();
		}

		void Update()
		{
			for (int i = 0; i < maxAsteroids; i++)
			{
				if (asteroids[i].isAlive)
					Update(asteroids[i]);
			}

			for (int i = 0; i < maxPowers; i++)
			{
				if (power[i].isActive)
					powerup::Update(power[i]);
			}

			countDown -= (GetFrameTime() < countDown) ? GetFrameTime() : countDown;
			countDownP -= (GetFrameTime() < countDownP) ? GetFrameTime() : countDownP;

			if (countDown <= 0)
			{
				for (int i = 0; i < astToSpawn; i++)
				{
					ActiveAsteroid();
				}
				countDown = resetCount;
				astToSpawn++;
			}

			if (countDownP <= 0)
			{
				ActivePower();
				countDownP = resetCountP;
			}
		}

		void Draw()
		{
			for (int i = 0; i < maxAsteroids; i++)
			{
				if (asteroids[i].isAlive)
					Draw(asteroids[i]);
			}

			for (int i = 0; i < maxPowers; i++)
			{
				if (power[i].isActive)
					powerup::Draw(power[i]);
			}
		}

		void ActiveAsteroid()
		{
			for (int i = 0; i < maxAsteroids; i++)
			{
				if (!asteroids[i].isAlive)
				{
					float x = 0;
					float y = 0;

					Vector2 randTarget;

					switch (GetRandomValue(1, 4))
					{
					case 1:
						x = static_cast<float>(GetRandomValue(0, GetScreenWidth()));
						y = static_cast<float>(-asteroids[i].body.radius);
						break;

					case 2:
						x = static_cast<float>(-asteroids[i].body.radius);
						y = static_cast<float>(GetRandomValue(0, GetScreenHeight()));
						break;

					case 3:
						x = static_cast<float>(GetRandomValue(0, GetScreenWidth()));
						y = static_cast<float>(GetScreenHeight() + asteroids[i].body.radius);
						break;

					case 4:
						x = static_cast<float>(GetScreenWidth() + asteroids[i].body.radius);
						y = static_cast<float>(GetRandomValue(0, GetScreenHeight()));
						break;
					}

					asteroids[i].body.x = x;
					asteroids[i].body.y = y;

					randTarget.x = static_cast<float>(GetRandomValue(0, GetScreenWidth()));
					randTarget.y = static_cast<float>(GetRandomValue(0, GetScreenHeight()));

					SetTarget(asteroids[i], randTarget);

					asteroids[i].isAlive = true;

					return;
				}
			}
		}
		void DeactiveAsteroid(int index)
		{
			if (asteroids[index].isAlive)
			{
				asteroids[index].isAlive = false;

				switch (asteroids[index].type)
				{
				case AsteroidType::NORMAL:
					SpawnAsteroid(Vector2{ asteroids[index].body.x, asteroids[index].body.y }, AsteroidType::SMALL);
					SpawnAsteroid(Vector2{ asteroids[index].body.x, asteroids[index].body.y }, AsteroidType::SMALL);
					break;

				case AsteroidType::LARGE:
					SpawnAsteroid(Vector2{ asteroids[index].body.x, asteroids[index].body.y }, AsteroidType::NORMAL);
					SpawnAsteroid(Vector2{ asteroids[index].body.x, asteroids[index].body.y }, AsteroidType::NORMAL);
					break;

				}


			}
		}

		void DeactivePower(int index)
		{
			if (power[index].isActive)
				power[index].isActive = false;
		}

		Asteroid& GetAsteroid(int index)
		{
			return asteroids[index];
		}

		PowerUp& GetPowers(int index)
		{
			return power[index];
		}

		void SpawnAsteroid(Vector2 position, AsteroidType type)
		{
			for (int i = 0; i < maxAsteroids; i++)
			{
				if (!asteroids[i].isAlive && asteroids[i].type == type)
				{
					float x = position.x;
					float y = position.y;

					Vector2 randTarget;

					asteroids[i].body.x = x;
					asteroids[i].body.y = y;
					asteroids[i].graphic.dest.x = x;
					asteroids[i].graphic.dest.y = y;

					randTarget.x = static_cast<float>(GetRandomValue(0, GetScreenWidth()));
					randTarget.y = static_cast<float>(GetRandomValue(0, GetScreenHeight()));

					SetTarget(asteroids[i], randTarget);

					asteroids[i].isAlive = true;

					return;
				}
			}
		}


		void ActivePower()
		{
			for (int i = 0; i < maxPowers; i++)
			{
				if (!power[i].isActive)
				{
					float x = 0;
					float y = 0;

					Vector2 randTarget;

					switch (GetRandomValue(1, 4))
					{
					case 1:
						x = static_cast<float>(GetRandomValue(0, GetScreenWidth()));
						y = static_cast<float>(-power[i].graph.dest.height);
						break;

					case 2:
						x = static_cast<float>(-power[i].graph.dest.width);
						y = static_cast<float>(GetRandomValue(0, GetScreenHeight()));
						break;

					case 3:
						x = static_cast<float>(GetRandomValue(0, GetScreenWidth()));
						y = static_cast<float>(GetScreenHeight() + power[i].graph.dest.height);
						break;

					case 4:
						x = static_cast<float>(GetScreenWidth() + power[i].graph.dest.width);
						y = static_cast<float>(GetRandomValue(0, GetScreenHeight()));
						break;
					}

					power[i].graph.dest.x = x;
					power[i].graph.dest.y = y;

					randTarget.x = static_cast<float>(GetRandomValue(0, GetScreenWidth()));
					randTarget.y = static_cast<float>(GetRandomValue(0, GetScreenHeight()));

					SetTarget(power[i], randTarget);

					power[i].isActive = true;

					return;
				}
			}
		}

		void CreatePowerUp()
		{
			for (int i = 0; i < maxPowers; i++)
			{
				power[i] = powerup::Create("PowerUp", Rectangle{0,0,32,32}, Vector2{0,0});
			}
		}
	}
}
