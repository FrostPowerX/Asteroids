#include "GameLoop.h"

#include "raylib.h"

#include "scenes/SceneGamePlay.h"
#include "scenes/SceneCredits.h"
#include "scenes/SceneOptions.h"
#include "scenes/SceneMenu.h"

#include "managers/ResolutionManager.h"
#include "managers/SpriteManager.h"
#include "managers/InputManager.h"
#include "managers/SpriteManager.h"
#include "managers/SoundManager.h"

using namespace game::resolutionmanager;
using namespace game::spritemanager;

namespace game
{
	const std::string GameName = "CAPSULE RIPER";

	SCENE currentScene = SCENE::MENU;

	SCENE prevScene = SCENE::MENU;

	bool programLoop = true;

	void Init();

	void Input();
	void Update();
	void Draw();

	void DeInit();

	void Play()
	{
		Init();

		while (!WindowShouldClose() && programLoop)
		{
			Input();
			Update();
			Draw();

			prevScene = currentScene;
		}

		DeInit();
	}

	void Init()
	{
		InitWindow(currentWidth, currentHeight, GameName.c_str());
		SetExitKey(KEY_NULL);

		InitAudioDevice();

		HideCursor();

		spritemanager::LoadSprites();
		soundmanager::LoadSounds();

		input::Init();
		resolutionmanager::Init();
		scenes::gameplay::Init();
		scenes::options::Init();
		scenes::credits::Init();
		scenes::menu::Init();
	}

	void Input()
	{
		switch (currentScene)
		{
		case SCENE::GAMEPLAY:
			scenes::gameplay::Input();
			break;

		case SCENE::OPTIONS:
			scenes::options::Input();
			break;

		case SCENE::CREDITS:
			scenes::credits::Input();
			break;

		case SCENE::MENU:
			scenes::menu::Input();
			break;
		}
	}

	void Update()
	{
		switch (currentScene)
		{
		case SCENE::GAMEPLAY:
			scenes::gameplay::Update();
			break;

		case SCENE::OPTIONS:
			scenes::options::Update();
			break;

		case SCENE::CREDITS:
			scenes::credits::Update();
			break;

		case SCENE::MENU:
			scenes::menu::Update();
			break;

		case SCENE::EXIT:
			programLoop = false;
			break;
		}

		if (prevScene != currentScene)
		{
			switch (prevScene)
			{
			case game::SCENE::GAMEPLAY:
				scenes::gameplay::Init();
				break;
			case game::SCENE::OPTIONS:
				scenes::options::Init();
				break;
			case game::SCENE::CREDITS:
				scenes::credits::Init();
				break;
			}
		}

		soundmanager::Update();
	}

	void Draw()
	{
		BeginDrawing();

		ClearBackground(BLACK);

		switch (currentScene)
		{
		case SCENE::GAMEPLAY:
			scenes::gameplay::Draw();
			break;

		case SCENE::OPTIONS:
			scenes::options::Draw();
			break;

		case SCENE::CREDITS:
			scenes::credits::Draw();
			break;

		case SCENE::MENU:
			scenes::menu::Draw();
			break;
		}

		unsigned char r = static_cast<unsigned char>(GetRandomValue(0, 255));
		unsigned char g = static_cast<unsigned char>(GetRandomValue(0, 255));
		unsigned char b = static_cast<unsigned char>(GetRandomValue(0, 255));
		unsigned char a = 255;

		Color color;

#ifdef _DEBUG
		color = Color{ r,g,b,a };
#else
		color = RED;
#endif // _DEBUG

		DrawTexturePro(GetSprite("Cursor")->texture,
			Rectangle {
			0, 0, static_cast<float>(GetSprite("Cursor")->texture.width), static_cast<float>(GetSprite("Cursor")->texture.height / 2)
		},
			Rectangle{ GetMousePosition().x,GetMousePosition().y,textureWidth * 2,textureHeight * 2 },
			Vector2{ 0,0 },
			0,
			WHITE);

		DrawTexturePro(GetSprite("Cursor")->texture,
			Rectangle {
			0, 16, static_cast<float>(GetSprite("Cursor")->texture.width), static_cast<float>(GetSprite("Cursor")->texture.height / 2)
		},
			Rectangle{ GetMousePosition().x,GetMousePosition().y ,textureWidth * 2,textureHeight * 2 },
			Vector2{ 0,0 },
			0,
			color);

		EndDrawing();
	}

	void DeInit()
	{
		spritemanager::UnloadSprites();
		soundmanager::UnloadSounds();
		CloseWindow();
		CloseAudioDevice();
	}
}

