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
			Button example;

			void Init()
			{
				example = CreateButton(0, 0, 50, 25, "Credits", 10, RED, WHITE, PURPLE, YELLOW);
			}

			void Input()
			{
			}

			void Update()
			{
				MouseOnTopButton(example);
				if (IsButtonPressed(example))
					currentScene = SCENE::CREDITS;
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