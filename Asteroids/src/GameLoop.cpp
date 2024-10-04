#include "GameLoop.h"

#include "raylib.h"

#include "scenes/SceneMenu.h"
#include "scenes/SceneCredits.h"

namespace game
{
	const int ScreenWidth = 1024;
	const int ScreenHeight = 768;
	const std::string GameName = "Asteroids";

	SCENE currentScene = SCENE::MENU;

	void Init();

	void Input();
	void Update();
	void Draw();

	void DeInit();

	void Play()
	{
		Init();

		while (!WindowShouldClose())
		{
			Input();
			Update();
			Draw();
		}

		DeInit();
	}

	void Init()
	{
		InitWindow(ScreenWidth, ScreenHeight, GameName.c_str());
		SetExitKey(KEY_NULL);

		scenes::menu::Init();
		scenes::credits::Init();
	}

	void Input()
	{
		switch (currentScene)
		{
		case game::SCENE::MENU:
			scenes::menu::Input();
			break;

		case game::SCENE::CREDITS:
			scenes::credits::Input();
			break;

		case game::SCENE::GAMEPLAY:
			break;

		case game::SCENE::CONTROLS:
			break;

		default:
			break;
		}
	}

	void Update()
	{
		switch (currentScene)
		{
		case game::SCENE::MENU:
			scenes::menu::Update();
			break;

		case game::SCENE::CREDITS:
			scenes::credits::Update();
			break;

		case game::SCENE::GAMEPLAY:
			break;

		case game::SCENE::CONTROLS:
			break;

		default:
			break;
		}
	}

	void Draw()
	{
		BeginDrawing();

		ClearBackground(BLACK);

		switch (currentScene)
		{
		case game::SCENE::MENU:
			scenes::menu::Draw();
			break;

		case game::SCENE::CREDITS:
			scenes::credits::Draw();
			break;

		case game::SCENE::GAMEPLAY:
			break;

		case game::SCENE::CONTROLS:
			break;

		default:
			break;
		}

		EndDrawing();
	}

	void DeInit()
	{
		CloseWindow();
	}
}

