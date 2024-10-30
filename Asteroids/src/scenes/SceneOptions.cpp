#include "SceneOptions.h"

#include "GameLoop.h"

#include "managers/InputManager.h"
#include "managers/SpriteManager.h"
#include "managers/ResolutionManager.h"

#include "ui/Button.h"

namespace game
{
	using namespace spritemanager;
	using namespace resolutionmanager;

	namespace scenes
	{
		namespace options
		{
			enum PAGE
			{
				VIDEO,
				CONTROLS,
				AUDIO
			};

			button::Button menu;
			button::Button video;
			button::Button controls;
			button::Button audio;

			PAGE currentPage = PAGE::VIDEO;

			void ButtonsInit();

			void Init()
			{
				ButtonsInit();
			}

			void Input()
			{
				if (input::GetKeyDown("Back") || button::IsPressed(menu))
					currentScene = SCENE::MENU;

				if(button::IsPressed(video))
					currentPage = PAGE::VIDEO;
				if (button::IsPressed(controls))
					currentPage = PAGE::CONTROLS;
				if (button::IsPressed(audio))
					currentPage = PAGE::AUDIO;
			}
			void Update()
			{
				button::MouseOnTop(menu);
				button::MouseOnTop(video);
				button::MouseOnTop(controls);
				button::MouseOnTop(audio);

				switch (currentPage)
				{
				case game::scenes::options::VIDEO:
					break;

				case game::scenes::options::CONTROLS:
					break;

				case game::scenes::options::AUDIO:
					break;
				}
			}
			void Draw()
			{
				switch (currentPage)
				{
				case game::scenes::options::VIDEO:
					break;

				case game::scenes::options::CONTROLS:
					DrawTexturePro(GetSprite("Controls")->texture, Rectangle { 0, 0, 1067, 708 }, Rectangle{ 0,0,static_cast<float>(GetScreenWidth()), static_cast<float>(GetScreenHeight()) }, Vector2{}, 0, WHITE);
					break;

				case game::scenes::options::AUDIO:
					break;
				}

				button::Draw(menu);
				button::Draw(video);
				button::Draw(controls);
				button::Draw(audio);
			}

			void DeInit()
			{

			}

			void ButtonsInit()
			{
				float posx = (button::ButtonWidth / 2) * GetScale().x;
				float posy = (button::ButtonHeight / 2) * GetScale().y;

				menu = button::Create("Button", Rectangle{ posx, posy, button::ButtonWidth, button::ButtonHeight }, "Menu");

				posx += button::ButtonWidth * GetScale().x;
				video = button::Create("Button", Rectangle{ posx, posy, button::ButtonWidth, button::ButtonHeight }, "Video");

				posx += button::ButtonWidth * GetScale().x;
				controls = button::Create("Button", Rectangle{ posx, posy, button::ButtonWidth, button::ButtonHeight }, "Controls");

				posx += button::ButtonWidth * GetScale().x;
				audio = button::Create("Button", Rectangle{ posx, posy, button::ButtonWidth, button::ButtonHeight }, "Audio");
			}
		}
	}
}
