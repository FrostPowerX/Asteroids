#include "GameLoop.h"

#include "raylib.h"

#include "scenes/SceneGamePlay.h"
#include "scenes/SceneControlls.h"
#include "scenes/SceneCredits.h"
#include "scenes/SceneMenu.h"

#include "managers/ResolutionManager.h"
#include "managers/SpriteManager.h"
#include "managers/InputManager.h"

using namespace game::resolutionmanager;

namespace game
{
	const int ScreenWidth = 1024;
	const int ScreenHeight = 768;
	const std::string GameName = "Asteroids";

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
		InitWindow(ScreenWidth, ScreenHeight, GameName.c_str());
		SetExitKey(KEY_NULL);


		spritemanager::LoadSprites();

		input::Init();
		resolutionmanager::Init();
		scenes::gameplay::Init();
		scenes::controlls::Init();
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

		case SCENE::CONTROLLS:
			scenes::controlls::Input();
			break;

		case SCENE::CREDITS:
			scenes::credits::Input();
			break;

		case SCENE::MENU:
			scenes::menu::Input();
			break;
		}

		if (input::GetKey("res1"))
		{
			SetResolution(Vector2{ 800,600 });
			scenes::gameplay::Init();
			scenes::controlls::Init();
			scenes::credits::Init();
			scenes::menu::Init();
		}

		if (input::GetKey("res2"))
		{
			SetResolution(Vector2{ 1024,768 });
			scenes::gameplay::Init();
			scenes::controlls::Init();
			scenes::credits::Init();
			scenes::menu::Init();
		}

		if (input::GetKey("res3"))
		{
			SetResolution(Vector2{ 1920,1080 });
			scenes::gameplay::Init();
			scenes::controlls::Init();
			scenes::credits::Init();
			scenes::menu::Init();
		}
	}

	void Update()
	{
		switch (currentScene)
		{
		case SCENE::GAMEPLAY:
			scenes::gameplay::Update();
			break;

		case SCENE::CONTROLLS:
			scenes::controlls::Update();
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
			case game::SCENE::CONTROLLS:
				scenes::controlls::Init();
				break;
			case game::SCENE::CREDITS:
				scenes::credits::Init();
				break;
			}
		}
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

		case SCENE::CONTROLLS:
			scenes::controlls::Draw();
			break;

		case SCENE::CREDITS:
			scenes::credits::Draw();
			break;

		case SCENE::MENU:
			scenes::menu::Draw();
			break;
		}

		EndDrawing();
	}

	void DeInit()
	{
		spritemanager::UnloadSprites();
		CloseWindow();
	}
}

