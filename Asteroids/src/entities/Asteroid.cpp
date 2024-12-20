#include "Asteroid.h"

#include "managers/ResolutionManager.h"

#include "utilities/Utils.h"

namespace game
{
	using namespace resolutionmanager;

	namespace asteroid
	{
		void Move(Asteroid& ast);

		Asteroid Create(Circle cir, Rectangle dest, std::string textureName, Vector2 target, AsteroidType type, float speed, bool isAlive)
		{
			Asteroid newA;

			cir.radius *= GetScalef();

			newA.body = cir;

			dest.width *= GetScale().x;
			dest.height *= GetScale().y;

			dest.x = cir.x;
			dest.y = cir.y;

			newA.rotationAngle = static_cast<float>(GetRandomValue(0,360));

			newA.graphic.origin = Vector2{ (dest.width / 2), (dest.height / 2) };
			newA.graphic.source = Rectangle{ 0,0,textureWidth,textureHeight };
			newA.graphic.dest = dest;

			newA.type = type;
			newA.speed = speed;

			newA.isAlive = isAlive;

			newA.graphic.sprite = GetSprite(textureName)->texture;

			SetTarget(newA, target);

			return newA;
		}

		void Move(Asteroid& ast)
		{
			ast.body.x += ast.dir.x * ast.speed * GetFrameTime();
			ast.body.y += ast.dir.y * ast.speed * GetFrameTime();

			ast.graphic.dest.x = ast.body.x;
			ast.graphic.dest.y = ast.body.y;
		}

		void Update(Asteroid& ast)
		{
			if (!ast.isAlive)
				return;

			Move(ast);
		}

		void Draw(Asteroid ast)
		{
			if (!ast.isAlive)
				return;

#ifdef _DEBUG
			DrawCircleLines(static_cast<int>(ast.body.x), static_cast<int>(ast.body.y), ast.body.radius, RED);
#endif // !DEBUG

			DrawTexturePro(ast.graphic.sprite, ast.graphic.source, ast.graphic.dest, ast.graphic.origin, ast.rotationAngle + 90, WHITE);
		}

		void SetTarget(Asteroid& ast, Vector2 target)
		{
			Vector2 dir = Vector2{ 0,0 };;
			ast.target = target;

			dir.x = ast.target.x - ast.body.x;
			dir.y = ast.target.y - ast.body.y;

			dir = NormalizeVector(dir);

			ast.dir = dir;
		}
	}
}