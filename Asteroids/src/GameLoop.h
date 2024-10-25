#pragma once

#include <iostream>

namespace game
{
	enum class SCENE
	{
		GAMEPLAY,
		CONTROLS,
		CREDITS,
		EXIT,
		MENU,
	};

	extern const int ScreenWidth;
	extern const int ScreenHeight;
	extern const std::string GameName;

	extern SCENE currentScene;

	extern bool programLoop;

	void Play();
}