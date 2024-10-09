#include "SceneMenu.h"

#include "raylib.h"

#include "GameLoop.h"
#include "ui/Button.h"

namespace game
{
	namespace scenes
	{
		namespace menu
		{
			const int maxButtons = 4;

			Button buttons[maxButtons];

			void Init()
			{
				//example = CreateButton(0, 0, 50, 25, "Credits", 10, RED, WHITE, PURPLE, YELLOW);
			}

			void Input()
			{
				MouseOnTopButton(buttons[0]);
				if (IsButtonPressed(buttons[0]))
					currentScene = SCENE::CREDITS;
			}

			void Update()
			{
				
			}

			void Draw()
			{
				for (int i = 0; i < maxButtons; i++)
				{
					DrawButton(buttons[i]);
				}
			}

			void DeInit()
			{

			}
		}
	}
}