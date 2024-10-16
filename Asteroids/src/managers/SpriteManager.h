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


		void AddSprite(std::string name, std::string path);

		Sprite GetSprite(std::string name);
	}
}