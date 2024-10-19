#include "SpaceShip.h"

#include <math.h>

#include "managers/InputManager.h"
#include "managers/SpriteManager.h"
#include "utilities/Utils.h"

namespace game
{
	namespace spaceship
	{
		void Move(SpaceShip& sp, Vector2 target);
		void Rotate(SpaceShip& sp, Vector2 target);
		void Shoot(SpaceShip& sp);

		void ActualizePos(SpaceShip& sp);
		void NormalizeVelocity(SpaceShip& sp);

		SpaceShip Create(Circle cir, Graphic graph, std::string textureName, float speed, float maxSpeed, int lives, bool isAlive)
		{
			SpaceShip ship;
			ship.body = cir;

			graph.dest.x = cir.x;
			graph.dest.y = cir.y;

			ship.velocity = Vector2{ 0,0 };
			ship.rotationAngle = 0;

			ship.graphic.source = graph.source;
			ship.graphic.dest = graph.dest;
			ship.graphic.origin = graph.origin;

			ship.speed = speed;
			ship.maxSpeed = maxSpeed;

			ship.lives = lives;

			ship.isAlive = isAlive;

			ship.graphic.spriteSheet = spritemanager::GetSprite(textureName).texture;

			return ship;
		}

		void Update(SpaceShip& sp)
		{
			Rotate(sp, GetMousePosition());

			if (input::GetKey("Shoot"))
				Shoot(sp);

			if(input::GetKey("Move"))
				Move(sp, GetMousePosition());

			ActualizePos(sp);
		}

		void Draw(SpaceShip sp)
		{
			DrawCircle(sp.body.x, sp.body.y, sp.body.radius, RED);
			DrawTexturePro(sp.graphic.spriteSheet, sp.graphic.source, sp.graphic.dest, sp.graphic.origin, sp.rotationAngle + 90, WHITE);
		}

		void Move(SpaceShip& sp, Vector2 target)
		{
			Vector2 normDir;
			normDir.x = target.x - sp.body.x;
			normDir.y = target.y - sp.body.y;
			normDir = NormalizeVector(normDir);

			sp.velocity.x += normDir.x * sp.speed * GetFrameTime();
			sp.velocity.y += normDir.y * sp.speed * GetFrameTime();

			float maxSpeedX = sp.maxSpeed;
			float maxSpeedY = sp.maxSpeed;

			maxSpeedX *= (sp.velocity.x > 0) ? 1 : -1;
			maxSpeedY *= (sp.velocity.y > 0) ? 1 : -1;

			sp.velocity.x = (abs(sp.velocity.x) > sp.maxSpeed) ? maxSpeedX : sp.velocity.x;
			sp.velocity.y = (abs(sp.velocity.y) > sp.maxSpeed) ? maxSpeedY : sp.velocity.y;
		}
		void Rotate(SpaceShip& sp, Vector2 target)
		{
			double x = target.x - sp.body.x;
			double y = target.y - sp.body.y;

			double angle = atan(y / x);

			angle = RadiansToGrades(angle);

			if (x < 0 && y > 0)
				angle += 180;
			else if (x < 0 && y <= 0)
				angle += 180;
			else if (x > 0 && y < 0)
				angle += 360;

			sp.rotationAngle = angle;
		}
		void Shoot(SpaceShip& sp)
		{
			std::cout << "Disparo\n";
		}

		void ActualizePos(SpaceShip& sp)
		{
			sp.body.x += sp.velocity.x * GetFrameTime();
			sp.body.y += sp.velocity.y * GetFrameTime();

			sp.graphic.dest.x = sp.body.x;
			sp.graphic.dest.y = sp.body.y;
		}
		void NormalizeVelocity(SpaceShip& sp)
		{
			float magnitude = GetMagnitud(sp.velocity);
			float normalVel = magnitude / sp.maxSpeed;

			if (normalVel > 1.0)
			{
				sp.velocity = NormalizeVector(sp.velocity);
			}
		}
	}

}
