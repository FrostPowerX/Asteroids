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
			std::string bNames[maxButtons];

			float offset = ButtonHeight * 2;
			float posx = ScreenWidth / 2;
			float posy = offset;


			void Init()
			{
				bNames[0] = "Play";
				bNames[1] = "Controlls";
				bNames[2] = "Credits";
				bNames[3] = "Exit";

				for (int i = 0; i < maxButtons; i++)
				{
					buttons[i] = CreateButton(bNames[i], posx, posy);
					
					posy += offset;
				}
			}

			void Input()
			{
				for (int i = 0; i < maxButtons; i++)
				{
					MouseOnTopButton(buttons[i]);
					if (IsButtonPressed(buttons[i]))
						currentScene = SCENE(i);
				}
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