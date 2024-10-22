#include "Bullet.h"

#include "managers/ResolutionManager.h"

using namespace game::resolutionmanager;

namespace bullet
{
	Bullet Create(Rectangle rect, Vector2 direction, float speed, float dmg, bool isAlive)
	{
		return Bullet();
	}

	void Move(Bullet& bullet)
	{
	}

	void Update(Bullet& bullet)
	{
		Move(bullet);
	}
	void Draw(Bullet bullet)
	{
	}

	void OnCollision(Bullet& bullet)
	{
	}
}


