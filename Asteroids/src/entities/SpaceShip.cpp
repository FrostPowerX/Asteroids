#include "SpaceShip.h"

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

		SpaceShip Create(Circle cir, Graphic graph, std::string textureName, float speed, float maxSpeed, int lives, bool isAlive)
		{
			SpaceShip ship;
			ship.body = cir;

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

		void Move(SpaceShip& sp, Vector2 target)
		{

		}
		void Rotate(SpaceShip& sp, Vector2 target)
		{
			float x = sp.body.x;
			float y = target.y;

			float r = sqrt(x * x + y * y);

			float angle = atan(y / x);

			x = r * cos(angle);
			y = r * sin(angle);

			if (x < 0 && y > 0)
				angle += 180;
			else if (x < 0 && y < 0)
				angle += 180;
			else if (x > 0 && y > 0)
				angle += 360;

			sp.rotationAngle = angle;
		}
		void Shoot(SpaceShip& sp)
		{
			std::cout << "Disparo\n";
		}

		void Update(SpaceShip& sp)
		{
			Rotate(sp, GetMousePosition());
			Move(sp, GetMousePosition());

			if (input::GetKey("Shoot"))
				Shoot(sp);
		}
		void Draw(SpaceShip sp)
		{
			DrawTexturePro(sp.graphic.spriteSheet, sp.graphic.source, sp.graphic.dest, sp.graphic.origin, sp.rotationAngle, WHITE);
		}
	}

}
