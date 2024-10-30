#include "SceneMenu.h"

#include "raylib.h"

#include "GameLoop.h"

#include "managers/ResolutionManager.h"
#include "managers/SoundManager.h"
#include "managers/GameManager.h"

#include "ui/Button.h"
#include "ui/Panel.h"

using namespace game::resolutionmanager;

using namespace button;

namespace game
{
	namespace scenes
	{
		namespace menu
		{
			const int maxButtonsPMenu = 4;

			Button buttons[maxButtonsPMenu];
			std::string bNames[maxButtonsPMenu];

			panel::Panel panel;

			text::Text hightScore;

			void Init()
			{
				soundmanager::PlayM("MenuM");

				hightScore = text::Create("High Score        ", (GetScreenWidth() / 2), 160, 20, WHITE);

				panel = panel::Create("Title", Rectangle{ static_cast<float>(GetScreenWidth() / 2),60,240,120 }, "");

				float offset = (ButtonHeight * 1.5f) * GetScale().y;
				float posx = currentWidth / 2.f;
				float posy = offset + ((ButtonHeight * 1.5f) * GetScale().y);

				bNames[0] = "Play";
				bNames[1] = "Options";
				bNames[2] = "Credits";
				bNames[3] = "Exit";

				for (int i = 0; i < maxButtonsPMenu; i++)
				{
					buttons[i] = Create("Button", Rectangle{ posx, posy, ButtonWidth, ButtonHeight }, bNames[i]);

					posy += offset;
				}
			}

			void Input()
			{
				for (int i = 0; i < maxButtonsPMenu; i++)
				{
					MouseOnTop(buttons[i]);
					if (IsPressed(buttons[i]))
						currentScene = SCENE(i);
					if (currentScene == SCENE::GAMEPLAY)
					{
						soundmanager::StopM("MenuM");
						soundmanager::PlayM("GamePlayM");
					}
				}
			}

			void Update()
			{
				hightScore.text = "High Score: " + std::to_string(gamemanager::GetMaxScore());
			}

			void Draw()
			{
				for (int i = 0; i < maxButtonsPMenu; i++)
				{
					Draw(buttons[i]);
				}

				if (gamemanager::GetMaxScore() > 0)
					text::Draw(hightScore);

				panel::Draw(panel);
			}

			void DeInit()
			{

			}
		}
	}
}