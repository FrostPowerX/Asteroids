#include "SceneMenu.h"

#include "raylib.h"

#include "GameLoop.h"

#include "managers/ResolutionManager.h"

#include "ui/Button.h"

using namespace game::resolutionmanager;

using namespace button;

namespace game
{
	namespace scenes
	{
		namespace menu
		{
			const int maxButtons = 4;

			Button buttons[maxButtons];
			std::string bNames[maxButtons];

			void Init()
			{
				float offset = (ButtonHeight * GetScale().y) * 2.f;
				float posx = currentWidth / 2.f;
				float posy = offset;

				bNames[0] = "Play";
				bNames[1] = "Controlls";
				bNames[2] = "Credits";
				bNames[3] = "Exit";

				for (int i = 0; i < maxButtons; i++)
				{
					buttons[i] = Create(bNames[i], posx, posy);
					
					posy += offset;
				}
			}

			void Input()
			{
				for (int i = 0; i < maxButtons; i++)
				{
					MouseOnTop(buttons[i]);
					if (IsPressed(buttons[i]))
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
					Draw(buttons[i]);
				}
			}

			void DeInit()
			{

			}
		}
	}
}