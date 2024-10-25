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
				float screenWidth = static_cast<float>(GetScreenWidth());
				float screenHeight = static_cast<float>(GetScreenHeight());

				Rectangle dest{ 0,0,32,32 };

				Circle cir;
				cir.x = screenWidth / 2;
				cir.y = screenHeight / 2;
				cir.radius = 15;

				player = Create(cir, dest, "PlayerShip", 500, 500);
			}
		}
	}
}