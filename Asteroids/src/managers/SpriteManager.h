#pragma once

#include <vector>
#include <string>

#include "raylib.h"

namespace game
{
	namespace spritemanager
	{
		struct Sprite
		{
			Texture2D texture;
			std::string name;
		};


		Sprite GetSprite(std::string name);

		void LoadSprites();
		void UnloadSprites();
	}
}