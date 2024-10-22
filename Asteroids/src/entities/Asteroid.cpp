#include "Asteroid.h"

#include "managers/ResolutionManager.h"

namespace game
{
	using namespace resolutionmanager;

	namespace asteroid
	{
		Asteroid Create(Circle cir, Rectangle dest, std::string textureName, float speed, float maxSpeed, bool isAlive)
		{
			Asteroid newA;

			cir.radius *= GetScalef();

			newA.body = cir;

			dest.width *= GetScale().x;
			dest.height *= GetScale().y;

			dest.x = cir.x;
			dest.y = cir.y;

			newA.velocity = Vector2{ 0,0 };
			newA.rotationAngle = 0;

			newA.graphic.source = Rectangle{ 0,0,textureWidth,textureHeight };
			newA.graphic.dest = dest;
			newA.graphic.origin = Vector2{ (textureWidth / 2) * GetScale().x,(textureHeight / 2) * GetScale().y };

			newA.speed = speed;
			newA.maxSpeed = maxSpeed;

			newA.isAlive = isAlive;

			newA.graphic.spriteSheet = GetSprite(textureName).texture;

			return newA;

			return Asteroid();
		}

		void Update(Asteroid a)
		{
			
		}

		void Draw(Asteroid a)
		{
			DrawCircleLines(a.body.x, a.body.y, a.body.radius, RED);
			DrawTexturePro(a.graphic.spriteSheet, a.graphic.source, a.graphic.dest, a.graphic.origin, a.rotationAngle + 90, WHITE);
		}

		bool IsAlive(Asteroid a)
		{
			return false;
		}
	}
}