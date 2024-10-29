#pragma once

#include <vector>
#include <string>

#include "raylib.h"

namespace game
{
	namespace spritemanager
	{
		const int textureWidth = 32;
		const int textureHeight = 32;

		struct Sprite
		{
			Texture2D texture;
			std::string name;
		};

		struct Graphic
		{
			Texture2D sprite;

			Rectangle source;
			Rectangle dest;
			Vector2 origin;
		};

		Sprite* GetSprite(std::string name);

		void LoadSprites();
		void UnloadSprites();
	}
}