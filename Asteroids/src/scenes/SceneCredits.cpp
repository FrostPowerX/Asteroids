#include "SceneCredits.h"

#include "raylib.h"

#include "GameLoop.h"
#include "ui/Button.h"

namespace game
{
	namespace scenes
	{
		namespace credits
		{
			Button example;

			void Init()
			{
				example = CreateButton(0, 0, 50, 25, "Menu", 10, RED, WHITE, PURPLE, YELLOW);
			}

			void Input()
			{
			}

			void Update()
			{
				MouseOnTopButton(example);
				if (IsButtonPressed(example))
					currentScene = SCENE::MENU;
			}

			void Draw()
			{
				DrawButton(example);
			}

			void DeInit()
			{

			}
		}
	}
}