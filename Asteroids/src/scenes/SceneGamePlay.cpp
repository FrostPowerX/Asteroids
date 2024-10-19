#include "SceneGamePlay.h"

#include "GameLoop.h"
#include "entities/SpaceShip.h"
#include "managers/InputManager.h"

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
				if (input::GetKey("Back"))
					currentScene = SCENE::MENU;
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
				Rectangle dest{ 0,0,32,32 };
				Vector2 origin{ 16,16 };

				Circle cir;
				cir.x = screenWidth / 2;
				cir.y = screenHeight / 2;
				cir.radius = 15;


				std::string textureName = "PlayerShip";

				Graphic graph{ Texture2D(),
								source,
								dest,
								origin };

				player = Create(cir, graph, textureName, 500, 500, 3, true);
			}
		}
	}
}