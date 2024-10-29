#include "SceneCredits.h"

#include "raylib.h"

#include "GameLoop.h"

#include "managers/InputManager.h"
#include "managers/ResolutionManager.h"

#include "ui/Panel.h"
#include "ui/Button.h"
#include "ui/Text.h"

using namespace button;
using namespace text;
using namespace panel;
using namespace game::resolutionmanager;

namespace game
{
	namespace scenes
	{
		namespace credits
		{
			const int maxLinksButtons = 5;

			Panel panels[maxLinksButtons];

			Button backButton;
			Button linksButtons[maxLinksButtons];
			Text texts[maxLinksButtons];

			void PanelInit();
			void TextInit();
			void ButtonInit();

			void Init()
			{
				PanelInit();
				TextInit();
				ButtonInit();
			}

			void Input()
			{
				if (input::GetKeyDown("Back"))
					currentScene = SCENE::MENU;

				if (IsPressed(backButton))
					currentScene = SCENE::MENU;

				for (size_t i = 0; i < maxLinksButtons; i++)
				{
					if (IsPressed(linksButtons[i]))
						switch (i)
						{
						case 0:
							OpenURL("https://frostpower.itch.io/");
							break;

						case 1:
							OpenURL("https://frostpower.itch.io/");
							break;

						case 2:
							OpenURL("https://www.artstation.com/victoria_thjellesen");
							break;

						case 3:
							break;

						case 4:
							break;
						}
				}
			}

			void Update()
			{
				MouseOnTop(backButton);
				for (int i = 0; i < maxLinksButtons; i++)
				{
					MouseOnTop(linksButtons[i]);
				}
			}

			void Draw()
			{
				Draw(backButton);
				for (int i = 0; i < maxLinksButtons; i++)
				{
					Draw(panels[i]);
					Draw(texts[i]);
					Draw(linksButtons[i]);
				}
			}

			void DeInit()
			{

			}

			void PanelInit()
			{
				float width = 300;
				float height = 60;

				float midWidth = GetScreenWidth() / 2;
				float offSetHeight = (height * GetScale().y) * 2;


				panels[0] = panel::Create("Panel", Rectangle{ midWidth,offSetHeight ,width,height }, "DEVELOPER");
				panels[1] = panel::Create("Panel", Rectangle{ midWidth,offSetHeight * 2,width,height }, "TEXTURES");
				panels[2] = panel::Create("Panel", Rectangle{ midWidth,offSetHeight * 3.4f,width,height }, "SOUNDS");
				panels[3] = panel::Create("Panel", Rectangle{ midWidth,offSetHeight * 4.4f,width,height }, "SPECIAL MENTIONS");
			}

			void TextInit()
			{
				texts[0] = text::Create("Emanuel Parajon", panels[0].graph.dest.x + (panels[0].graph.dest.width / 2), panels[0].graph.dest.y + panels[0].graph.dest.height * 1.2f, 20, WHITE);
				texts[1] = text::Create("Buttons, Panels, ScoreBoard By Emanuel Parajon", panels[1].graph.dest.x + (panels[1].graph.dest.width / 2), panels[1].graph.dest.y + panels[1].graph.dest.height * 1.2f, 20, WHITE);
				texts[2] = text::Create("SpaceShips, Asteroids, Backgrounds By Victoria Thjellesen", panels[1].graph.dest.x + (panels[1].graph.dest.width / 2), panels[1].graph.dest.y + panels[1].graph.dest.height * 1.8f, 20, WHITE);
				texts[3] = text::Create("Sergio Baretto", panels[3].graph.dest.x + (panels[3].graph.dest.width / 2), panels[3].graph.dest.y + panels[3].graph.dest.height * 1.2f, 20, WHITE);
				texts[4] = text::Create("Stefano Cvitanich", panels[3].graph.dest.x + (panels[3].graph.dest.width / 2), panels[3].graph.dest.y + panels[3].graph.dest.height * 1.8f, 20, WHITE);
			}

			void ButtonInit()
			{
				backButton = button::Create("Button", Rectangle{ ButtonWidth / 2,  ButtonHeight / 2, ButtonWidth, ButtonHeight }, "Back");

				for (int i = 0; i < maxLinksButtons; i++)
				{
					float x = texts[i].position.x + MeasureText(texts[i].text.c_str(), texts[i].font) + 32;
					float y = texts[i].position.y + 8;

					linksButtons[i] = button::Create("LinkButton", Rectangle{ x,y,32,32 }, "");
				}
			}
		}
	}
}