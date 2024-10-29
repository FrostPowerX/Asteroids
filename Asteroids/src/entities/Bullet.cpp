#include "Bullet.h"

#include "managers/ResolutionManager.h"

#include "utilities/Utils.h"

using namespace game::resolutionmanager;

namespace bullet
{
	void Move(Bullet& bullet);

	Bullet Create(Circle cir, Rectangle dest, std::string textureName, Vector2 target, float speed, float timeAlive, bool isAlive)
	{
		Bullet newB;

		cir.radius *= GetScalef();

		newB.body = cir;

		dest.width *= GetScale().x;
		dest.height *= GetScale().y;

		dest.x = cir.x;
		dest.y = cir.y;

		newB.timeAlive = timeAlive;
		newB.resetTime = timeAlive;
		newB.rotationAngle = 0;

		newB.graphic.origin = Vector2{ (dest.width / 2),(dest.height / 2) };
		newB.graphic.source = Rectangle{ 0,0,textureWidth,textureHeight };
		newB.graphic.dest = dest;

		newB.speed = speed;

		newB.isAlive = isAlive;

		newB.graphic.sprite = GetSprite(textureName)->texture;

		SetTarget(newB, target);

		return newB;
	}

	void Move(Bullet& bullet)
	{
		bullet.body.x += bullet.dir.x * bullet.speed * GetFrameTime();
		bullet.body.y += bullet.dir.y * bullet.speed * GetFrameTime();

		bullet.graphic.dest.x = bullet.body.x;
		bullet.graphic.dest.y = bullet.body.y;
	}

	void Update(Bullet& bullet)
	{
		if (!bullet.isAlive)
			return;

		Move(bullet);

		bullet.timeAlive -= (GetFrameTime() < bullet.timeAlive) ? GetFrameTime() : bullet.timeAlive;

		if (bullet.timeAlive == 0)
			bullet.isAlive = false;
	}
	void Draw(Bullet bullet)
	{
		if (!bullet.isAlive)
			return;

#ifdef _DEBUG
		DrawCircleLines(static_cast<int>(bullet.body.x), static_cast<int>(bullet.body.y), bullet.body.radius, RED);
#endif // _DEBUG

		DrawTexturePro(bullet.graphic.sprite, bullet.graphic.source, bullet.graphic.dest, bullet.graphic.origin, bullet.rotationAngle + 90, WHITE);
	}

	void SetTarget(Bullet& bullet, Vector2 target)
	{
		Vector2 dir = Vector2{ 0,0 };;

		bullet.target = target;

		dir.x = bullet.target.x - bullet.body.x;
		dir.y = bullet.target.y - bullet.body.y;

		dir = NormalizeVector(dir);

		bullet.dir = dir;
	}

	void Shoot(Bullet& bullet, Vector2 position, Vector2 target, float addAngle)
	{
		bullet.body.x = position.x;
		bullet.body.y = position.y;

		SetTarget(bullet, target);

		float x = bullet.target.x - bullet.body.x;
		float y = bullet.target.y - bullet.body.y;

		float angle = atan(y / x);

		float r = sqrt(x * x + y * y);

		angle = static_cast<float>(RadiansToGrades(angle));

		if (x < 0 && y > 0)
			angle += 180;
		else if (x < 0 && y <= 0)
			angle += 180;
		else if (x > 0 && y < 0)
			angle += 360;

		bullet.rotationAngle = angle + addAngle;

		if (addAngle != 0)
		{
			bullet.rotationAngle += (bullet.rotationAngle >= 360) ? -360 : 0;
			bullet.rotationAngle += (bullet.rotationAngle < 0) ? 360 : 0;

			float angleNew = static_cast<float>(GradesToRadians(bullet.rotationAngle));

			x = r * cos(angleNew);
			y = r * sin(angleNew);

			bullet.rotationAngle = static_cast<float>(RadiansToGrades(atan(y / x)));

			if (x < 0 && y > 0)
				bullet.rotationAngle += 180;
			else if (x < 0 && y <= 0)
				bullet.rotationAngle += 180;
			else if (x > 0 && y < 0)
				bullet.rotationAngle += 360;

			SetTarget(bullet, Vector2{ bullet.body.x + x , bullet.body.y + y });
		}

		bullet.timeAlive = bullet.resetTime;
		bullet.isAlive = true;
	}
	void OnCollision(Bullet& bullet)
	{
		bullet.isAlive = false;
	}
}


