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

		newB.graphic.origin = Vector2{ (dest.width / 2) * GetScale().x,(dest.height / 2) * GetScale().y };
		dest.width *= GetScale().x;
		dest.height *= GetScale().y;

		dest.x = cir.x;
		dest.y = cir.y;

		newB.timeAlive = timeAlive;
		newB.resetTime = timeAlive;
		newB.rotationAngle = 0;

		newB.graphic.source = Rectangle{ 0,0,textureWidth,textureHeight };
		newB.graphic.dest = dest;

		newB.speed = speed;

		newB.isAlive = isAlive;

		newB.graphic.spriteSheet = GetSprite(textureName).texture;

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

		DrawCircleLines(static_cast<int>(bullet.body.x), static_cast<int>(bullet.body.y), bullet.body.radius, RED);
		DrawTexturePro(bullet.graphic.spriteSheet, bullet.graphic.source, bullet.graphic.dest, bullet.graphic.origin, bullet.rotationAngle + 90, WHITE);
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

	void Shoot(Bullet& bullet, Vector2 position, Vector2 target)
	{
		bullet.body.x = position.x;
		bullet.body.y = position.y;

		SetTarget(bullet, target);

		float x = bullet.target.x - bullet.body.x;
		float y = bullet.target.y - bullet.body.y;

		float angle = atan(y / x);

		angle = static_cast<float>(RadiansToGrades(angle));

		if (x < 0 && y > 0)
			angle += 180;
		else if (x < 0 && y <= 0)
			angle += 180;
		else if (x > 0 && y < 0)
			angle += 360;

		bullet.rotationAngle = angle;

		bullet.timeAlive = bullet.resetTime;
		bullet.isAlive = true;
	}
}


