#include "SceneCredits.h"

#include "raylib.h"

#include "GameLoop.h"
#include "ui/Button.h"

using namespace button;

namespace game
{
	namespace scenes
	{
		namespace credits
		{
			Button example;

			void Init()
			{
				example = Create("Menu", 0, 0);
			}

			void Input()
			{
			}

			void Update()
			{
				MouseOnTop(example);
				if (IsPressed(example))
					currentScene = SCENE::MENU;
			}

			void Draw()
			{
				Draw(example);
			}

			void DeInit()
			{

			}
		}
	}
}