#include "SceneControls.h"

#include "GameLoop.h"

#include "managers/InputManager.h"

namespace game
{
	namespace scenes
	{
		namespace controls
		{


			void Init()
			{

			}

			void Input()
			{
				if (input::GetKeyDown("Back"))
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
