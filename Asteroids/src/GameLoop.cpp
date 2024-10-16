#include "GameLoop.h"

#include "raylib.h"

#include "scenes/SceneGamePlay.h"
#include "scenes/SceneControlls.h"
#include "scenes/SceneCredits.h"
#include "scenes/SceneMenu.h"

#include "managers/SpriteManager.h"

namespace game
{
	const int ScreenWidth = 800;
	const int ScreenHeight = 600;
	const std::string GameName = "Asteroids";

	SCENE currentScene = SCENE::MENU;

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
		}

		DeInit();
	}

	void Init()
	{
		InitWindow(ScreenWidth, ScreenHeight, GameName.c_str());
		SetExitKey(KEY_NULL);

		game::scenes::gameplay::Init();
		scenes::controlls::Init();
		scenes::credits::Init();
		scenes::menu::Init();
	}

	void Input()
	{
		switch (currentScene)
		{
		case game::SCENE::GAMEPLAY:
			game::scenes::gameplay::Input();
			break;

		case game::SCENE::CONTROLLS:
			game::scenes::controlls::Input();
			break;

		case game::SCENE::CREDITS:
			scenes::credits::Input();
			break;

		case game::SCENE::MENU:
			scenes::menu::Input();
			break;
		}
	}

	void Update()
	{
		switch (currentScene)
		{
		case game::SCENE::GAMEPLAY:
			game::scenes::gameplay::Update();
			break;

		case game::SCENE::CONTROLLS:
			game::scenes::controlls::Update();
			break;

		case game::SCENE::CREDITS:
			scenes::credits::Update();
			break;

		case game::SCENE::MENU:
			scenes::menu::Update();
			break;

		case game::SCENE::EXIT:
			programLoop = false;
			break;
		}
	}

	void Draw()
	{
		BeginDrawing();

		ClearBackground(BLACK);

		switch (currentScene)
		{
		case game::SCENE::GAMEPLAY:
			game::scenes::gameplay::Draw();
			break;

		case game::SCENE::CONTROLLS:
			game::scenes::controlls::Draw();
			break;

		case game::SCENE::CREDITS:
			scenes::credits::Draw();
			break;

		case game::SCENE::MENU:
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

