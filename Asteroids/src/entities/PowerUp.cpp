#include "PowerUP.h"

#include "managers/ResolutionManager.h"

#include "utilities/Utils.h"

using namespace game::resolutionmanager;

namespace powerup
{
	void Move(PowerUp& p);
	void Animation(PowerUp& p);

	PowerUp Create(std::string spriteName, Rectangle dest, Vector2 target, float speed, bool isAlive)
	{
		PowerUp newP;

		dest.x *= GetScale().x;
		dest.y *= GetScale().y;

		dest.width *= GetScale().x;
		dest.height *= GetScale().y;

		newP.graph.sprite = GetSprite(spriteName)->texture;

		newP.graph.origin = Vector2{ (0),(0) };
		newP.graph.source = Rectangle{ 0,0,textureWidth, textureHeight };
		newP.graph.dest = dest;

		newP.sourceUsed = newP.graph.source;

		newP.speed = speed;
		newP.isActive = isAlive;

		newP.animTime = 0;
		newP.resetTime = 0.2f;

		SetTarget(newP, target);

		return newP;
	}

	void Update(PowerUp& p)
	{
		Move(p);
		Animation(p);
	}



	void Draw(PowerUp& pUp)
	{

#ifdef _DEBUG
		DrawRectangle(static_cast<int>(pUp.graph.dest.x), static_cast<int>(pUp.graph.dest.y), static_cast<int>(pUp.graph.dest.width), static_cast<int>(pUp.graph.dest.height), GREEN);
#endif

		DrawTexturePro(pUp.graph.sprite, pUp.sourceUsed, pUp.graph.dest, pUp.graph.origin, 0, WHITE);
	}

	void Move(PowerUp& p)
	{
		p.graph.dest.x += p.dir.x * p.speed * GetFrameTime();
		p.graph.dest.y += p.dir.y * p.speed * GetFrameTime();
	}

	void Animation(PowerUp& p)
	{
		p;
	}

	void SetTarget(PowerUp& p, Vector2 target)
	{
		Vector2 dir = Vector2{ 0,0 };;
		p.target = target;

		dir.x = p.target.x - p.graph.dest.x;
		dir.y = p.target.y - p.graph.dest.y;

		dir = NormalizeVector(dir);

		p.dir = dir;
	}
}

