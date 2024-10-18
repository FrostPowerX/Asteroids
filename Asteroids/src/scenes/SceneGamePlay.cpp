#include "SceneGamePlay.h"

#include "entities/SpaceShip.h"


namespace game
{
	using namespace spaceship;

	namespace scenes
	{
		namespace gameplay
		{
			SpaceShip player;

			void CreatePlayer();

			void Init()
			{
				CreatePlayer();
			}

			void Input()
			{

			}
			void Update()
			{
				Update(player);
			}
			void Draw()
			{
				Draw(player);
			}

			void DeInit()
			{

			}

			void CreatePlayer()
			{
				float screenWidth = GetScreenWidth();
				float screenHeight = GetScreenHeight();

				Rectangle source{ 0,0,32,32 };
				Rectangle dest{ 0,0,16,16 };
				Vector2 origin{ 0,0 };

				Circle cir;

				std::string textureName = "PlayerShip";

				Graphic graph{ Texture2D(),
								source,
								dest,
								origin };

				player = Create(cir, graph, textureName, 500, 800, 3, true);
			}
		}
	}
}