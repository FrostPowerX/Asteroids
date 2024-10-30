#include "SpaceShip.h"

#include <math.h>

#include "managers/InputManager.h"
#include "managers/ResolutionManager.h"
#include "managers/SoundManager.h"

#include "utilities/Utils.h"

using namespace game::resolutionmanager;
using namespace game::soundmanager;

namespace game
{
	namespace spaceship
	{
		void Move(SpaceShip& sp, Vector2 target);
		void Rotate(SpaceShip& sp, Vector2 target);
		void Shoot(SpaceShip& sp, bool isTriple = false);

		void ActiveBullet(SpaceShip& sp, bool tripleShoot = false);

		void ActualizePos(SpaceShip& sp);
		void NormalizeVelocity(SpaceShip& sp);

		SpaceShip Create(Circle cir, Rectangle dest, std::string textureName, float speed, float maxSpeed, float invencibleT, float reloadTime, int lives, bool isAlive)
		{
			SpaceShip ship;

			cir.radius *= GetScalef();

			ship.body = cir;

			dest.width *= GetScale().x;
			dest.height *= GetScale().y;

			dest.x = cir.x;
			dest.y = cir.y;

			ship.reloadTime = 0;
			ship.resetTime = reloadTime;

			ship.invencibleT = 0;
			ship.resetInvT = invencibleT;

			ship.velocity = Vector2{ 0,0 };
			ship.rotationAngle = 0;

			ship.graphic.origin = Vector2{ (dest.width / 2),(dest.height / 2) };
			ship.graphic.source = Rectangle{ 0,0,textureWidth,textureHeight };
			ship.graphic.dest = dest;

			ship.speed = speed;
			ship.maxSpeed = maxSpeed;

			ship.lives = lives;

			ship.tripleShoot = false;
			ship.isAlive = isAlive;

			ship.graphic.sprite = spritemanager::GetSprite(textureName)->texture;

			for (int i = 0; i < maxBullets; i++)
			{
				Rectangle rect = Rectangle{ 0,0,16,16 };
				cir.radius = 5;

				ship.bullets[i] = bullet::Create(cir, rect, "Bullet", Vector2{ 0,0 });
			}
			return ship;
		}

		void TakeDamage(SpaceShip& sp)
		{
			if (sp.invencibleT > 0)
				return;

			PlayS("DmgRec");

			sp.invencibleT = sp.resetInvT;
			sp.lives--;

			if (sp.lives <= 0)
				sp.isAlive = false;
		}

		void Update(SpaceShip& sp)
		{
			if (!sp.isAlive)
				return;

			for (int i = 0; i < maxBullets; i++)
			{
				bullet::Update(sp.bullets[i]);
			}

			Rotate(sp, GetMousePosition());

			if (input::GetKeyDown("Shoot") && sp.reloadTime <= 0)
				Shoot(sp, sp.tripleShoot);

			if (input::GetKeyDown("Move"))
			{
				PlayS("Move");
				Move(sp, GetMousePosition());
			}
			else
				StopS("Move");

			sp.reloadTime -= (GetFrameTime() < sp.reloadTime) ? GetFrameTime() : sp.reloadTime;
			sp.invencibleT -= (GetFrameTime() < sp.invencibleT) ? GetFrameTime() : sp.invencibleT;

			ActualizePos(sp);
		}

		void Draw(SpaceShip sp)
		{
			if (!sp.isAlive)
				return;

			Color color;

			for (int i = 0; i < maxBullets; i++)
			{
				bullet::Draw(sp.bullets[i]);
			}

			if (sp.invencibleT <= 0)
				color = WHITE;
			else
				color = { 100,100,100,150 };

#ifdef _DEBUG
			DrawCircleLines(static_cast<int>(sp.body.x), static_cast<int>(sp.body.y), sp.body.radius, WHITE);
#endif // _DEBUG

			DrawTexturePro(sp.graphic.sprite, sp.graphic.source, sp.graphic.dest, sp.graphic.origin, sp.rotationAngle + 90, color);
		}

		bullet::Bullet& GetBullet(SpaceShip& sp, int index)
		{
			return sp.bullets[index];
		}

		void Move(SpaceShip& sp, Vector2 target)
		{
			Vector2 normDir = Vector2{ 0,0 };
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
			float x = target.x - sp.body.x;
			float y = target.y - sp.body.y;

			if (target.x == sp.body.x && target.y == sp.body.y)
				return;

			float angle = atan(y / x);

			angle = static_cast<float>(RadiansToGrades(angle));

			if (x < 0 && y > 0)
				angle += 180;
			else if (x < 0 && y <= 0)
				angle += 180;
			else if (x > 0 && y < 0)
				angle += 360;

			sp.rotationAngle = angle;
		}
		void Shoot(SpaceShip& sp, bool isTriple)
		{
			PlayS("Shoot");

			ActiveBullet(sp, isTriple);

			sp.reloadTime = sp.resetTime;
		}

		void ActiveBullet(SpaceShip& sp, bool tripleShoot)
		{
			if (tripleShoot)
			{
				const int maxSBull = 3;
				int count = 0;

				bullet::Bullet* bullets[maxSBull] = { nullptr,nullptr ,nullptr };

				for (int i = 0; i < maxBullets; i++)
				{
					if (!sp.bullets[i].isAlive)
					{
						bullets[count] = &sp.bullets[i];

						count++;
						if (count >= maxSBull)
							break;
					}
				}

				if (bullets[0] != nullptr)
					bullet::Shoot(*bullets[0], Vector2{ sp.body.x,sp.body.y }, GetMousePosition());

				if (bullets[1] != nullptr)
					bullet::Shoot(*bullets[1], Vector2{ sp.body.x,sp.body.y }, GetMousePosition(), 22.5f);

				if (bullets[2] != nullptr)
					bullet::Shoot(*bullets[2], Vector2{ sp.body.x,sp.body.y }, GetMousePosition(), -22.5f);
			}
			else
				for (int i = 0; i < maxBullets; i++)
				{
					if (!sp.bullets[i].isAlive)
					{
						bullet::Shoot(sp.bullets[i], Vector2{ sp.body.x,sp.body.y }, GetMousePosition());
						break;
					}
				}
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
