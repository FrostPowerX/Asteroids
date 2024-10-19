#include "SceneControlls.h"

#include "GameLoop.h"

#include "managers/InputManager.h"

namespace game
{
	namespace scenes
	{
		namespace controlls
		{


			void Init()
			{

			}

			void Input()
			{
				if (input::GetKey("Back"))
					currentScene = SCENE::MENU;
			}
			void Update()
			{

			}
			void Draw() 
			{

			}

			void DeInit()
			{

			}
		}
	}
}
